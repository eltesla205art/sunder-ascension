extends Node2D
## Campaign controller — runs the Nine Bows across 9 escalating stages,
## with the full storyline woven through: opening crawl, stage briefings,
## boss taunts, stage-clear lines, and the ending.

enum State { OPENING, BRIEFING, PLAYING, BOSS_INTRO, STAGE_CLEAR, VICTORY, DEFEAT }

var _state: int = State.OPENING
var _stage_index: int = 0
var _stage_score: int = 0
var _total_score: int = 0
var _spawn_timer: float = 0.0
var _boss_active: bool = false
var _cfg: Dictionary = {}

var enemy_scene: PackedScene = preload("res://scenes/Enemy.tscn")
var powerup_scene: PackedScene = preload("res://scenes/PowerUp.tscn")
var boss_scene: PackedScene = preload("res://scenes/Boss.tscn")

@onready var score_label: Label = $HUD/ScoreLabel
@onready var health_label: Label = $HUD/HealthLabel
@onready var bomb_label: Label = $HUD/BombLabel
@onready var weapon_label: Label = $HUD/WeaponLabel
@onready var stage_label: Label = $HUD/StageLabel
@onready var banner_label: Label = $HUD/GameOverLabel
@onready var boss_bar: ProgressBar = $HUD/BossBar
@onready var boss_name_label: Label = $HUD/BossName
@onready var player: Area2D = $Player

func _ready() -> void:
	randomize()
	player.setup_ship(ShipData.get_ship(GameState.selected_ship))
	player.died.connect(_on_player_died)
	player.bomb_used.connect(func(_r): _update_hud())
	player.weapon_changed.connect(func(_m, _l): _update_hud())
	player.form_changed.connect(_on_form_changed)
	AudioManager.play("main")
	boss_bar.visible = false
	boss_name_label.visible = false
	_show_opening()

# ---------------------------------------------------------------- OPENING
func _show_opening() -> void:
	_state = State.OPENING
	player.visible = false
	banner_label.text = "\n".join(StoryData.OPENING) + "\n\n[ Press SPACE ]"
	banner_label.visible = true

# ---------------------------------------------------------------- STAGE FLOW
func _begin_stage(idx: int) -> void:
	_stage_index = idx
	_cfg = StageData.get_stage(idx)
	_stage_score = 0
	_boss_active = false
	player.visible = true
	_show_briefing()

func _show_briefing() -> void:
	_state = State.BRIEFING
	var b: Dictionary = StoryData.BRIEFINGS.get(_cfg.num, {})
	banner_label.text = "STAGE %d / 9\n%s\n\n%s\n\n%s\n\n[ Press SPACE to engage ]" % [
		_cfg.num, _cfg.name.to_upper(),
		b.get("quote", ""), b.get("brief", "")
	]
	banner_label.visible = true
	_update_hud()

func _start_playing() -> void:
	_state = State.PLAYING
	banner_label.visible = false
	_spawn_timer = 0.6

# ---------------------------------------------------------------- INPUT
func _process(delta: float) -> void:
	match _state:
		State.OPENING:
			if Input.is_action_just_pressed("fire"):
				_begin_stage(0)
		State.BRIEFING:
			if Input.is_action_just_pressed("fire"):
				_start_playing()
		State.STAGE_CLEAR:
			if Input.is_action_just_pressed("fire"):
				_begin_stage(_stage_index + 1)
		State.VICTORY, State.DEFEAT:
			if Input.is_action_just_pressed("fire"):
				get_tree().reload_current_scene()
		State.PLAYING:
			_process_playing(delta)
		State.BOSS_INTRO:
			pass  # timed, auto-advances

	_update_hud()

func _process_playing(delta: float) -> void:
	if _boss_active:
		return
	if _stage_score >= _cfg.score_to_boss:
		_spawn_boss()
	else:
		_spawn_timer -= delta
		if _spawn_timer <= 0.0:
			_spawn_enemy()
			_spawn_timer = _cfg.spawn_interval

# ---------------------------------------------------------------- SPAWNING
func _spawn_enemy() -> void:
	var e := enemy_scene.instantiate()
	var vp := get_viewport_rect().size
	e.position = Vector2(randf_range(45, vp.x - 45), -45)
	e.configure(_cfg)
	e.destroyed.connect(func(pts):
		_stage_score += pts
		_total_score += pts)
	e.drop_powerup.connect(_spawn_powerup)
	add_child(e)

func _spawn_powerup(pos: Vector2, kind: String) -> void:
	var p := powerup_scene.instantiate()
	p.position = pos
	p.kind = kind
	add_child(p)

func _spawn_boss() -> void:
	_boss_active = true
	_state = State.BOSS_INTRO
	for e in get_tree().get_nodes_in_group("enemies"):
		e.queue_free()
	# Boss taunt card
	AudioManager.play("boss")
	var line: String = StoryData.BOSS_LINES.get(_cfg.num, "")
	banner_label.text = "%s\n\n%s" % [_cfg.boss_name, line]
	banner_label.visible = true
	await get_tree().create_timer(2.4).timeout
	if _state != State.BOSS_INTRO:
		return  # player died during intro
	banner_label.visible = false

	var boss := boss_scene.instantiate()
	boss.position = Vector2(get_viewport_rect().size.x / 2, -90)
	boss.configure(_cfg)
	boss.defeated.connect(_on_boss_defeated)
	boss.health_changed.connect(_on_boss_health)
	add_child(boss)
	boss_bar.visible = true
	boss_name_label.visible = true
	boss_name_label.text = _cfg.boss_name
	_state = State.PLAYING

# ---------------------------------------------------------------- BOSS EVENTS
func _on_boss_health(cur: int, mx: int) -> void:
	boss_bar.max_value = mx
	boss_bar.value = cur

func _on_boss_defeated(pts: int) -> void:
	_total_score += pts
	AudioManager.play("main")
	_boss_active = false
	boss_bar.visible = false
	boss_name_label.visible = false
	get_tree().call_group("enemy_bullets", "queue_free")

	if _stage_index + 1 >= StageData.stage_count():
		_win_game()
	else:
		_state = State.STAGE_CLEAR
		if is_instance_valid(player):
			player.add_life(1)   # reward: +1 life each stage cleared
		var clear: String = StoryData.CLEAR_LINES.get(_cfg.num, "")
		banner_label.text = "STAGE %d CLEARED\n%s FALL\n\n%s\n\n+1 LIFE RESTORED\n\nSCORE: %d\n\n[ Press SPACE ]" % [
			_cfg.num, _cfg.name.to_upper(), clear, _total_score
		]
		banner_label.visible = true

# ---------------------------------------------------------------- ENDINGS
func _win_game() -> void:
	_state = State.VICTORY
	AudioManager.play("victory")
	banner_label.text = "\n".join(StoryData.VICTORY) + "\n\nFINAL SCORE: %d\n\n[ Press SPACE to play again ]" % _total_score
	banner_label.visible = true

func _on_player_died() -> void:
	if _state == State.VICTORY:
		return
	_state = State.DEFEAT
	boss_bar.visible = false
	boss_name_label.visible = false
	banner_label.text = "ASCENSION DENIED\n\nStage %d — %s\n\n%s\n\nSCORE: %d\n\n[ Press SPACE to rise again ]" % [
		_cfg.get("num", 1), _cfg.get("name", ""), StoryData.DEFEAT_TAG, _total_score
	]
	banner_label.visible = true

# ---------------------------------------------------------------- FORM
func _on_form_changed(form_name: String) -> void:
	if form_name == "":
		return
	stage_label.text = "FORM: %s" % form_name.to_upper()

# ---------------------------------------------------------------- HUD
func _update_hud() -> void:
	score_label.text = "SCORE  %07d" % _total_score
	stage_label.text = "STAGE %d/9  %s" % [_cfg.get("num", 1), _cfg.get("name", "")]
	if is_instance_valid(player):
		health_label.text = "ANKH  " + "\u2665".repeat(max(player.get_health(), 0))
		bomb_label.text = "BOMB  %d" % player.bombs
		weapon_label.text = "%s Lv%d" % [player.get_weapon_name(), player.power_level]
