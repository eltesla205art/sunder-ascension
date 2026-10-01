# The Twelve Keepers and Act IV stages — evidence (2026-10-01)

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

## Act II (Hours 4–6)
- `blender/keepers.py <out> 128 2` builds **Nun, the Primeval Deep** (abyssal ring guardian crowned with sunken
  Atlantean spires, tentacle arms), **Sokar, Hawk of the Hidden Sand** (bronze war-hawk, crystal-edged wings,
  tail fan) and **the Fire Lake Seraphs** (four hooded fire-cobras around a burning brazier).
- Blender passes: draft 1 had a washed-out water dome, floating ring blocks, a toy-like hawk and blown-white fire;
  fixed with a deep coated water material, a solid lock-ring with spokes, a wider darker wingspan and heavier beak,
  flat hoods facing the camera, and saturated low-strength fire (AgX desaturates bright emission).
- Game: Hours 4–6 use the new sprites and intro portraits (`act2-bosses/`), Sokar drawn at 0.6 to cover its hitbox.
- Codex: 6 Keepers across two acts, act divider, act name in the header, horizontally scrolling cards on phones;
  the controls hint moved under the header after it overlapped the sixth card.

## Act III (Hours 7–9)
- `blender/keepers.py <out> 128 3` builds **UMBRA, Coiled** (Hour 7: UMBRA wound in Apep's faceted crystal coil,
  which weaves over and under the wings, with a striking serpent head), **the Hittite Engine** (Hour 8: battlemented
  iron deck with corner towers, crystal reactor citadel, a seven-gun wall-barrage bow, four six-spoked chariot-wheel
  rotors) and **Ammit, Devourer of Hearts** (Hour 9: crocodile jaws, spiked lion mane, hippo hindquarters, and the
  scales of judgement weighing a glowing heart against Ma'at's feather).
- Blender passes: draft 1's coil lay flat like a halo, the fortress read as a drone, and Ammit read as a turtle with a
  plank snout; fixed with a weaving helix, battlements and towers, tapered jaws, a larger mane and a smaller body.
  Portraits now aim at mid-height so tall Keepers (Ammit's scales) stay in frame.
- Game: Hours 7–9 use the new sprites and intro portraits (`act3-bosses/`). Hour 11's final UMBRA keeps the Hour 3 model.
- Codex: 9 Keepers across three acts; cards narrowed to 88 px so all nine fit on desktop.

## Act IV (Hours 10–12) and stage backdrops
- `blender/keepers.py <out> 128 4` builds **the Overlord's Echo** (Hour 10: the broken crystal crown of Part 1's
  Overlord, a void bowl of falling stars, orbiting gold armour), **UMBRA, Unmasked** (Hour 11: the gold Thunder breaking
  out of its obsidian mask — the shadow reveal) and **APEP** in two forms (Hour 12): jaws shut with coils trailing, and a
  final-phase render with the jaws splayed sideways around the Heart of Atlantis.
- Blender passes: Apep's first body read as a worm with a tiny head and its open jaws were invisible from above; the head
  was enlarged, the coils shortened, and the final-phase jaws now open sideways. UMBRA's loose seams were attached to
  the clinging mask plates.
- Game: Hours 10–12 use the new sprites and portraits; a Keeper with a `_p3` render switches to it for the last third of
  its hull, so Apep opens its jaws on the Heart (`act4-bosses/boss12_final_phase.png`).
- **Stage backdrops** (new): `blender/stages.py` renders top-down tiles — the Starfall plain (Hour 10), the Heart
  chamber floor (Hour 11) and Apep's scaled back (Hour 12). The game scrolls each tile with every other copy mirrored so
  no seam shows. Two defects found in capture and fixed: the scroll loop left the lower screen uncovered for half of each
  cycle (now covered for every offset — checked numerically), and Apep's crystal ridge read like enemy bullets at 60 %
  opacity (backdrops now drawn at 42 %).
- Kling: concept art for the three Act IV Keepers and a 9:16 stage concept for each Act IV Hour (job IDs in
  `game-progress.md`). They can't be downloaded in this sandbox; any the user sends back can replace the Blender tiles.
- Codex: all 13 entries (12 Keepers + Apep's final phase) in a scrolling card row; crystal emission capped harder for
  transmissive materials after the Overlord's crown measured contrast 200 (now 172).
- `test_sunder2.js`: 8/8 — new check that every Hour has a Blender Keeper and the Act IV Hours have backdrops.

## Keeper Codex inspection (`keepers-evidence.json`, run `keepers-act4-pass-2`)
All 26 captures (13 entries × desktop/mobile) PASS; `check_evidence.py`: 26 artifacts confirmed.
SwiftShader (software) rasterizer, so FPS is not measured. Identical diagnostics on both viewports:

| Keeper | calls | triangles | geometries | textures |
|---|---|---|---|---|
| Wepwawet | 45 | 45,252 | 14 | 17 |
| Sobek Reborn | 51 | 54,726 | 22 | 17 |
| UMBRA | 48 | 38,016 | 21 | 17 |
| Nun | 45 | 52,170 | 20 | 17 |
| Sokar | 48 | 36,930 | 21 | 17 |
| Fire Lake Seraphs | 31 | 42,552 | 19 | 17 |
| UMBRA, Coiled | 57 | 46,440 | 24 | 17 |
| Hittite Engine | 45 | 51,642 | 20 | 17 |
| Ammit | 37 | 23,440 | 22 | 17 |
| Overlord's Echo | 48 | 34,914 | 21 | 17 |
| UMBRA, Unmasked | 37 | 24,716 | 22 | 17 |
| Apep | 39 | 23,178 | 18 | 17 |
| Apep, final phase | 45 | 29,610 | 20 | 17 |

Pixel metrics, desktop → mobile: entropy 3.1–4.0 → 3.2–4.5, edge density 0.14–0.19 → 0.20–0.26,
contrast 52–172 → 91–184 (the Overlord's crystal crown is the high end). All within the desktop (300 calls) and mobile (150 calls) budgets.

Render setup: ACES filmic, sRGB, DPR cap 2 desktop / 1.5 mobile, 1 shadow-casting light (2048 / 1024 map),
1 post pass (bloom, threshold 0.9) + output. Budget fixes made during QA:
- Draw calls were 312 for Sobek (over 300 desktop / 150 mobile) because every Blender part exported as its own mesh;
  `keepers.py` now joins parts before export → 45–51 calls.
- Diagnostics originally read 1 call / 1 triangle (three.js resets `renderer.info` per composer pass); counters now span the frame.
- Pass 2 failed only on a Google Fonts request the sandbox proxy blocks and a missing favicon; the page now uses a local font stack.

Desktop contrast sits lower than mobile because the wide view shows more of the dark obsidian plinth — a
deliberate night-showroom look, not fog standing in for geometry. The scorecard targets active-play captures, which for
SUNDER II are the 2D game captures in `act1-bosses/` … `act4-bosses/`.

## Still weak
- Hours 1–9 have no stage backdrop yet (starfield only); Act IV's backdrops are Blender tiles until Kling ones are sent back.
- `game.html` is 732 KB with every render embedded; still one file, but worth moving art to separate files before release.
- Sokar's feather blades are thin, so the hawk reads slighter in the low 3/4 Codex view than top-down in the game.
- Keeper models are static (no rig/animation); motion in the viewer is hover, turntable and emissive pulse only.
- Kling concepts could not be inspected or used as image-to-3D input here (CDN blocked); models follow the written brief.
