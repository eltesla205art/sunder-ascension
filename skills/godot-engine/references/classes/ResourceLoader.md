# ResourceLoader

**Inherits:** Object

A singleton for loading resource files.

A singleton used to load resource files from the filesystem. It uses the many ResourceFormatLoader classes registered in the engine (either built-in or from a plugin) to load files into memory and convert them to a format that can be used by the engine. Note: You have to import the files into the engine first to load them using `load`. If you want to load Images at run-time, you may use `Image.load`.

## Methods

- `add_resource_format_loader(format_loader: ResourceFormatLoader, at_front: bool = false) -> void` — Registers a new ResourceFormatLoader.
- `exists(path: String, type_hint: String = "") -> bool` — Returns whether a recognized resource exists for the given `path`.
- `get_cached_ref(path: String) -> Resource` — Returns the cached resource reference for the given `path`.
- `get_dependencies(path: String) -> PackedStringArray` — Returns the dependencies for the resource at the given `path`.
- `get_recognized_extensions_for_type(type: String) -> PackedStringArray` — Returns the list of recognized extensions for a resource type.
- `get_resource_type(path: String) -> String` — Returns the resource type associated with a given resource path.
- `get_resource_uid(path: String) -> int` — Returns the ID associated with a given resource path, or `-1` when no such ID exists.
- `has_cached(path: String) -> bool` — Returns whether a cached resource is available for the given `path`.
- `list_directory(directory_path: String) -> PackedStringArray` — Lists a directory, returning all resources and subdirectories contained within.
- `load(path: String, type_hint: String = "", cache_mode: ResourceLoader.CacheMode = 1) -> Resource` — Loads a resource at the given `path`, caching the result for further access.
- `load_threaded_get(path: String) -> Resource` — Returns the resource loaded by `load_threaded_request`.
- `load_threaded_get_status(path: String, progress: Array = []) -> int[ResourceLoader.ThreadLoadStatus]` — Returns the status of a threaded loading operation started with `load_threaded_request` for the resource at `path`.
- `load_threaded_request(path: String, type_hint: String = "", use_sub_threads: bool = false, cache_mode: ResourceLoader.CacheMode = 1) -> int[Error]` — Loads the resource using threads.
- `remove_resource_format_loader(format_loader: ResourceFormatLoader) -> void` — Unregisters the given ResourceFormatLoader.
- `set_abort_on_missing_resources(abort: bool) -> void` — Changes the behavior on missing sub-resources.

## Enum ThreadLoadStatus

- `THREAD_LOAD_INVALID_RESOURCE = 0` — The resource is invalid, or has not been loaded with `load_threaded_request`.
- `THREAD_LOAD_IN_PROGRESS = 1` — The resource is still being loaded.
- `THREAD_LOAD_FAILED = 2` — Some error occurred during loading and it failed.
- `THREAD_LOAD_LOADED = 3` — The resource was loaded successfully and can be accessed via `load_threaded_get`.

## Enum CacheMode

- `CACHE_MODE_IGNORE = 0` — Neither the main resource (the one requested to be loaded) nor any of its subresources are retrieved from cache nor stored into it.
- `CACHE_MODE_REUSE = 1` — The main resource (the one requested to be loaded), its subresources, and its dependencies (external resources) are retrieved from cache if present, instead of loaded.
- `CACHE_MODE_REPLACE = 2` — Like `CACHE_MODE_REUSE`, but the cache is checked for the main resource (the one requested to be loaded) as well as for each of its subresources.
- `CACHE_MODE_IGNORE_DEEP = 3` — Like `CACHE_MODE_IGNORE`, but propagated recursively down the tree of dependencies (external resources).
- `CACHE_MODE_REPLACE_DEEP = 4` — Like `CACHE_MODE_REPLACE`, but propagated recursively down the tree of dependencies (external resources).
