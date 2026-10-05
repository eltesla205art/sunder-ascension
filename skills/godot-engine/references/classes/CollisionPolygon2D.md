# CollisionPolygon2D

**Inherits:** Node2D

A node that provides a polygon shape to a CollisionObject2D parent.

A node that provides a polygon shape to a CollisionObject2D parent and allows it to be edited. The polygon can be concave or convex. This can give a detection shape to an Area2D, turn a PhysicsBody2D into a solid object, or give a hollow shape to a StaticBody2D. Warning: A non-uniformly scaled CollisionPolygon2D will likely not behave as expected.

## Properties

- `build_mode: CollisionPolygon2D.BuildMode` = `0` — Collision build mode.
- `disabled: bool` = `false` — If `true`, no collisions will be detected.
- `one_way_collision: bool` = `false` — If `true`, only edges that face up, relative to CollisionPolygon2D's rotation, will collide with other objects.
- `one_way_collision_direction: Vector2` = `Vector2(0, 1)` — The direction used for one-way collision.
- `one_way_collision_margin: float` = `1.0` — The margin used for one-way collision (in pixels).
- `polygon: PackedVector2Array` = `PackedVector2Array()` — The polygon's list of vertices.

## Enum BuildMode

- `BUILD_SOLIDS = 0` — Collisions will include the polygon and its contained area.
- `BUILD_SEGMENTS = 1` — Collisions will only include the polygon edges.
