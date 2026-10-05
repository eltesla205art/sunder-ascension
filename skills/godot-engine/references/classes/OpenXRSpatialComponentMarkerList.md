# OpenXRSpatialComponentMarkerList

**Inherits:** OpenXRSpatialComponentData

Object for storing the queries marker result data.

Object for storing the queries marker result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_marker_data(snapshot: RID, index: int) -> Variant` *const* — Returns either a String or a PackedByteArray buffer with data for the marker at this `index`.
- `get_marker_id(index: int) -> int` *const* — Returns the marker ID for the marker at this `index`.
- `get_marker_type(index: int) -> int[OpenXRSpatialComponentMarkerList.MarkerType]` *const* — Returns the marker type for the marker at this `index`.

## Enum MarkerType

- `MARKER_TYPE_UNKNOWN = 0` — Unknown or unset marker type.
- `MARKER_TYPE_QRCODE = 1` — Marker based on a QR code.
- `MARKER_TYPE_MICRO_QRCODE = 2` — Marker based on a micro QR code.
- `MARKER_TYPE_ARUCO = 3` — Marker based on an ArUco code.
- `MARKER_TYPE_APRIL_TAG = 4` — Marker based on an April Tag.
- `MARKER_TYPE_MAX = 5` — Maximum value for this enum.
