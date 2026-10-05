---
name: godot-engine
description: >
  Godot 4 engine expert with the complete, offline Godot class reference (1,112 classes,
  built from the godotengine/godot repo). Use whenever the user writes, fixes, ports, or
  explains GDScript, .tscn/.tres scenes, project.godot settings, nodes, signals, physics,
  tweens, input, audio, UI/Control, shaders, or exports in Godot — including the SUNDER
  Godot project in `godot/` — or asks "what's the Godot API for X", or is porting Godot 3
  code to Godot 4.
---

# Godot Engine (4.x)

Reference built from `godotengine/godot` @ `e7cfa29` (4.8-dev, 2026-10-02). It covers the
engine's own class docs, `doc/classes/` plus module and platform `doc_classes/`, condensed to
signatures and one-line descriptions.

## Look up the API before writing code

Never guess a method name, signature, signal, or default value. Godot 3 names often still
show up in training data, and they won't work in Godot 4. Check the reference first:

```bash
S=skills/godot-engine/scripts
python3 $S/godot_api.py Area2D                    # full API of one class
python3 $S/godot_api.py CharacterBody2D velocity  # term search across a class + its ancestors
python3 $S/godot_api.py -s move_toward            # search every class for a member name
python3 $S/godot_api.py -c Control                # direct subclasses
```

- `references/class-index.md` has one line per class (name, parent, brief). Grep it to find
  the right node type.
- `references/classes/<Class>.md` lists properties with defaults, methods with
  signatures, signals, enums, constants, and theme items.
- `@GlobalScope.md` covers global functions (`lerp`, `clamp`, `randf_range`, `print`, …).
  `@GDScript.md` covers GDScript built-ins and annotations (`@export`, `@onready`, `preload`, …).
- The reference is the 4.x dev branch. If a project pins an older 4.x (see
  `config/features` in `project.godot`; SUNDER pins `"4.3"`), avoid anything the
  reference marks *(deprecated)*. Be careful with anything that looks new, too.

## GDScript 4 essentials

```gdscript
extends Area2D
class_name Bullet                       # optional global type name

signal hit(target: Node, damage: int)

@export var speed: float = 600.0        # inspector-editable
@export_range(1, 10) var damage := 1
@onready var sprite: Sprite2D = $Sprite2D

func _ready() -> void:
	area_entered.connect(_on_area_entered)          # signals are first-class
	hit.connect(func(t, d): print(t, d))            # lambdas OK

func _physics_process(delta: float) -> void:
	position += Vector2.UP * speed * delta
	if position.y < -32:
		queue_free()

func _on_area_entered(area: Area2D) -> void:
	hit.emit(area, damage)
	var t := create_tween()                          # tweens are created, not nodes
	t.tween_property(sprite, "modulate:a", 0.0, 0.2)
	await t.finished                                 # await replaces yield
	queue_free()
```

Spawning: `var e := preload("res://scenes/Enemy.tscn").instantiate()` then
`get_parent().add_child(e)`. If you're inside a physics callback, use
`add_child.call_deferred(e)`. Timers: `await get_tree().create_timer(0.5).timeout`.

## Godot 3 → 4 renames (the usual porting bugs)

| Godot 3 | Godot 4 |
|---|---|
| `KinematicBody2D` + `move_and_slide(vel)` | `CharacterBody2D`, set `velocity`, call `move_and_slide()` |
| `yield(obj, "sig")` | `await obj.sig` |
| `connect("sig", self, "_m")` | `sig.connect(_m)` |
| `emit_signal("sig", a)` | `sig.emit(a)` (old form still works) |
| `export var` / `onready var` | `@export var` / `@onready var` |
| `.instance()` | `.instantiate()` |
| `Tween` node + `interpolate_property` | `create_tween().tween_property(...)` |
| `rand_range`, `stepify` | `randf_range`, `snapped` |
| `Spatial`, `Position2D`, `Sprite` | `Node3D`, `Marker2D`, `Sprite2D` |
| `rect_position` / `rect_size` | `position` / `size` |
| `OS.window_size` | `get_window().size` / `DisplayServer.window_get_size()` |
| `get_tree().change_scene("…")` | `get_tree().change_scene_to_file("…")` |
| `tool` / `setget` | `@tool` / `var x: set = _set_x, get = _get_x` |
| `PoolStringArray` | `PackedStringArray` |
| `TileMap` (4.0–4.2) | `TileMapLayer` nodes (TileMap deprecated in 4.3+) |

## Working method

1. Read `project.godot` first. It has autoloads (singletons), input actions, physics
   layer names, stretch mode, and renderer (`gl_compatibility` is required for web export).
2. Use only input action names that exist under `[input]`, and use
   `Input.is_action_pressed("fire")` rather than raw keycodes.
3. Collision is `collision_layer` (what I am) and `collision_mask` (what I detect). In
   `.tscn` files these are bitmasks: layer 3 → `4`.
4. When editing `.tscn` by hand, keep `[ext_resource]` ids and `load_steps` consistent,
   and give each node a unique `name` under its parent. If a structural change is
   complex, prefer doing it in code (`_ready`).
5. Type everything (`var x: int`, `-> void`). Typed GDScript catches API mistakes at
   parse time.
6. To validate with no editor available, run headless if a `godot` binary exists:
   `godot --headless --path godot --quit` (parse/load errors) or
   `godot --headless --path godot --script res://test.gd`.
   If no binary is present, say so and fall back to checking the API against the
   reference.
7. Web export needs the Compatibility renderer and export templates. Threads and
   `SharedArrayBuffer` need COOP/COEP headers unless you export with threads off.

## This repo

`godot/` is the original Godot 4 SUNDER project: autoloads `StageData`, `StoryData`,
`ShipData`, `GameState`, `AudioManager`; scenes in `godot/scenes/`; 480×720
`canvas_items` stretch. The shipped game is the HTML5 port in `web/game.html`. Balance
rules (battle math) live in the `sunder-ascension-dev` skill, so keep both versions in
agreement when changing gameplay numbers.

## Refreshing the reference

```bash
git clone --depth 1 --filter=blob:none --sparse https://github.com/godotengine/godot.git /tmp/godot
cd /tmp/godot && git sparse-checkout set --no-cone '/doc/classes/' '/modules/*/doc_classes/' \
  '/platform/*/doc_classes/' '/LICENSE.txt' '/version.py'
python3 skills/godot-engine/scripts/build_reference.py /tmp/godot
```

To pin a stable release, add `--branch 4.3-stable` (or the version you need) to the clone.
Class reference content is © Godot Engine contributors, MIT (see `GODOT-LICENSE.txt`).
