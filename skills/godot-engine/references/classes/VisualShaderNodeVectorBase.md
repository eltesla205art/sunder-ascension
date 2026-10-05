# VisualShaderNodeVectorBase

**Inherits:** VisualShaderNode

A base type for the nodes that perform vector operations within the visual shader graph.

This is an abstract class. See the derived types for descriptions of the possible operations.

## Properties

- `op_type: VisualShaderNodeVectorBase.OpType` = `1` — A vector type that this operation is performed on.

## Enum OpType

- `OP_TYPE_VECTOR_2D = 0` — A 2D vector type.
- `OP_TYPE_VECTOR_3D = 1` — A 3D vector type.
- `OP_TYPE_VECTOR_4D = 2` — A 4D vector type.
- `OP_TYPE_MAX = 3` — Represents the size of the `OpType` enum.
