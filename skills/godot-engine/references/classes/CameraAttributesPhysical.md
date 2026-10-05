# CameraAttributesPhysical

**Inherits:** CameraAttributes

Physically-based camera settings.

CameraAttributesPhysical is used to set rendering settings based on a physically-based camera's settings. It is responsible for exposure, auto-exposure, and depth of field. When used in a WorldEnvironment, it provides default settings for exposure, auto-exposure, and depth of field that will be used by all cameras without their own CameraAttributes, including the editor camera. When used in a Camera3D, it will override any CameraAttributes set in the WorldEnvironment and will override the Camera3D's `Camera3D.far`, `Camera3D.near`, `Camera3D.fov`, and `Camera3D.keep_aspect` properties.

## Properties

- `auto_exposure_max_exposure_value: float` = `10.0` — The maximum luminance (in EV100) used when calculating auto exposure.
- `auto_exposure_min_exposure_value: float` = `-8.0` — The minimum luminance (in EV100) used when calculating auto exposure.
- `exposure_aperture: float` = `16.0` — Size of the aperture of the camera, measured in f-stops.
- `exposure_shutter_speed: float` = `100.0` — Time for shutter to open and close, evaluated as `1 / shutter_speed` seconds.
- `frustum_far: float` = `4000.0` — Override value for `Camera3D.far`.
- `frustum_focal_length: float` = `35.0` — Distance between camera lens and camera aperture, measured in millimeters.
- `frustum_focus_distance: float` = `10.0` — Distance from camera of object that will be in focus, measured in meters.
- `frustum_near: float` = `0.05` — Override value for `Camera3D.near`.

## Methods

- `get_fov() -> float` *const* — Returns the vertical field of view that corresponds to the `frustum_focal_length`.
