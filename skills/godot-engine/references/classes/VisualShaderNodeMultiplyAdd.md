# VisualShaderNodeMultiplyAdd

**Inherits:** VisualShaderNode

Performs a fused multiply-add operation within the visual shader graph.

Uses three operands to compute `(a * b + c)` expression.

## Properties

- `op_type: VisualShaderNodeMultiplyAdd.OpType` = `0` — A type of operands and returned value.

## Enum OpType

- `OP_TYPE_SCALAR = 0` — A floating-point scalar type.
- `OP_TYPE_VECTOR_2D = 1` — A 2D vector type.
- `OP_TYPE_VECTOR_3D = 2` — A 3D vector type.
- `OP_TYPE_VECTOR_4D = 3` — A 4D vector type.
- `OP_TYPE_MAX = 4` — Represents the size of the `OpType` enum.
