# AStar2D

**Inherits:** RefCounted

An implementation of A* for finding the shortest path between two vertices on a connected graph in 2D space.

An implementation of the A* algorithm, used to find the shortest path between two vertices on a connected graph in 2D space. See AStar3D for a more thorough explanation on how to use this class. AStar2D is a wrapper for AStar3D that enforces 2D coordinates.

## Properties

- `neighbor_filter_enabled: bool` = `false` — If `true` enables the filtering of neighbors via `_filter_neighbor`.

## Methods

- `_compute_cost(from_id: int, to_id: int) -> float` *virtual const* — Called when computing the cost between two connected points.
- `_estimate_cost(from_id: int, end_id: int) -> float` *virtual const* — Called when estimating the cost between a point and the path's ending point.
- `_filter_neighbor(from_id: int, neighbor_id: int) -> bool` *virtual const* — Called when neighboring enters processing and if `neighbor_filter_enabled` is `true`.
- `add_point(id: int, position: Vector2, weight_scale: float = 1.0) -> void` — Adds a new point at the given position with the given identifier.
- `are_points_connected(id: int, to_id: int, bidirectional: bool = true) -> bool` *const* — Returns whether there is a connection/segment between the given points.
- `clear() -> void` — Clears all the points and segments.
- `connect_points(id: int, to_id: int, bidirectional: bool = true) -> void` — Creates a segment between the given points.
- `disconnect_points(id: int, to_id: int, bidirectional: bool = true) -> void` — Deletes the segment between the given points.
- `get_available_point_id() -> int` *const* — Returns the next available point ID with no point associated to it.
- `get_closest_point(to_position: Vector2, include_disabled: bool = false) -> int` *const* — Returns the ID of the closest point to `to_position`, optionally taking disabled points into account.
- `get_closest_position_in_segment(to_position: Vector2) -> Vector2` *const* — Returns the closest position to `to_position` that resides inside a segment between two connected points.
- `get_id_path(from_id: int, to_id: int, allow_partial_path: bool = false) -> PackedInt64Array` — Returns an array with the IDs of the points that form the path found by AStar2D between the given points.
- `get_point_capacity() -> int` *const* — Returns the capacity of the structure backing the points, useful in conjunction with `reserve_space`.
- `get_point_connections(id: int) -> PackedInt64Array` — Returns an array with the IDs of the points that form the connection with the given point.
- `get_point_count() -> int` *const* — Returns the number of points currently in the points pool.
- `get_point_ids() -> PackedInt64Array` — Returns an array of all point IDs.
- `get_point_path(from_id: int, to_id: int, allow_partial_path: bool = false) -> PackedVector2Array` — Returns an array with the points that are in the path found by AStar2D between the given points.
- `get_point_position(id: int) -> Vector2` *const* — Returns the position of the point associated with the given `id`.
- `get_point_weight_scale(id: int) -> float` *const* — Returns the weight scale of the point associated with the given `id`.
- `has_point(id: int) -> bool` *const* — Returns whether a point associated with the given `id` exists.
- `is_point_disabled(id: int) -> bool` *const* — Returns whether a point is disabled or not for pathfinding.
- `remove_point(id: int) -> void` — Removes the point associated with the given `id` from the points pool.
- `reserve_space(num_nodes: int) -> void` — Reserves space internally for `num_nodes` points.
- `set_point_disabled(id: int, disabled: bool = true) -> void` — Disables or enables the specified point for pathfinding.
- `set_point_position(id: int, position: Vector2) -> void` — Sets the `position` for the point with the given `id`.
- `set_point_weight_scale(id: int, weight_scale: float) -> void` — Sets the `weight_scale` for the point with the given `id`.
