# ResourceSaver

**Inherits:** Object

A singleton for saving Resources to the filesystem.

A singleton for saving resource types to the filesystem. It uses the many ResourceFormatSaver classes registered in the engine (either built-in or from a plugin) to save resource data to text-based (e.g. `.tres` or `.tscn`) or binary files (e.g. `.res` or `.scn`).

## Methods

- `add_resource_format_saver(format_saver: ResourceFormatSaver, at_front: bool = false) -> void` — Registers a new ResourceFormatSaver.
- `get_recognized_extensions(type: Resource) -> PackedStringArray` — Returns the list of extensions available for saving a resource of a given type.
- `get_resource_id_for_path(path: String, generate: bool = false) -> int` — Returns the resource ID for the given path.
- `remove_resource_format_saver(format_saver: ResourceFormatSaver) -> void` — Unregisters the given ResourceFormatSaver.
- `save(resource: Resource, path: String = "", flags: ResourceSaver.SaverFlags = 0) -> int[Error]` — Saves a resource to disk to the given path, using a ResourceFormatSaver that recognizes the resource object.
- `set_uid(resource: String, uid: int) -> int[Error]` — Sets the UID of the given `resource` path to `uid`.

## Enum SaverFlags

- `FLAG_NONE = 0` — No resource saving option.
- `FLAG_RELATIVE_PATHS = 1` — Save the resource with a path relative to the scene which uses it.
- `FLAG_BUNDLE_RESOURCES = 2` — Bundles external resources.
- `FLAG_CHANGE_PATH = 4` — Changes the `Resource.resource_path` of the saved resource to match its new location.
- `FLAG_OMIT_EDITOR_PROPERTIES = 8` — Do not save editor-specific metadata (identified by their `__editor` prefix).
- `FLAG_SAVE_BIG_ENDIAN = 16` — Save as big endian (see `FileAccess.big_endian`).
- `FLAG_COMPRESS = 32` — Compress the resource on save using `FileAccess.COMPRESSION_ZSTD`.
- `FLAG_REPLACE_SUBRESOURCE_PATHS = 64` — Take over the paths of the saved subresources (see `Resource.take_over_path`).
