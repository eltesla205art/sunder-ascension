# OpenXRSpatialContainerExtension

**Inherits:** OpenXRExtensionWrapper

OpenXR extension that handles spatial containers.

OpenXR extension that handles spatial containers. Enabling this extension will automatically create a main spatial container, and update the lifecycle of the XR application.

## Methods

- `get_spatial_container_bounds() -> Vector3` — Retrieves the bounds of the main spatial container.
- `get_spatial_container_state() -> OpenXRSpatialContainerState` — Retrieves the OpenXRSpatialContainerState of the main spatial container.
- `get_supported_bounds_modes() -> Array` — Returns an array of supported spatial container bounds mode, see `OpenXRSpatialContainerState.BoundsMode`.
- `is_enabled() -> bool` *const* — Returns `true` if spatial containers are enabled in the project settings and available on the current runtime.
- `is_spatial_container_active() -> bool` *const* — Returns `true` if the main spatial container is active.
- `request_spatial_container_bounds_mode(bounds_mode: OpenXRSpatialContainerState.BoundsMode) -> bool` — Sends a request to the runtime to update the bounds mode of the main spatial container.
- `request_spatial_container_visible(visible: bool) -> bool` — Sends a request to the runtime to update the visibility of the spatial container.

## Signals

- `spatial_container_bounds_changed(spatial_container_rid: RID, spatial_container_infinite_bounds: bool, spatial_container_bounds_mode: int, spatial_container_bounds: Vector3)` — Emitted when the bounds of the spatial container specified by `spatial_container_rid` are updated.
- `spatial_container_bounds_mode_request_denied(spatial_container_rid: RID)` — Emitted when a request to update the bounds mode of the spatial container specified by `spatial_container_rid` is denied by the runtime.
- `spatial_container_closed(spatial_container_rid: RID)` — Emitted when the spatial container specified by `spatial_container_rid` is closed.
- `spatial_container_interactable_changed(spatial_container_rid: RID, spatial_container_interactable: bool)` — Emitted when the interactability of the spatial container specified by `spatial_container_rid` is updated.
- `spatial_container_visible_changed(spatial_container_rid: RID, spatial_container_visible: bool)` — Emitted when the visibility of the spatial container specified by `spatial_container_rid` is updated.
- `spatial_container_visible_request_denied(spatial_container_rid: RID)` — Emitted when the runtime denies the visibility request of the spatial container specified by `spatial_container_rid`.
