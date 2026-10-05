# OptionButton

**Inherits:** Button

A button that brings up a dropdown with selectable options when pressed.

OptionButton is a type of button that brings up a dropdown with selectable items when pressed. The item selected becomes the "current" item and is displayed as the button text. See also BaseButton which contains common properties and methods associated with this node. Note: The IDs used for items are limited to signed 32-bit integers, not the full 64 bits of int.

## Properties

- `action_mode: BaseButton.ActionMode` = `0` — 
- `alignment: HorizontalAlignment` = `0` — 
- `allow_reselect: bool` = `false` — If `true`, the currently selected item can be selected again.
- `fit_to_longest_item: bool` = `true` — If `true`, minimum size will be determined by the longest item's width, instead of the currently selected one's.
- `item_count: int` = `0` — The number of items to select from.
- `popup/item_{index}/disabled: bool` = `false` — If `true`, the item at `index` is disabled.
- `popup/item_{index}/icon: Texture2D` — The icon of the item at `index`.
- `popup/item_{index}/id: int` = `0` — The ID of the item at `index`.
- `popup/item_{index}/separator: bool` = `false` — If `true`, the item at `index` is a separator.
- `popup/item_{index}/text: String` = `""` — The text of the item at `index`.
- `search_bar_enabled: bool` = `false` — If `true`, shows a search bar at the top of the PopupMenu for filtering items.
- `search_bar_fuzzy_search_enabled: bool` = `true` — If `true`, enables fuzzy searching in the PopupMenu search bar.
- `search_bar_fuzzy_search_max_misses: int` = `2` — Sets the maximum number of mismatches allowed in each search result when fuzzy searching is enabled for the PopupMenu search bar.
- `search_bar_min_item_count: int` = `0` — Sets the minimum number of items required for the PopupMenu search bar to be visible.
- `selected: int` = `-1` — The index of the currently selected item, or `-1` if no item is selected.
- `toggle_mode: bool` = `true` — 

## Methods

- `add_icon_item(texture: Texture2D, label: String, id: int = -1) -> void` — Adds an item, with a `texture` icon, text `label` and (optionally) `id`.
- `add_item(label: String, id: int = -1) -> void` — Adds an item, with text `label` and (optionally) `id`.
- `add_separator(text: String = "") -> void` — Adds a separator to the list of items.
- `clear() -> void` — Clears all the items in the OptionButton.
- `get_item_auto_translate_mode(idx: int) -> int[Node.AutoTranslateMode]` *const* — Returns the auto translate mode of the item at index `idx`.
- `get_item_icon(idx: int) -> Texture2D` *const* — Returns the icon of the item at index `idx`.
- `get_item_id(idx: int) -> int` *const* — Returns the ID of the item at index `idx`.
- `get_item_index(id: int) -> int` *const* — Returns the index of the item with the given `id`.
- `get_item_metadata(idx: int) -> Variant` *const* — Retrieves the metadata of an item.
- `get_item_text(idx: int) -> String` *const* — Returns the text of the item at index `idx`.
- `get_item_tooltip(idx: int) -> String` *const* — Returns the tooltip of the item at index `idx`.
- `get_popup() -> PopupMenu` *const* — Returns the PopupMenu contained in this button.
- `get_selectable_item(from_last: bool = false) -> int` *const* — Returns the index of the first item which is not disabled, or marked as a separator.
- `get_selected_id() -> int` *const* — Returns the ID of the selected item, or `-1` if no item is selected.
- `get_selected_metadata() -> Variant` *const* — Gets the metadata of the selected item.
- `has_selectable_items() -> bool` *const* — Returns `true` if this button contains at least one item which is not disabled, or marked as a separator.
- `is_item_disabled(idx: int) -> bool` *const* — Returns `true` if the item at index `idx` is disabled.
- `is_item_separator(idx: int) -> bool` *const* — Returns `true` if the item at index `idx` is marked as a separator.
- `remove_item(idx: int) -> void` — Removes the item at index `idx`.
- `select(idx: int) -> void` — Selects an item by index and makes it the current item.
- `set_disable_shortcuts(disabled: bool) -> void` — If `true`, shortcuts are disabled and cannot be used to trigger the button.
- `set_item_auto_translate_mode(idx: int, mode: Node.AutoTranslateMode) -> void` — Sets the auto translate mode of the item at index `idx`.
- `set_item_disabled(idx: int, disabled: bool) -> void` — Sets whether the item at index `idx` is disabled.
- `set_item_icon(idx: int, texture: Texture2D) -> void` — Sets the icon of the item at index `idx`.
- `set_item_id(idx: int, id: int) -> void` — Sets the ID of the item at index `idx`.
- `set_item_metadata(idx: int, metadata: Variant) -> void` — Sets the metadata of an item.
- `set_item_text(idx: int, text: String) -> void` — Sets the text of the item at index `idx`.
- `set_item_tooltip(idx: int, tooltip: String) -> void` — Sets the tooltip of the item at index `idx`.
- `show_popup() -> void` — Adjusts popup position and sizing for the OptionButton, then shows the PopupMenu.

## Signals

- `item_focused(index: int)` — Emitted when the user navigates to an item using the `ProjectSettings.input/ui_up` or `ProjectSettings.input/ui_down` input actions.
- `item_selected(index: int)` — Emitted when the current item has been changed by the user.

## Theme items

- `arrow_margin: int` (constant) = `4`
- `modulate_arrow: int` (constant) = `0`
- `arrow: Texture2D` (icon)
