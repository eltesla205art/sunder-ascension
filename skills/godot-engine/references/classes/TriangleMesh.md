# TriangleMesh

**Inherits:** RefCounted

Triangle geometry for efficient, physicsless intersection queries.

Creates a bounding volume hierarchy (BVH) tree structure around triangle geometry. The triangle BVH tree can be used for efficient intersection queries without involving a physics engine. For example, this can be used in editor tools to select objects with complex shapes based on the mouse cursor position. Performance: Creating the BVH tree for complex geometry is a slow process and best done in a background thread.

## Methods

- `create_from_faces(faces: PackedVector3Array) -> bool` — Creates the BVH tree from an array of faces.
- `get_faces() -> PackedVector3Array` *const* — Returns a copy of the geometry faces.
- `intersect_ray(begin: Vector3, dir: Vector3) -> Dictionary` *const* — Tests for intersection with a ray starting at `begin` and facing `dir` and extending toward infinity.
- `intersect_segment(begin: Vector3, end: Vector3) -> Dictionary` *const* — Tests for intersection with a segment going from `begin` to `end`.
