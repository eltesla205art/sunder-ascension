# EditorExportPreset

**Inherits:** RefCounted

Export preset configuration.

Represents the configuration of an export preset, as created by the editor's export dialog. An EditorExportPreset instance is intended to be used a read-only configuration passed to the EditorExportPlatform methods when exporting the project.

## Methods

- `are_advanced_options_enabled() -> bool` *const* — Returns `true` if the "Advanced" toggle is enabled in the export dialog.
- `get_custom_features() -> String` *const* — Returns a comma-separated list of custom features added to this preset, as a string.
- `get_customized_files() -> Dictionary` *const* — Returns a dictionary of files selected in the "Resources" tab of the export dialog.
- `get_customized_files_count() -> int` *const* — Returns the number of files selected in the "Resources" tab of the export dialog.
- `get_encrypt_directory() -> bool` *const* — Returns `true` if PCK directory encryption is enabled in the export dialog.
- `get_encrypt_pck() -> bool` *const* — Returns `true` if PCK encryption is enabled in the export dialog.
- `get_encryption_ex_filter() -> String` *const* — Returns file filters to exclude during PCK encryption.
- `get_encryption_in_filter() -> String` *const* — Returns file filters to include during PCK encryption.
- `get_encryption_key() -> String` *const* — Returns PCK encryption key.
- `get_exclude_filter() -> String` *const* — Returns file filters to exclude during export.
- `get_export_filter() -> int[EditorExportPreset.ExportFilter]` *const* — Returns export file filter mode selected in the "Resources" tab of the export dialog.
- `get_export_path() -> String` *const* — Returns export target path.
- `get_file_export_mode(path: String, default: EditorExportPreset.FileExportMode = 0) -> int[EditorExportPreset.FileExportMode]` *const* — Returns file export mode for the specified file.
- `get_files_to_export() -> PackedStringArray` *const* — Returns array of files to export.
- `get_include_filter() -> String` *const* — Returns file filters to include during export.
- `get_or_env(name: StringName, env_var: String) -> Variant` *const* — Returns export option value or value of environment variable if it is set.
- `get_patches() -> PackedStringArray` *const* — Returns the list of packs on which to base a patch export on.
- `get_preset_name() -> String` *const* — Returns this export preset's name.
- `get_project_setting(name: StringName) -> Variant` — Returns the value of the setting identified by `name` using export preset feature tag overrides instead of current OS features.
- `get_script_export_mode() -> int[EditorExportPreset.ScriptExportMode]` *const* — Returns the export mode used by GDScript files.
- `get_version(name: StringName, windows_version: bool) -> String` *const* — Returns the preset's version number, or fall back to the `ProjectSettings.application/config/version` project setting if set to an empty string.
- `has(property: StringName) -> bool` *const* — Returns `true` if the preset has the property named `property`.
- `has_export_file(path: String) -> bool` — Returns `true` if the file at the specified `path` will be exported.
- `is_dedicated_server() -> bool` *const* — Returns `true` if the dedicated server export mode is selected in the export dialog.
- `is_runnable() -> bool` *const* — Returns `true` if the "Runnable" toggle is enabled in the export dialog.
- `resolve_encryption_key() -> PackedByteArray` — Returns PCK encryption key as a PackedByteArray.

## Enum ExportFilter

- `EXPORT_ALL_RESOURCES = 0` — 
- `EXPORT_SELECTED_SCENES = 1` — 
- `EXPORT_SELECTED_RESOURCES = 2` — 
- `EXCLUDE_SELECTED_RESOURCES = 3` — 
- `EXPORT_CUSTOMIZED = 4` — 

## Enum FileExportMode

- `MODE_FILE_NOT_CUSTOMIZED = 0` — 
- `MODE_FILE_STRIP = 1` — 
- `MODE_FILE_KEEP = 2` — 
- `MODE_FILE_REMOVE = 3` — 

## Enum ScriptExportMode

- `MODE_SCRIPT_TEXT = 0` — 
- `MODE_SCRIPT_BINARY_TOKENS = 1` — 
- `MODE_SCRIPT_BINARY_TOKENS_COMPRESSED = 2` —
