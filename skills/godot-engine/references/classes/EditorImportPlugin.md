# EditorImportPlugin

**Inherits:** ResourceImporter

Registers a custom resource importer in the editor. Use the class to parse any file and import it as a new resource type.

EditorImportPlugins provide a way to extend the editor's resource import functionality. Use them to import resources from custom files or to provide alternatives to the editor's existing importers. EditorImportPlugins work by associating with specific file extensions and a resource type. See `_get_recognized_extensions` and `_get_resource_type`.

## Methods

- `_can_import_threaded() -> bool` *virtual const* — Tells whether this importer can be run in parallel on threads, or, on the contrary, it's only safe for the editor to call it from the main thread, for one file at a time.
- `_get_format_version() -> int` *virtual const* — Gets the format version of this importer.
- `_get_import_options(path: String, preset_index: int) -> Dictionary[]` *virtual required const* — Gets the options and default values for the preset at this index.
- `_get_import_order() -> int` *virtual const* — Gets the order of this importer to be run when importing resources.
- `_get_importer_name() -> String` *virtual required const* — Gets the unique name of the importer.
- `_get_option_visibility(path: String, option_name: StringName, options: Dictionary) -> bool` *virtual const* — Gets whether the import option specified by `option_name` should be visible in the Import dock.
- `_get_preset_count() -> int` *virtual const* — Gets the number of initial presets defined by the plugin.
- `_get_preset_name(preset_index: int) -> String` *virtual required const* — Gets the name of the options preset at this index.
- `_get_priority() -> float` *virtual const* — Gets the priority of this plugin for the recognized extension.
- `_get_recognized_extensions() -> PackedStringArray` *virtual required const* — Gets the list of file extensions to associate with this loader (case-insensitive). e.g.
- `_get_resource_type() -> String` *virtual required const* — Gets the Godot resource type associated with this loader. e.g.
- `_get_save_extension() -> String` *virtual required const* — Gets the extension used to save this resource in the `.godot/imported` directory (see `ProjectSettings.application/config/use_hidden_project_data_directory`).
- `_get_visible_name() -> String` *virtual required const* — Gets the name to display in the import window.
- `_import(source_file: String, save_path: String, options: Dictionary, platform_variants: String[], gen_files: String[]) -> int[Error]` *virtual required const* — Imports `source_file` with the specified import `options`.
- `append_import_external_resource(path: String, custom_options: Dictionary = {}, custom_importer: String = "", generator_parameters: Variant = null) -> int[Error]` — This function can only be called during the `_import` callback and it allows manually importing resources from it.
