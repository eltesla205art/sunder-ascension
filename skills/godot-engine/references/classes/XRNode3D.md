# XRNode3D

**Inherits:** Node3D

A 3D node that has its position automatically updated by the XRServer.

This node can be bound to a specific pose of an XRPositionalTracker and will automatically have its `Node3D.transform` updated by the XRServer. Nodes of this type must be added as children of the XROrigin3D node.

## Properties

- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` — 
- `pose: StringName` = `&"default"` — The name of the pose we're bound to.
- `show_when_tracked: bool` = `false` — Enables showing the node when tracking starts, and hiding the node when tracking is lost.
- `tracker: StringName` = `&""` — The name of the tracker we're bound to.

## Methods

- `get_has_tracking_data() -> bool` *const* — Returns `true` if the `tracker` has current tracking data for the `pose` being tracked.
- `get_is_active() -> bool` *const* — Returns `true` if the `tracker` has been registered and the `pose` is being tracked.
- `get_pose() -> XRPose` — Returns the XRPose containing the current state of the pose being tracked.
- `trigger_haptic_pulse(action_name: String, frequency: float, amplitude: float, duration_sec: float, delay_sec: float) -> void` — Triggers a haptic pulse on a device associated with this interface.

## Signals

- `tracking_changed(tracking: bool)` — Emitted when the `tracker` starts or stops receiving updated tracking data for the `pose` being tracked.
