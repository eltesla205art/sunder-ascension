# GLTFMesh

**Inherits:** Resource

GLTFMesh represents a glTF mesh.

GLTFMesh handles 3D mesh data imported from glTF files. It includes properties for blend channels, blend weights, instance materials, and the mesh itself.

## Properties

- `blend_weights: PackedFloat32Array` = `PackedFloat32Array()` — An array of floats representing the blend weights of the mesh.
- `instance_materials: Material[]` = `[]` — An array of Material objects representing the materials used in the mesh.
- `mesh: ImporterMesh` — The ImporterMesh object representing the mesh itself.
- `original_name: String` = `""` — The original name of the mesh.

## Methods

- `get_additional_data(extension_name: StringName) -> Variant` — Gets additional arbitrary data in this GLTFMesh instance.
- `set_additional_data(extension_name: StringName, additional_data: Variant) -> void` — Sets additional arbitrary data in this GLTFMesh instance.
