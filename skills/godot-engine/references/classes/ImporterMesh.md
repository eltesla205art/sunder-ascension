# ImporterMesh

**Inherits:** Resource

A Resource that contains vertex array-based geometry during the import process.

ImporterMesh is a type of Resource analogous to ArrayMesh. It contains vertex array-based geometry, divided in surfaces. Each surface contains a completely separate array and a material used to draw it. Design wise, a mesh with multiple surfaces is preferred to a single surface, because objects created in 3D editing software commonly contain multiple materials.

## Methods

- `add_blend_shape(name: String) -> void` — Adds name for a blend shape that will be added with `add_surface`.
- `add_surface(primitive: Mesh.PrimitiveType, arrays: Array, blend_shapes: Array[] = [], lods: Dictionary = {}, material: Material = null, name: String = "", flags: int = 0) -> void` — Creates a new surface.
- `clear() -> void` — Removes all surfaces and blend shapes from this ImporterMesh.
- `from_mesh(mesh: Mesh) -> ImporterMesh` *static* — Converts the given Mesh into an ImporterMesh by copying all its surfaces, blend shapes, materials, and metadata into a new ImporterMesh object.
- `generate_lods(normal_merge_angle: float, normal_split_angle: float, bone_transform_array: Array) -> void` — Generates all lods for this ImporterMesh.
- `get_blend_shape_count() -> int` *const* — Returns the number of blend shapes that the mesh holds.
- `get_blend_shape_mode() -> int[Mesh.BlendShapeMode]` *const* — Returns the blend shape mode for this Mesh.
- `get_blend_shape_name(blend_shape_idx: int) -> String` *const* — Returns the name of the blend shape at this index.
- `get_lightmap_size_hint() -> Vector2i` *const* — Returns the size hint of this mesh for lightmap-unwrapping in UV-space.
- `get_mesh(base_mesh: ArrayMesh = null) -> ArrayMesh` — Returns the mesh data represented by this ImporterMesh as a usable ArrayMesh.
- `get_surface_arrays(surface_idx: int) -> Array` *const* — Returns the arrays for the vertices, normals, UVs, etc. that make up the requested surface.
- `get_surface_blend_shape_arrays(surface_idx: int, blend_shape_idx: int) -> Array` *const* — Returns a single set of blend shape arrays for the requested blend shape index for a surface.
- `get_surface_count() -> int` *const* — Returns the number of surfaces that the mesh holds.
- `get_surface_format(surface_idx: int) -> int` *const* — Returns the format of the surface that the mesh holds.
- `get_surface_lod_count(surface_idx: int) -> int` *const* — Returns the number of lods that the mesh holds on a given surface.
- `get_surface_lod_indices(surface_idx: int, lod_idx: int) -> PackedInt32Array` *const* — Returns the index buffer of a lod for a surface.
- `get_surface_lod_size(surface_idx: int, lod_idx: int) -> float` *const* — Returns the screen ratio which activates a lod for a surface.
- `get_surface_material(surface_idx: int) -> Material` *const* — Returns a Material in a given surface.
- `get_surface_name(surface_idx: int) -> String` *const* — Gets the name assigned to this surface.
- `get_surface_primitive_type(surface_idx: int) -> int[Mesh.PrimitiveType]` — Returns the primitive type of the requested surface (see `add_surface`).
- `merge_importer_meshes(importer_meshes: ImporterMesh[], relative_transforms: Transform3D[], deduplicate_surfaces: bool = true) -> ImporterMesh` *static* — Merges multiple ImporterMeshes into a single ImporterMesh.
- `set_blend_shape_mode(mode: Mesh.BlendShapeMode) -> void` — Sets the blend shape mode.
- `set_lightmap_size_hint(size: Vector2i) -> void` — Sets the size hint of this mesh for lightmap-unwrapping in UV-space.
- `set_surface_material(surface_idx: int, material: Material) -> void` — Sets a Material for a given surface.
- `set_surface_name(surface_idx: int, name: String) -> void` — Sets a name for a given surface.
