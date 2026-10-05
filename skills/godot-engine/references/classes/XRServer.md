# XRServer

**Inherits:** Object

Server for AR and VR features.

The AR/VR server is the heart of our Advanced and Virtual Reality solution and handles all the processing.

## Properties

- `camera_locked_to_origin: bool` = `false` — If set to `true`, the scene will be rendered as if the camera is locked to the XROrigin3D.
- `primary_interface: XRInterface` — The primary XRInterface currently bound to the XRServer.
- `world_origin: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The current origin of our tracking space in the virtual world.
- `world_scale: float` = `1.0` — The scale of the game world compared to the real world.

## Methods

- `add_interface(interface: XRInterface) -> void` — Registers an XRInterface object.
- `add_tracker(tracker: XRTracker) -> void` — Registers a new XRTracker that tracks a physical object.
- `center_on_hmd(rotation_mode: XRServer.RotationMode, keep_height: bool) -> void` — This is an important function to understand correctly.
- `clear_reference_frame() -> void` — Clears the reference frame that was set by previous calls to `center_on_hmd`.
- `find_interface(name: String) -> XRInterface` *const* — Finds an interface by its `name`.
- `get_camera_offsets(tracker_name: StringName) -> Transform3D[]` — Gets an array of offset transforms for each view for tracker `tracker_name`.
- `get_camera_projections(tracker_name: StringName, aspect: float, near: float, far: float) -> Projection[]` — Gets an array of projection matrices for each view for tracker `tracker_name`.
- `get_hmd_transform() -> Transform3D` — Returns the primary interface's transformation.
- `get_interface(idx: int) -> XRInterface` *const* — Returns the interface registered at the given `idx` index in the list of interfaces.
- `get_interface_count() -> int` *const* — Returns the number of interfaces currently registered with the AR/VR server.
- `get_interfaces() -> Dictionary[]` *const* — Returns a list of available interfaces the ID and name of each interface.
- `get_reference_frame() -> Transform3D` *const* — Returns the reference frame transform.
- `get_tracker(tracker_name: StringName) -> XRTracker` *const* — Returns the positional tracker with the given `tracker_name`.
- `get_trackers(tracker_types: int) -> Dictionary` — Returns a dictionary of trackers for `tracker_types`.
- `remove_interface(interface: XRInterface) -> void` — Removes this `interface`.
- `remove_tracker(tracker: XRTracker) -> void` — Removes this `tracker`.

## Signals

- `interface_added(interface_name: StringName)` — Emitted when a new interface has been added.
- `interface_removed(interface_name: StringName)` — Emitted when an interface is removed.
- `reference_frame_changed()` — Emitted when the reference frame transform changes.
- `tracker_added(tracker_name: StringName, type: int)` — Emitted when a new tracker has been added.
- `tracker_removed(tracker_name: StringName, type: int)` — Emitted when a tracker is removed.
- `tracker_updated(tracker_name: StringName, type: int)` — Emitted when an existing tracker has been updated.
- `world_origin_changed()` — Emitted when the world origin transform changes.

## Enum TrackerType

- `TRACKER_CAMERA = 1` — The tracker tracks the position of an XR camera (HMD, external camera, phone camera for phone based AR).
- `TRACKER_CONTROLLER = 2` — The tracker tracks the location of a controller.
- `TRACKER_BASESTATION = 4` — The tracker tracks the location of a base station.
- `TRACKER_ANCHOR = 8` — The tracker tracks the location and size of an AR anchor.
- `TRACKER_HAND = 16` — The tracker tracks the location and joints of a hand.
- `TRACKER_BODY = 32` — The tracker tracks the location and joints of a body.
- `TRACKER_FACE = 64` — The tracker tracks the expressions of a face.
- `TRACKER_ANY_KNOWN = 127` — Used internally to filter trackers of any known type.
- `TRACKER_UNKNOWN = 128` — Used internally if we haven't set the tracker type yet.
- `TRACKER_ANY = 255` — Used internally to select all trackers.
- `TRACKER_HEAD = 1` — The tracker tracks the location of the player's head.

## Enum RotationMode

- `RESET_FULL_ROTATION = 0` — Fully reset the orientation of the HMD.
- `RESET_BUT_KEEP_TILT = 1` — Resets the orientation but keeps the tilt of the device.
- `DONT_RESET_ROTATION = 2` — Does not reset the orientation of the HMD, only the position of the player gets centered.
