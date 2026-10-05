# RetargetModifier3D

**Inherits:** SkeletonModifier3D

A modifier to transfer parent skeleton poses (or global poses) to child skeletons in model space with different rests.

Retrieves the pose (or global pose) relative to the parent Skeleton's rest in model space and transfers it to the child Skeleton. This modifier rewrites the pose of the child skeleton directly in the parent skeleton's update process. This means that it overwrites the mapped bone pose set in the normal process on the target skeleton. If you want to set the target skeleton bone pose after retargeting, you will need to add a SkeletonModifier3D child to the target skeleton and thereby modify the pose.

## Properties

- `copy_bone_skin_scale: bool` = `true` — If `true`, copies `Skeleton3D.get_bone_skin_scale` of the source skeleton's bones to the child skeletons' mapped bones.
- `enable: RetargetModifier3D.TransformFlag` = `7` — Flags to control the process of the transform elements individually when `use_global_pose` is disabled.
- `profile: SkeletonProfile` — SkeletonProfile for retargeting bones with names matching the bone list.
- `use_global_pose: bool` = `false` — If `false`, in case the target skeleton has fewer bones than the source skeleton, the source bone parent's transform will be ignored.

## Methods

- `is_position_enabled() -> bool` *const* — Returns `true` if `enable` has `TRANSFORM_FLAG_POSITION`.
- `is_rotation_enabled() -> bool` *const* — Returns `true` if `enable` has `TRANSFORM_FLAG_ROTATION`.
- `is_scale_enabled() -> bool` *const* — Returns `true` if `enable` has `TRANSFORM_FLAG_SCALE`.
- `set_position_enabled(enabled: bool) -> void` — Sets `TRANSFORM_FLAG_POSITION` into `enable`.
- `set_rotation_enabled(enabled: bool) -> void` — Sets `TRANSFORM_FLAG_ROTATION` into `enable`.
- `set_scale_enabled(enabled: bool) -> void` — Sets `TRANSFORM_FLAG_SCALE` into `enable`.

## Enum TransformFlag

- `TRANSFORM_FLAG_POSITION = 1` — If set, allows to retarget the position.
- `TRANSFORM_FLAG_ROTATION = 2` — If set, allows to retarget the rotation.
- `TRANSFORM_FLAG_SCALE = 4` — If set, allows to retarget the scale.
- `TRANSFORM_FLAG_ALL = 7` — If set, allows to retarget the position/rotation/scale.
