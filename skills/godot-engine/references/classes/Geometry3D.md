# Geometry3D

**Inherits:** Object

Provides methods for some common 3D geometric operations.

Provides a set of helper functions to create geometric shapes, compute intersections between shapes, and process various other geometric operations in 3D.

## Methods

- `build_box_planes(extents: Vector3) -> Plane[]` — Returns an array with 6 Planes that describe the sides of a box centered at the origin.
- `build_capsule_planes(radius: float, height: float, sides: int, lats: int, axis: Vector3.Axis = 2) -> Plane[]` — Returns an array of Planes closely bounding a faceted capsule centered at the origin with radius `radius` and height `height`.
- `build_cylinder_planes(radius: float, height: float, sides: int, axis: Vector3.Axis = 2) -> Plane[]` — Returns an array of Planes closely bounding a faceted cylinder centered at the origin with radius `radius` and height `height`.
- `clip_polygon(points: PackedVector3Array, plane: Plane) -> PackedVector3Array` — Clips the polygon defined by the points in `points` against the `plane` and returns the points of the clipped polygon.
- `compute_convex_mesh_points(planes: Plane[]) -> PackedVector3Array` — Calculates and returns all the vertex points of a convex shape defined by an array of `planes`.
- `get_closest_point_to_segment(point: Vector3, s1: Vector3, s2: Vector3) -> Vector3` — Returns the 3D point on the 3D segment (`s1`, `s2`) that is closest to `point`.
- `get_closest_point_to_segment_uncapped(point: Vector3, s1: Vector3, s2: Vector3) -> Vector3` — Returns the 3D point on the 3D line defined by (`s1`, `s2`) that is closest to `point`.
- `get_closest_points_between_segments(p1: Vector3, p2: Vector3, q1: Vector3, q2: Vector3) -> PackedVector3Array` — Given the two 3D segments (`p1`, `p2`) and (`q1`, `q2`), finds those two points on the two segments that are closest to each other.
- `get_triangle_barycentric_coords(point: Vector3, a: Vector3, b: Vector3, c: Vector3) -> Vector3` — Returns a Vector3 containing weights based on how close a 3D position (`point`) is to a triangle's different vertices (`a`, `b` and `c`).
- `ray_intersects_triangle(from: Vector3, dir: Vector3, a: Vector3, b: Vector3, c: Vector3) -> Variant` — Tests if the 3D ray starting at `from` with the direction of `dir` intersects the triangle specified by `a`, `b` and `c`.
- `segment_intersects_convex(from: Vector3, to: Vector3, planes: Plane[]) -> PackedVector3Array` — Given a convex hull defined though the Planes in the array `planes`, tests if the segment (`from`, `to`) intersects with that hull.
- `segment_intersects_cylinder(from: Vector3, to: Vector3, height: float, radius: float) -> PackedVector3Array` — Checks if the segment (`from`, `to`) intersects the cylinder with height `height` that is centered at the origin and has radius `radius`.
- `segment_intersects_sphere(from: Vector3, to: Vector3, sphere_position: Vector3, sphere_radius: float) -> PackedVector3Array` — Checks if the segment (`from`, `to`) intersects the sphere that is located at `sphere_position` and has radius `sphere_radius`.
- `segment_intersects_triangle(from: Vector3, to: Vector3, a: Vector3, b: Vector3, c: Vector3) -> Variant` — Tests if the segment (`from`, `to`) intersects the triangle `a`, `b`, `c`.
- `tetrahedralize_delaunay(points: PackedVector3Array) -> PackedInt32Array` — Tetrahedralizes the volume specified by a discrete set of `points` in 3D space, ensuring that no point lies within the circumsphere of any resulting tetrahedron.
