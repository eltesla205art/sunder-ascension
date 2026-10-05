# AABB


A 3D axis-aligned bounding box.

The AABB built-in Variant type represents an axis-aligned bounding box in a 3D space. It is defined by its `position` and `size`, which are Vector3. It is frequently used for fast overlap tests (see `intersects`). Although AABB itself is axis-aligned, it can be combined with Transform3D to represent a rotated or skewed bounding box.

## Properties

- `end: Vector3` = `Vector3(0, 0, 0)` — The ending point.
- `position: Vector3` = `Vector3(0, 0, 0)` — The origin point.
- `size: Vector3` = `Vector3(0, 0, 0)` — The bounding box's width, height, and depth starting from `position`.

## Constructors

- `AABB() -> AABB` — Constructs an AABB with its `position` and `size` set to `Vector3.ZERO`.
- `AABB(from: AABB) -> AABB` — Constructs an AABB as a copy of the given AABB.
- `AABB(position: Vector3, size: Vector3) -> AABB` — Constructs an AABB by `position` and `size`.

## Methods

- `abs() -> AABB` *const* — Returns an AABB equivalent to this bounding box, with its width, height, and depth modified to be non-negative values.
- `encloses(with: AABB) -> bool` *const* — Returns `true` if this bounding box completely encloses the `with` box.
- `expand(to_point: Vector3) -> AABB` *const* — Returns a copy of this bounding box expanded to align the edges with the given `to_point`, if necessary.
- `get_center() -> Vector3` *const* — Returns the center point of the bounding box.
- `get_endpoint(idx: int) -> Vector3` *const* — Returns the position of one of the 8 vertices that compose this bounding box.
- `get_longest_axis() -> Vector3` *const* — Returns the longest normalized axis of this bounding box's `size`, as a Vector3 (`Vector3.RIGHT`, `Vector3.UP`, or `Vector3.BACK`).
- `get_longest_axis_index() -> int` *const* — Returns the index to the longest axis of this bounding box's `size` (see `Vector3.AXIS_X`, `Vector3.AXIS_Y`, and `Vector3.AXIS_Z`).
- `get_longest_axis_size() -> float` *const* — Returns the longest dimension of this bounding box's `size`.
- `get_shortest_axis() -> Vector3` *const* — Returns the shortest normalized axis of this bounding box's `size`, as a Vector3 (`Vector3.RIGHT`, `Vector3.UP`, or `Vector3.BACK`).
- `get_shortest_axis_index() -> int` *const* — Returns the index to the shortest axis of this bounding box's `size` (see `Vector3.AXIS_X`, `Vector3.AXIS_Y`, and `Vector3.AXIS_Z`).
- `get_shortest_axis_size() -> float` *const* — Returns the shortest dimension of this bounding box's `size`.
- `get_support(direction: Vector3) -> Vector3` *const* — Returns the vertex's position of this bounding box that's the farthest in the given direction.
- `get_volume() -> float` *const* — Returns the bounding box's volume.
- `grow(by: float) -> AABB` *const* — Returns a copy of this bounding box extended on all sides by the given amount `by`.
- `has_point(point: Vector3) -> bool` *const* — Returns `true` if the bounding box contains the given `point`.
- `has_surface() -> bool` *const* — Returns `true` if this bounding box has a surface or a length, that is, at least one component of `size` is greater than `0`.
- `has_volume() -> bool` *const* — Returns `true` if this bounding box's width, height, and depth are all positive.
- `intersection(with: AABB) -> AABB` *const* — Returns the intersection between this bounding box and `with`.
- `intersects(with: AABB) -> bool` *const* — Returns `true` if this bounding box overlaps with the box `with`.
- `intersects_plane(plane: Plane) -> bool` *const* — Returns `true` if this bounding box is on both sides of the given `plane`.
- `intersects_ray(from: Vector3, dir: Vector3) -> Variant` *const* — Returns the first point where this bounding box and the given ray intersect, as a Vector3.
- `intersects_segment(from: Vector3, to: Vector3) -> Variant` *const* — Returns the first point where this bounding box and the given segment intersect, as a Vector3.
- `is_equal_approx(aabb: AABB) -> bool` *const* — Returns `true` if this bounding box and `aabb` are approximately equal, by calling `Vector3.is_equal_approx` on the `position` and the `size`.
- `is_finite() -> bool` *const* — Returns `true` if this bounding box's values are finite, by calling `Vector3.is_finite` on the `position` and the `size`.
- `merge(with: AABB) -> AABB` *const* — Returns an AABB that encloses both this bounding box and `with` around the edges.

## Operators

- `operator !=(right: AABB) -> bool` — Returns `true` if the `position` or `size` of both bounding boxes are not equal.
- `operator *(right: Transform3D) -> AABB` — Inversely transforms (multiplies) the AABB by the given Transform3D transformation matrix, under the assumption that the transformation basis is orthonormal (i.e. rotation/reflection is fine, scaling/skew is not).
- `operator ==(right: AABB) -> bool` — Returns `true` if both `position` and `size` of the bounding boxes are exactly equal, respectively.
