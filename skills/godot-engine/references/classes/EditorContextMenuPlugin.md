# EditorContextMenuPlugin

**Inherits:** RefCounted

Plugin for adding custom context menus in the editor.

EditorContextMenuPlugin allows for the addition of custom options in the editor's context menu. Register them with `EditorPlugin.add_context_menu_plugin`. See `ContextMenuSlot` for the list of available areas where context menu plugins are supported.

## Methods

- `_get_menu_options(data: Dictionary[StringName, Variant]) -> void` *virtual* — Called when creating a context menu, custom options can be added by using the `add_context_menu_item` or `add_context_menu_item_from_shortcut` functions.
- `_popup_menu(paths: PackedStringArray) -> void` *virtual* *(deprecated)* — Note: Implementing this method makes the shortcut callbacks receive legacy data (for compatibility reasons).
- `add_context_menu_item(name: String, callback: Callable, icon: Texture2D = null) -> void` — Add custom option to the context menu of the plugin's specified slot.
- `add_context_menu_item_from_shortcut(name: String, shortcut: Shortcut, icon: Texture2D = null) -> void` — Add custom option to the context menu of the plugin's specified slot.
- `add_context_submenu_item(name: String, menu: PopupMenu, icon: Texture2D = null) -> void` — Add a submenu to the context menu of the plugin's specified slot.
- `add_menu_shortcut(shortcut: Shortcut, callback: Callable) -> void` — Registers a shortcut associated with the plugin's context menu.

## Enum ContextMenuSlot

- `CONTEXT_SLOT_SCENE_TREE = 0` — Context menu of Scene dock.
- `CONTEXT_SLOT_FILESYSTEM = 1` — Context menu of FileSystem dock.
- `CONTEXT_SLOT_SCRIPT_EDITOR = 2` — Context menu of Script editor's script tabs and Shader editor's shader tabs.
- `CONTEXT_SLOT_FILESYSTEM_CREATE = 3` — The "Create..." submenu of FileSystem dock's context menu, or the "New" section of the main context menu when empty space is clicked.
- `CONTEXT_SLOT_SCRIPT_EDITOR_CODE = 4` — Context menu of Script editor's code editor.
- `CONTEXT_SLOT_SCENE_TABS = 5` — Context menu of scene tabs.
- `CONTEXT_SLOT_2D_EDITOR = 6` — Context menu of the 2D editor's viewport.
- `CONTEXT_SLOT_INSPECTOR_PROPERTY = 7` — Context menu of an editor property in the inspector.
