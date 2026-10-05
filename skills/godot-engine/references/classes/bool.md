# bool


A built-in boolean type.

The bool is a built-in Variant type that may only store one of two values: `true` or `false`. You can imagine it as a switch that can be either turned on or off, or as a binary digit that can either be 1 or 0. Booleans can be directly used in `if`, and other conditional statements:  All comparison operators return booleans (`==`, `>`, `<=`, etc.). As such, it is not necessary to compare booleans themselves.

## Constructors

- `bool() -> bool` — Constructs a bool set to `false`.
- `bool(from: bool) -> bool` — Constructs a bool as a copy of the given bool.
- `bool(from: float) -> bool` — Casts a float value to a bool.
- `bool(from: int) -> bool` — Casts an int value to a bool.

## Operators

- `operator !=(right: bool) -> bool` — Returns `true` if one bool is `true` and the other bool is `false`.
- `operator <(right: bool) -> bool` — Returns `true` if the left bool is `false` and `right` is `true`.
- `operator <=(right: bool) -> bool` — Returns `true` if the left bool is `false`, or if both bools are `true`.
- `operator ==(right: bool) -> bool` — Returns `true` if both bools are `true`, or if both bools are `false`.
- `operator >(right: bool) -> bool` — Returns `true` if the left bool is `true` and `right` is `false`.
- `operator >=(right: bool) -> bool` — Returns `true` if the left bool is `true`, or if both bools are `false`.
