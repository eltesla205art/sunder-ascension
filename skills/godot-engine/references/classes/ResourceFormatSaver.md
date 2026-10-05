# ResourceFormatSaver

**Inherits:** RefCounted

Saves a specific resource type to a file.

The engine can save resources when you do it from the editor, or when you use the ResourceSaver singleton. This is accomplished thanks to multiple ResourceFormatSavers, each handling its own format and called automatically by the engine. By default, Godot saves resources as `.tres` (text-based), `.res` (binary) or another built-in format, but you can choose to create your own format by extending this class. Be sure to respect the documented return types and values.

## Methods

- `_get_recognized_extensions(resource: Resource) -> PackedStringArray` *virtual const* — Returns the list of extensions available for saving the resource object, provided it is recognized (see `_recognize`).
- `_recognize(resource: Resource) -> bool` *virtual const* — Returns whether the given resource object can be saved by this saver.
- `_recognize_path(resource: Resource, path: String) -> bool` *virtual const* — Returns `true` if this saver handles a given save path and `false` otherwise.
- `_save(resource: Resource, path: String, flags: int) -> int[Error]` *virtual* — Saves the given resource object to a file at the target `path`.
- `_set_uid(path: String, uid: int) -> int[Error]` *virtual* — Sets a new UID for the resource at the given `path`.
