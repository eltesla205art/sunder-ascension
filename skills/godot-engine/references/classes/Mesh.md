# Mesh

**Inherits:** Resource

A Resource that contains vertex array-based geometry.

Mesh is a type of Resource that contains vertex array-based geometry, divided in surfaces. Each surface contains a completely separate array and a material used to draw it. Design wise, a mesh with multiple surfaces is preferred to a single surface, because objects created in 3D editing software commonly contain multiple materials. The maximum number of surfaces per mesh is `RenderingServer.MAX_MESH_SURFACES`.

## Properties

- `lightmap_size_hint: Vector2i` = `Vector2i(0, 0)` — Sets a hint to be used for lightmap resolution.

## Methods

- `_get_aabb() -> AABB` *virtual required const* — Virtual method to override the AABB for a custom class extending Mesh.
- `_get_blend_shape_count() -> int` *virtual required const* — Virtual method to override the number of blend shapes for a custom class extending Mesh.
- `_get_blend_shape_name(index: int) -> StringName` *virtual required const* — Virtual method to override the retrieval of blend shape names for a custom class extending Mesh.
- `_get_surface_count() -> int` *virtual required const* — Virtual method to override the surface count for a custom class extending Mesh.
- `_set_blend_shape_name(index: int, name: StringName) -> void` *virtual required* — Virtual method to override the names of blend shapes for a custom class extending Mesh.
- `_surface_get_array_index_len(index: int) -> int` *virtual required const* — Virtual method to override the surface array index length for a custom class extending Mesh.
- `_surface_get_array_len(index: int) -> int` *virtual required const* — Virtual method to override the surface array length for a custom class extending Mesh.
- `_surface_get_arrays(index: int) -> Array` *virtual required const* — Virtual method to override the surface arrays for a custom class extending Mesh.
- `_surface_get_blend_shape_arrays(index: int) -> Array[]` *virtual required const* — Virtual method to override the blend shape arrays for a custom class extending Mesh.
- `_surface_get_format(index: int) -> int` *virtual required const* — Virtual method to override the surface format for a custom class extending Mesh.
- `_surface_get_lods(index: int) -> Dictionary` *virtual required const* — Virtual method to override the surface LODs for a custom class extending Mesh.
- `_surface_get_material(index: int) -> Material` *virtual required const* — Virtual method to override the surface material for a custom class extending Mesh.
- `_surface_get_primitive_type(index: int) -> int` *virtual required const* — Virtual method to override the surface primitive type for a custom class extending Mesh.
- `_surface_set_material(index: int, material: Material) -> void` *virtual required* — Virtual method to override the setting of a `material` at the given `index` for a custom class extending Mesh.
- `create_convex_shape(clean: bool = true, simplify: bool = false) -> ConvexPolygonShape3D` *const* — Calculate a ConvexPolygonShape3D from the mesh.
- `create_outline(margin: float) -> Mesh` *const* — Calculate an outline mesh at a defined offset (margin) from the original mesh.
- `create_placeholder() -> Resource` *const* — Creates a placeholder version of this resource (PlaceholderMesh).
- `create_trimesh_shape() -> ConcavePolygonShape3D` *const* — Calculate a ConcavePolygonShape3D from the mesh.
- `generate_triangle_mesh() -> TriangleMesh` *const* — Generate a TriangleMesh from the mesh.
- `get_aabb() -> AABB` *const* — Returns the smallest AABB enclosing this mesh in local space.
- `get_faces() -> PackedVector3Array` *const* — Returns all the vertices that make up the faces of the mesh.
- `get_surface_count() -> int` *const* — Returns the number of surfaces that the Mesh holds.
- `surface_get_arrays(surf_idx: int) -> Array` *const* — Returns the arrays for the vertices, normals, UVs, etc. that make up the requested surface (see `ArrayMesh.add_surface_from_arrays`).
- `surface_get_blend_shape_arrays(surf_idx: int) -> Array[]` *const* — Returns the blend shape arrays for the requested surface.
- `surface_get_material(surf_idx: int) -> Material` *const* — Returns a Material in a given surface.
- `surface_set_material(surf_idx: int, material: Material) -> void` — Sets a Material for a given surface.

## Enum PrimitiveType

- `PRIMITIVE_POINTS = 0` — Render array as points (one vertex equals one point).
- `PRIMITIVE_LINES = 1` — Render array as lines (every two vertices a line is created).
- `PRIMITIVE_LINE_STRIP = 2` — Render array as line strip.
- `PRIMITIVE_TRIANGLES = 3` — Render array as triangles (every three vertices a triangle is created).
- `PRIMITIVE_TRIANGLE_STRIP = 4` — Render array as triangle strips.

## Enum ArrayType

- `ARRAY_VERTEX = 0` — PackedVector3Array, PackedVector2Array, or Array of vertex positions.
- `ARRAY_NORMAL = 1` — PackedVector3Array of vertex normals.
- `ARRAY_TANGENT = 2` — PackedFloat32Array of vertex tangents.
- `ARRAY_COLOR = 3` — PackedColorArray of vertex colors.
- `ARRAY_TEX_UV = 4` — PackedVector2Array for UV coordinates.
- `ARRAY_TEX_UV2 = 5` — PackedVector2Array for second UV coordinates.
- `ARRAY_CUSTOM0 = 6` — Contains custom color channel 0.
- `ARRAY_CUSTOM1 = 7` — Contains custom color channel 1.
- `ARRAY_CUSTOM2 = 8` — Contains custom color channel 2.
- `ARRAY_CUSTOM3 = 9` — Contains custom color channel 3.
- `ARRAY_BONES = 10` — PackedFloat32Array or PackedInt32Array of bone indices.
- `ARRAY_WEIGHTS = 11` — PackedFloat32Array or PackedFloat64Array of bone weights in the range `0.0` to `1.0` (inclusive).
- `ARRAY_INDEX = 12` — PackedInt32Array of integers used as indices referencing vertices, colors, normals, tangents, and textures.
- `ARRAY_MAX = 13` — Represents the size of the `ArrayType` enum.

## Enum ArrayCustomFormat

- `ARRAY_CUSTOM_RGBA8_UNORM = 0` — Indicates this custom channel contains unsigned normalized byte colors from 0 to 1, encoded as PackedByteArray.
- `ARRAY_CUSTOM_RGBA8_SNORM = 1` — Indicates this custom channel contains signed normalized byte colors from -1 to 1, encoded as PackedByteArray.
- `ARRAY_CUSTOM_RG_HALF = 2` — Indicates this custom channel contains half precision float colors, encoded as PackedByteArray.
- `ARRAY_CUSTOM_RGBA_HALF = 3` — Indicates this custom channel contains half precision float colors, encoded as PackedByteArray.
- `ARRAY_CUSTOM_R_FLOAT = 4` — Indicates this custom channel contains full float colors, in a PackedFloat32Array.
- `ARRAY_CUSTOM_RG_FLOAT = 5` — Indicates this custom channel contains full float colors, in a PackedFloat32Array.
- `ARRAY_CUSTOM_RGB_FLOAT = 6` — Indicates this custom channel contains full float colors, in a PackedFloat32Array.
- `ARRAY_CUSTOM_RGBA_FLOAT = 7` — Indicates this custom channel contains full float colors, in a PackedFloat32Array.
- `ARRAY_CUSTOM_MAX = 8` — Represents the size of the `ArrayCustomFormat` enum.

## Enum ArrayFormat

- `ARRAY_FORMAT_VERTEX = 1` — Mesh array contains vertices.
- `ARRAY_FORMAT_NORMAL = 2` — Mesh array contains normals.
- `ARRAY_FORMAT_TANGENT = 4` — Mesh array contains tangents.
- `ARRAY_FORMAT_COLOR = 8` — Mesh array contains colors.
- `ARRAY_FORMAT_TEX_UV = 16` — Mesh array contains UVs.
- `ARRAY_FORMAT_TEX_UV2 = 32` — Mesh array contains second UV.
- `ARRAY_FORMAT_CUSTOM0 = 64` — Mesh array contains custom channel index 0.
- `ARRAY_FORMAT_CUSTOM1 = 128` — Mesh array contains custom channel index 1.
- `ARRAY_FORMAT_CUSTOM2 = 256` — Mesh array contains custom channel index 2.
- `ARRAY_FORMAT_CUSTOM3 = 512` — Mesh array contains custom channel index 3.
- `ARRAY_FORMAT_BONES = 1024` — Mesh array contains bones.
- `ARRAY_FORMAT_WEIGHTS = 2048` — Mesh array contains bone weights.
- `ARRAY_FORMAT_INDEX = 4096` — Mesh array uses indices.
- `ARRAY_FORMAT_BLEND_SHAPE_MASK = 7` — Mask of mesh channels permitted in blend shapes.
- `ARRAY_FORMAT_CUSTOM_BASE = 13` — Shift of first custom channel.
- `ARRAY_FORMAT_CUSTOM_BITS = 3` — Number of format bits per custom channel.
- `ARRAY_FORMAT_CUSTOM0_SHIFT = 13` — Amount to shift `ArrayCustomFormat` for custom channel index 0.
- `ARRAY_FORMAT_CUSTOM1_SHIFT = 16` — Amount to shift `ArrayCustomFormat` for custom channel index 1.
- `ARRAY_FORMAT_CUSTOM2_SHIFT = 19` — Amount to shift `ArrayCustomFormat` for custom channel index 2.
- `ARRAY_FORMAT_CUSTOM3_SHIFT = 22` — Amount to shift `ArrayCustomFormat` for custom channel index 3.
- `ARRAY_FORMAT_CUSTOM_MASK = 7` — Mask of custom format bits per custom channel.
- `ARRAY_COMPRESS_FLAGS_BASE = 25` — Shift of first compress flag.
- `ARRAY_FLAG_USE_2D_VERTICES = 33554432` — Flag used to mark that the array contains 2D vertices.
- `ARRAY_FLAG_USE_DYNAMIC_UPDATE = 67108864` — Flag used to mark that the mesh data will use `GL_DYNAMIC_DRAW` on GLES.
- `ARRAY_FLAG_USE_8_BONE_WEIGHTS = 134217728` — Flag used to mark that the mesh contains up to 8 bone influences per vertex.
- `ARRAY_FLAG_USES_EMPTY_VERTEX_ARRAY = 268435456` — Flag used to mark that the mesh intentionally contains no vertex array.
- `ARRAY_FLAG_COMPRESS_ATTRIBUTES = 536870912` — Flag used to mark that a mesh is using compressed attributes (vertices, normals, tangents, UVs).
- `ARRAY_FLAG_USE_STORAGE_BUFFER = 1073741824` — Flag used to mark that the surface's vertex, attribute, skin, and index buffers must be created with the storage-buffer usage bit so they can be bound as storage buffers in compute shaders.

## Enum BlendShapeMode

- `BLEND_SHAPE_MODE_NORMALIZED = 0` — Blend shapes are normalized.
- `BLEND_SHAPE_MODE_RELATIVE = 1` — Blend shapes are relative to base weight.
