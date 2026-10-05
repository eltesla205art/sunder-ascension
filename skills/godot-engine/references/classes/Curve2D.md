# Curve2D

**Inherits:** Resource

Describes a Bézier curve in 2D space.

This class describes a Bézier curve in 2D space. It is mainly used to give a shape to a Path2D, but can be manually sampled for other purposes. It keeps a cache of precalculated points along the curve, to speed up further calculations.

## Properties

- `bake_interval: float` = `5.0` — The distance in pixels between two adjacent cached points.
- `point_count: int` = `0` — The number of points describing the curve.
- `point_{index}/in: Vector2` = `Vector2(0, 0)` — The position of the control point leading to the vertex at `index`.
- `point_{index}/out: Vector2` = `Vector2(0, 0)` — The position of the control point leading out of the vertex at `index`.
- `point_{index}/position: Vector2` = `Vector2(0, 0)` — The position of for the vertex at `index`.

## Methods

- `add_point(position: Vector2, in: Vector2 = Vector2(0, 0), out: Vector2 = Vector2(0, 0), index: int = -1) -> void` — Adds a point with the specified `position` relative to the curve's own position, with control points `in` and `out`.
- `clear_points() -> void` — Removes all points from the curve.
- `get_baked_length() -> float` *const* — Returns the total length of the curve, based on the cached points.
- `get_baked_points() -> PackedVector2Array` *const* — Returns the cache of points as a PackedVector2Array.
- `get_closest_offset(to_point: Vector2) -> float` *const* — Returns the closest offset to `to_point`.
- `get_closest_point(to_point: Vector2) -> Vector2` *const* — Returns the closest point on baked segments (in curve's local space) to `to_point`.
- `get_point_in(idx: int) -> Vector2` *const* — Returns the position of the control point leading to the vertex `idx`.
- `get_point_out(idx: int) -> Vector2` *const* — Returns the position of the control point leading out of the vertex `idx`.
- `get_point_position(idx: int) -> Vector2` *const* — Returns the position of the vertex `idx`.
- `remove_point(idx: int) -> void` — Deletes the point `idx` from the curve.
- `sample(idx: int, t: float) -> Vector2` *const* — Returns the position between the vertex `idx` and the vertex `idx + 1`, where `t` controls if the point is the first vertex (`t = 0.0`), the last vertex (`t = 1.0`), or in between.
- `sample_baked(offset: float = 0.0, cubic: bool = false) -> Vector2` *const* — Returns a point within the curve at position `offset`, where `offset` is measured as a pixel distance along the curve.
- `sample_baked_with_rotation(offset: float = 0.0, cubic: bool = false) -> Transform2D` *const* — Similar to `sample_baked`, but returns Transform2D that includes a rotation along the curve, with `Transform2D.origin` as the point position and the `Transform2D.x` vector pointing in the direction of the path at that point.
- `samplef(fofs: float) -> Vector2` *const* — Returns the position at the vertex `fofs`.
- `set_point_in(idx: int, position: Vector2) -> void` — Sets the position of the control point leading to the vertex `idx`.
- `set_point_out(idx: int, position: Vector2) -> void` — Sets the position of the control point leading out of the vertex `idx`.
- `set_point_position(idx: int, position: Vector2) -> void` — Sets the position for the vertex `idx`.
- `tessellate(max_stages: int = 5, tolerance_degrees: float = 4) -> PackedVector2Array` *const* — Returns a list of points along the curve, with a curvature controlled point density.
- `tessellate_even_length(max_stages: int = 5, tolerance_length: float = 20.0) -> PackedVector2Array` *const* — Returns a list of points along the curve, with almost uniform density.
