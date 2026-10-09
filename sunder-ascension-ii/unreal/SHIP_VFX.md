# SUNDER: Ascension II — UE5 ship VFX: the shield, the explosion, the bomb and the form change (Niagara)

The web game draws a ship's shield as a pulsing cyan ring that thickens with each layer (up to 3). This is that shield
for the Unreal version, as two systems. The ship's explosion is in §5, its bomb blast in §7 and its form
change in §9.

| System | When | Lives |
|---|---|---|
| `NS_Ship_Shield` | while any shield is up | looping, rides on the ship; fades (not cut) when the last layer goes |
| `NS_Ship_ShieldEvent` | a hit soaked (ripple), the last layer breaking (shatter), a layer forming (gather) | one-shot, pooled |
| `NS_Ship_Explosion` | the hull taking a hit (a small gold burst), the ship destroyed (the big one) | one-shot, pooled |
| `NS_Ship_Bomb` | a bomb: the blast, a shockwave that sweeps the arena, and every wiped enemy shot fizzling | one-shot, pooled |
| `NS_Ship_FormChange` | the ship rising a form (one ring per form, light up the screen) or a hit knocking it back one | one-shot, pooled, rides on the ship |

> **Status:** written guidance, not yet built or run in-engine (no Unreal where it was written).
> The C++ that drives them is `ASunderShipPawn` in [`Source/`](Source/README.md) (`ShieldFX`, `ShieldEventFX`,
> `UpdateShield`, `ExplosionFX`, `SpawnExplosion`, `BombFX`, `SpawnBombBlast`, `FormFX`, `PlayFormChange`).
> [`Scripts/create_ship_fx_assets.py`](Scripts/create_ship_fx_assets.py) makes the materials and the five empty systems and sets them on `BP_SunderShip`; the emitters below are built by hand. Module names are from UE 5.3–5.5;
> the ones that moved between versions are marked ⚠.

Read [`WEAPON_VFX.md`](WEAPON_VFX.md) §0 first. The same camera rules apply: Z is up, the camera looks down −Z, every
material is Unlit and Additive, and every particle stays flat on the play plane. These systems reuse its
`M_FX_Additive`, `MI_Spark`, `MI_ShockRing` and `SP_FlattenToPlane`.

**Nothing breaks while you build.** Until `NS_Ship_Shield` has an emitter, the ship shows the placeholder disc. Until
`NS_Ship_ShieldEvent` has one, a hit or a break shows a plasma impact instead. Until `NS_Ship_Explosion` has one, a
hull hit shows one gold plasma impact and the ship's destruction four in its colour. Until `NS_Ship_Bomb` has one, a
bomb shows a ring of eleven cyan plasma impacts. Until `NS_Ship_FormChange` has one, a rise shows one plasma impact in the
ship's accent and a fall shows nothing.

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

---

## 5. `NS_Ship_Explosion` (one-shot)

The web game's ship explosions (web/game.html `playerTakeDamage` and `onPlayerDied`):
- **A hull hit** (no shield up, the ship survives): 20 gold sparks (#FFD54A) from the ship, and a small shake.
- **The ship destroyed:** 50 gold sparks flung far (the "big" burst: 60–320 px/s, living up to 1.05 s), a hard shake
  and the big explosion sound. The ship is gone until it respawns 2 s later (`RespawnDelay`).

Here the hit stays small, so it never hides the bullets around you. The destruction gets the full treatment: a white-hot
flash, the gold sparks, two shockwaves, shards of the hull in the ship's own colour, and an afterglow that lingers while
the ship is gone.

### 5.1 User parameters

`ASunderShipPawn::SpawnExplosion` sets these:

| Name | Type | Preview default | What the ship sends |
|---|---|---|---|
| `User.Event` | Float | 1 | 0 = a hull hit, 1 = the ship destroyed |
| `User.Color` | Linear Color | (3.5, 2.33, 0.24, 1) | `ExplosionColor`: the web game's gold, the same for every ship |
| `User.AccentColor` | Linear Color | (3.0, 2.1, 0.6, 1) | `DeathColor`: the ship's own colour from the hangar |
| `User.Size` | Float | 80 | `ExplosionSize` (80) × the ship's form scale, so a bigger form bursts bigger |

Make a bool from the event once, in Emitter Spawn: `Emitter.Death = User.Event > 0.5`, and use it in burst counts (a
count of 0 spawns nothing).

### 5.2 Emitters

**System:**
- World space (the ship is hidden or gone while it plays), Fixed Bounds ±1400.
- Effect Type `EFT_PlayerWeapon` (the script sets it): never culled, since your own death must always show.
- Pooled by the script: max 3, primed 1.
- Every emitter: CPU, a Spawn Burst at age 0, Emitter State **Self, Once**.

**A. `Flash`** (both events)
- Burst 1. Lifetime: hit 0.1, death 0.3.
- Size: hit `User.Size × 1.6`; death `User.Size × 6`. Curve 0.5 → 1 → 0 (death: hold near 1 for the first third).
- Colour: `User.Color` lerped 70 % toward white, × 2 for death. Alpha 1 → 0.
- Sprite renderer: `MI_Ship_Flash`, Face Camera Plane.

**B. `Sparks`** (both events): the web game's gold dots
- Burst: hit 20, death 50.
- Shape Location: Sphere, radius `User.Size × 0.2`, then `SP_FlattenToPlane` (WEAPON_VFX §2.3).
- Velocity from Point, flattened to the plane:
  - hit: `User.Size × 1.9` to `User.Size × 11` (150–900 u/s, the web's small burst ×5);
  - death: `User.Size × 3.75` to `User.Size × 20` (300–1600 u/s, its big burst).
- Drag 1.2. Lifetime: hit 0.35–0.7; death 0.35–1.05.
- Size: hit 8–20; death 8–28. Scale 1 → 0 over life.
- Colour `User.Color`, alpha 1 → 0.
- Sprite renderer: `MI_Spark`, Facing Velocity Aligned (stretch about 0.03 × speed).

**C. `Shockwave`** (death only): two rings on the play plane
- Burst `2 × Emitter.Death`. Particle 0 is fast and gold; particle 1 is slower, in the accent colour.
- Lifetime: 0.35 / 0.7.
- Size from `User.Size × 0.5` to `User.Size × 10` / `User.Size × 6`, ease-out.
- Colour `User.Color` / `User.AccentColor`, alpha 1 → 0. Ring thickness (Dynamic Parameter 1) 1 → 0.3.
- Sprite renderer: `MI_ShockRing`, Face Camera Plane.

**D. `Shards`** (death only): the hull coming apart
- Burst `12 × Emitter.Death`.
- Velocity radial on the plane, `User.Size × 2` to `User.Size × 7`. Drag 0.6.
- Lifetime 1.0–1.6. Sprite Rotation random, Rotation Rate ±360°/s.
- Size: a sliver, 6 × 22, so a spinning shard reads as a fragment. Constant until the last 30 % of life, then → 0.
- Colour `User.AccentColor` × 0.8, with a flicker toward white in the first 0.2 s.
- Sprite renderer: `MI_Spark`, Face Camera Plane, non-uniform sprite size.

**E. `Afterglow`** (death only): what's left while the ship is gone
- Burst `1 × Emitter.Death`. Lifetime 1.8 (just under `RespawnDelay`, so it's gone before the ship comes back).
- Size `User.Size × 3`, slowly shrinking to `User.Size × 1.5`.
- Colour `User.AccentColor × 0.35`, alpha 1 → 0 on an ease-in curve (it lingers, then fades).
- Sprite renderer: `MI_Shield_Glow`, Face Camera Plane.

**Budget:** a hit is 21 particles for 0.7 s; the death is 66 for under 2 s. Neither needs care.

## 6. Checks in play (explosion)

1. **Hull hit** with no shield up: a small gold burst, and the ship stays readable inside it. Bullets nearby are
   still visible.
2. **Shield hit:** no gold burst. That's the shield's ripple (§3), not this.
3. **Destroyed:** a white flash, gold sparks flung wide, two rings, shards in the ship's colour (try all three ships in
   the hangar), and a glow that fades just before the respawn.
4. **Forms:** destroyed at form 3 bursts bigger than at form 1. A hit drops the form first, so it bursts at the
   lower form's size.
5. **Game over:** the last life's explosion plays out fully under the Keeper's gloat.

---

## 7. `NS_Ship_Bomb` (one-shot)

The web game's bomb (web/game.html `useBomb`): every enemy shot vanishes, every enemy takes 8 damage (a Keeper 10), the
screen shakes (0.4), and 60 cyan sparks burst 100 px up the screen from the ship (500 units here).

The damage and the wipe happen at once, as in the web game (`ASunderShipPawn::UseBomb`). This system shows it:
- a cyan-white blast ahead of the ship;
- a **shockwave** that sweeps the whole arena in half a second, so you see the bomb reach everything;
- the web game's 60 sparks;
- **a fizzle where every wiped enemy shot was**, popping as the wave passes it, so you can see the bullets go.

### 7.1 User parameters

`ASunderShipPawn::SpawnBombBlast` sets these. The system spawns at the blast's centre (500 units up the screen from the
ship):

| Name | Type | Preview default | What the ship sends |
|---|---|---|---|
| `User.Color` | Linear Color | (0.6, 2.4, 4.0, 1) | `BombColor`: cyan HDR |
| `User.Reach` | Float | 1600 | how far the wave must travel to cover the arena's farthest corner from the blast (about 1250 from mid-arena, up to about 3000 from the top edge) |
| `User.WipedShots` | **Niagara Vector Array** (Array Float3) | empty | each wiped enemy shot's position, as an offset from the blast (Z = 0); at most `MaxBombFizzles` (256) |
| `User.WipedCount` | Int | 0 | how many are in `User.WipedShots` |

Add `User.WipedShots` from the user parameter list's **Array → Vector** type. The ship fills it with
`UNiagaraDataInterfaceArrayFunctionLibrary::SetNiagaraArrayVector`.

Set this once in System Spawn: `System.WaveTime = 0.5` (seconds for the wave to reach `User.Reach`). The fizzles use it.

### 7.2 Emitters

**System:**
- World space, Fixed Bounds ±3000 (it covers the arena from anywhere the blast can be).
- Effect Type `EFT_PlayerWeapon` (the script sets it): never culled.
- Pooled by the script: max 2, primed 1.
- Every emitter: CPU, a Spawn Burst at age 0, Emitter State **Self, Once**.

**A. `Blast`**: the centre
- Burst 2: a white-hot core and a wide glow.
- Core: size 120 → 520 → 0 over 0.3 s, colour `User.Color` lerped 75 % toward white × 2.
- Glow: size 900 → 0 over 0.5 s, colour `User.Color × 0.6`, alpha 1 → 0.
- Sprite renderer: `MI_Ship_Flash`, Face Camera Plane.

**B. `Wash`**: a brief tint over the whole screen
- Burst 1. Lifetime 0.25.
- Size `User.Reach × 2.4` (it covers the arena from the blast).
- Colour `User.Color × 0.12`, alpha 1 → 0 on an ease-out curve.
- Sprite renderer: `MI_Shield_Glow`, Face Camera Plane. Keep it faint: it should feel like a pulse of light, not hide
  the bullets that are left (there are none, but enemies still move).

**C. `Shockwave`**: the wave that reaches everything
- Burst 2: the leading wave and a slower echo.
- Leading wave: lifetime `System.WaveTime`. Size from 100 to `User.Reach × 2` (its diameter), linear, so it reaches
  the farthest corner exactly at 0.5 s. Colour `User.Color`, alpha 1 → 0.6 then → 0 in the last 15 %.
- Echo: lifetime 0.8, size 100 → `User.Reach × 1.2`, ease-out, colour `User.Color × 0.5`, alpha 0.8 → 0.
- Ring thickness (Dynamic Parameter 1): 1 → 0.35 over life.
- Sprite renderer: `MI_Bomb_Wave` (a thick soft ring), Face Camera Plane.

**D. `Sparks`**: the web game's 60
- Burst 60.
- Shape Location: Sphere, radius 60, then `SP_FlattenToPlane` (WEAPON_VFX §2.3).
- Velocity from Point, on the plane, 300–1600 u/s (the web's big burst ×5). Drag 1.2.
- Lifetime 0.35–1.05. Size 8–28, scaled 1 → 0.
- Colour `User.Color`, alpha 1 → 0.
- Sprite renderer: `MI_Spark`, Velocity Aligned (stretch about 0.03 × speed).

**E. `Fizzles`**: one per wiped enemy shot
- Spawn Burst count `User.WipedCount` (0 spawns nothing).
- Particle Spawn:
  - `Particles.Offset` = **Array Get** on `User.WipedShots` at index `Engine.ExecutionIndex`;
  - Position = the system's position + `Particles.Offset`;
  - `Particles.Delay` = `length(Particles.Offset) / User.Reach × System.WaveTime`: when the wave passes it;
  - Lifetime `Particles.Delay + 0.22`.
- Particle Update: `Particles.Local = max(Age − Particles.Delay, 0) / 0.22`.
  - Size: 0 before the wave, then 55 → 0 over `Local`.
  - Colour: the enemy shot's violet (1.3, 0.12, 2.7) at the pop, fading to `User.Color` (the bullet turned to light).
- Sprite renderer: `MI_Spark`, Face Camera Plane.
- Optional: a second burst of 3 tiny sparks per fizzle, using the same offset and delay, for a dense wave.

**Budget:** about 65 particles plus one or two per wiped shot. A bomb in a Keeper's bullet storm (200+ shots) is
about 500 particles for half a second; that's fine on the CPU. If it isn't, move E to GPU: the array works there too.

## 8. Checks in play (bomb)

1. **Blast:** a cyan-white flash 500 units ahead of the ship, wherever the ship is.
2. **Reach:** the leading wave reaches the arena's farthest corner just as it fades, from the bottom corners and from
   the top.
3. **Fizzles:** in a dense wave, every enemy bullet pops as the wave passes it: near ones first, far ones last.
4. **Kills:** enemies burst at once (the damage is instant, as in the web game). Within half a second that reads as the
   bomb's doing.
5. **No bullets:** with no enemy shots on screen, the bomb shows no fizzles and no errors.
6. **Two bombs** quickly: the second plays over the first (the pool holds two).

---

## 9. `NS_Ship_FormChange` (one-shot, rides on the ship)

The web game's form change (web/game.html `collectPowerup`): when the ship rises a form (a Power pickup, or its weapon
pickup again) it swells for 0.4 s, the form's name shows ("FORM: RISING FALCON"), and 24 sparks burst in the ship's
**accent** colour. A hull hit knocks it back a form with only the name.

Unreal already has the swell and the name (`SetPower`, the HUD). This system adds the moment:
- **Rising:** a flash, the web game's 24 sparks, **one ring for each form now reached** (so form 3 reads as three),
  rays of light shooting up the screen (the ascension), and at form 3 a crown of light circling the ship.
- **Falling** (a hit, the ship survives): the light sheds away, down the screen. It's quiet, because the hull hit's
  gold burst (§5) plays at the same moment.

### 9.1 User parameters

`ASunderShipPawn::PlayFormChange` sets these. The system is attached to the ship at its centre, so every emitter that
should stay with the ship uses Local Space **on**.

| Name | Type | Preview default | What the ship sends |
|---|---|---|---|
| `User.Up` | Float | 1 | 1 = rising a form, 0 = knocked back one |
| `User.Form` | Float | 2 | the new form, 1–3 |
| `User.Color` | Linear Color | (0.92, 2.43, 3.5, 1) | `FormColor`: the ship's accent from the web game (Sunborn #8CD9FF sky blue, Scarab #FF8C33 orange, Ibis #BFFFD9 pale green) |
| `User.Size` | Float | 90 | `FormFXSize` (90) × the new form's scale |

Set in Emitter Spawn: `Emitter.Rise = User.Up > 0.5`, `Emitter.Crown = Emitter.Rise && User.Form > 2.5`.

### 9.2 Emitters

**System:**
- Fixed Bounds ±1200 (the rays travel up the screen).
- Effect Type `EFT_PlayerWeapon` (the script sets it): never culled.
- Pooled by the script: max 3, primed 1.
- Every emitter: CPU, Emitter State **Self, Once**. Bursts use counts of 0 to switch an emitter off for the other
  direction.

**A. `Flash`** (Local Space on; rising only)
- Burst `1 × Emitter.Rise`. Lifetime 0.4 (the web game's swell).
- Size `User.Size × 2.4`, curve 0.6 → 1 → 0.
- Colour `User.Color` lerped 50 % toward white, alpha 1 → 0.
- Sprite renderer: `MI_Ship_Flash`, Face Camera Plane.

**B. `Sparks`** (Local Space **off**, so they stay behind as the ship flies; rising only): the web game's 24
- Burst `24 × Emitter.Rise`.
- Velocity radial on the plane, 150–900 u/s (the web's small burst ×5), Drag 1.2.
- Lifetime 0.35–0.7. Size 8–20 → 0. Colour `User.Color`, alpha 1 → 0.
- Sprite renderer: `MI_Spark`, Velocity Aligned.

**C. `FormRings`** (Local Space on; rising only): the form, as a count
- Burst `round(User.Form) × Emitter.Rise`: 2 rings at form 2, 3 at form 3.
- Each ring `i` (`Engine.ExecutionIndex`, 0-based) waits `0.09 × i` s: alpha 0 until then (as the bomb's fizzles do
  in §7.2 E).
- Lifetime `0.45 + 0.09 × i`. Size from `User.Size × 0.6` to `User.Size × (2.2 + 0.7 × i)`, ease-out.
- Colour `User.Color`, alpha 1 → 0. Ring thickness (Dynamic Parameter 1) 1 → 0.3.
- Sprite renderer: `MI_Shield_Ring`, Face Camera Plane.

**D. `Rays`** (Local Space on; rising only): light shooting up the screen
- Burst `7 × Emitter.Rise`.
- Position: across the ship, Y spread `±User.Size × 0.6`; X from `−User.Size × 0.3` to 0.
- Velocity +X (up the screen) 900–1500 u/s, no drag.
- Lifetime 0.35–0.55.
- Sprite size: 10–16 across × `User.Size × 1.4` long. Alpha 0 → 1 → 0.
- Colour `User.Color` lerped 30 % toward white.
- Sprite renderer: `MI_Form_Ray`, Facing **Velocity Aligned**, non-uniform size, so each ray is a streak up the screen.

**E. `Crown`** (Local Space on; rising to form 3 only)
- Burst `8 × Emitter.Crown` at 0.15 s.
- Placed evenly on a circle of radius `User.Size × 1.3` around the ship; orbit it at 1.2 turns/s (rotate the position
  by `Age × 1.2 × 2π` around Z, or use a Vortex Force with a Point Attraction holding the radius).
- Lifetime 0.9. Size 14 → 22 → 0. Colour `User.Color` toward white, alpha 0 → 1 → 0.
- Sprite renderer: `MI_Spark`, Face Camera Plane.

**F. `Shed`** (Local Space **off**; falling only): the form's light falling away
- Burst `10 × (1 − Emitter.Rise)`.
- Shape: a ring of radius `User.Size × 1.2` around the ship.
- Velocity −X (down the screen) 150–350 u/s plus a little outward drift, Drag 1.5.
- Lifetime 0.45–0.6. Size 10–16 → 0. Colour `User.Color × 0.5`, alpha 0.8 → 0.
- Plus one ring (a second particle set in the same emitter, or a tiny emitter beside it): size `User.Size × 2.2` →
  `User.Size × 1.1` over 0.3 s, colour `User.Color × 0.4`, alpha 0.7 → 0: the aura closing in.
- Sprite renderers: `MI_Spark` (motes), `MI_Shield_Ring` (ring).

**Budget:** a rise to form 3 is about 43 particles for under a second; a fall is 11. Nothing to watch.

## 10. Checks in play (form change)

1. **Rise to form 2:** a flash, sparks in the ship's accent, **two** rings, rays up the screen, and the name.
2. **Rise to form 3:** **three** rings and the crown circling the ship.
3. **Accent per ship:** sky blue for the Sunborn, orange for the Scarab, pale green for the Ibis (pick each in the
   hangar). If every ship bursts sky blue, run `create_ship_models.py` again: it saves the ship list into
   `BP_SunderGameMode`, and a list saved before the accents existed holds the default for all three.
4. **Flying:** rise while strafing. The rings, rays and crown stay with the ship, and the sparks stay behind.
5. **Hit at form 2 or 3:** light sheds down the screen with the hull hit's gold burst. No rings, no rays.
6. **Killing hit or respawn:** no form effect. A killing hit shows only the explosion, and a respawn resets the form
   quietly.
7. **Weapon switch** (Spread ↔ Laser): no form effect, because the form doesn't change.
