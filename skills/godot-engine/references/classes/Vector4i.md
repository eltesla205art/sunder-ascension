# Vector4i


A 4D vector using integer coordinates.

A 4-element structure that can be used to represent 4D grid coordinates or any other quadruplet of integers. It uses integer coordinates and is therefore preferable to Vector4 when exact precision is required. Note that the values are limited to 32 bits, and unlike Vector4 this cannot be configured with an engine build option. Use int or PackedInt64Array if 64-bit values are needed.

## Properties

- `w: int` = `0` — The vector's W component.
- `x: int` = `0` — The vector's X component.
- `y: int` = `0` — The vector's Y component.
- `z: int` = `0` — The vector's Z component.

## Constructors

- `Vector4i() -> Vector4i` — Constructs a default-initialized Vector4i with all components set to `0`.
- `Vector4i(from: Vector4i) -> Vector4i` — Constructs a Vector4i as a copy of the given Vector4i.
- `Vector4i(from: Vector4) -> Vector4i` — Constructs a new Vector4i from the given Vector4 by truncating components' fractional parts (rounding towards zero).
- `Vector4i(x: int, y: int, z: int, w: int) -> Vector4i` — Returns a Vector4i with the given components.

## Methods

- `abs() -> Vector4i` *const* — Returns a new vector with all components in absolute values (i.e. positive).
- `clamp(min: Vector4i, max: Vector4i) -> Vector4i` *const* — Returns a new vector with all components clamped between the components of `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `clampi(min: int, max: int) -> Vector4i` *const* — Returns a new vector with all components clamped between `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `distance_squared_to(to: Vector4i) -> int` *const* — Returns the squared Euclidean distance between this vector and `to`.
- `distance_to(to: Vector4i) -> float` *const* — Returns the Euclidean distance between this vector and `to`.
- `length() -> float` *const* — Returns the length (magnitude) of this vector.
- `length_squared() -> int` *const* — Returns the squared length (squared magnitude) of this vector.
- `max(with: Vector4i) -> Vector4i` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector4i(maxi(x, with.x), maxi(y, with.y), maxi(z, with.z), maxi(w, with.w))`.
- `max_axis_index() -> int` *const* — Returns the axis of the vector's highest value.
- `maxi(with: int) -> Vector4i` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector4i(maxi(x, with), maxi(y, with), maxi(z, with), maxi(w, with))`.
- `min(with: Vector4i) -> Vector4i` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector4i(mini(x, with.x), mini(y, with.y), mini(z, with.z), mini(w, with.w))`.
- `min_axis_index() -> int` *const* — Returns the axis of the vector's lowest value.
- `mini(with: int) -> Vector4i` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector4i(mini(x, with), mini(y, with), mini(z, with), mini(w, with))`.
- `sign() -> Vector4i` *const* — Returns a new vector with each component set to `1` if it's positive, `-1` if it's negative, and `0` if it's zero.
- `snapped(step: Vector4i) -> Vector4i` *const* — Returns a new vector with each component snapped to the closest multiple of the corresponding component in `step`.
- `snappedi(step: int) -> Vector4i` *const* — Returns a new vector with each component snapped to the closest multiple of `step`.

## Operators

- `operator !=(right: Vector4i) -> bool` — Returns `true` if the vectors are not equal.
- `operator %(right: Vector4i) -> Vector4i` — Gets the remainder of each component of the Vector4i with the components of the given Vector4i.
- `operator %(right: int) -> Vector4i` — Gets the remainder of each component of the Vector4i with the given int.
- `operator *(right: Vector4i) -> Vector4i` — Multiplies each component of the Vector4i by the components of the given Vector4i.
- `operator *(right: float) -> Vector4` — Multiplies each component of the Vector4i by the given float.
- `operator *(right: int) -> Vector4i` — Multiplies each component of the Vector4i by the given int.
- `operator +(right: Vector4i) -> Vector4i` — Adds each component of the Vector4i by the components of the given Vector4i.
- `operator -(right: Vector4i) -> Vector4i` — Subtracts each component of the Vector4i by the components of the given Vector4i.
- `operator /(right: Vector4i) -> Vector4i` — Divides each component of the Vector4i by the components of the given Vector4i.
- `operator /(right: float) -> Vector4` — Divides each component of the Vector4i by the given float.
- `operator /(right: int) -> Vector4i` — Divides each component of the Vector4i by the given int.
- `operator <(right: Vector4i) -> bool` — Compares two Vector4i vectors by first checking if the X value of the left vector is less than the X value of the `right` vector.
- `operator <=(right: Vector4i) -> bool` — Compares two Vector4i vectors by first checking if the X value of the left vector is less than or equal to the X value of the `right` vector.
- `operator ==(right: Vector4i) -> bool` — Returns `true` if the vectors are exactly equal.
- `operator >(right: Vector4i) -> bool` — Compares two Vector4i vectors by first checking if the X value of the left vector is greater than the X value of the `right` vector.
- `operator >=(right: Vector4i) -> bool` — Compares two Vector4i vectors by first checking if the X value of the left vector is greater than or equal to the X value of the `right` vector.
- `operator [](index: int) -> int` — Access vector components using their `index`.
- `operator unary+() -> Vector4i` — Returns the same value as if the `+` was not there.
- `operator unary-() -> Vector4i` — Returns the negative value of the Vector4i.

## Enum Axis

- `AXIS_X = 0` — Enumerated value for the X axis.
- `AXIS_Y = 1` — Enumerated value for the Y axis.
- `AXIS_Z = 2` — Enumerated value for the Z axis.
- `AXIS_W = 3` — Enumerated value for the W axis.

## Constants

- `ZERO = Vector4i(0, 0, 0, 0)` — Zero vector, a vector with all components set to `0`.
- `ONE = Vector4i(1, 1, 1, 1)` — One vector, a vector with all components set to `1`.
- `MIN = Vector4i(-2147483648, -2147483648, -2147483648, -2147483648)` — Min vector, a vector with all components equal to `INT32_MIN`.
- `MAX = Vector4i(2147483647, 2147483647, 2147483647, 2147483647)` — Max vector, a vector with all components equal to `INT32_MAX`.
