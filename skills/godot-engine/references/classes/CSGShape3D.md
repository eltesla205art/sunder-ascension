# CSGShape3D

**Inherits:** GeometryInstance3D

The CSG base class.

This is the CSG base class that provides CSG operation support to the various CSG nodes in Godot. Performance: CSG nodes are only intended for prototyping as they have a significant CPU performance cost. Consider baking final CSG operation results into static geometry that replaces the CSG nodes. Individual CSG root node results can be baked to nodes with static resources with the editor menu that appears when a CSG root node is selected.

## Properties

- `autosmooth: bool` = `false` — Enables automatic smoothing.
- `calculate_tangents: bool` = `true` — Calculate tangents for the CSG shape which allows the use of normal and height maps.
- `collision_layer: int` = `1` — The physics layers this area is in.
- `collision_mask: int` = `1` — The physics layers this CSG shape scans for collisions.
- `collision_priority: float` = `1.0` — The priority used to solve colliding when occurring penetration.
- `operation: CSGShape3D.Operation` = `0` — The operation that is performed on this shape.
- `smoothing_angle: float` = `50.0` — When autosmooth is enabled, faces with an angle between them greater than this will be smoothed, while faces with a smaller angle will remain sharp.
- `snap: float` *(deprecated)* — This property does nothing.
- `use_collision: bool` = `false` — Adds a collision shape to the physics engine for our CSG shape.

## Methods

- `bake_collision_shape() -> ConcavePolygonShape3D` — Returns a baked physics ConcavePolygonShape3D of this node's CSG operation result.
- `bake_static_mesh() -> ArrayMesh` — Returns a baked static ArrayMesh of this node's CSG operation result.
- `get_collision_layer_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_layer` is enabled, given a `layer_number` between 1 and 32.
- `get_collision_mask_value(layer_number: int) -> bool` *const* — Returns whether or not the specified layer of the `collision_mask` is enabled, given a `layer_number` between 1 and 32.
- `get_meshes() -> Array` *const* — Returns an Array with two elements, the first is the Transform3D of this node and the second is the root Mesh of this node.
- `is_root_shape() -> bool` *const* — Returns `true` if this is a root shape and is thus the object that is rendered.
- `set_collision_layer_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_layer`, given a `layer_number` between 1 and 32.
- `set_collision_mask_value(layer_number: int, value: bool) -> void` — Based on `value`, enables or disables the specified layer in the `collision_mask`, given a `layer_number` between 1 and 32.

## Enum Operation

- `OPERATION_UNION = 0` — Geometry of both primitives is merged, intersecting geometry is removed.
- `OPERATION_INTERSECTION = 1` — Only intersecting geometry remains, the rest is removed.
- `OPERATION_SUBTRACTION = 2` — The second shape is subtracted from the first, leaving a dent with its shape.
