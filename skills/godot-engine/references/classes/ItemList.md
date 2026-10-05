# ItemList

**Inherits:** Control

A vertical list of selectable items with one or multiple columns.

This control provides a vertical list of selectable items that may be in a single or in multiple columns, with each item having options for text and an icon. Tooltips are supported and may be different for every item in the list. Selectable items in the list may be selected or deselected and multiple selection may be enabled. Selection with right mouse button may also be enabled to allow use of popup context menus.

## Properties

- `allow_reselect: bool` = `false` — If `true`, the currently selected item can be selected again.
- `allow_rmb_select: bool` = `false` — If `true`, right mouse button click can select items.
- `allow_search: bool` = `true` — If `true`, allows navigating the ItemList with letter keys through incremental search.
- `auto_height: bool` = `false` — If `true`, the control will automatically resize the height to fit its content.
- `auto_width: bool` = `false` — If `true`, the control will automatically resize the width to fit its content.
- `clip_contents: bool` = `true` — 
- `fixed_column_width: int` = `0` — The width all columns will be adjusted to.
- `fixed_icon_size: Vector2i` = `Vector2i(0, 0)` — The size all icons will be adjusted to.
- `focus_mode: Control.FocusMode` = `2` — 
- `icon_mode: ItemList.IconMode` = `1` — The icon position, whether above or to the left of the text.
- `icon_scale: float` = `1.0` — The scale of icon applied after `fixed_icon_size` and transposing takes effect.
- `item_count: int` = `0` — The number of items currently in the list.
- `item_{index}/disabled: bool` = `false` — If `true`, the item at `index` is disabled.
- `item_{index}/icon: Texture2D` — The icon of the item at `index`.
- `item_{index}/selectable: bool` = `true` — If `true`, the item at `index` is selectable.
- `item_{index}/text: String` = `""` — The text of the item at `index`.
- `max_columns: int` = `1` — Maximum columns the list will have.
- `max_text_lines: int` = `1` — Maximum lines of text allowed in each item.
- `same_column_width: bool` = `false` — Whether all columns will have the same width.
- `scroll_hint_mode: ItemList.ScrollHintMode` = `0` — The way which scroll hints (indicators that show that the content can still be scrolled in a certain direction) will be shown.
- `select_mode: ItemList.SelectMode` = `0` — Allows single or multiple item selection.
- `text_overrun_behavior: TextServer.OverrunBehavior` = `3` — The clipping behavior when the text exceeds an item's bounding rectangle.
- `tile_scroll_hint: bool` = `false` — If `true`, the scroll hint texture will be tiled instead of stretched.
- `wraparound_items: bool` = `true` — If `true`, the control will automatically move items into a new row to fit its content.

## Methods

- `add_icon_item(icon: Texture2D, selectable: bool = true) -> int` — Adds an item to the item list with no text, only an icon.
- `add_item(text: String, icon: Texture2D = null, selectable: bool = true) -> int` — Adds an item to the item list with specified text.
- `center_on_current(center_verically: bool = true, center_horizontally: bool = true) -> void` — Ensures the currently selected item (the first selected item if multiple selection is enabled) is visible, adjusting the scroll position as necessary to place the item at the center of the list if possible.
- `clear() -> void` — Removes all items from the list.
- `deselect(idx: int) -> void` — Ensures the item associated with the specified index is not selected.
- `deselect_all() -> void` — Ensures there are no items selected.
- `ensure_current_is_visible() -> void` — Ensures the currently selected item (the first selected item if multiple selection is enabled) is visible, adjusting the scroll position as necessary.
- `force_update_list_size() -> void` — Forces an update to the list size based on its items.
- `get_h_scroll_bar() -> HScrollBar` — Returns the horizontal scrollbar.
- `get_item_at_position(position: Vector2, exact: bool = false) -> int` *const* — Returns the item index at the given `position`.
- `get_item_auto_translate_mode(idx: int) -> int[Node.AutoTranslateMode]` *const* — Returns item's auto translate mode.
- `get_item_custom_bg_color(idx: int) -> Color` *const* — Returns the custom background color of the item specified by `idx` index.
- `get_item_custom_fg_color(idx: int) -> Color` *const* — Returns the custom foreground color of the item specified by `idx` index.
- `get_item_icon(idx: int) -> Texture2D` *const* — Returns the icon associated with the specified index.
- `get_item_icon_modulate(idx: int) -> Color` *const* — Returns a Color modulating item's icon at the specified index.
- `get_item_icon_region(idx: int) -> Rect2` *const* — Returns the region of item's icon used.
- `get_item_language(idx: int) -> String` *const* — Returns item's text language code.
- `get_item_metadata(idx: int) -> Variant` *const* — Returns the metadata value of the specified index.
- `get_item_rect(idx: int, expand: bool = true) -> Rect2` *const* — Returns the position and size of the item with the specified index, in the coordinate system of the ItemList node.
- `get_item_text(idx: int) -> String` *const* — Returns the text associated with the specified index.
- `get_item_text_direction(idx: int) -> int[Control.TextDirection]` *const* — Returns item's text base writing direction.
- `get_item_tooltip(idx: int) -> String` *const* — Returns the tooltip hint associated with the specified index.
- `get_selected_items() -> PackedInt32Array` — Returns an array with the indexes of the selected items.
- `get_v_scroll_bar() -> VScrollBar` — Returns the vertical scrollbar.
- `is_anything_selected() -> bool` — Returns `true` if one or more items are selected.
- `is_item_disabled(idx: int) -> bool` *const* — Returns `true` if the item at the specified index is disabled.
- `is_item_icon_transposed(idx: int) -> bool` *const* — Returns `true` if the item icon will be drawn transposed, i.e. the X and Y axes are swapped.
- `is_item_selectable(idx: int) -> bool` *const* — Returns `true` if the item at the specified index is selectable.
- `is_item_tooltip_enabled(idx: int) -> bool` *const* — Returns `true` if the tooltip is enabled for specified item index.
- `is_selected(idx: int) -> bool` *const* — Returns `true` if the item at the specified index is currently selected.
- `move_item(from_idx: int, to_idx: int) -> void` — Moves item from index `from_idx` to `to_idx`.
- `remove_item(idx: int) -> void` — Removes the item specified by `idx` index from the list.
- `select(idx: int, single: bool = true) -> void` — Selects the item at the specified index.
- `set_item_auto_translate_mode(idx: int, mode: Node.AutoTranslateMode) -> void` — Sets the auto translate mode of the item associated with the specified index.
- `set_item_custom_bg_color(idx: int, custom_bg_color: Color) -> void` — Sets the background color of the item specified by `idx` index to the specified Color.
- `set_item_custom_fg_color(idx: int, custom_fg_color: Color) -> void` — Sets the foreground color of the item specified by `idx` index to the specified Color.
- `set_item_disabled(idx: int, disabled: bool) -> void` — Disables (or enables) the item at the specified index.
- `set_item_icon(idx: int, icon: Texture2D) -> void` — Sets (or replaces) the icon's Texture2D associated with the specified index.
- `set_item_icon_modulate(idx: int, modulate: Color) -> void` — Sets a modulating Color of the item associated with the specified index.
- `set_item_icon_region(idx: int, rect: Rect2) -> void` — Sets the region of item's icon used.
- `set_item_icon_transposed(idx: int, transposed: bool) -> void` — Sets whether the item icon will be drawn transposed.
- `set_item_language(idx: int, language: String) -> void` — Sets the language code of the text for the item at the given index to `language`.
- `set_item_metadata(idx: int, metadata: Variant) -> void` — Sets a value (of any type) to be stored with the item associated with the specified index.
- `set_item_selectable(idx: int, selectable: bool) -> void` — Allows or disallows selection of the item associated with the specified index.
- `set_item_text(idx: int, text: String) -> void` — Sets text of the item associated with the specified index.
- `set_item_text_direction(idx: int, direction: Control.TextDirection) -> void` — Sets item's text base writing direction.
- `set_item_tooltip(idx: int, tooltip: String) -> void` — Sets the tooltip hint for the item associated with the specified index.
- `set_item_tooltip_enabled(idx: int, enable: bool) -> void` — Sets whether the tooltip hint is enabled for specified item index.
- `sort_items_by_text() -> void` — Sorts items in the list by their text.

## Signals

- `empty_clicked(at_position: Vector2, mouse_button_index: int)` — Emitted when any mouse click is issued within the rect of the list but on empty space.
- `item_activated(index: int)` — Emitted when specified list item is activated via double-clicking or by pressing `Enter`.
- `item_clicked(index: int, at_position: Vector2, mouse_button_index: int)` — Emitted when specified list item has been clicked with any mouse button.
- `item_selected(index: int)` — Emitted when specified item has been selected.
- `multi_selected(index: int, selected: bool)` — Emitted when a multiple selection is altered on a list allowing multiple selection.

## Enum IconMode

- `ICON_MODE_TOP = 0` — Icon is drawn above the text.
- `ICON_MODE_LEFT = 1` — Icon is drawn to the left of the text.

## Enum SelectMode

- `SELECT_SINGLE = 0` — Only allow selecting a single item.
- `SELECT_MULTI = 1` — Allows selecting multiple items by holding `Ctrl` or `Shift`.
- `SELECT_TOGGLE = 2` — Allows selecting multiple items by toggling them on and off.

## Enum ScrollHintMode

- `SCROLL_HINT_MODE_DISABLED = 0` — Scroll hints will never be shown.
- `SCROLL_HINT_MODE_BOTH = 1` — Scroll hints will be shown at the top and bottom.
- `SCROLL_HINT_MODE_TOP = 2` — Only the top scroll hint will be shown.
- `SCROLL_HINT_MODE_BOTTOM = 3` — Only the bottom scroll hint will be shown.

## Theme items

- `font_color: Color` (color) = `Color(0.65, 0.65, 0.65, 1)`
- `font_disabled_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `font_disabled_hovered_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `font_hovered_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_hovered_selected_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_selected_color: Color` (color) = `Color(1, 1, 1, 1)`
- `guide_color: Color` (color) = `Color(0.7, 0.7, 0.7, 0.25)`
- `scroll_hint_color: Color` (color) = `Color(0, 0, 0, 1)`
- `h_separation: int` (constant) = `4`
- `icon_margin: int` (constant) = `4`
- `line_separation: int` (constant) = `2`
- `outline_size: int` (constant) = `0`
- `scrollbar_h_separation: int` (constant) = `4`
- `scrollbar_margin_bottom: int` (constant) = `-1`
- `scrollbar_margin_left: int` (constant) = `-1`
- `scrollbar_margin_right: int` (constant) = `-1`
- `scrollbar_margin_top: int` (constant) = `-1`
- `v_separation: int` (constant) = `4`
- `font: Font` (font)
- `font_size: int` (font_size)
- `scroll_hint: Texture2D` (icon)
- `focus_sound: AudioStream` (sound)
- `item_hovered_sound: AudioStream` (sound)
- `item_selected_disabled_sound: AudioStream` (sound)
- `item_selected_sound: AudioStream` (sound)
- `cursor: StyleBox` (style)
- `cursor_unfocused: StyleBox` (style)
- `disabled: StyleBox` (style)
- `disabled_hovered: StyleBox` (style)
- `focus: StyleBox` (style)
- `hovered: StyleBox` (style)
- `hovered_selected: StyleBox` (style)
- `hovered_selected_focus: StyleBox` (style)
- `panel: StyleBox` (style)
- `selected: StyleBox` (style)
- `selected_focus: StyleBox` (style)
