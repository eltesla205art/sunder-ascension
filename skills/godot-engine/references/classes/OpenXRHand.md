# OpenXRHand

**Inherits:** Node3D
**Deprecated:** Use XRHandModifier3D instead.

Node supporting hand and finger tracking in OpenXR.

This node enables OpenXR's hand tracking functionality. The node should be a child node of an XROrigin3D node, tracking will update its position to the player's tracked hand Palm joint location (the center of the middle finger's metacarpal bone). This node also updates the skeleton of a properly skinned hand or avatar model. If the skeleton is a hand (one of the hand bones is the root node of the skeleton), then the skeleton will be placed relative to the hand palm location and the hand mesh and skeleton should be children of the OpenXRHand node.

## Properties

- `bone_update: OpenXRHand.BoneUpdate` = `0` — Specify the type of updates to perform on the bone.
- `hand: OpenXRHand.Hands` = `0` — Specifies whether this node tracks the left or right hand of the player.
- `hand_skeleton: NodePath` = `NodePath("")` — Set a Skeleton3D node for which the pose positions will be updated.
- `motion_range: OpenXRHand.MotionRange` = `0` — Set the motion range (if supported) limiting the hand motion.
- `skeleton_rig: OpenXRHand.SkeletonRig` = `0` — Set the type of skeleton rig the `hand_skeleton` is compliant with.

## Enum Hands

- `HAND_LEFT = 0` — Tracking the player's left hand.
- `HAND_RIGHT = 1` — Tracking the player's right hand.
- `HAND_MAX = 2` — Maximum supported hands.

## Enum MotionRange

- `MOTION_RANGE_UNOBSTRUCTED = 0` — When player grips, hand skeleton will form a full fist.
- `MOTION_RANGE_CONFORM_TO_CONTROLLER = 1` — When player grips, hand skeleton conforms to the controller the player is holding.
- `MOTION_RANGE_MAX = 2` — Maximum supported motion ranges.

## Enum SkeletonRig

- `SKELETON_RIG_OPENXR = 0` — An OpenXR compliant skeleton.
- `SKELETON_RIG_HUMANOID = 1` — A SkeletonProfileHumanoid compliant skeleton.
- `SKELETON_RIG_MAX = 2` — Maximum supported hands.

## Enum BoneUpdate

- `BONE_UPDATE_FULL = 0` — The skeletons bones are fully updated (both position and rotation) to match the tracked bones.
- `BONE_UPDATE_ROTATION_ONLY = 1` — The skeletons bones are only rotated to align with the tracked bones, preserving bone length.
- `BONE_UPDATE_MAX = 2` — Maximum supported bone update mode.
