# OpenXRSpatialCapabilityConfigurationAprilTag

**Inherits:** OpenXRSpatialCapabilityConfigurationBaseHeader

Configuration header for April tag markers.

Configuration header for April tag markers. Pass this to `OpenXRSpatialEntityExtension.create_spatial_context` to create a spatial context that can detect April tags.

## Properties

- `april_dict: OpenXRSpatialCapabilityConfigurationAprilTag.AprilTagDict` = `4` — Dictionary to use to decode April tags.

## Methods

- `get_enabled_components() -> PackedInt64Array` *const* — Returns the components enabled by this configuration.

## Enum AprilTagDict

- `APRIL_TAG_DICT_16H5 = 1` — 4 by 4 bits, minimum Hamming distance between any two codes = 5, 30 codes.
- `APRIL_TAG_DICT_25H9 = 2` — 5 by 5 bits, minimum Hamming distance between any two codes = 9, 35 codes.
- `APRIL_TAG_DICT_36H10 = 3` — 6 by 6 bits, minimum Hamming distance between any two codes = 10, 2320 codes.
- `APRIL_TAG_DICT_36H11 = 4` — 6 by 6 bits, minimum Hamming distance between any two codes = 11, 587 codes.
