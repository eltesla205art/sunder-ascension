# GDExtensionManager

**Inherits:** Object

Provides access to GDExtension functionality.

The GDExtensionManager loads, initializes, and keeps track of all available GDExtension libraries in the project. Note: Do not worry about GDExtension unless you know what you are doing.

## Methods

- `get_extension(path: String) -> GDExtension` — Returns the GDExtension at the given file `path`, or `null` if it has not been loaded or does not exist.
- `get_loaded_extensions() -> PackedStringArray` *const* — Returns the file paths of all currently loaded extensions.
- `is_extension_loaded(path: String) -> bool` *const* — Returns `true` if the extension at the given file `path` has already been loaded successfully.
- `load_extension(path: String) -> int[GDExtensionManager.LoadStatus]` — Loads an extension by absolute file path.
- `load_extension_from_function(path: String, init_func: const GDExtensionInitializationFunction*) -> int[GDExtensionManager.LoadStatus]` — Loads the extension already in address space via the given path and initialization function.
- `reload_extension(path: String) -> int[GDExtensionManager.LoadStatus]` — Reloads the extension at the given file path.
- `unload_extension(path: String) -> int[GDExtensionManager.LoadStatus]` — Unloads an extension by file path.

## Signals

- `extension_loaded(extension: GDExtension)` — Emitted after the editor has finished loading a new extension.
- `extension_unloading(extension: GDExtension)` — Emitted before the editor starts unloading an extension.
- `extensions_reloaded()` — Emitted after the editor has finished reloading one or more extensions.

## Enum LoadStatus

- `LOAD_STATUS_OK = 0` — The extension has loaded successfully.
- `LOAD_STATUS_FAILED = 1` — The extension has failed to load, possibly because it does not exist or has missing dependencies.
- `LOAD_STATUS_ALREADY_LOADED = 2` — The extension has already been loaded.
- `LOAD_STATUS_NOT_LOADED = 3` — The extension has not been loaded.
- `LOAD_STATUS_NEEDS_RESTART = 4` — The extension requires the application to restart to fully load.
