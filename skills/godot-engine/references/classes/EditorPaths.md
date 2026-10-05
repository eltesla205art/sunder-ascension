# EditorPaths

**Inherits:** Object

Editor-only singleton that returns paths to various OS-specific data folders and files.

This editor-only singleton returns OS-specific paths to various data folders and files. It can be used in editor plugins to ensure files are saved in the correct location on each operating system. Note: This singleton is not accessible in exported projects. Attempting to access it in an exported project will result in a script error as the singleton won't be declared.

## Methods

- `get_cache_dir() -> String` *const* — Returns the absolute path to the user's cache folder.
- `get_config_dir() -> String` *const* — Returns the absolute path to the user's configuration folder.
- `get_data_dir() -> String` *const* — Returns the absolute path to the user's data folder.
- `get_project_settings_dir() -> String` *const* — Returns the relative path to the editor settings for this project.
- `get_self_contained_file() -> String` *const* — Returns the absolute path to the self-contained file that makes the current Godot editor instance be considered as self-contained.
- `is_self_contained() -> bool` *const* — Returns `true` if the editor is marked as self-contained, `false` otherwise.
