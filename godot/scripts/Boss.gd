extends Area2D
## Faction Boss — runs a pattern set defined by the stage config.
## Cycles through boss_patterns; each 1/3 of HP unlocks a harder blend.

signal defeated(points)
signal health_changed(current, maximum)

var boss_name: String = "Boss"
var max_health: int = 200
var points: int = 4000
var patterns: Array = ["radial_burst"]
var fire_rate: float = 1.0
var bullet_speed: float = 200.0
var move_speed: float = 80.0
var tint: Color = Color.WHITE

var _health: int
var _phase: int = 1
var _time: float = 0.0
var _fire_timer: float = 0.0
var _spiral_angle: float = 0.0
var _pattern_idx: int = 0
var _pattern_switch: float = 0.0
var _entering: bool = true
var _target_y: float = 130.0
var _dir: int = 1

var enemy_bullet_scene: PackedScene = preload("res://scenes/EnemyBullet.tscn")

func configure(cfg: Dictionary) -> void:
	boss_name = cfg.get("boss_name", "Boss")
	max_health = cfg.get("boss_health", 200)
	points = cfg.get("boss_points", 4000)
	patterns = cfg.get("boss_patterns", ["radial_burst"])
	fire_rate = cfg.get("boss_fire_rate", 1.0)
	bullet_speed = cfg.get("boss_bullet_speed", 200.0)
	move_speed = cfg.get("boss_move_speed", 80.0)
	tint = cfg.get("tint", Color.WHITE)

func _ready() -> void:
	add_to_group("boss")
	_health = max_health
	$Sprite2D.modulate = tint
	health_changed.emit(_health, max_health)

func _physics_process(delta: float) -> void:
	_time += delta
	if _entering:
		position.y += 80.0 * delta
		if position.y >= _target_y:
			position.y = _target_y
			_entering = false
		return

	_update_phase()
	_move(delta)

	# rotate through this stage's patterns every ~3.5s
	_pattern_switch -= delta
	if _pattern_switch <= 0.0:
		_pattern_idx = (_pattern_idx + 1) % max(patterns.size(), 1)
		_pattern_switch = 3.5

	_fire_timer -= delta
	if _fire_timer <= 0.0:
		_run_current_pattern()

func _update_phase() -> void:
	var pct := float(_health) / float(max_health)
	_phase = 3 if pct <= 0.33 else (2 if pct <= 0.66 else 1)

func _move(delta: float) -> void:
	var s := move_speed + _phase * 25.0
	position.x += _dir * s * delta
	var vp := get_viewport_rect().size
	if position.x < 100:
		position.x = 100; _dir = 1
	elif position.x > vp.x - 100:
		position.x = vp.x - 100; _dir = -1

func _run_current_pattern() -> void:
	var p: String = patterns[_pattern_idx] if patterns.size() > 0 else "radial_burst"
	match p:
		"aimed_volley": _aimed_volley()
		"spread_fan": _spread_fan()
		"horizontal_sweep": _horizontal_sweep()
		"radial_burst": _radial_burst(14 + _phase * 3)
		"cross_ring": _cross_ring()
		"spiral": _spiral()
		"wall_barrage": _wall_barrage()
		"dual_spiral": _dual_spiral()
		_: _radial_burst(14)
	# fire cadence tightens with phase
	_fire_timer = fire_rate * (1.0 - _phase * 0.12)

# ---- pattern library ----
func _aimed_volley() -> void:
	var players := get_tree().get_nodes_in_group("player")
	if players.is_empty(): return
	var base: float = (players[0].position - position).angle()
	for i in range(-1, 2):
		_spawn(Vector2.RIGHT.rotated(base + deg_to_rad(14 * i)) * bullet_speed)

func _spread_fan() -> void:
	var count := 5 + _phase * 2
	for i in range(count):
		var t := float(i) / float(count - 1) - 0.5
		_spawn(Vector2.RIGHT.rotated(deg_to_rad(90) + deg_to_rad(70) * t) * bullet_speed)

func _horizontal_sweep() -> void:
	var side := 1 if fmod(_time, 2.0) < 1.0 else -1
	for i in range(6):
		_spawn(Vector2(side * bullet_speed, 40 + i * 25))

func _radial_burst(count: int) -> void:
	for i in range(count):
		_spawn(Vector2.RIGHT.rotated(TAU * i / count) * bullet_speed * 0.85)

func _cross_ring() -> void:
	_radial_burst(12)
	for a in [0, 90, 180, 270]:
		_spawn(Vector2.RIGHT.rotated(deg_to_rad(a) + _time) * bullet_speed)

func _spiral() -> void:
	_spiral_angle += 0.4
	for i in range(3):
		_spawn(Vector2.RIGHT.rotated(_spiral_angle + TAU * i / 3) * bullet_speed)

func _wall_barrage() -> void:
	# horizontal wall with a gap
	var gap := randi() % 6
	for i in range(8):
		if i == gap or i == gap + 1: continue
		var x := 60 + i * 50
		_spawn_at(Vector2(x, position.y + 20), Vector2(0, bullet_speed))

func _dual_spiral() -> void:
	_spiral_angle += 0.5
	for i in range(2):
		var a := _spiral_angle if i == 0 else -_spiral_angle
		_spawn(Vector2.RIGHT.rotated(a + PI * i) * bullet_speed)

func _spawn(vel: Vector2) -> void:
	_spawn_at(position + Vector2(0, 20), vel)

func _spawn_at(pos: Vector2, vel: Vector2) -> void:
	var b := enemy_bullet_scene.instantiate()
	b.position = pos
	b.velocity = vel
	get_parent().add_child(b)

func take_damage(amount: int) -> void:
	if _entering: return
	_health -= amount
	health_changed.emit(max(_health, 0), max_health)
	_hit_flash()
	if _health <= 0:
		_die()

func _hit_flash() -> void:
	$Sprite2D.modulate = Color(2.2, 1.8, 1.8)
	var t := create_tween()
	t.tween_property($Sprite2D, "modulate", tint, 0.1)

func _die() -> void:
	defeated.emit(points)
	var t := create_tween()
	t.tween_property(self, "scale", Vector2(1.5, 1.5), 0.35)
	t.parallel().tween_property($Sprite2D, "modulate:a", 0.0, 0.35)
	await t.finished
	queue_free()

func get_boss_name() -> String:
	return boss_name
