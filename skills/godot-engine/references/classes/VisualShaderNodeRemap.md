# VisualShaderNodeRemap

**Inherits:** VisualShaderNode

A visual shader node for remap function.

Remap will transform the input range into output range, e.g. you can change a `0..1` value to `-2..2` etc. See `@GlobalScope.remap` for more details.

## Properties

- `op_type: VisualShaderNodeRemap.OpType` = `0` — 

## Enum OpType

- `OP_TYPE_SCALAR = 0` — A floating-point scalar type.
- `OP_TYPE_VECTOR_2D = 1` — A 2D vector type.
- `OP_TYPE_VECTOR_2D_SCALAR = 2` — The `value` port uses a 2D vector type, while the `input min`, `input max`, `output min`, and `output max` ports use a floating-point scalar type.
- `OP_TYPE_VECTOR_3D = 3` — A 3D vector type.
- `OP_TYPE_VECTOR_3D_SCALAR = 4` — The `value` port uses a 3D vector type, while the `input min`, `input max`, `output min`, and `output max` ports use a floating-point scalar type.
- `OP_TYPE_VECTOR_4D = 5` — A 4D vector type.
- `OP_TYPE_VECTOR_4D_SCALAR = 6` — The `value` port uses a 4D vector type, while the `input min`, `input max`, `output min`, and `output max` ports use a floating-point scalar type.
- `OP_TYPE_MAX = 7` — Represents the size of the `OpType` enum.
