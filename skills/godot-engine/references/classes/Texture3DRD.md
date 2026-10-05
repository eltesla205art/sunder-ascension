# Texture3DRD

**Inherits:** Texture3D

Texture for 3D that is bound to a texture created on the RenderingDevice.

This texture class allows you to use a 3D texture created directly on the RenderingDevice as a texture for materials, meshes, etc. Note: Texture3DRD is intended for low-level usage with RenderingDevice. For most use cases, use Texture3D instead.

## Properties

- `texture_rd_rid: RID` — The RID of the texture object created on the RenderingDevice.
