# ChainIK3D

**Inherits:** IKModifier3D

A SkeletonModifier3D to apply inverse kinematics to bone chains containing an arbitrary number of bones.

Base class of SkeletonModifier3D that automatically generates a joint list from the bones between the root bone and the end bone. Note: All the methods in this class take an `index` parameter. This parameter specifies which setting list entry to return if the IK has multiple entries (e.g. `settings/<index>/root_bone_name`).

## Methods

- `get_end_bone(index: int) -> int` *const* — Returns the end bone index of the bone chain.
- `get_end_bone_direction(index: int) -> int[SkeletonModifier3D.BoneDirection]` *const* — Returns the tail direction of the end bone of the bone chain when `is_end_bone_extended` is `true`.
- `get_end_bone_length(index: int) -> float` *const* — Returns the end bone tail length of the bone chain when `is_end_bone_extended` is `true`.
- `get_end_bone_name(index: int) -> String` *const* — Returns the end bone name of the bone chain.
- `get_joint_bone(index: int, joint: int) -> int` *const* — Returns the bone index at `joint` in the bone chain's joint list.
- `get_joint_bone_name(index: int, joint: int) -> String` *const* — Returns the bone name at `joint` in the bone chain's joint list.
- `get_joint_count(index: int) -> int` *const* — Returns the joint count of the bone chain's joint list.
- `get_root_bone(index: int) -> int` *const* — Returns the root bone index of the bone chain.
- `get_root_bone_name(index: int) -> String` *const* — Returns the root bone name of the bone chain.
- `is_end_bone_extended(index: int) -> bool` *const* — Returns `true` if the end bone is extended to have a tail.
- `set_end_bone(index: int, bone: int) -> void` — Sets the end bone index of the bone chain.
- `set_end_bone_direction(index: int, bone_direction: SkeletonModifier3D.BoneDirection) -> void` — Sets the end bone tail direction of the bone chain when `is_end_bone_extended` is `true`.
- `set_end_bone_length(index: int, length: float) -> void` — Sets the end bone tail length of the bone chain when `is_end_bone_extended` is `true`.
- `set_end_bone_name(index: int, bone_name: String) -> void` — Sets the end bone name of the bone chain.
- `set_extend_end_bone(index: int, enabled: bool) -> void` — If `enabled` is `true`, the end bone is extended to have a tail.
- `set_root_bone(index: int, bone: int) -> void` — Sets the root bone index of the bone chain.
- `set_root_bone_name(index: int, bone_name: String) -> void` — Sets the root bone name of the bone chain.
