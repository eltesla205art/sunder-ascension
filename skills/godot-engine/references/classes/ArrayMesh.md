# ArrayMesh

**Inherits:** Mesh

Mesh type that provides utility for constructing a surface from arrays.

The ArrayMesh is used to construct a Mesh by specifying the attributes as arrays. The most basic example is the creation of a single triangle:  The MeshInstance3D is ready to be added to the SceneTree to be shown. See also ImmediateMesh, MeshDataTool and SurfaceTool for procedural geometry generation. Note: Godot uses clockwise winding order for front faces of triangle primitive modes.

## Properties

- `blend_shape_mode: Mesh.BlendShapeMode` = `1` — The blend shape mode.
- `custom_aabb: AABB` = `AABB(0, 0, 0, 0, 0, 0)` — Overrides the AABB with one defined by user for use with frustum culling.
- `shadow_mesh: ArrayMesh` — An optional mesh which can be used for rendering shadows and the depth prepass.

## Methods

- `add_blend_shape(name: StringName) -> void` — Adds name for a blend shape that will be added with `add_surface_from_arrays`.
- `add_surface_from_arrays(primitive: Mesh.PrimitiveType, arrays: Array, blend_shapes: Array[] = [], lods: Dictionary = {}, flags: Mesh.ArrayFormat = 0) -> void` — Creates a new surface.
- `clear_blend_shapes() -> void` — Removes all blend shapes from this ArrayMesh.
- `clear_surfaces() -> void` — Removes all surfaces from this ArrayMesh.
- `get_blend_shape_count() -> int` *const* — Returns the number of blend shapes that the ArrayMesh holds.
- `get_blend_shape_name(index: int) -> StringName` *const* — Returns the name of the blend shape at this index.
- `lightmap_unwrap(transform: Transform3D, texel_size: float) -> int[Error]` — Performs a UV unwrap on the ArrayMesh to prepare the mesh for lightmapping.
- `regen_normal_maps() -> void` — Regenerates tangents for each of the ArrayMesh's surfaces.
- `set_blend_shape_name(index: int, name: StringName) -> void` — Sets the name of the blend shape at this index.
- `surface_find_by_name(name: String) -> int` *const* — Returns the index of the first surface with this name held within this ArrayMesh.
- `surface_get_array_index_len(surf_idx: int) -> int` *const* — Returns the length in indices of the index array in the requested surface (see `add_surface_from_arrays`).
- `surface_get_array_len(surf_idx: int) -> int` *const* — Returns the length in vertices of the vertex array in the requested surface (see `add_surface_from_arrays`).
- `surface_get_format(surf_idx: int) -> int[Mesh.ArrayFormat]` *const* — Returns the format mask of the requested surface (see `add_surface_from_arrays`).
- `surface_get_name(surf_idx: int) -> String` *const* — Gets the name assigned to this surface.
- `surface_get_primitive_type(surf_idx: int) -> int[Mesh.PrimitiveType]` *const* — Returns the primitive type of the requested surface (see `add_surface_from_arrays`).
- `surface_remove(surf_idx: int) -> void` — Removes the surface at the given index from the Mesh, shifting surfaces with higher index down by one.
- `surface_set_name(surf_idx: int, name: String) -> void` — Sets a name for a given surface.
- `surface_update_attribute_region(surf_idx: int, offset: int, data: PackedByteArray) -> void` — Updates the attribute buffer of this mesh's surface with the given `data`.
- `surface_update_skin_region(surf_idx: int, offset: int, data: PackedByteArray) -> void` — Updates the skin buffer of this mesh's surface with the given `data`.
- `surface_update_vertex_region(surf_idx: int, offset: int, data: PackedByteArray) -> void` — Updates the vertex buffer of this mesh's surface with the given `data`.
