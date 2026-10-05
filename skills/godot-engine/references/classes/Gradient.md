# Gradient

**Inherits:** Resource

A color transition.

This resource describes a color transition by defining a set of colored points and how to interpolate between them. See also Curve which supports more complex easing methods, but does not support colors.

## Properties

- `colors: PackedColorArray` = `PackedColorArray(0, 0, 0, 1, 1, 1, 1, 1)` — Gradient's colors as a PackedColorArray.
- `interpolation_color_space: Gradient.ColorSpace` = `0` — The color space used to interpolate between points of the gradient.
- `interpolation_mode: Gradient.InterpolationMode` = `0` — The algorithm used to interpolate between points of the gradient.
- `offsets: PackedFloat32Array` = `PackedFloat32Array(0, 1)` — Gradient's offsets as a PackedFloat32Array.

## Methods

- `add_point(offset: float, color: Color) -> void` — Adds the specified color to the gradient, with the specified offset.
- `get_color(point: int) -> Color` — Returns the color of the gradient color at index `point`.
- `get_offset(point: int) -> float` — Returns the offset of the gradient color at index `point`.
- `get_point_count() -> int` *const* — Returns the number of colors in the gradient.
- `remove_point(point: int) -> void` — Removes the color at index `point`.
- `reverse() -> void` — Reverses/mirrors the gradient.
- `sample(offset: float) -> Color` — Returns the interpolated color specified by `offset`.
- `set_color(point: int, color: Color) -> void` — Sets the color of the gradient color at index `point`.
- `set_offset(point: int, offset: float) -> void` — Sets the offset for the gradient color at index `point`.

## Enum InterpolationMode

- `GRADIENT_INTERPOLATE_LINEAR = 0` — Linear interpolation.
- `GRADIENT_INTERPOLATE_CONSTANT = 1` — Constant interpolation, color changes abruptly at each point and stays uniform between.
- `GRADIENT_INTERPOLATE_CUBIC = 2` — Cubic interpolation.

## Enum ColorSpace

- `GRADIENT_COLOR_SPACE_SRGB = 0` — sRGB color space.
- `GRADIENT_COLOR_SPACE_LINEAR_SRGB = 1` — Linear sRGB color space.
- `GRADIENT_COLOR_SPACE_OKLAB = 2` — Oklab color space.
