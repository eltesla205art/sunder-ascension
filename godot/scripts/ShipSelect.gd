extends Node2D
## Ship select screen. Left/Right to browse the 3 starcraft, Space to launch.
## Passes the chosen ship index to Main via a global.

var _index: int = 0

@onready var starfield: Node2D = $Starfield
@onready var name_label: Label = $UI/ShipName
@onready var class_label: Label = $UI/ShipClass
@onready var stats_label: Label = $UI/Stats
@onready var persona_label: Label = $UI/Persona
@onready var hint_label: Label = $UI/Hint
@onready var preview: Sprite2D = $Preview
@onready var arrows: Label = $UI/Arrows

func _ready() -> void:
	AudioManager.play("main")
	_refresh()

func _process(_delta: float) -> void:
	if Input.is_action_just_pressed("move_left"):
		_index = (_index - 1 + ShipData.ship_count()) % ShipData.ship_count()
		_refresh()
	elif Input.is_action_just_pressed("move_right"):
		_index = (_index + 1) % ShipData.ship_count()
		_refresh()
	elif Input.is_action_just_pressed("fire"):
		GameState.selected_ship = _index
		get_tree().change_scene_to_file("res://scenes/Main.tscn")

func _refresh() -> void:
	var s := ShipData.get_ship(_index)
	name_label.text = s.name
	name_label.add_theme_color_override("font_color", s.tint)
	class_label.text = "— %s —" % s.ship_class
	preview.modulate = s.tint
	preview.scale = Vector2(2.2, 2.2)
	var hp := "%d" % s.max_health
	var spd := _bar(s.speed, 250.0, 400.0)
	var rate := _bar(0.20 - s.fire_rate + 0.09, 0.09, 0.20)  # invert: faster = fuller
	var pwr := _bar(float(s.bullet_damage), 1.0, 2.0)
	stats_label.text = "HULL   %s\nSPEED  %s\nFIRE   %s\nPOWER  %s\nBOMBS  %d" % [
		"\u2665".repeat(s.max_health), spd, rate, pwr, s.bombs
	]
	persona_label.text = s.personality
	arrows.text = "\u25C0   %d / %d   \u25B6" % [_index + 1, ShipData.ship_count()]
	hint_label.text = "\u2190 / \u2192  choose      SPACE  launch"

func _bar(v: float, lo: float, hi: float) -> String:
	var pct := clampf((v - lo) / (hi - lo), 0.0, 1.0)
	var filled := int(round(pct * 10))
	return "\u2588".repeat(filled) + "\u2591".repeat(10 - filled)
