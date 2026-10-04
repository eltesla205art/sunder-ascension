# SUNDER II — drop-in UE5 C++ for the weapons and the test arena

C++ side of [`../WEAPON_VFX.md`](../WEAPON_VFX.md), plus the ship, a target and a game mode for the test arena. Written for UE 5.3+ (5.1 minimum: it uses `UE_SMALL_NUMBER`).

> **Status:** written without an Unreal install, so **not compiled yet**. Expect to fix small API differences on the
> first build; the comments say what each piece is for, so fixes stay local.

| File | What it is | Guide |
|---|---|---|
| `BeamWeaponComponent` | Actor component: persistent beam, sphere trace each frame, sets `BeamStart`/`BeamEnd`/`bHit`/`HitNormal`/`Intensity` on `NS_Laser_Beam`, ramps in and out, interval damage | §1.6 |
| `ImpactFXSubsystem` (+ `UImpactFXSettings`) | World subsystem: `QueueImpact`, merges hits on the same spot, caps full effects per frame, spawns pooled (`AutoRelease`) | §3.2 |
| `SunderProjectile` | Pooled plasma shot: overlap → queue impact, apply damage, return to the pool; times out off-screen | §3.4 |
| `ProjectilePoolSubsystem` | World subsystem: `Acquire` / `Release` / `Prewarm`, per-class free lists | §3.4 |
| `SunderShipPawn` | The player ship: eight-way movement clamped to the arena, held beam, held twin plasma shots from the pool; input built at runtime with Enhanced Input (no input assets) | — |
| `SunderTargetDummy` | Drifting target: takes beam and shot damage, swells when hit, bursts with an impact and respawns | — |
| `SunderGameMode` | Game mode whose default pawn is the ship (the Blueprint child points it at `BP_SunderShip`) | — |

## Install

1. Copy `Sunder2/Public/*` and `Sunder2/Private/*` into your game module, e.g. `Source/<YourGame>/Public` and
   `Source/<YourGame>/Private`. If your module has no Public/Private split, put all fourteen files in `Source/<YourGame>/`.
2. Replace `SUNDER2_API` with your module's export macro (`<YOURGAME>_API`) in the seven headers.
3. In `Source/<YourGame>/<YourGame>.Build.cs`, add to `PublicDependencyModuleNames`:
   ```csharp
   "Niagara", "DeveloperSettings", "EnhancedInput", "InputCore"
   ```
   (`Core`, `CoreUObject` and `Engine` are already there in a standard game module.)
4. Enable the **Niagara** and **Enhanced Input** plugins (both on by default in UE5), regenerate project files, and
   build `<YourGame>Editor` (Development Editor).

## Assets and the arena (editor scripts, Tools → Execute Python Script)

1. [`../Scripts/create_weapon_fx_assets.py`](../Scripts/create_weapon_fx_assets.py): materials, Effect Types and empty `NS_*`
   systems; build the emitters by hand from the guide.
2. [`../Scripts/create_arena_level.py`](../Scripts/create_arena_level.py): `BP_PlasmaShot`, `BP_SunderShip`, `BP_SunderGameMode` and the
   `L_SunderArena` level (ortho top-down camera, floor, light, player start, three target dummies, bloom). Open the
   level and press Play: **W A S D** move, **Space** beam, **J** shoot (gamepad: left stick, right trigger, A).

## Hook up

- **Project Settings → Game → Sunder Impact FX:** set `ImpactFX` to `NS_PlasmaBurst_Impact` and `ImpactFXLite` to the
  lite version. The defaults (merge 40 units, 10 full impacts per frame) match the guide.
- **Collision:** the beam traces the built-in Visibility channel, so it works straight away. For a real game, add a
  `PlayerWeapon` trace channel (Project Settings → Collision), set it as the beam's `TraceChannel`, and have enemies block it. Give the projectile's sphere your own projectile profile
  (it defaults to `OverlapAllDynamic`).
- **Ship:** `create_arena_level.py` makes `BP_SunderShip` with the beam and shots wired up. To use the beam on another
  actor instead, add a `BeamWeapon` component, set `BeamSystem = NS_Laser_Beam`, give its mesh a `Muzzle` socket, and
  call `StartFire` / `StopFire` from input.
- **Plasma shots:** `BP_PlasmaShot` (made by the script) is a small glowing bolt until you give its Trail component a
  system. Other actors can fire it with `Get ProjectilePoolSubsystem → Acquire (Class, location, (1,0,0), Self, Self)`;
  the ship prewarms 120 at BeginPlay.

## First checks after it compiles

1. Beam: stops on an enemy, grows back smoothly when the enemy dies, never lags the ship while strafing.
2. Impacts: `stat Niagara` stays flat with the §3.6 stress test (60 queued impacts a frame).
3. Pools: `GetTotalCreated` on the projectile pool and the Niagara Debugger's pooled-component count plateau rather
   than climbing.
