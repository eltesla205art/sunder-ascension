# PhysicsPointQueryParameters3D

**Inherits:** RefCounted

Provides parameters for `PhysicsDirectSpaceState3D.intersect_point`.

By changing various properties of this object, such as the point position, you can configure the parameters for `PhysicsDirectSpaceState3D.intersect_point`.

## Properties

- `collide_with_areas: bool` = `false` — If `true`, the query will take Area3Ds into account.
- `collide_with_bodies: bool` = `true` — If `true`, the query will take PhysicsBody3Ds into account.
- `collision_mask: int` = `4294967295` — The physics layers the query will detect (as a bitmask).
- `exclude: RID[]` = `[]` — The list of object RIDs that will be excluded from collisions.
- `position: Vector3` = `Vector3(0, 0, 0)` — The position being queried for, in global coordinates.
