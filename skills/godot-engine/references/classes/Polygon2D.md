# Polygon2D

**Inherits:** Node2D

A 2D polygon.

A Polygon2D is defined by a set of points. Each point is connected to the next, with the final point being connected to the first, resulting in a closed polygon. Polygon2Ds can be filled with color (solid or gradient) or filled with a given texture.

## Properties

- `antialiased: bool` = `false` — If `true`, polygon edges will be anti-aliased.
- `color: Color` = `Color(1, 1, 1, 1)` — The polygon's fill color.
- `internal_vertex_count: int` = `0` — Number of internal vertices, used for UV mapping.
- `invert_border: float` = `100.0` — Added padding applied to the bounding box when `invert_enabled` is set to `true`.
- `invert_enabled: bool` = `false` — If `true`, the polygon will be inverted, containing the area outside the defined points and extending to the `invert_border`.
- `offset: Vector2` = `Vector2(0, 0)` — The offset applied to each vertex.
- `polygon: PackedVector2Array` = `PackedVector2Array()` — The polygon's list of vertices.
- `polygons: Array` = `[]` — The list of polygons, in case more than one is being represented.
- `skeleton: NodePath` = `NodePath("")` — Path to a Skeleton2D node used for skeleton-based deformations of this polygon.
- `texture: Texture2D` — The polygon's fill texture.
- `texture_offset: Vector2` = `Vector2(0, 0)` — Amount to offset the polygon's `texture`.
- `texture_rotation: float` = `0.0` — The texture's rotation in radians.
- `texture_scale: Vector2` = `Vector2(1, 1)` — Amount to multiply the `uv` coordinates when using `texture`.
- `uv: PackedVector2Array` = `PackedVector2Array()` — Texture coordinates for each vertex of the polygon.
- `vertex_colors: PackedColorArray` = `PackedColorArray()` — Color for each vertex.

## Methods

- `add_bone(path: NodePath, weights: PackedFloat32Array) -> void` — Adds a bone with the specified `path` and `weights`.
- `clear_bones() -> void` — Removes all bones from this Polygon2D.
- `erase_bone(index: int) -> void` — Removes the specified bone from this Polygon2D.
- `get_bone_count() -> int` *const* — Returns the number of bones in this Polygon2D.
- `get_bone_path(index: int) -> NodePath` *const* — Returns the path to the node associated with the specified bone.
- `get_bone_weights(index: int) -> PackedFloat32Array` *const* — Returns the weight values of the specified bone.
- `set_bone_path(index: int, path: NodePath) -> void` — Sets the path to the node associated with the specified bone.
- `set_bone_weights(index: int, weights: PackedFloat32Array) -> void` — Sets the weight values for the specified bone.
