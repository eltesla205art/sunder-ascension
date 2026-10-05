# VisualShaderNodeFloatFunc

**Inherits:** VisualShaderNode

A scalar floating-point function to be used within the visual shader graph.

Accept a floating-point scalar (`x`) to the input port and transform it according to `function`.

## Properties

- `function: VisualShaderNodeFloatFunc.Function` = `13` — A function to be applied to the scalar.

## Enum Function

- `FUNC_SIN = 0` — Returns the sine of the parameter.
- `FUNC_COS = 1` — Returns the cosine of the parameter.
- `FUNC_TAN = 2` — Returns the tangent of the parameter.
- `FUNC_ASIN = 3` — Returns the arc-sine of the parameter.
- `FUNC_ACOS = 4` — Returns the arc-cosine of the parameter.
- `FUNC_ATAN = 5` — Returns the arc-tangent of the parameter.
- `FUNC_SINH = 6` — Returns the hyperbolic sine of the parameter.
- `FUNC_COSH = 7` — Returns the hyperbolic cosine of the parameter.
- `FUNC_TANH = 8` — Returns the hyperbolic tangent of the parameter.
- `FUNC_LOG = 9` — Returns the natural logarithm of the parameter.
- `FUNC_EXP = 10` — Returns the natural exponentiation of the parameter.
- `FUNC_SQRT = 11` — Returns the square root of the parameter.
- `FUNC_ABS = 12` — Returns the absolute value of the parameter.
- `FUNC_SIGN = 13` — Extracts the sign of the parameter.
- `FUNC_FLOOR = 14` — Finds the nearest integer less than or equal to the parameter.
- `FUNC_ROUND = 15` — Finds the nearest integer to the parameter.
- `FUNC_CEIL = 16` — Finds the nearest integer that is greater than or equal to the parameter.
- `FUNC_FRACT = 17` — Computes the fractional part of the argument.
- `FUNC_SATURATE = 18` — Clamps the value between `0.0` and `1.0` using `min(max(x, 0.0), 1.0)`.
- `FUNC_NEGATE = 19` — Negates the `x` using `-(x)`.
- `FUNC_ACOSH = 20` — Returns the arc-hyperbolic-cosine of the parameter.
- `FUNC_ASINH = 21` — Returns the arc-hyperbolic-sine of the parameter.
- `FUNC_ATANH = 22` — Returns the arc-hyperbolic-tangent of the parameter.
- `FUNC_DEGREES = 23` — Convert a quantity in radians to degrees.
- `FUNC_EXP2 = 24` — Returns 2 raised by the power of the parameter.
- `FUNC_INVERSE_SQRT = 25` — Returns the inverse of the square root of the parameter.
- `FUNC_LOG2 = 26` — Returns the base 2 logarithm of the parameter.
- `FUNC_RADIANS = 27` — Convert a quantity in degrees to radians.
- `FUNC_RECIPROCAL = 28` — Finds reciprocal value of dividing 1 by `x` (i.e.
- `FUNC_ROUNDEVEN = 29` — Finds the nearest even integer to the parameter.
- `FUNC_TRUNC = 30` — Returns a value equal to the nearest integer to `x` whose absolute value is not larger than the absolute value of `x`.
- `FUNC_ONEMINUS = 31` — Subtracts scalar `x` from 1 (i.e.
- `FUNC_MAX = 32` — Represents the size of the `Function` enum.
