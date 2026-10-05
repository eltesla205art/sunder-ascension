# CopyTransformModifier3D

**Inherits:** BoneConstraint3D

A SkeletonModifier3D that apply transform to the bone which copied from reference.

Apply the copied transform of the bone set by `BoneConstraint3D.set_reference_bone` to the bone set by `BoneConstraint3D.set_apply_bone` with processing it with some masks and options. There are 4 ways to apply the transform, depending on the combination of `set_relative` and `set_additive`. Relative + Additive: - Extract reference pose relative to the rest and add it to the apply bone's pose. Relative + Not Additive: - Extract reference pose relative to the rest and add it to the apply bone's rest.

## Properties

- `setting_count: int` = `0` — The number of settings in the modifier.

## Methods

- `get_axis_flags(index: int) -> int[CopyTransformModifier3D.AxisFlag]` *const* — Returns the axis flags of the setting at `index`.
- `get_copy_flags(index: int) -> int[CopyTransformModifier3D.TransformFlag]` *const* — Returns the copy flags of the setting at `index`.
- `get_invert_flags(index: int) -> int[CopyTransformModifier3D.AxisFlag]` *const* — Returns the invert flags of the setting at `index`.
- `is_additive(index: int) -> bool` *const* — Returns `true` if the additive option is enabled in the setting at `index`.
- `is_axis_x_enabled(index: int) -> bool` *const* — Returns `true` if the enable flags has the flag for the X-axis in the setting at `index`.
- `is_axis_x_inverted(index: int) -> bool` *const* — Returns `true` if the invert flags has the flag for the X-axis in the setting at `index`.
- `is_axis_y_enabled(index: int) -> bool` *const* — Returns `true` if the enable flags has the flag for the Y-axis in the setting at `index`.
- `is_axis_y_inverted(index: int) -> bool` *const* — Returns `true` if the invert flags has the flag for the Y-axis in the setting at `index`.
- `is_axis_z_enabled(index: int) -> bool` *const* — Returns `true` if the enable flags has the flag for the Z-axis in the setting at `index`.
- `is_axis_z_inverted(index: int) -> bool` *const* — Returns `true` if the invert flags has the flag for the Z-axis in the setting at `index`.
- `is_global(index: int) -> bool` *const* — Returns `true` if the global option is enabled in the setting at `index`.
- `is_position_copying(index: int) -> bool` *const* — Returns `true` if the copy flags has the flag for the position in the setting at `index`.
- `is_relative(index: int) -> bool` *const* — Returns `true` if the relative option is enabled in the setting at `index`.
- `is_rotation_copying(index: int) -> bool` *const* — Returns `true` if the copy flags has the flag for the rotation in the setting at `index`.
- `is_scale_copying(index: int) -> bool` *const* — Returns `true` if the copy flags has the flag for the scale in the setting at `index`.
- `set_additive(index: int, enabled: bool) -> void` — Sets additive option in the setting at `index` to `enabled`.
- `set_axis_flags(index: int, axis_flags: CopyTransformModifier3D.AxisFlag) -> void` — Sets the flags to copy axes.
- `set_axis_x_enabled(index: int, enabled: bool) -> void` — If `enabled` is `true`, the X-axis will be copied.
- `set_axis_x_inverted(index: int, enabled: bool) -> void` — If `enabled` is `true`, the X-axis will be inverted.
- `set_axis_y_enabled(index: int, enabled: bool) -> void` — If `enabled` is `true`, the Y-axis will be copied.
- `set_axis_y_inverted(index: int, enabled: bool) -> void` — If `enabled` is `true`, the Y-axis will be inverted.
- `set_axis_z_enabled(index: int, enabled: bool) -> void` — If `enabled` is `true`, the Z-axis will be copied.
- `set_axis_z_inverted(index: int, enabled: bool) -> void` — If `enabled` is `true`, the Z-axis will be inverted.
- `set_copy_flags(index: int, copy_flags: CopyTransformModifier3D.TransformFlag) -> void` — Sets the flags to process the transform operations.
- `set_copy_position(index: int, enabled: bool) -> void` — If `enabled` is `true`, the position will be copied.
- `set_copy_rotation(index: int, enabled: bool) -> void` — If `enabled` is `true`, the rotation will be copied.
- `set_copy_scale(index: int, enabled: bool) -> void` — If `enabled` is `true`, the scale will be copied.
- `set_global(index: int, enabled: bool) -> void` — Sets the global option in the setting at `index` to `enabled`.
- `set_invert_flags(index: int, axis_flags: CopyTransformModifier3D.AxisFlag) -> void` — Sets the flags to inverte axes.
- `set_relative(index: int, enabled: bool) -> void` — Sets relative option in the setting at `index` to `enabled`.

## Enum TransformFlag

- `TRANSFORM_FLAG_POSITION = 1` — If set, allows to copy the position.
- `TRANSFORM_FLAG_ROTATION = 2` — If set, allows to copy the rotation.
- `TRANSFORM_FLAG_SCALE = 4` — If set, allows to copy the scale.
- `TRANSFORM_FLAG_ALL = 7` — If set, allows to copy the position/rotation/scale.

## Enum AxisFlag

- `AXIS_FLAG_X = 1` — If set, allows to process the X-axis.
- `AXIS_FLAG_Y = 2` — If set, allows to process the Y-axis.
- `AXIS_FLAG_Z = 4` — If set, allows to process the Z-axis.
- `AXIS_FLAG_ALL = 7` — If set, allows to process the all axes.
