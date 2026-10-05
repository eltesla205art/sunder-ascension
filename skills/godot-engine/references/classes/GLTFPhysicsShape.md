# GLTFPhysicsShape

**Inherits:** Resource

Represents a glTF physics shape.

Represents a physics shape as defined by the `OMI_physics_shape` or `OMI_collider` glTF extensions. This class is an intermediary between the glTF data and Godot's nodes, and it's abstracted in a way that allows adding support for different glTF physics extensions in the future.

## Properties

- `height: float` = `2.0` — The height of the shape, in meters.
- `importer_mesh: ImporterMesh` — The ImporterMesh resource of the shape.
- `is_trigger: bool` = `false` — If `true`, indicates that this shape is a trigger.
- `mesh_index: int` = `-1` — The index of the shape's mesh in the glTF file.
- `radius: float` = `0.5` — The radius of the shape, in meters.
- `shape_type: String` = `""` — The type of shape this shape represents.
- `size: Vector3` = `Vector3(1, 1, 1)` — The size of the shape, in meters.

## Methods

- `from_dictionary(dictionary: Dictionary) -> GLTFPhysicsShape` *static* — Creates a new GLTFPhysicsShape instance by parsing the given Dictionary.
- `from_node(shape_node: CollisionShape3D) -> GLTFPhysicsShape` *static* — Creates a new GLTFPhysicsShape instance from the given Godot CollisionShape3D node.
- `from_resource(shape_resource: Shape3D) -> GLTFPhysicsShape` *static* — Creates a new GLTFPhysicsShape instance from the given Godot Shape3D resource.
- `to_dictionary() -> Dictionary` *const* — Serializes this GLTFPhysicsShape instance into a Dictionary in the format defined by `OMI_physics_shape`.
- `to_node(cache_shapes: bool = false) -> CollisionShape3D` — Converts this GLTFPhysicsShape instance into a Godot CollisionShape3D node.
- `to_resource(cache_shapes: bool = false) -> Shape3D` — Converts this GLTFPhysicsShape instance into a Godot Shape3D resource.
