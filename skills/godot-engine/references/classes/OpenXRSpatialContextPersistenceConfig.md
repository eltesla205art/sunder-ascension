# OpenXRSpatialContextPersistenceConfig

**Inherits:** OpenXRStructureBase

Configuration header for spatial persistence.

Configuration header for spatial persistence. Pass this to `OpenXRSpatialEntityExtension.create_spatial_context` as the next parameter to create a spatial context with spatial persistence capabilities.

## Methods

- `add_persistence_context(persistence_context: RID) -> void` — Adds a persistence context to this configuration.
- `get_persistence_contexts() -> Array` *const* — Gets the persistence context(s) (as RIDs) received by `add_persistence_context`.
- `remove_persistence_context(persistence_context: RID) -> void` — Removes a persistence context.
