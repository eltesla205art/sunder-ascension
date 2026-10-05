# PhysicsGetRestInfoResult2D

**Inherits:** RefCounted

Stores the nearest collision information of a shape query.

This class contains the collision data computed by `PhysicsDirectSpaceState2D.get_rest_info_into`. If the shape collides with multiple objects, only the nearest collision is stored.

## Properties

- `collider_id: int` = `0` — The colliding object's ID.
- `collider_rid: RID` = `RID()` — The intersecting object's RID.
- `collider_shape: int` = `0` — The shape index of the colliding shape.
- `collider_velocity: Vector2` = `Vector2(0, 0)` — The colliding object's velocity Vector2.
- `normal: Vector2` = `Vector2(0, 0)` — The collision normal of the query shape at the intersection point, pointing away from the intersecting object.
- `point: Vector2` = `Vector2(0, 0)` — The intersection point.
