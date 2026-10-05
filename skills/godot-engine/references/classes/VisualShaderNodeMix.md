# VisualShaderNodeMix

**Inherits:** VisualShaderNode

Linearly interpolates between two values within the visual shader graph.

Translates to `mix(a, b, weight)` in the shader language.

## Properties

- `op_type: VisualShaderNodeMix.OpType` = `0` — A type of operands and returned value.

## Enum OpType

- `OP_TYPE_SCALAR = 0` — A floating-point scalar.
- `OP_TYPE_VECTOR_2D = 1` — A 2D vector type.
- `OP_TYPE_VECTOR_2D_SCALAR = 2` — The `a` and `b` ports use a 2D vector type.
- `OP_TYPE_VECTOR_3D = 3` — A 3D vector type.
- `OP_TYPE_VECTOR_3D_SCALAR = 4` — The `a` and `b` ports use a 3D vector type.
- `OP_TYPE_VECTOR_4D = 5` — A 4D vector type.
- `OP_TYPE_VECTOR_4D_SCALAR = 6` — The `a` and `b` ports use a 4D vector type.
- `OP_TYPE_MAX = 7` — Represents the size of the `OpType` enum.
