# SkeletonModifier3D

**Inherits:** Node3D

A node that may modify a Skeleton3D's bones.

SkeletonModifier3D retrieves a target Skeleton3D by having a Skeleton3D parent. If there is an AnimationMixer, a modification always performs after playback process of the AnimationMixer. This node should be used to implement custom IK solvers, constraints, or skeleton physics.

## Properties

- `active: bool` = `true` — If `true`, the SkeletonModifier3D will be processing.
- `influence: float` = `1.0` — Sets the influence of the modification.

## Methods

- `_process_modification() -> void` *virtual* *(deprecated)* — Override this virtual method to implement a custom skeleton modifier.
- `_process_modification_with_delta(delta: float) -> void` *virtual* — Override this virtual method to implement a custom skeleton modifier.
- `_skeleton_changed(old_skeleton: Skeleton3D, new_skeleton: Skeleton3D) -> void` *virtual* — Called when the skeleton is changed.
- `_validate_bone_names() -> void` *virtual* — Called when bone names and indices need to be validated, such as when entering the scene tree or changing skeleton.
- `get_skeleton() -> Skeleton3D` *const* — Returns the parent Skeleton3D node if it exists.

## Signals

- `modification_processed()` — Notifies when the modification have been finished.

## Enum BoneAxis

- `BONE_AXIS_PLUS_X = 0` — Enumerated value for the +X axis.
- `BONE_AXIS_MINUS_X = 1` — Enumerated value for the -X axis.
- `BONE_AXIS_PLUS_Y = 2` — Enumerated value for the +Y axis.
- `BONE_AXIS_MINUS_Y = 3` — Enumerated value for the -Y axis.
- `BONE_AXIS_PLUS_Z = 4` — Enumerated value for the +Z axis.
- `BONE_AXIS_MINUS_Z = 5` — Enumerated value for the -Z axis.

## Enum BoneDirection

- `BONE_DIRECTION_PLUS_X = 0` — Enumerated value for the +X axis.
- `BONE_DIRECTION_MINUS_X = 1` — Enumerated value for the -X axis.
- `BONE_DIRECTION_PLUS_Y = 2` — Enumerated value for the +Y axis.
- `BONE_DIRECTION_MINUS_Y = 3` — Enumerated value for the -Y axis.
- `BONE_DIRECTION_PLUS_Z = 4` — Enumerated value for the +Z axis.
- `BONE_DIRECTION_MINUS_Z = 5` — Enumerated value for the -Z axis.
- `BONE_DIRECTION_FROM_PARENT = 6` — Enumerated value for the axis from a parent bone to the child bone.

## Enum SecondaryDirection

- `SECONDARY_DIRECTION_NONE = 0` — Enumerated value for the case when the axis is undefined.
- `SECONDARY_DIRECTION_PLUS_X = 1` — Enumerated value for the +X axis.
- `SECONDARY_DIRECTION_MINUS_X = 2` — Enumerated value for the -X axis.
- `SECONDARY_DIRECTION_PLUS_Y = 3` — Enumerated value for the +Y axis.
- `SECONDARY_DIRECTION_MINUS_Y = 4` — Enumerated value for the -Y axis.
- `SECONDARY_DIRECTION_PLUS_Z = 5` — Enumerated value for the +Z axis.
- `SECONDARY_DIRECTION_MINUS_Z = 6` — Enumerated value for the -Z axis.
- `SECONDARY_DIRECTION_CUSTOM = 7` — Enumerated value for an optional axis.

## Enum RotationAxis

- `ROTATION_AXIS_X = 0` — Enumerated value for the rotation of the X axis.
- `ROTATION_AXIS_Y = 1` — Enumerated value for the rotation of the Y axis.
- `ROTATION_AXIS_Z = 2` — Enumerated value for the rotation of the Z axis.
- `ROTATION_AXIS_ALL = 3` — Enumerated value for the unconstrained rotation.
- `ROTATION_AXIS_CUSTOM = 4` — Enumerated value for an optional rotation axis.
