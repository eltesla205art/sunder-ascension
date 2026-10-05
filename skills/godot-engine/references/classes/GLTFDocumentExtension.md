# GLTFDocumentExtension

**Inherits:** Resource

GLTFDocument extension class.

Extends the functionality of the GLTFDocument class by allowing you to run arbitrary code at various stages of glTF import or export. To use, make a new class extending GLTFDocumentExtension, override any methods you need, make an instance of your class, and register it using `GLTFDocument.register_gltf_document_extension`. Note: All GLTFDocumentExtension classes are duplicated when beginning the import or export process. Except for configuration values, these classes must be stateless in order to function properly.

## Methods

- `_convert_scene_node(state: GLTFState, gltf_node: GLTFNode, scene_node: Node) -> void` *virtual* — Part of the export process.
- `_export_get_property_list(root_node: Node) -> Dictionary[]` *virtual* — Runs prior to the export process.
- `_export_node(state: GLTFState, gltf_node: GLTFNode, json: Dictionary, node: Node) -> int[Error]` *virtual* — Part of the export process.
- `_export_object_model_property(state: GLTFState, node_path: NodePath, godot_node: Node, gltf_node_index: int, target_object: Object, target_depth: int) -> GLTFObjectModelProperty` *virtual* — Part of the export process.
- `_export_post(state: GLTFState) -> int[Error]` *virtual* — Part of the export process.
- `_export_post_convert(state: GLTFState, root: Node) -> int[Error]` *virtual* — Part of the export process.
- `_export_preflight(state: GLTFState, root: Node) -> int[Error]` *virtual* — Part of the export process.
- `_export_preserialize(state: GLTFState) -> int[Error]` *virtual* — Part of the export process.
- `_generate_scene_node(state: GLTFState, gltf_node: GLTFNode, scene_parent: Node) -> Node3D` *virtual* — Part of the import process.
- `_get_image_file_extension() -> String` *virtual* — Returns the file extension to use for saving image data into, for example, `".png"`.
- `_get_saveable_image_formats() -> PackedStringArray` *virtual* — Part of the export process.
- `_get_supported_extensions() -> PackedStringArray` *virtual* — Part of the import process.
- `_import_node(state: GLTFState, gltf_node: GLTFNode, json: Dictionary, node: Node) -> int[Error]` *virtual* — Part of the import process.
- `_import_object_model_property(state: GLTFState, split_json_pointer: PackedStringArray, partial_paths: NodePath[]) -> GLTFObjectModelProperty` *virtual* — Part of the import process.
- `_import_post(state: GLTFState, root: Node) -> int[Error]` *virtual* — Part of the import process.
- `_import_post_parse(state: GLTFState) -> int[Error]` *virtual* — Part of the import process.
- `_import_pre_generate(state: GLTFState) -> int[Error]` *virtual* — Part of the import process.
- `_import_preflight(state: GLTFState, extensions: PackedStringArray) -> int[Error]` *virtual* — Part of the import process.
- `_parse_image_data(state: GLTFState, image_data: PackedByteArray, mime_type: String, ret_image: Image) -> int[Error]` *virtual* — Part of the import process.
- `_parse_node_extensions(state: GLTFState, gltf_node: GLTFNode, extensions: Dictionary) -> int[Error]` *virtual* — Part of the import process.
- `_parse_texture_json(state: GLTFState, texture_json: Dictionary, ret_gltf_texture: GLTFTexture) -> int[Error]` *virtual* — Part of the import process.
- `_save_image_at_path(state: GLTFState, image: Image, file_path: String, image_format: String, lossy_quality: float) -> int[Error]` *virtual* — Part of the export process.
- `_serialize_image_to_bytes(state: GLTFState, image: Image, image_dict: Dictionary, image_format: String, lossy_quality: float) -> PackedByteArray` *virtual* — Part of the export process.
- `_serialize_texture_json(state: GLTFState, texture_json: Dictionary, gltf_texture: GLTFTexture, image_format: String) -> int[Error]` *virtual* — Part of the export process.
