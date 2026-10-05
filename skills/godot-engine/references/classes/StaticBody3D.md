# StaticBody3D

**Inherits:** PhysicsBody3D

A 3D physics body that can't be moved by external forces. When moved manually, it doesn't affect other bodies in its path.

A static 3D physics body. It can't be moved by external forces or contacts, but can be moved manually by other means such as code, AnimationMixers (with `AnimationMixer.callback_mode_process` set to `AnimationMixer.ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS`), and RemoteTransform3D. When StaticBody3D is moved, it is teleported to its new position without affecting other physics bodies in its path. If this is not desired, use AnimatableBody3D instead.

## Properties

- `constant_angular_velocity: Vector3` = `Vector3(0, 0, 0)` — The body's constant angular velocity.
- `constant_linear_velocity: Vector3` = `Vector3(0, 0, 0)` — The body's constant linear velocity.
- `physics_material_override: PhysicsMaterial` — The physics material override for the body.
