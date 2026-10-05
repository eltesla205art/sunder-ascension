# XRPositionalTracker

**Inherits:** XRTracker

A tracked object.

An instance of this object represents a device that is tracked, such as a controller or anchor point. HMDs aren't represented here as they are handled internally. As controllers are turned on and the XRInterface detects them, instances of this object are automatically added to this list of active tracking objects accessible through the XRServer. The XRNode3D and XRAnchor3D both consume objects of this type and should be used in your project.

## Properties

- `hand: XRPositionalTracker.TrackerHand` = `0` — Defines which hand this tracker relates to.
- `profile: String` = `""` — The profile associated with this tracker, interface dependent but will indicate the type of controller being tracked.

## Methods

- `get_input(name: StringName) -> Variant` *const* *(deprecated)* — Returns an input for this tracker.
- `get_pose(name: StringName) -> XRPose` *const* — Returns the current XRPose state object for the bound `name` pose.
- `has_pose(name: StringName) -> bool` *const* — Returns `true` if the tracker is available and is currently tracking the bound `name` pose.
- `invalidate_pose(name: StringName) -> void` — Marks this pose as invalid, we don't clear the last reported state but it allows users to decide if trackers need to be hidden if we lose tracking or just remain at their last known position.
- `set_input(name: StringName, value: Variant) -> void` *(deprecated)* — Changes the value for the given input.
- `set_pose(name: StringName, transform: Transform3D, linear_velocity: Vector3, angular_velocity: Vector3, tracking_confidence: XRPose.TrackingConfidence) -> void` — Sets the transform, linear velocity, angular velocity and tracking confidence for the given pose.

## Signals

- `button_pressed(action_name: String)` — Emitted when a button on this tracker is pressed.
- `button_released(action_name: String)` — Emitted when a button on this tracker is released.
- `input_float_changed(action_name: String, value: float)` — Emitted when a trigger or similar input on this tracker changes value.
- `input_vector2_changed(action_name: String, vector: Vector2)` — Emitted when a thumbstick or thumbpad on this tracker moves.
- `pose_changed(pose: XRPose)` — Emitted when the state of a pose tracked by this tracker changes.
- `pose_lost_tracking(pose: XRPose)` — Emitted when a pose tracked by this tracker stops getting updated tracking data.
- `profile_changed(role: String)` — Emitted when the profile of our tracker changes.

## Enum TrackerHand

- `TRACKER_HAND_UNKNOWN = 0` — The hand this tracker is held in is unknown or not applicable.
- `TRACKER_HAND_LEFT = 1` — This tracker is the left hand controller.
- `TRACKER_HAND_RIGHT = 2` — This tracker is the right hand controller.
- `TRACKER_HAND_MAX = 3` — Represents the size of the `TrackerHand` enum.
