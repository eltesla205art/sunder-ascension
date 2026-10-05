# GradientTexture2D

**Inherits:** Texture2D

A 2D texture that creates a pattern with colors obtained from a Gradient.

A 2D texture that obtains colors from a Gradient to fill the texture data. This texture is able to transform a color transition into different patterns such as a linear or a radial gradient. The texture is filled by interpolating colors starting from `fill_from` to `fill_to` offsets by default, but the gradient fill can be repeated to cover the entire texture. The gradient is sampled individually for each pixel so it does not necessarily represent an exact copy of the gradient (see `width` and `height`).

## Properties

- `fill: GradientTexture2D.Fill` = `0` — The gradient's fill type.
- `fill_from: Vector2` = `Vector2(0, 0)` — The initial offset used to fill the texture specified in UV coordinates.
- `fill_to: Vector2` = `Vector2(1, 0)` — The final offset used to fill the texture specified in UV coordinates.
- `gradient: Gradient` — The Gradient used to fill the texture.
- `height: int` = `64` — The number of vertical color samples that will be obtained from the Gradient, which also represents the texture's height.
- `repeat: GradientTexture2D.Repeat` = `0` — The gradient's repeat type.
- `resource_local_to_scene: bool` = `false` — 
- `use_hdr: bool` = `false` — If `true`, the generated texture will support high dynamic range (`Image.FORMAT_RGBAF` format).
- `width: int` = `64` — The number of horizontal color samples that will be obtained from the Gradient, which also represents the texture's width.

## Enum Fill

- `FILL_LINEAR = 0` — The colors are linearly interpolated in a straight line.
- `FILL_RADIAL = 1` — The colors are linearly interpolated in a circular pattern.
- `FILL_SQUARE = 2` — The colors are linearly interpolated in a square pattern.
- `FILL_CONIC = 3` — The colors are linearly interpolated in a cone pattern.

## Enum Repeat

- `REPEAT_NONE = 0` — The gradient fill is restricted to the range defined by `fill_from` to `fill_to` offsets.
- `REPEAT = 1` — The texture is filled starting from `fill_from` to `fill_to` offsets, repeating the same pattern in both directions.
- `REPEAT_MIRROR = 2` — The texture is filled starting from `fill_from` to `fill_to` offsets, mirroring the pattern in both directions.
