# NavigationMeshSourceGeometryData3D

**Inherits:** Resource

Container for parsed source geometry data used in navigation mesh baking.

Container for parsed source geometry data used in navigation mesh baking.

## Methods

- `add_faces(faces: PackedVector3Array, xform: Transform3D) -> void` — Adds an array of vertex positions to the geometry data for navigation mesh baking to form triangulated faces.
- `add_mesh(mesh: Mesh, xform: Transform3D) -> void` — Adds the geometry data of a Mesh resource to the navigation mesh baking data.
- `add_mesh_array(mesh_array: Array, xform: Transform3D) -> void` — Adds an Array the size of `Mesh.ARRAY_MAX` and with vertices at index `Mesh.ARRAY_VERTEX` and indices at index `Mesh.ARRAY_INDEX` to the navigation mesh baking data.
- `add_projected_obstruction(vertices: PackedVector3Array, elevation: float, height: float, carve: bool) -> void` — Adds a projected obstruction shape to the source geometry.
- `append_arrays(vertices: PackedFloat32Array, indices: PackedInt32Array) -> void` — Appends arrays of `vertices` and `indices` at the end of the existing arrays.
- `clear() -> void` — Clears the internal data.
- `clear_projected_obstructions() -> void` — Clears all projected obstructions.
- `get_bounds() -> AABB` — Returns an axis-aligned bounding box that covers all the stored geometry data.
- `get_indices() -> PackedInt32Array` *const* — Returns the parsed source geometry data indices array.
- `get_projected_obstructions() -> Array` *const* — Returns the projected obstructions as an Array of dictionaries.
- `get_vertices() -> PackedFloat32Array` *const* — Returns the parsed source geometry data vertices array.
- `has_data() -> bool` — Returns `true` when parsed source geometry data exists.
- `merge(other_geometry: NavigationMeshSourceGeometryData3D) -> void` — Adds the geometry data of another NavigationMeshSourceGeometryData3D to the navigation mesh baking data.
- `set_indices(indices: PackedInt32Array) -> void` — Sets the parsed source geometry data indices.
- `set_projected_obstructions(projected_obstructions: Array) -> void` — Sets the projected obstructions with an Array of Dictionaries with the following key value pairs:
- `set_vertices(vertices: PackedFloat32Array) -> void` — Sets the parsed source geometry data vertices.
