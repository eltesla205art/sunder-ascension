# PhysicsDirectBodyState2DExtension

**Inherits:** PhysicsDirectBodyState2D

Provides virtual methods that can be overridden to create custom PhysicsDirectBodyState2D implementations.

This class extends PhysicsDirectBodyState2D by providing additional virtual methods that can be overridden. When these methods are overridden, they will be called instead of the internal methods of the physics server. Intended for use with GDExtension to create custom implementations of PhysicsDirectBodyState2D.

## Methods

- `_add_constant_central_force(force: Vector2) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.add_constant_central_force`.
- `_add_constant_force(force: Vector2, position: Vector2) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.add_constant_force`.
- `_add_constant_torque(torque: float) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.add_constant_torque`.
- `_apply_central_force(force: Vector2) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.apply_central_force`.
- `_apply_central_impulse(impulse: Vector2) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.apply_central_impulse`.
- `_apply_force(force: Vector2, position: Vector2) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.apply_force`.
- `_apply_impulse(impulse: Vector2, position: Vector2) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.apply_impulse`.
- `_apply_torque(torque: float) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.apply_torque`.
- `_apply_torque_impulse(impulse: float) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.apply_torque_impulse`.
- `_get_angular_velocity() -> float` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.angular_velocity` and its respective getter.
- `_get_center_of_mass() -> Vector2` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.center_of_mass` and its respective getter.
- `_get_center_of_mass_local() -> Vector2` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.center_of_mass_local` and its respective getter.
- `_get_collision_layer() -> int` *virtual required const*
- `_get_collision_mask() -> int` *virtual required const*
- `_get_constant_force() -> Vector2` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_constant_force`.
- `_get_constant_torque() -> float` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_constant_torque`.
- `_get_contact_collider(contact_idx: int) -> RID` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_collider`.
- `_get_contact_collider_id(contact_idx: int) -> int` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_collider_id`.
- `_get_contact_collider_object(contact_idx: int) -> Object` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_collider_object`.
- `_get_contact_collider_position(contact_idx: int) -> Vector2` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_collider_position`.
- `_get_contact_collider_shape(contact_idx: int) -> int` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_collider_shape`.
- `_get_contact_collider_velocity_at_position(contact_idx: int) -> Vector2` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_collider_velocity_at_position`.
- `_get_contact_count() -> int` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_count`.
- `_get_contact_impulse(contact_idx: int) -> Vector2` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_impulse`.
- `_get_contact_local_normal(contact_idx: int) -> Vector2` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_local_normal`.
- `_get_contact_local_position(contact_idx: int) -> Vector2` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_local_position`.
- `_get_contact_local_shape(contact_idx: int) -> int` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_local_shape`.
- `_get_contact_local_velocity_at_position(contact_idx: int) -> Vector2` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_contact_local_velocity_at_position`.
- `_get_inverse_inertia() -> float` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.inverse_inertia` and its respective getter.
- `_get_inverse_mass() -> float` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.inverse_mass` and its respective getter.
- `_get_linear_velocity() -> Vector2` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.linear_velocity` and its respective getter.
- `_get_space_state() -> PhysicsDirectSpaceState2D` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.get_space_state`.
- `_get_step() -> float` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.step` and its respective getter.
- `_get_total_angular_damp() -> float` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.total_angular_damp` and its respective getter.
- `_get_total_gravity() -> Vector2` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.total_gravity` and its respective getter.
- `_get_total_linear_damp() -> float` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.total_linear_damp` and its respective getter.
- `_get_transform() -> Transform2D` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.transform` and its respective getter.
- `_get_velocity_at_local_position(local_position: Vector2) -> Vector2` *virtual required const* — Overridable version of `PhysicsDirectBodyState2D.get_velocity_at_local_position`.
- `_integrate_forces() -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.integrate_forces`.
- `_is_sleeping() -> bool` *virtual required const* — Implement to override the behavior of `PhysicsDirectBodyState2D.sleeping` and its respective getter.
- `_set_angular_velocity(velocity: float) -> void` *virtual required* — Implement to override the behavior of `PhysicsDirectBodyState2D.angular_velocity` and its respective setter.
- `_set_collision_layer(layer: int) -> void` *virtual required*
- `_set_collision_mask(mask: int) -> void` *virtual required*
- `_set_constant_force(force: Vector2) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.set_constant_force`.
- `_set_constant_torque(torque: float) -> void` *virtual required* — Overridable version of `PhysicsDirectBodyState2D.set_constant_torque`.
- `_set_linear_velocity(velocity: Vector2) -> void` *virtual required* — Implement to override the behavior of `PhysicsDirectBodyState2D.linear_velocity` and its respective setter.
- `_set_sleep_state(enabled: bool) -> void` *virtual required* — Implement to override the behavior of `PhysicsDirectBodyState2D.sleeping` and its respective setter.
- `_set_transform(transform: Transform2D) -> void` *virtual required* — Implement to override the behavior of `PhysicsDirectBodyState2D.transform` and its respective setter.
