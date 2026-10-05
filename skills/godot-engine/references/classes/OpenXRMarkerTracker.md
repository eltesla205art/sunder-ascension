# OpenXRMarkerTracker

**Inherits:** OpenXRSpatialEntityTracker

Spatial entity tracker for our spatial entity marker tracking extension.

Spatial entity tracker for our OpenXR spatial entity marker tracking extension. These trackers identify entities in our real space detected by a visual marker such as a QRCode or ArUco code, and map their location to our virtual space.

## Properties

- `bounds_size: Vector2` = `Vector2(0, 0)` — The bounds size for this marker.
- `marker_id: int` = `0` — The marker ID for this marker, this is only returned for ArUco and April Tag markers.
- `marker_type: OpenXRSpatialComponentMarkerList.MarkerType` = `0` — The type of marker.

## Methods

- `get_marker_data() -> Variant` *const* — Returns the marker data for this marker.
- `set_marker_data(marker_data: Variant) -> void` — Sets the marker data for this marker.
