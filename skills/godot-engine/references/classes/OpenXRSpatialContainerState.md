# OpenXRSpatialContainerState

**Inherits:** RefCounted

An object representing the state of an OpenXR spatial container.

The OpenXRSpatialContainerState object holds information about the current state of a spatial container, including its visibility, interactability, and bounds mode.

## Methods

- `get_bounds_mode() -> int[OpenXRSpatialContainerState.BoundsMode]` *const* — Returns the current bounds mode of the spatial container.
- `is_interactable() -> bool` *const* — Returns the current interactability of the spatial container.
- `is_visible() -> bool` *const* — Returns the current visibility state of the spatial container.

## Enum BoundsMode

- `BOUNDS_MODE_BOUNDED = 0` — The spatial container is in bounded mode.
- `BOUNDS_MODE_IMMERSIVE = 1` — The spatial container is in immersive mode.
