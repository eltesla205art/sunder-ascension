# PhysicsDirectBodyState3DExtension

**Inherits:** PhysicsDirectBodyState3D

Provides virtual methods that can be overridden to create custom PhysicsDirectBodyState3D implementations.

This class extends PhysicsDirectBodyState3D by providing additional virtual methods that can be overridden. When these methods are overridden, they will be called instead of the internal methods of the physics server. Intended for use with GDExtension to create custom implementations of PhysicsDirectBodyState3D.

## Methods

- `_add_constant_central_force(force: Vector3) -> void` *virtual required*
- `_add_constant_force(force: Vector3, position: Vector3) -> void` *virtual required*
- `_add_constant_torque(torque: Vector3) -> void` *virtual required*
- `_apply_central_force(force: Vector3) -> void` *virtual required*
- `_apply_central_impulse(impulse: Vector3) -> void` *virtual required*
- `_apply_force(force: Vector3, position: Vector3) -> void` *virtual required*
- `_apply_impulse(impulse: Vector3, position: Vector3) -> void` *virtual required*
- `_apply_torque(torque: Vector3) -> void` *virtual required*
- `_apply_torque_impulse(impulse: Vector3) -> void` *virtual required*
- `_get_angular_velocity() -> Vector3` *virtual required const*
- `_get_center_of_mass() -> Vector3` *virtual required const*
- `_get_center_of_mass_local() -> Vector3` *virtual required const*
- `_get_collision_layer() -> int` *virtual required const*
- `_get_collision_mask() -> int` *virtual required const*
- `_get_constant_force() -> Vector3` *virtual required const*
- `_get_constant_torque() -> Vector3` *virtual required const*
- `_get_contact_collider(contact_idx: int) -> RID` *virtual required const*
- `_get_contact_collider_id(contact_idx: int) -> int` *virtual required const*
- `_get_contact_collider_object(contact_idx: int) -> Object` *virtual required const*
- `_get_contact_collider_position(contact_idx: int) -> Vector3` *virtual required const*
- `_get_contact_collider_shape(contact_idx: int) -> int` *virtual required const*
- `_get_contact_collider_velocity_at_position(contact_idx: int) -> Vector3` *virtual required const*
- `_get_contact_count() -> int` *virtual required const*
- `_get_contact_impulse(contact_idx: int) -> Vector3` *virtual required const*
- `_get_contact_local_normal(contact_idx: int) -> Vector3` *virtual required const*
- `_get_contact_local_position(contact_idx: int) -> Vector3` *virtual required const*
- `_get_contact_local_shape(contact_idx: int) -> int` *virtual required const*
- `_get_contact_local_velocity_at_position(contact_idx: int) -> Vector3` *virtual required const*
- `_get_inverse_inertia() -> Vector3` *virtual required const*
- `_get_inverse_inertia_tensor() -> Basis` *virtual required const*
- `_get_inverse_mass() -> float` *virtual required const*
- `_get_linear_velocity() -> Vector3` *virtual required const*
- `_get_principal_inertia_axes() -> Basis` *virtual required const*
- `_get_space_state() -> PhysicsDirectSpaceState3D` *virtual required*
- `_get_step() -> float` *virtual required const*
- `_get_total_angular_damp() -> float` *virtual required const*
- `_get_total_gravity() -> Vector3` *virtual required const*
- `_get_total_linear_damp() -> float` *virtual required const*
- `_get_transform() -> Transform3D` *virtual required const*
- `_get_velocity_at_local_position(local_position: Vector3) -> Vector3` *virtual required const*
- `_integrate_forces() -> void` *virtual required*
- `_is_sleeping() -> bool` *virtual required const*
- `_set_angular_velocity(velocity: Vector3) -> void` *virtual required*
- `_set_collision_layer(layer: int) -> void` *virtual required*
- `_set_collision_mask(mask: int) -> void` *virtual required*
- `_set_constant_force(force: Vector3) -> void` *virtual required*
- `_set_constant_torque(torque: Vector3) -> void` *virtual required*
- `_set_linear_velocity(velocity: Vector3) -> void` *virtual required*
- `_set_sleep_state(enabled: bool) -> void` *virtual required*
- `_set_transform(transform: Transform3D) -> void` *virtual required*
