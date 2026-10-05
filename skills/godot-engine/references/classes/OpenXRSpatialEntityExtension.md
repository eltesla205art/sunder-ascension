# OpenXRSpatialEntityExtension

**Inherits:** OpenXRExtensionWrapper

OpenXR extension that handles spatial entities.

OpenXR extension that handles spatial entities and, when enabled, allows querying those spatial entities. This extension will also automatically manage XRTracker objects for static entities.

## Methods

- `add_spatial_entity(spatial_context: RID, entity_id: int, entity: int) -> RID` — Registers an entity that was created directly on the OpenXR runtime.
- `create_spatial_context(capability_configurations: OpenXRSpatialCapabilityConfigurationBaseHeader[], next: OpenXRStructureBase = null, user_callback: Callable = Callable(), failed_callback: Callable = Callable()) -> OpenXRFutureResult` — Creates a new spatial context that handles entities for the provided capability configurations.
- `discover_spatial_entities(spatial_context: RID, component_types: PackedInt64Array, next: OpenXRStructureBase = null, user_callback: Callable = Callable()) -> OpenXRFutureResult` — Starts a new discovery query, this will gather all objects tracked by the `spatial_context` that have at least one of the component types specified in `component_types`.
- `discover_spatial_entities_with_component_data(spatial_context: RID, component_data: OpenXRSpatialComponentData[], next: OpenXRStructureBase = null, user_callback: Callable = Callable()) -> OpenXRFutureResult` — Convenience method when the caller only has an Array of OpenXRSpatialComponentData and needs to discover spatial entities.
- `find_spatial_entity(entity_id: int) -> RID` — Returns the RID for the specified spatial entity ID.
- `free_spatial_context(spatial_context: RID) -> void` — Frees a spatial context previously created when calling `create_spatial_context`.
- `free_spatial_entity(entity: RID) -> void` — Frees an entity previously created when calling `add_spatial_entity` or `make_spatial_entity`.
- `free_spatial_snapshot(spatial_snapshot: RID) -> void` — Frees a spatial snapshot previously created when calling `discover_spatial_entities`.
- `get_float_buffer(spatial_snapshot: RID, buffer_id: int) -> PackedFloat32Array` *const* — Returns a buffer with floats from a buffer that was retrieved when taking a snapshot.
- `get_spatial_context_handle(spatial_context: RID) -> int` *const* — Returns the OpenXR spatial context handle for this snapshot.
- `get_spatial_context_ready(spatial_context: RID) -> bool` *const* — Returns `true` if the spatial context finished its creation and is ready to be used.
- `get_spatial_entity_context(entity: RID) -> RID` *const* — Returns the spatial context for this entity.
- `get_spatial_entity_id(entity: RID) -> int` *const* — Returns the internal `XrSpatialEntityIdEXT` associated with the entity.
- `get_spatial_snapshot_context(spatial_snapshot: RID) -> RID` *const* — Returns the spatial context related to this spatial snapshot.
- `get_spatial_snapshot_handle(spatial_snapshot: RID) -> int` *const* — Returns the OpenXR spatial snapshot handle for this snapshot.
- `get_string(spatial_snapshot: RID, buffer_id: int) -> String` *const* — Returns a string from a buffer that was retrieved when taking a snapshot.
- `get_uint8_buffer(spatial_snapshot: RID, buffer_id: int) -> PackedByteArray` *const* — Returns a buffer with 8 bit ints from a buffer that was retrieved when taking a snapshot.
- `get_uint16_buffer(spatial_snapshot: RID, buffer_id: int) -> PackedInt32Array` *const* — Returns a buffer with 16 bit ints from a buffer that was retrieved when taking a snapshot.
- `get_uint32_buffer(spatial_snapshot: RID, buffer_id: int) -> PackedInt32Array` *const* — Returns a buffer with 32 bit ints from a buffer that was retrieved when taking a snapshot.
- `get_vector2_buffer(spatial_snapshot: RID, buffer_id: int) -> PackedVector2Array` *const* — Returns a buffer with Vector2 entries from a buffer that was retrieved when taking a snapshot.
- `get_vector3_buffer(spatial_snapshot: RID, buffer_id: int) -> PackedVector3Array` *const* — Returns a buffer with Vector3 entries from a buffer that was retrieved when taking a snapshot.
- `make_spatial_entity(spatial_context: RID, entity_id: int) -> RID` — Creates a new entity for this `entity_id`.
- `query_snapshot(spatial_snapshot: RID, component_data: OpenXRSpatialComponentData[], next: OpenXRStructureBase = null) -> bool` — Queries the snapshot data.
- `supports_capability(capability: OpenXRSpatialEntityExtension.Capability) -> bool` — Returns `true` if this spatial entity `capability` is supported by the hardware used.
- `supports_component_type(capability: OpenXRSpatialEntityExtension.Capability, component_type: OpenXRSpatialEntityExtension.ComponentType) -> bool` — Returns `true` if this `capability` supports the `component_type`.
- `update_spatial_entities(spatial_context: RID, entities: RID[], component_types: PackedInt64Array, next: OpenXRStructureBase = null) -> RID` — Performs a snapshot for a limited number of entities.

## Signals

- `spatial_discovery_recommended(spatial_context: RID)` — Emitted when OpenXR recommends running a discovery query because entities managed by this spatial context have (likely) changed.

## Enum Capability

- `CAPABILITY_PLANE_TRACKING = 1000741000` — Plane tracking capability.
- `CAPABILITY_MARKER_TRACKING_QR_CODE = 1000743000` — QR code based marker tracking capability.
- `CAPABILITY_MARKER_TRACKING_MICRO_QR_CODE = 1000743001` — Micro QR code based marker tracking capability.
- `CAPABILITY_MARKER_TRACKING_ARUCO_MARKER = 1000743002` — ArUco marker based marker tracking capability.
- `CAPABILITY_MARKER_TRACKING_APRIL_TAG = 1000743003` — April tag based marker tracking capability.
- `CAPABILITY_ANCHOR = 1000762000` — Anchor capability.

## Enum ComponentType

- `COMPONENT_TYPE_BOUNDED_2D = 1` — Component that provides the 2D bounds for a spatial entity.
- `COMPONENT_TYPE_BOUNDED_3D = 2` — Component that provides the 3D bounds for a spatial entity.
- `COMPONENT_TYPE_PARENT = 3` — Component that provides the XrSpatialEntityIdEXT of the parent for a spatial entity.
- `COMPONENT_TYPE_MESH_3D = 4` — Component that provides a 3D mesh for a spatial entity.
- `COMPONENT_TYPE_PLANE_ALIGNMENT = 1000741000` — Component that provides the plane alignment enum for a spatial entity.
- `COMPONENT_TYPE_MESH_2D = 1000741001` — Component that provides a 2D mesh for a spatial entity.
- `COMPONENT_TYPE_POLYGON_2D = 1000741002` — Component that provides a 2D boundary polygon for a spatial entity.
- `COMPONENT_TYPE_PLANE_SEMANTIC_LABEL = 1000741003` — Component that provides a semantic label for a plane.
- `COMPONENT_TYPE_MARKER = 1000743000` — A component describing the marker type, ID and location.
- `COMPONENT_TYPE_ANCHOR = 1000762000` — Component that provides the location for an anchor.
- `COMPONENT_TYPE_PERSISTENCE = 1000763000` — Component that provides the persisted UUID for a spatial entity.

## Enum TrackingState

- `TRACKING_UNSUPPORTED_CAPABILITY = -3` — A capability supplied when creating the spatial context for tracking is unsupported.
- `TRACKING_NO_PERMISSION = -2` — A permission required by the tracking logic is missing.
- `TRACKING_SETUP_FAILED = -1` — Setup of the tracking logic failed, consult the logs for more details.
- `TRACKING_NOT_ACTIVE = 0` — Tracking is currently not active.
- `TRACKING_SETTING_UP = 1` — Tracking is being set up.
- `TRACKING_ENABLED = 2` — Tracking is enabled and running.
