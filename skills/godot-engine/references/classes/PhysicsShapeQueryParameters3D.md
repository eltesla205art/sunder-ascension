# PhysicsShapeQueryParameters3D

**Inherits:** RefCounted

Provides parameters for PhysicsDirectSpaceState3D's methods.

By changing various properties of this object, such as the shape, you can configure the parameters for PhysicsDirectSpaceState3D's methods.

## Properties

- `collide_with_areas: bool` = `false` — If `true`, the query will take Area3Ds into account.
- `collide_with_bodies: bool` = `true` — If `true`, the query will take PhysicsBody3Ds into account.
- `collision_mask: int` = `4294967295` — The physics layers the query will detect (as a bitmask).
- `exclude: RID[]` = `[]` — The list of object RIDs that will be excluded from collisions.
- `margin: float` = `0.0` — The collision margin for the shape.
- `motion: Vector3` = `Vector3(0, 0, 0)` — The motion of the shape being queried for.
- `shape: Resource` — The Shape3D that will be used for collision/intersection queries.
- `shape_rid: RID` = `RID()` — The queried shape's RID that will be used for collision/intersection queries.
- `transform: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The queried shape's transform matrix.
