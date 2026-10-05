# SurfaceTool

**Inherits:** RefCounted

Helper tool to create geometry.

The SurfaceTool is used to construct a Mesh by specifying vertex attributes individually. It can be used to construct a Mesh from a script. All properties except indices need to be added before calling `add_vertex`. For example, to add vertex colors and UVs:  The above SurfaceTool now contains one vertex of a triangle which has a UV coordinate and a specified Color.

## Methods

- `add_index(index: int) -> void` — Adds a vertex to index array if you are using indexed vertices.
- `add_triangle_fan(vertices: PackedVector3Array, uvs: PackedVector2Array = PackedVector2Array(), colors: PackedColorArray = PackedColorArray(), uv2s: PackedVector2Array = PackedVector2Array(), normals: PackedVector3Array = PackedVector3Array(), tangents: Plane[] = []) -> void` — Inserts a triangle fan made of array data into Mesh being constructed.
- `add_vertex(vertex: Vector3) -> void` — Specifies the position of current vertex.
- `append_from(existing: Mesh, surface: int, transform: Transform3D) -> void` — Append vertices from a given Mesh surface onto the current vertex array with specified Transform3D.
- `begin(primitive: Mesh.PrimitiveType) -> void` — Called before adding any vertices.
- `clear() -> void` — Clear all information passed into the surface tool so far.
- `commit(existing: ArrayMesh = null, flags: int = 0) -> ArrayMesh` — Returns a constructed ArrayMesh from current information passed in.
- `commit_to_arrays() -> Array` — Commits the data to the same format used by `ArrayMesh.add_surface_from_arrays`, `ImporterMesh.add_surface`, and `create_from_arrays`.
- `create_from(existing: Mesh, surface: int) -> void` — Creates a vertex array from an existing Mesh.
- `create_from_arrays(arrays: Array, primitive_type: Mesh.PrimitiveType = 3) -> void` — Creates this SurfaceTool from existing vertex arrays such as returned by `commit_to_arrays`, `Mesh.surface_get_arrays`, `Mesh.surface_get_blend_shape_arrays`, `ImporterMesh.get_surface_arrays`, and `ImporterMesh.get_surface_blend_shape_arrays`.
- `create_from_blend_shape(existing: Mesh, surface: int, blend_shape: String) -> void` — Creates a vertex array from the specified blend shape of an existing Mesh.
- `deindex() -> void` — Removes the index array by expanding the vertex array.
- `generate_lod(nd_threshold: float, target_index_count: int = 3) -> PackedInt32Array` *(deprecated)* — Generates an LOD for a given `nd_threshold` in linear units (square root of quadric error metric), using at most `target_index_count` indices.
- `generate_normals(flip: bool = false) -> void` — Generates normals from vertices so you do not have to do it manually.
- `generate_tangents() -> void` — Generates a tangent vector for each vertex.
- `get_aabb() -> AABB` *const* — Returns the axis-aligned bounding box of the vertex positions.
- `get_custom_format(channel_index: int) -> int[SurfaceTool.CustomFormat]` *const* — Returns the format for custom `channel_index` (currently up to 4).
- `get_primitive_type() -> int[Mesh.PrimitiveType]` *const* — Returns the type of mesh geometry, such as `Mesh.PRIMITIVE_TRIANGLES`.
- `get_skin_weight_count() -> int[SurfaceTool.SkinWeightCount]` *const* — By default, returns `SKIN_4_WEIGHTS` to indicate only 4 bone influences per vertex are used.
- `index() -> void` — Shrinks the vertex array by creating an index array.
- `optimize_indices_for_cache() -> void` — Optimizes triangle sorting for performance.
- `set_bones(bones: PackedInt32Array) -> void` — Specifies an array of bones to use for the next vertex.
- `set_color(color: Color) -> void` — Specifies a Color to use for the next vertex.
- `set_custom(channel_index: int, custom_color: Color) -> void` — Sets the custom value on this vertex for `channel_index`.
- `set_custom_format(channel_index: int, format: SurfaceTool.CustomFormat) -> void` — Sets the color format for this custom `channel_index`.
- `set_material(material: Material) -> void` — Sets Material to be used by the Mesh you are constructing.
- `set_normal(normal: Vector3) -> void` — Specifies a normal to use for the next vertex.
- `set_skin_weight_count(count: SurfaceTool.SkinWeightCount) -> void` — Set to `SKIN_8_WEIGHTS` to indicate that up to 8 bone influences per vertex may be used.
- `set_smooth_group(index: int) -> void` — Specifies the smooth group to use for the next vertex.
- `set_tangent(tangent: Plane) -> void` — Specifies a tangent to use for the next vertex.
- `set_uv(uv: Vector2) -> void` — Specifies a set of UV coordinates to use for the next vertex.
- `set_uv2(uv2: Vector2) -> void` — Specifies an optional second set of UV coordinates to use for the next vertex.
- `set_weights(weights: PackedFloat32Array) -> void` — Specifies weight values to use for the next vertex.

## Enum CustomFormat

- `CUSTOM_RGBA8_UNORM = 0` — Limits range of data passed to `set_custom` to unsigned normalized 0 to 1 stored in 8 bits per channel.
- `CUSTOM_RGBA8_SNORM = 1` — Limits range of data passed to `set_custom` to signed normalized -1 to 1 stored in 8 bits per channel.
- `CUSTOM_RG_HALF = 2` — Stores data passed to `set_custom` as half precision floats, and uses only red and green color channels.
- `CUSTOM_RGBA_HALF = 3` — Stores data passed to `set_custom` as half precision floats and uses all color channels.
- `CUSTOM_R_FLOAT = 4` — Stores data passed to `set_custom` as full precision floats, and uses only red color channel.
- `CUSTOM_RG_FLOAT = 5` — Stores data passed to `set_custom` as full precision floats, and uses only red and green color channels.
- `CUSTOM_RGB_FLOAT = 6` — Stores data passed to `set_custom` as full precision floats, and uses only red, green and blue color channels.
- `CUSTOM_RGBA_FLOAT = 7` — Stores data passed to `set_custom` as full precision floats, and uses all color channels.
- `CUSTOM_MAX = 8` — Used to indicate a disabled custom channel.

## Enum SkinWeightCount

- `SKIN_4_WEIGHTS = 0` — Each individual vertex can be influenced by only 4 bone weights.
- `SKIN_8_WEIGHTS = 1` — Each individual vertex can be influenced by up to 8 bone weights.
