# Parallax2D

**Inherits:** Node2D

A node used to create a parallax scrolling background.

A Parallax2D is used to create a parallax effect. It can move at a different speed relative to the camera movement using `scroll_scale`. This creates an illusion of depth in a 2D game. If manual scrolling is desired, the Camera2D position can be ignored with `ignore_camera_scroll`.

## Properties

- `autoscroll: Vector2` = `Vector2(0, 0)` — Velocity at which the offset scrolls automatically, in pixels per second.
- `follow_viewport: bool` = `true` — If `true`, this Parallax2D is offset by the current camera's position.
- `ignore_camera_scroll: bool` = `false` — If `true`, Parallax2D's position is not affected by the position of the camera.
- `limit_begin: Vector2` = `Vector2(-10000000, -10000000)` — Top-left limits for scrolling to begin.
- `limit_end: Vector2` = `Vector2(10000000, 10000000)` — Bottom-right limits for scrolling to end.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` — 
- `repeat_size: Vector2` = `Vector2(0, 0)` — Repeats the Texture2D of each of this node's children and offsets them by this value.
- `repeat_times: int` = `1` — Overrides the amount of times the texture repeats.
- `screen_offset: Vector2` = `Vector2(0, 0)` — Offset used to scroll this Parallax2D.
- `scroll_offset: Vector2` = `Vector2(0, 0)` — The Parallax2D's offset.
- `scroll_scale: Vector2` = `Vector2(1, 1)` — Multiplier to the final Parallax2D's offset.
