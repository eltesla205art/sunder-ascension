# MeshDataTool

**Inherits:** RefCounted

Helper tool to access and edit Mesh data.

MeshDataTool provides access to individual vertices in a Mesh. It allows users to read and edit vertex data of meshes. It also creates an array of faces and edges. To use MeshDataTool, load a mesh with `create_from_surface`.

## Methods

- `clear() -> void` — Clears all data currently in MeshDataTool.
- `commit_to_surface(mesh: ArrayMesh, compression_flags: int = 0) -> int[Error]` — Adds a new surface to specified Mesh with edited data.
- `create_from_surface(mesh: ArrayMesh, surface: int) -> int[Error]` — Uses specified surface of given Mesh to populate data for MeshDataTool.
- `get_edge_count() -> int` *const* — Returns the number of edges in this Mesh.
- `get_edge_faces(idx: int) -> PackedInt32Array` *const* — Returns array of faces that touch given edge.
- `get_edge_meta(idx: int) -> Variant` *const* — Returns meta information assigned to given edge.
- `get_edge_vertex(idx: int, vertex: int) -> int` *const* — Returns the index of the specified `vertex` connected to the edge at index `idx`.
- `get_face_count() -> int` *const* — Returns the number of faces in this Mesh.
- `get_face_edge(idx: int, edge: int) -> int` *const* — Returns the edge associated with the face at index `idx`.
- `get_face_meta(idx: int) -> Variant` *const* — Returns the metadata associated with the given face.
- `get_face_normal(idx: int) -> Vector3` *const* — Calculates and returns the face normal of the given face.
- `get_face_vertex(idx: int, vertex: int) -> int` *const* — Returns the specified vertex index of the given face.
- `get_format() -> int` *const* — Returns the Mesh's format as a combination of the `Mesh.ArrayFormat` flags.
- `get_material() -> Material` *const* — Returns the material assigned to the Mesh.
- `get_vertex(idx: int) -> Vector3` *const* — Returns the position of the given vertex.
- `get_vertex_bones(idx: int) -> PackedInt32Array` *const* — Returns the bones of the given vertex.
- `get_vertex_color(idx: int) -> Color` *const* — Returns the color of the given vertex.
- `get_vertex_count() -> int` *const* — Returns the total number of vertices in Mesh.
- `get_vertex_edges(idx: int) -> PackedInt32Array` *const* — Returns an array of edges that share the given vertex.
- `get_vertex_faces(idx: int) -> PackedInt32Array` *const* — Returns an array of faces that share the given vertex.
- `get_vertex_meta(idx: int) -> Variant` *const* — Returns the metadata associated with the given vertex.
- `get_vertex_normal(idx: int) -> Vector3` *const* — Returns the normal of the given vertex.
- `get_vertex_tangent(idx: int) -> Plane` *const* — Returns the tangent of the given vertex.
- `get_vertex_uv(idx: int) -> Vector2` *const* — Returns the UV of the given vertex.
- `get_vertex_uv2(idx: int) -> Vector2` *const* — Returns the UV2 of the given vertex.
- `get_vertex_weights(idx: int) -> PackedFloat32Array` *const* — Returns bone weights of the given vertex.
- `set_edge_meta(idx: int, meta: Variant) -> void` — Sets the metadata of the given edge.
- `set_face_meta(idx: int, meta: Variant) -> void` — Sets the metadata of the given face.
- `set_material(material: Material) -> void` — Sets the material to be used by newly-constructed Mesh.
- `set_vertex(idx: int, vertex: Vector3) -> void` — Sets the position of the given vertex.
- `set_vertex_bones(idx: int, bones: PackedInt32Array) -> void` — Sets the bones of the given vertex.
- `set_vertex_color(idx: int, color: Color) -> void` — Sets the color of the given vertex.
- `set_vertex_meta(idx: int, meta: Variant) -> void` — Sets the metadata associated with the given vertex.
- `set_vertex_normal(idx: int, normal: Vector3) -> void` — Sets the normal of the given vertex.
- `set_vertex_tangent(idx: int, tangent: Plane) -> void` — Sets the tangent of the given vertex.
- `set_vertex_uv(idx: int, uv: Vector2) -> void` — Sets the UV of the given vertex.
- `set_vertex_uv2(idx: int, uv2: Vector2) -> void` — Sets the UV2 of the given vertex.
- `set_vertex_weights(idx: int, weights: PackedFloat32Array) -> void` — Sets the bone weights of the given vertex.
