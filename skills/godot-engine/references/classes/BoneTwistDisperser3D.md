# BoneTwistDisperser3D

**Inherits:** SkeletonModifier3D

A node that propagates and disperses the child bone's twist to the parent bones.

This BoneTwistDisperser3D allows for smooth twist interpolation between multiple bones by dispersing the end bone's twist to the parents. This only changes the twist without changing the global position of each joint. This is useful for smoothly twisting bones in combination with CopyTransformModifier3D and IK. Note: If an extracted twist is greater than 180 degrees, flipping occurs.

## Properties

- `mutable_bone_axes: bool` = `true` — If `true`, the solver retrieves the bone axis from the bone pose every frame.
- `setting_count: int` = `0` — The number of settings.

## Methods

- `clear_settings() -> void` — Clears all settings.
- `get_damping_curve(index: int) -> Curve` *const* — Returns the damping curve when `get_disperse_mode` is `DISPERSE_MODE_CUSTOM`.
- `get_disperse_mode(index: int) -> int[BoneTwistDisperser3D.DisperseMode]` *const* — Returns whether to use automatic amount assignment or to allow manual assignment.
- `get_end_bone(index: int) -> int` *const* — Returns the end bone index of the bone chain.
- `get_end_bone_direction(index: int) -> int[SkeletonModifier3D.BoneDirection]` *const* — Returns the tail direction of the end bone of the bone chain when `is_end_bone_extended` is `true`.
- `get_end_bone_name(index: int) -> String` *const* — Returns the end bone name of the bone chain.
- `get_joint_bone(index: int, joint: int) -> int` *const* — Returns the bone index at `joint` in the bone chain's joint list.
- `get_joint_bone_name(index: int, joint: int) -> String` *const* — Returns the bone name at `joint` in the bone chain's joint list.
- `get_joint_count(index: int) -> int` *const* — Returns the joint count of the bone chain's joint list.
- `get_joint_twist_amount(index: int, joint: int) -> float` *const* — Returns the twist amount at `joint` in the bone chain's joint list when `get_disperse_mode` is `DISPERSE_MODE_CUSTOM`.
- `get_reference_bone(index: int) -> int` *const* — Returns the reference bone to extract twist of the setting at `index`.
- `get_reference_bone_name(index: int) -> String` *const* — Returns the reference bone name to extract twist of the setting at `index`.
- `get_root_bone(index: int) -> int` *const* — Returns the root bone index of the bone chain.
- `get_root_bone_name(index: int) -> String` *const* — Returns the root bone name of the bone chain.
- `get_twist_from(index: int) -> Quaternion` *const* — Returns the rotation to an arbitrary state before twisting for the current bone pose to extract the twist when `is_twist_from_rest` is `false`.
- `get_weight_position(index: int) -> float` *const* — Returns the position at which to divide the segment between joints for weight assignment when `get_disperse_mode` is `DISPERSE_MODE_WEIGHTED`.
- `is_end_bone_extended(index: int) -> bool` *const* — Returns `true` if the end bone is extended to have a tail.
- `is_twist_from_rest(index: int) -> bool` *const* — Returns `true` if extracting the twist amount from the difference between the bone rest and the current bone pose.
- `set_damping_curve(index: int, curve: Curve) -> void` — Sets the damping curve when `get_disperse_mode` is `DISPERSE_MODE_CUSTOM`.
- `set_disperse_mode(index: int, disperse_mode: BoneTwistDisperser3D.DisperseMode) -> void` — Sets whether to use automatic amount assignment or to allow manual assignment.
- `set_end_bone(index: int, bone: int) -> void` — Sets the end bone index of the bone chain.
- `set_end_bone_direction(index: int, bone_direction: SkeletonModifier3D.BoneDirection) -> void` — Sets the end bone tail direction of the bone chain when `is_end_bone_extended` is `true`.
- `set_end_bone_name(index: int, bone_name: String) -> void` — Sets the end bone name of the bone chain.
- `set_extend_end_bone(index: int, enabled: bool) -> void` — If `enabled` is `true`, the end bone is extended to have a tail.
- `set_joint_twist_amount(index: int, joint: int, twist_amount: float) -> void` — Sets the twist amount at `joint` in the bone chain's joint list when `get_disperse_mode` is `DISPERSE_MODE_CUSTOM`.
- `set_root_bone(index: int, bone: int) -> void` — Sets the root bone index of the bone chain.
- `set_root_bone_name(index: int, bone_name: String) -> void` — Sets the root bone name of the bone chain.
- `set_twist_from(index: int, from: Quaternion) -> void` — Sets the rotation to an arbitrary state before twisting for the current bone pose to extract the twist when `is_twist_from_rest` is `false`.
- `set_twist_from_rest(index: int, enabled: bool) -> void` — If `enabled` is `true`, it extracts the twist amount from the difference between the bone rest and the current bone pose.
- `set_weight_position(index: int, weight_position: float) -> void` — Sets the position at which to divide the segment between joints for weight assignment when `get_disperse_mode` is `DISPERSE_MODE_WEIGHTED`.

## Enum DisperseMode

- `DISPERSE_MODE_EVEN = 0` — Assign amounts so that they monotonically increase from `0.0` to `1.0`, ensuring all weights are equal.
- `DISPERSE_MODE_WEIGHTED = 1` — Assign amounts so that they monotonically increase from `0.0` to `1.0`, based on the length of the bones between joint segments.
- `DISPERSE_MODE_CUSTOM = 2` — You can assign arbitrary amounts to the joint list.
