# OpenXRSpatialComponentPlaneAlignmentList

**Inherits:** OpenXRSpatialComponentData

Object for storing the queries plane alignment result data.

Object for storing the queries plane alignment result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_plane_alignment(index: int) -> int[OpenXRSpatialComponentPlaneAlignmentList.PlaneAlignment]` *const* — Returns the plane alignment for the parent entity at this `index`.

## Enum PlaneAlignment

- `PLANE_ALIGNMENT_HORIZONTAL_UPWARD = 0` — Plane is facing upward.
- `PLANE_ALIGNMENT_HORIZONTAL_DOWNWARD = 1` — Plane is facing downwards.
- `PLANE_ALIGNMENT_VERTICAL = 2` — Plane is vertically aligned.
- `PLANE_ALIGNMENT_ARBITRARY = 3` — Plane has an arbitrary alignment.
