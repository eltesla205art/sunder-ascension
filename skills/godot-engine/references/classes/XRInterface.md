# XRInterface

**Inherits:** RefCounted

Base class for an XR interface implementation.

This class needs to be implemented to make an AR or VR platform available to Godot and these should be implemented as C++ modules or GDExtension modules. Part of the interface is exposed to GDScript so you can detect, enable and configure an AR or VR platform. Interfaces should be written in such a way that simply enabling them will give us a working setup. You can query the available interfaces through XRServer.

## Properties

- `ar_is_anchor_detection_enabled: bool` = `false` — On an AR interface, `true` if anchor detection is enabled.
- `environment_blend_mode: XRInterface.EnvironmentBlendMode` = `0` — Specify how XR should blend in the environment.
- `interface_is_primary: bool` = `false` — `true` if this is the primary interface.
- `xr_play_area_mode: XRInterface.PlayAreaMode` = `0` — The play area mode for this interface.

## Methods

- `get_camera_feed_id() -> int` — If this is an AR interface that requires displaying a camera feed as the background, this method returns the feed ID in the CameraServer for this interface.
- `get_camera_offsets(tracker_name: StringName) -> Transform3D[]` — Gets an array of offset transforms for each view for tracker `tracker_name`.
- `get_camera_projections(tracker_name: StringName, aspect: float, near: float, far: float) -> Projection[]` — Gets an array of projection matrices for each view for tracker `tracker_name`.
- `get_capabilities() -> int` *const* — Returns a combination of `Capabilities` flags providing information about the capabilities of this interface.
- `get_name() -> StringName` *const* — Returns the name of this interface (`"OpenXR"`, `"OpenVR"`, `"OpenHMD"`, `"ARKit"`, etc.).
- `get_play_area() -> PackedVector3Array` *const* — Returns an array of vectors that represent the physical play area mapped to the virtual space around the XROrigin3D point.
- `get_projection_for_view(view: int, aspect: float, near: float, far: float) -> Projection` *(deprecated)* — Returns the projection matrix for a view/eye.
- `get_render_target_size() -> Vector2` — Returns the resolution at which we should render our intermediate results before things like lens distortion are applied by the VR platform.
- `get_supported_environment_blend_modes() -> Array` — Returns the an array of supported environment blend modes, see `XRInterface.EnvironmentBlendMode`.
- `get_system_info() -> Dictionary` — Returns a Dictionary with extra system info.
- `get_tracking_status() -> int[XRInterface.TrackingStatus]` *const* — If supported, returns the status of our tracking.
- `get_transform_for_view(view: int, cam_transform: Transform3D) -> Transform3D` *(deprecated)* — Returns the transform for a view/eye.
- `get_view_count() -> int` — Returns the number of views that need to be rendered for this device. 1 for Monoscopic, 2 for Stereoscopic.
- `initialize() -> bool` — Call this to initialize this interface.
- `is_initialized() -> bool` *const* — Returns `true` if this interface has been initialized.
- `is_passthrough_enabled() -> bool` *(deprecated)* — Returns `true` if passthrough is enabled.
- `is_passthrough_supported() -> bool` *(deprecated)* — Returns `true` if this interface supports passthrough.
- `set_environment_blend_mode(mode: XRInterface.EnvironmentBlendMode) -> bool` — Sets the active environment blend mode.
- `set_play_area_mode(mode: XRInterface.PlayAreaMode) -> bool` — Sets the active play area mode, will return `false` if the mode can't be used with this interface.
- `start_passthrough() -> bool` *(deprecated)* — Starts passthrough, will return `false` if passthrough couldn't be started.
- `stop_passthrough() -> void` *(deprecated)* — Stops passthrough.
- `supports_play_area_mode(mode: XRInterface.PlayAreaMode) -> bool` — Call this to find out if a given play area mode is supported by this interface.
- `trigger_haptic_pulse(action_name: String, tracker_name: StringName, frequency: float, amplitude: float, duration_sec: float, delay_sec: float) -> void` — Triggers a haptic pulse on a device associated with this interface.
- `uninitialize() -> void` — Turns the interface off.

## Signals

- `play_area_changed(mode: int)` — Emitted when the play area is changed.

## Enum Capabilities

- `XR_NONE = 0` — No XR capabilities.
- `XR_MONO = 1` — This interface can work with normal rendering output (non-HMD based AR).
- `XR_STEREO = 2` — This interface supports stereoscopic rendering.
- `XR_QUAD = 4` — This interface supports quad rendering (not yet supported by Godot).
- `XR_VR = 8` — This interface supports VR.
- `XR_AR = 16` — This interface supports AR (video background and real world tracking).
- `XR_EXTERNAL = 32` — This interface outputs to an external device.

## Enum TrackingStatus

- `XR_NORMAL_TRACKING = 0` — Tracking is behaving as expected.
- `XR_EXCESSIVE_MOTION = 1` — Tracking is hindered by excessive motion (the player is moving faster than tracking can keep up).
- `XR_INSUFFICIENT_FEATURES = 2` — Tracking is hindered by insufficient features, it's too dark (for camera-based tracking), player is blocked, etc.
- `XR_UNKNOWN_TRACKING = 3` — We don't know the status of the tracking or this interface does not provide feedback.
- `XR_NOT_TRACKING = 4` — Tracking is not functional (camera not plugged in or obscured, lighthouses turned off, etc.).

## Enum PlayAreaMode

- `XR_PLAY_AREA_UNKNOWN = 0` — Play area mode not set or not available.
- `XR_PLAY_AREA_3DOF = 1` — Play area only supports orientation tracking, no positional tracking, area will center around player.
- `XR_PLAY_AREA_SITTING = 2` — Player is in seated position, limited positional tracking, fixed guardian around player.
- `XR_PLAY_AREA_ROOMSCALE = 3` — Player is free to move around, full positional tracking.
- `XR_PLAY_AREA_STAGE = 4` — Same as `XR_PLAY_AREA_ROOMSCALE` but origin point is fixed to the center of the physical space.
- `XR_PLAY_AREA_CUSTOM = 2147483647` — Custom play area set by a GDExtension.

## Enum EnvironmentBlendMode

- `XR_ENV_BLEND_MODE_OPAQUE = 0` — Opaque blend mode.
- `XR_ENV_BLEND_MODE_ADDITIVE = 1` — Additive blend mode.
- `XR_ENV_BLEND_MODE_ALPHA_BLEND = 2` — Alpha blend mode.

## Enum VRSTextureFormat

- `XR_VRS_TEXTURE_FORMAT_UNIFIED = 0` — The texture format is the same as returned by `XRVRS.make_vrs_texture`.
- `XR_VRS_TEXTURE_FORMAT_FRAGMENT_SHADING_RATE = 1` — The texture format is the same as expected by the Vulkan `VK_KHR_fragment_shading_rate` extension.
- `XR_VRS_TEXTURE_FORMAT_FRAGMENT_DENSITY_MAP = 2` — The texture format is the same as expected by the Vulkan `VK_EXT_fragment_density_map` extension.
- `XR_VRS_TEXTURE_FORMAT_RASTERIZATION_RATE_MAP = 3` — The texture contains a Metal `rasterizationRateMap`, used for foveated rendering on Apple platforms.
