# InputEventMouseMotion

**Inherits:** InputEventMouse

Represents a mouse or a pen movement.

Stores information about a mouse or a pen motion. This includes relative position, absolute position, and velocity. See `Node._input`. Note: By default, this event is only emitted once per frame rendered at most.

## Properties

- `pen_inverted: bool` = `false` — Returns `true` when using the eraser end of a stylus pen.
- `pressure: float` = `0.0` — Represents the pressure the user puts on the pen.
- `relative: Vector2` = `Vector2(0, 0)` — The mouse position relative to the previous position (position at the last frame).
- `screen_relative: Vector2` = `Vector2(0, 0)` — The unscaled mouse position relative to the previous position in the coordinate system of the screen (position at the last frame).
- `screen_velocity: Vector2` = `Vector2(0, 0)` — The unscaled mouse velocity in pixels per second in screen coordinates.
- `tilt: Vector2` = `Vector2(0, 0)` — Represents the angles of tilt of the pen.
- `velocity: Vector2` = `Vector2(0, 0)` — The mouse velocity in pixels per second.
