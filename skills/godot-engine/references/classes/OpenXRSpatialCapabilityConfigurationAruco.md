# OpenXRSpatialCapabilityConfigurationAruco

**Inherits:** OpenXRSpatialCapabilityConfigurationBaseHeader

Configuration header for ArUco markers.

Configuration header for ArUco markers. Pass this to `OpenXRSpatialEntityExtension.create_spatial_context` to create a spatial context that can detect ArUco markers.

## Properties

- `aruco_dict: OpenXRSpatialCapabilityConfigurationAruco.ArucoDict` = `16` — Dictionary to use to decode ArUco markers.

## Methods

- `get_enabled_components() -> PackedInt64Array` *const* — Returns the components enabled by this configuration.

## Enum ArucoDict

- `ARUCO_DICT_4X4_50 = 1` — 4 by 4 pixel ArUco marker dictionary with 50 IDs.
- `ARUCO_DICT_4X4_100 = 2` — 4 by 4 pixel ArUco marker dictionary with 100 IDs.
- `ARUCO_DICT_4X4_250 = 3` — 4 by 4 pixel ArUco marker dictionary with 250 IDs.
- `ARUCO_DICT_4X4_1000 = 4` — 4 by 4 pixel ArUco marker dictionary with 1000 IDs.
- `ARUCO_DICT_5X5_50 = 5` — 5 by 5 pixel ArUco marker dictionary with 50 IDs.
- `ARUCO_DICT_5X5_100 = 6` — 5 by 5 pixel ArUco marker dictionary with 100 IDs.
- `ARUCO_DICT_5X5_250 = 7` — 5 by 5 pixel ArUco marker dictionary with 250 IDs.
- `ARUCO_DICT_5X5_1000 = 8` — 5 by 5 pixel ArUco marker dictionary with 1000 IDs.
- `ARUCO_DICT_6X6_50 = 9` — 6 by 6 pixel ArUco marker dictionary with 50 IDs.
- `ARUCO_DICT_6X6_100 = 10` — 6 by 6 pixel ArUco marker dictionary with 100 IDs.
- `ARUCO_DICT_6X6_250 = 11` — 6 by 6 pixel ArUco marker dictionary with 250 IDs.
- `ARUCO_DICT_6X6_1000 = 12` — 6 by 6 pixel ArUco marker dictionary with 1000 IDs.
- `ARUCO_DICT_7X7_50 = 13` — 7 by 7 pixel ArUco marker dictionary with 50 IDs.
- `ARUCO_DICT_7X7_100 = 14` — 7 by 7 pixel ArUco marker dictionary with 100 IDs.
- `ARUCO_DICT_7X7_250 = 15` — 7 by 7 pixel ArUco marker dictionary with 250 IDs.
- `ARUCO_DICT_7X7_1000 = 16` — 7 by 7 pixel ArUco marker dictionary with 1000 IDs.
