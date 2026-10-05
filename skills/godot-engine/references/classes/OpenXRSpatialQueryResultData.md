# OpenXRSpatialQueryResultData

**Inherits:** OpenXRSpatialComponentData

Object for storing the main query result data.

Object for storing the main query result data when calling `OpenXRSpatialEntityExtension.query_snapshot`. This must always be the first component requested.

## Methods

- `get_capacity() -> int` *const* — Returns the number of entities that were retrieved.
- `get_entity_id(index: int) -> int` *const* — Returns the entity id (`XrSpatialEntityIdEXT`) for the entity at this `index`.
- `get_entity_state(index: int) -> int[OpenXRSpatialEntityTracker.EntityTrackingState]` *const* — Returns the entity state for the entity at this `index`.
