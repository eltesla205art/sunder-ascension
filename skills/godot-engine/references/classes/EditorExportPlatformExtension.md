# EditorExportPlatformExtension

**Inherits:** EditorExportPlatform

Base class for custom EditorExportPlatform implementations (plugins).

External EditorExportPlatform implementations should inherit from this class. To use EditorExportPlatform, register it using the `EditorPlugin.add_export_platform` method first.

## Methods

- `_can_export(preset: EditorExportPreset, debug: bool) -> bool` *virtual const* — Returns `true` if the specified `preset` is valid and can be exported.
- `_cleanup() -> void` *virtual* — Called by the editor before platform is unregistered.
- `_export_pack(preset: EditorExportPreset, debug: bool, path: String, flags: EditorExportPlatform.DebugFlags) -> int[Error]` *virtual* — Creates a PCK archive at `path` for the specified `preset`.
- `_export_pack_patch(preset: EditorExportPreset, debug: bool, path: String, patches: PackedStringArray, flags: EditorExportPlatform.DebugFlags) -> int[Error]` *virtual* — Creates a patch PCK archive at `path` for the specified `preset`, containing only the files that have changed since the last patch.
- `_export_project(preset: EditorExportPreset, debug: bool, path: String, flags: EditorExportPlatform.DebugFlags) -> int[Error]` *virtual required* — Creates a full project at `path` for the specified `preset`.
- `_export_zip(preset: EditorExportPreset, debug: bool, path: String, flags: EditorExportPlatform.DebugFlags) -> int[Error]` *virtual* — Create a ZIP archive at `path` for the specified `preset`.
- `_export_zip_patch(preset: EditorExportPreset, debug: bool, path: String, patches: PackedStringArray, flags: EditorExportPlatform.DebugFlags) -> int[Error]` *virtual* — Create a ZIP archive at `path` for the specified `preset`, containing only the files that have changed since the last patch.
- `_get_binary_extensions(preset: EditorExportPreset) -> PackedStringArray` *virtual required const* — Returns array of supported binary extensions for the full project export.
- `_get_debug_protocol() -> String` *virtual const* — Returns protocol used for remote debugging.
- `_get_device_architecture(device: int) -> String` *virtual const* — Returns device architecture for remote deploy.
- `_get_export_option_visibility(preset: EditorExportPreset, option: String) -> bool` *virtual const* — Validates `option` and returns visibility for the specified `preset`.
- `_get_export_option_warning(preset: EditorExportPreset, option: StringName) -> String` *virtual const* — Validates `option` and returns warning message for the specified `preset`.
- `_get_export_options() -> Dictionary[]` *virtual const* — Returns a property list, as an Array of dictionaries.
- `_get_logo() -> Texture2D` *virtual required const* — Returns the platform logo displayed in the export dialog.
- `_get_name() -> String` *virtual required const* — Returns export platform name.
- `_get_option_icon(device: int) -> Texture2D` *virtual const* — Returns the item icon for the specified `device` in the remote deploy menu.
- `_get_option_label(device: int) -> String` *virtual const* — Returns remote deploy menu item label for the specified `device`.
- `_get_option_tooltip(device: int) -> String` *virtual const* — Returns remote deploy menu item tooltip for the specified `device`.
- `_get_options_count() -> int` *virtual const* — Returns the number of devices (or other options) available in the remote deploy menu.
- `_get_options_tooltip() -> String` *virtual const* — Returns tooltip of the remote deploy menu button.
- `_get_os_name() -> String` *virtual required const* — Returns target OS name.
- `_get_platform_features() -> PackedStringArray` *virtual required const* — Returns array of platform specific features.
- `_get_preset_features(preset: EditorExportPreset) -> PackedStringArray` *virtual required const* — Returns array of platform specific features for the specified `preset`.
- `_get_run_icon() -> Texture2D` *virtual const* — Returns the icon of the remote deploy menu button.
- `_has_valid_export_configuration(preset: EditorExportPreset, debug: bool) -> bool` *virtual required const* — Returns `true` if export configuration is valid.
- `_has_valid_project_configuration(preset: EditorExportPreset) -> bool` *virtual required const* — Returns `true` if project configuration is valid.
- `_initialize() -> void` *virtual* — Initializes the plugin.
- `_is_executable(path: String) -> bool` *virtual const* — Returns `true` if specified file is a valid executable (native executable or script) for the target platform.
- `_poll_export() -> bool` *virtual* — Returns `true` if remote deploy options are changed and editor interface should be updated.
- `_run(preset: EditorExportPreset, device: int, debug_flags: EditorExportPlatform.DebugFlags) -> int[Error]` *virtual* — This method is called when `device` remote deploy menu option is selected.
- `_should_update_export_options() -> bool` *virtual* — Returns `true` if export options list is changed and presets should be updated.
- `get_config_error() -> String` *const* — Returns current configuration error message text.
- `get_config_missing_templates() -> bool` *const* — Returns `true` is export templates are missing from the current configuration.
- `set_config_error(error_text: String) -> void` *const* — Sets current configuration error message text.
- `set_config_missing_templates(missing_templates: bool) -> void` *const* — Set to `true` is export templates are missing from the current configuration.
