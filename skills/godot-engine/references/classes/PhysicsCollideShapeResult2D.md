# PhysicsCollideShapeResult2D

**Inherits:** RefCounted

Stores the collision points of a shape collision query.

This class contains the contact points computed by `PhysicsDirectSpaceState2D.collide_shape_into`. Each collision is represented as a pair of points: one on the query shape and one on the colliding shape.

## Properties

- `max_collisions: int` = `32` — The maximum number of collisions this object can store.

## Methods

- `get_collision_count() -> int` *const* — Returns the number of point pairs detected by the query.
- `get_point_on_colliding_shape(collision_index: int) -> Vector2` *const* — Returns the collision point on the colliding shape for the collision at the given index.
- `get_point_on_queried_shape(collision_index: int) -> Vector2` *const* — Returns the collision point on the query shape for the collision at the given index.
