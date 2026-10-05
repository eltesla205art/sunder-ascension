# PhysicsRayQueryParameters2D

**Inherits:** RefCounted

Provides parameters for `PhysicsDirectSpaceState2D.intersect_ray`.

By changing various properties of this object, such as the ray position, you can configure the parameters for `PhysicsDirectSpaceState2D.intersect_ray`.

## Properties

- `collide_with_areas: bool` = `false` — If `true`, the query will take Area2Ds into account.
- `collide_with_bodies: bool` = `true` — If `true`, the query will take PhysicsBody2Ds into account.
- `collision_mask: int` = `4294967295` — The physics layers the query will detect (as a bitmask).
- `exclude: RID[]` = `[]` — The list of object RIDs that will be excluded from collisions.
- `from: Vector2` = `Vector2(0, 0)` — The starting point of the ray being queried for, in global coordinates.
- `hit_from_inside: bool` = `false` — If `true`, the query will detect a hit when starting inside shapes.
- `to: Vector2` = `Vector2(0, 0)` — The ending point of the ray being queried for, in global coordinates.

## Methods

- `create(from: Vector2, to: Vector2, collision_mask: int = 4294967295, exclude: RID[] = []) -> PhysicsRayQueryParameters2D` *static* — Returns a new, pre-configured PhysicsRayQueryParameters2D object.
