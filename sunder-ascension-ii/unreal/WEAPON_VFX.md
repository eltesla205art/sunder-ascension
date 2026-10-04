# SUNDER: Ascension II — UE5 weapon VFX (Niagara)

Implementation guide for two weapon effects in the Unreal Engine 5 version of the sequel:

1. a persistent, thick laser beam whose length follows a line trace, and
2. a plasma-burst projectile impact with ribbon tendrils and erratic sparks,

plus the pooling and budgeting that keeps dozens of simultaneous impacts from dropping frames.

> **Status:** written guidance, not yet built or run in-engine (no Unreal in the environment where it was written).
> The C++ in §1.6 and §3 is also provided as drop-in source in [`Source/`](Source/README.md) (not compiled yet either).
> [`Scripts/create_weapon_fx_assets.py`](Scripts/create_weapon_fx_assets.py) creates the materials (§0.2), Effect Types (§3.3)
> and empty, named systems in the editor; the emitter stacks below are then built by hand.
> [`Scripts/create_arena_level.py`](Scripts/create_arena_level.py) then makes the ship Blueprint and a top-down test arena to fly them in.
> Module names are from UE 5.3–5.5; the few that moved between versions are marked ⚠ — check those in your build.

Conventions: Z is up, the camera looks straight down −Z, the gameplay plane is XY, and "up the screen" is world +X.
Every effect is kept flat on that plane. Colours use the game's palette: Sunborn gold `#E6C252`,
plasma magenta `#FF3FA4`, Ibis cyan `#8CD9FF`.

---

## 0. Shared foundations (do these first)

### 0.1 Overhead orthographic camera rules for VFX

1. **Facing.** Use **Face Camera Plane** for sprites. Use **Screen** facing for ribbons, or Custom Facing Vector
   `(0,0,1)`, which is stable because the camera never moves.
2. **Never use Face Camera Position.** It only matters with perspective cameras.
3. **Blend mode.** Make every material Unlit, Translucent and **Additive**. Additive needs no sorting, which matters
   when dozens of effects overlap.
4. **No depth fade or soft particles.** Orthographic depth is linear and these effects behave differently than in
   perspective. You don't need them on a flat plane anyway.
5. **Layering.** Set **Translucency Sort Priority** on each Niagara component (beam 10, impacts 20) so beams always
   draw over bullets and backgrounds. Also raise effects about +10 units in Z above the gameplay plane.
6. **Sizing in pixels.** On an ortho camera, one world unit is a fixed number of pixels:
   `px = units × ViewportWidth / OrthoWidth`. Pick beam widths in pixels and convert.
7. **Bounds.** Give every system **Fixed Bounds**. GPU emitters require them, and a beam's dynamic length breaks
   automatic bounds.

### 0.2 Master material: `M_FX_Additive`

| Setting | Value |
|---|---|
| Shading model | Unlit |
| Blend mode | Additive |
| Two sided | On |
| Responsive AA | Off |

- **Emissive:** `Particle Color × Texture × CoreBoost`, with HDR values above 1 so bloom does the glow.
- **Per-particle variation:** use a Dynamic Parameter (erosion and flicker).
- **Per-impact colour:** never create a dynamic material instance per impact. Particle Color carries the per-hit
  colour, and every hit shares the same instances: `MI_Beam_Core`, `MI_Beam_Glow`, `MI_Spark`, `MI_ShockRing`,
  `MI_PlasmaTendril`.

**Beam profile (Custom node in `MI_Beam_*`).** The ribbon's V coordinate runs across the beam:

```hlsl
// Inputs: UV (float2), Noise (float, from a panning noise texture), CoreSharpness, GlowSharpness
float v     = abs(UV.y * 2.0 - 1.0);              // 0 at the beam's centre line, 1 at its edges
float core  = pow(saturate(1.0 - v), CoreSharpness);   // ~8: white-hot spine
float glow  = pow(saturate(1.0 - v), GlowSharpness);   // ~1.5: soft plasma sheath
float flick = 0.85 + 0.15 * Noise;
return float3(core, glow, flick);
// Emissive = (lerp(GlowColor * glow.g, CoreColor * 8, core.r)) * ParticleColor * flick
```

Pan the noise texture along U with a Panner: speed `(-4, 0)` gives energy flowing away from the ship.

---

## 1. Persistent thick laser beam: `NS_Laser_Beam`

### 1.1 User parameters (System → User Parameters)

| Name | Type | Default | Set by |
|---|---|---|---|
| `User.BeamStart` | Vector | 0,0,0 | Weapon tick (muzzle position) |
| `User.BeamEnd` | Vector | 0,2000,0 | Weapon tick (trace result) |
| `User.BeamWidth` | Float | 28 | Weapon (power level) |
| `User.BeamColor` | Linear Color | (3.0, 2.1, 0.6, 1), Sunborn gold HDR | Weapon or ship |
| `User.Intensity` | Float | 0 | Weapon (charge-up / shut-down ramp) |
| `User.bHit` | Bool | false | Weapon tick |
| `User.HitNormal` | Vector | 0,0,1 | Weapon tick |
| `User.BeamSegments` | Int | 32 | Constant |

**System properties:**
- Fixed Bounds: a box bigger than the play area, e.g. ±4096.
- Warmup: 0.
- Effect Type: `EFT_PlayerWeapon` (see §3).

### 1.2 Emitter A: `Beam_Core` (CPU sim, Local Space **off**)

**Emitter Update**
1. **Emitter State**
   - Life Cycle Mode: Self
   - Loop Behavior: Infinite
   - Inactive Response: **Kill** ⚠ (named "Inactive Response" in 5.x)
2. **Spawn Burst Instantaneous**
   - Spawn Count: `User.BeamSegments`
   - Spawn Time: 0

**Particle Spawn**
1. **Initialize Particle**
   - Lifetime Mode: Direct; Lifetime: 9999
   - Color: `User.BeamColor`
2. **Scratch Pad `SP_InitBeamU`**. It gives each segment its position along the beam, from 0 at the muzzle to 1 at
   the hit point:
   ```hlsl
   // Inputs: int UniqueID (Particles.UniqueID), int Segments (User.BeamSegments)
   // Output: float BeamU -> Particles.BeamU
   BeamU = (float)UniqueID / (float)max(Segments - 1, 1);
   ```
   `UniqueID` restarts at 0 when the emitter resets, so always call `Activate(true)` when the beam starts.

**Particle Update**
1. **Particle State**: uncheck *Kill Particles When Lifetime Has Elapsed*.
2. **Scratch Pad `SP_BeamPosition`**. This is the core of the beam: each segment snaps every frame onto the line from
   start to end, so the beam's length always follows the trace.
   ```hlsl
   // Inputs:  float3 BeamStart (User.BeamStart), float3 BeamEnd (User.BeamEnd),
   //          float BeamU (Particles.BeamU), float Time (Engine.Time),
   //          float WobbleAmp (6.0), float WobbleFreq (0.02), float Intensity (User.Intensity)
   // Outputs: float3 OutPosition -> Particles.Position, float OutLength -> Particles.BeamLength
   float3 Axis = BeamEnd - BeamStart;
   float  Len  = length(Axis);
   float3 Dir  = Len > 0.001 ? Axis / Len : float3(1, 0, 0);
   float3 Side = normalize(cross(Dir, float3(0, 0, 1)));         // in-plane perpendicular (top-down)
   float  Pin  = sin(BeamU * 3.14159265);                        // 0 at muzzle and hit: ends stay pinned
   float  Wave = sin(BeamU * Len * WobbleFreq - Time * 30.0) * WobbleAmp * Pin * Intensity;
   OutPosition = BeamStart + Axis * BeamU + Side * Wave;
   OutLength   = Len;
   ```
3. **Scratch Pad `SP_BeamWidth`**. It sets a pulsing core width, a wider glow width, and a flare at the impact end:
   ```hlsl
   // Inputs: float BeamWidth (User.BeamWidth), float Intensity (User.Intensity), float BeamU, float Time
   // Outputs: OutCore -> Particles.RibbonWidth, OutGlow -> Particles.GlowWidth (new float attribute)
   float Pulse    = 1.0 + 0.12 * sin(Time * 42.0 + BeamU * 18.0);
   float EndFlare = 1.0 + 0.6 * smoothstep(0.92, 1.0, BeamU);   // swells into the impact
   OutCore = BeamWidth * 0.35 * Pulse * Intensity;
   OutGlow = BeamWidth * 1.00 * Pulse * EndFlare * Intensity;
   ```
4. **Color**: `Particles.Color = User.BeamColor * User.Intensity`.

**Renderers.** Use two ribbon renderers on the same particles, which gives a thick beam for one simulation.

| Setting | Ribbon 1: core | Ribbon 2: glow |
|---|---|---|
| Material | `MI_Beam_Core` | `MI_Beam_Glow` (magenta sheath) |
| Width binding | `Particles.RibbonWidth` | `Particles.GlowWidth` |
| Ribbon Link Order binding | `Particles.BeamU` | `Particles.BeamU` |
| Facing Mode | Screen | Screen |
| UV0 Distribution | **Tiled Over Ribbon Length**, Tiling Length 256 ⚠ | same |
| Tessellation | Disabled (we supply 32 segments) | same |
| Sort Order Hint | 1 | 0 (drawn underneath) |

Tiled UVs stop the texture stretching as the beam grows. The texture stays a fixed scale and scrolls.

### 1.3 Emitter B: `Beam_MuzzleFlare` (CPU)

- **Spawn Rate:** `40 × User.Intensity`.
- **Initialize Particle:**
  - Lifetime: random 0.05–0.08
  - Sprite Size: random 40–64
  - Position: `User.BeamStart`
- **Particle Update:**
  - Set Position = `User.BeamStart` each frame, so it sticks to the gun.
  - Scale Sprite Size: curve 1 → 0.4.
  - Scale Color: alpha 1 → 0.
- **Sprite renderer:** Face Camera Plane, `MI_Spark` (radial falloff).

### 1.4 Emitter C: `Beam_ImpactSparks` (GPU, Fixed Bounds)

- **Spawn Rate:** dynamic input *Select Float by Bool*. Use 140 when `User.bHit` is true, 0 when false.
- **Particle Spawn:**
  1. **Initialize Particle**
     - Lifetime: random 0.12–0.32
     - Sprite Size: random 3–8
     - Position: `User.BeamEnd`
     - Color: white-hot (8, 7, 5)
  2. **Add Velocity in Cone**
     - Cone Axis: `User.HitNormal`
     - Angle: 75°
     - Speed: random 600–1500
- **Particle Update:**
  1. Drag: 5
  2. Curl Noise Force: strength 350, frequency 0.015
  3. `SP_FlattenToPlane` (§2.3), plane Z = `User.BeamEnd.z`
  4. Color: curve from white-hot → `User.BeamColor` → transparent, over normalized age
- **Sprite renderer:**
  - Alignment: **Velocity Aligned**
  - Facing: Face Camera Plane
  - Material: `MI_Spark`
  - Stretch the sprites by speed with the *Scale Sprite Size by Speed* module (X axis only).

### 1.5 Emitter D: `Beam_ImpactGlow` (CPU, one particle)

- Spawn Burst Instantaneous: 1.
- Lifetime: 9999. Particle State: no kill.
- Particle Update:
  - Position = `User.BeamEnd`.
  - Sprite Size = `User.bHit ? 90 : 0` (Select by Bool), multiplied by `0.9 + 0.1 × sin(Time × 50)`.

This is the white-hot "contact point" disc. It is the single most important readability cue at shmup speed.

### 1.6 Weapon component Blueprint (`BPC_BeamWeapon`, Actor Component)

**Variables**

| Variable | Type | Default |
|---|---|---|
| `BeamFX` | NiagaraComponent | (set at BeginPlay) |
| `MaxRange` | Float | 2400 |
| `BeamRadius` | Float | 14 |
| `TraceChannel` | Trace channel | `PlayerWeapon` |
| `DPS` | Float | 140 |
| `DamageInterval` | Float | 0.05 |
| `bFiring` | Bool | false |
| `CurrentEnd` | Vector | (set while firing) |
| `IntensityTarget` | Float | 0 |
| `Intensity` | Float | 0 |

**Class Defaults:** Tick Group = **Pre Physics**, Start with Tick Enabled = off.

```
EVENT BeginPlay
 └─ Spawn System Attached (NS_Laser_Beam, AttachTo = ShipMesh, Socket = "Muzzle",
        Location Type = Snap To Target, Auto Destroy = false, Auto Activate = false,
        Pooling Method = None)                       // one per ship, lives forever; no pooling needed
 └─ Set BeamFX
 └─ BeamFX → Add Tick Prerequisite Component (Self)  // our tick (trace) runs BEFORE Niagara reads params
 └─ BeamFX → Set Translucent Sort Priority (10)

EVENT StartFire
 └─ bFiring = true ; IntensityTarget = 1
 └─ BeamFX → Activate (Reset = true)                 // resets UniqueID so BeamU is 0..1 again
 └─ Set Component Tick Enabled (true)
 └─ Set Timer by Event (ApplyBeamDamage, DamageInterval, Looping = true) → store handle

EVENT StopFire
 └─ bFiring = false ; IntensityTarget = 0            // tick ramps down, then shuts off (below)
 └─ Clear and Invalidate Timer (damage handle)

EVENT Tick (DeltaSeconds)
 ├─ Intensity = FInterp To Constant (Intensity, IntensityTarget, DeltaSeconds, 12)   // ~0.08 s ramp
 ├─ IF (!bFiring AND Intensity <= 0.01)
 │     └─ BeamFX → Deactivate Immediate ; Set Component Tick Enabled (false) ; RETURN
 ├─ Start  = ShipMesh → Get Socket Location ("Muzzle")
 ├─ Dir    = (1, 0, 0)                               // up-screen; for aimed beams: normalise(Aim with Z = 0)
 ├─ FarEnd = Start + Dir * MaxRange
 ├─ Sphere Trace By Channel (Start, FarEnd, Radius = BeamRadius, TraceChannel,
 │        Ignore Self = true)  → OutHit, bHit       // sphere = gameplay matches the beam's visual thickness
 ├─ TargetEnd = bHit ? Start + Dir * OutHit.Distance   // keep the end ON the beam axis (no sideways kink)
 │                   : FarEnd
 ├─ // Grow toward a farther end at a fixed speed (reads as the beam punching outward),
 ├─ // snap instantly when something blocks it (never draws through an enemy):
 ├─ CurrentEnd = (TargetEnd closer than CurrentEnd) ? TargetEnd
 │              : VInterp To Constant (CurrentEnd, TargetEnd, DeltaSeconds, 9000)
 ├─ BeamFX → Set Niagara Variable (Vector3)  "BeamStart"  = Start
 ├─ BeamFX → Set Niagara Variable (Vector3)  "BeamEnd"    = CurrentEnd
 ├─ BeamFX → Set Niagara Variable (Bool)     "bHit"       = bHit
 ├─ BeamFX → Set Niagara Variable (Vector3)  "HitNormal"  = bHit ? OutHit.ImpactNormal (Z = 0, normalised) : -Dir
 └─ BeamFX → Set Niagara Variable (Float)    "Intensity"  = Intensity

EVENT ApplyBeamDamage
 └─ IF (last trace hit a damageable actor) → Apply Damage (Actor, DPS * DamageInterval, ...)
```

**Notes**
- **Parameter names.** Pass names without the `User.` prefix (`BeamEnd`); the `User.` form also resolves. If a value
  never arrives, the name is misspelt; Niagara doesn't warn.
- **Who traces.** Do the trace in the weapon component, not the Player Controller. The controller should only call
  `StartFire` and `StopFire`, plus pass an aim vector if beams can be aimed.
- **Tick ordering.** With the Pre Physics tick group and the tick prerequisite, the beam can't lag a frame behind the
  ship. That lag would show as a gap at the muzzle during fast strafing.
- **Damage timing.** Apply damage on a timer, not every frame, so damage doesn't depend on frame rate.

C++ equivalent of the hot path, if you move it out of Blueprint:

```cpp
// BeamWeaponComponent.cpp: TickComponent (TickGroup = TG_PrePhysics)
const FVector Start  = Ship->GetSocketLocation(TEXT("Muzzle"));
const FVector Dir    = FVector::ForwardVector;                       // up-screen
const FVector FarEnd = Start + Dir * MaxRange;
FHitResult Hit;
FCollisionQueryParams Params(SCENE_QUERY_STAT(BeamTrace), false, GetOwner());
const bool bHit = GetWorld()->SweepSingleByChannel(Hit, Start, FarEnd, FQuat::Identity,
                     TraceChannel, FCollisionShape::MakeSphere(BeamRadius), Params);
const FVector TargetEnd = bHit ? Start + Dir * Hit.Distance : FarEnd;
CurrentEnd = (FVector::DistSquared(Start, TargetEnd) < FVector::DistSquared(Start, CurrentEnd))
           ? TargetEnd : FMath::VInterpConstantTo(CurrentEnd, TargetEnd, DeltaTime, 9000.f);

BeamFX->SetVariableVec3 (TEXT("BeamStart"), Start);
BeamFX->SetVariableVec3 (TEXT("BeamEnd"),   CurrentEnd);
BeamFX->SetVariableBool (TEXT("bHit"),      bHit);
BeamFX->SetVariableVec3 (TEXT("HitNormal"), bHit ? FVector(Hit.ImpactNormal.X, Hit.ImpactNormal.Y, 0).GetSafeNormal() : -Dir);
BeamFX->SetVariableFloat(TEXT("Intensity"), Intensity);
```

---

## 2. Plasma-burst impact: `NS_PlasmaBurst_Impact`

### 2.1 User parameters and system settings

| Name | Type | Default |
|---|---|---|
| `User.ImpactNormal` | Vector | 0,0,1 |
| `User.PlasmaColor` | Linear Color | (4.0, 0.6, 2.6, 1), magenta HDR |
| `User.Scale` | Float | 1 |

The impact position comes from the component's location, so it needs no parameter.

**System properties:**
- One-shot: every emitter uses Loop Behavior **Once** and finishes within 0.6 s. This is what lets the component
  return to the pool.
- Fixed Bounds: ±512 × Scale.
- Effect Type: `EFT_Impact` (§3).
- **Max Pool Size: 48. Pool Prime Size: 32** ⚠ (System Properties, Performance; Prime Size is 5.1+). Priming creates
  the components at load, so the first barrage doesn't hitch.

### 2.2 Emitters

**A. `Flash`** (CPU, 1 particle)
- Spawn Burst Instantaneous: 1.
- Initialize Particle:
  - Lifetime: 0.09
  - Sprite Size: 220 × Scale
  - Color: (12, 9, 14), near-white with a magenta tint
- Particle Update:
  - Scale Sprite Size: curve 1 → 0.3 (ease-out)
  - Scale Color alpha: 1 → 0
- Sprite renderer: Face Camera Plane, `MI_Spark`.

**B. `ShockRing`** (CPU, 1 particle)
- Spawn Burst: 1.
- Lifetime: 0.28.
- Color: `User.PlasmaColor`.
- Particle Update:
  - Sprite Size: curve 0.15 → 2.6 × (180 × Scale), cubic ease-out
  - Alpha: 1 → 0
  - Dynamic Parameter: ring thickness 0.3 → 0.05
- Sprite renderer: Facing Custom `(0,0,1)`, so it lies flat on the plane; `MI_ShockRing`.

**C. `Tendril_Heads`** (CPU, **no renderer**). These invisible particles lead the ribbons.
- Spawn Burst: random int 6–10.
- Initialize Particle: Lifetime random 0.25–0.4.
- Add Velocity in Cone:
  - Axis: `User.ImpactNormal`
  - Angle: 160°
  - Speed: random 900–1700 × Scale
- Particle Update:
  1. Drag: 6
  2. **`SP_ErraticJitter`** (§2.3): interval 0.03, angle 55°. This makes the zig-zag lightning paths.
  3. `SP_FlattenToPlane`

**D. `Tendril_Ribbons`** (CPU)
- **Emitter Update: Spawn Particles from Other Emitter** ⚠
  - Source: `Tendril_Heads`
  - Spawn Rate: 140 per source particle per second
- **Particle Spawn:**
  1. **Sample Particles from Other Emitter** ⚠: Source `Tendril_Heads`; copy Position.
  2. Set `Particles.RibbonID` = the sampled source particle's ID. One ribbon per head.
  3. Set `Particles.RibbonLinkOrder` = `Engine.Emitter.Age`. Newest point is the head.
  4. Initialize Particle:
     - Lifetime: random 0.10–0.16 (this is the trail length)
     - Color: `User.PlasmaColor`
     - Ribbon Width: 14 × Scale
- **Particle Update:** Ribbon Width × curve(NormalizedAge) 1 → 0, plus alpha fade.
- **Ribbon renderer:**
  - Material: `MI_PlasmaTendril`
  - Ribbon ID binding: `Particles.RibbonID`
  - Link Order binding: `Particles.RibbonLinkOrder`
  - Facing: Screen
  - UV0: Scaled Using Ribbon Segment Length

**E. `Erratic_Sparks`** (**GPU**, Fixed Bounds)
- Spawn Burst: 60 × Scale.
- Initialize Particle:
  - Lifetime: random 0.25–0.6
  - Sprite Size: random 3–7
- Add Velocity in Cone: axis normal, 120°, speed 700–2200 × Scale.
- Particle Update:
  1. Drag: 3.5
  2. Curl Noise Force: strength 500
  3. `SP_ErraticJitter`: interval random 0.04–0.07, angle 70°
  4. `SP_FlattenToPlane`
  5. Color over life: white-hot → `User.PlasmaColor` → 0
  6. Scale Sprite Size by Speed
- Sprite renderer: Velocity Aligned, Face Camera Plane, `MI_Spark`.

**F. `Residue`** (GPU, optional)
- Spawn Burst: 12.
- Lifetime: 0.8.
- Slow outward drift, gentle Curl Noise, small cyan embers that fade.

There's no light renderer on purpose: dozens of short-lived dynamic lights are the fastest way to lose frame rate.
The flash plus bloom reads as light.

### 2.3 Shared Scratch Pad modules

**`SP_ErraticJitter`** (Particle Update). It turns the velocity by a random angle at fixed time steps, giving
electric zig-zags rather than smooth noise:

```hlsl
// Inputs:  float3 Velocity (Particles.Velocity), float Age (Particles.Age), float DeltaTime (Engine.DeltaTime),
//          int Seed (Particles.UniqueID), float Interval (0.04), float MaxAngleDeg (65)
// Output:  float3 OutVelocity -> Particles.Velocity
float StepNow  = floor(Age / Interval);
float StepPrev = floor(max(Age - DeltaTime, 0.0) / Interval);
float3 V = float3(Velocity.xy, 0.0);
if (StepNow != StepPrev)
{
    // cheap deterministic hash per particle per step
    float r = frac(sin(Seed * 12.9898 + StepNow * 78.233) * 43758.5453);
    float a = radians((r * 2.0 - 1.0) * MaxAngleDeg);
    float c = cos(a), s = sin(a);
    V = float3(V.x * c - V.y * s, V.x * s + V.y * c, 0.0);   // rotate in the XY plane
}
OutVelocity = V;
```

**`SP_FlattenToPlane`** (Particle Update, last module before rendering). It keeps every particle on the gameplay
plane, so nothing drifts toward or away from the ortho camera:

```hlsl
// Inputs: float3 Position, float3 Velocity, float PlaneZ (Engine.Owner.Position.z + 10, or User.BeamEnd.z)
OutPosition = float3(Position.xy, PlaneZ);
OutVelocity = float3(Velocity.xy, 0.0);
```

### 2.4 Spawning an impact (Blueprint, on projectile hit)

```
EVENT OnProjectileHit (Hit)
 └─ ImpactFX Subsystem → Queue Impact (Hit.ImpactPoint, Hit.ImpactNormal, ShipPlasmaColor)
 └─ Return projectile to its pool (see §3.4); do NOT Destroy Actor
```

Never spawn the effect directly from the projectile. Route it through the subsystem in §3.2, which merges and
throttles impacts.

---

## 3. Zero-drop performance: pooling, budgets, clean shutdown

### 3.1 Tier 1: Niagara's built-in component pool (covers "dozens per second")

- **Spawn method.** Always use **Spawn System at Location** with Pooling Method = **Auto Release**. With pooling on,
  the pool owns the component's lifetime (Auto Destroy doesn't apply), so don't keep references to it.
- **Return to pool.** A component goes back to the pool when every emitter completes. Things that silently break
  this, so the pool keeps growing:
  - infinite loops
  - an emitter with "Kill on Lifetime" off
  - an Emitter State left on "System" life cycle with no duration
- **Avoid Manual Release** unless you need to hold the component, for example a charge-up attached to a moving enemy.
  Then call `ReleaseToPool`.
- **Prime the pool** with Pool Prime Size (§2.1) so the first barrage doesn't allocate.
- **Avoid shader-compile hitches.** Pre-compile the materials, and make sure PSO precaching is on (5.2+). The very
  first impact otherwise hitches on shader compilation rather than spawning. Run every effect once in a hidden spawn
  at level load.

### 3.2 Tier 1.5: an impact subsystem that merges and throttles

This is the part that guarantees no frame-rate drop when 40 bullets land in the same frame:

```cpp
// ImpactFXSubsystem.h: UTickableWorldSubsystem (remember to override GetStatId)
struct FPendingImpact { FVector Pos; FVector Normal; FLinearColor Color; float Scale = 1.f; };

UPROPERTY(EditDefaultsOnly) TObjectPtr<UNiagaraSystem> ImpactFX;      // NS_PlasmaBurst_Impact
UPROPERTY(EditDefaultsOnly) TObjectPtr<UNiagaraSystem> ImpactFXLite;  // flash + 15 sparks only
float MergeRadius = 40.f;
int32 MaxFullImpactsPerFrame = 10;
TArray<FPendingImpact> Pending;

// ImpactFXSubsystem.cpp
void UImpactFXSubsystem::QueueImpact(const FVector& P, const FVector& N, const FLinearColor& C)
{
    for (FPendingImpact& E : Pending)                       // merge hits landing on the same spot
        if (FVector::DistSquared2D(E.Pos, P) < FMath::Square(MergeRadius))
        { E.Scale = FMath::Min(E.Scale + 0.25f, 2.f); return; }   // bigger burst, not more systems
    Pending.Add({ P, N, C, 1.f });
}

void UImpactFXSubsystem::Tick(float DeltaTime)
{
    int32 Count = 0;
    for (const FPendingImpact& E : Pending)
    {
        UNiagaraSystem* FX = (Count++ < MaxFullImpactsPerFrame) ? ImpactFX : ImpactFXLite;
        if (UNiagaraComponent* NC = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
                GetWorld(), FX, E.Pos, E.Normal.Rotation(), FVector(1.f),
                /*bAutoDestroy*/ false, /*bAutoActivate*/ true, ENCPoolMethod::AutoRelease, /*bPreCullCheck*/ true))
        {
            NC->SetVariableVec3       (TEXT("ImpactNormal"), FVector(E.Normal.X, E.Normal.Y, 0).GetSafeNormal());
            NC->SetVariableLinearColor(TEXT("PlasmaColor"),  E.Color);
            NC->SetVariableFloat      (TEXT("Scale"),        E.Scale);
            NC->SetTranslucentSortPriority(20);
        }
    }
    Pending.Reset();
}
```

If you're Blueprint-only, do the same with a GameInstance Subsystem or a manager actor. Push hits into an array, and
drain it on tick with a for-loop and a counter.

### 3.3 Effect Types (scalability safety net)

Create two Niagara Effect Type assets and assign them in System Properties.

| | `EFT_PlayerWeapon` (beam) | `EFT_Impact` |
|---|---|---|
| Cull Reaction | Deactivate | **Deactivate Immediate** |
| Max Instances | unlimited (never cull the player's beam) | 40 (High) / 24 (Medium) / 12 (Low) |
| Significance Handler | none | **Age**: the newest impacts matter most, the oldest are culled first |
| Spawn Count Scale | 1 | 1.0 / 0.7 / 0.4 per quality level (scales the spark bursts) |
| Update Frequency | Continuous | Low (culling checks don't need to run every frame) |

### 3.4 Clean shutdown and the projectiles themselves

- **Beam:**
  - `DeactivateImmediate` is safe, because Emitter State "Inactive Response: Kill" clears the infinite-lifetime
    segments.
  - Never `DestroyComponent` it mid-game; reuse it.
- **Projectiles:** pool the actors, not just the effects.
  - On hit: queue the impact, then hide the actor, disable collision, and stop and disable its Projectile Movement.
  - Push it back on a `TArray` free list.
  - If the projectile carries a trail, call `Deactivate()`, not Immediate, so the trail fades out over a few frames.
    On reuse, call `ResetSystem()` before re-arming.
- **No per-hit allocations:**
  - no `CreateDynamicMaterialInstance`
  - no Spawn Actor
  - no `SpawnSystemAttached` per bullet
  - Colour and scale ride on user parameters.

### 3.5 Tier 2, if you go "bullet hell" (hundreds of hits per second)

Swap per-hit systems for **Niagara Data Channels** ⚠ (experimental in 5.3, usable from 5.4):
- Game code writes `{Position, Normal, Color}` into the data channel via **Write To Niagara Data Channel**.
- One persistent impact system reads it with a **spawn-from-data-channel** module, and spawns every hit's particles
  in a single simulation.

That brings a hit down to essentially a data write. Start with Tier 1.5: it handles "dozens at once" comfortably and
works on every 5.x version.

### 3.6 Proving "zero drops"

1. **Stress test.** Build a BP that queues 60 impacts per frame at random positions for 10 seconds, with the beam
   firing.
2. **Watch these:**
   - `stat Niagara`, `stat GPU`, `stat Game`
   - **Niagara Debugger** (Tools → Debug): per-system instance counts and pool usage
   - Unreal Insights, for game-thread spikes on the first spawn
3. **Targets:**
   - The Niagara game-thread total stays flat; spikes mean pooling is broken or a shader is compiling.
   - The pooled component count plateaus. If it keeps climbing, some emitter isn't completing.
   - The GPU particle simulation stays well under 1 ms at the Low tier.

---

## 4. Build order checklist

1. Make `M_FX_Additive` and its five material instances — or run `Scripts/create_weapon_fx_assets.py`
   (Tools → Execute Python Script), which also makes the Effect Types and empty systems and prints what's left.
2. Build `NS_Laser_Beam`. Test it with fixed `BeamEnd` values in the editor, by dragging the user parameters in the
   system's preview.
3. Add `BPC_BeamWeapon`. Confirm the beam stops on an enemy, extends smoothly when the enemy dies, and never lags the
   ship.
4. Build `NS_PlasmaBurst_Impact` (§2.2), the shared scratch pads (§2.3) and `ImpactFXLite`.
5. Set up the Effect Types (§3.3), pool sizes and the impact subsystem (§3.2).
6. Run the stress test (§3.6) and tune Max Instances and Spawn Count Scale until frame time is flat.
