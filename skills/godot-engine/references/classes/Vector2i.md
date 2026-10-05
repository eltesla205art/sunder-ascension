# Vector2i


A 2D vector using integer coordinates.

A 2-element structure that can be used to represent 2D grid coordinates or any other pair of integers. It uses integer coordinates and is therefore preferable to Vector2 when exact precision is required. Note that the values are limited to 32 bits, and unlike Vector2 this cannot be configured with an engine build option. Use int or PackedInt64Array if 64-bit values are needed.

## Properties

- `x: int` = `0` — The vector's X component.
- `y: int` = `0` — The vector's Y component.

## Constructors

- `Vector2i() -> Vector2i` — Constructs a default-initialized Vector2i with all components set to `0`.
- `Vector2i(from: Vector2i) -> Vector2i` — Constructs a Vector2i as a copy of the given Vector2i.
- `Vector2i(from: Vector2) -> Vector2i` — Constructs a new Vector2i from the given Vector2 by truncating components' fractional parts (rounding towards zero).
- `Vector2i(x: int, y: int) -> Vector2i` — Constructs a new Vector2i from the given `x` and `y`.

## Methods

- `abs() -> Vector2i` *const* — Returns a new vector with all components in absolute values (i.e. positive).
- `aspect() -> float` *const* — Returns the aspect ratio of this vector, the ratio of `x` to `y`.
- `clamp(min: Vector2i, max: Vector2i) -> Vector2i` *const* — Returns a new vector with all components clamped between the components of `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `clampi(min: int, max: int) -> Vector2i` *const* — Returns a new vector with all components clamped between `min` and `max`, by running `@GlobalScope.clamp` on each component.
- `distance_squared_to(to: Vector2i) -> int` *const* — Returns the squared Euclidean distance between this vector and `to`.
- `distance_to(to: Vector2i) -> float` *const* — Returns the Euclidean distance between this vector and `to`.
- `length() -> float` *const* — Returns the length (magnitude) of this vector.
- `length_squared() -> int` *const* — Returns the squared length (squared magnitude) of this vector.
- `max(with: Vector2i) -> Vector2i` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector2i(maxi(x, with.x), maxi(y, with.y))`.
- `max_axis_index() -> int` *const* — Returns the axis of the vector's highest value.
- `maxi(with: int) -> Vector2i` *const* — Returns the component-wise maximum of this and `with`, equivalent to `Vector2i(maxi(x, with), maxi(y, with))`.
- `min(with: Vector2i) -> Vector2i` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector2i(mini(x, with.x), mini(y, with.y))`.
- `min_axis_index() -> int` *const* — Returns the axis of the vector's lowest value.
- `mini(with: int) -> Vector2i` *const* — Returns the component-wise minimum of this and `with`, equivalent to `Vector2i(mini(x, with), mini(y, with))`.
- `sign() -> Vector2i` *const* — Returns a new vector with each component set to `1` if it's positive, `-1` if it's negative, and `0` if it's zero.
- `snapped(step: Vector2i) -> Vector2i` *const* — Returns a new vector with each component snapped to the closest multiple of the corresponding component in `step`.
- `snappedi(step: int) -> Vector2i` *const* — Returns a new vector with each component snapped to the closest multiple of `step`.

## Operators

- `operator !=(right: Vector2i) -> bool` — Returns `true` if the vectors are not equal.
- `operator %(right: Vector2i) -> Vector2i` — Gets the remainder of each component of the Vector2i with the components of the given Vector2i.
- `operator %(right: int) -> Vector2i` — Gets the remainder of each component of the Vector2i with the given int.
- `operator *(right: Vector2i) -> Vector2i` — Multiplies each component of the Vector2i by the components of the given Vector2i.
- `operator *(right: float) -> Vector2` — Multiplies each component of the Vector2i by the given float.
- `operator *(right: int) -> Vector2i` — Multiplies each component of the Vector2i by the given int.
- `operator +(right: Vector2i) -> Vector2i` — Adds each component of the Vector2i by the components of the given Vector2i.
- `operator -(right: Vector2i) -> Vector2i` — Subtracts each component of the Vector2i by the components of the given Vector2i.
- `operator /(right: Vector2i) -> Vector2i` — Divides each component of the Vector2i by the components of the given Vector2i.
- `operator /(right: float) -> Vector2` — Divides each component of the Vector2i by the given float.
- `operator /(right: int) -> Vector2i` — Divides each component of the Vector2i by the given int.
- `operator <(right: Vector2i) -> bool` — Compares two Vector2i vectors by first checking if the X value of the left vector is less than the X value of the `right` vector.
- `operator <=(right: Vector2i) -> bool` — Compares two Vector2i vectors by first checking if the X value of the left vector is less than or equal to the X value of the `right` vector.
- `operator ==(right: Vector2i) -> bool` — Returns `true` if the vectors are equal.
- `operator >(right: Vector2i) -> bool` — Compares two Vector2i vectors by first checking if the X value of the left vector is greater than the X value of the `right` vector.
- `operator >=(right: Vector2i) -> bool` — Compares two Vector2i vectors by first checking if the X value of the left vector is greater than or equal to the X value of the `right` vector.
- `operator [](index: int) -> int` — Access vector components using their `index`.
- `operator unary+() -> Vector2i` — Returns the same value as if the `+` was not there.
- `operator unary-() -> Vector2i` — Returns the negative value of the Vector2i.

## Enum Axis

- `AXIS_X = 0` — Enumerated value for the X axis.
- `AXIS_Y = 1` — Enumerated value for the Y axis.

## Constants

- `ZERO = Vector2i(0, 0)` — Zero vector, a vector with all components set to `0`.
- `ONE = Vector2i(1, 1)` — One vector, a vector with all components set to `1`.
- `MIN = Vector2i(-2147483648, -2147483648)` — Min vector, a vector with all components equal to `INT32_MIN`.
- `MAX = Vector2i(2147483647, 2147483647)` — Max vector, a vector with all components equal to `INT32_MAX`.
- `LEFT = Vector2i(-1, 0)` — Left unit vector.
- `RIGHT = Vector2i(1, 0)` — Right unit vector.
- `UP = Vector2i(0, -1)` — Up unit vector.
- `DOWN = Vector2i(0, 1)` — Down unit vector.
