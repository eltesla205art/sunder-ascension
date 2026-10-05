# AnimationNodeStateMachinePlayback

**Inherits:** Resource

Provides playback control for an AnimationNodeStateMachine.

Allows control of AnimationTree state machines created with AnimationNodeStateMachine. Retrieve with `$AnimationTree.get("parameters/playback")`.

## Properties

- `resource_local_to_scene: bool` = `true` — 

## Methods

- `get_current_length() -> float` *const* — Returns the current state length.
- `get_current_node() -> StringName` *const* — Returns the currently playing animation state.
- `get_current_play_position() -> float` *const* — Returns the playback position within the current animation state.
- `get_fading_from_length() -> float` *const* — Returns the playback state length of the node from `get_fading_from_node`.
- `get_fading_from_node() -> StringName` *const* — Returns the starting state of currently fading animation.
- `get_fading_from_play_position() -> float` *const* — Returns the playback position of the node from `get_fading_from_node`.
- `get_fading_length() -> float` *const* — Returns the length of the current fade animation.
- `get_fading_position() -> float` *const* — Returns the playback position of the current fade animation.
- `get_travel_path() -> StringName[]` *const* — Returns the current travel path as computed internally by the A* algorithm.
- `is_playing() -> bool` *const* — Returns `true` if an animation is playing.
- `next() -> void` — If there is a next path by travel or auto advance, immediately transitions from the current state to the next state.
- `start(node: StringName, reset: bool = true) -> void` — Starts playing the given animation.
- `stop() -> void` — Stops the currently playing animation.
- `travel(to_node: StringName, reset_on_teleport: bool = true) -> void` — Transitions from the current state to another one, following the shortest path.

## Signals

- `state_finished(state: StringName)` — Emitted when the `state` finishes playback.
- `state_started(state: StringName)` — Emitted when the `state` starts playback.
