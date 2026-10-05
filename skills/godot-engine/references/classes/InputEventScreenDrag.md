# InputEventScreenDrag

**Inherits:** InputEventFromWindow

Represents a screen drag event.

Stores information about screen drag events. See `Node._input`.

## Properties

- `index: int` = `0` — The drag event index in the case of a multi-drag event.
- `pen_inverted: bool` = `false` — Returns `true` when using the eraser end of a stylus pen.
- `position: Vector2` = `Vector2(0, 0)` — The drag position in the viewport the node is in, using the coordinate system of this viewport.
- `pressure: float` = `0.0` — Represents the pressure the user puts on the pen.
- `relative: Vector2` = `Vector2(0, 0)` — The drag position relative to the previous position (position at the last frame).
- `screen_relative: Vector2` = `Vector2(0, 0)` — The unscaled drag position relative to the previous position in screen coordinates (position at the last frame).
- `screen_velocity: Vector2` = `Vector2(0, 0)` — The unscaled drag velocity in pixels per second in screen coordinates.
- `tilt: Vector2` = `Vector2(0, 0)` — Represents the angles of tilt of the pen.
- `velocity: Vector2` = `Vector2(0, 0)` — The drag velocity.
