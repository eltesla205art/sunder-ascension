# NavigationLink3D

**Inherits:** Node3D

A link between two positions on NavigationRegion3Ds that agents can be routed through.

A link between two positions on NavigationRegion3Ds that agents can be routed through. These positions can be on the same NavigationRegion3D or on two different ones. Links are useful to express navigation methods other than traveling along the surface of the navigation mesh, such as ziplines, teleporters, or gaps that can be jumped across.

## Properties

- `bidirectional: bool` = `true` — Whether this link can be traveled in both directions or only from `start_position` to `end_position`.
- `enabled: bool` = `true` — Whether this link is currently active.
- `end_position: Vector3` = `Vector3(0, 0, 0)` — Ending position of the link.
- `enter_cost: float` = `0.0` — When pathfinding enters this link from another region's navigation mesh the `enter_cost` value is added to the path distance for determining the shortest path.
- `navigation_layers: int` = `1` — A bitfield determining all navigation layers the link belongs to.
- `start_position: Vector3` = `Vector3(0, 0, 0)` — Starting position of the link.
- `travel_cost: float` = `1.0` — When pathfinding moves along the link the traveled distance is multiplied with `travel_cost` for determining the shortest path.

## Methods

- `get_global_end_position() -> Vector3` *const* — Returns the `end_position` that is relative to the link as a global position.
- `get_global_start_position() -> Vector3` *const* — Returns the `start_position` that is relative to the link as a global position.
- `get_navigation_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `navigation_layers` bitmask is enabled, given a `layer_number` between 1 and 32.
- `get_navigation_map() -> RID` *const* — Returns the current navigation map RID used by this link.
- `get_rid() -> RID` *const* — Returns the RID of this link on the NavigationServer3D.
- `set_global_end_position(position: Vector3) -> void` — Sets the `end_position` that is relative to the link from a global `position`.
- `set_global_start_position(position: Vector3) -> void` — Sets the `start_position` that is relative to the link from a global `position`.
- `set_navigation_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `navigation_layers` bitmask, given a `layer_number` between 1 and 32.
- `set_navigation_map(navigation_map: RID) -> void` — Sets the RID of the navigation map this link should use.
