# Vector3i


A 3D vector using integer coordinates.

A 3-element structure that can be used to represent 3D grid coordinates or any other triplet of integers. It uses integer coordinates and is therefore preferable to Vector3 when exact precision is required. Note that the values are limited to 32 bits, and unlike Vector3 this cannot be configured with an engine build option. Use int or PackedInt64Array if 64-bit values are needed.

## Properties

- `x: int` = `0` — The vector's X component.
- `y: int` = `0` — The vector's Y component.
- `z: int` = `0` — The vector's Z component.

## Constructors

- `Vector3i() -> Vector3i` — Constructs a default-initialized Vector3i with all components set to `0`.
- `Vector3i(from: Vector3i) -> Vector3i` — Constructs a Vector3i as a copy of the given Vector3i.
- `Vector3i(from: Vector3) -> Vector3i` — Constructs a new Vector3i from the given Vector3 by truncating components' fractional parts (rounding towards zero).
- `Vector3i(x: int, y: int, z: int) -> Vector3i` — Returns a Vector3i with the given components.

## Methods

- `abs() -> Vector3i` *const* — Returns a new vector with all components in absolute values (i.e. positive).
- `clamp(min: Vector3i, max: Vector3i) -> Vector3i` *const* — Returns a new vector with all components clamped between the components of `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `clampi(min: int, max: int) -> Vector3i` *const* — Returns a new vector with all components clamped between `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `distance_squared_to(to: Vector3i) -> int` *const* — Returns the squared Euclidean distance between this vector and `to`.
- `distance_to(to: Vector3i) -> float` *const* — Returns the Euclidean distance between this vector and `to`.
- `length() -> float` *const* — Returns the length (magnitude) of this vector.
- `length_squared() -> int` *const* — Returns the squared length (squared magnitude) of this vector.
- `max(with: Vector3i) -> Vector3i` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector3i(maxi(x, with.x), maxi(y, with.y), maxi(z, with.z))`.
- `max_axis_index() -> int` *const* — Returns the axis of the vector's highest value.
- `maxi(with: int) -> Vector3i` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector3i(maxi(x, with), maxi(y, with), maxi(z, with))`.
- `min(with: Vector3i) -> Vector3i` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector3i(mini(x, with.x), mini(y, with.y), mini(z, with.z))`.
- `min_axis_index() -> int` *const* — Returns the axis of the vector's lowest value.
- `mini(with: int) -> Vector3i` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector3i(mini(x, with), mini(y, with), mini(z, with))`.
- `sign() -> Vector3i` *const* — Returns a new vector with each component set to `1` if it's positive, `-1` if it's negative, and `0` if it's zero.
- `snapped(step: Vector3i) -> Vector3i` *const* — Returns a new vector with each component snapped to the closest multiple of the corresponding component in `step`.
- `snappedi(step: int) -> Vector3i` *const* — Returns a new vector with each component snapped to the closest multiple of `step`.

## Operators

- `operator !=(right: Vector3i) -> bool` — Returns `true` if the vectors are not equal.
- `operator %(right: Vector3i) -> Vector3i` — Gets the remainder of each component of the Vector3i with the components of the given Vector3i.
- `operator %(right: int) -> Vector3i` — Gets the remainder of each component of the Vector3i with the given int.
- `operator *(right: Vector3i) -> Vector3i` — Multiplies each component of the Vector3i by the components of the given Vector3i.
- `operator *(right: float) -> Vector3` — Multiplies each component of the Vector3i by the given float.
- `operator *(right: int) -> Vector3i` — Multiplies each component of the Vector3i by the given int.
- `operator +(right: Vector3i) -> Vector3i` — Adds each component of the Vector3i by the components of the given Vector3i.
- `operator -(right: Vector3i) -> Vector3i` — Subtracts each component of the Vector3i by the components of the given Vector3i.
- `operator /(right: Vector3i) -> Vector3i` — Divides each component of the Vector3i by the components of the given Vector3i.
- `operator /(right: float) -> Vector3` — Divides each component of the Vector3i by the given float.
- `operator /(right: int) -> Vector3i` — Divides each component of the Vector3i by the given int.
- `operator <(right: Vector3i) -> bool` — Compares two Vector3i vectors by first checking if the X value of the left vector is less than the X value of the `right` vector.
- `operator <=(right: Vector3i) -> bool` — Compares two Vector3i vectors by first checking if the X value of the left vector is less than or equal to the X value of the `right` vector.
- `operator ==(right: Vector3i) -> bool` — Returns `true` if the vectors are equal.
- `operator >(right: Vector3i) -> bool` — Compares two Vector3i vectors by first checking if the X value of the left vector is greater than the X value of the `right` vector.
- `operator >=(right: Vector3i) -> bool` — Compares two Vector3i vectors by first checking if the X value of the left vector is greater than or equal to the X value of the `right` vector.
- `operator [](index: int) -> int` — Access vector components using their `index`.
- `operator unary+() -> Vector3i` — Returns the same value as if the `+` was not there.
- `operator unary-() -> Vector3i` — Returns the negative value of the Vector3i.

## Enum Axis

- `AXIS_X = 0` — Enumerated value for the X axis.
- `AXIS_Y = 1` — Enumerated value for the Y axis.
- `AXIS_Z = 2` — Enumerated value for the Z axis.

## Constants

- `ZERO = Vector3i(0, 0, 0)` — Zero vector, a vector with all components set to `0`.
- `ONE = Vector3i(1, 1, 1)` — One vector, a vector with all components set to `1`.
- `MIN = Vector3i(-2147483648, -2147483648, -2147483648)` — Min vector, a vector with all components equal to `INT32_MIN`.
- `MAX = Vector3i(2147483647, 2147483647, 2147483647)` — Max vector, a vector with all components equal to `INT32_MAX`.
- `LEFT = Vector3i(-1, 0, 0)` — Left unit vector.
- `RIGHT = Vector3i(1, 0, 0)` — Right unit vector.
- `UP = Vector3i(0, 1, 0)` — Up unit vector.
- `DOWN = Vector3i(0, -1, 0)` — Down unit vector.
- `FORWARD = Vector3i(0, 0, -1)` — Forward unit vector.
- `BACK = Vector3i(0, 0, 1)` — Back unit vector.
