# PhysicsRayQueryParameters3D

**Inherits:** RefCounted

Provides parameters for `PhysicsDirectSpaceState3D.intersect_ray`.

By changing various properties of this object, such as the ray position, you can configure the parameters for `PhysicsDirectSpaceState3D.intersect_ray`.

## Properties

- `collide_with_areas: bool` = `false` — If `true`, the query will take Area3Ds into account.
- `collide_with_bodies: bool` = `true` — If `true`, the query will take PhysicsBody3Ds into account.
- `collision_mask: int` = `4294967295` — The physics layers the query will detect (as a bitmask).
- `exclude: RID[]` = `[]` — The list of object RIDs that will be excluded from collisions.
- `from: Vector3` = `Vector3(0, 0, 0)` — The starting point of the ray being queried for, in global coordinates.
- `hit_back_faces: bool` = `true` — If `true`, the query will hit back faces with concave polygon shapes with back face enabled or heightmap shapes.
- `hit_from_inside: bool` = `false` — If `true`, the query will detect a hit when starting inside shapes.
- `to: Vector3` = `Vector3(0, 0, 0)` — The ending point of the ray being queried for, in global coordinates.

## Methods

- `create(from: Vector3, to: Vector3, collision_mask: int = 4294967295, exclude: RID[] = []) -> PhysicsRayQueryParameters3D` *static* — Returns a new, pre-configured PhysicsRayQueryParameters3D object.
