# OpenXRSpatialComponentPlaneSemanticLabelList

**Inherits:** OpenXRSpatialComponentData

Object for storing the queries plane semantic label result data.

Object for storing the queries plane semantic label result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_plane_semantic_label(index: int) -> int[OpenXRSpatialComponentPlaneSemanticLabelList.PlaneSemanticLabel]` *const* — Returns the plane semantic label for the parent entity at this `index`.

## Enum PlaneSemanticLabel

- `PLANE_SEMANTIC_LABEL_UNCATEGORIZED = 1` — Uncategorized plane.
- `PLANE_SEMANTIC_LABEL_FLOOR = 2` — Plane represents a floor.
- `PLANE_SEMANTIC_LABEL_WALL = 3` — Plane represents a wall.
- `PLANE_SEMANTIC_LABEL_CEILING = 4` — Plane represents a ceiling.
- `PLANE_SEMANTIC_LABEL_TABLE = 5` — Plane represents the surface of a table.
