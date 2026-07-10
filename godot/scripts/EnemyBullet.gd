extends Area2D
## Void-purple projectile fired by enemy drones.

@export var velocity: Vector2 = Vector2(0, 220)

func _physics_process(delta: float) -> void:
	position += velocity * delta
	var vp := get_viewport_rect().size
	if position.y > vp.y + 30 or position.y < -30 or position.x < -30 or position.x > vp.x + 30:
		queue_free()

func _ready() -> void:
	add_to_group("enemy_bullets")
