# EditorScenePostImportPlugin

**Inherits:** RefCounted

Plugin to control and modifying the process of importing a scene.

This plugin type exists to modify the process of importing scenes, allowing to change the content as well as add importer options at every stage of the process.

## Methods

- `_get_import_options(path: String) -> void` *virtual* — Override to add general import options.
- `_get_internal_import_options(category: int) -> void` *virtual* — Override to add internal import options.
- `_get_internal_option_update_view_required(category: int, option: String) -> Variant` *virtual const* — Should return `true` if the 3D view of the import dialog needs to update when changing the given option.
- `_get_internal_option_visibility(category: int, for_animation: bool, option: String) -> Variant` *virtual const* — Should return `true` to show the given option, `false` to hide the given option, or `null` to ignore.
- `_get_option_visibility(path: String, for_animation: bool, option: String) -> Variant` *virtual const* — Should return `true` to show the given option, `false` to hide the given option, or `null` to ignore.
- `_internal_process(category: int, base_node: Node, node: Node, resource: Resource) -> void` *virtual* — Process a specific node or resource for a given category.
- `_post_process(scene: Node) -> void` *virtual* — Post-process the scene.
- `_pre_process(scene: Node) -> void` *virtual* — Pre-process the scene.
- `add_import_option(name: String, value: Variant) -> void` — Add a specific import option (name and default value only).
- `add_import_option_advanced(type: Variant.Type, name: String, default_value: Variant, hint: PropertyHint = 0, hint_string: String = "", usage_flags: int = 6) -> void` — Add a specific import option.
- `get_option_value(name: StringName) -> Variant` *const* — Query the value of an option.

## Enum InternalImportCategory

- `INTERNAL_IMPORT_CATEGORY_NODE = 0` — 
- `INTERNAL_IMPORT_CATEGORY_MESH_3D_NODE = 1` — 
- `INTERNAL_IMPORT_CATEGORY_MESH = 2` — 
- `INTERNAL_IMPORT_CATEGORY_MATERIAL = 3` — 
- `INTERNAL_IMPORT_CATEGORY_ANIMATION = 4` — 
- `INTERNAL_IMPORT_CATEGORY_ANIMATION_NODE = 5` — 
- `INTERNAL_IMPORT_CATEGORY_SKELETON_3D_NODE = 6` — 
- `INTERNAL_IMPORT_CATEGORY_MAX = 7` —
