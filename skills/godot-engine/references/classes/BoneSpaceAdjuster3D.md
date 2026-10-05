# BoneSpaceAdjuster3D

**Inherits:** SkeletonModifier3D

Inputs a scale and converts it to the position of a child bone.

Inputs a scale and converts it to the position of a child bone. Intended for use in combination with `Skeleton3D.set_bone_skin_scale`. This modifier repositions child bones to follow the skin transformation by `Skeleton3D.set_bone_skin_scale` in cases when you want to adjust bone length using `Skeleton3D.set_bone_skin_scale` or when the bone has multiple child bones.

## Properties

- `setting_size: int` — The number of settings in the modifier.
- `use_bone_skin_scale_for_all_bones: bool` = `true` — If `true`, this modifier processes all bones for which `Skeleton3D.get_bone_skin_scale` is not `Vector3(1, 1, 1)`.

## Methods

- `clear_setting() -> void` — Clears all settings.
- `get_bone(index: int) -> int` *const* — Returns the scaled bone of the setting at `index`.
- `get_bone_name(index: int) -> StringName` *const* — Returns the scaled bone name of the setting at `index`.
- `get_bone_scale(index: int) -> Vector3` *const* — Returns the scale of the setting at `index`.
- `is_using_bone_skin_scale(index: int) -> bool` *const* — Returns whether to use the `skin_scale` property of a Skeleton3D's bone of the setting at `index`.
- `set_bone(index: int, bone: int) -> void` — Sets the scaled bone of the setting at `index`.
- `set_bone_name(index: int, bone_name: StringName) -> void` — Sets the scaled bone name of the setting at `index`.
- `set_bone_scale(index: int, scale: Vector3) -> void` — When `is_using_bone_skin_scale` returns `false`, sets the scale of the setting at `index`.
- `set_use_bone_skin_scale(index: int, enabled: bool) -> void` — Sets whether to use the `skin_scale` property of a Skeleton3D's bone of the setting at `index`.
