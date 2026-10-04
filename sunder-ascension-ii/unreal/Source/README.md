# SUNDER II — drop-in UE5 C++ for the weapon VFX

C++ side of [`../WEAPON_VFX.md`](../WEAPON_VFX.md). Written for UE 5.3+ (5.1 minimum: it uses `UE_SMALL_NUMBER`).

> **Status:** written without an Unreal install, so **not compiled yet**. Expect to fix small API differences on the
> first build; the comments say what each piece is for, so fixes stay local.

| File | What it is | Guide |
|---|---|---|
| `BeamWeaponComponent` | Actor component: persistent beam, sphere trace each frame, sets `BeamStart`/`BeamEnd`/`bHit`/`HitNormal`/`Intensity` on `NS_Laser_Beam`, ramps in and out, interval damage | §1.6 |
| `ImpactFXSubsystem` (+ `UImpactFXSettings`) | World subsystem: `QueueImpact`, merges hits on the same spot, caps full effects per frame, spawns pooled (`AutoRelease`) | §3.2 |
| `SunderProjectile` | Pooled plasma shot: overlap → queue impact, apply damage, return to the pool; times out off-screen | §3.4 |
| `ProjectilePoolSubsystem` | World subsystem: `Acquire` / `Release` / `Prewarm`, per-class free lists | §3.4 |

## Install

1. Copy `Sunder2/Public/*` and `Sunder2/Private/*` into your game module, e.g. `Source/<YourGame>/Public` and
   `Source/<YourGame>/Private`. If your module has no Public/Private split, put all eight files in `Source/<YourGame>/`.
2. Replace `SUNDER2_API` with your module's export macro (`<YOURGAME>_API`) in the four headers.
3. In `Source/<YourGame>/<YourGame>.Build.cs`, add to `PublicDependencyModuleNames`:
   ```csharp
   "Niagara", "DeveloperSettings"
   ```
   (`Core`, `CoreUObject` and `Engine` are already there in a standard game module.)
4. Enable the **Niagara** plugin (on by default), regenerate project files, and build `<YourGame>Editor` (Development Editor).

## Hook up

- **Project Settings → Game → Sunder Impact FX:** set `ImpactFX` to `NS_PlasmaBurst_Impact` and `ImpactFXLite` to the
  lite version. The defaults (merge 40 units, 10 full impacts per frame) match the guide.
- **Collision:** add a trace channel `PlayerWeapon` (Project Settings → Collision) and set it as the beam's
  `TraceChannel`. Give enemies a response of Block to it. Give the projectile's sphere your own projectile profile
  (it defaults to `OverlapAllDynamic`).
- **Ship Blueprint:**
  - Add a `BeamWeapon` component, set `BeamSystem = NS_Laser_Beam`, and give the ship mesh a `Muzzle` socket.
  - Fire input pressed → `StartFire`; released → `StopFire`.
- **Plasma shots:**
  - Make a Blueprint child of `SunderProjectile`, assign its trail system and tweak damage, speed and colour.
  - Fire with `Get ProjectilePoolSubsystem → Acquire (Class, Muzzle location, (1,0,0), Self, Self)`.
  - In the level Blueprint or game mode BeginPlay, call `Prewarm (Class, 200)`.

## First checks after it compiles

1. Beam: stops on an enemy, grows back smoothly when the enemy dies, never lags the ship while strafing.
2. Impacts: `stat Niagara` stays flat with the §3.6 stress test (60 queued impacts a frame).
3. Pools: `GetTotalCreated` on the projectile pool and the Niagara Debugger's pooled-component count plateau rather
   than climbing.
