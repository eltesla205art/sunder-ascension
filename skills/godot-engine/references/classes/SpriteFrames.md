# SpriteFrames

**Inherits:** Resource

Sprite frame library for AnimatedSprite2D and AnimatedSprite3D.

Sprite frame library for an AnimatedSprite2D or AnimatedSprite3D node. Contains frames and animation data for playback.

## Methods

- `add_animation(anim: StringName) -> void` — Adds a new `anim` animation to the library.
- `add_frame(anim: StringName, texture: Texture2D, duration: float = 1.0, at_position: int = -1) -> void` — Adds a frame to the `anim` animation.
- `clear(anim: StringName) -> void` — Removes all frames from the `anim` animation.
- `clear_all() -> void` — Removes all animations.
- `duplicate_animation(anim_from: StringName, anim_to: StringName) -> void` — Duplicates the animation `anim_from` to a new animation named `anim_to`.
- `get_animation_loop(anim: StringName) -> bool` *const* *(deprecated)* — Returns `true` if `get_animation_loop_mode(anim) == LOOP_LINEAR`.
- `get_animation_loop_mode(anim: StringName) -> int[SpriteFrames.LoopMode]` *const* — Returns the loop mode for the `anim` animation.
- `get_animation_names() -> PackedStringArray` *const* — Returns an array containing the names associated to each animation.
- `get_animation_speed(anim: StringName) -> float` *const* — Returns the speed in frames per second for the `anim` animation.
- `get_frame_count(anim: StringName) -> int` *const* — Returns the number of frames for the `anim` animation.
- `get_frame_duration(anim: StringName, idx: int) -> float` *const* — Returns a relative duration of the frame `idx` in the `anim` animation (defaults to `1.0`).
- `get_frame_texture(anim: StringName, idx: int) -> Texture2D` *const* — Returns the texture of the frame `idx` in the `anim` animation.
- `has_animation(anim: StringName) -> bool` *const* — Returns `true` if the `anim` animation exists.
- `remove_animation(anim: StringName) -> void` — Removes the `anim` animation.
- `remove_frame(anim: StringName, idx: int) -> void` — Removes the `anim` animation's frame `idx`.
- `rename_animation(anim: StringName, newname: StringName) -> void` — Changes the `anim` animation's name to `newname`.
- `set_animation_loop(anim: StringName, loop: bool) -> void` *(deprecated)* — If `loop` is `false` equivalent to `set_animation_loop_mode(LOOP_NONE)`.
- `set_animation_loop_mode(anim: StringName, loop_mode: SpriteFrames.LoopMode) -> void` — Sets the `loop_mode` for the `anim` animation.
- `set_animation_speed(anim: StringName, fps: float) -> void` — Sets the speed for the `anim` animation in frames per second.
- `set_frame(anim: StringName, idx: int, texture: Texture2D, duration: float = 1.0) -> void` — Sets the `texture` and the `duration` of the frame `idx` in the `anim` animation.

## Enum LoopMode

- `LOOP_NONE = 0` — The animation plays once and stops when it reaches the end, or the start if played in reverse.
- `LOOP_LINEAR = 1` — The animation restarts from the beginning when it reaches the end, or from the end if played in reverse, repeating continuously.
- `LOOP_PINGPONG = 2` — The animation alternates direction each time it reaches the end or start, playing forward and then in reverse repeatedly.
