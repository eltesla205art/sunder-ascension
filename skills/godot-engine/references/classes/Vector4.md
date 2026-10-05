# Vector4


A 4D vector using floating-point coordinates.

A 4-element structure that can be used to represent 4D coordinates or any other quadruplet of numeric values. It uses floating-point coordinates. By default, these floating-point values use 32-bit precision, unlike float which is always 64-bit. If double precision is needed, compile the engine with the option `precision=double`.

## Properties

- `w: float` = `0.0` — The vector's W component.
- `x: float` = `0.0` — The vector's X component.
- `y: float` = `0.0` — The vector's Y component.
- `z: float` = `0.0` — The vector's Z component.

## Constructors

- `Vector4() -> Vector4` — Constructs a default-initialized Vector4 with all components set to `0`.
- `Vector4(from: Vector4) -> Vector4` — Constructs a Vector4 as a copy of the given Vector4.
- `Vector4(from: Vector4i) -> Vector4` — Constructs a new Vector4 from the given Vector4i.
- `Vector4(x: float, y: float, z: float, w: float) -> Vector4` — Returns a Vector4 with the given components.

## Methods

- `abs() -> Vector4` *const* — Returns a new vector with all components in absolute values (i.e. positive).
- `ceil() -> Vector4` *const* — Returns a new vector with all components rounded up (towards positive infinity).
- `clamp(min: Vector4, max: Vector4) -> Vector4` *const* — Returns a new vector with all components clamped between the components of `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `clampf(min: float, max: float) -> Vector4` *const* — Returns a new vector with all components clamped between `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `cubic_interpolate(b: Vector4, pre_a: Vector4, post_b: Vector4, weight: float) -> Vector4` *const* — Performs a cubic interpolation between this vector and `b` using `pre_a` and `post_b` as handles, and returns the result at position `weight`.
- `cubic_interpolate_in_time(b: Vector4, pre_a: Vector4, post_b: Vector4, weight: float, b_t: float, pre_a_t: float, post_b_t: float) -> Vector4` *const* — Performs a cubic interpolation between this vector and `b` using `pre_a` and `post_b` as handles, and returns the result at position `weight`.
- `direction_to(to: Vector4) -> Vector4` *const* — Returns the normalized vector pointing from this vector to `to`.
- `distance_squared_to(to: Vector4) -> float` *const* — Returns the squared Euclidean distance between this vector and `to`.
- `distance_to(to: Vector4) -> float` *const* — Returns the Euclidean distance between this vector and `to`.
- `dot(with: Vector4) -> float` *const* — Returns the dot product of this vector and `with`.
- `floor() -> Vector4` *const* — Returns a new vector with all components rounded down (towards negative infinity).
- `inverse() -> Vector4` *const* — Returns the inverse of the vector.
- `is_equal_approx(to: Vector4) -> bool` *const* — Returns `true` if this vector and `to` are approximately equal, by running `@GlobalScope.is_equal_approx` on each component.
- `is_finite() -> bool` *const* — Returns `true` if this vector is finite, by calling `@GlobalScope.is_finite` on each component.
- `is_normalized() -> bool` *const* — Returns `true` if the vector is normalized, i.e. its length is approximately equal to 1.
- `is_zero_approx() -> bool` *const* — Returns `true` if this vector's values are approximately zero, by running `@GlobalScope.is_zero_approx` on each component.
- `length() -> float` *const* — Returns the length (magnitude) of this vector.
- `length_squared() -> float` *const* — Returns the squared length (squared magnitude) of this vector.
- `lerp(to: Vector4, weight: float) -> Vector4` *const* — Returns the result of the linear interpolation between this vector and `to` by amount `weight`.
- `max(with: Vector4) -> Vector4` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector4(maxf(x, with.x), maxf(y, with.y), maxf(z, with.z), maxf(w, with.w))`.
- `max_axis_index() -> int` *const* — Returns the axis of the vector's highest value.
- `maxf(with: float) -> Vector4` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector4(maxf(x, with), maxf(y, with), maxf(z, with), maxf(w, with))`.
- `min(with: Vector4) -> Vector4` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector4(minf(x, with.x), minf(y, with.y), minf(z, with.z), minf(w, with.w))`.
- `min_axis_index() -> int` *const* — Returns the axis of the vector's lowest value.
- `minf(with: float) -> Vector4` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector4(minf(x, with), minf(y, with), minf(z, with), minf(w, with))`.
- `normalized() -> Vector4` *const* — Returns the result of scaling the vector to unit length.
- `posmod(mod: float) -> Vector4` *const* — Returns a vector composed of the `@GlobalScope.fposmod` of this vector's components and `mod`.
- `posmodv(modv: Vector4) -> Vector4` *const* — Returns a vector composed of the `@GlobalScope.fposmod` of this vector's components and `modv`'s components.
- `round() -> Vector4` *const* — Returns a new vector with all components rounded to the nearest integer, with halfway cases rounded away from zero.
- `sign() -> Vector4` *const* — Returns a new vector with each component set to `1.0` if it's positive, `-1.0` if it's negative, and `0.0` if it's zero.
- `snapped(step: Vector4) -> Vector4` *const* — Returns a new vector with each component snapped to the nearest multiple of the corresponding component in `step`.
- `snappedf(step: float) -> Vector4` *const* — Returns a new vector with each component snapped to the nearest multiple of `step`.

## Operators

- `operator !=(right: Vector4) -> bool` — Returns `true` if the vectors are not equal.
- `operator *(right: Projection) -> Vector4` — Transforms (multiplies) the Vector4 by the transpose of the given Projection matrix.
- `operator *(right: Vector4) -> Vector4` — Multiplies each component of the Vector4 by the components of the given Vector4.
- `operator *(right: float) -> Vector4` — Multiplies each component of the Vector4 by the given float.
- `operator *(right: int) -> Vector4` — Multiplies each component of the Vector4 by the given int.
- `operator +(right: Vector4) -> Vector4` — Adds each component of the Vector4 by the components of the given Vector4.
- `operator -(right: Vector4) -> Vector4` — Subtracts each component of the Vector4 by the components of the given Vector4.
- `operator /(right: Vector4) -> Vector4` — Divides each component of the Vector4 by the components of the given Vector4.
- `operator /(right: float) -> Vector4` — Divides each component of the Vector4 by the given float.
- `operator /(right: int) -> Vector4` — Divides each component of the Vector4 by the given int.
- `operator <(right: Vector4) -> bool` — Compares two Vector4 vectors by first checking if the X value of the left vector is less than the X value of the `right` vector.
- `operator <=(right: Vector4) -> bool` — Compares two Vector4 vectors by first checking if the X value of the left vector is less than or equal to the X value of the `right` vector.
- `operator ==(right: Vector4) -> bool` — Returns `true` if the vectors are exactly equal.
- `operator >(right: Vector4) -> bool` — Compares two Vector4 vectors by first checking if the X value of the left vector is greater than the X value of the `right` vector.
- `operator >=(right: Vector4) -> bool` — Compares two Vector4 vectors by first checking if the X value of the left vector is greater than or equal to the X value of the `right` vector.
- `operator [](index: int) -> float` — Access vector components using their `index`.
- `operator unary+() -> Vector4` — Returns the same value as if the `+` was not there.
- `operator unary-() -> Vector4` — Returns the negative value of the Vector4.

## Enum Axis

- `AXIS_X = 0` — Enumerated value for the X axis.
- `AXIS_Y = 1` — Enumerated value for the Y axis.
- `AXIS_Z = 2` — Enumerated value for the Z axis.
- `AXIS_W = 3` — Enumerated value for the W axis.

## Constants

- `ZERO = Vector4(0, 0, 0, 0)` — Zero vector, a vector with all components set to `0`.
- `ONE = Vector4(1, 1, 1, 1)` — One vector, a vector with all components set to `1`.
- `INF = Vector4(inf, inf, inf, inf)` — Infinity vector, a vector with all components set to `@GDScript.INF`.
