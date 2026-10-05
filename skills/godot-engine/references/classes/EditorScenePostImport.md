# EditorScenePostImport

**Inherits:** RefCounted

Post-processes scenes after import.

Imported scenes can be automatically modified right after import by setting their Custom Script Import property to a `tool` script that inherits from this class. The `_post_import` callback receives the imported scene's root node and returns the modified version of the scene:

## Methods

- `_post_import(scene: Node) -> Object` *virtual* — Called after the scene was imported.
- `get_source_file() -> String` *const* — Returns the source file path which got imported (e.g.
