# Skeleton3D

**Inherits:** Node3D

A node containing a bone hierarchy, used to create a 3D skeletal animation.

Skeleton3D provides an interface for managing a hierarchy of bones, including pose, rest and animation (see Animation). It can also use ragdoll physics. The overall transform of a bone with respect to the skeleton is determined by bone pose. Bone rest defines the initial transform of the bone pose.

## Properties

- `animate_physical_bones: bool` = `true` *(deprecated)* — If you follow the recommended workflow and explicitly have PhysicalBoneSimulator3D as a child of Skeleton3D, you can control whether it is affected by raycasting without running `physical_bones_start_simulation`, by its `SkeletonModifier3D.active`.
- `modifier_callback_mode_process: Skeleton3D.ModifierCallbackModeProcess` = `1` — Sets the processing timing for the Modifier.
- `motion_scale: float` = `1.0` — Multiplies the 3D position track animation.
- `show_rest_only: bool` = `false` — If `true`, forces the bones in their default rest pose, regardless of their values.

## Methods

- `add_bone(name: String) -> int` — Adds a new bone with the given name.
- `advance(delta: float) -> void` — Manually advance the child SkeletonModifier3Ds by the specified time (in seconds).
- `clear_bones() -> void` — Clear all the bones in this skeleton.
- `clear_bones_global_pose_override() -> void` *(deprecated)* — Removes the global pose override on all bones in the skeleton.
- `create_skin_from_rest_transforms() -> Skin`
- `find_bone(name: String) -> int` *const* — Returns the bone index that matches `name` as its name.
- `force_update_all_bone_transforms() -> void` *(deprecated)* — Force updates the bone transforms/poses for all bones in the skeleton.
- `force_update_bone_child_transform(bone_idx: int) -> void` — Force updates the bone transform for the bone at `bone_idx` and all of its children.
- `get_bone_children(bone_idx: int) -> PackedInt32Array` *const* — Returns an array containing the bone indexes of all the child node of the passed in bone, `bone_idx`.
- `get_bone_count() -> int` *const* — Returns the number of bones in the skeleton.
- `get_bone_global_pose(bone_idx: int) -> Transform3D` *const* — Returns the overall transform of the specified bone, with respect to the skeleton.
- `get_bone_global_pose_no_override(bone_idx: int) -> Transform3D` *const* *(deprecated)* — Returns the overall transform of the specified bone, with respect to the skeleton, but without any global pose overrides.
- `get_bone_global_pose_override(bone_idx: int) -> Transform3D` *const* *(deprecated)* — Returns the global pose override transform for `bone_idx`.
- `get_bone_global_rest(bone_idx: int) -> Transform3D` *const* — Returns the global rest transform for `bone_idx`.
- `get_bone_meta(bone_idx: int, key: StringName) -> Variant` *const* — Returns the metadata with the given `key` for the bone at index `bone_idx`.
- `get_bone_meta_list(bone_idx: int) -> StringName[]` *const* — Returns the list of all metadata keys for the bone at index `bone_idx`.
- `get_bone_name(bone_idx: int) -> String` *const* — Returns the name of the bone at index `bone_idx`.
- `get_bone_parent(bone_idx: int) -> int` *const* — Returns the bone index which is the parent of the bone at `bone_idx`.
- `get_bone_pose(bone_idx: int) -> Transform3D` *const* — Returns the pose transform of the specified bone.
- `get_bone_pose_position(bone_idx: int) -> Vector3` *const* — Returns the pose position of the bone at `bone_idx`.
- `get_bone_pose_rotation(bone_idx: int) -> Quaternion` *const* — Returns the pose rotation of the bone at `bone_idx`.
- `get_bone_pose_scale(bone_idx: int) -> Vector3` *const* — Returns the pose scale of the bone at `bone_idx`.
- `get_bone_rest(bone_idx: int) -> Transform3D` *const* — Returns the rest transform for a bone `bone_idx`.
- `get_bone_skin_scale(bone_idx: int) -> Vector3` *const* — Returns the skin scale of the bone at `bone_idx`.
- `get_concatenated_bone_names() -> StringName` *const* — Returns all bone names concatenated with commas (`,`) as a single StringName.
- `get_parentless_bones() -> PackedInt32Array` *const* — Returns an array with all of the bones that are parentless.
- `get_version() -> int` *const* — Returns the number of times the bone hierarchy has changed within this skeleton, including renames.
- `has_bone_meta(bone_idx: int, key: StringName) -> bool` *const* — Returns `true` if the bone at index `bone_idx` has metadata with the given `key`.
- `is_bone_enabled(bone_idx: int) -> bool` *const* — Returns whether the bone pose for the bone at `bone_idx` is enabled.
- `localize_rests() -> void` — Returns all bones in the skeleton to their rest poses.
- `physical_bones_add_collision_exception(exception: RID) -> void` *(deprecated)* — Adds a collision exception to the physical bone.
- `physical_bones_remove_collision_exception(exception: RID) -> void` *(deprecated)* — Removes a collision exception to the physical bone.
- `physical_bones_start_simulation(bones: StringName[] = []) -> void` *(deprecated)* — Tells the PhysicalBone3D nodes in the Skeleton to start simulating and reacting to the physics world.
- `physical_bones_stop_simulation() -> void` *(deprecated)* — Tells the PhysicalBone3D nodes in the Skeleton to stop simulating.
- `register_skin(skin: Skin) -> SkinReference` — Binds the given Skin to the Skeleton.
- `reset_bone_pose(bone_idx: int, reset_bone_skin_scale: bool = false) -> void` — Sets the bone pose to rest for `bone_idx`.
- `reset_bone_poses(reset_bone_skin_scale: bool = false) -> void` — Sets all bone poses to rests.
- `set_bone_enabled(bone_idx: int, enabled: bool = true) -> void` — Disables the pose for the bone at `bone_idx` if `false`, enables the bone pose if `true`.
- `set_bone_global_pose(bone_idx: int, pose: Transform3D) -> void` — Sets the global pose transform, `pose`, for the bone at `bone_idx`.
- `set_bone_global_pose_override(bone_idx: int, pose: Transform3D, amount: float, persistent: bool = false) -> void` *(deprecated)* — Sets the global pose transform, `pose`, for the bone at `bone_idx`.
- `set_bone_meta(bone_idx: int, key: StringName, value: Variant) -> void` — Sets the metadata with the given `key` to `value` for the bone at index `bone_idx`.
- `set_bone_name(bone_idx: int, name: String) -> void` — Sets the bone name, `name`, for the bone at `bone_idx`.
- `set_bone_parent(bone_idx: int, parent_idx: int) -> void` — Sets the bone index `parent_idx` as the parent of the bone at `bone_idx`.
- `set_bone_pose(bone_idx: int, pose: Transform3D) -> void` — Sets the pose transform, `pose`, for the bone at `bone_idx`.
- `set_bone_pose_position(bone_idx: int, position: Vector3) -> void` — Sets the pose position of the bone at `bone_idx` to `position`.
- `set_bone_pose_rotation(bone_idx: int, rotation: Quaternion) -> void` — Sets the pose rotation of the bone at `bone_idx` to `rotation`.
- `set_bone_pose_scale(bone_idx: int, scale: Vector3) -> void` — Sets the pose scale of the bone at `bone_idx` to `scale`.
- `set_bone_rest(bone_idx: int, rest: Transform3D) -> void` — Sets the rest transform for bone `bone_idx`.
- `set_bone_skin_scale(bone_idx: int, skin_scale: Vector3) -> void` — Sets the skin scale of the bone at `bone_idx` to `skin_scale`.
- `unparent_bone_and_rest(bone_idx: int) -> void` — Unparents the bone at `bone_idx` and sets its rest position to that of its parent prior to being reset.

## Signals

- `bone_enabled_changed(bone_idx: int)` — Emitted when the bone at `bone_idx` is toggled with `set_bone_enabled`.
- `bone_list_changed()` — Emitted when the list of bones changes, such as when calling `add_bone`, `set_bone_parent`, `unparent_bone_and_rest`, or `clear_bones`.
- `pose_updated()` — Emitted when the pose is updated.
- `rest_updated()` — Emitted when the rest is updated.
- `show_rest_only_changed()` — Emitted when the value of `show_rest_only` changes.
- `skeleton_updated()` — Emitted when the final pose has been calculated will be applied to the skin in the update process.

## Enum ModifierCallbackModeProcess

- `MODIFIER_CALLBACK_MODE_PROCESS_PHYSICS = 0` — Set a flag to process modification during physics frames (see `Node.NOTIFICATION_INTERNAL_PHYSICS_PROCESS`).
- `MODIFIER_CALLBACK_MODE_PROCESS_IDLE = 1` — Set a flag to process modification during process frames (see `Node.NOTIFICATION_INTERNAL_PROCESS`).
- `MODIFIER_CALLBACK_MODE_PROCESS_MANUAL = 2` — Do not process modification.

## Constants

- `NOTIFICATION_UPDATE_SKELETON = 50` — Notification received when this skeleton's pose needs to be updated.
