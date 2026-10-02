# The Twelve Keepers and stage backdrops — evidence (2026-10-01)

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

## Stage backdrops for Hours 1–9
- `blender/stages.py` gained nine builders, one per arena in DESIGN.md: desert rail yards with crystal-burst wrecks (1),
  black floodwater with reed islands and fallen obelisks (2), a cracked glass desert (3), gold-capped Atlantean spires
  on the sea floor (4), Sokar's dune sea with half-buried bronze hawks (5), crust plates on a dim lava lake (6), Apep's
  coils passing under open night (7), iron girder walkways over storm cloud (8), and the checkered Judgement Hall with
  column tops and gold feather inlays (9). Every Hour now has its own backdrop.
- Review passes removed what competed with gameplay: cyan rings around the spires read as targeting reticles, the lava
  was bright orange, the white feather inlays could pass for pickups, and the glossy water/mirror threw hot specular
  patches. All dimmed or replaced; in-play captures (`stages-play/hour1-9.png`) show bullets and enemies clear on each.
- **Kling + Blender:** nine Kling stage concepts (one per Hour, job IDs in `game-progress.md`). `stages.py` now uses
  `art/kling/stage_<id>.png` as the ground texture when present, under Blender's props and lighting; verified with a
  stand-in texture. The Kling images still need to be sent back, as this sandbox can't download them.
- `test_sunder2.js`: 8/8, now requiring a distinct embedded backdrop for all 12 Hours. `game.html` is 792 KB.

## Art moved out of game.html
- All 43 embedded WebP images (Blender art table + hangar) extracted byte-for-byte to `web/assets/<key>.webp`;
  `game.html` went from 808 KB to 111 KB. Part 1's SVG sprites stay inline (generated at runtime).
- Checked: sampled assets are SHA-256 identical to the original encodes; all 43 are valid WebP; in Chromium every image
  loads with no failed requests or console errors both over HTTP (258 ms) and opened as a local file (184 ms);
  title, hangar and Apep's final phase render as before. `test_sunder2.js` 9/9 — new check that every referenced
  asset exists as WebP and nothing is still embedded.

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
- Stage backdrops are Blender tiles until Kling concepts are sent back and folded in through `art/kling/`.
- Sokar's feather blades are thin, so the hawk reads slighter in the low 3/4 Codex view than top-down in the game.
- Kling concepts could not be inspected or used as image-to-3D input here (CDN blocked); models follow the written brief.

## Animated Keepers (Blender + Kling)
- **Blender:** `keepers.py --anim` renders an 8-frame seamless loop per Keeper (13 loops, 104 frames, Cycles 48 samples),
  and `pack_anim.py` packs each into `web/assets/keeper_<id>_anim.webp` (47–131 KB each, about 1 MB total).
  Builders now label their parts with `mark()`; each Keeper has an animator that poses those parts for the loop angle:
  Wepwawet strides in diagonal pairs, Sobek's tail waves and its turrets track, UMBRA's drones orbit, Nun's spires turn
  and its tentacles sway, Sokar beats its wings, the Seraphs sway with flickering flame wings and embers, UMBRA Coiled's
  coil tightens as the head strikes, the Hittite chariot wheels spin and the guns recoil, Ammit's scales of judgement
  rock while the heart throbs, the Overlord's armour fragments orbit among twinkling stars, UMBRA's loose mask plates drift
  while its seams pulse, and a wave runs down Apep's coils (in the final phase its open jaws flex on the Heart).
- Static art unchanged: Act IV re-rendered with the old and new script has identical sizes and alpha, with colour
  differences only at denoiser-noise level (max 8/255, mean < 0.02); the shipped static sprites were not re-rendered.
- One defect found and fixed: the Hittite rotors' struts were grouped with the previous rotor, so they spun off the hull
  (sheet hit the 544 px canvas edge); each strut now has its own mark, and the sheet is back to 346 px wide.
- Game: `drawKeeper` plays the sheet at 8 fps once loaded (the still sprite until then and as fallback), at the still
  sprite's scale and centre, including the hit flash. Chromium capture of all 13 (`keepers-animated/`, `report.json`):
  the on-screen frame changes on every Keeper, no page errors, no failed requests.
- `test_sunder2.js`: 10/10 — new check that every Keeper has an animation sheet, as alpha WebP, a whole number of frames wide.
- **Kling:** 12 reveal clips, one per Keeper (5 s, 720p, `kling-video-v3_0_turbo`, 480 credits): image-to-video from the
  concept art for Wepwawet, Sobek, UMBRA, the Overlord's Echo, UMBRA Unmasked and Apep; text-to-video for the other six.
  All 12 completed; job IDs in `game-progress.md`. Links expire in 24 h and can't be downloaded here.

## Animated Keeper Codex (`keepers-evidence.json`, run `keepers-animated-pass-2`)
- `keepers.py` now exports each GLB with its loop baked in, from the same animators as the game sprites: every animated
  part becomes one joined mesh node with translation/rotation/scale tracks (32 samples, a 1 s loop, quaternions kept on
  one hemisphere so they never flip). Apep's coil wave isn't rigid, so its body carries 8 morph targets cross-faded
  round the loop. `python blender/keepers.py <out> 8 [act|id] --glb` exports only the models.
- `keepers.html` plays the clip with an `AnimationMixer` driven by the viewer's sim time, so `seed()` and pause still hold a
  pose; a new `pose(t)` hook freezes any moment of the loop for screenshots, and diagnostics report the clip.
- Budget: animated parts are separate nodes, so the Overlord's Echo (26 stars) first measured 165 calls on mobile, over the
  150 budget. Glowing light sources (stars, cores, embers) no longer cast shadows, which brought it to 129.
- Inspector: all 26 captures (13 × desktop/mobile) PASS; `check_evidence.py`: 26 artifacts confirmed.

| Keeper | calls before (static) | calls now, desktop | mobile | triangles |
|---|---|---|---|---|
| Wepwawet | 45 | 96 | 96 | 43,804 |
| Sobek Reborn | 51 | 138 | 138 | 52,114 |
| UMBRA | 48 | 63 | 63 | 36,004 |
| Nun | 45 | 76 | 76 | 48,090 |
| Sokar | 48 | 70 | 70 | 36,258 |
| Fire Lake Seraphs | 31 | 68 | 68 | 40,128 |
| UMBRA, Coiled | 57 | 76 | 76 | 43,964 |
| Hittite Engine | 45 | 104 | 104 | 50,606 |
| Ammit | 37 | 56 | 56 | 22,544 |
| Overlord's Echo | 48 | 129 | 129 | 31,590 |
| UMBRA, Unmasked | 37 | 69 | 69 | 22,876 |
| Apep | 39 | 46 | 46 | 22,370 |
| Apep, final phase | 45 | 59 | 59 | 26,690 |

- Motion check (`keepers-codex-animated/`, `report.json`): each Keeper posed at loop time 0 and 0.375 s from the same paused
  camera; the frame changes on all 13 (0.4 % of pixels for the Hittite wheels, whose six spokes nearly repeat, up to
  9.8 % for Apep's coils), one 1 s clip each, no console or page errors.

## Keeper sound (`web/keeper_audio.js`)
- One shared module, synthesised live with Web Audio like the rest of the game's sound (no files): 13 themes (12 Keepers +
  Apep's final phase) and five voice cues for each of the 12 Keepers, 60 in all. Themes are written in scale degrees in
  each Keeper's mode (Phrygian dominant for the desert of Act I, Dorian for Nun's deep, locrian for Apep, ...); UMBRA plays
  the hero's Part 1 theme inverted, UMBRA Unmasked plays it as written, and the Overlord's Echo quotes Part 1's boss
  theme with an echo. Each theme builds with the boss phase: bass, lead and kick; + snare and hats; + the lead doubled
  an octave up and double-time hats. Voices duck the music while they speak; attack and hurt cues are rate-limited.
- Game: the boss intro starts the Keeper's theme and its intro voice; firing plays its attack cue, damage its hurt cue,
  each phase change its stinger (and Apep switches to its final-phase theme); the death cry plays as it falls. If the
  player dies mid-fight the Keeper gloats and its theme stops. Swarm mode (no Keepers) keeps its old music.
- Codex: a SOUND toggle (button or S, off by default because browsers block autoplay) plays each Keeper's theme and intro.
- `test_sunder2.js` 11/11 — new check runs every theme at every layer and every voice against a strict stand-in
  AudioContext (no NaN, no exponential ramp to 0, which browsers reject), checks melodies are all distinct, the attack
  cue rate limit, and that the game calls every cue.
- Chromium: each Keeper rendered offline as a 15 s battle in miniature (intro, theme through phases 1-3, attacks, hurts,
  phase stingers, death). No clipping on any; peaks −5 to −10 dBFS, levels −24 to −34 dB RMS (Apep loudest, by design).
  Recorded as Opus previews in `artifacts/keeper-audio/` (`report.json` has per-second levels). Live game: the right theme
  plays from each boss intro (Hours 1, 7, 12 checked), Apep switches to `apep_p3` in its final phase, the theme stops on
  defeat and hands over to the stage-clear / victory music; Codex toggle on/off works; no page or console errors.

## Stage sound (`web/stage_audio.js`)
- Plugs into the engine in `keeper_audio.js`, which gained `register()`, ambience (looping beds with slow swells and
  filter sweeps, plus scattered events from a seeded generator) and one shared scheduler. Synthesised live; no files.
- Each of the 12 Hours: a theme in its act's colour (Act I desert modes, Act II slow and deep, Act III darker,
  Act IV urgent; the Heart of Atlantis plays the hero's theme), an ambience, and four cues: start (a call in the
  Hour's key + its texture), wave (formation alert), down (layered on every enemy explosion: sand, splash, glass,
  bubbles, embers, hiss, metal, stone, crystal, heartbeat), clear (an arpeggio fanfare in the Hour's key).
- Game flow: engaging an Hour starts its theme and ambience; the theme builds in thirds of the way to the Keeper;
  the Keeper's theme takes over at its intro while the ambience carries on; at the clear the music and ambience stop
  for the fanfare, and the menu music returns on the hour map. Defeat goes silent; swarm mode keeps its old music.
- Layers reworked for both Hours and Keepers so the build is audible: layer 1 holds the lead back, layer 2 brings it in
  with snare and hats, layer 3 doubles lead and bass an octave up with double-time hats. Measured on the theme alone:
  +1 to 1.6 dB overall per layer but +7 to 14 dB above 2 kHz from layer 1 to 3 (density and brightness, not volume).
  Keeper previews in `keeper-audio/` were re-recorded with this.
- Chromium, each Hour rendered offline as 20 s of play: no clipping; ambience measured alone sits 10+ dB under the
  music (−37 to −46 dB RMS) after a first pass found the low hums of the Judgement Hall, Sunken Spires, Heart and
  Apep within a few dB of it and thunder pushing peaks to −0.6 dBFS (beds and thunder turned down). Previews and
  levels: `stage-audio/`. Live game: theme, ambience and music state checked at every step from engaging Hour 4 to the
  hour map, plus defeat in Hour 8 and swarm mode; no page or console errors.
- `test_sunder2.js` 12/12 — new check runs every Hour's theme (all layers), 30 s of ambience and all four cues against
  the strict stand-in AudioContext, ambience replace/stop, distinct melodies across all 25 themes, the game's calls,
  and that stage layers climb 1 → 2 → 3 in thirds.

## Title screen and hangar sound (`web/menu_audio.js`)
- Third pack on the same engine. Title: the hero's theme at 84 bpm with pads and echo, over wind at the crystal gate,
  a two-tone portal hum and ember crackles with the odd crystal chime; `start` surges the gate open (filtered noise
  swell into an A-major chord and chime), `leaderboard` chimes. Hangar: a minor groove at 112 bpm over machine hum,
  vents and mains hum, with clanks, PA chimes, hydraulics and a distant drill; `move` (servo + lock), `mode`, `back`,
  `launch` (rising roar into a thump), and an engine `rev` for each ship. Engine: `start` and `launch` now duck the music.
- Game: the title's theme and ambience start on load and are heard from the first key or tap (the page now wakes audio
  on the first pointerdown or keydown); start → hangar theme + the selected ship revving; ship change → bay servo then
  that ship's engine; mode switch (keys and touch buttons) → its blip; launch → launch roar + ship rev, then the story
  music; ESC back to the hangar or title restores their themes. Without the engine the old blip still plays.
- Chromium, real keyboard and mouse input: loaded (context suspended, title theme queued) → first click (running) →
  SPACE hangar → next ship → mode ×2 → SPACE launch (OPENING, story music) → ESC hangar → ESC title; theme, ambience and
  music state right at every step, no page or console errors. Offline 20 s renders: no clipping; ambience 13–15 dB under
  the music. Previews and levels: `menu-audio/`.
- `test_sunder2.js` 13/13 — new check runs both themes, ambiences, every cue and all three ship engines against the strict
  stand-in AudioContext, keeps all 27 melodies distinct, and checks the game wiring and the audio wake-up.
