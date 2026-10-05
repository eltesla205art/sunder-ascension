# ResourceImporterScene

**Inherits:** ResourceImporter

Imports a glTF, FBX, COLLADA, or Blender 3D scene.

See also ResourceImporterOBJ, which is used for OBJ models that can be imported as an independent Mesh or a scene. Additional options (such as extracting individual meshes or materials to files) are available in the Advanced Import Settings dialog. This dialog can be accessed by double-clicking a 3D scene in the FileSystem dock or by selecting a 3D scene in the FileSystem dock, going to the Import dock and choosing Advanced. Note: ResourceImporterScene is not used for PackedScenes, such as `.tscn` and `.scn` files.

## Properties

- `_subresources: Dictionary` = `{}` — Contains properties for the scene's subresources.
- `animation/fps: float` = `30` — The number of frames per second to use for baking animation curves to a series of points with linear interpolation.
- `animation/import: bool` = `true` — If `true`, import animations from the 3D scene.
- `animation/import_rest_as_RESET: bool` = `false` — If `true`, adds an Animation named `RESET`, containing the `Skeleton3D.get_bone_rest` from Skeleton3D nodes.
- `animation/remove_immutable_tracks: bool` = `true` — If `true`, remove animation tracks that only contain default values.
- `animation/trimming: bool` = `false` — If `true`, trim the beginning and end of animations if there are no keyframe changes.
- `array_mesh/deduplicate_surfaces: bool` = `true` — If the 3D model file contains only one mesh, this option has no effect.
- `import_script/path: String` = `""` — Path to an import script, which can run code after the import process has completed for custom processing.
- `materials/extract: int` = `0` — Material extraction mode. - `0 (Keep Internal)`, materials are not extracted. - `1 (Extract Once)`, materials are extracted once and reused on subsequent import. - `2 (Extract and Overwrite)`, materials are extracted and overwritten on every import.
- `materials/extract_format: int` = `0` — Extracted material file format. - `0 (Text)`, text file format (`*.tres`). - `1 (Binary)`, binary file format (`*.res`). - `2 (Material)`, binary file format (`*.material`).
- `materials/extract_path: String` = `""` — Path extracted materials are saved to.
- `mesh_library/create_categories_from_hierarchy: bool` = `false` — If `true`, categories will be automatically set according to the node hierarchy, using the names of the parent nodes.
- `mesh_library/use_node_names_as_mesh_names: bool` = `false` — If `true`, the mesh names will be set to the names of the nodes in the 3D model file.
- `meshes/create_shadow_meshes: bool` = `true` — If `true`, enables the generation of shadow meshes on import.
- `meshes/ensure_tangents: bool` = `true` — If `true`, generate vertex tangents using Mikktspace if the input meshes don't have tangent data.
- `meshes/force_disable_compression: bool` = `false` — If `true`, mesh compression will not be used.
- `meshes/generate_lods: bool` = `true` — If `true`, generates lower detail variants of the mesh which will be displayed in the distance to improve rendering performance.
- `meshes/light_baking: int` = `1` — Configures the meshes' `GeometryInstance3D.gi_mode` in the 3D scene.
- `meshes/lightmap_texel_size: float` = `0.2` — Controls the size of each texel on the baked lightmap.
- `nodes/apply_root_scale: bool` = `true` — If `true`, `nodes/root_scale` will be applied to the descendant nodes, meshes, animations, bones, etc.
- `nodes/import_as_skeleton_bones: bool` = `false` — Treat all nodes in the imported scene as if they are bones within a single Skeleton3D.
- `nodes/root_name: String` = `""` — Override for the root node name.
- `nodes/root_scale: float` = `1.0` — The uniform scale to use for the scene root.
- `nodes/root_script: Script` = `null` — If set to a valid script, attaches the script to the root node of the imported scene.
- `nodes/root_type: String` = `""` — Override for the root node type.
- `nodes/use_name_suffixes: bool` = `true` — If `true`, will use suffixes in the names of imported objects such as nodes and resources to determine types and properties, such as `-noimp` to skip import of a node or animation, `-alpha` to enable alpha transparency on a material, and `-vcol` to enable vertex colors on a material.
- `nodes/use_node_type_suffixes: bool` = `true` — If `true`, will use suffixes in the node names to determine the node type, such as `-col` for collision shapes.
- `skins/use_named_skins: bool` = `true` — If checked, use named Skins for animation.
