# VisualShaderNodeDerivativeFunc

**Inherits:** VisualShaderNode

Calculates a derivative within the visual shader graph.

This node is only available in `Fragment` and `Light` visual shaders.

## Properties

- `function: VisualShaderNodeDerivativeFunc.Function` = `0` — A derivative function type.
- `op_type: VisualShaderNodeDerivativeFunc.OpType` = `0` — A type of operands and returned value.
- `precision: VisualShaderNodeDerivativeFunc.Precision` = `0` — Sets the level of precision to use for the derivative function.

## Enum OpType

- `OP_TYPE_SCALAR = 0` — A floating-point scalar.
- `OP_TYPE_VECTOR_2D = 1` — A 2D vector type.
- `OP_TYPE_VECTOR_3D = 2` — A 3D vector type.
- `OP_TYPE_VECTOR_4D = 3` — A 4D vector type.
- `OP_TYPE_MAX = 4` — Represents the size of the `OpType` enum.

## Enum Function

- `FUNC_SUM = 0` — Sum of absolute derivative in `x` and `y`.
- `FUNC_X = 1` — Derivative in `x` using local differencing.
- `FUNC_Y = 2` — Derivative in `y` using local differencing.
- `FUNC_MAX = 3` — Represents the size of the `Function` enum.

## Enum Precision

- `PRECISION_NONE = 0` — No precision is specified, the GPU driver is allowed to use whatever level of precision it chooses.
- `PRECISION_COARSE = 1` — The derivative will be calculated using the current fragment's neighbors (which may not include the current fragment).
- `PRECISION_FINE = 2` — The derivative will be calculated using the current fragment and its immediate neighbors.
- `PRECISION_MAX = 3` — Represents the size of the `Precision` enum.
