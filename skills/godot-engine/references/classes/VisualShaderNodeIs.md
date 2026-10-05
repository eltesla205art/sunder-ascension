# VisualShaderNodeIs

**Inherits:** VisualShaderNode

A boolean comparison operator to be used within the visual shader graph.

Returns the boolean result of the comparison between `INF` or `NaN` and a scalar parameter.

## Properties

- `function: VisualShaderNodeIs.Function` = `0` — The comparison function.

## Enum Function

- `FUNC_IS_INF = 0` — Comparison with `INF` (Infinity).
- `FUNC_IS_NAN = 1` — Comparison with `NaN` (Not a Number; indicates invalid numeric results, such as division by zero).
- `FUNC_MAX = 2` — Represents the size of the `Function` enum.
