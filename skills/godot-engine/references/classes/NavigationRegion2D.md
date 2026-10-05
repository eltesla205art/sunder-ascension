# NavigationRegion2D

**Inherits:** Node2D

A traversable 2D region that NavigationAgent2Ds can use for pathfinding.

A traversable 2D region based on a NavigationPolygon that NavigationAgent2Ds can use for pathfinding. Two regions can be connected to each other if they share a similar edge. You can set the minimum distance between two vertices required to connect two edges by using `NavigationServer2D.map_set_edge_connection_margin`. Note: Overlapping two regions' navigation polygons is not enough for connecting two regions.

## Properties

- `enabled: bool` = `true` — Determines if the NavigationRegion2D is enabled or disabled.
- `enter_cost: float` = `0.0` — When pathfinding enters this region's navigation mesh from another region's navigation mesh, this property's value is added to the path distance used to determine the shortest path.
- `navigation_layers: int` = `1` — A bitfield determining all navigation layers the region belongs to.
- `navigation_polygon: NavigationPolygon` — The NavigationPolygon resource to use.
- `travel_cost: float` = `1.0` — When pathfinding moves inside this region's navigation mesh the traveled distances are multiplied with `travel_cost` for determining the shortest path.
- `use_edge_connections: bool` = `true` — If enabled the navigation region will use edge connections to connect with other navigation regions within proximity of the navigation map edge connection margin.

## Methods

- `bake_navigation_polygon(on_thread: bool = true) -> void` — Bakes the NavigationPolygon.
- `get_bounds() -> Rect2` *const* — Returns the axis-aligned rectangle for the region's transformed navigation mesh.
- `get_navigation_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `navigation_layers` bitmask is enabled, given a `layer_number` between 1 and 32.
- `get_navigation_map() -> RID` *const* — Returns the current navigation map RID used by this region.
- `get_region_rid() -> RID` *const* *(deprecated)* — Returns the RID of this region on the NavigationServer2D.
- `get_rid() -> RID` *const* — Returns the RID of this region on the NavigationServer2D.
- `is_baking() -> bool` *const* — Returns `true` when the NavigationPolygon is being baked on a background thread.
- `set_navigation_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `navigation_layers` bitmask, given a `layer_number` between 1 and 32.
- `set_navigation_map(navigation_map: RID) -> void` — Sets the RID of the navigation map this region should use.

## Signals

- `bake_finished()` — Emitted when a navigation polygon bake operation is completed.
- `navigation_polygon_changed()` — Emitted when the used navigation polygon is replaced or changes to the internals of the current navigation polygon are committed.
