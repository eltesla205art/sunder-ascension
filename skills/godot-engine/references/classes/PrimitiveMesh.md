# PrimitiveMesh

**Inherits:** Mesh

Base class for all primitive meshes. Handles applying a Material to a primitive mesh.

Base class for all primitive meshes. Handles applying a Material to a primitive mesh. Examples include BoxMesh, CapsuleMesh, CylinderMesh, PlaneMesh, PrismMesh, and SphereMesh.

## Properties

- `add_uv2: bool` = `false` — If set, generates UV2 UV coordinates applying a padding using the `uv2_padding` setting.
- `custom_aabb: AABB` = `AABB(0, 0, 0, 0, 0, 0)` — Overrides the AABB with one defined by user for use with frustum culling.
- `flip_faces: bool` = `false` — If `true`, the order of the vertices in each triangle is reversed, resulting in the backside of the mesh being drawn.
- `material: Material` — The current Material of the primitive mesh.
- `uv2_padding: float` = `2.0` — If `add_uv2` is set, specifies the padding in pixels applied along seams of the mesh.

## Methods

- `_create_mesh_array() -> Array` *virtual const* — Override this method to customize how this primitive mesh should be generated.
- `get_mesh_arrays() -> Array` *const* — Returns the mesh arrays used to make up the surface of this primitive mesh.
- `request_update() -> void` — Request an update of this primitive mesh based on its properties.
