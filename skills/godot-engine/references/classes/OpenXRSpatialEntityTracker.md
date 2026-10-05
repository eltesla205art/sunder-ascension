# OpenXRSpatialEntityTracker

**Inherits:** XRPositionalTracker

Base class for Positional trackers managed by OpenXR's spatial entity extensions.

These are trackers created and managed by OpenXR's spatial entity extensions that give access to specific data related to OpenXR's spatial entities. They will always be of type `TRACKER_ANCHOR`.

## Properties

- `entity: RID` = `RID()` — The spatial entity associated with this tracker.
- `spatial_tracking_state: OpenXRSpatialEntityTracker.EntityTrackingState` = `2` — The spatial tracking state for this tracker.
- `type: XRServer.TrackerType` = `8` — 

## Methods

- `add_next(next: OpenXRStructureBase) -> void` — Adds a new OpenXRStructureBase to the next-chain.
- `get_next() -> OpenXRStructureBase` *const* — Gets the head OpenXRStructureBase in the next-chain.
- `get_spatial_context() -> RID` *const* — Gets the spatial context used to create this OpenXRSpatialEntityTracker.
- `remove_next(next: OpenXRStructureBase) -> void` — Removes a `next` object previously added in `add_next` from the next-chain.
- `set_spatial_context(spatial_context: RID) -> void` — Sets the spatial context used to create this tracker.

## Signals

- `next_changed()` — Emitted when the next-chain changes, from either `add_next` or `remove_next`.
- `spatial_tracking_state_changed(spatial_tracking_state: int)` — 

## Enum EntityTrackingState

- `ENTITY_TRACKING_STATE_STOPPED = 1` — This anchor has stopped tracking.
- `ENTITY_TRACKING_STATE_PAUSED = 2` — Tracking is currently paused.
- `ENTITY_TRACKING_STATE_TRACKING = 3` — This anchor is currently being tracked.
