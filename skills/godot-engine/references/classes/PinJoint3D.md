# PinJoint3D

**Inherits:** Joint3D

A physics joint that attaches two 3D physics bodies at a single point, allowing them to freely rotate.

A physics joint that attaches two 3D physics bodies at a single point, allowing them to freely rotate. For example, a RigidBody3D can be attached to a StaticBody3D to create a pendulum or a seesaw.

## Properties

- `params/bias: float` = `0.3` — The force with which the pinned objects stay in positional relation to each other.
- `params/damping: float` = `1.0` — The force with which the pinned objects stay in velocity relation to each other.
- `params/impulse_clamp: float` = `0.0` — If above 0, this value is the maximum value for an impulse that this Joint3D produces.

## Methods

- `get_param(param: PinJoint3D.Param) -> float` *const* — Returns the value of the specified parameter.
- `set_param(param: PinJoint3D.Param, value: float) -> void` — Sets the value of the specified parameter.

## Enum Param

- `PARAM_BIAS = 0` — The force with which the pinned objects stay in positional relation to each other.
- `PARAM_DAMPING = 1` — The force with which the pinned objects stay in velocity relation to each other.
- `PARAM_IMPULSE_CLAMP = 2` — If above 0, this value is the maximum value for an impulse that this Joint3D produces.
