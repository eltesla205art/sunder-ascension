# AudioListener3D

**Inherits:** Node3D

Overrides the location sounds are heard from.

Once added to the scene tree and enabled using `make_current`, this node will override the location sounds are heard from. This can be used to listen from a location different from the Camera3D.

## Properties

- `doppler_tracking: AudioListener3D.DopplerTracking` = `0` — If not `DOPPLER_TRACKING_DISABLED`, this listener will simulate the Doppler effect for objects changed in particular `_process` methods.

## Methods

- `clear_current() -> void` — Disables the listener to use the current camera's listener instead.
- `get_listener_transform() -> Transform3D` *const* — Returns the listener's global orthonormalized Transform3D.
- `is_current() -> bool` *const* — Returns `true` if the listener was made current using `make_current`, `false` otherwise.
- `make_current() -> void` — Enables the listener.

## Enum DopplerTracking

- `DOPPLER_TRACKING_DISABLED = 0` — Disables Doppler effect simulation (default).
- `DOPPLER_TRACKING_IDLE_STEP = 1` — Simulate Doppler effect by tracking positions of objects that are changed in `_process`.
- `DOPPLER_TRACKING_PHYSICS_STEP = 2` — Simulate Doppler effect by tracking positions of objects that are changed in `_physics_process`.
