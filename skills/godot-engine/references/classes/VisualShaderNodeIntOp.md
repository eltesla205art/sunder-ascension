# VisualShaderNodeIntOp

**Inherits:** VisualShaderNode

An integer scalar operator to be used within the visual shader graph.

Applies `operator` to two integer inputs: `a` and `b`.

## Properties

- `operator: VisualShaderNodeIntOp.Operator` = `0` — An operator to be applied to the inputs.

## Enum Operator

- `OP_ADD = 0` — Sums two numbers using `a + b`.
- `OP_SUB = 1` — Subtracts two numbers using `a - b`.
- `OP_MUL = 2` — Multiplies two numbers using `a * b`.
- `OP_DIV = 3` — Divides two numbers using `a / b`.
- `OP_MOD = 4` — Calculates the remainder of two numbers using `a % b`.
- `OP_MAX = 5` — Returns the greater of two numbers.
- `OP_MIN = 6` — Returns the lesser of two numbers.
- `OP_BITWISE_AND = 7` — Returns the result of bitwise `AND` operation on the integer.
- `OP_BITWISE_OR = 8` — Returns the result of bitwise `OR` operation for two integers.
- `OP_BITWISE_XOR = 9` — Returns the result of bitwise `XOR` operation for two integers.
- `OP_BITWISE_LEFT_SHIFT = 10` — Returns the result of bitwise left shift operation on the integer.
- `OP_BITWISE_RIGHT_SHIFT = 11` — Returns the result of bitwise right shift operation on the integer.
- `OP_ENUM_SIZE = 12` — Represents the size of the `Operator` enum.
