# ResourceUID

**Inherits:** Object

A singleton that manages the unique identifiers of all resources within a project.

Resource UIDs (Unique IDentifiers) allow the engine to keep references between resources intact, even if files are renamed or moved. They can be accessed with `uid://`. ResourceUID keeps track of all registered resource UIDs in a project, generates new UIDs, and converts between their string and integer representations.

## Methods

- `add_id(id: int, path: String) -> void` — Adds a new UID value which is mapped to the given resource path.
- `create_id() -> int` — Generates a random resource UID which is guaranteed to be unique within the list of currently loaded UIDs.
- `create_id_for_path(path: String) -> int` — Like `create_id`, but the UID is seeded with the provided `path` and project name.
- `ensure_path(path_or_uid: String) -> String` *static* — Returns a path, converting `path_or_uid` if necessary.
- `get_id_path(id: int) -> String` *const* — Returns the path that the given UID value refers to.
- `has_id(id: int) -> bool` *const* — Returns whether the given UID value is known to the cache.
- `id_to_text(id: int) -> String` *const* — Converts the given UID to a `uid://` string value.
- `path_to_uid(path: String) -> String` *static* — Converts the provided resource `path` to a UID.
- `remove_id(id: int) -> void` — Removes a loaded UID value from the cache.
- `set_id(id: int, path: String) -> void` — Updates the resource path of an existing UID.
- `text_to_id(text_id: String) -> int` *const* — Extracts the UID value from the given `uid://` string.
- `uid_to_path(uid: String) -> String` *static* — Converts the provided `uid` to a path.

## Constants

- `INVALID_ID = -1` — The value to use for an invalid UID, for example if the resource could not be loaded.
