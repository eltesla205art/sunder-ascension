# VisualShaderNodeUIntFunc

**Inherits:** VisualShaderNode

An unsigned scalar integer function to be used within the visual shader graph.

Accept an unsigned integer scalar (`x`) to the input port and transform it according to `function`.

## Properties

- `function: VisualShaderNodeUIntFunc.Function` = `0` — A function to be applied to the scalar.

## Enum Function

- `FUNC_NEGATE = 0` — Negates the `x` using `-(x)`.
- `FUNC_BITWISE_NOT = 1` — Returns the result of bitwise `NOT` operation on the integer.
- `FUNC_MAX = 2` — Represents the size of the `Function` enum.
