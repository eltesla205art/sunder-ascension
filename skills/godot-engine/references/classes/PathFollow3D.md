# PathFollow3D

**Inherits:** Node3D

Point sampler for a Path3D.

This node takes its parent Path3D, and returns the coordinates of a point within it, given a distance from the first vertex. It is useful for making other nodes follow a path, without coding the movement pattern. For that, the nodes must be children of this node. The descendant nodes will then move accordingly when setting the `progress` in this node.

## Properties

- `cubic_interp: bool` = `true` — If `true`, the position between two cached points is interpolated cubically, and linearly otherwise.
- `h_offset: float` = `0.0` — The node's offset along the curve.
- `loop: bool` = `true` — If `true`, any offset outside the path's length will wrap around, instead of stopping at the ends.
- `progress: float` = `0.0` — The distance from the first vertex, measured in 3D units along the path.
- `progress_ratio: float` = `0.0` — The distance from the first vertex, considering 0.0 as the first vertex and 1.0 as the last.
- `rotation_mode: PathFollow3D.RotationMode` = `3` — Allows or forbids rotation on one or more axes, depending on the `RotationMode` constants being used.
- `tilt_enabled: bool` = `true` — If `true`, the tilt property of Curve3D takes effect.
- `use_model_front: bool` = `false` — If `true`, the node moves on the travel path with orienting the +Z axis as forward.
- `v_offset: float` = `0.0` — The node's offset perpendicular to the curve.

## Methods

- `correct_posture(transform: Transform3D, rotation_mode: PathFollow3D.RotationMode) -> Transform3D` *static* — Correct the `transform`.

## Enum RotationMode

- `ROTATION_NONE = 0` — Forbids the PathFollow3D to rotate.
- `ROTATION_Y = 1` — Allows the PathFollow3D to rotate in the Y axis only.
- `ROTATION_XY = 2` — Allows the PathFollow3D to rotate in both the X, and Y axes.
- `ROTATION_XYZ = 3` — Allows the PathFollow3D to rotate in any axis.
- `ROTATION_ORIENTED = 4` — Uses the up vector information in a Curve3D to enforce orientation.
