# AimModifier3D

**Inherits:** BoneConstraint3D

The AimModifier3D rotates a bone to look at a reference bone.

This is a simple version of LookAtModifier3D that only allows bone to the reference without advanced options such as angle limitation or time-based interpolation. The feature is simplified, but instead it is implemented with smooth tracking without euler, see `set_use_euler`.

## Properties

- `setting_count: int` = `0` — The number of settings in the modifier.

## Methods

- `get_forward_axis(index: int) -> int[SkeletonModifier3D.BoneAxis]` *const* — Returns the forward axis of the bone.
- `get_primary_rotation_axis(index: int) -> int[Vector3.Axis]` *const* — Returns the axis of the first rotation.
- `is_relative(index: int) -> bool` *const* — Returns `true` if the relative option is enabled in the setting at `index`.
- `is_using_euler(index: int) -> bool` *const* — Returns `true` if it provides rotation with using euler.
- `is_using_secondary_rotation(index: int) -> bool` *const* — Returns `true` if it provides rotation by two axes.
- `set_forward_axis(index: int, axis: SkeletonModifier3D.BoneAxis) -> void` — Sets the forward axis of the bone.
- `set_primary_rotation_axis(index: int, axis: Vector3.Axis) -> void` — Sets the axis of the first rotation.
- `set_relative(index: int, enabled: bool) -> void` — Sets relative option in the setting at `index` to `enabled`.
- `set_use_euler(index: int, enabled: bool) -> void` — If sets `enabled` to `true`, it provides rotation with using euler.
- `set_use_secondary_rotation(index: int, enabled: bool) -> void` — If sets `enabled` to `true`, it provides rotation by two axes.
