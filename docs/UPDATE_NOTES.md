# UPDATE — Ship Select, Forms, Lives, Music

Everything you asked for, added on top of the 9-stage campaign.

## 1. Ship Select screen (NEW — plays first)
Boots into a select screen. **← / →** to browse the 3 craft, **SPACE** to launch.
Each ship shows its name, class, stat bars (hull/speed/fire/power/bombs), and personality.

## 2. Three starships — each unique
| Ship | Color | Style | Personality | Feel |
|------|-------|-------|-------------|------|
| **Sunborn Thunder** | Gold/cyan | Twin spread (widens with form) | The Balanced Heir — noble, steady | All-rounder |
| **Scarab Warbringer** | Crimson/orange | Heavy cannon (big, 2× damage) | The Juggernaut — fierce, unmoving | Slow, tanky, hits hard |
| **Ibis Phantom** | Emerald/silver | Rapid stream (fast thin shots) | The Swift — quick, elusive | Fragile, fast, high fire rate |

Different speed, fire rate, hull, bombs, and bullet damage per ship — all in `scripts/ShipData.gd`, easy to tune.

## 3. Form evolution (NEW)
Every time your power level rises (via power-ups), the ship **changes form** — scales up, tint shifts toward its accent color, and a burst flashes. Each ship has 3 named forms:
- Sunborn: Falcon → Rising Falcon → Solar Horus
- Scarab: Scarab → Armored Scarab → Khnum Ram
- Ibis: Ibis → Twin Ibis → Thoth Ascendant

(Forms currently reuse the base sprite with visual FX. Drop `sunborn_1/2/3.svg` etc. into assets/sprites and update the `forms` list in ShipData for full art swaps.)

## 4. More power-ups + lives (NEW)
- **+1 life restored after every stage cleared** (up to your ship's cap +2 overheal)
- **New "life" pickup** — a red ankh diamond, rare enemy drop (~8% of drops), restores a heart
- Existing red/blue (weapon), gold (power) pickups still there

## 5. Music system (NEW)
Full audio manager with fade + loop:
- Heroic galaxy theme on select + stages
- Intense boss theme when a boss appears
- Victory sting on the win screen
Add your tracks to `assets/audio/` (see README_MUSIC.md for exact names + Suno prompts). Missing files are skipped silently, so the game runs with or without audio.

## 6. Game Over renamed
"GATE BREACHED" → **"ASCENSION DENIED"**

---

### Files added
`scripts/ShipData.gd`, `scripts/ShipSelect.gd`, `scripts/GameState.gd`, `scripts/AudioManager.gd`, `scenes/ShipSelect.tscn`, `assets/sprites/powerup_life.svg`, `assets/audio/README_MUSIC.md`

### New autoloads
ShipData, GameState, AudioManager (plus existing StageData, StoryData)

---

## 7. RENAMED → "SUNDER: Ascension"
Game officially retitled from "Atlantean Blueprint: The Nine Bows" to **SUNDER: Ascension** (subtitle: The Nine Bows). Chosen after trademark research: "Sunder" is clear in the games class, phonetically distinct from protected shmup marks (unlike "Raiden"/"Raijin"), and ownable — sounds like "sun + thunder," means "to tear apart."

**New title screen** (`scenes/Title.tscn`) boots first: pulsing "PRESS SPACE TO BEGIN," AMG credit, then → ship select → campaign. Built-in vector logo works now; drop a Higgsfield logo as `assets/sprites/title_logo.png` to swap it in (see TITLE_LOGO_README.md).

⚠️ Before commercial launch: run "SUNDER" through the USPTO TESS search (Class 9) and ideally an attorney clearance. A web search isn't a legal clearance.
