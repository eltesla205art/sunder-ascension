# AnimatableBody2D

**Inherits:** StaticBody2D

A 2D physics body that can't be moved by external forces. When moved manually, it affects other bodies in its path.

An animatable 2D physics body. It can't be moved by external forces or contacts, but can be moved manually by other means such as code, AnimationMixers (with `AnimationMixer.callback_mode_process` set to `AnimationMixer.ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS`), and RemoteTransform2D. When AnimatableBody2D is moved, its linear and angular velocity are estimated and used to affect other physics bodies in its path. This makes it useful for moving platforms, doors, and other moving objects.

## Properties

- `sync_to_physics: bool` = `true` — If `true`, the body's movement will be synchronized to the physics frame.
