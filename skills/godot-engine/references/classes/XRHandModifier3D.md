# XRHandModifier3D

**Inherits:** SkeletonModifier3D

A node for driving hand meshes from XRHandTracker data.

This node uses hand tracking data from an XRHandTracker to pose the skeleton of a hand mesh. Positioning of hands is performed by creating an XRNode3D ancestor of the hand mesh driven by the same XRHandTracker. The hand tracking position-data is scaled by `Skeleton3D.motion_scale` when applied to the skeleton, which can be used to adjust the tracked hand to match the scale of the hand model.

## Properties

- `bone_update: XRHandModifier3D.BoneUpdate` = `0` — Specifies the type of updates to perform on the bones.
- `hand_tracker: StringName` = `&"/user/hand_tracker/left"` — The name of the XRHandTracker registered with XRServer to obtain the hand tracking data from.

## Enum BoneUpdate

- `BONE_UPDATE_FULL = 0` — The skeleton's bones are fully updated (both position and rotation) to match the tracked bones.
- `BONE_UPDATE_ROTATION_ONLY = 1` — The skeleton's bones are only rotated to align with the tracked bones, preserving bone length.
- `BONE_UPDATE_MAX = 2` — Represents the size of the `BoneUpdate` enum.
