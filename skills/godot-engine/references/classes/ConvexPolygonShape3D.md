# ConvexPolygonShape3D

**Inherits:** Shape3D

A 3D convex polyhedron shape used for physics collision.

A 3D convex polyhedron shape, intended for use in physics. Usually used to provide a shape for a CollisionShape3D. ConvexPolygonShape3D is solid, which means it detects collisions from objects that are fully inside it, unlike ConcavePolygonShape3D which is hollow. This makes it more suitable for both detection and physics.

## Properties

- `points: PackedVector3Array` = `PackedVector3Array()` — The list of 3D points forming the convex polygon shape.
