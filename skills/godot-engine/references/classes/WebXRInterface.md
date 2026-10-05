# WebXRInterface

**Inherits:** XRInterface

XR interface using WebXR.

WebXR is an open standard that allows creating VR and AR applications that run in the web browser. As such, this interface is only available when running in Web exports. WebXR supports a wide range of devices, from the very capable (like Valve Index, HTC Vive, Oculus Rift and Quest) down to the much less capable (like Google Cardboard, Oculus Go, GearVR, or plain smartphones). Since WebXR is based on JavaScript, it makes extensive use of callbacks, which means that WebXRInterface is forced to use signals, where other XR interfaces would instead use functions that return a result immediately.

## Properties

- `disable_webxr_layers: bool` — If `true`, the WebXR Layers API won't be used even when the browser supports it.
- `enabled_features: String` — A comma-separated list of features that were successfully enabled by `XRInterface.initialize` when setting up the WebXR session.
- `optional_features: String` — A comma-seperated list of optional features used by `XRInterface.initialize` when setting up the WebXR session.
- `reference_space_type: String` — The reference space type (from the list of requested types set in the `requested_reference_space_types` property), that was ultimately used by `XRInterface.initialize` when setting up the WebXR session.
- `requested_reference_space_types: String` — A comma-seperated list of reference space types used by `XRInterface.initialize` when setting up the WebXR session.
- `required_features: String` — A comma-seperated list of required features used by `XRInterface.initialize` when setting up the WebXR session.
- `session_mode: String` — The session mode used by `XRInterface.initialize` when setting up the WebXR session.
- `visibility_state: String` — Indicates if the WebXR session's imagery is visible to the user.

## Methods

- `get_available_display_refresh_rates() -> Array` *const* — Returns display refresh rates supported by the current HMD.
- `get_display_refresh_rate() -> float` *const* — Returns the display refresh rate for the current HMD.
- `get_input_source_target_ray_mode(input_source_id: int) -> int[WebXRInterface.TargetRayMode]` *const* — Returns the target ray mode for the given `input_source_id`.
- `get_input_source_tracker(input_source_id: int) -> XRControllerTracker` *const* — Gets an XRControllerTracker for the given `input_source_id`.
- `is_input_source_active(input_source_id: int) -> bool` *const* — Returns `true` if there is an active input source with the given `input_source_id`.
- `is_session_supported(session_mode: String) -> void` — Checks if the given `session_mode` is supported by the user's browser.
- `set_display_refresh_rate(refresh_rate: float) -> void` — Sets the display refresh rate for the current HMD.

## Signals

- `display_refresh_rate_changed()` — Emitted after the display's refresh rate has changed.
- `reference_space_reset()` — Emitted to indicate that the reference space has been reset or reconfigured.
- `select(input_source_id: int)` — Emitted after one of the input sources has finished its "primary action".
- `selectend(input_source_id: int)` — Emitted when one of the input sources has finished its "primary action".
- `selectstart(input_source_id: int)` — Emitted when one of the input source has started its "primary action".
- `session_ended()` — Emitted when the user ends the WebXR session (which can be done using UI from the browser or device).
- `session_failed(message: String)` — Emitted by `XRInterface.initialize` if the session fails to start.
- `session_started()` — Emitted by `XRInterface.initialize` if the session is successfully started.
- `session_supported(session_mode: String, supported: bool)` — Emitted by `is_session_supported` to indicate if the given `session_mode` is supported or not.
- `squeeze(input_source_id: int)` — Emitted after one of the input sources has finished its "primary squeeze action".
- `squeezeend(input_source_id: int)` — Emitted when one of the input sources has finished its "primary squeeze action".
- `squeezestart(input_source_id: int)` — Emitted when one of the input sources has started its "primary squeeze action".
- `visibility_state_changed()` — Emitted when `visibility_state` has changed.

## Enum TargetRayMode

- `TARGET_RAY_MODE_UNKNOWN = 0` — We don't know the target ray mode.
- `TARGET_RAY_MODE_GAZE = 1` — Target ray originates at the viewer's eyes and points in the direction they are looking.
- `TARGET_RAY_MODE_TRACKED_POINTER = 2` — Target ray from a handheld pointer, most likely a VR touch controller.
- `TARGET_RAY_MODE_SCREEN = 3` — Target ray from touch screen, mouse or other tactile input device.
