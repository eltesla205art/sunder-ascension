# ConvertTransformModifier3D

**Inherits:** BoneConstraint3D

A SkeletonModifier3D that apply transform to the bone which converted from reference.

Apply the copied transform of the bone set by `BoneConstraint3D.set_reference_bone` to the bone set by `BoneConstraint3D.set_apply_bone` about the specific axis with remapping it with some options. There are 4 ways to apply the transform, depending on the combination of `set_relative` and `set_additive`. Relative + Additive: - Extract reference pose relative to the rest and add it to the apply bone's pose. Relative + Not Additive: - Extract reference pose relative to the rest and add it to the apply bone's rest.

## Properties

- `setting_count: int` = `0` — The number of settings in the modifier.

## Methods

- `get_apply_axis(index: int) -> int[Vector3.Axis]` *const* — Returns the axis of the remapping destination transform.
- `get_apply_range_max(index: int) -> float` *const* — Returns the maximum value of the remapping destination range.
- `get_apply_range_min(index: int) -> float` *const* — Returns the minimum value of the remapping destination range.
- `get_apply_transform_mode(index: int) -> int[ConvertTransformModifier3D.TransformMode]` *const* — Returns the operation of the remapping destination transform.
- `get_reference_axis(index: int) -> int[Vector3.Axis]` *const* — Returns the axis of the remapping source transform.
- `get_reference_range_max(index: int) -> float` *const* — Returns the maximum value of the remapping source range.
- `get_reference_range_min(index: int) -> float` *const* — Returns the minimum value of the remapping source range.
- `get_reference_transform_mode(index: int) -> int[ConvertTransformModifier3D.TransformMode]` *const* — Returns the operation of the remapping source transform.
- `is_additive(index: int) -> bool` *const* — Returns `true` if the additive option is enabled in the setting at `index`.
- `is_global(index: int) -> bool` *const* — Returns `true` if the global option is enabled in the setting at `index`.
- `is_relative(index: int) -> bool` *const* — Returns `true` if the relative option is enabled in the setting at `index`.
- `set_additive(index: int, enabled: bool) -> void` — Sets additive option in the setting at `index` to `enabled`.
- `set_apply_axis(index: int, axis: Vector3.Axis) -> void` — Sets the axis of the remapping destination transform.
- `set_apply_range_max(index: int, range_max: float) -> void` — Sets the maximum value of the remapping destination range.
- `set_apply_range_min(index: int, range_min: float) -> void` — Sets the minimum value of the remapping destination range.
- `set_apply_transform_mode(index: int, transform_mode: ConvertTransformModifier3D.TransformMode) -> void` — Sets the operation of the remapping destination transform.
- `set_global(index: int, enabled: bool) -> void` — Sets the global option in the setting at `index` to `enabled`.
- `set_reference_axis(index: int, axis: Vector3.Axis) -> void` — Sets the axis of the remapping source transform.
- `set_reference_range_max(index: int, range_max: float) -> void` — Sets the maximum value of the remapping source range.
- `set_reference_range_min(index: int, range_min: float) -> void` — Sets the minimum value of the remapping source range.
- `set_reference_transform_mode(index: int, transform_mode: ConvertTransformModifier3D.TransformMode) -> void` — Sets the operation of the remapping source transform.
- `set_relative(index: int, enabled: bool) -> void` — Sets relative option in the setting at `index` to `enabled`.

## Enum TransformMode

- `TRANSFORM_MODE_POSITION = 0` — Convert with position.
- `TRANSFORM_MODE_ROTATION = 1` — Convert with rotation.
- `TRANSFORM_MODE_SCALE = 2` — Convert with scale.
