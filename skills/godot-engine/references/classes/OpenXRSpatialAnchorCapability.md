# OpenXRSpatialAnchorCapability

**Inherits:** OpenXRExtensionWrapper

Implementation for handling spatial entity anchor logic.

This is an internal class that handles the OpenXR anchor spatial entity extension.

## Methods

- `create_default_persistence_context(user_callback: Callable = Callable()) -> OpenXRFutureResult` — Calls `create_persistence_context` with a configuration that likely works with the XR runtime.
- `create_new_anchor(transform: Transform3D, spatial_context: RID = RID(), next: OpenXRStructureBase = null) -> OpenXRAnchorTracker` — Creates a new anchor that will be tracked by the XR runtime.
- `create_persistence_context(scope: OpenXRSpatialAnchorCapability.PersistenceScope, user_callback: Callable = Callable()) -> OpenXRFutureResult` — Creates a new persistence context for storing persistent data.
- `do_entity_update(spatial_context: RID, component_data: OpenXRSpatialComponentData[], next_snapshot_create: OpenXRStructureBase = null, next_snapshot_query: OpenXRStructureBase = null) -> void` — Calls `OpenXRSpatialEntityExtension.update_spatial_entities` and `OpenXRSpatialEntityExtension.query_snapshot` with the anchor entities associated with `spatial_context`.
- `free_persistence_context(persistence_context: RID) -> void` — Frees a persistence context previously created with `create_persistence_context`.
- `get_persistence_context_handle(persistence_context: RID) -> int` *const* — Returns the internal handle for this persistence context.
- `is_persistence_scope_supported(scope: OpenXRSpatialAnchorCapability.PersistenceScope) -> bool` — Returns `true` if this persistence scope is supported by our spatial anchor capability.
- `is_spatial_anchor_supported() -> bool` — Returns `true` if spatial anchors are supported by the hardware.
- `is_spatial_persistence_supported() -> bool` — Returns `true` if persistent spatial anchors are supported by the hardware.
- `persist_anchor(anchor_tracker: OpenXRAnchorTracker, persistence_context: RID = RID(), user_callback: Callable = Callable()) -> OpenXRFutureResult` — Changes this anchor into a persistent anchor.
- `remove_anchor(anchor_tracker: OpenXRAnchorTracker) -> void` — Remove an anchor previously created with `create_new_anchor`.
- `start_entity_discovery(spatial_context: RID, component_data: OpenXRSpatialComponentData[], next_snapshot_create: OpenXRStructureBase = null, next_snapshot_query: OpenXRStructureBase = null, user_callback: Callable = Callable()) -> OpenXRFutureResult` — Calls `OpenXRSpatialEntityExtension.discover_spatial_entities` and `OpenXRSpatialEntityExtension.query_snapshot` with the anchor entities associated with `spatial_context`.
- `unpersist_anchor(anchor_tracker: OpenXRAnchorTracker, persistence_context: RID = RID(), user_callback: Callable = Callable()) -> OpenXRFutureResult` — Removes the persistent data from this anchor.

## Enum PersistenceScope

- `PERSISTENCE_SCOPE_SYSTEM_MANAGED = 1` — Provides the application with read-only access (i.e. application cannot modify this scope) to spatial entities persisted and managed by the system.
- `PERSISTENCE_SCOPE_LOCAL_ANCHORS = 1000781000` — Persistence operations and data access is limited to spatial anchors, on the same device, for the same user and same app (using `persist_anchor` and `unpersist_anchor` functions)
