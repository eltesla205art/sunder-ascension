# GLTFLight

**Inherits:** Resource

Represents a glTF light.

Represents a light as defined by the `KHR_lights_punctual` glTF extension.

## Properties

- `color: Color` = `Color(1, 1, 1, 1)` — The Color of the light in linear space.
- `inner_cone_angle: float` = `0.0` — The inner angle of the cone in a spotlight.
- `intensity: float` = `1.0` — The intensity of the light.
- `light_type: String` = `""` — The type of the light.
- `outer_cone_angle: float` = `0.7853982` — The outer angle of the cone in a spotlight.
- `range: float` = `inf` — The range of the light, beyond which the light has no effect. glTF lights with no range defined behave like physical lights (which have infinite range).

## Methods

- `from_dictionary(dictionary: Dictionary) -> GLTFLight` *static* — Creates a new GLTFLight instance by parsing the given Dictionary.
- `from_node(light_node: Light3D) -> GLTFLight` *static* — Create a new GLTFLight instance from the given Godot Light3D node.
- `get_additional_data(extension_name: StringName) -> Variant`
- `set_additional_data(extension_name: StringName, additional_data: Variant) -> void`
- `to_dictionary() -> Dictionary` *const* — Serializes this GLTFLight instance into a Dictionary.
- `to_node() -> Light3D` *const* — Converts this GLTFLight instance into a Godot Light3D node.
