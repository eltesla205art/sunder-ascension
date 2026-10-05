# ResourceImporterTextureAtlas

**Inherits:** ResourceImporter

Imports a collection of textures from a PNG image into an optimized AtlasTexture for 2D rendering.

This imports a collection of textures from a PNG image into an AtlasTexture or 2D ArrayMesh. This can be used to save memory when importing 2D animations from spritesheets. Texture atlases are only supported in 2D rendering, not 3D. See also ResourceImporterTexture and ResourceImporterLayeredTexture.

## Properties

- `atlas_file: String` = `""` — Path to the atlas spritesheet.
- `crop_to_region: bool` = `false` — If `true`, discards empty areas from the atlas.
- `import_mode: int` = `0` — Region: Imports the atlas in an AtlasTexture resource, which is rendered as a rectangle.
- `trim_alpha_border_from_region: bool` = `true` — If `true`, trims the region to exclude fully transparent pixels using a clipping rectangle (which is never rotated).
