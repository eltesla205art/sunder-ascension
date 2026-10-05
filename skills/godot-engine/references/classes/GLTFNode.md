# GLTFNode

**Inherits:** Resource

glTF node class.

Represents a glTF node. glTF nodes may have names, transforms, children (other glTF nodes), and more specialized properties (represented by their own classes). glTF nodes generally exist inside of GLTFState which represents all data of a glTF file. Most of GLTFNode's properties are indices of other data in the glTF file. You can extend a glTF node with additional properties by using `get_additional_data` and `set_additional_data`.

## Properties

- `camera: int` = `-1` — If this glTF node is a camera, the index of the GLTFCamera in the GLTFState that describes the camera's properties.
- `children: PackedInt32Array` = `PackedInt32Array()` — The indices of the child nodes in the GLTFState.
- `height: int` = `-1` — How deep into the node hierarchy this node is.
- `light: int` = `-1` — If this glTF node is a light, the index of the GLTFLight in the GLTFState that describes the light's properties.
- `mesh: int` = `-1` — If this glTF node is a mesh, the index of the GLTFMesh in the GLTFState that describes the mesh's properties.
- `original_name: String` = `""` — The original name of the node.
- `parent: int` = `-1` — The index of the parent node in the GLTFState.
- `position: Vector3` = `Vector3(0, 0, 0)` — The position of the glTF node relative to its parent.
- `rotation: Quaternion` = `Quaternion(0, 0, 0, 1)` — The rotation of the glTF node relative to its parent.
- `scale: Vector3` = `Vector3(1, 1, 1)` — The scale of the glTF node relative to its parent.
- `skeleton: int` = `-1` — If this glTF node has a skeleton, the index of the GLTFSkeleton in the GLTFState that describes the skeleton's properties.
- `skin: int` = `-1` — If this glTF node has a skin, the index of the GLTFSkin in the GLTFState that describes the skin's properties.
- `visible: bool` = `true` — If `true`, the GLTF node is visible.
- `xform: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — The transform of the glTF node relative to its parent.

## Methods

- `append_child_index(child_index: int) -> void` — Appends the given child node index to the `children` array.
- `get_additional_data(extension_name: StringName) -> Variant` — Gets additional arbitrary data in this GLTFNode instance.
- `get_scene_node_path(gltf_state: GLTFState, handle_skeletons: bool = true) -> NodePath` — Returns the NodePath that this GLTF node will have in the Godot scene tree after being imported.
- `set_additional_data(extension_name: StringName, additional_data: Variant) -> void` — Sets additional arbitrary data in this GLTFNode instance.
