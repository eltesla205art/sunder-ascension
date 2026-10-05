# TextureLayeredRD

**Inherits:** TextureLayered

Abstract base class for layered texture RD types.

Base class for Texture2DArrayRD, TextureCubemapRD and TextureCubemapArrayRD. Cannot be used directly, but contains all the functions necessary for accessing the derived resource types. Note: TextureLayeredRD is intended for low-level usage with RenderingDevice. For most use cases, use TextureLayered instead.

## Properties

- `texture_rd_rid: RID` — The RID of the texture object created on the RenderingDevice.
