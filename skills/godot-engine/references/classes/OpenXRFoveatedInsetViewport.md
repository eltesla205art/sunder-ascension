# OpenXRFoveatedInsetViewport

**Inherits:** SubViewport

This viewport is used for rendering our foveated inset.

This viewport is used for rendering our foveated inset. When foveated inset rendering is supported OpenXR will create and configure this viewport correctly and use its output. The viewport will be available after OpenXR reaches the "begun" state. You can access it by calling `get_tree().get_root().get_node("OpenXRFoveatedInsetViewport")` at this time.

## Properties

- `process_priority: int` = `99999` — 
- `render_target_update_mode: SubViewport.UpdateMode` = `0` — 

## Methods

- `get_xr_camera3d() -> XRCamera3D` *const* — Returns the XRCamera3D node used for rendering the foveated inset.
- `get_xr_origin3d() -> XROrigin3D` *const* — Returns the XROrigin3D node used for tracking the foveated inset.
