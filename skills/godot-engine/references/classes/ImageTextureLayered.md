# ImageTextureLayered

**Inherits:** TextureLayered

Base class for texture types which contain the data of multiple ImageTextures. Each image is of the same size and format.

Base class for Texture2DArray, Cubemap and CubemapArray. Cannot be used directly, but contains all the functions necessary for accessing the derived resource types. See also Texture3D.

## Methods

- `create_from_images(images: Image[]) -> int[Error]` — Creates an ImageTextureLayered from an array of Images.
- `update_layer(image: Image, layer: int) -> void` — Replaces the existing Image data at the given `layer` with this new image.
