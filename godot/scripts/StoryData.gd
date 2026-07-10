extends Node
## StoryData — the narrative of THE NINE BOWS.
## Opening crawl, per-stage briefings, boss intro lines, and endings.
## Referenced by Main.gd to show story beats between the action.

# --- OPENING CRAWL (shown at game start) ---
const OPENING: Array = [
	"ATLANTEAN BLUEPRINT",
	"— THE NINE BOWS —",
	"",
	"Before Egypt, there was ATLANTIS.",
	"When it fell, its last engineers hid",
	"their greatest weapon beneath the sands:",
	"THE SUNBORN THUNDER —",
	"a starcraft grown from a single seed of gold.",
	"",
	"For ten thousand years it slept.",
	"",
	"Now the sky burns. The Crystal —",
	"the ancient enemy that drowned Atlantis —",
	"has returned, and it does not come alone.",
	"It has raised the NINE BOWS:",
	"every foe Egypt ever faced,",
	"reborn in crystal and fury.",
	"",
	"You are ELTESLA, heir of the old blood.",
	"The Thunder answers only to you.",
	"",
	"Rise. Hold the line. Break all nine.",
]

# --- PER-STAGE BRIEFINGS (shown before each stage begins) ---
# Keyed by stage number (1-9).
const BRIEFINGS: Dictionary = {
	1: {
		"quote": "\"The southern archers come first — they always tested us first.\"",
		"brief": "The Nubians of the crystal have risen from the First Cataract. Their arrows blot the sun. A gentle test — but the Crystal is watching how you fight.",
	},
	2: {
		"quote": "\"The desert never forgot its grudge.\"",
		"brief": "The Libyan raiders sweep in from the western dunes, faster and in greater number. Warlord Meshwesh rides at their head, scattering fire across the sky.",
	},
	3: {
		"quote": "\"They took Egypt once — with chariots of bronze. Now they ride chariots of light.\"",
		"brief": "The Hyksos invaders charge without pause. Chariot Lord Khyan carves the heavens in horizontal sweeps. Do not stand still.",
	},
	4: {
		"quote": "\"A tide of drowned nations. They have no home — so they will take yours.\"",
		"brief": "The Sea Peoples surge in a broken, zigzagging swarm. Wave Tyrant Peleset commands the tides themselves, firing in rings that close like a net.",
	},
	5: {
		"quote": "\"Iron does not bleed. Iron does not tire. But iron can be broken.\"",
		"brief": "The Hittite Empire arrives armored and unrelenting. Iron Charioteer Muwatalli weaves crosses of fire through the void. Halfway there — the Crystal grows impatient.",
	},
	6: {
		"quote": "\"The horse-lords of the north. They circle before they strike.\"",
		"brief": "The Mitanni flankers spiral around you, hunting your blind spots. Maryannu Rider Tushratta answers with rotating spirals that never seem to end.",
	},
	7: {
		"quote": "\"The siege that never ends. This is where lesser pilots fall.\"",
		"brief": "The Assyrian war-machine advances in dense formation, walls of fire crashing down. Siege King Ashurbanipal has broken a hundred cities. Do not become the hundred-and-first.",
	},
	8: {
		"quote": "\"The Immortals. Kill one, another takes its place. But you are not fighting men.\"",
		"brief": "The Persian Immortal Host is fast, evasive, and endless. Immortal Shah Cambyses twists dual spirals into the dark. The gate to the Overlord lies just beyond him.",
	},
	9: {
		"quote": "\"All nine, as one. And behind them — the thing that drowned the world.\"",
		"brief": "The Nine Bows unite in a single storm. And above them descends THE CRYSTAL OVERLORD — the enemy of Atlantis itself. Everything ends here. Break it, ELTESLA, or the sky falls forever.",
	},
}

# --- BOSS INTRO LINES (shown when a boss appears) ---
const BOSS_LINES: Dictionary = {
	1: "\"Golden ghost. You will not pass the First Cataract.\"",
	2: "\"The dunes will bury you and your machine both!\"",
	3: "\"We ruled Egypt once. We will rule its ashes again.\"",
	4: "\"Drown with us, child of the old blood.\"",
	5: "\"Iron against gold. Let us see which bends.\"",
	6: "\"Round and round — you cannot see where death comes from.\"",
	7: "\"I have broken kings. You are only a pilot.\"",
	8: "\"I am one of ten thousand. You are one. Do the arithmetic.\"",
	9: "\"I DROWNED ATLANTIS. I WILL DROWN WHAT LITTLE REMAINS OF IT — YOU.\"",
}

# --- STAGE-CLEAR LINES (shown after each boss falls) ---
const CLEAR_LINES: Dictionary = {
	1: "The archers scatter. The Thunder hums, satisfied. One bow broken.",
	2: "The desert falls silent. Two bows broken. The Crystal shifts its gaze.",
	3: "The chariots shatter into light. Three bows broken. You are being remembered.",
	4: "The tide recedes. Four bows broken. Halfway to the drowned truth.",
	5: "Iron breaks after all. Five bows broken. The sky thins — you can almost see it now.",
	6: "The spirals unwind into nothing. Six bows broken. The Overlord stops pretending.",
	7: "The siege lifts. Seven bows broken. Only two stand between you and the enemy of Atlantis.",
	8: "The last Immortal falls. Eight bows broken. The gate opens. It is time.",
}

# --- ENDINGS ---
const VICTORY: Array = [
	"THE NINE BOWS ARE BROKEN.",
	"",
	"The Crystal Overlord shatters into a rain",
	"of falling stars, and the sky heals gold.",
	"",
	"Ten thousand years of waiting — answered.",
	"Atlantis is avenged. Egypt stands eternal.",
	"",
	"The Sunborn Thunder returns to the sand,",
	"to sleep again... until the sky next burns.",
	"",
	"— ELTESLA, HEIR OF THE OLD BLOOD —",
]

const DEFEAT_TAG: String = "The Thunder goes dark. The sky keeps burning.\nBut the old blood does not stay down. Rise again."
