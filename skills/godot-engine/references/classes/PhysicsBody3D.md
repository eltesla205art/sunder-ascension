# PhysicsBody3D

**Inherits:** CollisionObject3D

Abstract base class for 3D game objects affected by physics.

PhysicsBody3D is an abstract base class for 3D game objects affected by physics. All 3D physics bodies inherit from it. Warning: With a non-uniform scale, this node will likely not behave as expected. It is advised to keep its scale the same on all axes and adjust its collision shape(s) instead.

## Properties

- `axis_lock_angular_x: bool` = `false` — Lock the body's rotation in the X axis.
- `axis_lock_angular_y: bool` = `false` — Lock the body's rotation in the Y axis.
- `axis_lock_angular_z: bool` = `false` — Lock the body's rotation in the Z axis.
- `axis_lock_linear_x: bool` = `false` — Lock the body's linear movement in the X axis.
- `axis_lock_linear_y: bool` = `false` — Lock the body's linear movement in the Y axis.
- `axis_lock_linear_z: bool` = `false` — Lock the body's linear movement in the Z axis.

## Methods

- `add_collision_exception_with(body: Node) -> void` — Adds a body to the list of bodies that this body can't collide with.
- `get_axis_lock(axis: PhysicsServer3D.BodyAxis) -> bool` *const* — Returns `true` if the specified linear or rotational `axis` is locked.
- `get_collision_exceptions() -> PhysicsBody3D[]` — Returns an array of nodes that were added as collision exceptions for this body.
- `get_gravity() -> Vector3` *const* — Returns the gravity vector computed from all sources that can affect the body, including all gravity overrides from Area3D nodes and the global world gravity.
- `move_and_collide(motion: Vector3, test_only: bool = false, safe_margin: float = 0.001, recovery_as_collision: bool = false, max_collisions: int = 1) -> KinematicCollision3D` — Moves the body along the vector `motion`.
- `remove_collision_exception_with(body: Node) -> void` — Removes a body from the list of bodies that this body can't collide with.
- `set_axis_lock(axis: PhysicsServer3D.BodyAxis, lock: bool) -> void` — Locks or unlocks the specified linear or rotational `axis` depending on the value of `lock`.
- `test_move(from: Transform3D, motion: Vector3, collision: KinematicCollision3D = null, safe_margin: float = 0.001, recovery_as_collision: bool = false, max_collisions: int = 1) -> bool` — Checks for collisions without moving the body.
