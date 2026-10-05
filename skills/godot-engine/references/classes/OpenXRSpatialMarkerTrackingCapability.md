# OpenXRSpatialMarkerTrackingCapability

**Inherits:** OpenXRExtensionWrapper

Implementation for handling spatial entity marker tracking logic.

This class handles the OpenXR marker tracking spatial entity extension.

## Methods

- `do_entity_update(spatial_context: RID, component_data: OpenXRSpatialComponentData[], next_snapshot_create: OpenXRStructureBase = null, next_snapshot_query: OpenXRStructureBase = null) -> void` — Calls `OpenXRSpatialEntityExtension.update_spatial_entities` and `OpenXRSpatialEntityExtension.query_snapshot` with the marker entities associated with `spatial_context`.
- `get_built_in_tracking_state() -> int[OpenXRSpatialEntityExtension.TrackingState]` — Returns the state of the built-in tracking system.
- `is_april_tag_supported() -> bool` — Returns `true` if April tag marker tracking is supported by the current device.
- `is_aruco_supported() -> bool` — Returns `true` if ArUco marker tracking is supported by the current device.
- `is_micro_qrcode_supported() -> bool` — Returns `true` if micro QR code marker tracking is supported by the current device.
- `is_qrcode_supported() -> bool` — Returns `true` if QR code marker tracking is supported by the current device.
- `start_built_in_tracking(marker_types: OpenXRSpatialMarkerTrackingCapability.MarkerTypeFlags) -> bool` — Starts the built-in marker tracking logic for the specified marker types.
- `start_entity_discovery(spatial_context: RID, component_data: OpenXRSpatialComponentData[], next_snapshot_create: OpenXRStructureBase = null, next_snapshot_query: OpenXRStructureBase = null, user_callback: Callable = Callable()) -> OpenXRFutureResult` — Calls `OpenXRSpatialEntityExtension.discover_spatial_entities` and `OpenXRSpatialEntityExtension.query_snapshot` with the marker entities associated with `spatial_context`.
- `stop_built_in_tracking(clear_trackers: bool = true) -> void` — Stops the built-in marker tracking logic.

## Enum MarkerTypeFlags

- `MARKER_QR_CODE = 1` — QR Code.
- `MARKER_MICRO_QR_CODE = 2` — Micro QR Code.
- `MARKER_ARUCO = 4` — ArUco marker.
- `MARKER_APRIL_TAG = 8` — April tag.
