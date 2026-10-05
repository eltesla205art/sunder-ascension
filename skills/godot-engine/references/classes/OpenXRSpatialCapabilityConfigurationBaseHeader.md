# OpenXRSpatialCapabilityConfigurationBaseHeader

**Inherits:** RefCounted

Wrapper base class for OpenXR Spatial Capability Configuration headers.

Wrapper base class for OpenXR Spatial Capability Configuration headers. This class needs to be implemented for each capability configuration structure usable within OpenXR's spatial entities system.

## Methods

- `_get_configuration() -> int` *virtual* — Return a pointer (encoded as an `int64_t`) to a struct holding the spatial capability configuration data.
- `_has_valid_configuration() -> bool` *virtual const* — Return `true` if this object contains a valid configuration that can be retrieved when calling `_get_configuration`.
- `get_configuration() -> int` — Gets a pointer to the `XrSpatialCapabilityConfigurationBaseHeaderEXT` struct.
- `has_valid_configuration() -> bool` *const* — Returns `true` if this object contains a valid configuration that can be used when calling `OpenXRSpatialEntityExtension.create_spatial_context`.
