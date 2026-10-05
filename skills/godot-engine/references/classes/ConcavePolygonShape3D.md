# ConcavePolygonShape3D

**Inherits:** Shape3D

A 3D trimesh shape used for physics collision.

A 3D trimesh shape, intended for use in physics. Usually used to provide a shape for a CollisionShape3D. Being just a collection of interconnected triangles, ConcavePolygonShape3D is the most freely configurable single 3D shape. It can be used to form polyhedra of any nature, or even shapes that don't enclose a volume.

## Properties

- `backface_collision: bool` = `false` — If set to `true`, collisions occur on both sides of the concave shape faces.

## Methods

- `get_faces() -> PackedVector3Array` *const* — Returns the faces of the trimesh shape as an array of vertices.
- `set_faces(faces: PackedVector3Array) -> void` — Sets the faces of the trimesh shape from an array of vertices.
