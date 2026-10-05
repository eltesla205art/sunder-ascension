# Texture2DArray

**Inherits:** ImageTextureLayered

A single texture resource which consists of multiple, separate images. Each image has the same dimensions and number of mipmap levels.

A Texture2DArray is different from a Texture3D: The Texture2DArray does not support trilinear interpolation between the Images, i.e. no blending. See also Cubemap and CubemapArray, which are texture arrays with specialized cubemap functions. A Texture2DArray is also different from an AtlasTexture: In a Texture2DArray, all images are treated separately. In an atlas, the regions (i.e. the single images) can be of different sizes.

## Methods

- `create_placeholder() -> Resource` *const* — Creates a placeholder version of this resource (PlaceholderTexture2DArray).
