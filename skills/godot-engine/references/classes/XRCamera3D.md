# XRCamera3D

**Inherits:** Camera3D

A camera node which automatically positions itself based on XR tracking data.

A camera node which automatically positions itself based on XR tracking data. Note: Due to the nature of headsets, camera positioning needs to update every frame even when your game is paused. `Node.process_mode` must be set to `Node.PROCESS_MODE_ALWAYS`.

## Properties

- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` — 
- `process_mode: Node.ProcessMode` = `3` — 
- `tracker: StringName` = `&"head"` — The name of the camera tracker we're bound to.
