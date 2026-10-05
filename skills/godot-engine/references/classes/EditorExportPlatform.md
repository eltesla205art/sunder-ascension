# EditorExportPlatform

**Inherits:** RefCounted

Identifies a supported export platform, and internally provides the functionality of exporting to that platform.

Base resource that provides the functionality of exporting a release build of a project to a platform, from the editor. Stores platform-specific metadata such as the name and supported features of the platform, and performs the exporting of projects, PCK files, and ZIP files. Uses an export template for the platform provided at the time of project exporting. Used in scripting by EditorExportPlugin to configure platform-specific customization of scenes and resources.

## Methods

- `add_message(type: EditorExportPlatform.ExportMessageType, category: String, message: String) -> void` — Adds a message to the export log that will be displayed when exporting ends.
- `clear_messages() -> void` — Clears the export log.
- `create_preset() -> EditorExportPreset` — Create a new preset for this platform.
- `export_pack(preset: EditorExportPreset, debug: bool, path: String, flags: EditorExportPlatform.DebugFlags = 0) -> int[Error]` — Creates a PCK archive at `path` for the specified `preset`.
- `export_pack_patch(preset: EditorExportPreset, debug: bool, path: String, patches: PackedStringArray = PackedStringArray(), flags: EditorExportPlatform.DebugFlags = 0) -> int[Error]` — Creates a patch PCK archive at `path` for the specified `preset`, containing only the files that have changed since the last patch.
- `export_project(preset: EditorExportPreset, debug: bool, path: String, flags: EditorExportPlatform.DebugFlags = 0, notify: bool = true) -> int[Error]` — Creates a full project at `path` for the specified `preset`.
- `export_project_files(preset: EditorExportPreset, debug: bool, save_cb: Callable, shared_cb: Callable = Callable()) -> int[Error]` — Exports project files for the specified preset.
- `export_zip(preset: EditorExportPreset, debug: bool, path: String, flags: EditorExportPlatform.DebugFlags = 0) -> int[Error]` — Create a ZIP archive at `path` for the specified `preset`.
- `export_zip_patch(preset: EditorExportPreset, debug: bool, path: String, patches: PackedStringArray = PackedStringArray(), flags: EditorExportPlatform.DebugFlags = 0) -> int[Error]` — Create a patch ZIP archive at `path` for the specified `preset`, containing only the files that have changed since the last patch.
- `find_export_template(template_file_name: String) -> Dictionary` *const* — Locates export template for the platform, and returns Dictionary with the following keys: `path: String` and `error: String`.
- `gen_export_flags(flags: EditorExportPlatform.DebugFlags) -> PackedStringArray` — Generates array of command line arguments for the default export templates for the debug flags and editor settings.
- `get_current_presets() -> Array` *const* — Returns array of EditorExportPresets for this platform.
- `get_forced_export_files(preset: EditorExportPreset = null) -> PackedStringArray` *static* — Returns array of core file names that always should be exported regardless of preset config.
- `get_internal_export_files(preset: EditorExportPreset, debug: bool) -> Dictionary` — Returns additional files that should always be exported regardless of preset configuration, and are not part of the project source.
- `get_message_category(index: int) -> String` *const* — Returns the message category for the message with the given `index`.
- `get_message_count() -> int` *const* — Returns the number of messages in the export log.
- `get_message_text(index: int) -> String` *const* — Returns the text for the message with the given `index`.
- `get_message_type(index: int) -> int[EditorExportPlatform.ExportMessageType]` *const* — Returns the type for the message with the given `index`.
- `get_os_name() -> String` *const* — Returns the name of the export operating system handled by this EditorExportPlatform class, as a friendly string.
- `get_worst_message_type() -> int[EditorExportPlatform.ExportMessageType]` *const* — Returns most severe message type currently present in the export log.
- `save_pack(preset: EditorExportPreset, debug: bool, path: String, embed: bool = false) -> Dictionary` — Saves PCK archive and returns Dictionary with the following keys: `result: Error`, `so_files: Array` (array of the shared/static objects which contains dictionaries with the following keys: `path: String`, `tags: PackedStringArray`, and `target_folder: String`).
- `save_pack_patch(preset: EditorExportPreset, debug: bool, path: String) -> Dictionary` — Saves patch PCK archive and returns Dictionary with the following keys: `result: Error`, `so_files: Array` (array of the shared/static objects which contains dictionaries with the following keys: `path: String`, `tags: PackedStringArray`, and `target_folder: String`).
- `save_zip(preset: EditorExportPreset, debug: bool, path: String) -> Dictionary` — Saves ZIP archive and returns Dictionary with the following keys: `result: Error`, `so_files: Array` (array of the shared/static objects which contains dictionaries with the following keys: `path: String`, `tags: PackedStringArray`, and `target_folder: String`).
- `save_zip_patch(preset: EditorExportPreset, debug: bool, path: String) -> Dictionary` — Saves patch ZIP archive and returns Dictionary with the following keys: `result: Error`, `so_files: Array` (array of the shared/static objects which contains dictionaries with the following keys: `path: String`, `tags: PackedStringArray`, and `target_folder: String`).
- `ssh_push_to_remote(host: String, port: String, scp_args: PackedStringArray, src_file: String, dst_file: String) -> int[Error]` *const* — Uploads specified file over SCP protocol to the remote host.
- `ssh_run_on_remote(host: String, port: String, ssh_arg: PackedStringArray, cmd_args: String, output: Array = [], port_fwd: int = -1) -> int[Error]` *const* — Executes specified command on the remote host via SSH protocol and returns command output in the `output`.
- `ssh_run_on_remote_no_wait(host: String, port: String, ssh_args: PackedStringArray, cmd_args: String, port_fwd: int = -1) -> int` *const* — Executes specified command on the remote host via SSH protocol and returns process ID (on the remote host) without waiting for command to finish.

## Enum ExportMessageType

- `EXPORT_MESSAGE_NONE = 0` — Invalid message type used as the default value when no type is specified.
- `EXPORT_MESSAGE_INFO = 1` — Message type for informational messages that have no effect on the export.
- `EXPORT_MESSAGE_WARNING = 2` — Message type for warning messages that should be addressed but still allow to complete the export.
- `EXPORT_MESSAGE_ERROR = 3` — Message type for error messages that must be addressed and fail the export.

## Enum DebugFlags

- `DEBUG_FLAG_DUMB_CLIENT = 1` — Flag is set if the remotely debugged project is expected to use the remote file system.
- `DEBUG_FLAG_REMOTE_DEBUG = 2` — Flag is set if remote debug is enabled.
- `DEBUG_FLAG_REMOTE_DEBUG_LOCALHOST = 4` — Flag is set if remotely debugged project is running on the localhost.
- `DEBUG_FLAG_VIEW_COLLISIONS = 8` — Flag is set if the "Visible Collision Shapes" remote debug option is enabled.
- `DEBUG_FLAG_VIEW_NAVIGATION = 16` — Flag is set if the "Visible Navigation" remote debug option is enabled.
