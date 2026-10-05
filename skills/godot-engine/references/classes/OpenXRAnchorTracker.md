# OpenXRAnchorTracker

**Inherits:** OpenXRSpatialEntityTracker

Positional tracker for our spatial entity anchor extension.

Positional tracker for our OpenXR spatial entity anchor extension, it tracks a user defined location in real space and maps it to our virtual space.

## Properties

- `uuid: String` = `""` — The UUID provided for persistent anchors.

## Methods

- `has_uuid() -> bool` *const* — Returns `true` if a non-zero UUID is set.

## Signals

- `uuid_changed()` — Emitted when the UUID for this anchor was changed.
