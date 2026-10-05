# VisualShaderNodeColorFunc

**Inherits:** VisualShaderNode

A Color function to be used within the visual shader graph.

Accept a Color to the input port and transform it according to `function`.

## Properties

- `function: VisualShaderNodeColorFunc.Function` = `0` — A function to be applied to the input color.

## Enum Function

- `FUNC_GRAYSCALE = 0` — Converts the color to grayscale using the following formula:
- `FUNC_HSV2RGB = 1` — Converts HSV vector to RGB equivalent.
- `FUNC_RGB2HSV = 2` — Converts RGB vector to HSV equivalent.
- `FUNC_SEPIA = 3` — Applies sepia tone effect using the following formula:
- `FUNC_LINEAR_TO_SRGB = 4` — Converts color from linear encoding to nonlinear sRGB encoding using the following formula:  The Compatibility renderer uses a simpler formula that may produce undefined behavior with negative input values:
- `FUNC_SRGB_TO_LINEAR = 5` — Converts color from nonlinear sRGB encoding to linear encoding using the following formula:  The Compatibility renderer uses a simpler formula that behaves poorly with negative input values:
- `FUNC_MAX = 6` — Represents the size of the `Function` enum.
