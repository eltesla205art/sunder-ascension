# GLTFPhysicsBody

**Inherits:** Resource

Represents a glTF physics body.

Represents a physics body as an intermediary between the `OMI_physics_body` glTF data and Godot's nodes, and it's abstracted in a way that allows adding support for different glTF physics extensions in the future.

## Properties

- `angular_velocity: Vector3` = `Vector3(0, 0, 0)` — The angular velocity of the physics body, in radians per second.
- `body_type: String` = `"rigid"` — The type of the body.
- `center_of_mass: Vector3` = `Vector3(0, 0, 0)` — The center of mass of the body, in meters.
- `inertia_diagonal: Vector3` = `Vector3(0, 0, 0)` — The inertia strength of the physics body, in kilogram meter squared (kg⋅m²).
- `inertia_orientation: Quaternion` = `Quaternion(0, 0, 0, 1)` — The inertia orientation of the physics body.
- `inertia_tensor: Basis` = `Basis(0, 0, 0, 0, 0, 0, 0, 0, 0)` *(deprecated)* — The inertia tensor of the physics body, in kilogram meter squared (kg⋅m²).
- `linear_velocity: Vector3` = `Vector3(0, 0, 0)` — The linear velocity of the physics body, in meters per second.
- `mass: float` = `1.0` — The mass of the physics body, in kilograms.

## Methods

- `from_dictionary(dictionary: Dictionary) -> GLTFPhysicsBody` *static* — Creates a new GLTFPhysicsBody instance by parsing the given Dictionary in the `OMI_physics_body` glTF extension format.
- `from_node(body_node: CollisionObject3D) -> GLTFPhysicsBody` *static* — Creates a new GLTFPhysicsBody instance from the given Godot CollisionObject3D node.
- `to_dictionary() -> Dictionary` *const* — Serializes this GLTFPhysicsBody instance into a Dictionary.
- `to_node() -> CollisionObject3D` *const* — Converts this GLTFPhysicsBody instance into a Godot CollisionObject3D node.
