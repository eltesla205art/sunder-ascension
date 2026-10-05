# int


A built-in type for integers.

Signed 64-bit integer type. This means that it can take values from `-2^63` to `2^63 - 1`, i.e. from `-9223372036854775808` to `9223372036854775807`. When it exceeds these bounds, it will wrap around. ints can be automatically converted to floats when necessary, for example when passing them as arguments in functions. The float will be as close to the original integer as possible.

## Constructors

- `int() -> int` — Constructs an int set to `0`.
- `int(from: int) -> int` — Constructs an int as a copy of the given int.
- `int(from: String) -> int` — Constructs a new int from a String, following the same rules as `String.to_int`.
- `int(from: bool) -> int` — Constructs a new int from a bool.
- `int(from: float) -> int` — Constructs a new int from a float.

## Operators

- `operator !=(right: float) -> bool` — Returns `true` if the int is not equivalent to the float.
- `operator !=(right: int) -> bool` — Returns `true` if the ints are not equal.
- `operator %(right: int) -> int` — Returns the remainder after dividing two ints.
- `operator &(right: int) -> int` — Performs the bitwise `AND` operation.
- `operator *(right: Color) -> Color` — Multiplies each component of the Color by the int.
- `operator *(right: Quaternion) -> Quaternion` — Multiplies each component of the Quaternion by the int.
- `operator *(right: Vector2) -> Vector2` — Multiplies each component of the Vector2 by the int.
- `operator *(right: Vector2i) -> Vector2i` — Multiplies each component of the Vector2i by the int.
- `operator *(right: Vector3) -> Vector3` — Multiplies each component of the Vector3 by the int.
- `operator *(right: Vector3i) -> Vector3i` — Multiplies each component of the Vector3i by the int.
- `operator *(right: Vector4) -> Vector4` — Multiplies each component of the Vector4 by the int.
- `operator *(right: Vector4i) -> Vector4i` — Multiplies each component of the Vector4i by the int.
- `operator *(right: float) -> float` — Multiplies the float by the int.
- `operator *(right: int) -> int` — Multiplies the two ints.
- `operator **(right: float) -> float` — Raises an int to a power of a float.
- `operator **(right: int) -> int` — Raises the left int to a power of the right int.
- `operator +(right: float) -> float` — Adds the int and the float.
- `operator +(right: int) -> int` — Adds the two ints.
- `operator -(right: float) -> float` — Subtracts the float from the int.
- `operator -(right: int) -> int` — Subtracts the two ints.
- `operator /(right: float) -> float` — Divides the int by the float.
- `operator /(right: int) -> int` — Divides the two ints.
- `operator <(right: float) -> bool` — Returns `true` if the int is less than the float.
- `operator <(right: int) -> bool` — Returns `true` if the left int is less than the right int.
- `operator <<(right: int) -> int` — Performs the bitwise shift left operation.
- `operator <=(right: float) -> bool` — Returns `true` if the int is less than or equal to the float.
- `operator <=(right: int) -> bool` — Returns `true` if the left int is less than or equal to the right int.
- `operator ==(right: float) -> bool` — Returns `true` if the int is equal to the float.
- `operator ==(right: int) -> bool` — Returns `true` if the two ints are equal.
- `operator >(right: float) -> bool` — Returns `true` if the int is greater than the float.
- `operator >(right: int) -> bool` — Returns `true` if the left int is greater than the right int.
- `operator >=(right: float) -> bool` — Returns `true` if the int is greater than or equal to the float.
- `operator >=(right: int) -> bool` — Returns `true` if the left int is greater than or equal to the right int.
- `operator >>(right: int) -> int` — Performs the bitwise shift right operation.
- `operator ^(right: int) -> int` — Performs the bitwise `XOR` operation.
- `operator unary+() -> int` — Returns the same value as if the `+` was not there.
- `operator unary-() -> int` — Returns the negated value of the int.
- `operator |(right: int) -> int` — Performs the bitwise `OR` operation.
- `operator ~() -> int` — Performs the bitwise `NOT` operation on the int.
