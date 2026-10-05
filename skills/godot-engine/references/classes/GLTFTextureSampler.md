# GLTFTextureSampler

**Inherits:** Resource

Represents a glTF texture sampler

Represents a texture sampler as defined by the base glTF spec. Texture samplers in glTF specify how to sample data from the texture's base image, when rendering the texture on an object.

## Properties

- `mag_filter: int` = `9729` — Texture's magnification filter, used when texture appears larger on screen than the source image.
- `min_filter: int` = `9987` — Texture's minification filter, used when the texture appears smaller on screen than the source image.
- `wrap_s: int` = `10497` — Wrapping mode to use for S-axis (horizontal) texture coordinates.
- `wrap_t: int` = `10497` — Wrapping mode to use for T-axis (vertical) texture coordinates.
