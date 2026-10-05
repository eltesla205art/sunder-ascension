# TextureLayered

**Inherits:** Texture

Base class for texture types which contain the data of multiple Images. Each image is of the same size and format.

Base class for ImageTextureLayered and CompressedTextureLayered. Cannot be used directly, but contains all the functions necessary for accessing the derived resource types. See also Texture3D. Data is set on a per-layer basis.

## Methods

- `_get_format() -> int[Image.Format]` *virtual required const* — Called when the TextureLayered's format is queried.
- `_get_height() -> int` *virtual required const* — Called when the TextureLayered's height is queried.
- `_get_layer_data(layer_index: int) -> Image` *virtual required const* — Called when the data for a layer in the TextureLayered is queried.
- `_get_layered_type() -> int` *virtual required const* — Called when the layers' type in the TextureLayered is queried.
- `_get_layers() -> int` *virtual required const* — Called when the number of layers in the TextureLayered is queried.
- `_get_width() -> int` *virtual required const* — Called when the TextureLayered's width queried.
- `_has_mipmaps() -> bool` *virtual required const* — Called when the presence of mipmaps in the TextureLayered is queried.
- `get_format() -> int[Image.Format]` *const* — Returns the current format being used by this texture.
- `get_height() -> int` *const* — Returns the height of the texture in pixels.
- `get_layer_data(layer: int) -> Image` *const* — Returns an Image resource with the data from specified `layer`.
- `get_layered_type() -> int[TextureLayered.LayeredType]` *const* — Returns the TextureLayered's type.
- `get_layers() -> int` *const* — Returns the number of referenced Images.
- `get_width() -> int` *const* — Returns the width of the texture in pixels.
- `has_mipmaps() -> bool` *const* — Returns `true` if the layers have generated mipmaps.

## Enum LayeredType

- `LAYERED_TYPE_2D_ARRAY = 0` — Texture is a generic Texture2DArray.
- `LAYERED_TYPE_CUBEMAP = 1` — Texture is a Cubemap, with each side in its own layer (6 in total).
- `LAYERED_TYPE_CUBEMAP_ARRAY = 2` — Texture is a CubemapArray, with each cubemap being made of 6 layers.
