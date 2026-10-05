# IterateIK3D

**Inherits:** ChainIK3D

A SkeletonModifier3D to approach the goal by repeating small rotations.

Base class of SkeletonModifier3D to approach the goal by repeating small rotations. Each bone chain (setting) has one effector, which is processed in order of the setting list. You can set some limitations for each joint. Note: All the methods in this class take an `index` parameter.

## Properties

- `angular_delta_limit: float` = `0.034906585` — The maximum amount each bone can rotate in a single iteration.
- `deterministic: bool` = `false` — If `false`, the result is calculated from the previous frame's IterateIK3D result as the initial state.
- `max_iterations: int` = `4` — The number of iteration loops used by the IK solver to produce more accurate results.
- `min_distance: float` = `0.001` — The minimum distance between the end bone and the target.
- `setting_count: int` = `0` — The number of settings.

## Methods

- `get_joint_limitation(index: int, joint: int) -> JointLimitation3D` *const* — Returns the joint limitation at `joint` in the bone chain's joint list.
- `get_joint_limitation_right_axis(index: int, joint: int) -> int[SkeletonModifier3D.SecondaryDirection]` *const* — Returns the joint limitation right axis at `joint` in the bone chain's joint list.
- `get_joint_limitation_right_axis_vector(index: int, joint: int) -> Vector3` *const* — Returns the joint limitation right axis vector at `joint` in the bone chain's joint list.
- `get_joint_limitation_rotation_offset(index: int, joint: int) -> Quaternion` *const* — Returns the joint limitation rotation offset at `joint` in the bone chain's joint list.
- `get_joint_rotation_axis(index: int, joint: int) -> int[SkeletonModifier3D.RotationAxis]` *const* — Returns the rotation axis at `joint` in the bone chain's joint list.
- `get_joint_rotation_axis_vector(index: int, joint: int) -> Vector3` *const* — Returns the rotation axis vector for the specified joint in the bone chain.
- `get_target_node(index: int) -> NodePath` *const* — Returns the target node that the end bone is trying to reach.
- `is_joint_using_rest_for_limitation(index: int, joint: int) -> bool` *const* — Returns whether the limitation at `joint` in the bone chain's joint list is applied based on the `Skeleton3D.get_bone_rest`.
- `set_joint_limitation(index: int, joint: int, limitation: JointLimitation3D) -> void` — Sets the joint limitation at `joint` in the bone chain's joint list.
- `set_joint_limitation_right_axis(index: int, joint: int, direction: SkeletonModifier3D.SecondaryDirection) -> void` — Sets the joint limitation right axis at `joint` in the bone chain's joint list.
- `set_joint_limitation_right_axis_vector(index: int, joint: int, vector: Vector3) -> void` — Sets the optional joint limitation right axis vector at `joint` in the bone chain's joint list.
- `set_joint_limitation_rotation_offset(index: int, joint: int, offset: Quaternion) -> void` — Sets the joint limitation rotation offset at `joint` in the bone chain's joint list.
- `set_joint_rotation_axis(index: int, joint: int, axis: SkeletonModifier3D.RotationAxis) -> void` — Sets the rotation axis at `joint` in the bone chain's joint list.
- `set_joint_rotation_axis_vector(index: int, joint: int, axis_vector: Vector3) -> void` — Sets the rotation axis vector for the specified joint in the bone chain.
- `set_joint_use_rest_for_limitation(index: int, joint: int, enabled: bool) -> void` — Sets whether the limitation and the rotation axis at `joint` in the bone chain's joint list are applied based on the `Skeleton3D.get_bone_rest`.
- `set_target_node(index: int, target_node: NodePath) -> void` — Sets the target node that the end bone is trying to reach.
