# EditorFileSystem

**Inherits:** Node

Resource filesystem, as the editor sees it.

This object holds information of all resources in the filesystem, their types, etc. Note: This class shouldn't be instantiated directly. Instead, access the singleton using `EditorInterface.get_resource_filesystem`.

## Methods

- `get_file_type(path: String) -> String` *const* — Returns the resource type of the file, given the full path.
- `get_filesystem() -> EditorFileSystemDirectory` — Gets the root directory object.
- `get_filesystem_path(path: String) -> EditorFileSystemDirectory` — Returns a view into the filesystem at `path`.
- `get_scanning_progress() -> float` *const* — Returns the scan progress for 0 to 1 if the FS is being scanned.
- `is_importing() -> bool` *const* — Returns `true` if resources are currently being imported.
- `is_scanning() -> bool` *const* — Returns `true` if the filesystem is being scanned.
- `reimport_files(files: PackedStringArray) -> void` — Reimports a set of files.
- `scan() -> void` — Scan the filesystem for changes.
- `scan_sources() -> void` — Check if the source of any imported resource changed.
- `update_file(path: String) -> void` — Add a file in an existing directory, or schedule file information to be updated on editor restart.

## Signals

- `filesystem_changed()` — Emitted if the filesystem changed.
- `resources_reimported(resources: PackedStringArray)` — Emitted if a resource is reimported.
- `resources_reimporting(resources: PackedStringArray)` — Emitted before a resource is reimported.
- `resources_reload(resources: PackedStringArray)` — Emitted if at least one resource is reloaded when the filesystem is scanned.
- `script_classes_updated()` — Emitted when the list of global script classes gets updated.
- `sources_changed(exist: bool)` — Emitted if the source of any imported file changed.
