# VisualShaderNodeUVFunc

**Inherits:** VisualShaderNode

Contains functions to modify texture coordinates (`uv`) to be used within the visual shader graph.

UV functions are similar to Vector2 functions, but the input port of this node uses the shader's UV value by default.

## Properties

- `function: VisualShaderNodeUVFunc.Function` = `0` — A function to be applied to the texture coordinates.

## Enum Function

- `FUNC_PANNING = 0` — Translates `uv` by using `scale` and `offset` values using the following formula: `uv = uv + offset * scale`.
- `FUNC_SCALING = 1` — Scales `uv` by using `scale` and `pivot` values using the following formula: `uv = (uv - pivot) * scale + pivot`.
- `FUNC_MAX = 2` — Represents the size of the `Function` enum.
