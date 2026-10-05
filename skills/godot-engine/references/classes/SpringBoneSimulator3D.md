# SpringBoneSimulator3D

**Inherits:** SkeletonModifier3D

A SkeletonModifier3D to apply inertial wavering to bone chains.

This SkeletonModifier3D can be used to wiggle hair, cloth, and tails. This modifier behaves differently from PhysicalBoneSimulator3D as it attempts to return the original pose after modification. If you setup `set_root_bone` and `set_end_bone`, it is treated as one bone chain. Note that it does not support a branched chain like Y-shaped chains.

## Properties

- `external_force: Vector3` = `Vector3(0, 0, 0)` — The constant force that always affected bones.
- `mutable_bone_axes: bool` = `true` — If `true`, the solver retrieves the bone axis from the bone pose every frame.
- `setting_count: int` = `0` — The number of settings.

## Methods

- `are_all_child_collisions_enabled(index: int) -> bool` *const* — Returns `true` if all child SpringBoneCollision3Ds are contained in the collision list at `index` in the settings.
- `clear_collisions(index: int) -> void` — Clears all collisions from the collision list at `index` in the settings when `are_all_child_collisions_enabled` is `false`.
- `clear_exclude_collisions(index: int) -> void` — Clears all exclude collisions from the collision list at `index` in the settings when `are_all_child_collisions_enabled` is `true`.
- `clear_settings() -> void` — Clears all settings.
- `get_center_bone(index: int) -> int` *const* — Returns the center bone index of the bone chain.
- `get_center_bone_name(index: int) -> String` *const* — Returns the center bone name of the bone chain.
- `get_center_from(index: int) -> int[SpringBoneSimulator3D.CenterFrom]` *const* — Returns what the center originates from in the bone chain.
- `get_center_node(index: int) -> NodePath` *const* — Returns the center node path of the bone chain.
- `get_collision_count(index: int) -> int` *const* — Returns the collision count of the bone chain's collision list when `are_all_child_collisions_enabled` is `false`.
- `get_collision_path(index: int, collision: int) -> NodePath` *const* — Returns the node path of the SpringBoneCollision3D at `collision` in the bone chain's collision list when `are_all_child_collisions_enabled` is `false`.
- `get_drag(index: int) -> float` *const* — Returns the drag force damping curve of the bone chain.
- `get_drag_damping_curve(index: int) -> Curve` *const* — Returns the drag force damping curve of the bone chain.
- `get_end_bone(index: int) -> int` *const* — Returns the end bone index of the bone chain.
- `get_end_bone_direction(index: int) -> int[SkeletonModifier3D.BoneDirection]` *const* — Returns the tail direction of the end bone of the bone chain when `is_end_bone_extended` is `true`.
- `get_end_bone_length(index: int) -> float` *const* — Returns the end bone tail length of the bone chain when `is_end_bone_extended` is `true`.
- `get_end_bone_name(index: int) -> String` *const* — Returns the end bone name of the bone chain.
- `get_exclude_collision_count(index: int) -> int` *const* — Returns the exclude collision count of the bone chain's exclude collision list when `are_all_child_collisions_enabled` is `true`.
- `get_exclude_collision_path(index: int, collision: int) -> NodePath` *const* — Returns the node path of the SpringBoneCollision3D at `collision` in the bone chain's exclude collision list when `are_all_child_collisions_enabled` is `true`.
- `get_gravity(index: int) -> float` *const* — Returns the gravity amount of the bone chain.
- `get_gravity_damping_curve(index: int) -> Curve` *const* — Returns the gravity amount damping curve of the bone chain.
- `get_gravity_direction(index: int) -> Vector3` *const* — Returns the gravity direction of the bone chain.
- `get_joint_bone(index: int, joint: int) -> int` *const* — Returns the bone index at `joint` in the bone chain's joint list.
- `get_joint_bone_name(index: int, joint: int) -> String` *const* — Returns the bone name at `joint` in the bone chain's joint list.
- `get_joint_count(index: int) -> int` *const* — Returns the joint count of the bone chain's joint list.
- `get_joint_drag(index: int, joint: int) -> float` *const* — Returns the drag force at `joint` in the bone chain's joint list.
- `get_joint_gravity(index: int, joint: int) -> float` *const* — Returns the gravity amount at `joint` in the bone chain's joint list.
- `get_joint_gravity_direction(index: int, joint: int) -> Vector3` *const* — Returns the gravity direction at `joint` in the bone chain's joint list.
- `get_joint_radius(index: int, joint: int) -> float` *const* — Returns the radius at `joint` in the bone chain's joint list.
- `get_joint_rotation_axis(index: int, joint: int) -> int[SkeletonModifier3D.RotationAxis]` *const* — Returns the rotation axis at `joint` in the bone chain's joint list.
- `get_joint_rotation_axis_vector(index: int, joint: int) -> Vector3` *const* — Returns the rotation axis vector for the specified joint in the bone chain.
- `get_joint_stiffness(index: int, joint: int) -> float` *const* — Returns the stiffness force at `joint` in the bone chain's joint list.
- `get_radius(index: int) -> float` *const* — Returns the joint radius of the bone chain.
- `get_radius_damping_curve(index: int) -> Curve` *const* — Returns the joint radius damping curve of the bone chain.
- `get_root_bone(index: int) -> int` *const* — Returns the root bone index of the bone chain.
- `get_root_bone_name(index: int) -> String` *const* — Returns the root bone name of the bone chain.
- `get_rotation_axis(index: int) -> int[SkeletonModifier3D.RotationAxis]` *const* — Returns the rotation axis of the bone chain.
- `get_rotation_axis_vector(index: int) -> Vector3` *const* — Returns the rotation axis vector of the bone chain.
- `get_stiffness(index: int) -> float` *const* — Returns the stiffness force of the bone chain.
- `get_stiffness_damping_curve(index: int) -> Curve` *const* — Returns the stiffness force damping curve of the bone chain.
- `is_config_individual(index: int) -> bool` *const* — Returns `true` if the config can be edited individually for each joint.
- `is_end_bone_extended(index: int) -> bool` *const* — Returns `true` if the end bone is extended to have a tail.
- `reset() -> void` — Resets a simulating state with respect to the current bone pose.
- `set_center_bone(index: int, bone: int) -> void` — Sets the center bone index of the bone chain.
- `set_center_bone_name(index: int, bone_name: String) -> void` — Sets the center bone name of the bone chain.
- `set_center_from(index: int, center_from: SpringBoneSimulator3D.CenterFrom) -> void` — Sets what the center originates from in the bone chain.
- `set_center_node(index: int, node_path: NodePath) -> void` — Sets the center node path of the bone chain.
- `set_collision_count(index: int, count: int) -> void` — Sets the number of collisions in the collision list at `index` in the settings when `are_all_child_collisions_enabled` is `false`.
- `set_collision_path(index: int, collision: int, node_path: NodePath) -> void` — Sets the node path of the SpringBoneCollision3D at `collision` in the bone chain's collision list when `are_all_child_collisions_enabled` is `false`.
- `set_drag(index: int, drag: float) -> void` — Sets the drag force of the bone chain.
- `set_drag_damping_curve(index: int, curve: Curve) -> void` — Sets the drag force damping curve of the bone chain.
- `set_enable_all_child_collisions(index: int, enabled: bool) -> void` — If `enabled` is `true`, all child SpringBoneCollision3Ds are colliding and `set_exclude_collision_path` is enabled as an exclusion list at `index` in the settings.
- `set_end_bone(index: int, bone: int) -> void` — Sets the end bone index of the bone chain.
- `set_end_bone_direction(index: int, bone_direction: SkeletonModifier3D.BoneDirection) -> void` — Sets the end bone tail direction of the bone chain when `is_end_bone_extended` is `true`.
- `set_end_bone_length(index: int, length: float) -> void` — Sets the end bone tail length of the bone chain when `is_end_bone_extended` is `true`.
- `set_end_bone_name(index: int, bone_name: String) -> void` — Sets the end bone name of the bone chain.
- `set_exclude_collision_count(index: int, count: int) -> void` — Sets the number of exclude collisions in the exclude collision list at `index` in the settings when `are_all_child_collisions_enabled` is `true`.
- `set_exclude_collision_path(index: int, collision: int, node_path: NodePath) -> void` — Sets the node path of the SpringBoneCollision3D at `collision` in the bone chain's exclude collision list when `are_all_child_collisions_enabled` is `true`.
- `set_extend_end_bone(index: int, enabled: bool) -> void` — If `enabled` is `true`, the end bone is extended to have a tail.
- `set_gravity(index: int, gravity: float) -> void` — Sets the gravity amount of the bone chain.
- `set_gravity_damping_curve(index: int, curve: Curve) -> void` — Sets the gravity amount damping curve of the bone chain.
- `set_gravity_direction(index: int, gravity_direction: Vector3) -> void` — Sets the gravity direction of the bone chain.
- `set_individual_config(index: int, enabled: bool) -> void` — If `enabled` is `true`, the config can be edited individually for each joint.
- `set_joint_drag(index: int, joint: int, drag: float) -> void` — Sets the drag force at `joint` in the bone chain's joint list when `is_config_individual` is `true`.
- `set_joint_gravity(index: int, joint: int, gravity: float) -> void` — Sets the gravity amount at `joint` in the bone chain's joint list when `is_config_individual` is `true`.
- `set_joint_gravity_direction(index: int, joint: int, gravity_direction: Vector3) -> void` — Sets the gravity direction at `joint` in the bone chain's joint list when `is_config_individual` is `true`.
- `set_joint_radius(index: int, joint: int, radius: float) -> void` — Sets the joint radius at `joint` in the bone chain's joint list when `is_config_individual` is `true`.
- `set_joint_rotation_axis(index: int, joint: int, axis: SkeletonModifier3D.RotationAxis) -> void` — Sets the rotation axis at `joint` in the bone chain's joint list when `is_config_individual` is `true`.
- `set_joint_rotation_axis_vector(index: int, joint: int, vector: Vector3) -> void` — Sets the rotation axis vector for the specified joint in the bone chain.
- `set_joint_stiffness(index: int, joint: int, stiffness: float) -> void` — Sets the stiffness force at `joint` in the bone chain's joint list when `is_config_individual` is `true`.
- `set_radius(index: int, radius: float) -> void` — Sets the joint radius of the bone chain.
- `set_radius_damping_curve(index: int, curve: Curve) -> void` — Sets the joint radius damping curve of the bone chain.
- `set_root_bone(index: int, bone: int) -> void` — Sets the root bone index of the bone chain.
- `set_root_bone_name(index: int, bone_name: String) -> void` — Sets the root bone name of the bone chain.
- `set_rotation_axis(index: int, axis: SkeletonModifier3D.RotationAxis) -> void` — Sets the rotation axis of the bone chain.
- `set_rotation_axis_vector(index: int, vector: Vector3) -> void` — Sets the rotation axis vector of the bone chain.
- `set_stiffness(index: int, stiffness: float) -> void` — Sets the stiffness force of the bone chain.
- `set_stiffness_damping_curve(index: int, curve: Curve) -> void` — Sets the stiffness force damping curve of the bone chain.

## Enum CenterFrom

- `CENTER_FROM_WORLD_ORIGIN = 0` — The world origin is defined as center.
- `CENTER_FROM_NODE = 1` — The Node3D specified by `set_center_node` is defined as center.
- `CENTER_FROM_BONE = 2` — The bone pose origin of the parent Skeleton3D specified by `set_center_bone` is defined as center.
