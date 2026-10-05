# BoneMap

**Inherits:** Resource

Describes a mapping of bone names for retargeting Skeleton3D into common names defined by a SkeletonProfile.

This class contains a dictionary that uses a list of bone names in SkeletonProfile as key names. By assigning the actual Skeleton3D bone name as the key value, it maps the Skeleton3D to the SkeletonProfile.

## Properties

- `profile: SkeletonProfile` — A SkeletonProfile of the mapping target.

## Methods

- `find_profile_bone_name(skeleton_bone_name: StringName) -> StringName` *const* — Returns a profile bone name having `skeleton_bone_name`.
- `get_skeleton_bone_name(profile_bone_name: StringName) -> StringName` *const* — Returns a skeleton bone name is mapped to `profile_bone_name`.
- `set_skeleton_bone_name(profile_bone_name: StringName, skeleton_bone_name: StringName) -> void` — Maps a skeleton bone name to `profile_bone_name`.

## Signals

- `bone_map_updated()` — This signal is emitted when change the key value in the BoneMap.
- `profile_updated()` — This signal is emitted when change the value in profile or change the reference of profile.
