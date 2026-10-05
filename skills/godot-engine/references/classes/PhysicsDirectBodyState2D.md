# PhysicsDirectBodyState2D

**Inherits:** Object

Provides direct access to a physics body in the PhysicsServer2D.

Provides direct access to a physics body in the PhysicsServer2D, allowing safe changes to physics properties. This object is passed via the direct state callback of RigidBody2D, and is intended for changing the direct state of that body. See `RigidBody2D._integrate_forces`.

## Properties

- `angular_velocity: float` — The body's rotational velocity in radians per second.
- `center_of_mass: Vector2` — The body's center of mass position relative to the body's center in the global coordinate system.
- `center_of_mass_local: Vector2` — The body's center of mass position in the body's local coordinate system.
- `collision_layer: int` — The body's collision layer.
- `collision_mask: int` — The body's collision mask.
- `inverse_inertia: float` — The inverse of the inertia of the body.
- `inverse_mass: float` — The inverse of the mass of the body.
- `linear_velocity: Vector2` — The body's linear velocity in pixels per second.
- `sleeping: bool` — If `true`, this body is currently sleeping (not active).
- `step: float` — The timestep (delta) used for the simulation.
- `total_angular_damp: float` — The rate at which the body stops rotating, if there are not any other forces moving it.
- `total_gravity: Vector2` — The total gravity vector being currently applied to this body.
- `total_linear_damp: float` — The rate at which the body stops moving, if there are not any other forces moving it.
- `transform: Transform2D` — The body's transformation matrix.

## Methods

- `add_constant_central_force(force: Vector2 = Vector2(0, 0)) -> void` — Adds a constant directional force without affecting rotation that keeps being applied over time until cleared with `constant_force = Vector2(0, 0)`.
- `add_constant_force(force: Vector2, position: Vector2 = Vector2(0, 0)) -> void` — Adds a constant positioned force to the body that keeps being applied over time until cleared with `constant_force = Vector2(0, 0)`.
- `add_constant_torque(torque: float) -> void` — Adds a constant rotational force without affecting position that keeps being applied over time until cleared with `constant_torque = 0`.
- `apply_central_force(force: Vector2 = Vector2(0, 0)) -> void` — Applies a directional force without affecting rotation.
- `apply_central_impulse(impulse: Vector2) -> void` — Applies a directional impulse without affecting rotation.
- `apply_force(force: Vector2, position: Vector2 = Vector2(0, 0)) -> void` — Applies a positioned force to the body.
- `apply_impulse(impulse: Vector2, position: Vector2 = Vector2(0, 0)) -> void` — Applies a positioned impulse to the body.
- `apply_torque(torque: float) -> void` — Applies a rotational force without affecting position.
- `apply_torque_impulse(impulse: float) -> void` — Applies a rotational impulse to the body without affecting the position.
- `get_constant_force() -> Vector2` *const* — Returns the body's total constant positional forces applied during each physics update.
- `get_constant_torque() -> float` *const* — Returns the body's total constant rotational forces applied during each physics update.
- `get_contact_collider(contact_idx: int) -> RID` *const* — Returns the collider's RID.
- `get_contact_collider_id(contact_idx: int) -> int` *const* — Returns the collider's object id.
- `get_contact_collider_object(contact_idx: int) -> Object` *const* — Returns the collider object.
- `get_contact_collider_position(contact_idx: int) -> Vector2` *const* — Returns the position of the contact point on the collider in the global coordinate system.
- `get_contact_collider_shape(contact_idx: int) -> int` *const* — Returns the collider's shape index.
- `get_contact_collider_velocity_at_position(contact_idx: int) -> Vector2` *const* — Returns the velocity vector at the collider's contact point.
- `get_contact_count() -> int` *const* — Returns the number of contacts this body has with other bodies.
- `get_contact_impulse(contact_idx: int) -> Vector2` *const* — Returns the impulse created by the contact.
- `get_contact_local_normal(contact_idx: int) -> Vector2` *const* — Returns the local normal at the contact point.
- `get_contact_local_position(contact_idx: int) -> Vector2` *const* — Returns the position of the contact point on the body in the global coordinate system.
- `get_contact_local_shape(contact_idx: int) -> int` *const* — Returns the local shape index of the collision.
- `get_contact_local_velocity_at_position(contact_idx: int) -> Vector2` *const* — Returns the velocity vector at the body's contact point.
- `get_space_state() -> PhysicsDirectSpaceState2D` — Returns the current state of the space, useful for queries.
- `get_velocity_at_local_position(local_position: Vector2) -> Vector2` *const* — Returns the body's velocity at the given relative position.
- `integrate_forces() -> void` — Updates the body's linear and angular velocity by applying gravity and damping for the equivalent of one physics tick.
- `set_constant_force(force: Vector2) -> void` — Sets the body's total constant positional forces applied during each physics update.
- `set_constant_torque(torque: float) -> void` — Sets the body's total constant rotational forces applied during each physics update.
