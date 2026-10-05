# ConeTwistJoint3D

**Inherits:** Joint3D

A physics joint that connects two 3D physics bodies in a way that simulates a ball-and-socket joint.

A physics joint that connects two 3D physics bodies in a way that simulates a ball-and-socket joint. The twist axis is initiated as the X axis of the ConeTwistJoint3D. Once the physics bodies swing, the twist axis is calculated as the middle of the X axes of the joint in the local space of the two physics bodies. Useful for limbs like shoulders and hips, lamps hanging off a ceiling, etc.

## Properties

- `bias: float` = `0.3` — The speed with which the swing or twist will take place.
- `relaxation: float` = `1.0` — Defines, how fast the swing- and twist-speed-difference on both sides gets synced.
- `softness: float` = `0.8` — The ease with which the joint starts to twist.
- `swing_span: float` = `0.7853982` — Swing is rotation from side to side, around the axis perpendicular to the twist axis.
- `twist_span: float` = `3.1415927` — Twist is the rotation around the twist axis, this value defined how far the joint can twist.

## Methods

- `get_param(param: ConeTwistJoint3D.Param) -> float` *const* — Returns the value of the specified parameter.
- `set_param(param: ConeTwistJoint3D.Param, value: float) -> void` — Sets the value of the specified parameter.

## Enum Param

- `PARAM_SWING_SPAN = 0` — Swing is rotation from side to side, around the axis perpendicular to the twist axis.
- `PARAM_TWIST_SPAN = 1` — Twist is the rotation around the twist axis, this value defined how far the joint can twist.
- `PARAM_BIAS = 2` — The speed with which the swing or twist will take place.
- `PARAM_SOFTNESS = 3` — The ease with which the joint starts to twist.
- `PARAM_RELAXATION = 4` — Defines, how fast the swing- and twist-speed-difference on both sides gets synced.
- `PARAM_MAX = 5` — Represents the size of the `Param` enum.
