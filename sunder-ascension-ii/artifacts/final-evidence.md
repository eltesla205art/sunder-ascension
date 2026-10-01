# Act I Keepers — evidence (2026-10-01)

Skills followed: `skills/threejs-game-director`, `threejs-aaa-graphics-builder` (visual-scorecard, authoring-recipes,
technical-art), `threejs-qa-release` (canvas inspector + `check_evidence.py`). Credential probe: Tripo, Gemini and
ElevenLabs keys MISSING, so concepts came from Kling and models were authored in Blender.

## What was built
| Surface | Source | Files |
|---|---|---|
| Wepwawet, Sobek Reborn, UMBRA models | Blender (procedural, `blender/keepers.py`) | `web/models/keeper_*.glb` |
| Top-down boss sprites + intro portraits | Blender Cycles renders | `art/blender/keepers/`, embedded in `web/game.html` |
| Real-time 3D Keeper Codex | Three.js r169 (self-hosted in `web/vendor/three`) | `web/keepers.html` |
| Concept art (reference only) | Kling, 6 images, 12 credits | job IDs in `game-progress.md` (links expire in 24 h; not downloadable from this sandbox) |

## Game integration (`web/game.html`)
- Hours 1, 2, 3 (and UMBRA's rematches in Hours 7 and 11) draw the Blender Keeper sprites; other Hours keep Part 1 SVG bosses.
- Boss-intro card shows the Keeper portrait above the name and taunt.
- HUD: Hour name hides while the boss name bar is up (fixed an overlap found in capture).
- `node web/test_sunder2.js`: 7/7 pass (12-Hour campaign vs battle-math law, all ships, swarm soak, defeat, leaderboard isolation).
- Captures: `act1-bosses/boss{1,2,3}_{intro,fight}.png`, no page or console errors.

## Keeper Codex inspection (`keepers-evidence.json`, run `keepers-pass-6`)
All 6 captures PASS; `check_evidence.py`: 6 artifacts confirmed. Rasterized on SwiftShader (software), so FPS is not measured.

| Capture | calls | triangles | geometries | textures | entropy | edges | contrast |
|---|---|---|---|---|---|---|---|
| desktop wepwawet | 45 | 45,252 | 14 | 17 | 3.40 | 0.122 | 50.9 |
| desktop sobek | 51 | 54,726 | 22 | 17 | 3.06 | 0.122 | 48.5 |
| desktop umbra | 48 | 38,016 | 21 | 17 | 3.27 | 0.110 | 35.7 |
| mobile wepwawet | 45 | 45,252 | 14 | 17 | 3.84 | 0.204 | 91.6 |
| mobile sobek | 51 | 54,726 | 22 | 17 | 3.36 | 0.206 | 96.0 |
| mobile umbra | 48 | 38,016 | 21 | 17 | 3.68 | 0.190 | 97.7 |

Render setup: ACES filmic, sRGB, DPR cap 2 desktop / 1.5 mobile, 1 shadow-casting light (2048 / 1024 map),
1 post pass (bloom, threshold 0.9) + output. Budget fixes made during QA:
- Draw calls were 312 for Sobek (over 300 desktop / 150 mobile) because every Blender part exported as its own mesh;
  `keepers.py` now joins parts before export → 45–51 calls.
- Diagnostics originally read 1 call / 1 triangle (three.js resets `renderer.info` per composer pass); counters now span the frame.
- Pass 2 failed only on a Google Fonts request the sandbox proxy blocks and a missing favicon; the page now uses a local font stack.

Low desktop contrast (36–51) is a deliberate night-showroom look with a large obsidian plinth, not fog standing in for
geometry; the scorecard targets active-play captures, which for SUNDER II are the 2D game captures above.

## Still weak
- Bosses for Hours 4–6, 8–10 and 12 still use Part 1 SVG art.
- Keeper models are static (no rig/animation); motion in the viewer is hover, turntable and emissive pulse only.
- Kling concepts could not be inspected or used as image-to-3D input here (CDN blocked); models follow the written brief.
