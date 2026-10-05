# GLTFDocument

**Inherits:** Resource

Class for importing and exporting glTF files in and out of Godot.

GLTFDocument supports reading data from a glTF file, buffer, or Godot scene. This data can then be written to the filesystem, buffer, or used to create a Godot scene. All of the data in a glTF scene is stored in the GLTFState class. GLTFDocument processes state objects, but does not contain any scene data itself.

## Properties

- `fallback_image_format: String` = `"None"` — The user-friendly name of the fallback image format.
- `fallback_image_quality: float` = `0.25` — The quality of the fallback image, if any.
- `image_format: String` = `"PNG"` — The user-friendly name of the export image format.
- `lossy_quality: float` = `0.75` — If `image_format` is a lossy image format, this determines the lossy quality of the image.
- `root_node_mode: GLTFDocument.RootNodeMode` = `0` — How to process the root node during export.
- `texture_map_mode: GLTFDocument.TextureMapMode` = `1` — How to handle texture maps during import.
- `visibility_mode: GLTFDocument.VisibilityMode` = `0` — How to deal with node visibility during export.

## Methods

- `append_from_buffer(bytes: PackedByteArray, base_path: String, state: GLTFState, flags: int = 0) -> int[Error]` — Takes a PackedByteArray defining a glTF and imports the data to the given GLTFState object through the `state` parameter.
- `append_from_file(path: String, state: GLTFState, flags: int = 0, base_path: String = "") -> int[Error]` — Takes a path to a glTF file and imports the data at that file path to the given GLTFState object through the `state` parameter.
- `append_from_scene(node: Node, state: GLTFState, flags: int = 0) -> int[Error]` — Takes a Godot Engine scene node and exports it and its descendants to the given GLTFState object through the `state` parameter.
- `export_object_model_property(state: GLTFState, node_path: NodePath, godot_node: Node, gltf_node_index: int) -> GLTFObjectModelProperty` *static* — Determines a mapping between the given Godot `node_path` and the corresponding glTF Object Model JSON pointer(s) in the generated glTF file.
- `generate_buffer(state: GLTFState) -> PackedByteArray` — Takes a GLTFState object through the `state` parameter and returns a glTF PackedByteArray.
- `generate_scene(state: GLTFState, bake_fps: float = 30, trimming: bool = false, remove_immutable_tracks: bool = true) -> Node` — Takes a GLTFState object through the `state` parameter and returns a Godot Engine scene node.
- `get_supported_gltf_extensions() -> PackedStringArray` *static* — Returns a list of all support glTF extensions, including extensions supported directly by the engine, and extensions supported by user plugins registering GLTFDocumentExtension classes.
- `import_object_model_property(state: GLTFState, json_pointer: String) -> GLTFObjectModelProperty` *static* — Determines a mapping between the given glTF Object Model `json_pointer` and the corresponding Godot node path(s) in the generated Godot scene.
- `register_gltf_document_extension(extension: GLTFDocumentExtension, first_priority: bool = false) -> void` *static* — Registers the given GLTFDocumentExtension instance with GLTFDocument.
- `unregister_gltf_document_extension(extension: GLTFDocumentExtension) -> void` *static* — Unregisters the given GLTFDocumentExtension instance.
- `write_to_filesystem(state: GLTFState, path: String) -> int[Error]` — Takes a GLTFState object through the `state` parameter and writes a glTF file to the filesystem.

## Enum RootNodeMode

- `ROOT_NODE_MODE_SINGLE_ROOT = 0` — Treat the Godot scene's root node as the root node of the glTF file, and mark it as the single root node via the `GODOT_single_root` glTF extension.
- `ROOT_NODE_MODE_KEEP_ROOT = 1` — Treat the Godot scene's root node as the root node of the glTF file, but do not mark it as anything special.
- `ROOT_NODE_MODE_MULTI_ROOT = 2` — Treat the Godot scene's root node as the name of the glTF scene, and add all of its children as root nodes of the glTF file.

## Enum TextureMapMode

- `TEXTURE_MAP_MODE_DO_NOT_REMAP = 0` — Import the texture maps in the glTF file as they are, without trying to fit them into specific texture slots suitable for Godot's built-in materials.
- `TEXTURE_MAP_MODE_REMAP_TO_STANDARD_MATERIAL = 1` — Import the texture maps in the glTF file remapped to the most suitable texture slots based on Godot's StandardMaterial3D class.

## Enum VisibilityMode

- `VISIBILITY_MODE_INCLUDE_REQUIRED = 0` — If the scene contains any non-visible nodes, include them, mark them as non-visible with `KHR_node_visibility`, and require that importers respect their non-visibility.
- `VISIBILITY_MODE_INCLUDE_OPTIONAL = 1` — If the scene contains any non-visible nodes, include them, mark them as non-visible with `KHR_node_visibility`, and do not impose any requirements on importers.
- `VISIBILITY_MODE_EXCLUDE = 2` — If the scene contains any non-visible nodes, do not include them in the export.

## Enum ImportFlags

- `IMPORT_FLAG_GENERATE_TANGENT_ARRAYS = 8` — If `true`, generate vertex tangents using Mikktspace if the input meshes don't have tangent data.
- `IMPORT_FLAG_USE_NAMED_SKIN_BINDS = 16` — If checked, use named Skins for animation.
- `IMPORT_FLAG_DISCARD_MESHES_AND_MATERIALS = 32` — Ignore meshes and materials on import.
- `IMPORT_FLAG_FORCE_DISABLE_MESH_COMPRESSION = 64` — If `true`, mesh compression will not be used.
