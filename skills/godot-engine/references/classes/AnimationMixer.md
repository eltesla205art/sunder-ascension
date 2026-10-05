# AnimationMixer

**Inherits:** Node

Base class for AnimationPlayer and AnimationTree.

Base class for AnimationPlayer and AnimationTree to manage animation lists. It also has general properties and methods for playback and blending. After instantiating the playback information data within the extended class, the blending is processed by the AnimationMixer.

## Properties

- `active: bool` = `true` — If `true`, the AnimationMixer will be processing.
- `audio_max_polyphony: int` = `32` — The number of possible simultaneous sounds for each of the assigned AudioStreamPlayers.
- `callback_mode_discrete: AnimationMixer.AnimationCallbackModeDiscrete` = `1` — Ordinarily, tracks can be set to `Animation.UPDATE_DISCRETE` to update infrequently, usually when using nearest interpolation.
- `callback_mode_method: AnimationMixer.AnimationCallbackModeMethod` = `0` — The call mode used for "Call Method" tracks.
- `callback_mode_process: AnimationMixer.AnimationCallbackModeProcess` = `1` — The process notification in which to update animations.
- `deterministic: bool` = `false` — If `true`, the blending uses the deterministic algorithm.
- `reset_on_save: bool` = `true` — This is used by the editor.
- `root_motion_local: bool` = `false` — If `true`, `get_root_motion_position` value is extracted as a local translation value before blending.
- `root_motion_track: NodePath` = `NodePath("")` — The path to the Animation track used for root motion.
- `root_node: NodePath` = `NodePath("..")` — The node which node path references will travel from.

## Methods

- `_post_process_key_value(animation: Animation, track: int, value: Variant, object_id: int, object_sub_idx: int) -> Variant` *virtual const* — A virtual function for processing after getting a key during playback.
- `add_animation_library(name: StringName, library: AnimationLibrary) -> int[Error]` — Adds `library` to the animation player, under the key `name`.
- `advance(delta: float) -> void` — Manually advance the animations by the specified time (in seconds).
- `capture(name: StringName, duration: float, trans_type: Tween.TransitionType = 0, ease_type: Tween.EaseType = 0) -> void` — If the animation track specified by `name` has an option `Animation.UPDATE_CAPTURE`, stores current values of the objects indicated by the track path as a cache.
- `clear_caches() -> void` — AnimationMixer caches animated nodes.
- `find_animation(animation: Animation) -> StringName` *const* — Returns the key of `animation` or an empty StringName if not found.
- `find_animation_library(animation: Animation) -> StringName` *const* — Returns the key for the AnimationLibrary that contains `animation` or an empty StringName if not found.
- `get_animation(name: StringName) -> Animation` *const* — Returns the Animation with the key `name`.
- `get_animation_library(name: StringName) -> AnimationLibrary` *const* — Returns the first AnimationLibrary with key `name` or `null` if not found.
- `get_animation_library_list() -> StringName[]` *const* — Returns the list of stored library keys.
- `get_animation_list() -> PackedStringArray` *const* — Returns the list of stored animation keys.
- `get_root_motion_position() -> Vector3` *const* — Retrieve the motion delta of position with the `root_motion_track` as a Vector3 that can be used elsewhere.
- `get_root_motion_position_accumulator() -> Vector3` *const* — Retrieve the blended value of the position tracks with the `root_motion_track` as a Vector3 that can be used elsewhere.
- `get_root_motion_rotation() -> Quaternion` *const* — Retrieve the motion delta of rotation with the `root_motion_track` as a Quaternion that can be used elsewhere.
- `get_root_motion_rotation_accumulator() -> Quaternion` *const* — Retrieve the blended value of the rotation tracks with the `root_motion_track` as a Quaternion that can be used elsewhere.
- `get_root_motion_scale() -> Vector3` *const* — Retrieve the motion delta of scale with the `root_motion_track` as a Vector3 that can be used elsewhere.
- `get_root_motion_scale_accumulator() -> Vector3` *const* — Retrieve the blended value of the scale tracks with the `root_motion_track` as a Vector3 that can be used elsewhere.
- `has_animation(name: StringName) -> bool` *const* — Returns `true` if the AnimationMixer stores an Animation with key `name`.
- `has_animation_library(name: StringName) -> bool` *const* — Returns `true` if the AnimationMixer stores an AnimationLibrary with key `name`.
- `remove_animation_library(name: StringName) -> void` — Removes the AnimationLibrary associated with the key `name`.
- `rename_animation_library(name: StringName, newname: StringName) -> void` — Moves the AnimationLibrary associated with the key `name` to the key `newname`.

## Signals

- `animation_finished(anim_name: StringName)` — Notifies when an animation finished playing.
- `animation_libraries_updated()` — Notifies when the animation libraries have changed.
- `animation_list_changed()` — Notifies when an animation list is changed.
- `animation_started(anim_name: StringName)` — Notifies when an animation starts playing.
- `caches_cleared()` — Notifies when the caches have been cleared, either automatically, or manually via `clear_caches`.
- `mixer_applied()` — Notifies when the blending result related have been applied to the target objects.
- `mixer_updated()` — Notifies when the property related process have been updated.

## Enum AnimationCallbackModeProcess

- `ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS = 0` — Process animation during physics frames (see `Node.NOTIFICATION_INTERNAL_PHYSICS_PROCESS`).
- `ANIMATION_CALLBACK_MODE_PROCESS_IDLE = 1` — Process animation during process frames (see `Node.NOTIFICATION_INTERNAL_PROCESS`).
- `ANIMATION_CALLBACK_MODE_PROCESS_MANUAL = 2` — Do not process animation.

## Enum AnimationCallbackModeMethod

- `ANIMATION_CALLBACK_MODE_METHOD_DEFERRED = 0` — Batch method calls during the animation process, then do the calls after events are processed.
- `ANIMATION_CALLBACK_MODE_METHOD_IMMEDIATE = 1` — Make method calls immediately when reached in the animation.

## Enum AnimationCallbackModeDiscrete

- `ANIMATION_CALLBACK_MODE_DISCRETE_DOMINANT = 0` — An `Animation.UPDATE_DISCRETE` track value takes precedence when blending `Animation.UPDATE_CONTINUOUS` or `Animation.UPDATE_CAPTURE` track values and `Animation.UPDATE_DISCRETE` track values.
- `ANIMATION_CALLBACK_MODE_DISCRETE_RECESSIVE = 1` — An `Animation.UPDATE_CONTINUOUS` or `Animation.UPDATE_CAPTURE` track value takes precedence when blending the `Animation.UPDATE_CONTINUOUS` or `Animation.UPDATE_CAPTURE` track values and the `Animation.UPDATE_DISCRETE` track values.
- `ANIMATION_CALLBACK_MODE_DISCRETE_FORCE_CONTINUOUS = 2` — Always treat the `Animation.UPDATE_DISCRETE` track value as `Animation.UPDATE_CONTINUOUS` with `Animation.INTERPOLATION_NEAREST`.
