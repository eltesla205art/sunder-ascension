# CurveTexture

**Inherits:** Texture2D

A 1D texture where pixel brightness corresponds to points on a curve.

A 1D texture where pixel brightness corresponds to points on a unit Curve resource, either in grayscale or in red. This visual representation simplifies the task of saving curves as image files. If you need to store up to 3 curves within a single texture, use CurveXYZTexture instead. See also GradientTexture1D and GradientTexture2D.

## Properties

- `curve: Curve` — The Curve that is rendered onto the texture.
- `resource_local_to_scene: bool` = `false` — 
- `texture_mode: CurveTexture.TextureMode` = `0` — The format the texture should be generated with.
- `width: int` = `256` — The width of the texture (in pixels).

## Enum TextureMode

- `TEXTURE_MODE_RGB = 0` — Store the curve equally across the red, green and blue channels.
- `TEXTURE_MODE_RED = 1` — Store the curve only in the red channel.
