# CameraAttributes

**Inherits:** Resource

Parent class for camera settings.

Controls camera-specific attributes such as depth of field and exposure override. When used in a WorldEnvironment it provides default settings for exposure, auto-exposure, and depth of field that will be used by all cameras without their own CameraAttributes, including the editor camera. When used in a Camera3D it will override any CameraAttributes set in the WorldEnvironment. When used in VoxelGI or LightmapGI, only the exposure settings will be used.

## Properties

- `auto_exposure_enabled: bool` = `false` — If `true`, enables the tonemapping auto exposure mode of the scene renderer.
- `auto_exposure_scale: float` = `0.4` — The scale of the auto exposure effect.
- `auto_exposure_speed: float` = `0.5` — The speed of the auto exposure effect.
- `exposure_multiplier: float` = `1.0` — Multiplier for the exposure amount.
- `exposure_sensitivity: float` = `100.0` — Sensitivity of camera sensors, measured in ISO.
