# SUNDER II — game progress

## Done: Act I Keepers (Hours 1–3) — see final-evidence.md
Pipeline (threejs-game-director / threejs-aaa-graphics-builder): concept → authored model → materials → lighting → VFX → browser evidence.
- Concepts: Kling (no Tripo/Gemini/ElevenLabs keys in this environment; probe run 2026-10-01).
- Models: Blender (bpy 4.2, procedural) → top-down boss sprites, 3/4 portraits, GLB exports.
- Real-time 3D: Three.js Keeper viewer (`web/keepers.html`) loading the GLBs.
- Game: Hours 1–3 use the Blender sprites; boss intro card shows the portrait.

## Kling jobs (account 49246555)
| Keeper | Generation ID | Credits |
|---|---|---|
| Wepwawet, Opener of Ways | AQuC_cN0rSvS1svV2PhSV-4iWzt8Nk8RzpmT18BNo7EcTJ8BKllvs4MCizfAImvUVjSK-Rt3 | 4 |
| Sobek Reborn | AaIGEOM_8IIn5TuNFM0LP-zKjBWd7vpx49SAzX9bLbbS1bil0mlCAMhcL3nM_ahe9K9p3e6u | 4 |
| UMBRA, the Shadow Heir | ARjZu9qtpGyS_XZNs-uAxhp_TDT-TiD9L6Cdzzlln-BJWIO552Q-MBlv-Aw4jSTuL_EuUwE6 | 4 |

Kling result URLs expire after 24 h, and this sandbox cannot download from Kling's CDN.

## Constraints
- Never change Part 1 (`web/`, `docs/`, `godot/`); sequel lives in `sunder-ascension-ii/`.
- Battle-math law holds; sequel never writes to Part 1's leaderboard.

## Done: Act II Keepers (Hours 4–6) — Nun, Sokar, the Fire Lake Seraphs (see final-evidence.md)

## Done: Act III Keepers (Hours 7–9) — UMBRA Coiled, the Hittite Engine, Ammit (see final-evidence.md)

## Done: Act IV — the Overlord's Echo, UMBRA Unmasked, Apep (+ final phase), stage backdrops for Hours 10–12

## Done: stage backdrops for Hours 1–9 (Blender), Kling concepts requested for each

## Done: art moved out of game.html into web/assets/ (808 KB → 111 KB)

## Next
- Fold in Kling stage concepts the user sends back (art/kling/stage_<id>.png, re-run stages.py).
- Optional: send the favourite Kling concepts back into the chat so the models can be matched to them.

## Act IV Kling jobs (account 49246555, 4 credits each)
| Image | Generation ID |
|---|---|
| Overlord's Echo concept | AdFrx72QR9tWJ_tAumh43ljxHB1aaBUBw0lGqLM6ihxWwEUTr1AzPdSVHv5KF29CjCtuyYCg |
| UMBRA Unmasked concept | ASGvQfuNnU4q6otnsRLmC4OSJQCYMzjUqdbBWRXbnyadx5NiEvHYppJWh1Hwq5GAJtZRmOZe |
| Apep concept | AXKhL_5tPL6P3F4yYuj4rj_lNKsSrYdWEEccT5lxJhaCXSgRqd8vFqLjeZrpwixlpFpDdPgg |
| Stage 10 — Starfall (9:16 tile) | AYpe56bFBiODXPncTtROP8E3GvFM-PnTnynFglfS0HL5yfbRW8DD78IoY0kKBEL5U59MQWQn |
| Stage 11 — Heart chamber (9:16 tile) | AddAPZ9MJsCtOhmUrrI5yOU6kGjd9lBLF98hU50RvxZ6NM_pCQkhJZu-q2QxUpP9YFz-1ZD7 |
| Stage 12 — Apep's back (9:16 tile) | AePLNRS8HHZKYAkdqh8paYj36fckKkrI9tgjaWiiWtXlfz5As6FA45_GFYwu-YjNdxTd41MK |

## Hours 1–9 stage concept jobs (Kling, 4 credits each, 9:16, 2 images)
| Hour | Generation ID |
|---|---|
| 1 Western Horizon | AVHGrBAH2mct_yVCAtPzBFmnSl5WZ64_cxILbCa3Md8wravhsQcC6VwOfLaGB6ozuzsE5iAe |
| 2 Drowned Fields | AeGncFA6NLway761_4tcOjm0cKJK4U9hwdccUjhytzqGfI8qJnQ0sFQyvGZxr69cXQY1jG3x |
| 3 Mirror | AYh0A-J6g7TRWg08olE1mhMkMOgn_9W0iu41B8agd9SkUYe2rRcCbIM1QiDsQNJXYZJa2FmY |
| 4 Sunken Spires | AXscCYVp7ynIcsj6CW2ydxBYJQTMkejnwv2oVuiDigf-qP5GTOqHDe8H0eksrRth9wEdq0UA |
| 5 Sokar's Sand | AdjK-jBcAKPp-OBPSZR9rX-gqTeY9LV04_Tssn4u4ZctoKm6OT0ZZ9QMUnvrn04Fl0loI9LB |
| 6 Lake of Fire | ATatDwHaWIwr9hVTGppkZ115YtvQktodKfrw1DtkP5RAF0vv4HG_sjrm2J6jzsEron3KMat0 |
| 7 Coiled One | AQ0frvLaZ757hJcZpnIzRGTAA9QHTAkZEkLI7TU_TNtJzQxNvbCEu-qZk-9IVbCrmEyznaAG |
| 8 Iron Sky | AXhrWwr8EIkt-Ft08DEuQ4YYzk13VvQQmWFE4VwJ7N5Plw317LL0OwOqkApx9FrqZE-OqMvW |
| 9 Judgement Hall | ARoZcPRWQGDFNMs0JRtv3ryXoM6TNvBEpJ1lU7HrwEHXdIo4CCHh8YWnw4qbn3QYyC-E6wyg |
Workflow: save a chosen image as `art/kling/stage_<id>.png` and re-run `blender/stages.py` — it becomes the ground texture.
