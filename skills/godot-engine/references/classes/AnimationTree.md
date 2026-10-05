# AnimationTree

**Inherits:** AnimationMixer

A node used for advanced animation transitions in an AnimationPlayer.

A node used for advanced animation transitions in an AnimationPlayer. Note: When linked with an AnimationPlayer, several properties and methods of the corresponding AnimationPlayer will not function as expected. Playback and transitions should be handled using only the AnimationTree and its constituent AnimationNode(s). The AnimationPlayer node should be used solely for adding, deleting, and editing animations.

## Properties

- `advance_expression_base_node: NodePath` = `NodePath(".")` — The path to the Node used to evaluate the AnimationNode Expression if one is not explicitly specified internally.
- `anim_player: NodePath` = `NodePath("")` — The path to the AnimationPlayer used for animating.
- `callback_mode_discrete: AnimationMixer.AnimationCallbackModeDiscrete` = `2` — 
- `deterministic: bool` = `true` — 
- `tree_root: AnimationRootNode` — The root animation node of this AnimationTree.

## Methods

- `get_process_callback() -> int[AnimationTree.AnimationProcessCallback]` *const* *(deprecated)* — Returns the process notification in which to update animations.
- `set_process_callback(mode: AnimationTree.AnimationProcessCallback) -> void` *(deprecated)* — Sets the process notification in which to update animations.

## Signals

- `animation_player_changed()` — Emitted when the `anim_player` is changed.

## Enum AnimationProcessCallback

- `ANIMATION_PROCESS_PHYSICS = 0` — 
- `ANIMATION_PROCESS_IDLE = 1` — 
- `ANIMATION_PROCESS_MANUAL = 2` —
