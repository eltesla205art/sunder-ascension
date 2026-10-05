# PhysicsBody2D

**Inherits:** CollisionObject2D

Abstract base class for 2D game objects affected by physics.

PhysicsBody2D is an abstract base class for 2D game objects affected by physics. All 2D physics bodies inherit from it.

## Properties

- `input_pickable: bool` = `false` — 

## Methods

- `add_collision_exception_with(body: Node) -> void` — Adds a body to the list of bodies that this body can't collide with.
- `get_collision_exceptions() -> PhysicsBody2D[]` — Returns an array of nodes that were added as collision exceptions for this body.
- `get_gravity() -> Vector2` *const* — Returns the gravity vector computed from all sources that can affect the body, including all gravity overrides from Area2D nodes and the global world gravity.
- `move_and_collide(motion: Vector2, test_only: bool = false, safe_margin: float = 0.08, recovery_as_collision: bool = false) -> KinematicCollision2D` — Moves the body along the vector `motion`.
- `remove_collision_exception_with(body: Node) -> void` — Removes a body from the list of bodies that this body can't collide with.
- `test_move(from: Transform2D, motion: Vector2, collision: KinematicCollision2D = null, safe_margin: float = 0.08, recovery_as_collision: bool = false) -> bool` — Checks for collisions without moving the body.
