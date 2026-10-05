# Texture2DRD

**Inherits:** Texture2D

Texture for 2D that is bound to a texture created on the RenderingDevice.

This texture class allows you to use a 2D texture created directly on the RenderingDevice as a texture for materials, meshes, etc. Note: Texture2DRD is intended for low-level usage with RenderingDevice. For most use cases, use Texture2D instead.

## Properties

- `resource_local_to_scene: bool` = `false` — 
- `texture_rd_rid: RID` — The RID of the texture object created on the RenderingDevice.
