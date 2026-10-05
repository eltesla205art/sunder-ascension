# ResourceImporter

**Inherits:** RefCounted

Base class for resource importers.

This is the base class for Godot's resource importers. To implement your own resource importers using editor plugins, see EditorImportPlugin.

## Methods

- `_get_build_dependencies(path: String) -> PackedStringArray` *virtual const* — Called when the engine compilation profile editor wants to check what build options an imported resource needs.

## Enum ImportOrder

- `IMPORT_ORDER_DEFAULT = 0` — The default import order.
- `IMPORT_ORDER_SCENE = 100` — The import order for scenes, which ensures scenes are imported after all other core resources such as textures.
