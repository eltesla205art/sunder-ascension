# XRHandTracker

**Inherits:** XRPositionalTracker

A tracked hand in XR.

A hand tracking system will create an instance of this object and add it to the XRServer. This tracking system will then obtain skeleton data, convert it to the Godot Humanoid hand skeleton and store this data on the XRHandTracker object. Use XRHandModifier3D to animate a hand mesh using hand tracking data.

## Properties

- `hand: XRPositionalTracker.TrackerHand` = `1` — 
- `hand_tracking_source: XRHandTracker.HandTrackingSource` = `0` — The source of the hand tracking data.
- `has_tracking_data: bool` = `false` — If `true`, the hand tracking data is valid.
- `type: XRServer.TrackerType` = `16` — 

## Methods

- `get_hand_joint_angular_velocity(joint: XRHandTracker.HandJoint) -> Vector3` *const* — Returns the angular velocity for the given hand joint.
- `get_hand_joint_flags(joint: XRHandTracker.HandJoint) -> int[XRHandTracker.HandJointFlags]` *const* — Returns flags about the validity of the tracking data for the given hand joint.
- `get_hand_joint_linear_velocity(joint: XRHandTracker.HandJoint) -> Vector3` *const* — Returns the linear velocity for the given hand joint.
- `get_hand_joint_radius(joint: XRHandTracker.HandJoint) -> float` *const* — Returns the radius of the given hand joint.
- `get_hand_joint_transform(joint: XRHandTracker.HandJoint) -> Transform3D` *const* — Returns the transform for the given hand joint.
- `set_hand_joint_angular_velocity(joint: XRHandTracker.HandJoint, angular_velocity: Vector3) -> void` — Sets the angular velocity for the given hand joint.
- `set_hand_joint_flags(joint: XRHandTracker.HandJoint, flags: XRHandTracker.HandJointFlags) -> void` — Sets flags about the validity of the tracking data for the given hand joint.
- `set_hand_joint_linear_velocity(joint: XRHandTracker.HandJoint, linear_velocity: Vector3) -> void` — Sets the linear velocity for the given hand joint.
- `set_hand_joint_radius(joint: XRHandTracker.HandJoint, radius: float) -> void` — Sets the radius of the given hand joint.
- `set_hand_joint_transform(joint: XRHandTracker.HandJoint, transform: Transform3D) -> void` — Sets the transform for the given hand joint.

## Enum HandTrackingSource

- `HAND_TRACKING_SOURCE_UNKNOWN = 0` — The source of hand tracking data is unknown.
- `HAND_TRACKING_SOURCE_UNOBSTRUCTED = 1` — The source of hand tracking data is unobstructed, meaning that an accurate method of hand tracking is used.
- `HAND_TRACKING_SOURCE_CONTROLLER = 2` — The source of hand tracking data is a controller, meaning that joint positions are inferred from controller inputs.
- `HAND_TRACKING_SOURCE_NOT_TRACKED = 3` — No hand tracking data is tracked, this either means the hand is obscured, the controller is turned off, or tracking is not supported for the current input type.
- `HAND_TRACKING_SOURCE_MAX = 4` — Represents the size of the `HandTrackingSource` enum.

## Enum HandJoint

- `HAND_JOINT_PALM = 0` — Palm joint.
- `HAND_JOINT_WRIST = 1` — Wrist joint.
- `HAND_JOINT_THUMB_METACARPAL = 2` — Thumb metacarpal joint.
- `HAND_JOINT_THUMB_PHALANX_PROXIMAL = 3` — Thumb phalanx proximal joint.
- `HAND_JOINT_THUMB_PHALANX_DISTAL = 4` — Thumb phalanx distal joint.
- `HAND_JOINT_THUMB_TIP = 5` — Thumb tip joint.
- `HAND_JOINT_INDEX_FINGER_METACARPAL = 6` — Index finger metacarpal joint.
- `HAND_JOINT_INDEX_FINGER_PHALANX_PROXIMAL = 7` — Index finger phalanx proximal joint.
- `HAND_JOINT_INDEX_FINGER_PHALANX_INTERMEDIATE = 8` — Index finger phalanx intermediate joint.
- `HAND_JOINT_INDEX_FINGER_PHALANX_DISTAL = 9` — Index finger phalanx distal joint.
- `HAND_JOINT_INDEX_FINGER_TIP = 10` — Index finger tip joint.
- `HAND_JOINT_MIDDLE_FINGER_METACARPAL = 11` — Middle finger metacarpal joint.
- `HAND_JOINT_MIDDLE_FINGER_PHALANX_PROXIMAL = 12` — Middle finger phalanx proximal joint.
- `HAND_JOINT_MIDDLE_FINGER_PHALANX_INTERMEDIATE = 13` — Middle finger phalanx intermediate joint.
- `HAND_JOINT_MIDDLE_FINGER_PHALANX_DISTAL = 14` — Middle finger phalanx distal joint.
- `HAND_JOINT_MIDDLE_FINGER_TIP = 15` — Middle finger tip joint.
- `HAND_JOINT_RING_FINGER_METACARPAL = 16` — Ring finger metacarpal joint.
- `HAND_JOINT_RING_FINGER_PHALANX_PROXIMAL = 17` — Ring finger phalanx proximal joint.
- `HAND_JOINT_RING_FINGER_PHALANX_INTERMEDIATE = 18` — Ring finger phalanx intermediate joint.
- `HAND_JOINT_RING_FINGER_PHALANX_DISTAL = 19` — Ring finger phalanx distal joint.
- `HAND_JOINT_RING_FINGER_TIP = 20` — Ring finger tip joint.
- `HAND_JOINT_PINKY_FINGER_METACARPAL = 21` — Pinky finger metacarpal joint.
- `HAND_JOINT_PINKY_FINGER_PHALANX_PROXIMAL = 22` — Pinky finger phalanx proximal joint.
- `HAND_JOINT_PINKY_FINGER_PHALANX_INTERMEDIATE = 23` — Pinky finger phalanx intermediate joint.
- `HAND_JOINT_PINKY_FINGER_PHALANX_DISTAL = 24` — Pinky finger phalanx distal joint.
- `HAND_JOINT_PINKY_FINGER_TIP = 25` — Pinky finger tip joint.
- `HAND_JOINT_MAX = 26` — Represents the size of the `HandJoint` enum.

## Enum HandJointFlags

- `HAND_JOINT_FLAG_ORIENTATION_VALID = 1` — The hand joint's orientation data is valid.
- `HAND_JOINT_FLAG_ORIENTATION_TRACKED = 2` — The hand joint's orientation is actively tracked.
- `HAND_JOINT_FLAG_POSITION_VALID = 4` — The hand joint's position data is valid.
- `HAND_JOINT_FLAG_POSITION_TRACKED = 8` — The hand joint's position is actively tracked.
- `HAND_JOINT_FLAG_LINEAR_VELOCITY_VALID = 16` — The hand joint's linear velocity data is valid.
- `HAND_JOINT_FLAG_ANGULAR_VELOCITY_VALID = 32` — The hand joint's angular velocity data is valid.
