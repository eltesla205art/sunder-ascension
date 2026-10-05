# HingeJoint3D

**Inherits:** Joint3D

A physics joint that restricts the rotation of a 3D physics body around an axis relative to another physics body.

A physics joint that restricts the rotation of a 3D physics body around an axis relative to another physics body. For example, Body A can be a StaticBody3D representing a door hinge that a RigidBody3D rotates around.

## Properties

- `angular_limit/bias: float` = `0.3` — The speed with which the rotation across the axis perpendicular to the hinge gets corrected.
- `angular_limit/enable: bool` = `false` — If `true`, the hinges maximum and minimum rotation, defined by `angular_limit/lower` and `angular_limit/upper` has effects.
- `angular_limit/lower: float` = `-1.5707964` — The minimum rotation.
- `angular_limit/relaxation: float` = `1.0` — The lower this value, the more the rotation gets slowed down.
- `angular_limit/softness: float` = `0.9` *(deprecated)* — 
- `angular_limit/upper: float` = `1.5707964` — The maximum rotation.
- `motor/enable: bool` = `false` — When activated, a motor turns the hinge.
- `motor/max_impulse: float` = `1.0` — Maximum acceleration for the motor.
- `motor/target_velocity: float` = `1.0` — Target speed for the motor.
- `params/bias: float` = `0.3` — The speed with which the two bodies get pulled together when they move in different directions.

## Methods

- `get_flag(flag: HingeJoint3D.Flag) -> bool` *const* — Returns the value of the specified flag.
- `get_param(param: HingeJoint3D.Param) -> float` *const* — Returns the value of the specified parameter.
- `set_flag(flag: HingeJoint3D.Flag, enabled: bool) -> void` — If `true`, enables the specified flag.
- `set_param(param: HingeJoint3D.Param, value: float) -> void` — Sets the value of the specified parameter.

## Enum Param

- `PARAM_BIAS = 0` — The speed with which the two bodies get pulled together when they move in different directions.
- `PARAM_LIMIT_UPPER = 1` — The maximum rotation.
- `PARAM_LIMIT_LOWER = 2` — The minimum rotation.
- `PARAM_LIMIT_BIAS = 3` — The speed with which the rotation across the axis perpendicular to the hinge gets corrected.
- `PARAM_LIMIT_SOFTNESS = 4` — 
- `PARAM_LIMIT_RELAXATION = 5` — The lower this value, the more the rotation gets slowed down.
- `PARAM_MOTOR_TARGET_VELOCITY = 6` — Target speed for the motor.
- `PARAM_MOTOR_MAX_IMPULSE = 7` — Maximum acceleration for the motor.
- `PARAM_MAX = 8` — Represents the size of the `Param` enum.

## Enum Flag

- `FLAG_USE_LIMIT = 0` — If `true`, the hinges maximum and minimum rotation, defined by `angular_limit/lower` and `angular_limit/upper` has effects.
- `FLAG_ENABLE_MOTOR = 1` — When activated, a motor turns the hinge.
- `FLAG_MAX = 2` — Represents the size of the `Flag` enum.
