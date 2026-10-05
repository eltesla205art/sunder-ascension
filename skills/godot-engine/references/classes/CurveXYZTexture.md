# CurveXYZTexture

**Inherits:** Texture2D

A 1D texture where the red, green, and blue color channels correspond to points on 3 curves.

A 1D texture where the red, green, and blue color channels correspond to points on 3 unit Curve resources. Compared to using separate CurveTextures, this further simplifies the task of saving curves as image files. If you only need to store one curve within a single texture, use CurveTexture instead. See also GradientTexture1D and GradientTexture2D.

## Properties

- `curve_x: Curve` — The Curve that is rendered onto the texture's red channel.
- `curve_y: Curve` — The Curve that is rendered onto the texture's green channel.
- `curve_z: Curve` — The Curve that is rendered onto the texture's blue channel.
- `resource_local_to_scene: bool` = `false` — 
- `width: int` = `256` — The width of the texture (in pixels).
