# AStarGrid2D

**Inherits:** RefCounted

An implementation of A* for finding the shortest path between two points on a partial 2D grid.

AStarGrid2D is a variant of AStar2D that is specialized for partial 2D grids. It is simpler to use because it doesn't require you to manually create points and connect them together. This class also supports multiple types of heuristics, modes for diagonal movement, and a jumping mode to speed up calculations. To use AStarGrid2D, you only need to set the `region` of the grid, optionally set the `cell_size`, and then call the `update` method:  To remove a point from the pathfinding grid, it must be set as "solid" with `set_point_solid`.

## Properties

- `cell_shape: AStarGrid2D.CellShape` = `0` — The cell shape.
- `cell_size: Vector2` = `Vector2(1, 1)` — The size of the point cell which will be applied to calculate the resulting point position returned by `get_point_path`.
- `default_compute_heuristic: AStarGrid2D.Heuristic` = `0` — The default `Heuristic` which will be used to calculate the cost between two points if `_compute_cost` was not overridden.
- `default_estimate_heuristic: AStarGrid2D.Heuristic` = `0` — The default `Heuristic` which will be used to calculate the cost between the point and the end point if `_estimate_cost` was not overridden.
- `diagonal_mode: AStarGrid2D.DiagonalMode` = `0` — A specific `DiagonalMode` mode which will force the path to avoid or accept the specified diagonals.
- `jumping_enabled: bool` = `false` — Enables or disables jumping to skip up the intermediate points and speeds up the searching algorithm.
- `offset: Vector2` = `Vector2(0, 0)` — The offset of the grid which will be applied to calculate the resulting point position returned by `get_point_path`.
- `region: Rect2i` = `Rect2i(0, 0, 0, 0)` — The region of grid cells available for pathfinding.
- `size: Vector2i` = `Vector2i(0, 0)` *(deprecated)* — The size of the grid (number of cells of size `cell_size` on each axis).

## Methods

- `_compute_cost(from_id: Vector2i, to_id: Vector2i) -> float` *virtual const* — Called when computing the cost between two connected points.
- `_estimate_cost(from_id: Vector2i, end_id: Vector2i) -> float` *virtual const* — Called when estimating the cost between a point and the path's ending point.
- `clear() -> void` — Clears the grid and sets the `region` to `Rect2i(0, 0, 0, 0)`.
- `fill_solid_region(region: Rect2i, solid: bool = true) -> void` — Fills the given `region` on the grid with the specified value for the solid flag.
- `fill_weight_scale_region(region: Rect2i, weight_scale: float) -> void` — Fills the given `region` on the grid with the specified value for the weight scale.
- `get_id_path(from_id: Vector2i, to_id: Vector2i, allow_partial_path: bool = false) -> Vector2i[]` — Returns an array with the IDs of the points that form the path found by AStar2D between the given points.
- `get_point_data_in_region(region: Rect2i) -> Dictionary[]` *const* — Returns an array of dictionaries with point data (`id`: Vector2i, `position`: Vector2, `solid`: bool, `weight_scale`: float) within a `region`.
- `get_point_path(from_id: Vector2i, to_id: Vector2i, allow_partial_path: bool = false) -> PackedVector2Array` — Returns an array with the points that are in the path found by AStarGrid2D between the given points.
- `get_point_position(id: Vector2i) -> Vector2` *const* — Returns the position of the point associated with the given `id`.
- `get_point_weight_scale(id: Vector2i) -> float` *const* — Returns the weight scale of the point associated with the given `id`.
- `is_dirty() -> bool` *const* — Indicates that the grid parameters were changed and `update` needs to be called.
- `is_in_bounds(x: int, y: int) -> bool` *const* — Returns `true` if the `x` and `y` is a valid grid coordinate (id), i.e. if it is inside `region`.
- `is_in_boundsv(id: Vector2i) -> bool` *const* — Returns `true` if the `id` vector is a valid grid coordinate, i.e. if it is inside `region`.
- `is_point_solid(id: Vector2i) -> bool` *const* — Returns `true` if a point is disabled for pathfinding.
- `set_point_solid(id: Vector2i, solid: bool = true) -> void` — Disables or enables the specified point for pathfinding.
- `set_point_weight_scale(id: Vector2i, weight_scale: float) -> void` — Sets the `weight_scale` for the point with the given `id`.
- `update() -> void` — Updates the internal state of the grid according to the parameters to prepare it to search the path.

## Enum Heuristic

- `HEURISTIC_EUCLIDEAN = 0` — The Euclidean heuristic to be used for the pathfinding using the following formula:  Note: This is also the internal heuristic used in AStar3D and AStar2D by default (with the inclusion of possible z-axis coordinate).
- `HEURISTIC_MANHATTAN = 1` — The Manhattan heuristic to be used for the pathfinding using the following formula:  Note: This heuristic is intended to be used with 4-side orthogonal movements, provided by setting the `diagonal_mode` to `DIAGONAL_MODE_NEVER`.
- `HEURISTIC_OCTILE = 2` — The Octile heuristic to be used for the pathfinding using the following formula:
- `HEURISTIC_CHEBYSHEV = 3` — The Chebyshev heuristic to be used for the pathfinding using the following formula:
- `HEURISTIC_MAX = 4` — Represents the size of the `Heuristic` enum.

## Enum DiagonalMode

- `DIAGONAL_MODE_ALWAYS = 0` — The pathfinding algorithm will ignore solid neighbors around the target cell and allow passing using diagonals.
- `DIAGONAL_MODE_NEVER = 1` — The pathfinding algorithm will ignore all diagonals and the way will be always orthogonal.
- `DIAGONAL_MODE_AT_LEAST_ONE_WALKABLE = 2` — The pathfinding algorithm will avoid using diagonals if at least two obstacles have been placed around the neighboring cells of the specific path segment.
- `DIAGONAL_MODE_ONLY_IF_NO_OBSTACLES = 3` — The pathfinding algorithm will avoid using diagonals if any obstacle has been placed around the neighboring cells of the specific path segment.
- `DIAGONAL_MODE_MAX = 4` — Represents the size of the `DiagonalMode` enum.

## Enum CellShape

- `CELL_SHAPE_SQUARE = 0` — Rectangular cell shape.
- `CELL_SHAPE_ISOMETRIC_RIGHT = 1` — Diamond cell shape (for isometric look).
- `CELL_SHAPE_ISOMETRIC_DOWN = 2` — Diamond cell shape (for isometric look).
- `CELL_SHAPE_MAX = 3` — Represents the size of the `CellShape` enum.
