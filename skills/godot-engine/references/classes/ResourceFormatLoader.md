# ResourceFormatLoader

**Inherits:** RefCounted

Loads a specific resource type from a file.

Godot loads resources in the editor or in exported games using ResourceFormatLoaders. They are queried automatically via the ResourceLoader singleton, or when a resource with internal dependencies is loaded. Each file type may load as a different resource type, so multiple ResourceFormatLoaders are registered in the engine. Extending this class allows you to define your own loader.

## Methods

- `_exists(path: String) -> bool` *virtual const*
- `_get_classes_used(path: String) -> PackedStringArray` *virtual const*
- `_get_dependencies(path: String, add_types: bool) -> PackedStringArray` *virtual const* — Should return the dependencies for the resource at the given `path`.
- `_get_recognized_extensions() -> PackedStringArray` *virtual const* — Gets the list of extensions for files this loader is able to read.
- `_get_resource_script_class(path: String) -> String` *virtual const* — Returns the script class name associated with the Resource under the given `path`.
- `_get_resource_type(path: String) -> String` *virtual const* — Gets the class name of the resource associated with the given path.
- `_get_resource_uid(path: String) -> int` *virtual const* — Should return the unique ID for the resource associated with the given path.
- `_handles_type(type: StringName) -> bool` *virtual const* — Tells which resource class this loader can load.
- `_load(path: String, original_path: String, use_sub_threads: bool, cache_mode: int) -> Variant` *virtual required const* — Loads a resource when the engine finds this loader to be compatible.
- `_recognize_path(path: String, type: StringName) -> bool` *virtual const* — Tells whether or not this loader should load a resource from its resource path for a given type.
- `_rename_dependencies(path: String, renames: Dictionary) -> int[Error]` *virtual const* — If implemented, renames dependencies within the given resource and saves it.

## Enum CacheMode

- `CACHE_MODE_IGNORE = 0` — Neither the main resource (the one requested to be loaded) nor any of its subresources are retrieved from cache nor stored into it.
- `CACHE_MODE_REUSE = 1` — The main resource (the one requested to be loaded), its subresources, and its dependencies (external resources) are retrieved from cache if present, instead of loaded.
- `CACHE_MODE_REPLACE = 2` — Like `CACHE_MODE_REUSE`, but the cache is checked for the main resource (the one requested to be loaded) as well as for each of its subresources.
- `CACHE_MODE_IGNORE_DEEP = 3` — Like `CACHE_MODE_IGNORE`, but propagated recursively down the tree of dependencies (external resources).
- `CACHE_MODE_REPLACE_DEEP = 4` — Like `CACHE_MODE_REPLACE`, but propagated recursively down the tree of dependencies (external resources).
