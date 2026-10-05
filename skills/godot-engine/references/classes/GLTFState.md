# GLTFState

**Inherits:** Resource

Represents all data of a glTF file.

Contains all nodes and resources of a glTF file. This is used by GLTFDocument as data storage, which allows GLTFDocument and all GLTFDocumentExtension classes to remain stateless. GLTFState can be populated by GLTFDocument reading a file or by converting a Godot scene. Then the data can either be used to create a Godot scene or save to a glTF file.

## Properties

- `bake_fps: float` = `30.0` — The baking fps of the animation for either import or export.
- `base_path: String` = `""` — The folder path associated with this glTF data.
- `buffers: PackedByteArray[]` = `[]` — 
- `copyright: String` = `""` — The copyright string in the asset header of the glTF file.
- `create_animations: bool` = `true` — 
- `filename: String` = `""` — The file name associated with this glTF data.
- `glb_data: PackedByteArray` = `PackedByteArray()` — The binary buffer attached to a .glb file.
- `handle_binary_image_mode: GLTFState.HandleBinaryImageMode` = `1` — When importing a glTF file with unimported raw binary images embedded inside of binary blob buffers, in data URIs, or separate files not imported by Godot, this controls how the images are handled.
- `import_as_skeleton_bones: bool` = `false` — If `true`, forces all GLTFNodes in the document to be bones of a single Skeleton3D Godot node.
- `json: Dictionary` = `{}` — The original raw JSON document corresponding to this GLTFState.
- `major_version: int` = `0` — 
- `minor_version: int` = `0` — 
- `root_nodes: PackedInt32Array` = `PackedInt32Array()` — The root nodes of the glTF file.
- `scene_name: String` = `""` — The name of the scene.
- `use_named_skin_binds: bool` = `false` — 

## Methods

- `add_used_extension(extension_name: String, required: bool) -> void` — Appends an extension to the list of extensions used by this glTF file during serialization.
- `append_data_to_buffers(data: PackedByteArray, deduplication: bool) -> int` — Appends the given byte array `data` to the buffers and creates a GLTFBufferView for it.
- `append_gltf_node(gltf_node: GLTFNode, godot_scene_node: Node, parent_node_index: int) -> int` — Appends the given GLTFNode to the state, and returns its new index.
- `get_accessors() -> GLTFAccessor[]` *const*
- `get_additional_data(extension_name: StringName) -> Variant` *const* — Gets additional arbitrary data in this GLTFState instance.
- `get_animation_player(anim_player_index: int) -> AnimationPlayer` *const* — Returns the AnimationPlayer node with the given index.
- `get_animation_players_count(anim_player_index: int) -> int` *const* — Returns the number of AnimationPlayer nodes in this GLTFState.
- `get_animations() -> GLTFAnimation[]` *const* — Returns an array of all GLTFAnimations in the glTF file.
- `get_buffer_views() -> GLTFBufferView[]` *const*
- `get_cameras() -> GLTFCamera[]` *const* — Returns an array of all GLTFCameras in the glTF file.
- `get_handle_binary_image() -> int` *const* *(deprecated)* — Deprecated untyped alias for `handle_binary_image_mode`.
- `get_images() -> Texture2D[]` *const* — Gets the images of the glTF file as an array of Texture2Ds.
- `get_lights() -> GLTFLight[]` *const* — Returns an array of all GLTFLights in the glTF file.
- `get_materials() -> Material[]` *const*
- `get_meshes() -> GLTFMesh[]` *const* — Returns an array of all GLTFMeshes in the glTF file.
- `get_node_index(scene_node: Node) -> int` *const* — Returns the index of the GLTFNode corresponding to this Godot scene node.
- `get_nodes() -> GLTFNode[]` *const* — Returns an array of all GLTFNodes in the glTF file.
- `get_scene_node(gltf_node_index: int) -> Node` *const* — Returns the Godot scene node that corresponds to the same index as the GLTFNode it was generated from.
- `get_skeletons() -> GLTFSkeleton[]` *const* — Returns an array of all GLTFSkeletons in the glTF file.
- `get_skins() -> GLTFSkin[]` *const* — Returns an array of all GLTFSkins in the glTF file.
- `get_texture_samplers() -> GLTFTextureSampler[]` *const* — Retrieves the array of texture samplers that are used by the textures contained in the glTF.
- `get_textures() -> GLTFTexture[]` *const*
- `get_unique_animation_names() -> String[]` *const* — Returns an array of unique animation names.
- `get_unique_names() -> String[]` *const* — Returns an array of unique node names.
- `set_accessors(accessors: GLTFAccessor[]) -> void`
- `set_additional_data(extension_name: StringName, additional_data: Variant) -> void` — Sets additional arbitrary data in this GLTFState instance.
- `set_animations(animations: GLTFAnimation[]) -> void` — Sets the GLTFAnimations in the state.
- `set_buffer_views(buffer_views: GLTFBufferView[]) -> void`
- `set_cameras(cameras: GLTFCamera[]) -> void` — Sets the GLTFCameras in the state.
- `set_handle_binary_image(method: int) -> void` *(deprecated)* — Deprecated untyped alias for `handle_binary_image_mode`.
- `set_images(images: Texture2D[]) -> void` — Sets the images in the state stored as an array of Texture2Ds.
- `set_lights(lights: GLTFLight[]) -> void` — Sets the GLTFLights in the state.
- `set_materials(materials: Material[]) -> void`
- `set_meshes(meshes: GLTFMesh[]) -> void` — Sets the GLTFMeshes in the state.
- `set_nodes(nodes: GLTFNode[]) -> void` — Sets the GLTFNodes in the state.
- `set_skeletons(skeletons: GLTFSkeleton[]) -> void` — Sets the GLTFSkeletons in the state.
- `set_skins(skins: GLTFSkin[]) -> void` — Sets the GLTFSkins in the state.
- `set_texture_samplers(texture_samplers: GLTFTextureSampler[]) -> void` — Sets the array of texture samplers that are used by the textures contained in the glTF.
- `set_textures(textures: GLTFTexture[]) -> void`
- `set_unique_animation_names(unique_animation_names: String[]) -> void` — Sets the unique animation names in the state.
- `set_unique_names(unique_names: String[]) -> void` — Sets the unique node names in the state.

## Enum HandleBinaryImageMode

- `HANDLE_BINARY_IMAGE_MODE_DISCARD_TEXTURES = 0` — When importing a glTF file with embedded binary images, discards all images and uses untextured materials in their place.
- `HANDLE_BINARY_IMAGE_MODE_EXTRACT_TEXTURES = 1` — When importing a glTF file with embedded binary images, extracts them and saves them to their own files.
- `HANDLE_BINARY_IMAGE_MODE_EMBED_AS_BASISU = 2` — When importing a glTF file with embedded binary images, embeds textures VRAM compressed with Basis Universal into the generated scene.
- `HANDLE_BINARY_IMAGE_MODE_EMBED_AS_UNCOMPRESSED = 3` — When importing a glTF file with embedded binary images, embeds textures compressed losslessly into the generated scene.

## Constants

- `HANDLE_BINARY_DISCARD_TEXTURES = 0` — Discards all embedded textures and uses untextured materials.
- `HANDLE_BINARY_EXTRACT_TEXTURES = 1` — Extracts embedded textures to be reimported and compressed.
- `HANDLE_BINARY_EMBED_AS_BASISU = 2` — Embeds textures VRAM compressed with Basis Universal into the generated scene.
- `HANDLE_BINARY_EMBED_AS_UNCOMPRESSED = 3` — Embeds textures compressed losslessly into the generated scene, matching old behavior.
