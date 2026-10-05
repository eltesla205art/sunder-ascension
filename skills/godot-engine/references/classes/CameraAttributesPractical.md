# CameraAttributesPractical

**Inherits:** CameraAttributes

Camera settings in an easy to use format.

Controls camera-specific attributes such as auto-exposure, depth of field, and exposure override. When used in a WorldEnvironment it provides default settings for exposure, auto-exposure, and depth of field that will be used by all cameras without their own CameraAttributes, including the editor camera. When used in a Camera3D it will override any CameraAttributes set in the WorldEnvironment. When used in VoxelGI or LightmapGI, only the exposure settings will be used.

## Properties

- `auto_exposure_max_sensitivity: float` = `800.0` — The maximum sensitivity (in ISO) used when calculating auto exposure.
- `auto_exposure_min_sensitivity: float` = `0.0` — The minimum sensitivity (in ISO) used when calculating auto exposure.
- `dof_blur_amount: float` = `0.1` — Sets the maximum amount of blur.
- `dof_blur_far_distance: float` = `10.0` — Objects further from the Camera3D by this amount will be blurred by the depth of field effect.
- `dof_blur_far_enabled: bool` = `false` — Enables depth of field blur for objects further than `dof_blur_far_distance`.
- `dof_blur_far_transition: float` = `5.0` — When positive, distance over which (starting from `dof_blur_far_distance`) blur effect will scale from 0 to `dof_blur_amount`.
- `dof_blur_near_distance: float` = `2.0` — Objects closer from the Camera3D by this amount will be blurred by the depth of field effect.
- `dof_blur_near_enabled: bool` = `false` — Enables depth of field blur for objects closer than `dof_blur_near_distance`.
- `dof_blur_near_transition: float` = `1.0` — When positive, distance over which blur effect will scale from 0 to `dof_blur_amount`, ending at `dof_blur_near_distance`.
