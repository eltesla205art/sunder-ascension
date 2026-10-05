# MenuButton

**Inherits:** Button

A button that brings up a PopupMenu when clicked.

A button that brings up a PopupMenu when clicked. To create new items inside this PopupMenu, use `get_popup().add_item("My Item Name")`. You can also create them directly from Godot editor's inspector. See also BaseButton which contains common properties and methods associated with this node.

## Properties

- `action_mode: BaseButton.ActionMode` = `0` — 
- `flat: bool` = `true` — 
- `focus_mode: Control.FocusMode` = `3` — 
- `item_count: int` = `0` — The number of items currently in the list.
- `popup/item_{index}/checkable: int` = `0` — The checkable item type of the item at `index`.
- `popup/item_{index}/checked: bool` = `false` — If `true`, the item at `index` is checked.
- `popup/item_{index}/disabled: bool` = `false` — If `true`, the item at `index` is disabled.
- `popup/item_{index}/icon: Texture2D` — The icon of the item at `index`.
- `popup/item_{index}/id: int` = `0` — The ID of the item at `index`.
- `popup/item_{index}/indeterminate: bool` = `false` — If `true`, the item at `index` is in an indeterminate state.
- `popup/item_{index}/separator: bool` = `false` — If `true`, the item at `index` is a separator.
- `popup/item_{index}/text: String` = `""` — The text of the item at `index`.
- `switch_on_hover: bool` = `false` — If `true`, when the cursor hovers above another MenuButton within the same parent which also has `switch_on_hover` enabled, it will close the current MenuButton and open the other one.
- `toggle_mode: bool` = `true` — 

## Methods

- `get_popup() -> PopupMenu` *const* — Returns the PopupMenu contained in this button.
- `set_disable_shortcuts(disabled: bool) -> void` — If `true`, shortcuts are disabled and cannot be used to trigger the button.
- `show_popup() -> void` — Adjusts popup position and sizing for the MenuButton, then shows the PopupMenu.

## Signals

- `about_to_popup()` — Emitted when the PopupMenu of this MenuButton is about to show.
