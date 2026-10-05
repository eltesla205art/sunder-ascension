# Geometry2D

**Inherits:** Object

Provides methods for some common 2D geometric operations.

Provides a set of helper functions to create geometric shapes, compute intersections between shapes, and process various other geometric operations in 2D.

## Methods

- `bresenham_line(from: Vector2i, to: Vector2i) -> Vector2i[]` — Returns the Bresenham line between the `from` and `to` points.
- `clip_polygons(polygon_a: PackedVector2Array, polygon_b: PackedVector2Array) -> PackedVector2Array[]` — Clips `polygon_a` against `polygon_b` and returns an array of clipped polygons.
- `clip_polyline_with_polygon(polyline: PackedVector2Array, polygon: PackedVector2Array) -> PackedVector2Array[]` — Clips `polyline` against `polygon` and returns an array of clipped polylines.
- `convex_hull(points: PackedVector2Array) -> PackedVector2Array` — Given an array of Vector2s, returns the convex hull as a list of points in counterclockwise order.
- `decompose_polygon_in_convex(polygon: PackedVector2Array) -> PackedVector2Array[]` — Decomposes the `polygon` into multiple convex hulls and returns an array of PackedVector2Array.
- `exclude_polygons(polygon_a: PackedVector2Array, polygon_b: PackedVector2Array) -> PackedVector2Array[]` — Mutually excludes common area defined by intersection of `polygon_a` and `polygon_b` (see `intersect_polygons`) and returns an array of excluded polygons.
- `get_closest_point_to_segment(point: Vector2, s1: Vector2, s2: Vector2) -> Vector2` — Returns the 2D point on the 2D segment (`s1`, `s2`) that is closest to `point`.
- `get_closest_point_to_segment_uncapped(point: Vector2, s1: Vector2, s2: Vector2) -> Vector2` — Returns the 2D point on the 2D line defined by (`s1`, `s2`) that is closest to `point`.
- `get_closest_points_between_segments(p1: Vector2, q1: Vector2, p2: Vector2, q2: Vector2) -> PackedVector2Array` — Given the two 2D segments (`p1`, `q1`) and (`p2`, `q2`), finds those two points on the two segments that are closest to each other.
- `intersect_polygons(polygon_a: PackedVector2Array, polygon_b: PackedVector2Array) -> PackedVector2Array[]` — Intersects `polygon_a` with `polygon_b` and returns an array of intersected polygons.
- `intersect_polyline_with_polygon(polyline: PackedVector2Array, polygon: PackedVector2Array) -> PackedVector2Array[]` — Intersects `polyline` with `polygon` and returns an array of intersected polylines.
- `is_point_in_circle(point: Vector2, circle_position: Vector2, circle_radius: float) -> bool` — Returns `true` if `point` is inside the circle or if it's located exactly on the circle's boundary, otherwise returns `false`.
- `is_point_in_polygon(point: Vector2, polygon: PackedVector2Array) -> bool` — Returns `true` if `point` is inside `polygon` or if it's located exactly on polygon's boundary, otherwise returns `false`.
- `is_polygon_clockwise(polygon: PackedVector2Array) -> bool` — Returns `true` if `polygon`'s vertices are ordered in clockwise order, otherwise returns `false`.
- `line_intersects_line(from_a: Vector2, dir_a: Vector2, from_b: Vector2, dir_b: Vector2) -> Variant` — Returns the point of intersection between the two lines (`from_a`, `dir_a`) and (`from_b`, `dir_b`).
- `make_atlas(sizes: PackedVector2Array) -> Dictionary` — Given an array of Vector2s representing tiles, builds an atlas.
- `merge_polygons(polygon_a: PackedVector2Array, polygon_b: PackedVector2Array) -> PackedVector2Array[]` — Merges (combines) `polygon_a` and `polygon_b` and returns an array of merged polygons.
- `offset_polygon(polygon: PackedVector2Array, delta: float, join_type: Geometry2D.PolyJoinType = 0) -> PackedVector2Array[]` — Inflates or deflates `polygon` by `delta` units (pixels).
- `offset_polyline(polyline: PackedVector2Array, delta: float, join_type: Geometry2D.PolyJoinType = 0, end_type: Geometry2D.PolyEndType = 3) -> PackedVector2Array[]` — Inflates or deflates `polyline` by `delta` units (pixels), producing polygons.
- `point_is_inside_triangle(point: Vector2, a: Vector2, b: Vector2, c: Vector2) -> bool` *const* — Returns if `point` is inside the triangle specified by `a`, `b` and `c`.
- `segment_intersects_circle(segment_from: Vector2, segment_to: Vector2, circle_position: Vector2, circle_radius: float) -> float` — Given the 2D segment (`segment_from`, `segment_to`), returns the position on the segment (as a number between 0 and 1) at which the segment hits the circle that is located at position `circle_position` and has radius `circle_radius`.
- `segment_intersects_segment(from_a: Vector2, to_a: Vector2, from_b: Vector2, to_b: Vector2) -> Variant` — Checks if two line segments intersect, with line `a` between `from_a` and `to_a` and line `b` between `from_b` and `to_b`.
- `triangulate_delaunay(points: PackedVector2Array) -> PackedInt32Array` — Triangulates the area specified by discrete set of `points` such that no point is inside the circumcircle of any resulting triangle.
- `triangulate_polygon(polygon: PackedVector2Array) -> PackedInt32Array` — Triangulates the polygon specified by the points in `polygon`.

## Enum PolyBooleanOperation

- `OPERATION_UNION = 0` — Create regions where either subject or clip polygons (or both) are filled.
- `OPERATION_DIFFERENCE = 1` — Create regions where subject polygons are filled except where clip polygons are filled.
- `OPERATION_INTERSECTION = 2` — Create regions where both subject and clip polygons are filled.
- `OPERATION_XOR = 3` — Create regions where either subject or clip polygons are filled but not where both are filled.

## Enum PolyJoinType

- `JOIN_SQUARE = 0` — Squaring is applied uniformally at all convex edge joins at `1 * delta`.
- `JOIN_ROUND = 1` — While flattened paths can never perfectly trace an arc, they are approximated by a series of arc chords.
- `JOIN_MITER = 2` — There's a necessary limit to mitered joins since offsetting edges that join at very acute angles will produce excessively long and narrow "spikes".

## Enum PolyEndType

- `END_POLYGON = 0` — Endpoints are joined using the `PolyJoinType` value and the path filled as a polygon.
- `END_JOINED = 1` — Endpoints are joined using the `PolyJoinType` value and the path filled as a polyline.
- `END_BUTT = 2` — Endpoints are squared off with no extension.
- `END_SQUARE = 3` — Endpoints are squared off and extended by `delta` units.
- `END_ROUND = 4` — Endpoints are rounded off and extended by `delta` units.
