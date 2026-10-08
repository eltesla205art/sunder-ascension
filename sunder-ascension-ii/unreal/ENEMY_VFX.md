# SUNDER: Ascension II — UE5 enemy VFX: the enemy shot trail (Niagara)

`NS_Enemy_Shot` is the look of every regular enemy's bullet (`BP_EnemyShot`). It follows the web game's enemy bullet
(web/game.html `enemy_bullet`): a violet orb (#9B30D6) with a pale lavender core, 12 px across (about 60 units here).

> **Status:** written guidance, not yet built or run in-engine (no Unreal where it was written).
> [`Scripts/create_enemy_fx_assets.py`](Scripts/create_enemy_fx_assets.py) makes the material, an Effect Type and the
> empty system, and sets it as the Trail of `BP_EnemyShot` with its size. The emitters below are built by hand. Module
> names are from UE 5.3–5.5.

Read [`WEAPON_VFX.md`](WEAPON_VFX.md) §0 first: Unlit, Additive, flat on the play plane. The system reuses
`MI_PlasmaTendril` from there.

**Nothing breaks while you build.** Until the system has an emitter, the shot shows its placeholder bolt. As soon as it
has one, the bolt hides itself (`ASunderProjectile::BeginPlay`).

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
