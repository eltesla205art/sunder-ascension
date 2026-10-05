# GLTFSkin

**Inherits:** Resource





## Properties

- `godot_skin: Skin` — 
- `joints: PackedInt32Array` = `PackedInt32Array()` — 
- `joints_original: PackedInt32Array` = `PackedInt32Array()` — 
- `non_joints: PackedInt32Array` = `PackedInt32Array()` — 
- `roots: PackedInt32Array` = `PackedInt32Array()` — 
- `skeleton: int` = `-1` — 
- `skin_root: int` = `-1` — 

## Methods

- `get_inverse_binds() -> Transform3D[]`
- `get_joint_i_to_bone_i() -> Dictionary`
- `get_joint_i_to_name() -> Dictionary`
- `set_inverse_binds(inverse_binds: Transform3D[]) -> void`
- `set_joint_i_to_bone_i(joint_i_to_bone_i: Dictionary) -> void`
- `set_joint_i_to_name(joint_i_to_name: Dictionary) -> void`
