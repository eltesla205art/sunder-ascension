# NavigationPathQueryParameters3D

**Inherits:** RefCounted

Provides parameters for 3D navigation path queries.

By changing various properties of this object, such as the start and target position, you can configure path queries to the NavigationServer3D.

## Properties

- `excluded_regions: RID[]` = `[]` — The list of region RIDs that will be excluded from the path query.
- `included_regions: RID[]` = `[]` — The list of region RIDs that will be included by the path query.
- `map: RID` = `RID()` — The navigation map RID used in the path query.
- `metadata_flags: NavigationPathQueryParameters3D.PathMetadataFlags` = `7` — Additional information to include with the navigation path.
- `navigation_layers: int` = `1` — The navigation layers the query will use (as a bitmask).
- `path_postprocessing: NavigationPathQueryParameters3D.PathPostProcessing` = `0` — The path postprocessing applied to the raw path corridor found by the `pathfinding_algorithm`.
- `path_return_max_length: float` = `0.0` — The maximum allowed length of the returned path in world units.
- `path_return_max_radius: float` = `0.0` — The maximum allowed radius in world units that the returned path can be from the path start.
- `path_search_max_distance: float` = `0.0` — The maximum distance a searched polygon can be away from the start polygon before the pathfinding cancels the search for a path to the (possibly unreachable or very far away) target position polygon.
- `path_search_max_polygons: int` = `4096` — The maximum number of polygons that are searched before the pathfinding cancels the search for a path to the (possibly unreachable or very far away) target position polygon.
- `pathfinding_algorithm: NavigationPathQueryParameters3D.PathfindingAlgorithm` = `0` — The pathfinding algorithm used in the path query.
- `simplify_epsilon: float` = `0.0` — The path simplification amount in world units.
- `simplify_path: bool` = `false` — If `true` a simplified version of the path will be returned with less critical path points removed.
- `start_position: Vector3` = `Vector3(0, 0, 0)` — The pathfinding start position in global coordinates.
- `target_position: Vector3` = `Vector3(0, 0, 0)` — The pathfinding target position in global coordinates.

## Enum PathfindingAlgorithm

- `PATHFINDING_ALGORITHM_ASTAR = 0` — The path query uses the default A* pathfinding algorithm.

## Enum PathPostProcessing

- `PATH_POSTPROCESSING_CORRIDORFUNNEL = 0` — Applies a funnel algorithm to the raw path corridor found by the pathfinding algorithm.
- `PATH_POSTPROCESSING_EDGECENTERED = 1` — Centers every position in the middle of the traveled navigation mesh's polygon edge.
- `PATH_POSTPROCESSING_NONE = 2` — Applies no postprocessing and returns the raw path corridor as found by the pathfinding algorithm.

## Enum PathMetadataFlags

- `PATH_METADATA_INCLUDE_NONE = 0` — Don't include any additional metadata about the returned path.
- `PATH_METADATA_INCLUDE_TYPES = 1` — Include the type of navigation primitive (region or link) that each point of the path goes through.
- `PATH_METADATA_INCLUDE_RIDS = 2` — Include the RIDs of the regions and links that each point of the path goes through.
- `PATH_METADATA_INCLUDE_OWNERS = 4` — Include the `ObjectID`s of the Objects which manage the regions and links each point of the path goes through.
- `PATH_METADATA_INCLUDE_ALL = 7` — Include all available metadata about the returned path.
