# Vector3


A 3D vector using floating-point coordinates.

A 3-element structure that can be used to represent 3D coordinates or any other triplet of numeric values. It uses floating-point coordinates. By default, these floating-point values use 32-bit precision, unlike float which is always 64-bit. If double precision is needed, compile the engine with the option `precision=double`.

## Properties

- `x: float` = `0.0` — The vector's X component.
- `y: float` = `0.0` — The vector's Y component.
- `z: float` = `0.0` — The vector's Z component.

## Constructors

- `Vector3() -> Vector3` — Constructs a default-initialized Vector3 with all components set to `0`.
- `Vector3(from: Vector3) -> Vector3` — Constructs a Vector3 as a copy of the given Vector3.
- `Vector3(from: Vector3i) -> Vector3` — Constructs a new Vector3 from Vector3i.
- `Vector3(x: float, y: float, z: float) -> Vector3` — Returns a Vector3 with the given components.

## Methods

- `abs() -> Vector3` *const* — Returns a new vector with all components in absolute values (i.e. positive).
- `angle_to(to: Vector3) -> float` *const* — Returns the unsigned minimum angle to the given vector, in radians.
- `bezier_derivative(control_1: Vector3, control_2: Vector3, end: Vector3, t: float) -> Vector3` *const* — Returns the derivative at the given `t` on the Bézier curve defined by this vector and the given `control_1`, `control_2`, and `end` points.
- `bezier_interpolate(control_1: Vector3, control_2: Vector3, end: Vector3, t: float) -> Vector3` *const* — Returns the point at the given `t` on the Bézier curve defined by this vector and the given `control_1`, `control_2`, and `end` points.
- `bounce(n: Vector3) -> Vector3` *const* — Returns the vector "bounced off" from a plane defined by the given normal `n`.
- `ceil() -> Vector3` *const* — Returns a new vector with all components rounded up (towards positive infinity).
- `clamp(min: Vector3, max: Vector3) -> Vector3` *const* — Returns a new vector with all components clamped between the components of `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `clampf(min: float, max: float) -> Vector3` *const* — Returns a new vector with all components clamped between `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `cross(with: Vector3) -> Vector3` *const* — Returns the cross product of this vector and `with`.
- `cubic_interpolate(b: Vector3, pre_a: Vector3, post_b: Vector3, weight: float) -> Vector3` *const* — Performs a cubic interpolation between this vector and `b` using `pre_a` and `post_b` as handles, and returns the result at position `weight`.
- `cubic_interpolate_in_time(b: Vector3, pre_a: Vector3, post_b: Vector3, weight: float, b_t: float, pre_a_t: float, post_b_t: float) -> Vector3` *const* — Performs a cubic interpolation between this vector and `b` using `pre_a` and `post_b` as handles, and returns the result at position `weight`.
- `direction_to(to: Vector3) -> Vector3` *const* — Returns the normalized vector pointing from this vector to `to`.
- `distance_squared_to(to: Vector3) -> float` *const* — Returns the squared Euclidean distance between this vector and `to`.
- `distance_to(to: Vector3) -> float` *const* — Returns the Euclidean distance between this vector and `to`.
- `dot(with: Vector3) -> float` *const* — Returns the dot product of this vector and `with`.
- `floor() -> Vector3` *const* — Returns a new vector with all components rounded down (towards negative infinity).
- `inverse() -> Vector3` *const* — Returns the inverse of the vector.
- `is_equal_approx(to: Vector3) -> bool` *const* — Returns `true` if this vector and `to` are approximately equal, by running `@GlobalScope.is_equal_approx` on each component.
- `is_finite() -> bool` *const* — Returns `true` if this vector is finite, by calling `@GlobalScope.is_finite` on each component.
- `is_normalized() -> bool` *const* — Returns `true` if the vector is normalized, i.e. its length is approximately equal to 1.
- `is_zero_approx() -> bool` *const* — Returns `true` if this vector's values are approximately zero, by running `@GlobalScope.is_zero_approx` on each component.
- `length() -> float` *const* — Returns the length (magnitude) of this vector.
- `length_squared() -> float` *const* — Returns the squared length (squared magnitude) of this vector.
- `lerp(to: Vector3, weight: float) -> Vector3` *const* — Returns the result of the linear interpolation between this vector and `to` by amount `weight`.
- `limit_length(length: float = 1.0) -> Vector3` *const* — Returns the vector with a maximum length by limiting its length to `length`.
- `max(with: Vector3) -> Vector3` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector3(maxf(x, with.x), maxf(y, with.y), maxf(z, with.z))`.
- `max_axis_index() -> int` *const* — Returns the axis of the vector's highest value.
- `maxf(with: float) -> Vector3` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector3(maxf(x, with), maxf(y, with), maxf(z, with))`.
- `min(with: Vector3) -> Vector3` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector3(minf(x, with.x), minf(y, with.y), minf(z, with.z))`.
- `min_axis_index() -> int` *const* — Returns the axis of the vector's lowest value.
- `minf(with: float) -> Vector3` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector3(minf(x, with), minf(y, with), minf(z, with))`.
- `move_toward(to: Vector3, delta: float) -> Vector3` *const* — Returns a new vector moved toward `to` by the fixed `delta` amount.
- `normalized() -> Vector3` *const* — Returns the result of scaling the vector to unit length.
- `octahedron_decode(uv: Vector2) -> Vector3` *static* — Returns the Vector3 from an octahedral-compressed form created using `octahedron_encode` (stored as a Vector2).
- `octahedron_encode() -> Vector2` *const* — Returns the octahedral-encoded (oct32) form of this Vector3 as a Vector2.
- `outer(with: Vector3) -> Basis` *const* — Returns the outer product with `with`.
- `posmod(mod: float) -> Vector3` *const* — Returns a vector composed of the `@GlobalScope.fposmod` of this vector's components and `mod`.
- `posmodv(modv: Vector3) -> Vector3` *const* — Returns a vector composed of the `@GlobalScope.fposmod` of this vector's components and `modv`'s components.
- `project(b: Vector3) -> Vector3` *const* — Returns a new vector resulting from projecting this vector onto the given vector `b`.
- `reflect(n: Vector3) -> Vector3` *const* — Returns the result of reflecting the vector through a plane defined by the given normal vector `n`.
- `rotated(axis: Vector3, angle: float) -> Vector3` *const* — Returns the result of rotating this vector around a given axis by `angle` (in radians).
- `round() -> Vector3` *const* — Returns a new vector with all components rounded to the nearest integer, with halfway cases rounded away from zero.
- `sign() -> Vector3` *const* — Returns a new vector with each component set to `1.0` if it's positive, `-1.0` if it's negative, and `0.0` if it's zero.
- `signed_angle_to(to: Vector3, axis: Vector3) -> float` *const* — Returns the signed angle to the given vector, in radians.
- `slerp(to: Vector3, weight: float) -> Vector3` *const* — Returns the result of spherical linear interpolation between this vector and `to`, by amount `weight`.
- `slide(n: Vector3) -> Vector3` *const* — Returns a new vector resulting from sliding this vector along a plane with normal `n`.
- `snapped(step: Vector3) -> Vector3` *const* — Returns a new vector with each component snapped to the nearest multiple of the corresponding component in `step`.
- `snappedf(step: float) -> Vector3` *const* — Returns a new vector with each component snapped to the nearest multiple of `step`.

## Operators

- `operator !=(right: Vector3) -> bool` — Returns `true` if the vectors are not equal.
- `operator *(right: Basis) -> Vector3` — Inversely transforms (multiplies) the Vector3 by the given Basis matrix, under the assumption that the basis is orthonormal (i.e. rotation/reflection is fine, scaling/skew is not).
- `operator *(right: Quaternion) -> Vector3` — Inversely transforms (multiplies) the Vector3 by the given Quaternion.
- `operator *(right: Transform3D) -> Vector3` — Inversely transforms (multiplies) the Vector3 by the given Transform3D transformation matrix, under the assumption that the transformation basis is orthonormal (i.e. rotation/reflection is fine, scaling/skew is not).
- `operator *(right: Vector3) -> Vector3` — Multiplies each component of the Vector3 by the components of the given Vector3.
- `operator *(right: float) -> Vector3` — Multiplies each component of the Vector3 by the given float.
- `operator *(right: int) -> Vector3` — Multiplies each component of the Vector3 by the given int.
- `operator +(right: Vector3) -> Vector3` — Adds each component of the Vector3 by the components of the given Vector3.
- `operator -(right: Vector3) -> Vector3` — Subtracts each component of the Vector3 by the components of the given Vector3.
- `operator /(right: Vector3) -> Vector3` — Divides each component of the Vector3 by the components of the given Vector3.
- `operator /(right: float) -> Vector3` — Divides each component of the Vector3 by the given float.
- `operator /(right: int) -> Vector3` — Divides each component of the Vector3 by the given int.
- `operator <(right: Vector3) -> bool` — Compares two Vector3 vectors by first checking if the X value of the left vector is less than the X value of the `right` vector.
- `operator <=(right: Vector3) -> bool` — Compares two Vector3 vectors by first checking if the X value of the left vector is less than or equal to the X value of the `right` vector.
- `operator ==(right: Vector3) -> bool` — Returns `true` if the vectors are exactly equal.
- `operator >(right: Vector3) -> bool` — Compares two Vector3 vectors by first checking if the X value of the left vector is greater than the X value of the `right` vector.
- `operator >=(right: Vector3) -> bool` — Compares two Vector3 vectors by first checking if the X value of the left vector is greater than or equal to the X value of the `right` vector.
- `operator [](index: int) -> float` — Access vector components using their `index`.
- `operator unary+() -> Vector3` — Returns the same value as if the `+` was not there.
- `operator unary-() -> Vector3` — Returns the negative value of the Vector3.

## Enum Axis

- `AXIS_X = 0` — Enumerated value for the X axis.
- `AXIS_Y = 1` — Enumerated value for the Y axis.
- `AXIS_Z = 2` — Enumerated value for the Z axis.

## Constants

- `ZERO = Vector3(0, 0, 0)` — Zero vector, a vector with all components set to `0`.
- `ONE = Vector3(1, 1, 1)` — One vector, a vector with all components set to `1`.
- `INF = Vector3(inf, inf, inf)` — Infinity vector, a vector with all components set to `@GDScript.INF`.
- `LEFT = Vector3(-1, 0, 0)` — Left unit vector.
- `RIGHT = Vector3(1, 0, 0)` — Right unit vector.
- `UP = Vector3(0, 1, 0)` — Up unit vector.
- `DOWN = Vector3(0, -1, 0)` — Down unit vector.
- `FORWARD = Vector3(0, 0, -1)` — Forward unit vector.
- `BACK = Vector3(0, 0, 1)` — Back unit vector.
- `MODEL_LEFT = Vector3(1, 0, 0)` — Unit vector pointing towards the left side of imported 3D assets.
- `MODEL_RIGHT = Vector3(-1, 0, 0)` — Unit vector pointing towards the right side of imported 3D assets.
- `MODEL_TOP = Vector3(0, 1, 0)` — Unit vector pointing towards the top side (up) of imported 3D assets.
- `MODEL_BOTTOM = Vector3(0, -1, 0)` — Unit vector pointing towards the bottom side (down) of imported 3D assets.
- `MODEL_FRONT = Vector3(0, 0, 1)` — Unit vector pointing towards the front side (facing forward) of imported 3D assets.
- `MODEL_REAR = Vector3(0, 0, -1)` — Unit vector pointing towards the rear side (back) of imported 3D assets.
