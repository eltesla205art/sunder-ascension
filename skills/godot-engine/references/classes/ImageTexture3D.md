# ImageTexture3D

**Inherits:** Texture3D

Texture with 3 dimensions.

ImageTexture3D is a 3-dimensional ImageTexture that has a width, height, and depth. See also ImageTextureLayered. 3D textures are typically used to store density maps for FogMaterial, color correction LUTs for Environment, vector fields for GPUParticlesAttractorVectorField3D and collision maps for GPUParticlesCollisionSDF3D. 3D textures can also be used in custom shaders.

## Methods

- `create(format: Image.Format, width: int, height: int, depth: int, use_mipmaps: bool, data: Image[]) -> int[Error]` — Creates the ImageTexture3D with specified `format`, `width`, `height`, and `depth`.
- `update(data: Image[]) -> void` — Replaces the texture's existing data with the layers specified in `data`.
