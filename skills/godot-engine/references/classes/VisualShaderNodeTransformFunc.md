# VisualShaderNodeTransformFunc

**Inherits:** VisualShaderNode

Computes a Transform3D function within the visual shader graph.

Computes an inverse or transpose function on the provided Transform3D.

## Properties

- `function: VisualShaderNodeTransformFunc.Function` = `0` — The function to be computed.

## Enum Function

- `FUNC_INVERSE = 0` — Perform the inverse operation on the Transform3D matrix.
- `FUNC_TRANSPOSE = 1` — Perform the transpose operation on the Transform3D matrix.
- `FUNC_MAX = 2` — Represents the size of the `Function` enum.
