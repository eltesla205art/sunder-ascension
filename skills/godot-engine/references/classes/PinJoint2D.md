# PinJoint2D

**Inherits:** Joint2D

A physics joint that attaches two 2D physics bodies at a single point, allowing them to freely rotate.

A physics joint that attaches two 2D physics bodies at a single point, allowing them to freely rotate. For example, a RigidBody2D can be attached to a StaticBody2D to create a pendulum or a seesaw.

## Properties

- `angular_limit_enabled: bool` = `false` — If `true`, the pin maximum and minimum rotation, defined by `angular_limit_lower` and `angular_limit_upper` are applied.
- `angular_limit_lower: float` = `0.0` — The minimum rotation.
- `angular_limit_upper: float` = `0.0` — The maximum rotation.
- `motor_enabled: bool` = `false` — When activated, a motor turns the pin.
- `motor_target_velocity: float` = `0.0` — Target speed for the motor.
- `softness: float` = `0.0` — The higher this value, the more the bond to the pinned partner can flex.
