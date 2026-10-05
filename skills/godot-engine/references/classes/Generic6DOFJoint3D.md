# Generic6DOFJoint3D

**Inherits:** Joint3D

A physics joint that allows for complex movement and rotation between two 3D physics bodies.

The Generic6DOFJoint3D (6 Degrees Of Freedom) joint allows for implementing custom types of joints by locking the rotation and translation of certain axes. The first 3 DOF represent the linear motion of the physics bodies and the last 3 DOF represent the angular motion of the physics bodies. Each axis can be either locked, or limited.

## Properties

- `angular_drive_x/torque_limit: float` = `3.4028235e+38` — The maximum torque the joint can apply around the X angular axis.
- `angular_drive_y/torque_limit: float` = `3.4028235e+38` — The maximum torque the joint can apply around the Y angular axis.
- `angular_drive_z/torque_limit: float` = `3.4028235e+38` — The maximum torque the joint can apply around the Z angular axis.
- `angular_limit_x/damping: float` = `1.0` — The amount of rotational damping across the X axis.
- `angular_limit_x/enabled: bool` = `true` — If `true`, rotation across the X axis is limited.
- `angular_limit_x/erp: float` = `0.5` — When rotating across the X axis, this error tolerance factor defines how much the correction gets slowed down.
- `angular_limit_x/force_limit: float` = `0.0` — The maximum amount of force that can occur, when rotating around the X axis.
- `angular_limit_x/lower_angle: float` = `0.0` — The minimum rotation in negative direction to break loose and rotate around the X axis.
- `angular_limit_x/restitution: float` = `0.0` — The amount of rotational restitution across the X axis.
- `angular_limit_x/softness: float` = `0.5` — The speed of all rotations across the X axis.
- `angular_limit_x/upper_angle: float` = `0.0` — The minimum rotation in positive direction to break loose and rotate around the X axis.
- `angular_limit_y/damping: float` = `1.0` — The amount of rotational damping across the Y axis.
- `angular_limit_y/enabled: bool` = `true` — If `true`, rotation across the Y axis is limited.
- `angular_limit_y/erp: float` = `0.5` — When rotating across the Y axis, this error tolerance factor defines how much the correction gets slowed down.
- `angular_limit_y/force_limit: float` = `0.0` — The maximum amount of force that can occur, when rotating around the Y axis.
- `angular_limit_y/lower_angle: float` = `0.0` — The minimum rotation in negative direction to break loose and rotate around the Y axis.
- `angular_limit_y/restitution: float` = `0.0` — The amount of rotational restitution across the Y axis.
- `angular_limit_y/softness: float` = `0.5` — The speed of all rotations across the Y axis.
- `angular_limit_y/upper_angle: float` = `0.0` — The minimum rotation in positive direction to break loose and rotate around the Y axis.
- `angular_limit_z/damping: float` = `1.0` — The amount of rotational damping across the Z axis.
- `angular_limit_z/enabled: bool` = `true` — If `true`, rotation across the Z axis is limited.
- `angular_limit_z/erp: float` = `0.5` — When rotating across the Z axis, this error tolerance factor defines how much the correction gets slowed down.
- `angular_limit_z/force_limit: float` = `0.0` — The maximum amount of force that can occur, when rotating around the Z axis.
- `angular_limit_z/lower_angle: float` = `0.0` — The minimum rotation in negative direction to break loose and rotate around the Z axis.
- `angular_limit_z/restitution: float` = `0.0` — The amount of rotational restitution across the Z axis.
- `angular_limit_z/softness: float` = `0.5` — The speed of all rotations across the Z axis.
- `angular_limit_z/upper_angle: float` = `0.0` — The minimum rotation in positive direction to break loose and rotate around the Z axis.
- `angular_motor_x/enabled: bool` = `false` — If `true`, a rotating motor at the X axis is enabled.
- `angular_motor_x/force_limit: float` = `300.0` *(deprecated)* — Maximum acceleration for the motor at the X axis.
- `angular_motor_x/target_velocity: float` = `0.0` — Target speed for the motor at the X axis.
- `angular_motor_y/enabled: bool` = `false` — If `true`, a rotating motor at the Y axis is enabled.
- `angular_motor_y/force_limit: float` = `300.0` *(deprecated)* — Maximum acceleration for the motor at the Y axis.
- `angular_motor_y/target_velocity: float` = `0.0` — Target speed for the motor at the Y axis.
- `angular_motor_z/enabled: bool` = `false` — If `true`, a rotating motor at the Z axis is enabled.
- `angular_motor_z/force_limit: float` = `300.0` *(deprecated)* — Maximum acceleration for the motor at the Z axis.
- `angular_motor_z/target_velocity: float` = `0.0` — Target speed for the motor at the Z axis.
- `angular_spring_x/damping: float` = `0.0` — 
- `angular_spring_x/enabled: bool` = `false` — 
- `angular_spring_x/equilibrium_point: float` = `0.0` — 
- `angular_spring_x/stiffness: float` = `0.0` — 
- `angular_spring_y/damping: float` = `0.0` — 
- `angular_spring_y/enabled: bool` = `false` — 
- `angular_spring_y/equilibrium_point: float` = `0.0` — 
- `angular_spring_y/stiffness: float` = `0.0` — 
- `angular_spring_z/damping: float` = `0.0` — 
- `angular_spring_z/enabled: bool` = `false` — 
- `angular_spring_z/equilibrium_point: float` = `0.0` — 
- `angular_spring_z/stiffness: float` = `0.0` — 
- `linear_drive_x/force_limit: float` = `3.4028235e+38` — The maximum force the joint can apply along the X linear axis.
- `linear_drive_y/force_limit: float` = `3.4028235e+38` — The maximum force the joint can apply along the Y linear axis.
- `linear_drive_z/force_limit: float` = `3.4028235e+38` — The maximum force the joint can apply along the Z linear axis.
- `linear_limit_x/damping: float` = `1.0` — The amount of damping that happens at the X motion.
- `linear_limit_x/enabled: bool` = `true` — If `true`, the linear motion across the X axis is limited.
- `linear_limit_x/lower_distance: float` = `0.0` — The minimum difference between the pivot points' X axis.
- `linear_limit_x/restitution: float` = `0.5` — The amount of restitution on the X axis movement.
- `linear_limit_x/softness: float` = `0.7` — A factor applied to the movement across the X axis.
- `linear_limit_x/upper_distance: float` = `0.0` — The maximum difference between the pivot points' X axis.
- `linear_limit_y/damping: float` = `1.0` — The amount of damping that happens at the Y motion.
- `linear_limit_y/enabled: bool` = `true` — If `true`, the linear motion across the Y axis is limited.
- `linear_limit_y/lower_distance: float` = `0.0` — The minimum difference between the pivot points' Y axis.
- `linear_limit_y/restitution: float` = `0.5` — The amount of restitution on the Y axis movement.
- `linear_limit_y/softness: float` = `0.7` — A factor applied to the movement across the Y axis.
- `linear_limit_y/upper_distance: float` = `0.0` — The maximum difference between the pivot points' Y axis.
- `linear_limit_z/damping: float` = `1.0` — The amount of damping that happens at the Z motion.
- `linear_limit_z/enabled: bool` = `true` — If `true`, the linear motion across the Z axis is limited.
- `linear_limit_z/lower_distance: float` = `0.0` — The minimum difference between the pivot points' Z axis.
- `linear_limit_z/restitution: float` = `0.5` — The amount of restitution on the Z axis movement.
- `linear_limit_z/softness: float` = `0.7` — A factor applied to the movement across the Z axis.
- `linear_limit_z/upper_distance: float` = `0.0` — The maximum difference between the pivot points' Z axis.
- `linear_motor_x/enabled: bool` = `false` — If `true`, then there is a linear motor on the X axis.
- `linear_motor_x/force_limit: float` = `0.0` *(deprecated)* — The maximum force the linear motor can apply on the X axis while trying to reach the target velocity.
- `linear_motor_x/target_velocity: float` = `0.0` — The speed that the linear motor will attempt to reach on the X axis.
- `linear_motor_y/enabled: bool` = `false` — If `true`, then there is a linear motor on the Y axis.
- `linear_motor_y/force_limit: float` = `0.0` *(deprecated)* — The maximum force the linear motor can apply on the Y axis while trying to reach the target velocity.
- `linear_motor_y/target_velocity: float` = `0.0` — The speed that the linear motor will attempt to reach on the Y axis.
- `linear_motor_z/enabled: bool` = `false` — If `true`, then there is a linear motor on the Z axis.
- `linear_motor_z/force_limit: float` = `0.0` *(deprecated)* — The maximum force the linear motor can apply on the Z axis while trying to reach the target velocity.
- `linear_motor_z/target_velocity: float` = `0.0` — The speed that the linear motor will attempt to reach on the Z axis.
- `linear_spring_x/damping: float` = `0.01` — 
- `linear_spring_x/enabled: bool` = `false` — 
- `linear_spring_x/equilibrium_point: float` = `0.0` — 
- `linear_spring_x/stiffness: float` = `0.01` — 
- `linear_spring_y/damping: float` = `0.01` — 
- `linear_spring_y/enabled: bool` = `false` — 
- `linear_spring_y/equilibrium_point: float` = `0.0` — 
- `linear_spring_y/stiffness: float` = `0.01` — 
- `linear_spring_z/damping: float` = `0.01` — 
- `linear_spring_z/enabled: bool` = `false` — 
- `linear_spring_z/equilibrium_point: float` = `0.0` — 
- `linear_spring_z/stiffness: float` = `0.01` — 

## Methods

- `clear_angular_target_rotation() -> void` — Clears the quaternion angular target.
- `get_angular_target_rotation() -> Quaternion` *const* — Returns the joint's current angular target as a body-space quaternion.
- `get_flag_x(flag: Generic6DOFJoint3D.Flag) -> bool` *const*
- `get_flag_y(flag: Generic6DOFJoint3D.Flag) -> bool` *const*
- `get_flag_z(flag: Generic6DOFJoint3D.Flag) -> bool` *const*
- `get_param_x(param: Generic6DOFJoint3D.Param) -> float` *const*
- `get_param_y(param: Generic6DOFJoint3D.Param) -> float` *const*
- `get_param_z(param: Generic6DOFJoint3D.Param) -> float` *const*
- `has_target_rotation() -> bool` *const* — Returns `true` if a quaternion angular target was explicitly set via `set_angular_target_rotation` and has not been cleared.
- `set_angular_target_rotation(target_rotation: Quaternion) -> void` — Sets the target angular orientation as a body-space quaternion describing the desired orientation of body B relative to body A.
- `set_flag_x(flag: Generic6DOFJoint3D.Flag, value: bool) -> void`
- `set_flag_y(flag: Generic6DOFJoint3D.Flag, value: bool) -> void`
- `set_flag_z(flag: Generic6DOFJoint3D.Flag, value: bool) -> void`
- `set_param_x(param: Generic6DOFJoint3D.Param, value: float) -> void`
- `set_param_y(param: Generic6DOFJoint3D.Param, value: float) -> void`
- `set_param_z(param: Generic6DOFJoint3D.Param, value: float) -> void`

## Enum Param

- `PARAM_LINEAR_LOWER_LIMIT = 0` — The minimum difference between the pivot points' axes.
- `PARAM_LINEAR_UPPER_LIMIT = 1` — The maximum difference between the pivot points' axes.
- `PARAM_LINEAR_LIMIT_SOFTNESS = 2` — A factor applied to the movement across the axes.
- `PARAM_LINEAR_RESTITUTION = 3` — The amount of restitution on the axes' movement.
- `PARAM_LINEAR_DAMPING = 4` — The amount of damping that happens at the linear motion across the axes.
- `PARAM_LINEAR_MOTOR_TARGET_VELOCITY = 5` — The velocity the linear motor will try to reach.
- `PARAM_LINEAR_MOTOR_FORCE_LIMIT = 6` — The maximum force the linear motor will apply while trying to reach the velocity target.
- `PARAM_LINEAR_SPRING_STIFFNESS = 7` — 
- `PARAM_LINEAR_SPRING_DAMPING = 8` — 
- `PARAM_LINEAR_SPRING_EQUILIBRIUM_POINT = 9` — 
- `PARAM_ANGULAR_LOWER_LIMIT = 10` — The minimum rotation in negative direction to break loose and rotate around the axes.
- `PARAM_ANGULAR_UPPER_LIMIT = 11` — The minimum rotation in positive direction to break loose and rotate around the axes.
- `PARAM_ANGULAR_LIMIT_SOFTNESS = 12` — The speed of all rotations across the axes.
- `PARAM_ANGULAR_DAMPING = 13` — The amount of rotational damping across the axes.
- `PARAM_ANGULAR_RESTITUTION = 14` — The amount of rotational restitution across the axes.
- `PARAM_ANGULAR_FORCE_LIMIT = 15` — The maximum amount of force that can occur, when rotating around the axes.
- `PARAM_ANGULAR_ERP = 16` — When rotating across the axes, this error tolerance factor defines how much the correction gets slowed down.
- `PARAM_ANGULAR_MOTOR_TARGET_VELOCITY = 17` — Target speed for the motor at the axes.
- `PARAM_ANGULAR_MOTOR_FORCE_LIMIT = 18` — Maximum acceleration for the motor at the axes.
- `PARAM_ANGULAR_SPRING_STIFFNESS = 19` — 
- `PARAM_ANGULAR_SPRING_DAMPING = 20` — 
- `PARAM_ANGULAR_SPRING_EQUILIBRIUM_POINT = 21` — 
- `PARAM_LINEAR_DRIVE_FORCE_LIMIT = 22` — The maximum force the joint can apply along this linear axis.
- `PARAM_ANGULAR_DRIVE_TORQUE_LIMIT = 23` — The maximum torque the joint can apply around this angular axis.
- `PARAM_MAX = 24` — Represents the size of the `Param` enum.

## Enum Flag

- `FLAG_ENABLE_LINEAR_LIMIT = 0` — If enabled, linear motion is possible within the given limits.
- `FLAG_ENABLE_ANGULAR_LIMIT = 1` — If enabled, rotational motion is possible within the given limits.
- `FLAG_ENABLE_LINEAR_SPRING = 3` — 
- `FLAG_ENABLE_ANGULAR_SPRING = 2` — 
- `FLAG_ENABLE_ANGULAR_MOTOR = 4` — If enabled, there is a rotational or angular motor across these axes.
- `FLAG_ENABLE_MOTOR = 4` — If enabled, there is a rotational or angular motor across these axes.
- `FLAG_ENABLE_LINEAR_MOTOR = 5` — If enabled, there is a linear motor across these axes.
- `FLAG_MAX = 6` — Represents the size of the `Flag` enum.
