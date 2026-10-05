# BoneConstraint3D

**Inherits:** SkeletonModifier3D

A node that may modify Skeleton3D's bone with associating the two bones.

Base class of SkeletonModifier3D that modifies the bone set in `set_apply_bone` based on the transform of the bone retrieved by `get_reference_bone`. Note: Most methods in this class take an `index` parameter. This parameter specifies which setting list entry to return if the IK has multiple entries (e.g. `settings/<index>/amount`).

## Methods

- `clear_setting() -> void` — Clear all settings.
- `get_amount(index: int) -> float` *const* — Returns the apply amount of the setting at `index`.
- `get_apply_bone(index: int) -> int` *const* — Returns the apply bone of the setting at `index`.
- `get_apply_bone_name(index: int) -> String` *const* — Returns the apply bone name of the setting at `index`.
- `get_reference_bone(index: int) -> int` *const* — Returns the reference bone of the setting at `index`.
- `get_reference_bone_name(index: int) -> String` *const* — Returns the reference bone name of the setting at `index`.
- `get_reference_node(index: int) -> NodePath` *const* — Returns the reference node path of the setting at `index`.
- `get_reference_type(index: int) -> int[BoneConstraint3D.ReferenceType]` *const* — Returns the reference target type of the setting at `index`.
- `get_setting_count() -> int` *const* — Returns the number of settings in the modifier.
- `set_amount(index: int, amount: float) -> void` — Sets the apply amount of the setting at `index` to `amount`.
- `set_apply_bone(index: int, bone: int) -> void` — Sets the apply bone of the setting at `index` to `bone`.
- `set_apply_bone_name(index: int, bone_name: String) -> void` — Sets the apply bone of the setting at `index` to `bone_name`.
- `set_reference_bone(index: int, bone: int) -> void` — Sets the reference bone of the setting at `index` to `bone`.
- `set_reference_bone_name(index: int, bone_name: String) -> void` — Sets the reference bone of the setting at `index` to `bone_name`.
- `set_reference_node(index: int, node: NodePath) -> void` — Sets the reference node path of the setting at `index` to `node`.
- `set_reference_type(index: int, type: BoneConstraint3D.ReferenceType) -> void` — Sets the reference target type of the setting at `index` to `type`.
- `set_setting_count(count: int) -> void` — Sets the number of settings in the modifier.

## Enum ReferenceType

- `REFERENCE_TYPE_BONE = 0` — The reference target is a bone.
- `REFERENCE_TYPE_NODE = 1` — The reference target is a Node3D.
