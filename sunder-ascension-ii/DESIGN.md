# SUNDER: Ascension II — The Twelve Gates

A design pitch and prompt pack for the sequel to *SUNDER: Ascension — The Nine Bows*.
The story, gameplay ideas and a PS5-grade UI direction come first. After that is a
set of ready-to-paste prompts written with the repo's `prompt-optimizer` skill
(`skills/prompt-optimizer/`).

> **About the Raiden references.** The five reference screenshots are from Raiden and
> are used here only as a *gameplay and feel* reference: the vertical scroll, ground
> armor on terrain, the bomber mini-bosses, medal chaining, the homing plasma beam and
> the screen-filling bomb. **Don't ship, trace, or feed Raiden sprites or screenshots
> into an image model as style references.** Those assets are copyrighted, and the game
> was renamed SUNDER specifically to stay clear of the Raiden/Raijin marks
> (`docs/UPDATE_NOTES.md` §7). Game mechanics are fair to borrow; art and names aren't.
> Every prompt below describes *original* Egyptian-Atlantean art.

---

## 1. The storyline

### Where Part 1 left off
ELTESLA broke all Nine Bows. The Crystal Overlord shattered "into falling stars; the
sky heals gold," and the Sunborn Thunder went back to sleep beneath the sand. Act II also
left a thread hanging: **the Crystal "did not merely sink a city — it stole a heart."**
Part 1 never says where that heart went. Part 2 is built on that question.

### Premise — "The Starfall"
The falling stars were not debris. Each shard of the Overlord fell *through* the earth
and into the **Duat**, the underworld that Ra's sun-boat crosses every night. There the
shards woke what the Crystal had always served: **Apep, the Serpent of Unmaking**. The
Crystal was only its claws. Apep's hunger was the thing that drowned Atlantis.

Now the sun sets and doesn't rise. The first night lasts forty days, then the second. Crystal
gates climb out of the Nile, the Red Sea and the desert, and each one opens onto one of
the **Twelve Hours of the Night**. If Apep swallows the sun barque at the twelfth hour,
dawn never comes again.

The Thunder wakes on its own. And this time it isn't alone. The **Heart of
Atlantis** (the thing the Crystal stole) is beating somewhere at the bottom of the
Duat, and it's calling to the ship built from its seed.

### Characters
| Character | Role |
|---|---|
| **ELTESLA** | Returning pilot and heir of the old blood. Older, carrying the weight of Part 1. The Thunder now speaks to them in fragments. |
| **SEKHET-9** | *New ally.* An Atlantean guardian AI found inside the first gate. She runs the HUD comms and missions, the way a Cortana- or EDI-style voice does. She was built to guard the Heart and failed. |
| **UMBRA** | *Rival.* A crystal-grown copy of the Sunborn Thunder, flown by a pilot who wears ELTESLA's face. Fought three times (Hours 3, 7 and 11). In the final twist UMBRA is what the Crystal made from ELTESLA's own shadow when the Overlord fell. |
| **APEP** | Final antagonist. A serpent the width of the horizon, made of crystal, void and old light. |
| **The Twelve Keepers** | One boss per hour. Duat guardians corrupted by Apep's crystal. |

### Campaign — the Twelve Hours (12 stages, 4 acts)
Three hours per act. Each act gets an interlude card, the same way `INTERLUDES` works now.

**ACT I — DUSK (Hours 1–3): "The Sun Does Not Rise"**
1. **Hour of the Western Horizon.** Keeper: *Wepwawet, Opener of Ways* (jackal war-walker). Desert
   rail yards and crystal-infested tank columns; this is the Raiden-style desert armor stage.
2. **Hour of the Drowned Fields.** Keeper: *Sobek Reborn* (armored crocodile dreadnought
   rising from a flooded Nile delta).
3. **Hour of the Mirror.** Keeper: **UMBRA, first encounter.** A duel with no wingmen above a
   glass desert that reflects both ships.

**ACT II — MIDNIGHT (Hours 4–6): "The Drowned Heart"**
4. **Hour of the Sunken Spires.** Keeper: *Nun, the Primeval Deep*. You fly over the ruins of Atlantis,
   now fully lit and pulled up into the Duat.
5. **Hour of Sokar's Sand.** Keeper: *Sokar, Hawk of the Hidden Sand*. A dark sand-sea where the
   scroll speed changes with the dunes.
6. **Hour of the Lake of Fire.** Keeper: *The Fire Lake Seraphs* (four-part boss fight).

**ACT III — THE DEEP NIGHT (Hours 7–9): "Shadow of the Heir"**
7. **Hour of the Coiled One.** Keeper: **UMBRA, second encounter**, now with Apep's coils in the background.
8. **Hour of the Iron Sky.** Keeper: *The Hittite Engine*, an iron sky-fortress rebuilt from a Nine
   Bows foe. This is the payoff for Part 1 players.
9. **Hour of the Judgement Hall.** Keeper: *Ammit, Devourer of Hearts* (weighs your score against
   a feather; a mid-fight scoring puzzle).

**ACT IV — DAWN OR NOTHING (Hours 10–12): "The Last Sunrise"**
10. **Hour of the Starfall.** Keeper: *The Overlord's Echo*. A remnant of the Part 1 final boss.
11. **Hour of the Heart.** Keeper: **UMBRA, final encounter**. UMBRA drops its mask and the reveal lands.
    Beat it and UMBRA joins you as an **option drone** for Hour 12.
12. **Hour of Apep.** Keeper: **APEP, the Serpent of Unmaking**. A multi-phase vertical chase
    up the serpent's body with a final phase inside its jaws, where the Heart of Atlantis is waiting.

### Endings
- **True ending** (all 12 hours, no continues, or all 12 Heart Fragments collected):
  ELTESLA puts the Heart back into the Thunder. The sun barque rises with the Thunder
  flying escort, and Atlantis surfaces in the Mediterranean dawn. Tag line: *"Ascension complete."*
- **Standard ending:** Apep falls and dawn comes, but the Heart shatters. The Thunder sleeps
  again with one gold crack in its hull, which leaves room for Part 3.
- **Defeat:** "DAWN DENIED" (replaces "ASCENSION DENIED").

---

## 2. Gameplay ideas (Raiden feel, SUNDER identity)

These are taken from what the reference screenshots show and reworked in SUNDER's own terms:

| What the screenshots show | SUNDER II version |
|---|---|
| Red spread / blue laser weapon swaps | Keep the red and blue weapons. **Add violet: the "Ka Tether"**, a homing plasma beam that locks onto up to 4 targets and bends around cover. |
| Gold medal gems dropped by ground targets | **Ankh Medals.** They're worth more if you keep collecting them without missing one (chain ×2…×10). Letting one fall resets the chain. |
| "B" bomb pickups, screen-wide green bomb | **Eye of Ra bomb.** A solar flash that turns every bullet on screen into medals. It's already counted by the bomb cap of 9. |
| Twin wingmen at the player's side | **Option drones** ("Ba Spirits"): up to 2, each mirroring the current weapon at 50% damage. |
| Ground tanks, rail yards, bunkers under a scrolling camera | **Two-layer scroll.** Ground targets on parallax terrain and air targets above them. The ground armor uses full 3D models and casts real shadows. |
| Bomber planes that fill half the screen | **Mid-boss "Barque Carriers"** in every stage, with breakable parts that drop weapon upgrades. |
| 2-player co-op | **Local + online co-op.** Player 2 flies UMBRA's ship once it's unlocked. |

**New systems**
- **Heart Fragments.** Each stage has one hidden fragment (under a destructible, or found by
  finishing a boss before its timer runs out). Collecting all 12 unlocks the true ending.
- **Sun Meter.** A timer at the top of the HUD. It drains a little on every death, and if it runs
  out, the run ends in the standard ending, even if you win.
- **Fourth ship: SCARAB WARBRINGER Mk II** (the crimson ship in reference image 3). It's
  heavy, with twin side-cannons and a charge shot on L2/R2.
- **Swarm mode returns as "Endless Night"**, with a daily seed and its own global leaderboard.

**Battle math.** The five laws in `README.md` / the dev skill still apply. Build the sequel's
`STAGES` table with 12 entries. Boss bullets deal 2 from **Hour 7** onward (a proportional
version of the current "stage 5 of 9" rule). The UMBRA fights use player-scale hull ×3.

---

## 3. Elite PS5-style UI direction

The goal is for the web build to *feel* like a first-party PS5 title, even in a browser.

**Visual language**
- **Palette:** night indigo `#0B0F2A`, Duat violet `#5B2A86`, solar gold `#E6C252`, Atlantean
  cyan `#8CD9FF`, crystal magenta `#FF3FA4` (enemy-only). Gold is for the player, magenta is for the threat.
- **Type:** a wide geometric sans for headings (e.g. *Orbitron* / *Exo 2*) and a clean
  humanist sans for body text (*Inter*). All caps with wide letter-spacing on menus.
- **Materials:** frosted glass panels with a 1 px gold hairline border, a soft inner glow,
  and a subtle hieroglyph pattern at 4% opacity.
- **Motion:** 250 ms ease-out card slides, parallax tilt on the focused card, and
  a light sweep across the selected item. Hitting 60 fps in the menus is mandatory.

**Screens**
1. **Title / Press Start.** Full-bleed 3D key art (the Thunder rising over the Duat gate), a slowly
   orbiting camera, and "PRESS ✕ TO BEGIN" that pulses to the music's BPM.
2. **Home hub (PS5 "cards" layout).** A horizontal row of large tiles: *Campaign · Endless Night ·
   Hangar · Co-op · Leaderboards · Codex · Settings*. The focused tile grows and plays a looping video.
   An **Activity cards** row underneath ("Hour 4: Sunken Spires — 12 min — Resume").
3. **Hangar / ship select.** A 3D ship on a turntable under studio light, with stat bars that animate
   in and a form-evolution preview (Form 1 → 2 → 3).
4. **Hour map.** The twelve gates on a circular sundial. Cleared hours glow gold and locked hours show
   crystal cracks. Heart Fragment icons show which fragments you've collected.
5. **In-game HUD.** Minimal and pushed to the edges. Top-left: score + medal chain. Top-center: Sun Meter.
   Top-right: high score. Bottom-left: hull hearts + shields. Bottom-right: bombs (Eye of Ra icons).
   Boss health appears as a thin gold bar with the Keeper's name in hieroglyph-styled caps.
6. **Pause / results.** A blurred game frame behind a glass panel. On results screens, stats count up one at a time with
   a trophy-style "ACHIEVEMENT UNLOCKED" toast.
7. **Codex.** Lore entries for every Keeper, ship and Hour, unlocked as you play.

**PS5 hardware feel (where the platform allows)**
- **DualSense:** adaptive-trigger resistance on the R2 charge shot, a distinct haptic pattern for each
  weapon, and the lightbar color matching the equipped weapon. In a browser, use the Gamepad API
  plus `vibrationActuator` for rumble. Full adaptive triggers need a native PS5 build.
- **3D audio:** positional boss audio (WebAudio `PannerNode` on web, Tempest on PS5).
- **Performance modes:** "Fidelity (4K HDR 60)" and "Performance (120 Hz)" toggles in Settings.
- **Accessibility:** colorblind-safe bullet palettes, a hitbox-always-visible toggle, remappable
  controls and adjustable screen-shake.

**Tech path.** The current game is a single-file 2D canvas. For "elite graphics," move the
renderer to Three.js with an orthographic top-down camera. Keep the gameplay logic in
2D, and draw it with 3D ships/terrain, bloom, and HDR explosions. The repo's `skills/threejs-*`
pack covers this (start with `threejs-game-director`, then `threejs-aaa-graphics-builder`
and `threejs-game-ui-designer`). A true PS5 release would need Sony's developer program
and an engine port (Godot/Unity/Unreal). The existing `godot/` project is the natural base for that.

---

## 4. Prompt pack (built with `prompt-optimizer`)

Each prompt names the optimizer mode it was written in. Anything in `{{double_curly}}` is a
variable to fill in; the rest is ready to paste.

### 4.1 Master build prompt — *system-output-format*
Paste this as the system prompt of a Claude (or other LLM) session that will build the sequel.

```markdown
# Role: SUNDER II Lead Game Developer

## Profile
- language: English
- description: Senior HTML5/Three.js game developer building "SUNDER: Ascension II — The Twelve Gates", the sequel to the vertical shooter SUNDER: Ascension — The Nine Bows by Ascension Media Group.
- background: 10+ years shipping arcade shoot-'em-ups and console UI; expert in Three.js, WebAudio, the Gamepad API and 60 fps mobile performance.
- personality: Direct, precise, shows working code rather than describing it.
- target_audience: Andre EL (owner/designer) and playtesters on phones, PCs and controllers.

## Skills
1. Gameplay
   - Vertical-scroll shmup systems: weapons (red spread, blue laser, violet homing "Ka Tether"), option drones, medal chains, bombs, mid-bosses, multi-phase bosses.
   - Balance using the SUNDER battle-math law (below).
2. Presentation
   - Three.js orthographic top-down rendering with bloom, HDR explosions, parallax terrain and real shadows.
   - PS5-style menu UI: card hub, activity cards, glass panels, 250 ms eased motion.

## Rules
1. Battle-math law (never break):
   - Player damage = (base + 1 if blue weapon) × power level.
   - Boss hull = STAGES[i].boss_health × 1.3, rounded to 10s.
   - Enemy bullets deal 1; boss bullets deal 2 from Hour 7; boss contact deals 2.
   - Stage length = round(score_to_boss × 1.6).
   - Stage clear: +1 life (cap maxHp+2), +1 bomb (cap 9), +1 shield (cap 3).
   - A shield absorbs an entire hit, followed by 0.8 s of invulnerability.
2. Art and IP:
   - All art, names and audio must be original Egyptian-Atlantean designs. Never reproduce sprites, logos, names or music from Raiden or any other existing game.
   - Enemy color = crystal magenta #FF3FA4; player color = solar gold #E6C252 / cyan #8CD9FF.
3. Engineering:
   - Hold 60 fps on a mid-range phone; degrade post-processing before gameplay.
   - Touch input uses a per-frame pulse queue, never setTimeout pulses.
   - Keep the Supabase leaderboard/signup/comment integration working.

## Workflows
- Goal: deliver {{feature_or_stage}} for SUNDER II.
- Step 1: Restate the feature in one sentence plus its acceptance criteria.
- Step 2: List the files and data tables that change.
- Step 3: Write the code.
- Step 4: Write a test (or test-harness addition) that proves the battle-math law still holds.
- Expected result: working, tested code ready to drop into the build.

## OutputFormat
1. Format:
   - type: markdown
   - structure: "## Plan" (≤6 bullets) → "## Code" (complete fenced files or exact diffs) → "## Test" → "## How to verify" (≤5 steps)
2. Validation:
   - Every code block is complete and runnable; no "…rest unchanged" placeholders inside a changed function.
   - error_handling: if {{feature_or_stage}} conflicts with the battle-math law, stop and explain the conflict instead of coding it.

## Initialization
As SUNDER II Lead Game Developer, follow the Rules, work through the Workflows, and respond in the OutputFormat.
```

### 4.2 Production plan — *user-planning*

```markdown
# Task: Production plan for SUNDER: Ascension II — The Twelve Gates

## 1. Role and Goal
You will act as an indie game producer. Your goal is a milestone plan that takes SUNDER II from design doc to a public web playtest in {{weeks_available}} weeks with a team of {{team_size}}.

## 2. Background and Context
SUNDER: Ascension (Part 1) is a live single-file HTML5 shooter: 9 stages, 3 ships, swarm mode, Supabase leaderboard. The sequel adds 12 stages ("Twelve Hours of the Night"), a rival (UMBRA), a 4th ship, the violet homing weapon, medal chains, Heart Fragments, a Three.js renderer and a PS5-style UI. The full design is in sunder-ascension-ii/DESIGN.md.

## 3. Key Steps
1. **Vertical slice**: Hour 1 fully playable with the new renderer, HUD and one boss.
2. **Systems**: weapons, medals, options, Sun Meter, Heart Fragments.
3. **Content**: remaining 11 Hours, 12 Keepers, 3 UMBRA fights.
4. **UI/UX**: title, hub, hangar, hour map, codex, settings.
5. **Audio + story**: music per act, SEKHET-9 voice lines, interludes.
6. **QA + launch**: test harness, balance pass, playtest hub update, sunderascension.com deploy.

## 4. Output Requirements
- **Format**: markdown table with columns Milestone | Weeks | Deliverables | Exit criteria | Risk.
- **Style**: plain, practical, no hype.
- **Constraints**:
  - The vertical slice must land in the first 25% of the schedule.
  - Flag any milestone that depends on paid tools or external approvals (e.g. Sony developer program).
  - Respond with the final plan only, without step narration.
```

### 4.3 Story & dialogue writer — *system-general*

```markdown
# Role: SUNDER II Narrative Writer

## Profile
- description: Writes in-game text for SUNDER: Ascension II: stage briefings, boss taunts, stage-clear lines, act interludes, SEKHET-9 comms and codex entries.
- background: Mythic-sci-fi writer steeped in Egyptian mythology (the Duat, the Twelve Hours, Apep, Ammit, Sokar) and Atlantis legend.
- personality: Epic, compressed, arcade-punchy.

## Rules
- Canon: ELTESLA broke the Nine Bows in Part 1; the Overlord's shards fell into the Duat and woke Apep; the Heart of Atlantis is the goal; UMBRA is ELTESLA's crystal shadow (don't reveal this before Hour 11).
- Length limits: briefing ≤ 40 words, boss taunt ≤ 15 words, stage-clear line ≤ 10 words, interlude ≤ 90 words, codex entry ≤ 120 words.
- Never use names or lines from other games or films.
- Refer to the player only as ELTESLA or "Heir."

## Workflows
- Input: {{hour_number}} and {{text_type}}.
- Output: the text only, formatted as a JavaScript string ready to paste into the game's data tables.
```

### 4.4 Key art — *image-t2i*

```text
A sleek golden starfighter with cyan energy veins, the Sunborn Thunder, climbs vertically out of a colossal crystal gate that rises from a night-black desert, trailing a column of solar fire. Behind it, a serpent of violet crystal and void, as wide as the horizon, coils around a darkened sun, while magenta crystal warships pour out of the gate below. Low-angle hero shot looking up, 16:9 widescreen, the ship in the upper third with room for a title in the lower third. The only warm light comes from the ship's engines and a thin gold rim on the eclipsed sun; everything else is lit by cool indigo moonlight and magenta crystal glow. Deep indigo, violet and solar gold palette, with glossy enamel hull plating, carved Egyptian-Atlantean panel lines and fine volumetric dust. Epic, reverent, AAA console cover-art mood; no text, no logos.
```

### 4.5 Hero ship from your red reference — *image-edit*
Use reference image 3 (the red starfighter) as the only input.

```text
Change: repaint the hull from red to deep crimson lacquer with brushed-gold trim, add carved Egyptian scarab-wing motifs to the two side panels, turn the orange canopy into a glowing amber scarab gem, and add two heavy side-cannons with gold muzzle rings.
Keep: the exact silhouette, symmetrical top-down view, proportions, engine layout and centered framing of the original ship.
Finish: clean studio lighting from above, soft ambient occlusion, white background, game-ready top-down sprite reference for "SCARAB WARBRINGER Mk II".
```

### 4.6 Boss concept (repeat per Keeper) — *image-t2i with variables*

```text
A colossal {{keeper_name}} boss, {{keeper_description}}, grown from translucent magenta crystal fused with ancient Egyptian bronze and carved hieroglyph armor, seen from directly above as a vertical-scrolling shooter boss. It fills the top half of a 9:16 portrait frame over {{stage_environment}}, with glowing weak-point cores and turret clusters clearly readable as targets. Hard magenta core light against cool indigo ambient light, with sharp rim highlights on the bronze edges. Palette of crystal magenta, bronze and deep indigo, with glossy crystal, pitted metal and faint energy haze. Menacing, mythic, readable at small size; no text.
```
Example fill: `{{keeper_name}}` = "Sobek Reborn", `{{keeper_description}}` = "an armored crocodile dreadnought with jaw-mounted cannons",
`{{stage_environment}}` = "a flooded Nile delta at night with broken obelisks".

### 4.7 Stage backdrop — *image-t2i*

```text
A seamless top-down terrain tile for a vertical-scrolling shooter: {{stage_environment}}, crossed by ancient rail lines, crystal-infested bunkers and scorched craters, viewed straight down at 90 degrees. Portrait 9:16, with no single focal point so it tiles vertically and leaves clear space for sprites. Moonlit from the upper left with long soft shadows and small pockets of magenta crystal glow. Muted desert ochre, charcoal and indigo, with gritty sand, cracked stone and weathered metal texture. Painterly-realistic AAA background art; no characters, no vehicles, no text.
```

### 4.8 PS5 home hub UI mockup — *image-t2i*

```text
A premium console game home menu for "SUNDER: Ascension II": a horizontal row of seven large rounded tiles labeled CAMPAIGN, ENDLESS NIGHT, HANGAR, CO-OP, LEADERBOARDS, CODEX, SETTINGS, with the CAMPAIGN tile focused, enlarged and glowing, above a smaller row of activity cards. Behind the tiles, a blurred cinematic view of a golden starfighter above a crystal desert gate at night. 16:9, 4K UI screenshot framing, generous safe margins, crisp wide geometric sans-serif type in all caps. Frosted glass panels with thin gold hairline borders and a soft cyan glow on the focused tile. Palette of night indigo #0B0F2A, violet #5B2A86, solar gold #E6C252 and cyan #8CD9FF. Clean, luxurious, first-party console feel; readable text, no platform logos.
```

### 4.9 In-game HUD mockup — *image-t2i*

```text
A gameplay screenshot of a vertical-scrolling shooter in 9:16 portrait: a golden starfighter at the bottom center firing a violet homing plasma beam that curves into three magenta crystal gunships over a moonlit desert with rail yards. A minimal HUD sits hugged to the edges: score and "CHAIN ×7" at top left, a thin gold "SUN" meter at top center, high score at top right, three gold heart icons and two shield pips at bottom left, and three eye-shaped bomb icons at bottom right. Top-down camera, bright readable bullets against a darker ground. Gold for player elements, magenta for enemies, cyan for UI accents, frosted-glass HUD plates. Modern high-end console arcade look with bloom on projectiles; all HUD text crisp and legible.
```

### 4.10 Trailer shot — *image-t2i → video*

```text
A cinematic 8-second shot: the camera starts low on a black desert under a sunless sky, a crystal gate cracks open with magenta light, and a golden starfighter bursts out of the sand in a spray of gold dust, banks toward camera, and climbs as a colossal violet serpent silhouette coils across the clouds above. Handheld-feel crane-up move, 16:9. Engine glow is the key light; magenta crystal is the fill. Deep indigo, gold and magenta, with heavy volumetric dust and lens flares. Epic, ominous, console launch-trailer tone; no text.
```

### 4.11 Music (per act) — *user-professional*

```text
Write a 2:30 instrumental loop for Act {{act_number}} of a vertical space shooter set in the Egyptian underworld. Tempo {{bpm}} BPM, key {{key}}. Blend driving synthwave bass and arcade drums with ancient Egyptian instruments (ney flute, oud, frame drum, sistrum). Structure: 8-bar intro, A section, B section with a rising brass-synth melody, seamless loop point back to A. Mood: {{mood}}. No vocals, no lyrics, and no melodies quoted from existing games.
```
Suggested fills: Act I 140 BPM D minor "heroic dusk"; Act II 132 BPM F minor "drowned and
mysterious"; Act III 150 BPM C# minor "desperate, dark"; Act IV 160 BPM E minor "triumphant dawn".

---

## 5. Suggested next steps
1. Lock the story and names above (or change them). Then use prompt 4.3 to generate all 12 briefings
   and taunts.
2. Generate the key art (4.4) and the Mk II ship (4.5) to set the visual bar.
3. Use prompt 4.1 to build the **Hour 1 vertical slice** in Three.js, reusing the existing
   engine, leaderboard and test harness.
4. Before announcing the title, run "SUNDER" plus the subtitle through a USPTO trademark search (Class 9).
