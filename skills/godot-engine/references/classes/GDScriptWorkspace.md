# GDScriptWorkspace

**Inherits:** RefCounted

Workspace related language server functionality.

Provides language server functionality related to the workspace.

## Methods

- `apply_new_signal(obj: Object, function: String, args: PackedStringArray) -> void` *(deprecated)*
- `didDeleteFiles(params: Dictionary) -> void` *(deprecated)*
- `generate_script_api(path: String) -> Dictionary` — Returns the interface of the script in a machine-readable format.
- `get_file_path(uri: String) -> String` — Converts a URI to a file path.
- `get_file_uri(path: String) -> String` *const* — Converts a file path to a URI.
- `parse_local_script(path: String) -> int[Error]` *(deprecated)*
- `parse_script(path: String, content: String) -> int[Error]` *(deprecated)*
- `publish_diagnostics(path: String) -> void` *(deprecated)*
