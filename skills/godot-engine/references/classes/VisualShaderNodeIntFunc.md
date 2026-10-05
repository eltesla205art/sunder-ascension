# VisualShaderNodeIntFunc

**Inherits:** VisualShaderNode

A scalar integer function to be used within the visual shader graph.

Accept an integer scalar (`x`) to the input port and transform it according to `function`.

## Properties

- `function: VisualShaderNodeIntFunc.Function` = `2` — A function to be applied to the scalar.

## Enum Function

- `FUNC_ABS = 0` — Returns the absolute value of the parameter.
- `FUNC_NEGATE = 1` — Negates the `x` using `-(x)`.
- `FUNC_SIGN = 2` — Extracts the sign of the parameter.
- `FUNC_BITWISE_NOT = 3` — Returns the result of bitwise `NOT` operation on the integer.
- `FUNC_MAX = 4` — Represents the size of the `Function` enum.
