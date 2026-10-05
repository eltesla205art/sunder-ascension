# RigidBody3D

**Inherits:** PhysicsBody3D

A 3D physics body that is moved by a physics simulation.

RigidBody3D implements full 3D physics. It cannot be controlled directly, instead, you must apply forces to it (gravity, impulses, etc.), and the physics simulation will calculate the resulting movement, rotation, react to collisions, and affect other physics bodies in its path. The body's behavior can be adjusted via `lock_rotation`, `freeze`, and `freeze_mode`. By changing various properties of the object, such as `mass`, you can control how the physics simulation acts on it.

## Properties

- `angular_damp: float` = `0.0` — Damps the body's rotation.
- `angular_damp_mode: RigidBody3D.DampMode` = `0` — Defines how `angular_damp` is applied.
- `angular_velocity: Vector3` = `Vector3(0, 0, 0)` — The RigidBody3D's rotational velocity in radians per second.
- `can_sleep: bool` = `true` — If `true`, the body can enter sleep mode when there is no movement.
- `center_of_mass: Vector3` = `Vector3(0, 0, 0)` — The body's custom center of mass, relative to the body's origin position, when `center_of_mass_mode` is set to `CENTER_OF_MASS_MODE_CUSTOM`.
- `center_of_mass_mode: RigidBody3D.CenterOfMassMode` = `0` — Defines the way the body's center of mass is set.
- `constant_force: Vector3` = `Vector3(0, 0, 0)` — The body's total constant positional forces applied during each physics update.
- `constant_torque: Vector3` = `Vector3(0, 0, 0)` — The body's total constant rotational forces applied during each physics update.
- `contact_monitor: bool` = `false` — If `true`, the RigidBody3D will emit signals when it collides with another body.
- `continuous_cd: bool` = `false` — If `true`, continuous collision detection is used.
- `custom_integrator: bool` = `false` — If `true`, the standard force integration (like gravity or damping) will be disabled for this body.
- `freeze: bool` = `false` — If `true`, the body is frozen.
- `freeze_mode: RigidBody3D.FreezeMode` = `0` — The body's freeze mode.
- `gravity_scale: float` = `1.0` — This is multiplied by `ProjectSettings.physics/3d/default_gravity` to produce this body's gravity.
- `inertia: Vector3` = `Vector3(0, 0, 0)` — The body's moment of inertia.
- `linear_damp: float` = `0.0` — Damps the body's movement.
- `linear_damp_mode: RigidBody3D.DampMode` = `0` — Defines how `linear_damp` is applied.
- `linear_velocity: Vector3` = `Vector3(0, 0, 0)` — The body's linear velocity in units per second.
- `lock_rotation: bool` = `false` — If `true`, the body cannot rotate.
- `mass: float` = `1.0` — The body's mass.
- `max_contacts_reported: int` = `0` — The maximum number of contacts that will be recorded.
- `physics_material_override: PhysicsMaterial` — The physics material override for the body.
- `sleeping: bool` = `false` — If `true`, the body will not move and will not calculate forces until woken up by another body through, for example, a collision, or by using the `apply_impulse` or `apply_force` methods.

## Methods

- `_integrate_forces(state: PhysicsDirectBodyState3D) -> void` *virtual* — Called during physics processing, allowing you to read and safely modify the simulation state for the object.
- `add_constant_central_force(force: Vector3) -> void` — Adds a constant directional force without affecting rotation that keeps being applied over time until cleared with `constant_force = Vector3(0, 0, 0)`.
- `add_constant_force(force: Vector3, position: Vector3 = Vector3(0, 0, 0)) -> void` — Adds a constant positioned force to the body that keeps being applied over time until cleared with `constant_force = Vector3(0, 0, 0)`.
- `add_constant_torque(torque: Vector3) -> void` — Adds a constant rotational force without affecting position that keeps being applied over time until cleared with `constant_torque = Vector3(0, 0, 0)`.
- `apply_central_force(force: Vector3) -> void` — Applies a directional force without affecting rotation.
- `apply_central_impulse(impulse: Vector3) -> void` — Applies a directional impulse without affecting rotation.
- `apply_force(force: Vector3, position: Vector3 = Vector3(0, 0, 0)) -> void` — Applies a positioned force to the body.
- `apply_impulse(impulse: Vector3, position: Vector3 = Vector3(0, 0, 0)) -> void` — Applies a positioned impulse to the body.
- `apply_torque(torque: Vector3) -> void` — Applies a rotational force without affecting position.
- `apply_torque_impulse(impulse: Vector3) -> void` — Applies a rotational impulse to the body without affecting the position.
- `get_colliding_bodies() -> Node3D[]` *const* — Returns a list of the bodies colliding with this one.
- `get_contact_count() -> int` *const* — Returns the number of contacts this body has with other bodies.
- `get_inverse_inertia_tensor() -> Basis` *const* — Returns the inverse inertia tensor basis.
- `get_velocity_at_local_position(local_position: Vector3) -> Vector3` *const* — Returns the body's velocity at the given relative position.
- `get_velocity_at_position(global_point: Vector3) -> Vector3` *const* — Returns the body's velocity at the given global position.
- `set_axis_velocity(axis_velocity: Vector3) -> void` — Sets an axis velocity.

## Signals

- `body_entered(body: Node)` — Emitted when a collision with another PhysicsBody3D or GridMap occurs.
- `body_exited(body: Node)` — Emitted when the collision with another PhysicsBody3D or GridMap ends.
- `body_shape_entered(body_rid: RID, body: Node, body_shape_index: int, local_shape_index: int)` — Emitted when one of this RigidBody3D's Shape3Ds collides with another PhysicsBody3D or GridMap's Shape3Ds.
- `body_shape_exited(body_rid: RID, body: Node, body_shape_index: int, local_shape_index: int)` — Emitted when the collision between one of this RigidBody3D's Shape3Ds and another PhysicsBody3D or GridMap's Shape3Ds ends.
- `sleeping_state_changed()` — Emitted when the physics engine changes the body's sleeping state.

## Enum FreezeMode

- `FREEZE_MODE_STATIC = 0` — Static body freeze mode (default).
- `FREEZE_MODE_KINEMATIC = 1` — Kinematic body freeze mode.

## Enum CenterOfMassMode

- `CENTER_OF_MASS_MODE_AUTO = 0` — In this mode, the body's center of mass is calculated automatically based on its shapes.
- `CENTER_OF_MASS_MODE_CUSTOM = 1` — In this mode, the body's center of mass is set through `center_of_mass`.

## Enum DampMode

- `DAMP_MODE_COMBINE = 0` — In this mode, the body's damping value is added to any value set in areas or the default value.
- `DAMP_MODE_REPLACE = 1` — In this mode, the body's damping value replaces any value set in areas or the default value.
