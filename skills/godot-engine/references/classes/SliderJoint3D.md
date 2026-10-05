# SliderJoint3D

**Inherits:** Joint3D

A physics joint that restricts the movement of a 3D physics body along an axis relative to another physics body.

A physics joint that restricts the movement of a 3D physics body along an axis relative to another physics body. For example, Body A could be a StaticBody3D representing a piston base, while Body B could be a RigidBody3D representing the piston head, moving up and down.

## Properties

- `angular_limit/damping: float` = `0.0` — The amount of damping of the rotation when the limit is surpassed.
- `angular_limit/lower_angle: float` = `0.0` — The lower limit of rotation in the slider.
- `angular_limit/restitution: float` = `0.7` — The amount of restitution of the rotation when the limit is surpassed.
- `angular_limit/softness: float` = `1.0` — A factor applied to the all rotation once the limit is surpassed.
- `angular_limit/upper_angle: float` = `0.0` — The upper limit of rotation in the slider.
- `angular_motion/damping: float` = `1.0` — The amount of damping of the rotation in the limits.
- `angular_motion/restitution: float` = `0.7` — The amount of restitution of the rotation in the limits.
- `angular_motion/softness: float` = `1.0` — A factor applied to the all rotation in the limits.
- `angular_ortho/damping: float` = `1.0` — The amount of damping of the rotation across axes orthogonal to the slider.
- `angular_ortho/restitution: float` = `0.7` — The amount of restitution of the rotation across axes orthogonal to the slider.
- `angular_ortho/softness: float` = `1.0` — A factor applied to the all rotation across axes orthogonal to the slider.
- `linear_limit/damping: float` = `1.0` — The amount of damping that happens once the limit defined by `linear_limit/lower_distance` and `linear_limit/upper_distance` is surpassed.
- `linear_limit/lower_distance: float` = `-1.0` — The minimum difference between the pivot points on their X axis before damping happens.
- `linear_limit/restitution: float` = `0.7` — The amount of restitution once the limits are surpassed.
- `linear_limit/softness: float` = `1.0` — A factor applied to the movement across the slider axis once the limits get surpassed.
- `linear_limit/upper_distance: float` = `1.0` — The maximum difference between the pivot points on their X axis before damping happens.
- `linear_motion/damping: float` = `0.0` — The amount of damping inside the slider limits.
- `linear_motion/restitution: float` = `0.7` — The amount of restitution inside the slider limits.
- `linear_motion/softness: float` = `1.0` — A factor applied to the movement across the slider axis as long as the slider is in the limits.
- `linear_ortho/damping: float` = `1.0` — The amount of damping when movement is across axes orthogonal to the slider.
- `linear_ortho/restitution: float` = `0.7` — The amount of restitution when movement is across axes orthogonal to the slider.
- `linear_ortho/softness: float` = `1.0` — A factor applied to the movement across axes orthogonal to the slider.

## Methods

- `get_param(param: SliderJoint3D.Param) -> float` *const* — Returns the value of the given parameter.
- `set_param(param: SliderJoint3D.Param, value: float) -> void` — Assigns `value` to the given parameter.

## Enum Param

- `PARAM_LINEAR_LIMIT_UPPER = 0` — Constant for accessing `linear_limit/upper_distance`.
- `PARAM_LINEAR_LIMIT_LOWER = 1` — Constant for accessing `linear_limit/lower_distance`.
- `PARAM_LINEAR_LIMIT_SOFTNESS = 2` — Constant for accessing `linear_limit/softness`.
- `PARAM_LINEAR_LIMIT_RESTITUTION = 3` — Constant for accessing `linear_limit/restitution`.
- `PARAM_LINEAR_LIMIT_DAMPING = 4` — Constant for accessing `linear_limit/damping`.
- `PARAM_LINEAR_MOTION_SOFTNESS = 5` — Constant for accessing `linear_motion/softness`.
- `PARAM_LINEAR_MOTION_RESTITUTION = 6` — Constant for accessing `linear_motion/restitution`.
- `PARAM_LINEAR_MOTION_DAMPING = 7` — Constant for accessing `linear_motion/damping`.
- `PARAM_LINEAR_ORTHOGONAL_SOFTNESS = 8` — Constant for accessing `linear_ortho/softness`.
- `PARAM_LINEAR_ORTHOGONAL_RESTITUTION = 9` — Constant for accessing `linear_motion/restitution`.
- `PARAM_LINEAR_ORTHOGONAL_DAMPING = 10` — Constant for accessing `linear_motion/damping`.
- `PARAM_ANGULAR_LIMIT_UPPER = 11` — Constant for accessing `angular_limit/upper_angle`.
- `PARAM_ANGULAR_LIMIT_LOWER = 12` — Constant for accessing `angular_limit/lower_angle`.
- `PARAM_ANGULAR_LIMIT_SOFTNESS = 13` — Constant for accessing `angular_limit/softness`.
- `PARAM_ANGULAR_LIMIT_RESTITUTION = 14` — Constant for accessing `angular_limit/restitution`.
- `PARAM_ANGULAR_LIMIT_DAMPING = 15` — Constant for accessing `angular_limit/damping`.
- `PARAM_ANGULAR_MOTION_SOFTNESS = 16` — Constant for accessing `angular_motion/softness`.
- `PARAM_ANGULAR_MOTION_RESTITUTION = 17` — Constant for accessing `angular_motion/restitution`.
- `PARAM_ANGULAR_MOTION_DAMPING = 18` — Constant for accessing `angular_motion/damping`.
- `PARAM_ANGULAR_ORTHOGONAL_SOFTNESS = 19` — Constant for accessing `angular_ortho/softness`.
- `PARAM_ANGULAR_ORTHOGONAL_RESTITUTION = 20` — Constant for accessing `angular_ortho/restitution`.
- `PARAM_ANGULAR_ORTHOGONAL_DAMPING = 21` — Constant for accessing `angular_ortho/damping`.
- `PARAM_MAX = 22` — Represents the size of the `Param` enum.
