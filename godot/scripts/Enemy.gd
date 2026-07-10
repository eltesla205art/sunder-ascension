extends Area2D
## Faction enemy — behavior driven by the stage config passed via configure().

signal destroyed(points)
signal drop_powerup(pos, kind)

var health: int = 2
var speed: float = 120.0
var points: int = 100
var fire_interval: float = 1.6
var bullet_speed: float = 220.0
var move_type: String = "dive"
var drop_chance: float = 0.18
var tint: Color = Color.WHITE

var _time: float = 0.0
var _fire_timer: float = 0.0
var _base_x: float = 0.0
var _phase_off: float = 0.0
var _evade_dir: int = 1

var enemy_bullet_scene: PackedScene = preload("res://scenes/EnemyBullet.tscn")

func configure(cfg: Dictionary) -> void:
	health = cfg.get("enemy_health", 2)
	speed = cfg.get("enemy_speed", 120.0)
	points = cfg.get("enemy_points", 100)
	fire_interval = cfg.get("enemy_fire_interval", 1.6)
	bullet_speed = cfg.get("enemy_bullet_speed", 220.0)
	move_type = cfg.get("enemy_move", "dive")
	drop_chance = cfg.get("drop_chance", 0.18)
	tint = cfg.get("tint", Color.WHITE)

func _ready() -> void:
	add_to_group("enemies")
	_base_x = position.x
	_phase_off = randf() * TAU
	_fire_timer = fire_interval * randf_range(0.4, 1.0)
	$Sprite2D.modulate = tint

func _physics_process(delta: float) -> void:
	_time += delta
	_apply_movement(delta)

	_fire_timer -= delta
	if _fire_timer <= 0.0:
		_fire()
		_fire_timer = fire_interval

	var vp := get_viewport_rect().size
	if position.y > vp.y + 50 or position.x < -60 or position.x > vp.x + 60:
		queue_free()

func _apply_movement(delta: float) -> void:
	var vp := get_viewport_rect().size
	match move_type:
		"dive":
			position.y += speed * delta
		"weave":
			position.y += speed * delta
			position.x = _base_x + sin(_time * 2.0 + _phase_off) * 90.0
		"rush":
			position.y += speed * 1.4 * delta
		"zigzag":
			position.y += speed * delta
			position.x += sin(_time * 6.0 + _phase_off) * 140.0 * delta
		"circle":
			position.y += speed * 0.7 * delta
			position.x = _base_x + cos(_time * 2.5 + _phase_off) * 110.0
		"formation":
			position.y += speed * delta
			position.x = _base_x + sin(_time * 1.2) * 40.0
		"evade":
			position.y += speed * delta
			# dodge toward gaps: flip direction periodically
			if fmod(_time, 0.8) < delta:
				_evade_dir *= -1
			position.x += _evade_dir * speed * 0.8 * delta
			position.x = clamp(position.x, 30, vp.x - 30)

func _fire() -> void:
	var players := get_tree().get_nodes_in_group("player")
	var dir := Vector2(0, 1)
	if players.size() > 0:
		dir = (players[0].position - position).normalized()
	_spawn_bullet(dir * bullet_speed)
	# rush + formation factions double-tap
	if move_type == "formation" or move_type == "rush":
		_spawn_bullet(dir.rotated(deg_to_rad(12)) * bullet_speed)

func _spawn_bullet(vel: Vector2) -> void:
	var b := enemy_bullet_scene.instantiate()
	b.position = position + Vector2(0, 22)
	b.velocity = vel
	get_parent().add_child(b)

func take_damage(amount: int) -> void:
	health -= amount
	_hit_flash()
	if health <= 0:
		destroyed.emit(points)
		if randf() < drop_chance:
			var roll := randf()
			var kind := "red" if roll < 0.35 else ("blue" if roll < 0.7 else ("power" if roll < 0.92 else "life"))
			drop_powerup.emit(position, kind)
		queue_free()

func _hit_flash() -> void:
	$Sprite2D.modulate = Color(2, 2, 2)
	var t := create_tween()
	t.tween_property($Sprite2D, "modulate", tint, 0.12)
