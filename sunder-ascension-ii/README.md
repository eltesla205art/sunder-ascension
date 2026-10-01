# SUNDER: Ascension II — The Twelve Gates (work in progress)

Everything for the sequel lives in this folder, kept separate from the
original *SUNDER: Ascension — The Nine Bows* (`web/`, `godot/`, `docs/`), which is unchanged.

| Path | What it is |
|---|---|
| `DESIGN.md` | Storyline, gameplay ideas, PS5-style UI direction, prompt pack |
| `web/game.html` | The sequel build: open it in a browser (it loads its art from `web/assets/`) |
| `web/assets/` | The game's 56 images as WebP: title, hangar, ships, Keeper sprites, animation sheets and portraits, stage backdrops |
| `web/keepers.html` | Keeper Codex: real-time Three.js viewer of the Keeper models (serve the `web/` folder over HTTP; three.js is self-hosted in `web/vendor/three`, MIT) |
| `web/models/` | Keeper GLB models exported from Blender, plus portrait thumbnails |
| `web/test_sunder2.js` | Headless test of the 12-Hour campaign against the battle-math law: `node web/test_sunder2.js` |
| `blender/` | Blender Python scripts that model and render the game art |
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
python3 blender/pack_anim.py /tmp/anim art/blender/keepers/anim web/assets   # pack into sprite sheets (needs Pillow)
```

To view the Keeper Codex locally: `cd web && python3 -m http.server 5188`, then open http://127.0.0.1:5188/keepers.html.

The game loads compressed WebP copies of these renders from `web/assets/` (same name as the art key, e.g.
`keeper_nun.webp`, `stage_delta.webp`). After re-rendering, re-encode to WebP and replace the file there.

**Shipping:** upload the whole `web/` folder — `game.html` and `assets/` must stay side by side.
The page shows SVG fallbacks for any image that hasn't arrived yet, so a slow connection never blocks play.

Kling subject for the Mk II: **Scarab Warbringer Mk II**, id `322794480306968`.
