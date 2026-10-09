# SUNDER: Ascension II — UE5 enemy VFX: the enemy shot trail and the enemy explosion (Niagara)

Two systems for the regular enemies (the Keepers have their own, in [`KEEPER_VFX.md`](KEEPER_VFX.md)):
- `NS_Enemy_Shot` (§1–§4): every enemy bullet;
- `NS_Enemy_Explosion` (§5–§6): every enemy shot down.

`NS_Enemy_Shot` is the look of every regular enemy's bullet (`BP_EnemyShot`). It follows the web game's enemy bullet
(web/game.html `enemy_bullet`): a violet orb (#9B30D6) with a pale lavender core, 12 px across (about 60 units here).

> **Status:** written guidance, not yet built or run in-engine (no Unreal where it was written).
> [`Scripts/create_enemy_fx_assets.py`](Scripts/create_enemy_fx_assets.py) makes the materials, the Effect Types and
> the two empty systems. It sets `NS_Enemy_Shot` as the Trail of `BP_EnemyShot` with its size, and `NS_Enemy_Explosion`
> as the Explosion FX of the five enemy Blueprints with their sizes. The emitters below are built by hand. Module names
> are from UE 5.3–5.5.

Read [`WEAPON_VFX.md`](WEAPON_VFX.md) §0 first: Unlit, Additive, flat on the play plane. The system reuses
`MI_PlasmaTendril` from there.

**Nothing breaks while you build.** Until a system has an emitter, the game uses its stand-in: the shot shows its
placeholder bolt (hidden by itself once `NS_Enemy_Shot` has an emitter, in `ASunderProjectile::BeginPlay`), and enemies
burst in the shared plasma impacts (replaced once `NS_Enemy_Explosion` has one, in `ASunderEnemy::SpawnExplosion`).

---

## 1. What it has to do

Enemy bullets are the thing the player reads most. They must stand out from:
- the player's own gold and blue shots;
- the Keepers' bullets, which are in each Hour's colour, bigger, with a comet tail;
- the stage backdrops.

So the enemy shot is **small, round and violet, with a bright core and almost no tail**. It reads as "dodge this"
rather than as a streak. There can be many at once (a bomber's ring is 12), so it stays cheap.

## 2. User parameters

The shot hands these to its trail every time it's fired (`ASunderProjectile::Fire`, then `ResetSystem`):

| Name | Type | Preview default | Value |
|---|---|---|---|
| `User.ShotColor` | Linear Color | (1.3, 0.12, 2.7, 1) | the shot's `PlasmaColor`: the web game's violet (set on `BP_EnemyShot` by the script) |
| `User.ShotSize` | Float | 30 | `TrailSize` on `BP_EnemyShot`: 30 |

(`User.Heavy` is also sent, always 0 here; the system doesn't need it.)

## 3. `NS_Enemy_Shot`

**System:**
- Fixed Bounds ±120.
- Effect Type `EFT_EnemyShot` (made by the script): **never culled**. A bullet whose look was culled would still hit
  you, so cut the cost in the emitters instead (see Budget).
- No pooling settings: the trail lives on the pooled shot, and the shot pool does the pooling.

**A. `Orb`** (CPU, Local Space **on**, 2 particles)
- Spawn Burst 2, Lifetime 9999.
- Particle 0 is the glow:
  - size `User.ShotSize × (1.0 + 0.08 × sin(Age × 24))`, a faint throb so bullets feel alive;
  - colour `User.ShotColor`.
- Particle 1 is the core:
  - size `User.ShotSize × 0.38`;
  - colour pale lavender (3.6, 3.0, 4.0), the web's #F5E0FF made bright;
  - set slightly up the screen from centre (+X × 0.08 × `User.ShotSize`), like the web sprite's highlight.
- Sprite renderer: Face Camera Plane, `MI_Enemy_Shot`.

**B. `Wake`** (CPU, Local Space **off**): a very short smear, only enough to show which way it's moving
- Spawn Rate: 40.
- Lifetime: 0.05.
- RibbonLinkOrder = `Engine.Emitter.Age`.
- Width: `User.ShotSize × 0.4` → 0.
- Colour: `User.ShotColor × 0.45` → 0.
- Ribbon renderer: `MI_PlasmaTendril`, Screen facing.

That's all: two emitters and three particles plus a short ribbon per bullet.

**Budget:**
- Aim for 300 enemy shots under about 1 ms in `stat Niagara`.
- If a dense wave goes over, drop the Wake first.
- Past that, use the single-system bullet renderer in WEAPON_VFX §3.5.

## 4. Checks in play

1. **Colour:** enemy shots are violet dots with a bright core. They never look like your gold or blue shots, or the
   Keepers' comets.
2. **Speed:** shots fired faster in later Hours (the wave set's shot speed scale) show a slightly longer wake, and nothing else changes.
3. **Hits:** shots hitting your ship burst in the same violet (the impact uses the shot's `PlasmaColor`).
4. **Placeholder:** the placeholder bolt is gone once the system has an emitter.

---

## 5. `NS_Enemy_Explosion`

The web game's kill (web/game.html `enemyKilled` → `explode`): a spray of dots in the **stage's colour**, flung out in
every direction and slowing as they fade.
- A normal kill throws 14 sparks at 30–180 px/s, living 0.35–0.7 s.
- A bomber's throws 26 at 60–320 px/s, living up to 1.05 s, and shakes the screen harder.

Here it keeps those numbers (×5 for units) and adds a flash and a ring, so a kill reads at a glance at 4K with bloom.

### 5.1 User parameters

`ASunderEnemy::SpawnExplosion` sets these when the enemy is shot down:

| Name | Type | Preview default | Value |
|---|---|---|---|
| `User.Color` | Linear Color | (3.0, 1.13, 0.32, 1) | the enemy's `DeathColor`. In an Hour, that's the Hour's colour (the wave set's Explosion Tint, set by `create_hour_waves.py`); elsewhere, the enemy's own |
| `User.Size` | Float | 40 | the enemy's `ExplosionSize` (Scout 40, Diver 36, Skimmer 40, Gunship 64, Bomber 80) |
| `User.Big` | Float | 0 | 1 for the bomber (`bBigBurst`): the web game's big burst |

Make `User.Big` a float (0/1) so it can scale numbers directly: `lerp(a, b, User.Big)`.

### 5.2 Emitters

**System:**
- Fixed Bounds ±600 (the big burst's sparks travel about 1300 units at most before drag stops them; they're faded by
  then, so a little clipping at the edge is fine).
- Effect Type `EFT_EnemyExplosion` (made by the script): at most 48 at once. Unlike bullets, a skipped explosion
  changes nothing in play, and a bomb can shoot down a screenful in one frame.
- Pooled by the script: max 48, primed 16. Each burst goes back to the pool when its emitters finish.
- Every emitter: CPU, Local Space **off**, a one-shot Spawn Burst at age 0 and Emitter State **Self, Once** (so the
  system completes and returns to the pool).

**A. `Flash`**: the moment of the kill
- Burst 1. Lifetime 0.14 (Big: 0.2).
- Size: `User.Size × lerp(2.6, 3.4, User.Big)`, curve 0.6 → 1 → 0 over its life (a quick swell, then gone).
- Colour: `User.Color × 1.6`, lerped 60 % toward white, alpha 1 → 0.
- Sprite renderer: `MI_Enemy_Flash`, Face Camera Plane.

**B. `Sparks`**: the web game's dots
- Burst `lerp(14, 26, User.Big)`.
- Shape Location: Sphere, radius `User.Size × 0.25`, then `SP_FlattenToPlane` (WEAPON_VFX §2.3).
- Add Velocity from Point: speed random `User.Size × 3.75` to `User.Size × lerp(22.5, 20, User.Big)`.
  - With the sizes above that's 150–900 u/s for a Scout and 300–1600 for a bomber, the web's speeds ×5.
  - Flatten the velocity to the play plane too (Z = 0).
- Drag 1.2 (the web game's ×0.98 a frame at 60 fps).
- Lifetime random 0.35 to `lerp(0.7, 1.05, User.Big)`.
- Sprite size random 8 to `lerp(20, 28, User.Big)`, scaled 1 → 0 over life.
- Colour `User.Color`, alpha 1 → 0 over life.
- Sprite renderer: `MI_Enemy_Spark`, Facing **Velocity Aligned** with a stretch of about 0.03 × speed, so fast sparks
  read as short streaks.

**C. `Ring`**: a shockwave on the play plane
- Burst 1. Lifetime `lerp(0.25, 0.4, User.Big)`.
- Size `User.Size × 0.5` → `User.Size × lerp(3, 5, User.Big)`, ease-out.
- Colour `User.Color × 0.8`, alpha `lerp(0.5, 1, User.Big)` → 0.
- Sprite renderer: `MI_Enemy_Ring`, Face Camera Plane. Dynamic Parameter 1 (ring thickness) 1 → 0.4 over life.

**D. `Embers`**: the bomber's slow debris (Big only)
- Burst `6 × User.Big` (none for a normal kill).
- Velocity: radial, `User.Size × 1–3`, on the plane. Drag 0.8.
- Lifetime 0.8–1.3.
- Size 14–22, constant until the last 30 % of life, then → 0.
- Colour: `User.Color × 0.5` toward a dim ember (0.6, 0.25, 0.1), with a flicker (`SP_KeeperPulse` from KEEPER_VFX
  §1.3, or a sine on Age with a random phase).
- Sprite renderer: `MI_Enemy_Spark`, Face Camera Plane.

### 5.3 Budget

- A normal kill: 16 particles for under 0.8 s. A bomber: 34.
- A bomb clearing 40 enemies at once: about 650 particles for a moment, well inside one CPU frame in `stat Niagara`.
- If that spikes: lower the Sparks count first; past that, move B to GPU (it has no per-particle logic that needs the
  CPU).

## 6. Checks in play

1. **Colour:** in each Hour, kills burst in its colour (amber in Hour 1, violet in Hour 12). In the test arena without
   an Hour, they use each enemy's own Death Color.
2. **Size:** a Scout's burst is a quick pop; a bomber's is clearly bigger, with a wide ring and embers that linger.
3. **Bomb:** set off a bomb in a dense wave. Every enemy bursts, the frame doesn't hitch, and only one explosion sound
   plays (`ASunderGameMode::PlayExplosion` skips repeats).
4. **Pool:** after a long fight, `fx.Niagara.Debug.PoolStats` (or the Niagara debugger) shows `NS_Enemy_Explosion`
   recycling, not growing.
5. **Keepers:** they keep their own death (KEEPER_VFX.md §6); this system isn't on them.
