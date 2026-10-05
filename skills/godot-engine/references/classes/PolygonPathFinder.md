# PolygonPathFinder

**Inherits:** Resource





## Methods

- `find_path(from: Vector2, to: Vector2) -> PackedVector2Array`
- `get_bounds() -> Rect2` *const*
- `get_closest_point(point: Vector2) -> Vector2` *const*
- `get_intersections(from: Vector2, to: Vector2) -> PackedVector2Array` *const*
- `get_point_penalty(idx: int) -> float` *const*
- `is_point_inside(point: Vector2) -> bool` *const* — Returns `true` if `point` falls inside the polygon area.
- `set_point_penalty(idx: int, penalty: float) -> void`
- `setup(points: PackedVector2Array, connections: PackedInt32Array) -> void` — Sets up PolygonPathFinder with an array of points that define the vertices of the polygon, and an array of indices that determine the edges of the polygon.
