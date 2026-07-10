extends Node
## ShipData — the three selectable starcraft of the Atlantean fleet.
## Each has its own color, shooting style, personality, base stats,
## and a 3-tier FORM evolution triggered by power level.
##
## Ship select screen reads this; Player.gd applies the chosen ship's stats
## and swaps sprite/tint as power level rises (form change).

const SHIPS: Array = [
	{
		"id": "sunborn",
		"name": "SUNBORN THUNDER",
		"ship_class": "The Balanced Heir",
		"personality": "Noble, steady, born to lead. Master of none's weakness, jack of every strength.",
		"tint": Color(0.90, 0.76, 0.32),        # gold
		"accent": Color(0.55, 0.85, 1.0),        # cyan core
		# --- base stats ---
		"speed": 320.0,
		"fire_rate": 0.14,
		"max_health": 3,
		"bombs": 3,
		# --- shooting style ---
		"style": "twin_spread",                  # balanced twin cannons that widen with form
		"bullet_damage": 1,
		# --- form evolution (sprite per power level 1/2/3) ---
		"forms": ["player.svg", "player.svg", "player.svg"],
		"form_names": ["Falcon", "Rising Falcon", "Solar Horus"],
		"form_scale": [1.0, 1.05, 1.12],
	},
	{
		"id": "scarab",
		"name": "SCARAB WARBRINGER",
		"ship_class": "The Juggernaut",
		"personality": "Fierce and unmoving. Trades speed for raw devastation. Hits like the fall of a dynasty.",
		"tint": Color(0.85, 0.25, 0.20),         # crimson
		"accent": Color(1.0, 0.55, 0.20),        # orange core
		"speed": 250.0,                          # slower
		"fire_rate": 0.20,                       # slower fire...
		"max_health": 4,                         # ...but tankier
		"bombs": 4,
		"style": "heavy_cannon",                 # fewer, bigger, higher-damage rounds
		"bullet_damage": 2,
		"forms": ["player.svg", "player.svg", "player.svg"],
		"form_names": ["Scarab", "Armored Scarab", "Khnum Ram"],
		"form_scale": [1.1, 1.18, 1.28],
	},
	{
		"id": "ibis",
		"name": "IBIS PHANTOM",
		"ship_class": "The Swift",
		"personality": "Quick, clever, elusive. Death by a thousand cuts. Gone before the enemy knows it's hit.",
		"tint": Color(0.30, 0.85, 0.50),         # emerald
		"accent": Color(0.75, 1.0, 0.85),        # pale green core
		"speed": 400.0,                          # fastest
		"fire_rate": 0.09,                        # rapid fire
		"max_health": 2,                          # fragile
		"bombs": 3,
		"style": "rapid_stream",                  # fast thin stream, more shots per form
		"bullet_damage": 1,
		"forms": ["player.svg", "player.svg", "player.svg"],
		"form_names": ["Ibis", "Twin Ibis", "Thoth Ascendant"],
		"form_scale": [0.92, 0.96, 1.0],
	},
]

static func get_ship(index: int) -> Dictionary:
	if index < 0 or index >= SHIPS.size():
		return SHIPS[0]
	return SHIPS[index]

static func ship_count() -> int:
	return SHIPS.size()
