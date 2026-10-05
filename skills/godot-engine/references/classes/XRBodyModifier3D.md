# XRBodyModifier3D

**Inherits:** SkeletonModifier3D

A node for driving body meshes from XRBodyTracker data.

This node uses body tracking data from an XRBodyTracker to pose the skeleton of a body mesh. Positioning of the body is performed by creating an XRNode3D ancestor of the body mesh driven by the same XRBodyTracker. The body tracking position-data is scaled by `Skeleton3D.motion_scale` when applied to the skeleton, which can be used to adjust the tracked body to match the scale of the body model.

## Properties

- `body_tracker: StringName` = `&"/user/body_tracker"` — The name of the XRBodyTracker registered with XRServer to obtain the body tracking data from.
- `body_update: XRBodyModifier3D.BodyUpdate` = `7` — Specifies the body parts to update.
- `bone_update: XRBodyModifier3D.BoneUpdate` = `0` — Specifies the type of updates to perform on the bones.

## Enum BodyUpdate

- `BODY_UPDATE_UPPER_BODY = 1` — The skeleton's upper body joints are updated.
- `BODY_UPDATE_LOWER_BODY = 2` — The skeleton's lower body joints are updated.
- `BODY_UPDATE_HANDS = 4` — The skeleton's hand joints are updated.

## Enum BoneUpdate

- `BONE_UPDATE_FULL = 0` — The skeleton's bones are fully updated (both position and rotation) to match the tracked bones.
- `BONE_UPDATE_ROTATION_ONLY = 1` — The skeleton's bones are only rotated to align with the tracked bones, preserving bone length.
- `BONE_UPDATE_MAX = 2` — Represents the size of the `BoneUpdate` enum.
