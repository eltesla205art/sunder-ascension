# SUNDER: Ascension II — The Twelve Gates (work in progress)

Everything for the sequel lives in this folder, kept separate from the
original *SUNDER: Ascension — The Nine Bows* (`web/`, `godot/`, `docs/`), which is unchanged.

| Path | What it is |
|---|---|
| `DESIGN.md` | Storyline, gameplay ideas, PS5-style UI direction, prompt pack |
| `web/game.html` | The sequel build: open it in a browser (it loads its art from `web/assets/`) |
| `web/assets/` | The game's 56 images as WebP: title, hangar, ships, Keeper sprites, animation sheets and portraits, stage backdrops |
| `web/keeper_audio.js` | Every Keeper's battle theme and voice, synthesised live with Web Audio (shared by the game and the Codex), and the audio engine |
| `web/stage_audio.js` | Every Hour's stage theme, ambience and stage cues (plugs into `keeper_audio.js`) |
| `web/menu_audio.js` | Title screen and hangar music, ambience, interface cues and each ship's engine sound (plugs into `keeper_audio.js`) |
| `web/story_audio.js` | Music, ambience and cues for the opening crawl, hour map, briefings, act interludes, true ending and defeat (plugs into `keeper_audio.js`) |
| `web/keepers.html` | Keeper Codex: real-time Three.js viewer of the Keeper models (serve the `web/` folder over HTTP; three.js is self-hosted in `web/vendor/three`, MIT) |
| `web/models/` | Keeper GLB models exported from Blender, each with its animation loop baked in, plus portrait thumbnails |
| `web/test_sunder2.js` | Headless test of the 12-Hour campaign against the battle-math law: `node web/test_sunder2.js` |
| `blender/` | Blender Python scripts that model and render the game art |
| `unreal/WEAPON_VFX.md` | UE5 Niagara guide for the planned Unreal version: the trace-driven laser beam, the plasma-burst impact, pooling and budgets (not yet built in-engine) |
| `unreal/Scripts/create_weapon_fx_assets.py` | Editor Python: makes the weapon FX master material and instances, Effect Types and empty Niagara systems, then lists what's left to build by hand (untested until first run) |
| `unreal/Source/` | Drop-in UE5 C++: beam weapon, impact FX, pooled projectiles, the player ship, enemies, wave set and director, the Keeper boss, power-ups and bombs, layered music and stage sound, the title screen and hangar, story mode and the hour map, game mode with score and lives, HUD, target dummy (not compiled yet; install steps inside) |
| `unreal/Scripts/create_enemies_and_waves.py` | Editor Python: five enemy Blueprints and their shot, a five-wave `DA_TestWaves`, and a wave director in `L_SunderArena` (untested until first run) |
| `unreal/Scripts/create_arena_level.py` | Editor Python: makes `BP_SunderShip`, `BP_PlasmaShot`, `BP_SunderGameMode` and the top-down test level `L_SunderArena` (needs the C++ compiled; untested until first run) |
| `unreal/Scripts/create_keepers.py` | Editor Python: imports the Keeper models and makes the twelve `BP_Keeper_*` boss Blueprints, their shots and `DA_KeeperGauntlet` (untested until first run) |
| `unreal/KEEPER_VFX.md` | UE5 Niagara guide for the Keepers: aura, arrival Gate, muzzle flares, phase shockwave, death and shot trails |
| `unreal/Scripts/create_keeper_fx_assets.py` | Editor Python: Keeper FX materials, Effect Types and empty systems, wired onto the twelve Keeper Blueprints with their colours (untested until first run) |
| `unreal/Scripts/create_keeper_audio.py` | Editor Python: imports the Keepers' music and voices and sets them on the twelve Keeper Blueprints (untested until first run) |
| `unreal/Content/Audio/Keepers/` | The Keepers' battle themes (three layers each, seamless loops) and voices as WAV, rendered from `web/keeper_audio.js` |
| `unreal/Scripts/create_stage_audio.py` | Editor Python: imports the twelve Hours' music, ambience and cues, makes their stage audio assets and gives them to the wave sets (untested until first run) |
| `unreal/Content/Audio/Stages/` | The Hours' themes (three layers each), ambience beds and cues as WAV, rendered from `web/stage_audio.js` |
| `unreal/Scripts/create_menu_level.py` | Editor Python: the title screen and hangar level (`L_SunderTitle`) with the menu music, ambience, interface cues and ship engines (untested until first run) |
| `unreal/Content/Audio/Menus/` | The title and hangar themes (three layers each), ambience beds, interface cues and ship engine revs as WAV, rendered from `web/menu_audio.js` |
| `unreal/Scripts/create_story_level.py` | Editor Python: story mode (`L_SunderStory`): the opening crawl, hour map, briefings, Hour survived, dawn and DAWN DENIED, with their music, ambience and cues, and the twelve Hours wired to their stage sound and Keepers (untested until first run) |
| `unreal/Scripts/create_ship_models.py` | Editor Python: imports the Sunborn, Scarab and Ibis models and sets them on the arena's ships (untested until first run) |
| `unreal/Scripts/create_ship_sounds.py` | Editor Python: imports the game's sound effects and sets the ship's pickup, life, bomb and hit sounds (untested until first run) |
| `unreal/Content/Audio/Effects/` | The game's own sound effects (pickups, bomb, hits, shots, explosions) as WAV, rendered from `web/game.html` |
| `unreal/Content/Ships/` | The three ships as FBX for Unreal (one mesh each), from `blender/ships.py --fbx` |
| `unreal/Scripts/create_hour_waves.py` | Editor Python: a wave set for each of the Twelve Hours from the web game's stage tuning, each ending with its Keeper, for story mode (untested until first run) |
| `unreal/Content/Audio/Story/` | The story screens' themes (three layers each), the crawl's and the map's ambience, and the story cues as WAV, rendered from `web/story_audio.js` |
| `unreal/Content/Story/story.json` | The story's words and each Hour's battle tuning for Unreal, exported from `web/game.html` by `unreal/Tools/export_story_text.cjs` |
| `unreal/Tools/render_web_audio.cjs` | Renders the Keeper, stage, menu, story and game-effect WAVs from the web game's synth in Chromium (Playwright) |
| `unreal/Content/Keepers/` | The thirteen Keeper models as FBX for Unreal (one mesh each, plus Apep's final form), from `blender/keepers.py --fbx` |
| `art/blender/` | Full-resolution Blender renders (title backdrop, ship sprites, `keepers/` boss sprites and portraits) |
| `artifacts/` | Progress note, QA evidence (`final-evidence.md`), inspector captures |
| `art/` | AI concept art: key art A/B, Scarab Warbringer Mk II A/B, Mk II hangar shots A/B |

## What the build has so far

- **Title screen:** Blender-rendered backdrop (the crystal gate under the eclipsed sun, Apep coiled around it),
  with a breathing portal, flickering eclipse rim, rising embers, and your ship emerging from the gate.
- **Blender ship sprites** for the Sunborn Thunder, Scarab Warbringer and Ibis Phantom, in the hangar and in play.
- **The Twelve Hours:** 12 stages in 4 acts with the Keepers from `DESIGN.md`, the new opening crawl,
  briefings, taunts, act interludes, the true ending and "DAWN DENIED".
- **Hour map** with 12 gates, and the Mk II hangar backdrop on ship select.
- **Battle math** unchanged, scaled to 12 Hours: boss bullets deal 2 from Hour 7.
- **Scores stay on the device.** The sequel has no online leaderboard yet, so it can never write into
  Part 1's live leaderboard. It needs its own Supabase table before going online.
- **All twelve Keepers** are Blender models: Wepwawet, Sobek Reborn, UMBRA (Act I); Nun, Sokar, the Fire Lake
  Seraphs (Act II); UMBRA Coiled, the Hittite Engine, Ammit (Act III); the Overlord's Echo, UMBRA Unmasked and Apep
  (Act IV), with Apep changing form for its final phase. Top-down sprites in play, portraits on the boss-intro card,
  GLBs in the Keeper Codex.
- **Animated Keepers:** every Keeper plays an 8-frame Blender animation loop in battle (Wepwawet strides,
  Sobek's tail waves, UMBRA's drones orbit, Nun's spires turn, Sokar beats its wings, the Seraphs sway in their flames,
  the Hittite rotors spin, Ammit's scales rock, the Overlord's armour orbits, UMBRA's mask peels, Apep's coils ripple).
  The Keeper Codex plays the same loops on the 3D models.
- **Keeper sound:** each Keeper has its own battle theme that builds with its phase (bass and lead, then drums,
  then the lead doubled), and its own voice: an intro roar, an attack cue, a phase stinger, a hurt sound and a death cry.
  UMBRA plays the hero's theme upside down, UMBRA Unmasked plays it straight, the Overlord's Echo echoes Part 1's boss
  theme, and Apep gets a new theme for its final phase. All synthesised in `web/keeper_audio.js`, so there are no audio
  files; M still mutes the music. The Codex has a SOUND toggle (S) that plays each Keeper's theme and intro.
  Listening previews (15 s each): `artifacts/keeper-audio/*.webm`.
- **Stage sound:** every Hour has its own theme, which builds in thirds as you near its Keeper, and its own ambience
  under the whole stage, boss fight included: desert wind and rail clanks, floodwater and drips, singing glass, the deep
  sea, dune gusts, a crackling lava lake, Apep's hiss in the void, storm and thunder over the Iron Sky, a bell in the
  Judgement Hall, falling stars, the Heart of Atlantis beating, and Apep breathing beneath you. Each Hour also has a
  start sting, a formation alert, its own texture on every enemy explosion, and a clear fanfare in its key.
  The Heart of Atlantis plays the hero's theme. Previews (20 s each): `artifacts/stage-audio/*.webm`.
- **Title and hangar sound:** the title plays the hero's theme slow and wide over wind at the crystal gate, the
  portal's hum and drifting embers; pressing start surges the gate open. The hangar has its own working groove over
  machinery, vents, clanks and the base PA; changing ship turns the bay and revs that ship's engine (Sunborn bright,
  Scarab heavy, Ibis a high whine), the mode switch has its own blip, and launching revs the ship into a launch roar.
  Audio wakes on the first key or tap. Previews: `artifacts/menu-audio/*.webm`.
- **Story and hour map sound:** the opening crawl is a slow desert lament over wind in the void, opened by a gong;
  the hour map has a journey theme that builds act by act, over starfield shimmer and the hum of the gates, with a
  whoosh onto the map and a chime as each gate opens; briefings play a watchful drone over the coming Hour's own
  ambience with a transmission stinger; between acts a bell tolls and the hero's theme returns, slow; the true ending
  breaks into the hero's theme in a major key over a sunrise chord; DAWN DENIED falls away into a lament.
  Previews: `artifacts/story-audio/*.webm`.
  Kling reveal clips (5 s each, job IDs in `artifacts/game-progress.md`) bring each Keeper to life for trailers.
- **Stage backdrops for all twelve Hours:** scrolling Blender tiles (`blender/stages.py`) behind play, one per arena.
  Kling stage concepts can be folded in as ground textures (save as `art/kling/stage_<id>.png`, re-run the script).

## Re-rendering the Blender art

Blender runs headless as a Python module (`pip install bpy==4.2.0`, Python 3.11):

```bash
python blender/ships.py art/blender 256                       # ship_sunborn/scarab/ibis.png
python blender/title_scene.py art/blender/title_bg.png 720 1080 128
python blender/keepers.py art/blender/keepers 128 [1|2|3|4]   # one act or all: sprites, portraits, GLBs (move .glb to web/models/)
python blender/stages.py art/blender/stages 64 [id ...]       # stage backdrops (all, or e.g. horizon delta)
python blender/keepers.py /tmp/anim 48 [act|id] --anim         # Keeper animation frames (8 per Keeper)
python blender/keepers.py web/models 8 [act|id] --glb          # only the animated Codex models
python blender/keepers.py unreal/Content/Keepers 8 [act|id] --fbx   # static FBX models for Unreal
python blender/ships.py unreal/Content/Ships 0 --fbx              # the three ships as FBX for Unreal
python3 blender/pack_anim.py /tmp/anim art/blender/keepers/anim web/assets   # pack into sprite sheets (needs Pillow)
```

To view the Keeper Codex locally: `cd web && python3 -m http.server 5188`, then open http://127.0.0.1:5188/keepers.html.

The game loads compressed WebP copies of these renders from `web/assets/` (same name as the art key, e.g.
`keeper_nun.webp`, `stage_delta.webp`). After re-rendering, re-encode to WebP and replace the file there.

**Shipping:** upload the whole `web/` folder — `game.html`, the four `*_audio.js` files and `assets/` must stay side by side.
The page shows SVG fallbacks for any image that hasn't arrived yet, so a slow connection never blocks play.

Kling subject for the Mk II: **Scarab Warbringer Mk II**, id `322794480306968`.
