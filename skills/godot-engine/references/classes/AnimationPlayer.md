# AnimationPlayer

**Inherits:** AnimationMixer

A node used for animation playback.

An animation player is used for general-purpose playback of animations. It contains a dictionary of AnimationLibrary resources and custom blend times between animation transitions. Some methods and properties use a single key to reference an animation directly. These keys are formatted as the key for the library, followed by a forward slash, then the key for the animation within the library, for example `"movement/run"`.

## Properties

- `assigned_animation: StringName` — If playing, the current animation's key, otherwise, the animation last played.
- `autoplay: StringName` = `&""` — The key of the animation to play when the scene loads.
- `clear_cache_on_stop: bool` = `true` — If `true`, the animation track cache is cleared when the animation is stopped or the playback queue becomes empty.
- `current_animation: StringName` = `&""` — The key of the currently playing animation.
- `current_animation_length: float` — The length (in seconds) of the currently playing animation.
- `current_animation_position: float` — The position (in seconds) of the currently playing animation.
- `movie_quit_on_finish: bool` = `false` — If `true` and the engine is running in Movie Maker mode (see MovieWriter), exits the engine with `SceneTree.quit` as soon as an animation is done playing in this AnimationPlayer.
- `playback_auto_capture: bool` = `true` — If `true`, performs `AnimationMixer.capture` before playback automatically.
- `playback_auto_capture_duration: float` = `-1.0` — See also `play_with_capture` and `AnimationMixer.capture`.
- `playback_auto_capture_ease_type: Tween.EaseType` = `0` — The ease type of the capture interpolation.
- `playback_auto_capture_transition_type: Tween.TransitionType` = `0` — The transition type of the capture interpolation.
- `playback_default_blend_time: float` = `0.0` — The default time in which to blend animations.
- `speed_scale: float` = `1.0` — The speed scaling ratio.

## Methods

- `animation_get_next(animation_from: StringName) -> StringName` *const* — Returns the key of the animation which is queued to play after the `animation_from` animation.
- `animation_set_next(animation_from: StringName, animation_to: StringName) -> void` — Triggers the `animation_to` animation when the `animation_from` animation completes.
- `clear_queue() -> void` — Clears all queued, unplayed animations.
- `get_blend_time(animation_from: StringName, animation_to: StringName) -> float` *const* — Returns the blend time (in seconds) between two animations, referenced by their keys.
- `get_method_call_mode() -> int[AnimationPlayer.AnimationMethodCallMode]` *const* *(deprecated)* — Returns the call mode used for "Call Method" tracks.
- `get_playing_speed() -> float` *const* — Returns the actual playing speed of current animation or `0` if not playing.
- `get_process_callback() -> int[AnimationPlayer.AnimationProcessCallback]` *const* *(deprecated)* — Returns the process notification in which to update animations.
- `get_queue() -> StringName[]` — Returns a list of the animation keys that are currently queued to play.
- `get_root() -> NodePath` *const* *(deprecated)* — Returns the node which node path references will travel from.
- `get_section_end_time() -> float` *const* — Returns the end time of the section currently being played.
- `get_section_start_time() -> float` *const* — Returns the start time of the section currently being played.
- `has_section() -> bool` *const* — Returns `true` if an animation is currently playing with a section.
- `is_animation_active() -> bool` *const* — Returns `true` if the an animation is currently active.
- `is_playing() -> bool` *const* — Returns `true` if an animation is currently playing (even if `speed_scale` and/or `custom_speed` are `0`).
- `pause() -> void` — Pauses the currently playing animation.
- `play(name: StringName = &"", custom_blend: float = -1, custom_speed: float = 1.0, from_end: bool = false) -> void` — Plays the animation with key `name`.
- `play_backwards(name: StringName = &"", custom_blend: float = -1) -> void` — Plays the animation with key `name` in reverse.
- `play_section(name: StringName = &"", start_time: float = -1, end_time: float = -1, custom_blend: float = -1, custom_speed: float = 1.0, from_end: bool = false) -> void` — Plays the animation with key `name` and the section starting from `start_time` and ending on `end_time`.
- `play_section_backwards(name: StringName = &"", start_time: float = -1, end_time: float = -1, custom_blend: float = -1) -> void` — Plays the animation with key `name` and the section starting from `start_time` and ending on `end_time` in reverse.
- `play_section_with_markers(name: StringName = &"", start_marker: StringName = &"", end_marker: StringName = &"", custom_blend: float = -1, custom_speed: float = 1.0, from_end: bool = false) -> void` — Plays the animation with key `name` and the section starting from `start_marker` and ending on `end_marker`.
- `play_section_with_markers_backwards(name: StringName = &"", start_marker: StringName = &"", end_marker: StringName = &"", custom_blend: float = -1) -> void` — Plays the animation with key `name` and the section starting from `start_marker` and ending on `end_marker` in reverse.
- `play_with_capture(name: StringName = &"", duration: float = -1.0, custom_blend: float = -1, custom_speed: float = 1.0, from_end: bool = false, trans_type: Tween.TransitionType = 0, ease_type: Tween.EaseType = 0) -> void` — See also `AnimationMixer.capture`.
- `queue(name: StringName) -> void` — Queues an animation for playback once the current animation and all previously queued animations are done.
- `reset_section() -> void` — Resets the current section.
- `seek(seconds: float, update: bool = false, update_only: bool = false) -> void` — Seeks the animation to the `seconds` point in time (in seconds).
- `set_blend_time(animation_from: StringName, animation_to: StringName, sec: float) -> void` — Specifies a blend time (in seconds) between two animations, referenced by their keys.
- `set_method_call_mode(mode: AnimationPlayer.AnimationMethodCallMode) -> void` *(deprecated)* — Sets the call mode used for "Call Method" tracks.
- `set_process_callback(mode: AnimationPlayer.AnimationProcessCallback) -> void` *(deprecated)* — Sets the process notification in which to update animations.
- `set_root(path: NodePath) -> void` *(deprecated)* — Sets the node which node path references will travel from.
- `set_section(start_time: float = -1, end_time: float = -1) -> void` — Changes the start and end times of the section being played.
- `set_section_with_markers(start_marker: StringName = &"", end_marker: StringName = &"") -> void` — Changes the start and end markers of the section being played.
- `stop(keep_state: bool = false) -> void` — Stops the currently playing animation.

## Signals

- `animation_changed(old_name: StringName, new_name: StringName)` — Emitted when a queued animation plays after the previous animation finished.
- `current_animation_changed(anim_name: StringName)` — Emitted when `current_animation` changes.

## Enum AnimationProcessCallback

- `ANIMATION_PROCESS_PHYSICS = 0` — 
- `ANIMATION_PROCESS_IDLE = 1` — 
- `ANIMATION_PROCESS_MANUAL = 2` — 

## Enum AnimationMethodCallMode

- `ANIMATION_METHOD_CALL_DEFERRED = 0` — 
- `ANIMATION_METHOD_CALL_IMMEDIATE = 1` —
