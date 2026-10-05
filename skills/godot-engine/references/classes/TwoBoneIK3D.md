# TwoBoneIK3D

**Inherits:** IKModifier3D

Rotation based intersection of two circles inverse kinematics solver.

This IKModifier3D requires a pole target. It provides deterministic results by constructing a plane from each joint and pole target and finding the intersection of two circles (disks in 3D). This IK can handle twist by setting the pole direction. If there are more than one bone between each set bone, their rotations are ignored, and the straight line connecting the root-middle and middle-end joints are treated as virtual bones.

## Properties

- `setting_count: int` = `0` — The number of settings.

## Methods

- `get_end_bone(index: int) -> int` *const* — Returns the end bone index.
- `get_end_bone_direction(index: int) -> int[SkeletonModifier3D.BoneDirection]` *const* — Returns the end bone's tail direction when `is_end_bone_extended` is `true`.
- `get_end_bone_length(index: int) -> float` *const* — Returns the end bone tail length of the bone chain when `is_end_bone_extended` is `true`.
- `get_end_bone_name(index: int) -> String` *const* — Returns the end bone name.
- `get_middle_bone(index: int) -> int` *const* — Returns the middle bone index.
- `get_middle_bone_name(index: int) -> String` *const* — Returns the middle bone name.
- `get_pole_direction(index: int) -> int[SkeletonModifier3D.SecondaryDirection]` *const* — Returns the pole direction.
- `get_pole_direction_vector(index: int) -> Vector3` *const* — Returns the pole direction vector.
- `get_pole_node(index: int) -> NodePath` *const* — Returns the pole target node that constructs a plane which the joints are all on and the pole is trying to direct.
- `get_root_bone(index: int) -> int` *const* — Returns the root bone index.
- `get_root_bone_name(index: int) -> String` *const* — Returns the root bone name.
- `get_target_node(index: int) -> NodePath` *const* — Returns the target node that the end bone is trying to reach.
- `is_end_bone_extended(index: int) -> bool` *const* — Returns `true` if the end bone is extended to have a tail.
- `is_using_virtual_end(index: int) -> bool` *const* — Returns `true` if the end bone is extended from the middle bone as a virtual bone.
- `set_end_bone(index: int, bone: int) -> void` — Sets the end bone index.
- `set_end_bone_direction(index: int, bone_direction: SkeletonModifier3D.BoneDirection) -> void` — Sets the end bone tail direction when `is_end_bone_extended` is `true`.
- `set_end_bone_length(index: int, length: float) -> void` — Sets the end bone tail length when `is_end_bone_extended` is `true`.
- `set_end_bone_name(index: int, bone_name: String) -> void` — Sets the end bone name.
- `set_extend_end_bone(index: int, enabled: bool) -> void` — If `enabled` is `true`, the end bone is extended to have a tail.
- `set_middle_bone(index: int, bone: int) -> void` — Sets the middle bone index.
- `set_middle_bone_name(index: int, bone_name: String) -> void` — Sets the middle bone name.
- `set_pole_direction(index: int, direction: SkeletonModifier3D.SecondaryDirection) -> void` — Sets the pole direction.
- `set_pole_direction_vector(index: int, vector: Vector3) -> void` — Sets the pole direction vector.
- `set_pole_node(index: int, pole_node: NodePath) -> void` — Sets the pole target node that constructs a plane which the joints are all on and the pole is trying to direct.
- `set_root_bone(index: int, bone: int) -> void` — Sets the root bone index.
- `set_root_bone_name(index: int, bone_name: String) -> void` — Sets the root bone name.
- `set_target_node(index: int, target_node: NodePath) -> void` — Sets the target node that the end bone is trying to reach.
- `set_use_virtual_end(index: int, enabled: bool) -> void` — If `enabled` is `true`, the end bone is extended from the middle bone as a virtual bone.
