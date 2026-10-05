# SplineIK3D

**Inherits:** ChainIK3D

A SkeletonModifier3D for aligning bones along a Path3D.

A SkeletonModifier3D for aligning bones along a Path3D. The smoothness of the fitting depends on the `Curve3D.bake_interval`. If you want the Path3D to attach to a specific bone, it is recommended to place a ModifierBoneTarget3D before the SplineIK3D in the SkeletonModifier3D list (children of the Skeleton3D), and then place a Path3D as the ModifierBoneTarget3D's child. Bone twist is determined based on the `Curve3D.get_point_tilt`.

## Properties

- `setting_count: int` = `0` — The number of settings.

## Methods

- `get_path_3d(index: int) -> NodePath` *const* — Returns the node path of the Path3D which is describing the path.
- `get_tilt_fade_in(index: int) -> int` *const* — Returns the tilt interpolation method used between the root bone and the start point of the Curve3D when they are apart.
- `get_tilt_fade_out(index: int) -> int` *const* — Returns the tilt interpolation method used between the end bone and the end point of the Curve3D when they are apart.
- `is_tilt_enabled(index: int) -> bool` *const* — Returns if the tilt property of the Curve3D affects the bone twist.
- `set_path_3d(index: int, path_3d: NodePath) -> void` — Sets the node path of the Path3D which is describing the path.
- `set_tilt_enabled(index: int, enabled: bool) -> void` — Sets if the tilt property of the Curve3D should affect the bone twist.
- `set_tilt_fade_in(index: int, size: int) -> void` — If `size` is greater than `0`, the tilt is interpolated between `size` start bones from the start point of the Curve3D when they are apart.
- `set_tilt_fade_out(index: int, size: int) -> void` — If `size` is greater than `0`, the tilt is interpolated between `size` end bones from the end point of the Curve3D when they are apart.
