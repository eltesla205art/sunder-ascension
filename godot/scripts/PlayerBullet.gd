extends Area2D
## Player round. setup() configures direction, color tint, and damage.

var velocity: Vector2 = Vector2.UP * 640.0
var damage: int = 1

func setup(vel: Vector2, color: String) -> void:
	velocity = vel
	if color == "blue":
		modulate = Color(0.55, 0.85, 1.2)   # cyan tint
	else:
		modulate = Color(1.2, 0.85, 0.4)    # gold/red tint

func _ready() -> void:
	add_to_group("player_bullets")
	area_entered.connect(_on_area_entered)

func _physics_process(delta: float) -> void:
	position += velocity * delta
	if position.y < -30 or position.y > 760 or position.x < -30 or position.x > 510:
		queue_free()

func _on_area_entered(area: Area2D) -> void:
	if area.is_in_group("enemies") or area.is_in_group("boss"):
		if area.has_method("take_damage"):
			area.take_damage(damage)
		queue_free()
