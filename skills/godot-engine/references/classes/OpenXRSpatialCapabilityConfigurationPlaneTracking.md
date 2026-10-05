# OpenXRSpatialCapabilityConfigurationPlaneTracking

**Inherits:** OpenXRSpatialCapabilityConfigurationBaseHeader

Configuration header for plane tracking.

Configuration header for plane tracking. Pass this to `OpenXRSpatialEntityExtension.create_spatial_context` to create a spatial context with plane tracking capabilities.

## Methods

- `get_enabled_components() -> PackedInt64Array` *const* — Returns the components enabled by this configuration.
- `supports_labels() -> bool` — Returns `true` if we support the plane semantic label component (only valid after the OpenXR session has started).
- `supports_mesh_2d() -> bool` — Returns `true` if we support the mesh 2D component (only valid after the OpenXR session has started).
- `supports_polygons() -> bool` — Returns `true` if we support the polygon 2D component (only valid after the OpenXR session has started).
