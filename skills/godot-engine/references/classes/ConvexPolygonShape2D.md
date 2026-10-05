# ConvexPolygonShape2D

**Inherits:** Shape2D

A 2D convex polygon shape used for physics collision.

A 2D convex polygon shape, intended for use in physics. Used internally in CollisionPolygon2D when it's in `CollisionPolygon2D.BUILD_SOLIDS` mode. ConvexPolygonShape2D is solid, which means it detects collisions from objects that are fully inside it, unlike ConcavePolygonShape2D which is hollow. This makes it more suitable for both detection and physics.

## Properties

- `points: PackedVector2Array` = `PackedVector2Array()` — The polygon's list of vertices that form a convex hull.

## Methods

- `set_point_cloud(point_cloud: PackedVector2Array) -> void` — Based on the set of points provided, this assigns the `points` property using the convex hull algorithm, removing all unneeded points.
