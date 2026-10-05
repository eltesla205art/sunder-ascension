# GLTFSkeleton

**Inherits:** Resource





## Properties

- `joints: PackedInt32Array` = `PackedInt32Array()` — 
- `roots: PackedInt32Array` = `PackedInt32Array()` — 

## Methods

- `get_bone_attachment(idx: int) -> BoneAttachment3D`
- `get_bone_attachment_count() -> int`
- `get_godot_bone_node() -> Dictionary` — Returns a Dictionary that maps skeleton bone indices to the indices of glTF nodes.
- `get_godot_skeleton() -> Skeleton3D`
- `get_unique_names() -> String[]`
- `set_godot_bone_node(godot_bone_node: Dictionary) -> void` — Sets a Dictionary that maps skeleton bone indices to the indices of glTF nodes.
- `set_unique_names(unique_names: String[]) -> void`
