# GradientTexture1D

**Inherits:** Texture2D

A 1D texture that uses colors obtained from a Gradient.

A 1D texture that obtains colors from a Gradient to fill the texture data. The texture is filled by sampling the gradient for each pixel. Therefore, the texture does not necessarily represent an exact copy of the gradient, as it may miss some colors if there are not enough pixels. See also GradientTexture2D, CurveTexture and CurveXYZTexture.

## Properties

- `gradient: Gradient` — The Gradient used to fill the texture.
- `resource_local_to_scene: bool` = `false` — 
- `use_hdr: bool` = `false` — If `true`, the generated texture will support high dynamic range (`Image.FORMAT_RGBAF` format).
- `width: int` = `256` — The number of color samples that will be obtained from the Gradient.
