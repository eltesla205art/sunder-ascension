# NavigationObstacle3D

**Inherits:** Node3D

3D obstacle used to affect navigation mesh baking or constrain velocities of avoidance controlled agents.

An obstacle needs a navigation map and outline `vertices` defined to work correctly. The outlines can not cross or overlap and are restricted to a plane projection. This means the y-axis of the vertices is ignored, instead the obstacle's global y-axis position is used for placement. The projected shape is extruded by the obstacles height along the y-axis.

## Properties

- `affect_navigation_mesh: bool` = `false` — If enabled and parsed in a navigation mesh baking process the obstacle will discard source geometry inside its `vertices` and `height` defined shape.
- `avoidance_enabled: bool` = `true` — If `true` the obstacle affects avoidance using agents.
- `avoidance_layers: int` = `1` — A bitfield determining the avoidance layers for this obstacle.
- `carve_navigation_mesh: bool` = `false` — If enabled the obstacle vertices will carve into the baked navigation mesh with the shape unaffected by additional offsets (e.g. agent radius).
- `height: float` = `1.0` — Sets the obstacle height used in 2D avoidance. 2D avoidance using agents ignore obstacles that are below or above them.
- `radius: float` = `0.0` — Sets the avoidance radius for the obstacle.
- `use_3d_avoidance: bool` = `false` — If `true` the obstacle affects 3D avoidance using agents with obstacle `radius`.
- `velocity: Vector3` = `Vector3(0, 0, 0)` — The wanted velocity for the obstacle, used by other agents to better predict the obstacle if it is moved with a velocity regularly (every frame), instead of warped to a new position.
- `vertices: PackedVector3Array` = `PackedVector3Array()` — The outline vertices of the obstacle.

## Methods

- `get_avoidance_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `avoidance_layers` bitmask is enabled, given a `layer_number` between 1 and 32.
- `get_navigation_map() -> RID` *const* — Returns the RID of the navigation map for this NavigationObstacle node.
- `get_rid() -> RID` *const* — Returns the RID of this obstacle on the NavigationServer3D.
- `set_avoidance_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `avoidance_layers` bitmask, given a `layer_number` between 1 and 32.
- `set_navigation_map(navigation_map: RID) -> void` — Sets the RID of the navigation map this NavigationObstacle node should use and also updates the `obstacle` on the NavigationServer.
