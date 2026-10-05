# Animation

**Inherits:** Resource

Holds data that can be used to animate anything in the engine.

This resource holds data that can be used to animate anything in the engine. Animations are divided into tracks and each track must be linked to a node. The state of that node can be changed through time, by adding timed keys (events) to the track. Animations are just data containers, and must be added to nodes such as an AnimationPlayer to be played back.

## Properties

- `capture_included: bool` = `false` — Returns `true` if the capture track is included.
- `length: float` = `1.0` — The total length of the animation (in seconds).
- `loop_mode: Animation.LoopMode` = `0` — Determines the behavior of both ends of the animation timeline during animation playback.
- `step: float` = `0.033333335` — The animation step value.

## Methods

- `add_marker(name: StringName, time: float) -> void` — Adds a marker to this Animation.
- `add_track(type: Animation.TrackType, at_position: int = -1) -> int` — Adds a track to the Animation.
- `animation_track_get_key_animation(track_idx: int, key_idx: int) -> StringName` *const* — Returns the animation name at the key identified by `key_idx`.
- `animation_track_insert_key(track_idx: int, time: float, animation: StringName) -> int` — Inserts a key with value `animation` at the given `time` (in seconds).
- `animation_track_set_key_animation(track_idx: int, key_idx: int, animation: StringName) -> void` — Sets the key identified by `key_idx` to value `animation`.
- `audio_track_get_key_end_offset(track_idx: int, key_idx: int) -> float` *const* — Returns the end offset of the key identified by `key_idx`.
- `audio_track_get_key_start_offset(track_idx: int, key_idx: int) -> float` *const* — Returns the start offset of the key identified by `key_idx`.
- `audio_track_get_key_stream(track_idx: int, key_idx: int) -> Resource` *const* — Returns the audio stream of the key identified by `key_idx`.
- `audio_track_insert_key(track_idx: int, time: float, stream: Resource, start_offset: float = 0, end_offset: float = 0) -> int` — Inserts an Audio Track key at the given `time` in seconds.
- `audio_track_is_use_blend(track_idx: int) -> bool` *const* — Returns `true` if the track at `track_idx` will be blended with other animations.
- `audio_track_set_key_end_offset(track_idx: int, key_idx: int, offset: float) -> void` — Sets the end offset of the key identified by `key_idx` to value `offset`.
- `audio_track_set_key_start_offset(track_idx: int, key_idx: int, offset: float) -> void` — Sets the start offset of the key identified by `key_idx` to value `offset`.
- `audio_track_set_key_stream(track_idx: int, key_idx: int, stream: Resource) -> void` — Sets the stream of the key identified by `key_idx` to value `stream`.
- `audio_track_set_use_blend(track_idx: int, enable: bool) -> void` — Sets whether the track will be blended with other animations.
- `bezier_track_get_key_in_handle(track_idx: int, key_idx: int) -> Vector2` *const* — Returns the in handle of the key identified by `key_idx`.
- `bezier_track_get_key_out_handle(track_idx: int, key_idx: int) -> Vector2` *const* — Returns the out handle of the key identified by `key_idx`.
- `bezier_track_get_key_value(track_idx: int, key_idx: int) -> float` *const* — Returns the value of the key identified by `key_idx`.
- `bezier_track_insert_key(track_idx: int, time: float, value: float, in_handle: Vector2 = Vector2(0, 0), out_handle: Vector2 = Vector2(0, 0)) -> int` — Inserts a Bezier Track key at the given `time` in seconds.
- `bezier_track_interpolate(track_idx: int, time: float) -> float` *const* — Returns the interpolated value at the given `time` (in seconds).
- `bezier_track_set_key_in_handle(track_idx: int, key_idx: int, in_handle: Vector2, balanced_value_time_ratio: float = 1.0) -> void` — Sets the in handle of the key identified by `key_idx` to value `in_handle`.
- `bezier_track_set_key_out_handle(track_idx: int, key_idx: int, out_handle: Vector2, balanced_value_time_ratio: float = 1.0) -> void` — Sets the out handle of the key identified by `key_idx` to value `out_handle`.
- `bezier_track_set_key_value(track_idx: int, key_idx: int, value: float) -> void` — Sets the value of the key identified by `key_idx` to the given value.
- `blend_shape_track_insert_key(track_idx: int, time: float, amount: float) -> int` — Inserts a key in a given blend shape track.
- `blend_shape_track_interpolate(track_idx: int, time_sec: float, backward: bool = false) -> float` *const* — Returns the interpolated blend shape value at the given time (in seconds).
- `clear() -> void` — Clear the animation (clear all tracks and reset all).
- `compress(page_size: int = 8192, fps: int = 120, split_tolerance: float = 4.0) -> void` — Compress the animation and all its tracks in-place.
- `copy_track(track_idx: int, to_animation: Animation) -> void` — Adds a new track to `to_animation` that is a copy of the given track from this animation.
- `find_track(path: NodePath, type: Animation.TrackType) -> int` *const* — Returns the index of the specified track.
- `get_marker_at_time(time: float) -> StringName` *const* — Returns the name of the marker located at the given time.
- `get_marker_color(name: StringName) -> Color` *const* — Returns the given marker's color.
- `get_marker_names() -> PackedStringArray` *const* — Returns every marker in this Animation, sorted ascending by time.
- `get_marker_time(name: StringName) -> float` *const* — Returns the given marker's time.
- `get_next_marker(time: float) -> StringName` *const* — Returns the closest marker that comes after the given time.
- `get_prev_marker(time: float) -> StringName` *const* — Returns the closest marker that comes before the given time.
- `get_track_count() -> int` *const* — Returns the amount of tracks in the animation.
- `has_marker(name: StringName) -> bool` *const* — Returns `true` if this Animation contains a marker with the given name.
- `method_track_get_name(track_idx: int, key_idx: int) -> StringName` *const* — Returns the method name of a method track.
- `method_track_get_params(track_idx: int, key_idx: int) -> Array` *const* — Returns the arguments values to be called on a method track for a given key in a given track.
- `optimize(allowed_velocity_err: float = 0.01, allowed_angular_err: float = 0.01, precision: int = 3) -> void` — Optimize the animation and all its tracks in-place.
- `position_track_insert_key(track_idx: int, time: float, position: Vector3) -> int` — Inserts a key in a given 3D position track.
- `position_track_interpolate(track_idx: int, time_sec: float, backward: bool = false) -> Vector3` *const* — Returns the interpolated position value at the given time (in seconds).
- `remove_marker(name: StringName) -> void` — Removes the marker with the given name from this Animation.
- `remove_track(track_idx: int) -> void` — Removes a track by specifying the track index.
- `rotation_track_insert_key(track_idx: int, time: float, rotation: Quaternion) -> int` — Inserts a key in a given 3D rotation track.
- `rotation_track_interpolate(track_idx: int, time_sec: float, backward: bool = false) -> Quaternion` *const* — Returns the interpolated rotation value at the given time (in seconds).
- `scale_track_insert_key(track_idx: int, time: float, scale: Vector3) -> int` — Inserts a key in a given 3D scale track.
- `scale_track_interpolate(track_idx: int, time_sec: float, backward: bool = false) -> Vector3` *const* — Returns the interpolated scale value at the given time (in seconds).
- `set_marker_color(name: StringName, color: Color) -> void` — Sets the given marker's color.
- `track_find_key(track_idx: int, time: float, find_mode: Animation.FindMode = 0, limit: bool = false, backward: bool = false) -> int` *const* — Finds the key index by time in a given track.
- `track_get_interpolation_loop_wrap(track_idx: int) -> bool` *const* — Returns `true` if the track at `track_idx` wraps the interpolation loop.
- `track_get_interpolation_type(track_idx: int) -> int[Animation.InterpolationType]` *const* — Returns the interpolation type of a given track.
- `track_get_key_count(track_idx: int) -> int` *const* — Returns the number of keys in a given track.
- `track_get_key_time(track_idx: int, key_idx: int) -> float` *const* — Returns the time at which the key is located.
- `track_get_key_transition(track_idx: int, key_idx: int) -> float` *const* — Returns the transition curve (easing) for a specific key (see the built-in math function `@GlobalScope.ease`).
- `track_get_key_value(track_idx: int, key_idx: int) -> Variant` *const* — Returns the value of a given key in a given track.
- `track_get_path(track_idx: int) -> NodePath` *const* — Gets the path of a track.
- `track_get_type(track_idx: int) -> int[Animation.TrackType]` *const* — Gets the type of a track.
- `track_insert_key(track_idx: int, time: float, key: Variant, transition: float = 1) -> int` — Inserts a generic key in a given track.
- `track_is_compressed(track_idx: int) -> bool` *const* — Returns `true` if the track is compressed, `false` otherwise.
- `track_is_enabled(track_idx: int) -> bool` *const* — Returns `true` if the track at index `track_idx` is enabled.
- `track_is_imported(track_idx: int) -> bool` *const* — Returns `true` if the given track is imported.
- `track_move_down(track_idx: int) -> void` — Moves a track down.
- `track_move_to(track_idx: int, to_idx: int) -> void` — Changes the index position of track `track_idx` to the one defined in `to_idx`.
- `track_move_up(track_idx: int) -> void` — Moves a track up.
- `track_remove_key(track_idx: int, key_idx: int) -> void` — Removes a key by index in a given track.
- `track_remove_key_at_time(track_idx: int, time: float) -> void` — Removes a key at `time` in a given track.
- `track_set_enabled(track_idx: int, enabled: bool) -> void` — Enables/disables the given track.
- `track_set_imported(track_idx: int, imported: bool) -> void` — Sets the given track as imported or not.
- `track_set_interpolation_loop_wrap(track_idx: int, interpolation: bool) -> void` — If `true`, the track at `track_idx` wraps the interpolation loop.
- `track_set_interpolation_type(track_idx: int, interpolation: Animation.InterpolationType) -> void` — Sets the interpolation type of a given track.
- `track_set_key_time(track_idx: int, key_idx: int, time: float) -> void` — Sets the time of an existing key.
- `track_set_key_transition(track_idx: int, key_idx: int, transition: float) -> void` — Sets the transition curve (easing) for a specific key (see the built-in math function `@GlobalScope.ease`).
- `track_set_key_value(track_idx: int, key: int, value: Variant) -> void` — Sets the value of an existing key.
- `track_set_path(track_idx: int, path: NodePath) -> void` — Sets the path of a track.
- `track_swap(track_idx: int, with_idx: int) -> void` — Swaps the track `track_idx`'s index position with the track `with_idx`.
- `value_track_get_update_mode(track_idx: int) -> int[Animation.UpdateMode]` *const* — Returns the update mode of a value track.
- `value_track_interpolate(track_idx: int, time_sec: float, backward: bool = false) -> Variant` *const* — Returns the interpolated value at the given time (in seconds).
- `value_track_set_update_mode(track_idx: int, mode: Animation.UpdateMode) -> void` — Sets the update mode of a value track.

## Enum TrackType

- `TYPE_VALUE = 0` — Value tracks set values in node properties, but only those which can be interpolated.
- `TYPE_POSITION_3D = 1` — 3D position track (values are stored in Vector3s).
- `TYPE_ROTATION_3D = 2` — 3D rotation track (values are stored in Quaternions).
- `TYPE_SCALE_3D = 3` — 3D scale track (values are stored in Vector3s).
- `TYPE_BLEND_SHAPE = 4` — Blend shape track.
- `TYPE_METHOD = 5` — Method tracks call functions with given arguments per key.
- `TYPE_BEZIER = 6` — Bezier tracks are used to interpolate a value using custom curves.
- `TYPE_AUDIO = 7` — Audio tracks are used to play an audio stream with either type of AudioStreamPlayer.
- `TYPE_ANIMATION = 8` — Animation tracks play animations in other AnimationPlayer nodes.

## Enum InterpolationType

- `INTERPOLATION_NEAREST = 0` — No interpolation (nearest value).
- `INTERPOLATION_LINEAR = 1` — Linear interpolation.
- `INTERPOLATION_CUBIC = 2` — Cubic interpolation.
- `INTERPOLATION_LINEAR_ANGLE = 3` — Linear interpolation with shortest path rotation.
- `INTERPOLATION_CUBIC_ANGLE = 4` — Cubic interpolation with shortest path rotation.
- `INTERPOLATION_MAKIMA = 5` — Modified Akima interpolation.
- `INTERPOLATION_MAKIMA_ANGLE = 6` — Modified Akima interpolation with shortest path rotation.

## Enum UpdateMode

- `UPDATE_CONTINUOUS = 0` — Update between keyframes and hold the value.
- `UPDATE_DISCRETE = 1` — Update at the keyframes.
- `UPDATE_CAPTURE = 2` — Same as `UPDATE_CONTINUOUS` but works as a flag to capture the value of the current object and perform interpolation in some methods.

## Enum LoopMode

- `LOOP_NONE = 0` — At both ends of the animation, the animation will stop playing.
- `LOOP_LINEAR = 1` — At both ends of the animation, the animation will be repeated without changing the playback direction.
- `LOOP_PINGPONG = 2` — Repeats playback and reverse playback at both ends of the animation.

## Enum LoopedFlag

- `LOOPED_FLAG_NONE = 0` — This flag indicates that the animation proceeds without any looping.
- `LOOPED_FLAG_END = 1` — This flag indicates that the animation has reached the end of the animation and just after loop processed.
- `LOOPED_FLAG_START = 2` — This flag indicates that the animation has reached the start of the animation and just after loop processed.

## Enum FindMode

- `FIND_MODE_NEAREST = 0` — Finds the nearest time key.
- `FIND_MODE_APPROX = 1` — Finds only the key with approximating the time.
- `FIND_MODE_EXACT = 2` — Finds only the key with matching the time.
