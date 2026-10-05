# NavigationAgent3D

**Inherits:** Node

A 3D agent used to pathfind to a position while avoiding obstacles.

A 3D agent used to pathfind to a position while avoiding static and dynamic obstacles. The calculation can be used by the parent node to dynamically move it along the path. Requires navigation data to work correctly. Dynamic obstacles are avoided using RVO collision avoidance.

## Properties

- `avoidance_enabled: bool` = `false` — If `true` the agent is registered for an RVO avoidance callback on the NavigationServer3D.
- `avoidance_layers: int` = `1` — A bitfield determining the avoidance layers for this NavigationAgent.
- `avoidance_mask: int` = `1` — A bitfield determining what other avoidance agents and obstacles this NavigationAgent will avoid when a bit matches at least one of their `avoidance_layers`.
- `avoidance_priority: float` = `1.0` — The agent does not adjust the velocity for other agents that would match the `avoidance_mask` but have a lower `avoidance_priority`.
- `debug_enabled: bool` = `false` — If `true` shows debug visuals for this agent.
- `debug_path_custom_color: Color` = `Color(1, 1, 1, 1)` — If `debug_use_custom` is `true` uses this color for this agent instead of global color.
- `debug_path_custom_point_size: float` = `4.0` — If `debug_use_custom` is `true` uses this rasterized point size for rendering path points for this agent instead of global point size.
- `debug_use_custom: bool` = `false` — If `true` uses the defined `debug_path_custom_color` for this agent instead of global color.
- `height: float` = `1.0` — The height of the avoidance agent.
- `keep_y_velocity: bool` = `true` — If `true`, and the agent uses 2D avoidance, it will remember the set y-axis velocity and reapply it after the avoidance step.
- `max_neighbors: int` = `10` — The maximum number of neighbors for the agent to consider.
- `max_speed: float` = `10.0` — The maximum speed that an agent can move.
- `navigation_layers: int` = `1` — A bitfield determining which navigation layers of navigation regions this agent will use to calculate a path.
- `neighbor_distance: float` = `50.0` — The distance to search for other agents.
- `path_desired_distance: float` = `1.0` — The distance threshold before a path point is considered to be reached.
- `path_height_offset: float` = `0.0` — The height offset is subtracted from the y-axis value of any vector path position for this NavigationAgent.
- `path_max_distance: float` = `5.0` — The maximum distance the agent is allowed away from the ideal path to the final position.
- `path_metadata_flags: NavigationPathQueryParameters3D.PathMetadataFlags` = `7` — Additional information to return with the navigation path.
- `path_postprocessing: NavigationPathQueryParameters3D.PathPostProcessing` = `0` — The path postprocessing applied to the raw path corridor found by the `pathfinding_algorithm`.
- `path_return_max_length: float` = `0.0` — The maximum allowed length of the returned path in world units.
- `path_return_max_radius: float` = `0.0` — The maximum allowed radius in world units that the returned path can be from the path start.
- `path_search_max_distance: float` = `0.0` — The maximum distance a searched polygon can be away from the start polygon before the pathfinding cancels the search for a path to the (possibly unreachable or very far away) target position polygon.
- `path_search_max_polygons: int` = `4096` — The maximum number of polygons that are searched before the pathfinding cancels the search for a path to the (possibly unreachable or very far away) target position polygon.
- `pathfinding_algorithm: NavigationPathQueryParameters3D.PathfindingAlgorithm` = `0` — The pathfinding algorithm used in the path query.
- `radius: float` = `0.5` — The radius of the avoidance agent.
- `simplify_epsilon: float` = `0.0` — The path simplification amount in world units.
- `simplify_path: bool` = `false` — If `true` a simplified version of the path will be returned with less critical path points removed.
- `target_desired_distance: float` = `1.0` — The distance threshold before the target is considered to be reached.
- `target_position: Vector3` = `Vector3(0, 0, 0)` — If set, a new navigation path from the current agent position to the `target_position` is requested from the NavigationServer.
- `time_horizon_agents: float` = `1.0` — The minimal amount of time for which this agent's velocities, that are computed with the collision avoidance algorithm, are safe with respect to other agents.
- `time_horizon_obstacles: float` = `0.0` — The minimal amount of time for which this agent's velocities, that are computed with the collision avoidance algorithm, are safe with respect to static avoidance obstacles.
- `use_3d_avoidance: bool` = `false` — If `true`, the agent calculates avoidance velocities in 3D omnidirectionally, e.g. for games that take place in air, underwater or space.
- `velocity: Vector3` = `Vector3(0, 0, 0)` — Sets the new wanted velocity for the agent.

## Methods

- `distance_to_target() -> float` *const* — Returns the distance to the target position, using the agent's global position.
- `get_avoidance_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `avoidance_layers` bitmask is enabled, given a `layer_number` between 1 and 32.
- `get_avoidance_mask_value(mask_number: int) -> bool` *const* — Returns whether or not the specified mask of the `avoidance_mask` bitmask is enabled, given a `mask_number` between 1 and 32.
- `get_current_navigation_path() -> PackedVector3Array` *const* — Returns this agent's current path from start to finish in global coordinates.
- `get_current_navigation_path_index() -> int` *const* — Returns which index the agent is currently on in the navigation path's PackedVector3Array.
- `get_current_navigation_result() -> NavigationPathQueryResult3D` *const* — Returns the path query result for the path the agent is currently following.
- `get_final_position() -> Vector3` — Returns the reachable final position of the current navigation path in global coordinates.
- `get_navigation_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `navigation_layers` bitmask is enabled, given a `layer_number` between 1 and 32.
- `get_navigation_map() -> RID` *const* — Returns the RID of the navigation map for this NavigationAgent node.
- `get_next_path_position() -> Vector3` — Returns the next position in global coordinates that can be moved to, making sure that there are no static objects in the way.
- `get_path_length() -> float` *const* — Returns the length of the currently calculated path.
- `get_rid() -> RID` *const* — Returns the RID of this agent on the NavigationServer3D.
- `is_navigation_finished() -> bool` — Returns `true` if the agent's navigation has finished.
- `is_target_reachable() -> bool` — Returns `true` if `get_final_position` is within `target_desired_distance` of the `target_position`.
- `is_target_reached() -> bool` *const* — Returns `true` if the agent reached the target, i.e. the agent moved within `target_desired_distance` of the `target_position`.
- `set_avoidance_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `avoidance_layers` bitmask, given a `layer_number` between 1 and 32.
- `set_avoidance_mask_value(mask_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified mask in the `avoidance_mask` bitmask, given a `mask_number` between 1 and 32.
- `set_navigation_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `navigation_layers` bitmask, given a `layer_number` between 1 and 32.
- `set_navigation_map(navigation_map: RID) -> void` — Sets the RID of the navigation map this NavigationAgent node should use and also updates the `agent` on the NavigationServer.
- `set_velocity_forced(velocity: Vector3) -> void` — Replaces the internal velocity in the collision avoidance simulation with `velocity`.

## Signals

- `link_reached(details: Dictionary)` — Signals that the agent reached a navigation link.
- `navigation_finished()` — Signals that the agent's navigation has finished.
- `path_changed()` — Emitted when the agent had to update the loaded path: - because path was previously empty. - because navigation map has changed. - because agent pushed further away from the current path segment than the `path_max_distance`.
- `target_reached()` — Signals that the agent reached the target, i.e. the agent moved within `target_desired_distance` of the `target_position`.
- `velocity_computed(safe_velocity: Vector3)` — Notifies when the collision avoidance velocity is calculated.
- `waypoint_reached(details: Dictionary)` — Signals that the agent reached a waypoint.
