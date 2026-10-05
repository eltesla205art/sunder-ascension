# SUNDER: Ascension II — UE5 ship VFX: the shield (Niagara)

The web game draws a ship's shield as a pulsing cyan ring that thickens with each layer (up to 3). This is that shield
for the Unreal version, as two systems:

| System | When | Lives |
|---|---|---|
| `NS_Ship_Shield` | while any shield is up | looping, rides on the ship; fades (not cut) when the last layer goes |
| `NS_Ship_ShieldEvent` | a hit soaked (ripple), the last layer breaking (shatter), a layer forming (gather) | one-shot, pooled |

> **Status:** written guidance, not yet built or run in-engine (no Unreal where it was written).
> The C++ that drives them is `ASunderShipPawn` in [`Source/`](Source/README.md) (`ShieldFX`, `ShieldEventFX`,
> `UpdateShield`). [`Scripts/create_ship_fx_assets.py`](Scripts/create_ship_fx_assets.py) makes the materials and the two
> empty systems and sets them on `BP_SunderShip`; the emitters below are built by hand. Module names are from UE 5.3–5.5;
> the ones that moved between versions are marked ⚠.

Read [`WEAPON_VFX.md`](WEAPON_VFX.md) §0 first. The same camera rules apply: Z is up, the camera looks down −Z, every
material is Unlit and Additive, and every particle stays flat on the play plane. These systems reuse its
`M_FX_Additive`, `MI_Spark`, `MI_ShockRing` and `SP_FlattenToPlane`.

**Nothing breaks while you build.** Until `NS_Ship_Shield` has an emitter, the ship shows the placeholder disc. Until
`NS_Ship_ShieldEvent` has one, a hit or a break shows a plasma impact instead.

---

## 1. Shared

### 1.1 User parameters

The ship sets these (`ASunderShipPawn::UpdateShield`). Add them to both systems with these names:

| Name | Type | Preview default | What the ship sends |
|---|---|---|---|
| `User.ShieldColor` | Linear Color | (0.6, 2.4, 4.0, 1) | cyan HDR (`ShieldColor` on the ship) |
| `User.Radius` | Float | 190 | the shield's radius in units: `ShieldRadius` × the ship's form scale, so it grows with each form |
| `User.Layers` | Float | 2 | shields up, 0–3 (after the event, for `NS_Ship_ShieldEvent`) |
| `User.Event` | Float | 0 | `NS_Ship_ShieldEvent` only: 0 = hit soaked, 1 = last layer broken, 2 = a layer formed |

The looping system reads `User.Layers` live: picking up a shield, or losing one, changes it while the system runs.

### 1.2 Materials (made by the script)

Both are instances of `M_FX_Additive`:

| Instance | Mode | Use |
|---|---|---|
| `MI_Shield_Ring` | ring, thin (0.06), sharp core | the shield's rings |
| `MI_Shield_Glow` | sprite, very soft | the bubble's fill and the event flashes |

### 1.3 Scratch pad: `SP_LayerMask` (Dynamic Input, Float)

Turns one of three rings on or off by the number of layers, so a single emitter can draw all three:

```hlsl
// Inputs:  float Layers (User.Layers), int Ring (1, 2 or 3: which ring this particle is)
// Output:  float Out   (multiply alpha by it; it eases rather than snaps, so layers fade in and out)
Out = saturate(Layers - (float)Ring + 1.0);
```

For `Ring`, use `(Particles.UniqueID % 3) + 1`, or set a `Particles.Ring` int in Particle Spawn from the spawn count.

### 1.4 System settings

- **Local Space:** on for `NS_Ship_Shield`, so it rides with the ship; world space for the event system.
- **Bounds:** Fixed Bounds of ±(3 × 300) for both.
- **Effect Type:** `EFT_PlayerWeapon`, never culled: your own shield must always show.
- **Pooling:** the script gives `NS_Ship_ShieldEvent` a max pool size of 6 and a prime size of 2. The looping shield
  lives on the ship and isn't pooled.
- **Bloom:** no light renderers; bloom does the glow.

---

## 2. `NS_Ship_Shield` (looping)

The look: a faint blue bubble, with one to three bright rings that breathe outward. Rings are re-born several times a
second rather than living forever, so the shield shimmers, and it fades out by itself when the ship deactivates the
system.

**A. `Bubble`** (CPU, Local Space on)
- Spawn Rate: 4. Lifetime 0.6.
- Sprite Size: `User.Radius × 2.1`.
- Color: `User.ShieldColor × 0.12`. Alpha: 0 → 1 → 0 over life (a triangle curve), × `(0.35 + 0.2 × User.Layers)`.
- Sprite renderer: Facing Custom `(0,0,1)` (flat on the plane), `MI_Shield_Glow`.

**B. `Rings`** (CPU, Local Space on)
- Spawn Rate: `9`. Particle Spawn: set `Particles.Ring` = `(Engine.Emitter.SpawnCountTotal % 3) + 1` ⚠ (or use
  `Particles.UniqueID % 3`), so the rings take turns.
- Lifetime: 0.55.
- Sprite Size: `User.Radius × 2 × (0.90 + 0.06 × Particles.Ring)`, × a curve over life from 0.97 to 1.05 (the breath
  outward).
- Sprite Rotation: random. Rotation rate ±40° / s (sign by ring, so neighbouring rings turn opposite ways).
- Color: `User.ShieldColor`. Alpha: in over 0.1 s, out over 0.25 s, × `SP_LayerMask(User.Layers, Particles.Ring)`.
- Dynamic Parameter 1 (ring thickness): `0.05 + 0.025 × User.Layers` (a thicker ring as the shield stacks, as in the web
  game's `lineWidth 2 + shield`).
- Sprite renderer: Facing Custom `(0,0,1)`, `MI_Shield_Ring`.

**C. `Glyphs`** (GPU, Local Space on): small sparks running round the edge, like the hex light of the Afrofuturist
crystal tech
- Spawn Rate: `5 × User.Layers`.
- Shape Location: Ring, radius `User.Radius`, axis Z.
- Lifetime 0.25–0.45. Size 6–12. Color `User.ShieldColor`; alpha flicker (Curl Noise on alpha, or random per frame).
- Particle Update: Vortex Velocity around Z, speed 300 (they skate along the ring), then `SP_FlattenToPlane`.
- Sprite renderer: Velocity Aligned, `MI_Spark`.

**Checks:**
- One layer: a thin ring, barely there.
- Three layers: three counter-turning rings and a busy edge.
- The size grows a little with each ship form.

---

## 3. `NS_Ship_ShieldEvent` (one-shot)

The emitters all burst at once and are gated by the event: multiply each Spawn Burst count by a Compare Floats ⚠
dynamic input (`User.Event == n` → 1, else 0), or by a scratch pad doing the same. Everything is done within 0.7 s.

**Event 0: a hit soaked (ripple)**

**A. `Ripple`** (CPU, 1 particle, gated to Event 0)
- Lifetime 0.3.
- Size: `User.Radius × 2 × (1.0 → 1.45)`, cubic ease-out.
- Color `User.ShieldColor`, alpha 1 → 0. Thickness 0.12 → 0.02.
- Renderer: Facing Custom `(0,0,1)`, `MI_ShockRing`.

**B. `Skitter`** (GPU, burst 18, gated to Event 0)
- Shape Location: Ring, radius `User.Radius`.
- Velocity: tangent to the ring (Vortex Velocity, speed 900), plus a little outward.
- Lifetime 0.15–0.3; Drag 4; `SP_FlattenToPlane`.
- Renderer: Velocity Aligned `MI_Spark`.

**Event 1: the last layer breaks (shatter)**

**C. `Shatter_Flash`** (CPU, 1 particle, gated to Event 1)
- Lifetime 0.12; size `User.Radius × 2.6`; white (10, 12, 14) → `User.ShieldColor`.
- Renderer: `MI_Shield_Glow`.

**D. `Shatter_Shards`** (GPU, burst 36, gated to Event 1)
- Shape Location: Ring, radius `User.Radius`.
- Add Velocity from Point (outward), speed 600–1400.
- Lifetime 0.35–0.6; Drag 3.
- Sprite Size X 14–24 × Y 4 (thin shards); Sprite Rotation from velocity; `SP_FlattenToPlane`.
- Color `User.ShieldColor` → 0.
- Renderer: `MI_Spark`.

**E. `Shatter_Ring`** (CPU, 1 particle, gated to Event 1)
- Lifetime 0.45; size `User.Radius × 2 × (1 → 2.2)`; thickness 0.2 → 0.02.
- Renderer: `MI_ShockRing`.

**Event 2: a layer forms (gather)**

**F. `Gather`** (GPU, burst 40, gated to Event 2)
- Shape Location: Ring, radius `User.Radius × 2.2`.
- Point Attraction Force: strength 2200, toward the owner. Kill particles inside `User.Radius`.
- Lifetime 0.35–0.5; size 4–8; `User.ShieldColor`.
- Renderer: Velocity Aligned `MI_Spark`.

**G. `Settle`** (CPU, 1 particle, gated to Event 2)
- Lifetime 0.4; size `User.Radius × 2 × (1.6 → 1.0)`, contracting onto the new layer; alpha 0 → 1 → 0.
- Renderer: `MI_Shield_Ring`.

**When each event plays** (the ship decides):
- **A shield pickup:** Event 2, as the new layer forms.
- **A hit soaked:** Event 0, with the ship's hit sound.
- **The last layer gone:** Event 1, and the looping shield fades out.
- **A respawn:** Event 2, as the ship comes back with its shield.

---

## 4. Checks in play

1. Pick up a shield: light gathers in, and a new ring appears in the loop.
2. Take a hit with two layers: a ripple, and one ring fades.
3. Take a hit with one layer: a shatter, and the loop fades away (no pop).
4. Power up through the forms: the shield grows with the ship.
5. Budget: `NS_Ship_Shield` under 0.1 ms in `stat Niagara`. Being the player's own effect, it's never culled.
