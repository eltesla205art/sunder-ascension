# HeightMapShape3D

**Inherits:** Shape3D

A 3D heightmap shape used for physics collision.

A 3D heightmap shape, intended for use in physics to provide a shape for a CollisionShape3D. This type is most commonly used for terrain with vertices placed in a fixed-width grid. The heightmap is represented as a 2D grid of height values, which represent the position of grid points on the Y axis. Grid points are spaced 1 unit apart on the X and Z axes, and the grid is centered on the origin of the CollisionShape3D node.

## Properties

- `map_data: PackedFloat32Array` = `PackedFloat32Array(0, 0, 0, 0)` — Heightmap data.
- `map_depth: int` = `2` — Number of vertices in the depth of the heightmap.
- `map_width: int` = `2` — Number of vertices in the width of the heightmap.

## Methods

- `get_max_height() -> float` *const* — Returns the largest height value found in `map_data`.
- `get_min_height() -> float` *const* — Returns the smallest height value found in `map_data`.
- `update_map_data_from_image(image: Image, height_min: float, height_max: float) -> void` — Updates `map_data` with data read from an Image reference.
