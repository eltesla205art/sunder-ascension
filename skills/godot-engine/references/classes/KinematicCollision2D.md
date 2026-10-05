# KinematicCollision2D

**Inherits:** RefCounted

Holds collision data from the movement of a PhysicsBody2D.

Holds collision data from the movement of a PhysicsBody2D, usually from `PhysicsBody2D.move_and_collide`. When a PhysicsBody2D is moved, it stops if it detects a collision with another body. If a collision is detected, a KinematicCollision2D object is returned. The collision data includes the colliding object, the remaining motion, and the collision position.

## Methods

- `get_angle(up_direction: Vector2 = Vector2(0, -1)) -> float` *const* — Returns the collision angle according to `up_direction`, which is `Vector2.UP` by default.
- `get_collider() -> Object` *const* — Returns the colliding body's attached Object.
- `get_collider_id() -> int` *const* — Returns the unique instance ID of the colliding body's attached Object.
- `get_collider_rid() -> RID` *const* — Returns the colliding body's RID used by the PhysicsServer2D.
- `get_collider_shape() -> Object` *const* — Returns the colliding body's shape.
- `get_collider_shape_index() -> int` *const* — Returns the colliding body's shape index.
- `get_collider_velocity() -> Vector2` *const* — Returns the colliding body's velocity.
- `get_depth() -> float` *const* — Returns the colliding body's length of overlap along the collision normal.
- `get_local_shape() -> Object` *const* — Returns the moving object's colliding shape.
- `get_normal() -> Vector2` *const* — Returns the colliding body's shape's normal at the point of collision.
- `get_position() -> Vector2` *const* — Returns the point of collision in global coordinates.
- `get_remainder() -> Vector2` *const* — Returns the moving object's remaining movement vector.
- `get_travel() -> Vector2` *const* — Returns the moving object's travel before collision.
