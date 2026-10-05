# VisualShaderNodeFloatOp

**Inherits:** VisualShaderNode

A floating-point scalar operator to be used within the visual shader graph.

Applies `operator` to two floating-point inputs: `a` and `b`.

## Properties

- `operator: VisualShaderNodeFloatOp.Operator` = `0` — An operator to be applied to the inputs.

## Enum Operator

- `OP_ADD = 0` — Sums two numbers using `a + b`.
- `OP_SUB = 1` — Subtracts two numbers using `a - b`.
- `OP_MUL = 2` — Multiplies two numbers using `a * b`.
- `OP_DIV = 3` — Divides two numbers using `a / b`.
- `OP_MOD = 4` — Calculates the remainder of two numbers.
- `OP_POW = 5` — Raises the `a` to the power of `b`.
- `OP_MAX = 6` — Returns the greater of two numbers.
- `OP_MIN = 7` — Returns the lesser of two numbers.
- `OP_ATAN2 = 8` — Returns the arc-tangent of the parameters.
- `OP_STEP = 9` — Generates a step function by comparing `b`(x) to `a`(edge).
- `OP_ENUM_SIZE = 10` — Represents the size of the `Operator` enum.
