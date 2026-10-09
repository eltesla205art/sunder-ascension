# SUNDER II — drop-in UE5 C++ for the weapons, the ship, enemies, waves, the Keepers, the title screen and hangar, story mode with the hour map, and the music and sound of all of them

C++ side of [`../WEAPON_VFX.md`](../WEAPON_VFX.md) and [`../KEEPER_VFX.md`](../KEEPER_VFX.md), plus the ship, enemies, waves, the twelve Keeper bosses, scoring and a HUD for the test arena. Written for UE 5.3+ (5.1 minimum: it uses `UE_SMALL_NUMBER`).

> **Status:** written without an Unreal install, so **not compiled yet**. Expect to fix small API differences on the
> first build; the comments say what each piece is for, so fixes stay local.

| File | What it is | Guide |
|---|---|---|
| `BeamWeaponComponent` | Actor component: persistent beam, sphere trace each frame, sets `BeamStart`/`BeamEnd`/`bHit`/`HitNormal`/`Intensity` on `NS_Laser_Beam`, ramps in and out, interval damage | §1.6 |
| `ImpactFXSubsystem` (+ `UImpactFXSettings`) | World subsystem: `QueueImpact`, merges hits on the same spot, caps full effects per frame, spawns pooled (`AutoRelease`) | §3.2 |
| `SunderProjectile` | Pooled plasma shot: overlap → queue impact, apply damage, return to the pool; times out off-screen; `SetShotColor` recolours one shot; hands its trail `TrailSize`, its `PlasmaColor` (as `ShotColor`) and `bHeavyTrail`, and hides its placeholder bolt once the trail system is built | §3.4 |
| `ProjectilePoolSubsystem` | World subsystem: `Acquire` / `Release` / `Prewarm`, per-class free lists | §3.4 |
| `SunderShipPawn` | The player ship: eight-way movement clamped to the arena, held beam, held plasma shots from the pool in the chosen ship's style (Sunborn twin spread, Scarab heavy cannon, Ibis rapid stream; `ApplyLoadout`), flown as the ship's own model (turned nose-up, sized, guns at its nose); the web game's power-ups (Spread / Laser weapons, three forms per ship with more guns and ×power damage (a Niagara form change in the ship's accent: one ring per form, light up the screen — SHIP_VFX.md §9), bombs on X / K / Y that hit everything and wipe enemy shots (a Niagara blast whose shockwave sweeps the arena, popping each wiped shot as it passes — SHIP_VFX.md §7), shields that soak a whole hit (a Niagara shield that grows with the layers and the ship's form, ripples, shatters and gathers — SHIP_VFX.md — with a placeholder disc until it is built), Life up to 2 over full; a hull hit costs a form) with the web game's pickup, bomb and hit sounds, a 5-hit hull with blinking invulnerability, death and respawn (a Niagara explosion for a hull hit and for its destruction — SHIP_VFX.md §5 — with plasma impacts until it is built) and a Niagara warp-in on respawn (light gathers, it flashes in, then shimmers — SHIP_VFX.md §11); input built at runtime with Enhanced Input (no input assets) | — |
| `SunderPickup` | A falling power-up (Spread, Laser, Power, Bomb, Shield, Life): each kind's faceted gem from `blender/pickups.py` (`KindMeshes`), tilting to catch the light, or a placeholder diamond with its letter; dropped by enemies at the Hour's rate (bombers more), collected by flying into it, breaking into light in its colour that's drawn into the ship (PICKUP_VFX.md; a plasma impact until it is built) | — |
| `SunderTargetDummy` | Drifting target: takes beam and shot damage, swells when hit, bursts with an impact and respawns | — |
| `SunderGameMode` | Default pawn = the ship, flown as the hangar's choice (`Ships`: the web game's three ships in Unreal units; `?Ship=` / `?Mode=` also work on the URL); Swarm mode; score, 3 lives, respawn after 2 s, DAWN DENIED and a restart (or back to `MenuLevel`, the title; in story mode, DAWN DENIED on the story level) when the last life goes; wave banner; tracks the active Keeper | — |
| `SunderEnemy` | Enemy craft: moves Straight / Weave / Dive / Strafe / Zigzag, fires Aimed / Spread / Radial from the pool, rams, flashes when hit, bursts and scores on death (a Niagara explosion in its Death Color, the Hour's colour in an Hour — ENEMY_VFX.md §5 — with the plasma impacts until it's built); each type is a Blueprint child | — |
| `SunderKeeper` | Keeper boss (child of `SunderEnemy`): holds off-screen for its intro card (`IntroHold`, the web game's 2.4 s), then enters invulnerable, fits its model to the screen, strafes; three phases (66% / 33%) that fire faster and dash in phase 3; eight attack patterns ported from the web game (Aimed Volley, Spread Fan, Horizontal Sweep, Radial Burst, Cross Ring, Spiral, Dual Spiral, Wall Barrage) rotating every 3.5 s; optional final-form mesh; a two-second death (shudder, bursts across the body, then the final burst); spawns its Niagara effects (aura, arrival Gate, muzzle flares, phase shockwave, death) and tints its shots, falling back to the plasma impacts for any system not built yet; plays its battle theme (building a layer per phase, Apep's final-form theme in phase 3) and its voice (intro, attack, phase, hurt, death, and a gloat at DAWN DENIED) | Keeper VFX |
| `SunderMusicSubsystem` | World subsystem: layered music like the web game's: a theme's three same-length loops start together and crossfade by layer; `Duck` steps the music back under a voice; one theme at a time with fades. Also the current stage's sound: its ambience bed (fading between stages), its theme and its rate-limited cues | — |
| `SunderFrontEndGameMode` | Base for the screens outside the arena: no pawn, `SunderMenuController` input (Confirm / Back / Navigate), cues that can wait a beat and duck the music | — |
| `SunderLoadoutSubsystem` | Game instance subsystem: the hangar's ship and mode, kept across level loads (story mode passes through the story level first) | — |
| `SunderMenuGameMode` | The title screen and hangar: Start → choose a ship (A / D) and Story / Swarm (W / S) → Launch: Story opens the story level, Swarm the arena (with `?Ship=` / `?Mode=`), Esc back; plays each screen's theme and ambience, the interface cues, and each ship's engine rev when picked and at launch | — |
| `SunderMenuController` | Input for every front-end screen, built at runtime with Enhanced Input (keys, D-pad, left stick, A / B / Start) | — |
| `SunderMenuHUD` | Canvas drawing for the title (title art, name, blinking prompt) and hangar (ship sprites in their colours, mode, hints, launch fade) | — |
| `SunderStoryData` | Data asset (header only): the story's words (from `web/game.html`), its twelve Hours (name, act, Keeper, briefing, gate-open line, act interlude, stage sound, Keeper Blueprint, own wave set, backdrop, portrait), the enemy waves, and the story screens' music and cues | — |
| `SunderStorySubsystem` | Game instance subsystem: the campaign across level loads (next Hour, score, which story screen to show); builds the arena's wave set for the current Hour and takes its result | — |
| `SunderStoryGameMode` | The story screens with the web game's sound and timing: opening crawl (lament + wind), hour map (theme builds act by act), briefing (drone over the Hour's own ambience), Hour survived (bell and interlude theme between acts), dawn, DAWN DENIED | — |
| `SunderStoryHUD` | Canvas drawing for those screens: the crawl, the hour map as in the web game (its road of twelve gates snaking up through four acts toward a glow of dawn, opened gates gold, the next ringed and pulsing, a spark travelling the last road), briefings over the Hour's backdrop with its Keeper's portrait in the Hour's glow, revealed line by line, the Hour-survived screen with its rewards, the ending under a breaking dawn (the sun climbing over a warming horizon), DAWN DENIED as a dull red sun sinks and its glow goes out, wrapped story text | — |
| `SunderStageAudio` | Data asset (header only): one Hour's (or menu screen's) theme layers, ambience, and Start / Wave / Down / Clear cues | — |
| `SunderWaveSet` | Data asset: waves of spawn groups (enemy type, count, timing, formation Column / Line / V / Random / Sides, lane, spacing), an optional Keeper per wave, stage audio for the set (and an optional per-wave switch), the Hour's colour for its enemies' explosions, the Hour's difficulty (enemy health, speed, fire rate, bullet speed, points, pickup drop rate; not its Keeper's), loop scaling | — |
| `SunderWaveDirector` | Level actor that plays a wave set: schedules formations along the top edge, spawns a wave's Keeper at the top centre (first clearing the enemies left on screen: each bursts in the Hour's colour, with no score or drops, as in the web game), flies the story's current Hour (and reports it survived) in story mode, in Swarm skips Keepers, loops and quickens (the web game's 0.985 per second, down to `SwarmPaceFloor`); plays the stage's sound (Start cue and ambience on entering a stage, Wave cues, the theme building a layer each third of the way to the Keeper), waits for each wave to clear, loops tougher | — |
| `SunderHUD` | Canvas HUD: score, lives, hull bar, the ship's name in its colour, the Swarm clock, wave banner, a Keeper's intro card (the screen dims, its portrait in its Hour's glow, its Hour, name and taunt, as in the web game's BOSS_INTRO) and its clear card when beaten (HOUR N SURVIVED, the Hour's name · GATE OPEN, its closing line: the web game's STAGE_CLEAR; after the last Keeper, THE TWELFTH GATE IS OPEN · ASCENSION COMPLETE), boss bar coloured by phase, DAWN DENIED as the night closes in (with the score, and in Swarm how long you lasted) | — |

Projectiles are team-aware: enemy shots only hit the ship, the player's shots never do, and shots ignore each other.

## Install

1. Copy `Sunder2/Public/*` and `Sunder2/Private/*` into your game module, e.g. `Source/<YourGame>/Public` and
   `Source/<YourGame>/Private`. If your module has no Public/Private split, put all forty-five files in `Source/<YourGame>/`.
2. Replace `SUNDER2_API` with your module's export macro (`<YOURGAME>_API`) in the twenty-four headers.
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
3. [`../Scripts/create_enemies_and_waves.py`](../Scripts/create_enemies_and_waves.py): `BP_EnemyShot`, five enemy Blueprints
   (Scout, Diver, Skimmer, Gunship, Bomber), `DA_TestWaves` (five waves, looping tougher) and a wave director in
   `L_SunderArena`, replacing the target dummies.
4. [`../Scripts/create_keepers.py`](../Scripts/create_keepers.py): imports the Keeper models from
   [`../Content/Keepers`](../Content/Keepers) (FBX, one mesh each), makes `BP_KeeperShot` / `BP_KeeperShotHeavy` (2 damage from
   Hour 7), the twelve `BP_Keeper_*` Blueprints with the web game's numbers, `DA_KeeperGauntlet` (all twelve in order),
   and adds Wepwawet to the end of `DA_TestWaves`. Set `USE_GAUNTLET_IN_ARENA = True` to play the gauntlet in the arena.
5. [`../Scripts/create_keeper_fx_assets.py`](../Scripts/create_keeper_fx_assets.py): Keeper materials, Effect Types and
   empty `NS_Keeper_*` systems, wired onto the twelve Keepers with each one's colours, and `NS_Keeper_Shot` on the Keeper
   shots; build the emitters by hand from [`../KEEPER_VFX.md`](../KEEPER_VFX.md).
6. [`../Scripts/create_keeper_audio.py`](../Scripts/create_keeper_audio.py): imports the Keepers' music (39 loops: twelve
   themes and Apep's final form, three layers each) and voices (60 cues) from [`../Content/Audio/Keepers`](../Content/Audio/Keepers),
   sets the loops to play in step, and sets them on every Keeper. The WAVs are the web game's own synth, rendered by
   [`../Tools/render_web_audio.cjs`](../Tools/render_web_audio.cjs) (`node unreal/Tools/render_web_audio.cjs keepers`, needs
   Playwright); re-render after changing `web/keeper_audio.js`.
7. [`../Scripts/create_stage_audio.py`](../Scripts/create_stage_audio.py): imports the twelve Hours' music (36 loops),
   ambience (12 seamless 24 s beds) and cues (48) from [`../Content/Audio/Stages`](../Content/Audio/Stages), makes
   `DA_StageAudio_<Hour>`, gives `DA_TestWaves` the Horizon and each `DA_KeeperGauntlet` wave its Keeper's Hour.
   Rendered by `node unreal/Tools/render_web_audio.cjs stages` from `web/stage_audio.js`.
8. [`../Scripts/create_menu_level.py`](../Scripts/create_menu_level.py): the title screen and hangar. Imports the menu
   music, ambience, cues and ship engines from [`../Content/Audio/Menus`](../Content/Audio/Menus) (`render_web_audio.cjs menus`,
   from `web/menu_audio.js`) and the title art and ship sprites from `art/blender`, makes `BP_SunderMenuGameMode` and
   `L_SunderTitle`, and sends the arena back to the title after DAWN DENIED. Open `L_SunderTitle` and press Play.
9. [`../Scripts/create_story_level.py`](../Scripts/create_story_level.py) (last): story mode. Imports the story music,
   ambience and cues from [`../Content/Audio/Story`](../Content/Audio/Story) (`render_web_audio.cjs story`, from
   `web/story_audio.js`), the words from [`../Content/Story/story.json`](../Content/Story/story.json)
   (`node unreal/Tools/export_story_text.cjs`, from `web/game.html`) and the Hours' backdrops and Keeper portraits, makes
   `DA_StoryData`, `BP_SunderStoryGameMode` and `L_SunderStory`, and points the hangar's Story mode at it.
10. [`../Scripts/create_hour_waves.py`](../Scripts/create_hour_waves.py): a wave set for each Hour,
    `DA_Waves_HourNN_<Stage>`, from the web game's stage tuning in `story.json` (main enemy from the Hour's movement
    style, its scout lines and bomber runs, a second enemy from its briefing, gunships in later acts; difficulty by the
    web ratios to Hour 1; long enough for the web Hour's score to its Keeper, longer each act), ending with the Hour's
    Keeper in its own sound. Gives them to `DA_StoryData`; set `ARENA_HOUR` to fly one in the arena.
11. [`../Scripts/create_ship_models.py`](../Scripts/create_ship_models.py): imports the three ships' models from
    [`../Content/Ships`](../Content/Ships) (`blender/ships.py <dir> 0 --fbx`) and gives each to its ship in
    `BP_SunderGameMode` → Ships, replacing the placeholder cone.
12. [`../Scripts/create_ship_sounds.py`](../Scripts/create_ship_sounds.py): imports the game's own sound effects from
    [`../Content/Audio/Effects`](../Content/Audio/Effects) (`render_web_audio.cjs effects`, from `web/game.html` sfx()) and
    sets the shot, pickup, life, bomb and hit sounds on `BP_SunderShip` and the explosions on `BP_SunderGameMode`.
13. [`../Scripts/create_ship_fx_assets.py`](../Scripts/create_ship_fx_assets.py): the shield's, explosion's, bomb's,
    form change's and respawn's materials and empty `NS_Ship_Shield` / `NS_Ship_ShieldEvent` / `NS_Ship_Explosion` /
    `NS_Ship_Bomb` / `NS_Ship_FormChange` / `NS_Ship_Respawn`, set on `BP_SunderShip`; build the emitters from [`../SHIP_VFX.md`](../SHIP_VFX.md).
14. [`../Scripts/create_pickup_art.py`](../Scripts/create_pickup_art.py): imports the six pickup gems from
    [`../Content/Pickups`](../Content/Pickups) (`blender/pickups.py <dir> 0 --fbx`), makes `BP_SunderPickup` with them, and
    sets it as the game mode's Pickup Class.
15. [`../Scripts/create_enemy_fx_assets.py`](../Scripts/create_enemy_fx_assets.py): the enemy materials, `EFT_EnemyShot` /
    `EFT_EnemyExplosion` and empty `NS_Enemy_Shot` / `NS_Enemy_Explosion`, set as `BP_EnemyShot`'s trail (size 30, violet)
    and the five enemies' Explosion FX; build the emitters from [`../ENEMY_VFX.md`](../ENEMY_VFX.md). Run
    `create_hour_waves.py` after it (again) so each Hour's explosions take its colour.
16. [`../Scripts/create_pickup_fx_assets.py`](../Scripts/create_pickup_fx_assets.py): `MI_Pickup_Mote` / `MI_Pickup_Ring`
    and an empty, pooled `NS_Pickup_Collect`, set as `BP_SunderPickup`'s Collect FX (after `create_pickup_art.py`); build
    the emitters from [`../PICKUP_VFX.md`](../PICKUP_VFX.md).

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
3. Keepers: each faces down the screen (else change its Body Rotation yaw), stays invulnerable until it settles,
   and the boss bar changes colour at 66% and 33%.
4. Pools: `GetTotalCreated` on the projectile pool and the Niagara Debugger's pooled-component count plateau rather
   than climbing.
