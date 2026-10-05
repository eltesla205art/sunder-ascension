# PhysicalBone3D

**Inherits:** PhysicsBody3D

A physics body used to make bones in a Skeleton3D react to physics.

The PhysicalBone3D node is a physics body that can be used to make bones in a Skeleton3D react to physics. Note: In order to detect physical bones with raycasts, the `SkeletonModifier3D.active` property of the parent PhysicalBoneSimulator3D must be `true` and the Skeleton3D's bone must be assigned to PhysicalBone3D correctly; it means that `get_bone_id` should return a valid id (`>= 0`).

## Properties

- `angular_damp: float` = `0.0` — Damps the body's rotation.
- `angular_damp_mode: PhysicalBone3D.DampMode` = `0` — Defines how `angular_damp` is applied.
- `angular_velocity: Vector3` = `Vector3(0, 0, 0)` — The PhysicalBone3D's rotational velocity in radians per second.
- `body_offset: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — Sets the body's transform.
- `bounce: float` = `0.0` — The body's bounciness.
- `can_sleep: bool` = `true` — If `true`, the body is deactivated when there is no movement, so it will not take part in the simulation until it is awakened by an external force.
- `custom_integrator: bool` = `false` — If `true`, the standard force integration (like gravity or damping) will be disabled for this body.
- `friction: float` = `1.0` — The body's friction, from `0` (frictionless) to `1` (max friction).
- `gravity_scale: float` = `1.0` — This is multiplied by `ProjectSettings.physics/3d/default_gravity` to produce this body's gravity.
- `joint_offset: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — Sets the joint's transform.
- `joint_rotation: Vector3` = `Vector3(0, 0, 0)` — Sets the joint's rotation in radians.
- `joint_type: PhysicalBone3D.JointType` = `0` — Sets the joint type.
- `linear_damp: float` = `0.0` — Damps the body's movement.
- `linear_damp_mode: PhysicalBone3D.DampMode` = `0` — Defines how `linear_damp` is applied.
- `linear_velocity: Vector3` = `Vector3(0, 0, 0)` — The body's linear velocity in units per second.
- `mass: float` = `1.0` — The body's mass.

## Methods

- `_integrate_forces(state: PhysicsDirectBodyState3D) -> void` *virtual* — Called during physics processing, allowing you to read and safely modify the simulation state for the object.
- `apply_central_impulse(impulse: Vector3) -> void` — Applies a directional impulse without affecting rotation.
- `apply_impulse(impulse: Vector3, position: Vector3 = Vector3(0, 0, 0)) -> void` — Applies a positioned impulse to the PhysicsBone3D.
- `get_bone_id() -> int` *const* — Returns the unique identifier of the PhysicsBone3D.
- `get_joint_rid() -> RID` *const* — Returns the joint's internal RID from the PhysicsServer3D.
- `get_simulate_physics() -> bool` — Returns `true` if the PhysicsBone3D is allowed to simulate physics.
- `is_simulating_physics() -> bool` — Returns `true` if the PhysicsBone3D is currently simulating physics.

## Enum DampMode

- `DAMP_MODE_COMBINE = 0` — In this mode, the body's damping value is added to any value set in areas or the default value.
- `DAMP_MODE_REPLACE = 1` — In this mode, the body's damping value replaces any value set in areas or the default value.

## Enum JointType

- `JOINT_TYPE_NONE = 0` — No joint is applied to the PhysicsBone3D.
- `JOINT_TYPE_PIN = 1` — A pin joint is applied to the PhysicsBone3D.
- `JOINT_TYPE_CONE = 2` — A cone joint is applied to the PhysicsBone3D.
- `JOINT_TYPE_HINGE = 3` — A hinge joint is applied to the PhysicsBone3D.
- `JOINT_TYPE_SLIDER = 4` — A slider joint is applied to the PhysicsBone3D.
- `JOINT_TYPE_6DOF = 5` — A 6 degrees of freedom joint is applied to the PhysicsBone3D.
