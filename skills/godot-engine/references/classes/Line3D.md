# Line3D

**Inherits:** GeometryInstance3D

A node to draw 3D lines in space. Note: This class currently has no functionality and only serves as a base class for Trail3D.



## Enum MeshAlignment

- `MESH_ALIGNMENT_LOCAL = 0` — Align the line normal to the local Y axis of the line node.
- `MESH_ALIGNMENT_BILLBOARD = 1` — Align the normal of each section of the Line3D to face the camera.
- `MESH_ALIGNMENT_MAX = 2` — Represents the size of the `MeshAlignment` enum.

## Enum TilingMode

- `TILING_MODE_UNIT = 0` — Assign UVs from `0` to `1` across the length of the line.
- `TILING_MODE_LENGTH = 1` — Assign UVs from `0` to current length, across the length of the line.
- `TILING_MAX = 2` — Represents the size of the `TilingMode` enum.

## Enum MaterialMode

- `MATERIAL_MODE_MIX = 0` — Assign a built-in mix material to the line.
- `MATERIAL_MODE_ADD = 1` — Assign a built-in additive material to the line.
- `MATERIAL_MODE_CUSTOM = 2` — Assign a custom material to the line.
- `MATERIAL_MODE_MAX = 3` — Represents the size of the `MaterialMode` enum.
