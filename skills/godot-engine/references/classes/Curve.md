# Curve

**Inherits:** Resource

A mathematical curve.

This resource describes a mathematical curve by defining a set of points and tangents at each point. By default, it ranges between `0` and `1` on the X and Y axes, but these ranges can be changed. Please note that many resources and nodes assume they are given unit curves. A unit curve is a curve whose domain (the X axis) is between `0` and `1`.

## Properties

- `bake_resolution: int` = `100` — The number of points to include in the baked (i.e. cached) curve data.
- `max_domain: float` = `1.0` — The maximum domain (x-coordinate) that points can have.
- `max_value: float` = `1.0` — The maximum value (y-coordinate) that points can have.
- `min_domain: float` = `0.0` — The minimum domain (x-coordinate) that points can have.
- `min_value: float` = `0.0` — The minimum value (y-coordinate) that points can have.
- `point_count: int` = `0` — The number of points describing the curve.
- `point_{index}/left_mode: int` = `0` — The left `TangentMode` for the point at `index`.
- `point_{index}/left_tangent: float` = `0.0` — The left tangent angle (in degrees) for the point at `index`.
- `point_{index}/position: Vector2` = `Vector2(0, 0)` — The position of the point at `index`.
- `point_{index}/right_mode: int` = `0` — The right `TangentMode` for the point at `index`.
- `point_{index}/right_tangent: float` = `0.0` — The right tangent angle (in degrees) for the point at `index`.

## Methods

- `add_point(position: Vector2, left_tangent: float = 0, right_tangent: float = 0, left_mode: Curve.TangentMode = 0, right_mode: Curve.TangentMode = 0) -> int` — Adds a point to the curve.
- `bake() -> void` — Recomputes the baked cache of points for the curve.
- `clean_dupes() -> void` — Removes duplicate points, i.e. points that are less than 0.00001 units (engine epsilon value) away from their neighbor on the curve.
- `clear_points() -> void` — Removes all points from the curve.
- `get_domain_range() -> float` *const* — Returns the difference between `min_domain` and `max_domain`.
- `get_point_left_mode(index: int) -> int[Curve.TangentMode]` *const* — Returns the left `TangentMode` for the point at `index`.
- `get_point_left_tangent(index: int) -> float` *const* — Returns the left tangent angle (in degrees) for the point at `index`.
- `get_point_position(index: int) -> Vector2` *const* — Returns the curve coordinates for the point at `index`.
- `get_point_right_mode(index: int) -> int[Curve.TangentMode]` *const* — Returns the right `TangentMode` for the point at `index`.
- `get_point_right_tangent(index: int) -> float` *const* — Returns the right tangent angle (in degrees) for the point at `index`.
- `get_value_range() -> float` *const* — Returns the difference between `min_value` and `max_value`.
- `remove_point(index: int) -> void` — Removes the point at `index` from the curve.
- `sample(offset: float) -> float` *const* — Returns the Y value for the point that would exist at the X position `offset` along the curve.
- `sample_baked(offset: float) -> float` *const* — Returns the Y value for the point that would exist at the X position `offset` along the curve using the baked cache.
- `set_point_left_mode(index: int, mode: Curve.TangentMode) -> void` — Sets the left `TangentMode` for the point at `index` to `mode`.
- `set_point_left_tangent(index: int, tangent: float) -> void` — Sets the left tangent angle for the point at `index` to `tangent`.
- `set_point_offset(index: int, offset: float) -> int` — Assigns the horizontal position `offset` to the point at `index`.
- `set_point_right_mode(index: int, mode: Curve.TangentMode) -> void` — Sets the right `TangentMode` for the point at `index` to `mode`.
- `set_point_right_tangent(index: int, tangent: float) -> void` — Sets the right tangent angle for the point at `index` to `tangent`.
- `set_point_value(index: int, y: float) -> void` — Assigns the vertical position `y` to the point at `index`.

## Signals

- `domain_changed()` — Emitted when `max_domain` or `min_domain` is changed.
- `range_changed()` — Emitted when `max_value` or `min_value` is changed.

## Enum TangentMode

- `TANGENT_FREE = 0` — The tangent on this side of the point is user-defined.
- `TANGENT_LINEAR = 1` — The curve calculates the tangent on this side of the point as the slope halfway towards the adjacent point.
- `TANGENT_MODE_COUNT = 2` — The total number of available tangent modes.
