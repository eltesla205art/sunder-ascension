# PhysicsTestMotionResult2D

**Inherits:** RefCounted

Describes the motion and collision result from `PhysicsServer2D.body_test_motion`.

Describes the motion and collision result from `PhysicsServer2D.body_test_motion`.

## Methods

- `get_collider() -> Object` *const* — Returns the colliding body's attached Object, if a collision occurred.
- `get_collider_id() -> int` *const* — Returns the unique instance ID of the colliding body's attached Object, if a collision occurred.
- `get_collider_rid() -> RID` *const* — Returns the colliding body's RID used by the PhysicsServer2D, if a collision occurred.
- `get_collider_shape() -> int` *const* — Returns the colliding body's shape index, if a collision occurred.
- `get_collider_velocity() -> Vector2` *const* — Returns the colliding body's velocity, if a collision occurred.
- `get_collision_depth() -> float` *const* — Returns the length of overlap along the collision normal, if a collision occurred.
- `get_collision_local_shape() -> int` *const* — Returns the moving object's colliding shape, if a collision occurred.
- `get_collision_normal() -> Vector2` *const* — Returns the colliding body's shape's normal at the point of collision, if a collision occurred.
- `get_collision_point() -> Vector2` *const* — Returns the point of collision in global coordinates, if a collision occurred.
- `get_collision_safe_fraction() -> float` *const* — Returns the maximum fraction of the motion that can occur without a collision, between `0` and `1`.
- `get_collision_unsafe_fraction() -> float` *const* — Returns the minimum fraction of the motion needed to collide, if a collision occurred, between `0` and `1`.
- `get_remainder() -> Vector2` *const* — Returns the moving object's remaining movement vector.
- `get_travel() -> Vector2` *const* — Returns the moving object's travel before collision.
