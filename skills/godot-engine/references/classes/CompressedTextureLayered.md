# CompressedTextureLayered

**Inherits:** TextureLayered

Base class for texture arrays that can optionally be compressed.

Base class for CompressedTexture2DArray and CompressedTexture3D. Cannot be used directly, but contains all the functions necessary for accessing the derived resource types. See also TextureLayered.

## Properties

- `load_path: String` = `""` — The path the texture should be loaded from.

## Methods

- `load(path: String) -> int[Error]` — Loads the texture at `path`.
