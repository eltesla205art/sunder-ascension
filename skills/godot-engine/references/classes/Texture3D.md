# Texture3D

**Inherits:** Texture

Base class for 3-dimensional textures.

Base class for ImageTexture3D and CompressedTexture3D. Cannot be used directly, but contains all the functions necessary for accessing the derived resource types. Texture3D is the base class for all 3-dimensional texture types. See also TextureLayered.

## Methods

- `_get_data() -> Image[]` *virtual required const* — Called when the Texture3D's data is queried.
- `_get_depth() -> int` *virtual required const* — Called when the Texture3D's depth is queried.
- `_get_format() -> int[Image.Format]` *virtual required const* — Called when the Texture3D's format is queried.
- `_get_height() -> int` *virtual required const* — Called when the Texture3D's height is queried.
- `_get_width() -> int` *virtual required const* — Called when the Texture3D's width is queried.
- `_has_mipmaps() -> bool` *virtual required const* — Called when the presence of mipmaps in the Texture3D is queried.
- `create_placeholder() -> Resource` *const* — Creates a placeholder version of this resource (PlaceholderTexture3D).
- `get_data() -> Image[]` *const* — Returns the Texture3D's data as an array of Images.
- `get_depth() -> int` *const* — Returns the Texture3D's depth in pixels.
- `get_format() -> int[Image.Format]` *const* — Returns the current format being used by this texture.
- `get_height() -> int` *const* — Returns the Texture3D's height in pixels.
- `get_width() -> int` *const* — Returns the Texture3D's width in pixels.
- `has_mipmaps() -> bool` *const* — Returns `true` if the Texture3D has generated mipmaps.
