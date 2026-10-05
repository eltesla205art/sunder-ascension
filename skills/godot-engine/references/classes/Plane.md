# Plane


A plane in Hessian normal form.

Represents a normalized plane equation. `normal` is the normal of the plane (a, b, c normalized), and `d` is the distance from the origin to the plane (in the direction of "normal"). "Over" or "Above" the plane is considered the side of the plane towards where the normal is pointing. Note: In a boolean context, a plane will evaluate to `false` if all its components equal `0`. Otherwise, a plane will always evaluate to `true`.

## Properties

- `d: float` = `0.0` — The distance from the origin to the plane, expressed in terms of `normal` (according to its direction and magnitude).
- `normal: Vector3` = `Vector3(0, 0, 0)` — The normal of the plane, typically a unit vector.
- `x: float` = `0.0` — The X component of the plane's `normal` vector.
- `y: float` = `0.0` — The Y component of the plane's `normal` vector.
- `z: float` = `0.0` — The Z component of the plane's `normal` vector.

## Constructors

- `Plane() -> Plane` — Constructs a default-initialized Plane with all components set to `0`.
- `Plane(from: Plane) -> Plane` — Constructs a Plane as a copy of the given Plane.
- `Plane(a: float, b: float, c: float, d: float) -> Plane` — Creates a plane from the four parameters.
- `Plane(normal: Vector3) -> Plane` — Creates a plane from the normal vector.
- `Plane(normal: Vector3, d: float) -> Plane` — Creates a plane from the normal vector and the plane's distance from the origin.
- `Plane(normal: Vector3, point: Vector3) -> Plane` — Creates a plane from the normal vector and a point on the plane.
- `Plane(point1: Vector3, point2: Vector3, point3: Vector3) -> Plane` — Creates a plane from the three points, given in clockwise order.

## Methods

- `distance_to(point: Vector3) -> float` *const* — Returns the shortest distance from the plane to the position `point`.
- `get_center() -> Vector3` *const* — Returns the center of the plane.
- `has_point(point: Vector3, tolerance: float = 1e-05) -> bool` *const* — Returns `true` if `point` is inside the plane.
- `intersect_3(b: Plane, c: Plane) -> Variant` *const* — Returns the intersection point of the three planes `b`, `c` and this plane.
- `intersects_ray(from: Vector3, dir: Vector3) -> Variant` *const* — Returns the intersection point of a ray consisting of the position `from` and the direction normal `dir` with this plane.
- `intersects_segment(from: Vector3, to: Vector3) -> Variant` *const* — Returns the intersection point of a segment from position `from` to position `to` with this plane.
- `is_equal_approx(to_plane: Plane) -> bool` *const* — Returns `true` if this plane and `to_plane` are approximately equal, by running `@GlobalScope.is_equal_approx` on each component.
- `is_finite() -> bool` *const* — Returns `true` if this plane is finite, by calling `@GlobalScope.is_finite` on each component.
- `is_point_over(point: Vector3) -> bool` *const* — Returns `true` if `point` is located above the plane.
- `normalized() -> Plane` *const* — Returns a copy of the plane, with normalized `normal` (so it's a unit vector).
- `project(point: Vector3) -> Vector3` *const* — Returns the orthogonal projection of `point` into a point in the plane.

## Operators

- `operator !=(right: Plane) -> bool` — Returns `true` if the planes are not equal.
- `operator *(right: Transform3D) -> Plane` — Inversely transforms (multiplies) the Plane by the given Transform3D transformation matrix.
- `operator ==(right: Plane) -> bool` — Returns `true` if the planes are exactly equal.
- `operator unary+() -> Plane` — Returns the same value as if the `+` was not there.
- `operator unary-() -> Plane` — Returns the negative value of the Plane.

## Constants

- `PLANE_YZ = Plane(1, 0, 0, 0)` — A plane that extends in the Y and Z axes (normal vector points +X).
- `PLANE_XZ = Plane(0, 1, 0, 0)` — A plane that extends in the X and Z axes (normal vector points +Y).
- `PLANE_XY = Plane(0, 0, 1, 0)` — A plane that extends in the X and Y axes (normal vector points +Z).
