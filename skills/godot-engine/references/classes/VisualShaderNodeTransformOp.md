# VisualShaderNodeTransformOp

**Inherits:** VisualShaderNode

A Transform3D operator to be used within the visual shader graph.

Applies `operator` to two transform (4×4 matrices) inputs.

## Properties

- `operator: VisualShaderNodeTransformOp.Operator` = `0` — The type of the operation to be performed on the transforms.

## Enum Operator

- `OP_AxB = 0` — Multiplies transform `a` by the transform `b`.
- `OP_BxA = 1` — Multiplies transform `b` by the transform `a`.
- `OP_AxB_COMP = 2` — Performs a component-wise multiplication of transform `a` by the transform `b`.
- `OP_BxA_COMP = 3` — Performs a component-wise multiplication of transform `b` by the transform `a`.
- `OP_ADD = 4` — Adds two transforms.
- `OP_A_MINUS_B = 5` — Subtracts the transform `a` from the transform `b`.
- `OP_B_MINUS_A = 6` — Subtracts the transform `b` from the transform `a`.
- `OP_A_DIV_B = 7` — Divides the transform `a` by the transform `b`.
- `OP_B_DIV_A = 8` — Divides the transform `b` by the transform `a`.
- `OP_MAX = 9` — Represents the size of the `Operator` enum.
