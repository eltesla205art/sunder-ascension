# SpringArm3D

**Inherits:** Node3D

A 3D raycast that dynamically moves its children near the collision point.

SpringArm3D casts a ray or a shape along its Z axis and moves all its direct children to the collision point, with an optional margin. This is useful for 3rd person cameras that move closer to the player when inside a tight space (you may need to exclude the player's collider from the SpringArm3D's collision check).

## Properties

- `collision_mask: int` = `1` — The layers against which the collision check will be done.
- `margin: float` = `0.01` — When the collision check is made, a candidate length for the SpringArm3D is given.
- `shape: Shape3D` — The Shape3D to use for the SpringArm3D.
- `spring_length: float` = `1.0` — The maximum extent of the SpringArm3D.

## Methods

- `add_excluded_object(RID: RID) -> void` — Adds the PhysicsBody3D object with the given RID to the list of PhysicsBody3D objects excluded from the collision check.
- `clear_excluded_objects() -> void` — Clears the list of PhysicsBody3D objects excluded from the collision check.
- `get_hit_length() -> float` — Returns the spring arm's current length.
- `remove_excluded_object(RID: RID) -> bool` — Removes the given RID from the list of PhysicsBody3D objects excluded from the collision check.
