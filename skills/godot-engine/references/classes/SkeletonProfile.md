# SkeletonProfile

**Inherits:** Resource

Base class for a profile of a virtual skeleton used as a target for retargeting.

This resource is used in EditorScenePostImport. Some parameters are referring to bones in Skeleton3D, Skin, Animation, and some other nodes are rewritten based on the parameters of SkeletonProfile. Note: These parameters need to be set only when creating a custom profile. In SkeletonProfileHumanoid, they are defined internally as read-only values.

## Properties

- `bone_size: int` = `0` — The amount of bones in retargeting section's BoneMap editor.
- `group_size: int` = `0` — The amount of groups of bones in retargeting section's BoneMap editor.
- `root_bone: StringName` = `&""` — A bone name that will be used as the root bone in AnimationTree.
- `scale_base_bone: StringName` = `&""` — A bone name which will use model's height as the coefficient for normalization.

## Methods

- `find_bone(bone_name: StringName) -> int` *const* — Returns the bone index that matches `bone_name` as its name.
- `get_bone_name(bone_idx: int) -> StringName` *const* — Returns the name of the bone at `bone_idx` that will be the key name in the BoneMap.
- `get_bone_parent(bone_idx: int) -> StringName` *const* — Returns the name of the bone which is the parent to the bone at `bone_idx`.
- `get_bone_tail(bone_idx: int) -> StringName` *const* — Returns the name of the bone which is the tail of the bone at `bone_idx`.
- `get_group(bone_idx: int) -> StringName` *const* — Returns the group of the bone at `bone_idx`.
- `get_group_name(group_idx: int) -> StringName` *const* — Returns the name of the group at `group_idx` that will be the drawing group in the BoneMap editor.
- `get_handle_offset(bone_idx: int) -> Vector2` *const* — Returns the offset of the bone at `bone_idx` that will be the button position in the BoneMap editor.
- `get_reference_pose(bone_idx: int) -> Transform3D` *const* — Returns the reference pose transform for bone `bone_idx`.
- `get_tail_direction(bone_idx: int) -> int[SkeletonProfile.TailDirection]` *const* — Returns the tail direction of the bone at `bone_idx`.
- `get_texture(group_idx: int) -> Texture2D` *const* — Returns the texture of the group at `group_idx` that will be the drawing group background image in the BoneMap editor.
- `is_required(bone_idx: int) -> bool` *const* — Returns whether the bone at `bone_idx` is required for retargeting.
- `set_bone_name(bone_idx: int, bone_name: StringName) -> void` — Sets the name of the bone at `bone_idx` that will be the key name in the BoneMap.
- `set_bone_parent(bone_idx: int, bone_parent: StringName) -> void` — Sets the bone with name `bone_parent` as the parent of the bone at `bone_idx`.
- `set_bone_tail(bone_idx: int, bone_tail: StringName) -> void` — Sets the bone with name `bone_tail` as the tail of the bone at `bone_idx`.
- `set_group(bone_idx: int, group: StringName) -> void` — Sets the group of the bone at `bone_idx`.
- `set_group_name(group_idx: int, group_name: StringName) -> void` — Sets the name of the group at `group_idx` that will be the drawing group in the BoneMap editor.
- `set_handle_offset(bone_idx: int, handle_offset: Vector2) -> void` — Sets the offset of the bone at `bone_idx` that will be the button position in the BoneMap editor.
- `set_reference_pose(bone_idx: int, bone_name: Transform3D) -> void` — Sets the reference pose transform for bone `bone_idx`.
- `set_required(bone_idx: int, required: bool) -> void` — Sets the required status for bone `bone_idx` to `required`.
- `set_tail_direction(bone_idx: int, tail_direction: SkeletonProfile.TailDirection) -> void` — Sets the tail direction of the bone at `bone_idx`.
- `set_texture(group_idx: int, texture: Texture2D) -> void` — Sets the texture of the group at `group_idx` that will be the drawing group background image in the BoneMap editor.

## Signals

- `profile_updated()` — This signal is emitted when change the value in profile.

## Enum TailDirection

- `TAIL_DIRECTION_AVERAGE_CHILDREN = 0` — Direction to the average coordinates of bone children.
- `TAIL_DIRECTION_SPECIFIC_CHILD = 1` — Direction to the coordinates of specified bone child.
- `TAIL_DIRECTION_END = 2` — Direction is not calculated.
