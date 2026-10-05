# MeshTexture

**Inherits:** Texture2D

Simple texture that uses a mesh to draw itself.

Simple texture that uses a mesh to draw itself. It's limited because flags can't be changed and region drawing is not supported.

## Properties

- `base_texture: Texture2D` — Sets the base texture that the Mesh will use to draw.
- `image_size: Vector2` = `Vector2(0, 0)` — Sets the size of the image, needed for reference.
- `mesh: Mesh` — Sets the mesh used to draw.
- `resource_local_to_scene: bool` = `false` —
