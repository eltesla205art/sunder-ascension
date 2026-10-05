# OpenXRSpatialPlaneTrackingCapability

**Inherits:** OpenXRExtensionWrapper

Implementation for handling spatial entity plane tracking logic.

This class handles the OpenXR plane tracking spatial entity extension.

## Methods

- `get_built_in_tracking_state() -> int[OpenXRSpatialEntityExtension.TrackingState]` — Returns the state of the built-in tracking system.
- `is_supported() -> bool` — Returns `true` if plane tracking is supported by the current device.
- `start_built_in_tracking() -> bool` — Starts the built-in plane tracking logic.
- `start_entity_discovery(spatial_context: RID, component_data: OpenXRSpatialComponentData[], next_snapshot_create: OpenXRStructureBase = null, next_snapshot_query: OpenXRStructureBase = null, user_callback: Callable = Callable()) -> OpenXRFutureResult` — Calls `OpenXRSpatialEntityExtension.discover_spatial_entities` and `OpenXRSpatialEntityExtension.query_snapshot` with the plane entities associated with `spatial_context`.
- `stop_built_in_tracking(clear_trackers: bool = true) -> void` — Stops the built-in plane tracking logic.
