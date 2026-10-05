# PhysicsPointQueryParameters2D

**Inherits:** RefCounted

Provides parameters for `PhysicsDirectSpaceState2D.intersect_point`.

By changing various properties of this object, such as the point position, you can configure the parameters for `PhysicsDirectSpaceState2D.intersect_point`.

## Properties

- `canvas_instance_id: int` = `0` — If different from `0`, restricts the query to a specific canvas layer specified by its instance ID.
- `collide_with_areas: bool` = `false` — If `true`, the query will take Area2Ds into account.
- `collide_with_bodies: bool` = `true` — If `true`, the query will take PhysicsBody2Ds into account.
- `collision_mask: int` = `4294967295` — The physics layers the query will detect (as a bitmask).
- `exclude: RID[]` = `[]` — The list of object RIDs that will be excluded from collisions.
- `position: Vector2` = `Vector2(0, 0)` — The position being queried for, in global coordinates.
