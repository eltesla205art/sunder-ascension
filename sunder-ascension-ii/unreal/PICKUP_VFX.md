# SUNDER: Ascension II — UE5 pickup VFX: the collect effect (Niagara)

`NS_Pickup_Collect` plays when the ship flies into a power-up (`ASunderPickup::PlayCollect`). The gem breaks into light
in its own colour, and the light is drawn into the ship.

The web game has no collect effect of its own: a pickup just vanishes with its chime, and only a form change bursts
(24 sparks in the ship's colour, already in Unreal as `SetPower`'s impact). This adds the moment of taking it, kept
small and quick so it never hides bullets.

> **Status:** written guidance, not yet built or run in-engine (no Unreal where it was written).
> [`Scripts/create_pickup_fx_assets.py`](Scripts/create_pickup_fx_assets.py) makes the materials and the empty, pooled
> system and sets it as `BP_SunderPickup`'s Collect FX. The emitters below are built by hand. Module names are from
> UE 5.3–5.5.

Read [`WEAPON_VFX.md`](WEAPON_VFX.md) §0 first: Unlit, Additive, flat on the play plane. This system reuses its
`SP_FlattenToPlane`.

**Nothing breaks while you build.** Until the system has an emitter, a collected pickup shows one plasma impact in its
colour.

---

## 1. How it's placed

- The system is **attached to the ship**, starting where the gem was (`SpawnSystemAttached`, Keep World Position). So
  it moves with the ship: light drawn into the ship still reaches it while you fly on.
- Emitters that should stay where the gem broke (the Pop) use **Local Space off**. Emitters that should follow the
  ship (Motes, Halo, Lift) use **Local Space on**.
- In local space the ship's centre is at `User.ToShip`. (The ship actor never turns in this game, so world and local
  axes agree.)

## 2. User parameters

| Name | Type | Preview default | What the pickup sends |
|---|---|---|---|
| `User.Color` | Linear Color | (4.0, 2.6, 0.24, 1) | the kind's colour, brightest channel at `CollectGlow` (4): Spread red, Laser blue, Power gold, Bomb amber, Shield cyan, Life rose |
| `User.Kind` | Float | 2 | 0 Spread, 1 Laser, 2 Power, 3 Bomb, 4 Shield, 5 Life |
| `User.Size` | Float | 140 | the gem's size (`MeshSize`) |
| `User.ToShip` | Vector | (−60, 0, 0) | the ship's centre from where the gem was, in units |

Handy flags, set once in Emitter Spawn:
- `Emitter.IsShield = abs(User.Kind − 4) < 0.5`
- `Emitter.IsLife = abs(User.Kind − 5) < 0.5`

## 3. `NS_Pickup_Collect`

**System:**
- Fixed Bounds ±400.
- Effect Type `EFT_PlayerWeapon` (the script sets it): never culled.
- Pooled by the script: max 6, primed 2.
- Every emitter: CPU, a Spawn Burst at age 0, Emitter State **Self, Once**.

**A. `Pop`** (Local Space **off**): the gem breaks
- Burst 2 sprites:
  - a flash: size `User.Size × 1.4` → 0 over 0.12 s, colour `User.Color` lerped 50 % toward white;
  - a thin ring: size `User.Size × 0.4` → `User.Size × 1.3` over 0.2 s, ease-out, colour `User.Color`, alpha 1 → 0
    (`MI_Pickup_Ring`).
- Plus a burst of 8 facets: velocity radial on the plane, 250–500 u/s, Drag 4, lifetime 0.18–0.3, size 10–16 → 0,
  colour `User.Color`.
- Sprite renderers: `MI_Pickup_Mote` (flash, facets), `MI_Pickup_Ring` (ring). Face Camera Plane.

**B. `Motes`** (Local Space **on**): the light drawn into the ship
- Burst 14.
- Shape Location: Sphere, radius `User.Size × 0.35`, flattened to the plane (around the gem's spot, the local origin).
- Initial velocity: radial outward, 150–300 u/s, so they bloom out before being pulled in.
- **Point Attraction Force:** position `User.ToShip`, strength 6000, radius 1000, falloff 0, kill radius 20.
- Drag 2.5. Lifetime 0.35–0.5 (most are pulled into the ship and killed before then).
- Size 8–14, colour `User.Color`, alpha 1 → 0 over the last 30 % of life.
- Sprite renderer: `MI_Pickup_Mote`, Velocity Aligned (stretch about 0.02 × speed), so they streak toward the ship.

**C. `Halo`** (Local Space **on**): the ship takes it in
- Burst `1 − Emitter.IsShield` (none for a shield: the shield's own gather plays then, SHIP_VFX.md §3).
- Position `User.ToShip`. Spawn it 0.12 s after the others (Spawn Burst Time 0.12), as the motes arrive.
- Lifetime 0.25. Size 260 → 90, ease-in: it closes onto the ship.
- Colour `User.Color × 0.8`, alpha 0 → 1 → 0.
- Sprite renderer: `MI_Pickup_Ring`, Face Camera Plane.

**D. `Lift`** (Local Space **on**, Life only): a gentle rise of light over the ship
- Burst `6 × Emitter.IsLife` at 0.15 s.
- Position `User.ToShip` + a random offset of up to 50 across.
- Velocity +X (up the screen) 120–220 u/s, Drag 1.
- Lifetime 0.6–0.8. Size 10 → 18 → 0. Colour `User.Color` toward white, alpha 1 → 0.
- Sprite renderer: `MI_Pickup_Mote`, Face Camera Plane.

**Budget:** about 26 particles for half a second, 32 for a Life. Nothing to watch.

## 4. Checks in play

1. **Colour:** each kind's burst matches its gem: red Spread, blue Laser, gold Power, amber Bomb, cyan Shield, rose
   Life.
2. **Follows the ship:** collect a pickup while flying sideways at full speed. The motes still land in the ship, and
   the Pop stays where the gem was.
3. **Shield:** no Halo, and the shield's gather plays instead, with no doubling.
4. **Life:** a soft rise of light over the ship.
5. **Power / weapon level-up:** the form change still bursts in the ship's colour (its own effect) along with this one.
6. **Two quick pickups:** both play (the pool holds six).
