# SUNDER: Ascension II — The Twelve Gates (work in progress)

Everything for the sequel lives in this folder, kept separate from the
original *SUNDER: Ascension — The Nine Bows* (`web/`, `godot/`, `docs/`), which is unchanged.

| Path | What it is |
|---|---|
| `DESIGN.md` | Storyline, gameplay ideas, PS5-style UI direction, prompt pack |
| `web/game.html` | The sequel build (single file, open it in a browser) |
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
- **Keepers of Acts I and II** are Blender models: Wepwawet, Sobek Reborn, UMBRA (Hours 1–3, and UMBRA's
  rematches in Hours 7 and 11) and Nun, Sokar, the Fire Lake Seraphs (Hours 4–6). Top-down sprites in play,
  portraits on the boss-intro card, GLBs in the Keeper Codex.

The other Hours still use Part 1's SVG bosses (assigned per Hour through each stage's `art` field).

## Re-rendering the Blender art

Blender runs headless as a Python module (`pip install bpy==4.2.0`, Python 3.11):

```bash
python blender/ships.py art/blender 256                       # ship_sunborn/scarab/ibis.png
python blender/title_scene.py art/blender/title_bg.png 720 1080 128
python blender/keepers.py art/blender/keepers 128 [1|2]       # one act or all: sprites, portraits, GLBs (move .glb to web/models/)
```

To view the Keeper Codex locally: `cd web && python3 -m http.server 5188`, then open http://127.0.0.1:5188/keepers.html.

The game embeds compressed WebP copies of these renders, so `game.html` stays a single file.

Kling subject for the Mk II: **Scarab Warbringer Mk II**, id `322794480306968`.
