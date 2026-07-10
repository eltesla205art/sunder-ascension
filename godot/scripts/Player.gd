extends Area2D
## The player craft. Configured from ShipData based on the ship picked at select.
## RED/BLUE weapon overlay still applies, but each SHIP has a base shooting STYLE
## and its own stats. Collecting power-ups raises power level AND changes FORM
## (visual evolution: tint pulse + scale up + burst).

signal died
signal bomb_used(remaining)
signal weapon_changed(mode, level)
signal form_changed(form_name)

enum Weapon { RED, BLUE }

# --- configured from ShipData ---
var ship_id: String = "sunborn"
var ship_name: String = "SUNBORN THUNDER"
var speed: float = 320.0
var fire_rate: float = 0.14
var max_health: int = 3
var bombs: int = 3
var style: String = "twin_spread"
var base_damage: int = 1
var tint: Color = Color(0.9, 0.76, 0.32)
var accent: Color = Color(0.55, 0.85, 1.0)
var form_names: Array = ["I", "II", "III"]
var form_scale: Array = [1.0, 1.05, 1.12]

var weapon: Weapon = Weapon.RED
var power_level: int = 1
var _fire_cooldown: float = 0.0
var _health: int
var _invincible: bool = false

var bullet_scene: PackedScene = preload("res://scenes/PlayerBullet.tscn")

func setup_ship(cfg: Dictionary) -> void:
	ship_id = cfg.get("id", "sunborn")
	ship_name = cfg.get("name", "SUNBORN THUNDER")
	speed = cfg.get("speed", 320.0)
	fire_rate = cfg.get("fire_rate", 0.14)
	max_health = cfg.get("max_health", 3)
	bombs = cfg.get("bombs", 3)
	style = cfg.get("style", "twin_spread")
	base_damage = cfg.get("bullet_damage", 1)
	tint = cfg.get("tint", tint)
	accent = cfg.get("accent", accent)
	form_names = cfg.get("form_names", form_names)
	form_scale = cfg.get("form_scale", form_scale)

func _ready() -> void:
	_health = max_health
	area_entered.connect(_on_area_entered)
	$Sprite2D.modulate = tint
	_apply_form()
	weapon_changed.emit(weapon, power_level)

func _physics_process(delta: float) -> void:
	var dir := Vector2.ZERO
	dir.x = Input.get_axis("move_left", "move_right")
	dir.y = Input.get_axis("move_up", "move_down")
	if dir.length() > 1.0:
		dir = dir.normalized()
	position += dir * speed * delta

	var vp := get_viewport_rect().size
	position.x = clamp(position.x, 24, vp.x - 24)
	position.y = clamp(position.y, 24, vp.y - 24)

	_fire_cooldown -= delta
	if Input.is_action_pressed("fire") and _fire_cooldown <= 0.0:
		_shoot()
		var mult := 0.85 if weapon == Weapon.BLUE else 1.0
		_fire_cooldown = fire_rate * mult

	if Input.is_action_just_pressed("bomb") and bombs > 0:
		_use_bomb()

func _shoot() -> void:
	match style:
		"twin_spread": _fire_twin_spread()
		"heavy_cannon": _fire_heavy_cannon()
		"rapid_stream": _fire_rapid_stream()
		_: _fire_twin_spread()

# --- Sunborn: balanced twin cannons, widen with power ---
func _fire_twin_spread() -> void:
	var angles: Array = []
	match power_level:
		1: angles = [-6, 6]
		2: angles = [-10, 0, 10]
		3: angles = [-16, -5, 5, 16]
	for a in angles:
		_spawn_bullet(Vector2.UP.rotated(deg_to_rad(a)) * 640.0, base_damage)

# --- Scarab: fewer, bigger, high-damage rounds ---
func _fire_heavy_cannon() -> void:
	var offsets: Array = []
	match power_level:
		1: offsets = [0]
		2: offsets = [-14, 14]
		3: offsets = [-18, 0, 18]
	for o in offsets:
		var b := _spawn_bullet(Vector2.UP * 560.0, base_damage + 1)
		if b: b.scale = Vector2(1.6, 1.6)

# --- Ibis: rapid thin stream, adds columns with power ---
func _fire_rapid_stream() -> void:
	var offsets: Array = []
	match power_level:
		1: offsets = [0]
		2: offsets = [-8, 8]
		3: offsets = [-12, 0, 12]
	for o in offsets:
		var b := _spawn_bullet(Vector2.UP * 780.0, base_damage)
		if b: b.scale = Vector2(0.7, 1.2)

func _spawn_bullet(vel: Vector2, dmg: int):
	var b := bullet_scene.instantiate()
	b.position = position + Vector2(0, -30)
	var col := "blue" if weapon == Weapon.BLUE else "red"
	b.setup(vel, col)
	b.damage = dmg + (1 if weapon == Weapon.BLUE else 0)
	get_parent().add_child(b)
	return b

func _use_bomb() -> void:
	bombs -= 1
	bomb_used.emit(bombs)
	get_tree().call_group("enemy_bullets", "queue_free")
	for e in get_tree().get_nodes_in_group("enemies"):
		if e.has_method("take_damage"):
			e.take_damage(8)
	for b in get_tree().get_nodes_in_group("boss"):
		if b.has_method("take_damage"):
			b.take_damage(10)

func collect_powerup(kind: String) -> void:
	var before := power_level
	match kind:
		"red":
			if weapon == Weapon.RED: power_level = min(power_level + 1, 3)
			else: weapon = Weapon.RED
			weapon_changed.emit(weapon, power_level)
		"blue":
			if weapon == Weapon.BLUE: power_level = min(power_level + 1, 3)
			else: weapon = Weapon.BLUE
			weapon_changed.emit(weapon, power_level)
		"power":
			power_level = min(power_level + 1, 3)
			weapon_changed.emit(weapon, power_level)
		"life":
			_health = min(_health + 1, max_health + 2)  # can overheal +2
	if power_level != before:
		_evolve_form()

func add_life(n: int = 1) -> void:
	_health += n

func _evolve_form() -> void:
	_apply_form()
	form_changed.emit(form_names[power_level - 1] if power_level - 1 < form_names.size() else "")
	# burst: flash accent color + scale pop
	var s := form_scale[power_level - 1] if power_level - 1 < form_scale.size() else 1.0
	$Sprite2D.modulate = accent * 1.5
	var t := create_tween()
	t.tween_property($Sprite2D, "scale", Vector2(s, s) * 1.3, 0.12)
	t.parallel().tween_property($Sprite2D, "modulate", tint, 0.25)
	t.tween_property($Sprite2D, "scale", Vector2(s, s), 0.12)

func _apply_form() -> void:
	var idx := clamp(power_level - 1, 0, form_scale.size() - 1)
	$Sprite2D.scale = Vector2(form_scale[idx], form_scale[idx])
	# tint deepens slightly with form
	$Sprite2D.modulate = tint.lerp(accent, (power_level - 1) * 0.18)

func _on_area_entered(area: Area2D) -> void:
	if area.is_in_group("powerups"):
		return
	if _invincible:
		return
	if area.is_in_group("enemy_bullets") or area.is_in_group("enemies"):
		if area.is_in_group("enemy_bullets"):
			area.queue_free()
		take_damage(1)

func take_damage(amount: int) -> void:
	if _invincible:
		return
	_health -= amount
	# losing health knocks power down a notch (form de-evolves)
	if power_level > 1:
		power_level -= 1
		_apply_form()
		weapon_changed.emit(weapon, power_level)
	if _health <= 0:
		died.emit()
		queue_free()
	else:
		_flash_invincible()

func _flash_invincible() -> void:
	_invincible = true
	var t := create_tween()
	t.set_loops(8)
	t.tween_property(self, "modulate:a", 0.2, 0.07)
	t.tween_property(self, "modulate:a", 1.0, 0.07)
	await t.finished
	_invincible = false

func get_health() -> int:
	return _health

func get_weapon_name() -> String:
	return "RED" if weapon == Weapon.RED else "BLUE"

func get_form_name() -> String:
	var idx := clamp(power_level - 1, 0, form_names.size() - 1)
	return form_names[idx]
