# OpenXRSpatialComponentPersistenceList

**Inherits:** OpenXRSpatialComponentData

Object for storing the query persistence result data.

Object for storing the query persistence result data when calling `OpenXRSpatialEntityExtension.query_snapshot`.

## Methods

- `get_persistent_state(index: int) -> int` *const* — Returns the persistent state (`XrSpatialPersistenceStateEXT`) for the entity at this `index`.
- `get_persistent_uuid(index: int) -> String` *const* — Returns the persistent uuid for the entity at this `index`.
