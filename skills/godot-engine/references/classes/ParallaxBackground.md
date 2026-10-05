# ParallaxBackground

**Inherits:** CanvasLayer
**Deprecated:** Use the Parallax2D node instead.

A node used to create a parallax scrolling background.

A ParallaxBackground uses one or more ParallaxLayer child nodes to create a parallax effect. Each ParallaxLayer can move at a different speed using `ParallaxLayer.motion_offset`. This creates an illusion of depth in a 2D game. If not used with a Camera2D, you must manually calculate the `scroll_offset`.

## Properties

- `layer: int` = `-100` — 
- `scroll_base_offset: Vector2` = `Vector2(0, 0)` — The base position offset for all ParallaxLayer children.
- `scroll_base_scale: Vector2` = `Vector2(1, 1)` — The base motion scale for all ParallaxLayer children.
- `scroll_ignore_camera_zoom: bool` = `false` — If `true`, elements in ParallaxLayer child aren't affected by the zoom level of the camera.
- `scroll_limit_begin: Vector2` = `Vector2(0, 0)` — Top-left limits for scrolling to begin.
- `scroll_limit_end: Vector2` = `Vector2(0, 0)` — Bottom-right limits for scrolling to end.
- `scroll_offset: Vector2` = `Vector2(0, 0)` — The ParallaxBackground's scroll value.
