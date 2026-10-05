# AnimatedSprite2D

**Inherits:** Node2D

Sprite node that contains multiple textures as frames to play for animation.

AnimatedSprite2D is similar to the Sprite2D node, except it carries multiple textures as animation frames. Animations are created using a SpriteFrames resource, which allows you to import image files (or a folder containing said files) to provide the animation frames for the sprite. The SpriteFrames resource can be configured in the editor via the SpriteFrames bottom panel.

## Properties

- `animation: StringName` = `&"default"` — The current animation from the `sprite_frames` resource.
- `autoplay: String` = `""` — The key of the animation to play when the scene loads.
- `centered: bool` = `true` — If `true`, texture will be centered.
- `flip_h: bool` = `false` — If `true`, texture is flipped horizontally.
- `flip_v: bool` = `false` — If `true`, texture is flipped vertically.
- `frame: int` = `0` — The displayed animation frame's index.
- `frame_progress: float` = `0.0` — The progress value between `0.0` and `1.0` until the current frame transitions to the next frame.
- `offset: Vector2` = `Vector2(0, 0)` — The texture's drawing offset.
- `speed_scale: float` = `1.0` — The speed scaling ratio.
- `sprite_frames: SpriteFrames` — The SpriteFrames resource containing the animation(s).

## Methods

- `get_playing_speed() -> float` *const* — Returns the actual playing speed of current animation or `0` if not playing.
- `is_playing() -> bool` *const* — Returns `true` if an animation is currently playing (even if `speed_scale` and/or `custom_speed` are `0`).
- `pause() -> void` — Pauses the currently playing animation.
- `play(name: StringName = &"", custom_speed: float = 1.0, from_end: bool = false) -> void` — Plays the animation with key `name`.
- `play_backwards(name: StringName = &"") -> void` — Plays the animation with key `name` in reverse.
- `set_frame_and_progress(frame: int, progress: float) -> void` — Sets `frame` and `frame_progress` to the given values.
- `stop() -> void` — Stops the currently playing animation.

## Signals

- `animation_changed()` — Emitted when `animation` changes.
- `animation_finished()` — Emitted when the animation reaches the end, or the start if it is played in reverse.
- `animation_looped()` — Emitted when the animation loops.
- `frame_changed()` — Emitted when `frame` changes.
- `sprite_frames_changed()` — Emitted when `sprite_frames` changes.
