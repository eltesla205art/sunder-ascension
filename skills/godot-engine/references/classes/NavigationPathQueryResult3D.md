# NavigationPathQueryResult3D

**Inherits:** RefCounted

Represents the result of a 3D pathfinding query.

This class stores the result of a 3D navigation path query from the NavigationServer3D.

## Properties

- `path: PackedVector3Array` = `PackedVector3Array()` — The resulting path array from the navigation query.
- `path_length: float` = `0.0` — Returns the length of the path.
- `path_owner_ids: PackedInt64Array` = `PackedInt64Array()` — The `ObjectID`s of the Objects which manage the regions and links each point of the path goes through.
- `path_rids: RID[]` = `[]` — The RIDs of the regions and links that each point of the path goes through.
- `path_types: PackedInt32Array` = `PackedInt32Array()` — The type of navigation primitive (region or link) that each point of the path goes through.

## Methods

- `reset() -> void` — Reset the result object to its initial state.

## Enum PathSegmentType

- `PATH_SEGMENT_TYPE_REGION = 0` — This segment of the path goes through a region.
- `PATH_SEGMENT_TYPE_LINK = 1` — This segment of the path goes through a link.
