# PhysicsIntersectRayResult2D

**Inherits:** RefCounted

Stores the result of a ray intersection query.

This object contains the intersection information produced by `PhysicsDirectSpaceState2D.intersect_ray_into`. After calling `PhysicsDirectSpaceState2D.intersect_ray_into`, the fields of this object will be populated with the hit information if the ray intersects a shape. If no intersection occurred, the values remain unchanged from the previous state.

## Properties

- `collider: Object` — The colliding object.
- `collider_id: int` = `0` — The colliding object's ID.
- `collider_rid: RID` = `RID()` — The intersecting object's RID.
- `collider_shape: int` = `0` — The shape index of the colliding shape.
- `normal: Vector2` = `Vector2(0, 0)` — The object's surface normal at the intersection point, or `Vector2(0, 0)` if the ray starts inside the shape and `PhysicsRayQueryParameters2D.hit_from_inside` is `true`.
- `position: Vector2` = `Vector2(0, 0)` — The intersection point.
