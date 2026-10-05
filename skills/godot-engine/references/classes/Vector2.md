# Vector2


A 2D vector using floating-point coordinates.

A 2-element structure that can be used to represent 2D coordinates or any other pair of numeric values. It uses floating-point coordinates. By default, these floating-point values use 32-bit precision, unlike float which is always 64-bit. If double precision is needed, compile the engine with the option `precision=double`.

## Properties

- `x: float` = `0.0` — The vector's X component.
- `y: float` = `0.0` — The vector's Y component.

## Constructors

- `Vector2() -> Vector2` — Constructs a default-initialized Vector2 with all components set to `0`.
- `Vector2(from: Vector2) -> Vector2` — Constructs a Vector2 as a copy of the given Vector2.
- `Vector2(from: Vector2i) -> Vector2` — Constructs a new Vector2 from Vector2i.
- `Vector2(x: float, y: float) -> Vector2` — Constructs a new Vector2 from the given `x` and `y`.

## Methods

- `abs() -> Vector2` *const* — Returns a new vector with all components in absolute values (i.e. positive).
- `angle() -> float` *const* — Returns this vector's angle with respect to the positive X axis, or `(1, 0)` vector, in radians.
- `angle_to(to: Vector2) -> float` *const* — Returns the signed angle to the given vector, in radians.
- `angle_to_point(to: Vector2) -> float` *const* — Returns the signed angle between the X axis and the line from this vector to point `to`, in radians.
- `aspect() -> float` *const* — Returns this vector's aspect ratio, which is `x` divided by `y`.
- `bezier_derivative(control_1: Vector2, control_2: Vector2, end: Vector2, t: float) -> Vector2` *const* — Returns the derivative at the given `t` on the Bézier curve defined by this vector and the given `control_1`, `control_2`, and `end` points.
- `bezier_interpolate(control_1: Vector2, control_2: Vector2, end: Vector2, t: float) -> Vector2` *const* — Returns the point at the given `t` on the Bézier curve defined by this vector and the given `control_1`, `control_2`, and `end` points.
- `bounce(n: Vector2) -> Vector2` *const* — Returns the vector "bounced off" from a line defined by the given normal `n` perpendicular to the line.
- `ceil() -> Vector2` *const* — Returns a new vector with all components rounded up (towards positive infinity).
- `clamp(min: Vector2, max: Vector2) -> Vector2` *const* — Returns a new vector with all components clamped between the components of `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `clampf(min: float, max: float) -> Vector2` *const* — Returns a new vector with all components clamped between `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `cross(with: Vector2) -> float` *const* — Returns the 2D analog of the cross product for this vector and `with`.
- `cubic_interpolate(b: Vector2, pre_a: Vector2, post_b: Vector2, weight: float) -> Vector2` *const* — Performs a cubic interpolation between this vector and `b` using `pre_a` and `post_b` as handles, and returns the result at position `weight`.
- `cubic_interpolate_in_time(b: Vector2, pre_a: Vector2, post_b: Vector2, weight: float, b_t: float, pre_a_t: float, post_b_t: float) -> Vector2` *const* — Performs a cubic interpolation between this vector and `b` using `pre_a` and `post_b` as handles, and returns the result at position `weight`.
- `direction_to(to: Vector2) -> Vector2` *const* — Returns the normalized vector pointing from this vector to `to`.
- `distance_squared_to(to: Vector2) -> float` *const* — Returns the squared Euclidean distance between this vector and `to`.
- `distance_to(to: Vector2) -> float` *const* — Returns the Euclidean distance between this vector and `to`.
- `dot(with: Vector2) -> float` *const* — Returns the dot product of this vector and `with`.
- `floor() -> Vector2` *const* — Returns a new vector with all components rounded down (towards negative infinity).
- `from_angle(angle: float) -> Vector2` *static* — Creates a Vector2 rotated to the given `angle` in radians.
- `inverse() -> Vector2` *const* — Returns the inverse of the vector.
- `is_equal_approx(to: Vector2) -> bool` *const* — Returns `true` if this vector and `to` are approximately equal, by running `@GlobalScope.is_equal_approx` on each component.
- `is_finite() -> bool` *const* — Returns `true` if this vector is finite, by calling `@GlobalScope.is_finite` on each component.
- `is_normalized() -> bool` *const* — Returns `true` if the vector is normalized, i.e. its length is approximately equal to 1.
- `is_zero_approx() -> bool` *const* — Returns `true` if this vector's values are approximately zero, by running `@GlobalScope.is_zero_approx` on each component.
- `length() -> float` *const* — Returns the length (magnitude) of this vector.
- `length_squared() -> float` *const* — Returns the squared length (squared magnitude) of this vector.
- `lerp(to: Vector2, weight: float) -> Vector2` *const* — Returns the result of the linear interpolation between this vector and `to` by amount `weight`.
- `limit_length(length: float = 1.0) -> Vector2` *const* — Returns the vector with a maximum length by limiting its length to `length`.
- `max(with: Vector2) -> Vector2` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector2(maxf(x, with.x), maxf(y, with.y))`.
- `max_axis_index() -> int` *const* — Returns the axis of the vector's highest value.
- `maxf(with: float) -> Vector2` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector2(maxf(x, with), maxf(y, with))`.
- `min(with: Vector2) -> Vector2` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector2(minf(x, with.x), minf(y, with.y))`.
- `min_axis_index() -> int` *const* — Returns the axis of the vector's lowest value.
- `minf(with: float) -> Vector2` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector2(minf(x, with), minf(y, with))`.
- `move_toward(to: Vector2, delta: float) -> Vector2` *const* — Returns a new vector moved toward `to` by the fixed `delta` amount.
- `normalized() -> Vector2` *const* — Returns the result of scaling the vector to unit length.
- `orthogonal() -> Vector2` *const* — Returns a perpendicular vector rotated 90 degrees counter-clockwise compared to the original, with the same length.
- `posmod(mod: float) -> Vector2` *const* — Returns a vector composed of the `@GlobalScope.fposmod` of this vector's components and `mod`.
- `posmodv(modv: Vector2) -> Vector2` *const* — Returns a vector composed of the `@GlobalScope.fposmod` of this vector's components and `modv`'s components.
- `project(b: Vector2) -> Vector2` *const* — Returns a new vector resulting from projecting this vector onto the given vector `b`.
- `reflect(line: Vector2) -> Vector2` *const* — Returns the result of reflecting the vector from a line defined by the given direction vector `line`.
- `rotated(angle: float) -> Vector2` *const* — Returns the result of rotating this vector by `angle` (in radians).
- `round() -> Vector2` *const* — Returns a new vector with all components rounded to the nearest integer, with halfway cases rounded away from zero.
- `sign() -> Vector2` *const* — Returns a new vector with each component set to `1.0` if it's positive, `-1.0` if it's negative, and `0.0` if it's zero.
- `slerp(to: Vector2, weight: float) -> Vector2` *const* — Returns the result of spherical linear interpolation between this vector and `to`, by amount `weight`.
- `slide(n: Vector2) -> Vector2` *const* — Returns a new vector resulting from sliding this vector along a line with normal `n`.
- `snapped(step: Vector2) -> Vector2` *const* — Returns a new vector with each component snapped to the nearest multiple of the corresponding component in `step`.
- `snappedf(step: float) -> Vector2` *const* — Returns a new vector with each component snapped to the nearest multiple of `step`.

## Operators

- `operator !=(right: Vector2) -> bool` — Returns `true` if the vectors are not equal.
- `operator *(right: Transform2D) -> Vector2` — Inversely transforms (multiplies) the Vector2 by the given Transform2D transformation matrix, under the assumption that the transformation basis is orthonormal (i.e. rotation/reflection is fine, scaling/skew is not).
- `operator *(right: Vector2) -> Vector2` — Multiplies each component of the Vector2 by the components of the given Vector2.
- `operator *(right: float) -> Vector2` — Multiplies each component of the Vector2 by the given float.
- `operator *(right: int) -> Vector2` — Multiplies each component of the Vector2 by the given int.
- `operator +(right: Vector2) -> Vector2` — Adds each component of the Vector2 by the components of the given Vector2.
- `operator -(right: Vector2) -> Vector2` — Subtracts each component of the Vector2 by the components of the given Vector2.
- `operator /(right: Vector2) -> Vector2` — Divides each component of the Vector2 by the components of the given Vector2.
- `operator /(right: float) -> Vector2` — Divides each component of the Vector2 by the given float.
- `operator /(right: int) -> Vector2` — Divides each component of the Vector2 by the given int.
- `operator <(right: Vector2) -> bool` — Compares two Vector2 vectors by first checking if the X value of the left vector is less than the X value of the `right` vector.
- `operator <=(right: Vector2) -> bool` — Compares two Vector2 vectors by first checking if the X value of the left vector is less than or equal to the X value of the `right` vector.
- `operator ==(right: Vector2) -> bool` — Returns `true` if the vectors are exactly equal.
- `operator >(right: Vector2) -> bool` — Compares two Vector2 vectors by first checking if the X value of the left vector is greater than the X value of the `right` vector.
- `operator >=(right: Vector2) -> bool` — Compares two Vector2 vectors by first checking if the X value of the left vector is greater than or equal to the X value of the `right` vector.
- `operator [](index: int) -> float` — Access vector components using their `index`.
- `operator unary+() -> Vector2` — Returns the same value as if the `+` was not there.
- `operator unary-() -> Vector2` — Returns the negative value of the Vector2.

## Enum Axis

- `AXIS_X = 0` — Enumerated value for the X axis.
- `AXIS_Y = 1` — Enumerated value for the Y axis.

## Constants

- `ZERO = Vector2(0, 0)` — Zero vector, a vector with all components set to `0`.
- `ONE = Vector2(1, 1)` — One vector, a vector with all components set to `1`.
- `INF = Vector2(inf, inf)` — Infinity vector, a vector with all components set to `@GDScript.INF`.
- `LEFT = Vector2(-1, 0)` — Left unit vector.
- `RIGHT = Vector2(1, 0)` — Right unit vector.
- `UP = Vector2(0, -1)` — Up unit vector.
- `DOWN = Vector2(0, 1)` — Down unit vector.
