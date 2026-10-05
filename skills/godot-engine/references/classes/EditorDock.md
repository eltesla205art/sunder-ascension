# EditorDock

**Inherits:** MarginContainer

Dockable container for the editor.

EditorDock is a Container node that can be docked in one of the editor's dock slots. Docks are added by plugins to provide space for controls related to an EditorPlugin. The editor comes with a few built-in docks, such as the Scene dock, FileSystem dock, etc. You can add a dock by using `EditorPlugin.add_dock`.

## Properties

- `accessibility_region: bool` = `true` — 
- `allow_switch_screen: bool` = `false` — If `true` and this dock is docked in the main screen, selecting a node in the scene tree can switch away from this dock.
- `available_layouts: EditorDock.DockLayout` = `5` — The available layouts for this dock, as a bitmask.
- `closable: bool` = `false` — If `true`, the dock can be closed with the Close button in the context popup.
- `default_slot: EditorDock.DockSlot` = `-1` — The default dock slot used when adding the dock with `EditorPlugin.add_dock`.
- `dock_icon: Texture2D` — The icon for the dock, as a texture.
- `dock_shortcut: Shortcut` — The shortcut used to open the dock.
- `force_show_icon: bool` = `false` — If `true`, the dock will always display an icon, regardless of `EditorSettings.interface/editor/docks/dock_tab_style` or `EditorSettings.interface/editor/docks/bottom_dock_tab_style`.
- `global: bool` = `true` — If `true`, the dock appears in the Editor > Editor Docks menu and can be closed.
- `icon_name: StringName` = `&""` — The icon for the dock, as a name from the `EditorIcons` theme type in the editor theme.
- `layout_key: String` = `""` — The key representing this dock in the editor's layout file.
- `title: String` = `""` — The title of the dock's tab.
- `title_color: Color` = `Color(0, 0, 0, 0)` — The color of the dock tab's title.
- `transient: bool` = `false` — If `true`, the dock is not automatically opened or closed when loading an editor layout, only moved.

## Methods

- `_load_layout_from_config(config: ConfigFile, section: String) -> void` *virtual* — Implement this method to handle loading this dock's layout.
- `_save_layout_to_config(config: ConfigFile, section: String) -> void` *virtual const* — Implement this method to handle saving this dock's layout.
- `_update_layout(layout: int) -> void` *virtual* *(deprecated)* — Implement this method to handle the layout switching for this dock.
- `_update_layout_and_slot(layout: int, slot: int) -> void` *virtual* — Implement this method to handle the layout/slot switching for this dock.
- `close() -> void` — Closes the dock, making its tab hidden.
- `make_visible() -> void` — Focuses the dock's tab (or window if it's floating).
- `open() -> void` — Opens the dock.

## Signals

- `closed()` — Emitted when the dock is closed, before it's removed from its parent.
- `opened()` — Emitted when the dock is opened via the Editor > Editor Docks menu, before it's made visible.

## Enum DockLayout

- `DOCK_LAYOUT_VERTICAL = 1` — Allows placing the dock in the vertical dock slots on either side of the editor.
- `DOCK_LAYOUT_HORIZONTAL = 2` — Allows placing the dock in the horizontal dock slots at the bottom.
- `DOCK_LAYOUT_FLOATING = 4` — Allows making the dock floating (opened as a separate window).
- `DOCK_LAYOUT_MAIN_SCREEN = 8` — Allows using the dock as main screen.
- `DOCK_LAYOUT_ALL = 7` — Allows placing the dock in all available slots, except in main screen.

## Enum DockSlot

- `DOCK_SLOT_NONE = -1` — The dock is closed.
- `DOCK_SLOT_LEFT_UL = 0` — Dock slot, left side, upper-left (empty in default layout).
- `DOCK_SLOT_LEFT_BL = 1` — Dock slot, left side, bottom-left (empty in default layout).
- `DOCK_SLOT_LEFT_UR = 2` — Dock slot, left side, upper-right (in default layout includes Scene and Import docks).
- `DOCK_SLOT_LEFT_BR = 3` — Dock slot, left side, bottom-right (in default layout includes FileSystem and History docks).
- `DOCK_SLOT_RIGHT_UL = 4` — Dock slot, right side, upper-left (in default layout includes Inspector, Signal, and Group docks).
- `DOCK_SLOT_RIGHT_BL = 5` — Dock slot, right side, bottom-left (empty in default layout).
- `DOCK_SLOT_RIGHT_UR = 6` — Dock slot, right side, upper-right (empty in default layout).
- `DOCK_SLOT_RIGHT_BR = 7` — Dock slot, right side, bottom-right (empty in default layout).
- `DOCK_SLOT_BOTTOM = 8` — Bottom panel.
- `DOCK_SLOT_BOTTOM_L = 9` — Dock slot at the bottom, below bottom panel, on the left side.
- `DOCK_SLOT_BOTTOM_R = 10` — Dock slot at the bottom, below bottom panel, on the right side.
- `DOCK_SLOT_MAIN_SCREEN = 11` — The editor's main screen.
- `DOCK_SLOT_MAX = 12` — Represents the size of the `DockSlot` enum.
