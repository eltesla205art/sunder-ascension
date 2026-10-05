# GLTFCamera

**Inherits:** Resource

Represents a glTF camera.

Represents a camera as defined by the base glTF spec.

## Properties

- `depth_far: float` = `4000.0` — The distance to the far culling boundary for this camera relative to its local Z axis, in meters.
- `depth_near: float` = `0.05` — The distance to the near culling boundary for this camera relative to its local Z axis, in meters.
- `fov: float` = `1.3089969` — The FOV of the camera.
- `perspective: bool` = `true` — If `true`, the camera is in perspective mode.
- `size_mag: float` = `0.5` — The size of the camera.

## Methods

- `from_dictionary(dictionary: Dictionary) -> GLTFCamera` *static* — Creates a new GLTFCamera instance by parsing the given Dictionary.
- `from_node(camera_node: Camera3D) -> GLTFCamera` *static* — Create a new GLTFCamera instance from the given Godot Camera3D node.
- `to_dictionary() -> Dictionary` *const* — Serializes this GLTFCamera instance into a Dictionary.
- `to_node() -> Camera3D` *const* — Converts this GLTFCamera instance into a Godot Camera3D node.
