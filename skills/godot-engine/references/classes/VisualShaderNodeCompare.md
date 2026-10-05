# VisualShaderNodeCompare

**Inherits:** VisualShaderNode

A comparison function for common types within the visual shader graph.

Compares `a` and `b` of `type` by `function`. Returns a boolean scalar. Translates to `if` instruction in shader code.

## Properties

- `condition: VisualShaderNodeCompare.Condition` = `0` — Extra condition which is applied if `type` is set to `CTYPE_VECTOR_3D`.
- `function: VisualShaderNodeCompare.Function` = `0` — A comparison function.
- `type: VisualShaderNodeCompare.ComparisonType` = `0` — The type to be used in the comparison.

## Enum ComparisonType

- `CTYPE_SCALAR = 0` — A floating-point scalar.
- `CTYPE_SCALAR_INT = 1` — An integer scalar.
- `CTYPE_SCALAR_UINT = 2` — An unsigned integer scalar.
- `CTYPE_VECTOR_2D = 3` — A 2D vector type.
- `CTYPE_VECTOR_3D = 4` — A 3D vector type.
- `CTYPE_VECTOR_4D = 5` — A 4D vector type.
- `CTYPE_BOOLEAN = 6` — A boolean type.
- `CTYPE_TRANSFORM = 7` — A transform (`mat4`) type.
- `CTYPE_MAX = 8` — Represents the size of the `ComparisonType` enum.

## Enum Function

- `FUNC_EQUAL = 0` — Comparison for equality (`a == b`).
- `FUNC_NOT_EQUAL = 1` — Comparison for inequality (`a != b`).
- `FUNC_GREATER_THAN = 2` — Comparison for greater than (`a > b`).
- `FUNC_GREATER_THAN_EQUAL = 3` — Comparison for greater than or equal (`a >= b`).
- `FUNC_LESS_THAN = 4` — Comparison for less than (`a < b`).
- `FUNC_LESS_THAN_EQUAL = 5` — Comparison for less than or equal (`a <= b`).
- `FUNC_MAX = 6` — Represents the size of the `Function` enum.

## Enum Condition

- `COND_ALL = 0` — The result will be `true` if all components in the vector satisfy the comparison condition.
- `COND_ANY = 1` — The result will be `true` if any component in the vector satisfies the comparison condition.
- `COND_MAX = 2` — Represents the size of the `Condition` enum.
