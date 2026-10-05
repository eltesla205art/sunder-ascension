# VisualShaderNodeVectorOp

**Inherits:** VisualShaderNodeVectorBase

A vector operator to be used within the visual shader graph.

A visual shader node for use of vector operators. Operates on vector `a` and vector `b`.

## Properties

- `operator: VisualShaderNodeVectorOp.Operator` = `0` — The operator to be used.

## Enum Operator

- `OP_ADD = 0` — Adds two vectors.
- `OP_SUB = 1` — Subtracts a vector from a vector.
- `OP_MUL = 2` — Multiplies two vectors.
- `OP_DIV = 3` — Divides vector by vector.
- `OP_MOD = 4` — Returns the remainder of the two vectors.
- `OP_POW = 5` — Returns the value of the first parameter raised to the power of the second, for each component of the vectors.
- `OP_MAX = 6` — Returns the greater of two values, for each component of the vectors.
- `OP_MIN = 7` — Returns the lesser of two values, for each component of the vectors.
- `OP_CROSS = 8` — Calculates the cross product of two vectors.
- `OP_ATAN2 = 9` — Returns the arc-tangent of the parameters.
- `OP_REFLECT = 10` — Returns the vector that points in the direction of reflection.
- `OP_STEP = 11` — Vector step operator.
- `OP_ENUM_SIZE = 12` — Represents the size of the `Operator` enum.
