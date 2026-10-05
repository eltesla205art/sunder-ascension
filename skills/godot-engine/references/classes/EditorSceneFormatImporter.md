# EditorSceneFormatImporter

**Inherits:** RefCounted

Imports scenes from third-parties' 3D files.

EditorSceneFormatImporter allows to define an importer script for a third-party 3D format. To use EditorSceneFormatImporter, register it using the `EditorPlugin.add_scene_format_importer_plugin` method first.

## Methods

- `_get_extensions() -> PackedStringArray` *virtual required const* — Return supported file extensions for this scene importer.
- `_get_import_options(path: String) -> void` *virtual* — Override to add general import options.
- `_get_option_visibility(path: String, for_animation: bool, option: String) -> Variant` *virtual const* — Should return `true` to show the given option, `false` to hide the given option, or `null` to ignore.
- `_import_scene(path: String, flags: int, options: Dictionary) -> Object` *virtual required* — Perform the bulk of the scene import logic here, for example using GLTFDocument or FBXDocument.
- `add_import_option(name: String, value: Variant) -> void` — Add a specific import option (name and default value only).
- `add_import_option_advanced(type: Variant.Type, name: String, default_value: Variant, hint: PropertyHint = 0, hint_string: String = "", usage_flags: int = 6) -> void` — Add a specific import option.

## Enum ImportFlags

- `IMPORT_SCENE = 1` — Unused flag (this has no effect when enabled).
- `IMPORT_ANIMATION = 2` — Import animations from the 3D scene.
- `IMPORT_FAIL_ON_MISSING_DEPENDENCIES = 4` — Unused flag (this has no effect when enabled).
- `IMPORT_GENERATE_TANGENT_ARRAYS = 8` — If `true`, generate vertex tangents using Mikktspace if the input meshes don't have tangent data.
- `IMPORT_USE_NAMED_SKIN_BINDS = 16` — If checked, use named Skins for animation.
- `IMPORT_DISCARD_MESHES_AND_MATERIALS = 32` — Ignore meshes and materials on import.
- `IMPORT_FORCE_DISABLE_MESH_COMPRESSION = 64` — If `true`, mesh compression will not be used.
