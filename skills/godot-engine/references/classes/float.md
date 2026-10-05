# float


A built-in type for floating-point numbers.

The float built-in type is a 64-bit double-precision floating-point number, equivalent to `double` in C++. This type has 14 reliable decimal digits of precision. The maximum value of float is approximately `1.79769e308`, and the minimum is approximately `-1.79769e308`. Many methods and properties in the engine use 32-bit single-precision floating-point numbers instead, equivalent to `float` in C++, which have 6 reliable decimal digits of precision.

## Constructors

- `float() -> float` — Constructs a default-initialized float set to `0.0`.
- `float(from: float) -> float` — Constructs a float as a copy of the given float.
- `float(from: String) -> float` — Converts a String to a float, following the same rules as `String.to_float`.
- `float(from: bool) -> float` — Cast a bool value to a floating-point value, `float(true)` will be equal to 1.0 and `float(false)` will be equal to 0.0.
- `float(from: int) -> float` — Cast an int value to a floating-point value, `float(1)` will be equal to `1.0`.

## Operators

- `operator !=(right: float) -> bool` — Returns `true` if two floats are different from each other.
- `operator !=(right: int) -> bool` — Returns `true` if the integer has different value than the float.
- `operator *(right: Color) -> Color` — Multiplies each component of the Color, including the alpha, by the given float.
- `operator *(right: Quaternion) -> Quaternion` — Multiplies each component of the Quaternion by the given float.
- `operator *(right: Vector2) -> Vector2` — Multiplies each component of the Vector2 by the given float.
- `operator *(right: Vector2i) -> Vector2` — Multiplies each component of the Vector2i by the given float.
- `operator *(right: Vector3) -> Vector3` — Multiplies each component of the Vector3 by the given float.
- `operator *(right: Vector3i) -> Vector3` — Multiplies each component of the Vector3i by the given float.
- `operator *(right: Vector4) -> Vector4` — Multiplies each component of the Vector4 by the given float.
- `operator *(right: Vector4i) -> Vector4` — Multiplies each component of the Vector4i by the given float.
- `operator *(right: float) -> float` — Multiplies two floats.
- `operator *(right: int) -> float` — Multiplies a float and an int.
- `operator **(right: float) -> float` — Raises a float to a power of a float.
- `operator **(right: int) -> float` — Raises a float to a power of an int.
- `operator +(right: float) -> float` — Adds two floats.
- `operator +(right: int) -> float` — Adds a float and an int.
- `operator -(right: float) -> float` — Subtracts a float from a float.
- `operator -(right: int) -> float` — Subtracts an int from a float.
- `operator /(right: float) -> float` — Divides two floats.
- `operator /(right: int) -> float` — Divides a float by an int.
- `operator <(right: float) -> bool` — Returns `true` if the left float is less than the right one.
- `operator <(right: int) -> bool` — Returns `true` if this float is less than the given int.
- `operator <=(right: float) -> bool` — Returns `true` if the left float is less than or equal to the right one.
- `operator <=(right: int) -> bool` — Returns `true` if this float is less than or equal to the given int.
- `operator ==(right: float) -> bool` — Returns `true` if both floats are exactly equal.
- `operator ==(right: int) -> bool` — Returns `true` if the float and the given int are equal.
- `operator >(right: float) -> bool` — Returns `true` if the left float is greater than the right one.
- `operator >(right: int) -> bool` — Returns `true` if this float is greater than the given int.
- `operator >=(right: float) -> bool` — Returns `true` if the left float is greater than or equal to the right one.
- `operator >=(right: int) -> bool` — Returns `true` if this float is greater than or equal to the given int.
- `operator unary+() -> float` — Returns the same value as if the `+` was not there.
- `operator unary-() -> float` — Returns the negative value of the float.
