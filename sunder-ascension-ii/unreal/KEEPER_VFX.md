# SUNDER: Ascension II — UE5 Keeper VFX (Niagara)

The twelve Keepers' effects in the Unreal version:

| System | When | Where | Lives |
|---|---|---|---|
| `NS_Keeper_Aura` | the whole fight | rides on the Keeper | looping, one per Keeper |
| `NS_Keeper_Arrival` | as it descends | the Gate opens where it will hold | one-shot, `Duration` + 0.8 s |
| `NS_Keeper_Muzzle` | every volley; ×2 when the attack pattern changes | below the Keeper | one-shot, 0.35 s, pooled |
| `NS_Keeper_PhaseShift` | at 66 % and 33 % hull (bigger for Apep's final form) | the Keeper | one-shot, 0.9 s, pooled |
| `NS_Keeper_Death` | beaten: rumble and cracks, then the final burst | the Keeper | one-shot, `Duration` + 1.8 s |
| `NS_Keeper_Shot` | every Keeper bullet | trail on `BP_KeeperShot` / `BP_KeeperShotHeavy` | for the shot's flight |

> **Status:** written guidance, not yet built or run in-engine (no Unreal where it was written).
> The C++ that drives these is in [`Source/`](Source/README.md) (`SunderKeeper`, not compiled yet).
> [`Scripts/create_keeper_fx_assets.py`](Scripts/create_keeper_fx_assets.py) creates the materials, Effect Types and
> empty, named systems, and wires them and each Keeper's colours onto the twelve Keeper Blueprints; the emitter stacks
> below are then built by hand. Module names are from UE 5.3–5.5; the few that moved between versions are marked ⚠.

Read [`WEAPON_VFX.md`](WEAPON_VFX.md) §0 first: the same camera rules apply (Z up, camera looking down −Z, play plane
XY, "up the screen" = +X, every material Unlit + Additive, every particle flattened onto the plane), and these
systems reuse its master material `M_FX_Additive`, `MI_Spark`, `MI_ShockRing`, `MI_PlasmaTendril` and its scratch pad
modules `SP_ErraticJitter` and `SP_FlattenToPlane`.

**Nothing breaks while you build.** The Keeper skips any system that has no emitters yet and falls back to the shared
plasma impacts (phase change, death). Build the systems in any order; each one shows up in play the moment it has an
emitter. Build order suggestion: Death, PhaseShift, Aura, Muzzle, Arrival, Shot.

---

## 1. Shared

### 1.1 User parameters (every `NS_Keeper_*` system except the shot)

The Keeper sets all five on every spawn (`ASunderKeeper::SetFXParams`). Add them under System → User Parameters with
exactly these names:

| Name | Type | Default (for previewing) | What the Keeper sends |
|---|---|---|---|
| `User.KeeperColor` | Linear Color | (3.4, 1.3, 0.45, 1) | its Hour's colour, HDR (set per Keeper by the script) |
| `User.AccentColor` | Linear Color | (4.0, 0.6, 2.6, 1) | its second colour: crystal, cyan, violet, fire, heart… |
| `User.Size` | Float | 350 | body radius in units, about half its on-screen size (× 2 for a pattern-change flare, × 1.6 for Apep's final form) |
| `User.Phase` | Float | 1 | 1, 2, 3; **4 while it dies** |
| `User.Duration` | Float | 2 | Arrival: seconds until it reaches its hold point. Death: seconds of rumble before the final burst |

Write every size, radius and speed below in terms of `User.Size`, so one system fits a 300-unit Wepwawet and a
700-unit Apep. Put the multiplication in the module input (Multiply Float dynamic input, or the input's expression).

`NS_Keeper_Shot` has its own three (§7): `User.ShotColor` (the Keeper's colour), `User.ShotSize` (34, heavy 46) and
`User.Heavy` (0 or 1).

### 1.2 Materials (made by the script)

All are instances of `M_FX_Additive` (WEAPON_VFX §0.2). Colour always comes from Particle Color.

| Instance | Mode | Use |
|---|---|---|
| `MI_Keeper_Glow` | sprite, very soft | halos, the death core, gate glow |
| `MI_Keeper_Rune` | ring, thin (0.08) | the Gate ring, the aura's rune ring, the muzzle's charge ring |
| `MI_Keeper_Ray` | ribbon, soft, slow scroll | the death's light rays |
| `MI_Keeper_Shot` | sprite, hot core | the bullet itself |

### 1.3 Scratch pad: `SP_KeeperPulse` (Dynamic Input, Float)

One breathing rhythm for everything a Keeper owns: slow at phase 1, quick and brighter at phase 3, a hard flicker
while it dies.

```hlsl
// Inputs:  float Phase (User.Phase), float Time (Engine.Time), float Seed (Particles.UniqueID or 0)
// Output:  float Out   (multiply alpha or size by it)
float P    = min(Phase, 3.0);
float Rate = 0.8 + 0.45 * P;                               // breaths per second
float Out1 = 0.75 + 0.25 * sin(Time * Rate * 6.2832 + Seed * 1.7);
if (Phase > 3.5)                                           // dying: hard, random flicker 24 times a second
{
    Out1 = 0.4 + 1.2 * frac(sin(floor(Time * 24.0) * 91.7 + Seed * 13.1) * 43758.5453);
}
Out = Out1 * (1.0 + 0.2 * (P - 1.0));                      // each phase burns 20 % brighter
```

### 1.4 System settings common to all

- Fixed Bounds on every system (± the size noted per system); no dynamic bounds calculation.
- Effect Type: `EFT_Keeper` (never culled: a boss's effects must always play). `NS_Keeper_Shot`: `EFT_KeeperShot`,
  also never culled: a bullet whose look was culled would still hit you, so cut cost in the emitters instead.
- Pool sizes are set by the script: Muzzle 24 (prime 12), PhaseShift 4 (2), Arrival 2 (1), Death 2 (1). The aura and
  shot trails live on their actors and are not pooled.
- No light renderers (the reason is in WEAPON_VFX §2.2). Bloom does the lighting.

---

## 2. `NS_Keeper_Aura` (looping, rides on the Keeper)

Fixed Bounds ±(3 × 700). Local Space **on** for A–C (they follow the Keeper as it strafes); D is world space.

**A. `Halo`** (CPU, 1 particle, never dies)
- Spawn Burst: 1. Initialize Particle: Lifetime 9999 (or Kill Particles off), Sprite Size `User.Size × 2.6`.
- Particle Update:
  - Sprite Size: `User.Size × 2.6 × SP_KeeperPulse`
  - Color: `User.KeeperColor × 0.35`, alpha `0.6 × SP_KeeperPulse`
- Sprite renderer: Face Camera Plane, `MI_Keeper_Glow`, Sort Order Hint −1 (behind the rest).

**B. `RuneRing`** (CPU, 1 particle)
- Spawn Burst: 1, Lifetime 9999. Sprite Size `User.Size × 2.2`.
- Particle Update:
  - Sprite Rotation: rate `20° × User.Phase` per second (Update Sprite Rotation Rate ⚠ or Sprite Rotation += rate × DeltaTime)
  - Color: `User.AccentColor × 0.5`, alpha `0.5 × SP_KeeperPulse`
- Sprite renderer: Facing Custom `(0,0,1)` (flat on the plane), `MI_Keeper_Rune`.

**C. `Motes`** (GPU, Fixed Bounds)
- Spawn Rate: `20 + 15 × User.Phase` (so 35 / 50 / 65, and 80 while dying).
- Initialize Particle: Lifetime random 1.2–2.0, Sprite Size random 6–14, Color `User.AccentColor`.
- Shape Location: Ring, radius `User.Size × 1.1`, axis Z.
- Particle Update:
  1. Vortex Velocity: axis (0,0,1), speed `90 + 40 × User.Phase`
  2. Point Attraction Force: strength 200, radius `User.Size × 1.5` (the motes drift inward as they orbit)
  3. Curl Noise Force: strength 80
  4. `SP_FlattenToPlane`
  5. Color over life: AccentColor → KeeperColor → 0
- Sprite renderer: Face Camera Plane, `MI_Spark`.

**D. `Embers`** (GPU, Local Space **off**)
- Spawn Rate: `8 × User.Phase`.
- Shape Location: Disc, radius `User.Size × 0.8`.
- Initialize: Lifetime 1.0–1.6, size 4–9, Color `User.KeeperColor`, velocity +X 80–160 (heat rising up the screen).
- Update: Drag 1, Curl Noise 120, `SP_FlattenToPlane`, alpha 1 → 0.
- Being world space, they trail behind as the Keeper strafes and dashes.

**E. `DeathCracks`** (CPU): only while dying
- Spawn Rate: `User.Phase > 3.5 ? 140 : 0` (Select Float by Bool ⚠, or a Compare Floats dynamic input).
- Lifetime 0.2–0.35, size 3–6, Color white → `User.AccentColor`.
- Add Velocity in Cone: axis (0,0,1), angle 180° (every direction on the plane), speed `User.Size × 2–4`.
- Update: `SP_ErraticJitter` (interval 0.04, 70°), `SP_FlattenToPlane`, Scale Sprite Size by Speed.
- Sprite renderer: Velocity Aligned, `MI_Spark`.

---

## 3. `NS_Keeper_Arrival` (the Gate opens)

Spawned where the Keeper will hold, as it starts its descent; `User.Duration` is how long it takes to get there (about
2–4 s). Fixed Bounds ±(5 × 700). All emitters: Loop Behavior **Once**. World space.

**A. `GateRing`** (CPU, 1 particle)
- Spawn Burst: 1. Lifetime `User.Duration + 0.4`.
- Update:
  - Sprite Size: `User.Size × 2.4 × ease_out(NormalizedAge × (Duration + 0.4) / Duration)`: grows to full size exactly
    as the Keeper arrives (use a Float Curve on a clamped `Particles.Age / User.Duration`).
  - Sprite Rotation: rate 90° / s.
  - Color `User.KeeperColor`; alpha 0.3 → 1 over the duration, then 1 → 0 in the last 0.4 s.
- Sprite renderer: Facing Custom `(0,0,1)`, `MI_Keeper_Rune`.

**B. `GateGlyphs`** (CPU)
- Spawn Burst: 12.
- Shape Location: Ring, radius `User.Size × 1.2`, **Uniform Spread** ⚠ (Ring → "U Distribution: Uniform"), so the
  twelve sit evenly like the hours on a dial.
- Lifetime `User.Duration + 0.3`; size 26; Color `User.AccentColor`.
- Update: Rotate Around Point ⚠ (centre = owner, rate −60° / s: against the ring), alpha flicker × `SP_KeeperPulse`
  with Phase 3 (fast).
- Sprite renderer: Face Camera Plane, `MI_Spark`.

**C. `Inflow`** (GPU)
- Spawn Rate 220 while `Engine.Emitter.Age < User.Duration` (Spawn Rate × Compare Floats ⚠, or Emitter State → Loop
  Duration bound to `User.Duration` ⚠).
- Shape Location: Ring, radius `User.Size × 3`.
- Lifetime 0.5–0.8; size 3–6; Color `User.KeeperColor`.
- Update: Point Attraction Force (strength 1400, falloff to 0 at the centre, kill radius 20), `SP_FlattenToPlane`.
- Sprite renderer: **Velocity Aligned**, `MI_Spark`. Reads as light being drawn into the Gate.

**D. `GateGlow`** (CPU, 1 particle)
- Spawn Burst 1, Lifetime `User.Duration + 0.5`, size `User.Size × 3 × NormalizedAge`, Color `User.KeeperColor × 0.25`.
- Sprite renderer: `MI_Keeper_Glow`.

**E. `Opening`**: the burst as the Keeper lands. Three emitters, each a Spawn Burst Instantaneous with **Spawn Time =
`User.Duration`** (link the Spawn Time input to the user parameter):
- `Opening_Flash`: 1 particle, 0.12 s, size `User.Size × 3`, white-hot (12, 10, 10), `MI_Keeper_Glow`.
- `Opening_Shock`: 1 particle, 0.45 s, size `User.Size × 0.5 → × 4.5` (cubic ease-out), Color `User.KeeperColor`,
  ring thickness 0.3 → 0.05 (Dynamic Parameter 1), Facing Custom (0,0,1), `MI_ShockRing`.
- `Opening_Sparks` (GPU): burst 80, cone 180° on the plane, speed `User.Size × 3–6`, Drag 4, `SP_ErraticJitter`,
  `SP_FlattenToPlane`, AccentColor → 0, Velocity Aligned `MI_Spark`.

---

## 4. `NS_Keeper_Muzzle` (each volley)

Spawned 60 units below the Keeper's centre on every volley, `User.Size` × 1; × 2 when it switches attack pattern (a
warning flare the player learns to read). Fixed Bounds ±600. Loop Once. Short and cheap: the Dual Spiral fires about
four times a second.

**A. `Flash`** (CPU, 1): 0.12 s, size `User.Size × 0.45`, Color `User.KeeperColor × 2`, size 1 → 0.4, alpha 1 → 0,
`MI_Keeper_Glow`.

**B. `ChargeRing`** (CPU, 1): 0.18 s, size `User.Size × 0.8 → × 0.15` (it **shrinks**: reads as a charge released),
Color `User.AccentColor`, Facing Custom (0,0,1), `MI_Keeper_Rune`.

**C. `Sparks`** (GPU): burst `6 + 2 × User.Phase`, Add Velocity in Cone axis (−1,0,0) (down the screen), angle 70°,
speed 600–1200, Lifetime 0.15–0.3, Drag 3, `SP_FlattenToPlane`, KeeperColor → 0, Velocity Aligned `MI_Spark`.

---

## 5. `NS_Keeper_PhaseShift` (the hull cracks: 66 %, 33 %)

Fixed Bounds ±(10 × 700). Loop Once, everything done by 0.9 s. `User.Phase` is the phase just entered (2 or 3): use it
to make phase 3 bigger. For Apep's final form `User.Size` arrives × 1.6.

**A. `Flash`** (CPU, 1): 0.15 s, size `User.Size × 3`, white (14, 12, 14) → `User.AccentColor`, `MI_Keeper_Glow`.

**B. `Shockwave`** (CPU, 2 particles): two rings, the second 0.12 s later
- Spawn Burst 1 at time 0 (KeeperColor) and 1 at time 0.12 (AccentColor): two Spawn Burst entries.
- Lifetime 0.6; size `User.Size × 0.5 → × (5 + 2 × User.Phase)`, cubic ease-out (phase 3 sweeps most of the screen).
- Ring thickness 0.35 → 0.04; alpha 1 → 0. Facing Custom (0,0,1), `MI_ShockRing`.

**C. `Crack_Heads`** + **D. `Crack_Ribbons`**: the impact's tendrils (WEAPON_VFX §2.2 C–D), scaled up:
- Heads: burst `6 + 4 × User.Phase`, Lifetime 0.35–0.55, cone 180° on the plane, speed `User.Size × 3–5`, Drag 4,
  `SP_ErraticJitter` (interval 0.035, 60°), `SP_FlattenToPlane`. No renderer.
- Ribbons: Spawn Particles from Other Emitter (140 / s per head), Sample Particles from Other Emitter for position,
  RibbonID = source ID, Link Order = emitter age, Lifetime 0.18–0.25, width 22 → 0, Color `User.AccentColor`;
  Ribbon renderer `MI_PlasmaTendril`, Screen facing.

**E. `Shards`** (GPU): burst 40, Lifetime 0.5–0.9, size 10–22 × (Sprite Size X 0.35: elongated), cone 180°, speed
`User.Size × 1.5–3.5`, Drag 2.5, Sprite Rotation from velocity, Color `User.KeeperColor` → 0, `MI_Spark`.

**F. `Afterglow`** (CPU, 1): 0.9 s, size `User.Size × 2.4`, `User.AccentColor × 0.4` fading, `MI_Keeper_Glow`.

---

## 6. `NS_Keeper_Death` (rumble, then the final burst)

The C++ handles the rest of the death: for `User.Duration` seconds (`DeathDuration`, default 2.2) the Keeper stops,
shudders harder and harder, swells 8 %, and plasma impacts pop across its body faster and faster in its two colours;
then 14 impacts burst across it, it scores and is gone. This system is the Keeper's light going out on top of that.

Fixed Bounds ±(14 × 700). Loop Once; all done by `User.Duration + 1.8`.

**Stage 1: coming apart (0 → `User.Duration`)**

**A. `Core`** (CPU, 1 particle): Lifetime `User.Duration`
- Size `User.Size × (0.5 → 2.2)` with an ease-in curve on `Particles.Age / User.Duration`.
- Color `User.KeeperColor` → white (16, 14, 16) on the same curve, alpha × `SP_KeeperPulse` with Phase 4 (flicker).
- `MI_Keeper_Glow`.

**B. `Fissure_Heads`** + **C. `Fissure_Ribbons`**: cracks crawling outward through the body
- Heads: Spawn Rate `4 + 26 × (Engine.Emitter.Age / User.Duration)` while age < Duration; Lifetime 0.4–0.7; start on a
  disc of radius `User.Size × 0.3`; slow speed `User.Size × 0.6–1.2`; `SP_ErraticJitter` (interval 0.06, 50°);
  `SP_FlattenToPlane`.
- Ribbons from the heads as in §5 D; Lifetime 0.4 (long, lingering cracks), width 10 → 0, Color `User.AccentColor`.

**D. `Implosion`** (GPU): Spawn Rate 300 while age < Duration; Ring radius `User.Size × 2.5`; Point Attraction 1800;
size 3–6; KeeperColor; Velocity Aligned `MI_Spark`. The world's light pours into it.

**Stage 2: the final burst (Spawn Burst Instantaneous at Spawn Time = `User.Duration`)**

**E. `Whiteout`** (CPU, 1): 0.25 s, size `User.Size × 8`, white (20, 18, 20) → 0, `MI_Keeper_Glow`. The big beat.

**F. `Rings`** (CPU, 3 particles): bursts at Duration, Duration + 0.1, Duration + 0.25, in KeeperColor, AccentColor and
white; Lifetime 0.9; size `User.Size × 0.5 → × 12`, cubic ease-out; thickness 0.4 → 0.03. `MI_ShockRing`, flat.

**G. `Rays`** (CPU, 16 particles + ribbons): the Ascension
- Heads: burst 16, Shape Location Ring radius 1 with Uniform Spread ⚠, Add Velocity from Point (outward) speed
  `User.Size × 9`, Lifetime 0.7, Drag 1.5, no jitter (straight light), `SP_FlattenToPlane`.
- Ribbons from the heads: Lifetime 0.5, width `User.Size × 0.18` → 0, Color white → `User.KeeperColor`,
  `MI_Keeper_Ray`, Screen facing. Sixteen long rays fanning out like a sunrise: the Hour is won.

**H. `Sparks`** (GPU): burst 300, cone 180°, speed `User.Size × 3–10`, Drag 2.5, Curl Noise 400,
`SP_ErraticJitter` (0.05, 60°), `SP_FlattenToPlane`, Lifetime 0.5–1.2, AccentColor → KeeperColor → 0, Velocity
Aligned `MI_Spark`.

**I. `Embers`** (GPU): burst 120, disc radius `User.Size`, slow drift +X 40–120 (rising up the screen), Lifetime
1.2–1.8, Curl Noise 60, KeeperColor fading, `MI_Spark`.

**For Apep** (Hour 12): its colours are violet and void-violet already; to make the last Keeper's end unmistakable,
duplicate the system as `NS_Keeper_Death_Apep`, set the Rays to 32 and the Rings to `× 18`, and set it as the Death FX
on `BP_Keeper_Apep` only (also raise its Death Duration to 3.5).

---

## 7. `NS_Keeper_Shot` (each Keeper bullet)

The script sets it as the Trail of `BP_KeeperShot` and `BP_KeeperShotHeavy`. It must be readable at a glance in a
screen full of bullets, so the look is simple:
- a hot white core inside a glow in the Keeper's colour;
- a short comet tail along its flight;
- for the heavy shot (Hours 7+, 2 damage) more size, a turning cross-flare and a few embers. You learn to fear it.

**What the shot hands the trail on every firing** (`ASunderProjectile::Fire`, then `ResetSystem`, so pooled shots
start clean):

| Name | Type | Preview default | Value |
|---|---|---|---|
| `User.ShotColor` | Linear Color | (3, 2, 0.5, 1) | the Keeper's colour (`SetShotColor`, from the Keeper's `KeeperColor`) |
| `User.ShotSize` | Float | 34 | `TrailSize` on the shot Blueprint: 34, heavy 46 (set by the script) |
| `User.Heavy` | Float | 0 | 1 on `BP_KeeperShotHeavy` (`bHeavyTrail`), else 0 |

The placeholder sphere hides itself once this system has an emitter, so there's no setting to change.

**Budget.** Up to a few hundred of these can be on screen at once (Wall Barrage plus Dual Spiral at phase 3).
- **Light shot:** two CPU emitters, A and B; C spawns nothing.
- **Heavy shot:** C adds a few cheap sprites.
- **System:** Fixed Bounds ±200; Effect Type `EFT_KeeperShot` (the script sets it; never culled).

**A. `Body`** (CPU, Local Space **on**, 2 particles)
- Spawn Burst: 2, Lifetime 9999.
- Particle 0 (`Particles.UniqueID == 0`) is the core:
  - size `User.ShotSize × 0.45`;
  - colour white-hot (8, 8, 8) blended 30 % toward `User.ShotColor`.
- Particle 1 is the glow:
  - size `User.ShotSize × (1.0 + 0.12 × sin(Age × 30))` (a fast flicker);
  - colour `User.ShotColor`.
- Heavy: Sprite Rotation rate `User.Heavy × 240°/s`.
- Sprite renderer: Face Camera Plane, `MI_Keeper_Shot`.
- The heavy shot's cross-flare is a third particle:
  - Spawn Burst `User.Heavy` (0 or 1);
  - Sprite Size (`User.ShotSize × 1.8`, `User.ShotSize × 0.18`) (a thin bar);
  - rotation rate 240°/s;
  - colour `User.ShotColor × 0.7`;
  - in a second sprite renderer with `MI_Spark`, or the same one with a Sub UV-free bar material.

**B. `Tail`** (CPU, Local Space **off**: the tail stays where the shot has been)
- Spawn Rate: 60.
- Lifetime: 0.09 (0.12 when heavy: `0.09 + 0.03 × User.Heavy`). The tail's length is its lifetime × the shot's speed,
  so faster later Hours get longer comets for free.
- Ribbon: RibbonLinkOrder = `Engine.Emitter.Age` (newest at the head).
- Width: `User.ShotSize × 0.55` → 0 over life.
- Colour: `User.ShotColor × 0.6` → 0.
- Ribbon renderer: `MI_PlasmaTendril`, Screen facing, UV0 Scaled Using Ribbon Segment Length.

**C. `Embers`** (CPU, Local Space **off**: heavy shots only)
- Spawn Rate: `14 × User.Heavy` (nothing on light shots).
- Lifetime 0.2–0.35. Size 4–8.
- Add Velocity in Cone: axis (0,0,1), 180° on the plane, speed 80–200, so they shed sideways and fall behind.
- Drag 3; `SP_FlattenToPlane`.
- Colour `User.ShotColor` → 0.
- Renderer: `MI_Spark`.

**Checks:**
- In Hour 1 (Wepwawet's amber), shots read as small bright comets in its colour.
- From Hour 7 the heavy shots are visibly bigger, with a turning cross and embers.
- With 300 in flight (Apep, phase 3), `stat Niagara` stays under about 1.5 ms for this system. Over that, drop C's
  embers first, then the Tail. Beyond that, move to the single-system bullet renderer in WEAPON_VFX §3.5.

---

## 8. Checks in play

1. **Arrival:** the Gate's ring is fully open exactly as the Keeper settles, and the burst lands on that frame. If it
   bursts early or late, check that the Spawn Time inputs are linked to `User.Duration`, not typed in.
2. **Aura:** breathes slowly at phase 1, visibly quicker and brighter after each crack, flickers hard while dying;
   embers trail behind its phase-3 dashes.
3. **Muzzle:** a pattern change gives the big flare about a second before the new pattern is readable.
4. **PhaseShift:** Apep's final form gets the bigger version as it opens its jaws.
5. **Death:** shudder → cracks → whiteout → rays; the bursts from the C++ and the system's whiteout land together.
6. **Budget:** with Hour 12 at phase 3 and the screen full of shots, `stat Niagara` stays under 2.5 ms total
   (shots ≤ 1.5, aura ≤ 0.3), and `stat unit` holds frame time.
7. **Colours:** each Keeper reads as its Hour (the script's `KEEPER_FX` table is the place to tune them; run it again
   to apply).
