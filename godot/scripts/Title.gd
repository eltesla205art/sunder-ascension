extends Node2D
## Title screen — SUNDER: Ascension.
## Shows the logo (Higgsfield PNG if present at assets/sprites/title_logo.png,
## otherwise the built-in vector title), a pulsing prompt, then → ship select.

@onready var logo_img: TextureRect = $UI/LogoImage
@onready var logo_text: Control = $UI/LogoText
@onready var prompt: Label = $UI/Prompt
@onready var subtitle: Label = $UI/Subtitle

var _t: float = 0.0

func _ready() -> void:
	AudioManager.play("main")
	# Prefer a dropped-in Higgsfield logo if it exists
	var logo_path := "res://assets/sprites/title_logo.png"
	if ResourceLoader.exists(logo_path):
		logo_img.texture = load(logo_path)
		logo_img.visible = true
		logo_text.visible = false
	else:
		logo_img.visible = false
		logo_text.visible = true

func _process(delta: float) -> void:
	_t += delta
	# pulse the prompt
	prompt.modulate.a = 0.4 + 0.6 * abs(sin(_t * 2.2))
	if Input.is_action_just_pressed("fire"):
		get_tree().change_scene_to_file("res://scenes/ShipSelect.tscn")
