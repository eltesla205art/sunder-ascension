extends Area2D
## Dropped pickup. kind = "red" | "blue" | "power" | "life".

@export var kind: String = "power"
@export var fall_speed: float = 90.0

var _tex := {
	"red": preload("res://assets/sprites/powerup_red.svg"),
	"blue": preload("res://assets/sprites/powerup_blue.svg"),
	"power": preload("res://assets/sprites/powerup_power.svg"),
	"life": preload("res://assets/sprites/powerup_life.svg"),
}

func _ready() -> void:
	add_to_group("powerups")
	area_entered.connect(_on_area_entered)
	if _tex.has(kind):
		$Sprite2D.texture = _tex[kind]

func _physics_process(delta: float) -> void:
	position.y += fall_speed * delta
	position.x += sin(position.y * 0.04) * 0.6
	var s := 1.0 + sin(position.y * 0.1) * 0.12
	scale = Vector2(s, s)
	if position.y > 760:
		queue_free()

func _on_area_entered(area: Area2D) -> void:
	if area.is_in_group("player"):
		if area.has_method("collect_powerup"):
			area.collect_powerup(kind)
		queue_free()
