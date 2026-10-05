# Tree

**Inherits:** Control

A control used to show a set of internal TreeItems in a hierarchical structure.

A control used to show a set of internal TreeItems in a hierarchical structure. The tree items can be selected, expanded and collapsed. The tree can have multiple columns with custom controls like LineEdits, buttons and popups. It can be useful for structured displays and interactions.

## Properties

- `allow_reselect: bool` = `false` — If `true`, the currently selected cell may be selected again.
- `allow_rmb_select: bool` = `false` — If `true`, a right mouse button click can select items.
- `allow_search: bool` = `true` — If `true`, allows navigating the Tree with letter keys through incremental search.
- `auto_tooltip: bool` = `true` — If `true`, tree items with no tooltip assigned display their text as their tooltip.
- `clip_contents: bool` = `true` — 
- `column_titles_visible: bool` = `false` — If `true`, column titles are visible.
- `columns: int` = `1` — The number of columns.
- `drop_mode_flags: int` = `0` — The drop mode as an OR combination of flags.
- `enable_drag_unfolding: bool` = `true` — If `true`, tree items will unfold when hovered over during a drag-and-drop.
- `enable_recursive_folding: bool` = `true` — If `true`, recursive folding is enabled for this Tree.
- `focus_mode: Control.FocusMode` = `2` — 
- `hide_folding: bool` = `false` — If `true`, the folding arrow is hidden.
- `hide_root: bool` = `false` — If `true`, the tree's root is hidden.
- `scroll_hint_mode: Tree.ScrollHintMode` = `0` — The way which scroll hints (indicators that show that the content can still be scrolled in a certain direction) will be shown.
- `scroll_horizontal_enabled: bool` = `true` — If `true`, enables horizontal scrolling.
- `scroll_vertical_enabled: bool` = `true` — If `true`, enables vertical scrolling.
- `select_mode: Tree.SelectMode` = `0` — Allows single or multiple selection.
- `tile_scroll_hint: bool` = `false` — If `true`, the scroll hint texture will be tiled instead of stretched.

## Methods

- `clear() -> void` — Clears the tree.
- `create_item(parent: TreeItem = null, index: int = -1) -> TreeItem` — Creates an item in the tree and adds it as a child of `parent`, which can be either a valid TreeItem or `null`.
- `deselect_all() -> void` — Deselects all tree items (rows and columns).
- `edit_selected(force_edit: bool = false) -> bool` — Edits the selected tree item as if it was clicked.
- `ensure_cursor_is_visible() -> void` — Makes the currently focused cell visible.
- `get_button_id_at_position(position: Vector2) -> int` *const* — Returns the button ID at `position`, or -1 if no button is there.
- `get_column_at_position(position: Vector2) -> int` *const* — Returns the column index at `position`, or -1 if no item is there.
- `get_column_expand_ratio(column: int) -> int` *const* — Returns the expand ratio assigned to the column.
- `get_column_title(column: int) -> String` *const* — Returns the column's title.
- `get_column_title_alignment(column: int) -> int[HorizontalAlignment]` *const* — Returns the column title alignment.
- `get_column_title_direction(column: int) -> int[Control.TextDirection]` *const* — Returns column title base writing direction.
- `get_column_title_language(column: int) -> String` *const* — Returns column title language code.
- `get_column_title_tooltip_text(column: int) -> String` *const* — Returns the column title's tooltip text.
- `get_column_width(column: int) -> int` *const* — Returns the column's width in pixels.
- `get_custom_drawing_canvas_item() -> RID` *const* — Returns the internal canvas item designated for custom drawing.
- `get_custom_popup_rect() -> Rect2` *const* — Returns the rectangle for custom popups.
- `get_drop_section_at_position(position: Vector2) -> int` *const* — Returns the drop section at `position`, as permitted by enabled `DropModeFlags`. - `-1` if the position is above the item.
- `get_edited() -> TreeItem` *const* — Returns the currently edited item.
- `get_edited_column() -> int` *const* — Returns the column for the currently edited item.
- `get_item_area_rect(item: TreeItem, column: int = -1, button_index: int = -1) -> Rect2` *const* — Returns the rectangle area for the specified TreeItem.
- `get_item_at_position(position: Vector2) -> TreeItem` *const* — Returns the tree item at the specified position (relative to the tree origin position).
- `get_next_selected(from: TreeItem) -> TreeItem` — Returns the next selected TreeItem after the given one, or `null` if the end is reached.
- `get_pressed_button() -> int` *const* — Returns the last pressed button's index.
- `get_root() -> TreeItem` *const* — Returns the tree's root item, or `null` if the tree is empty.
- `get_scroll() -> Vector2` *const* — Returns the current scrolling position.
- `get_selected() -> TreeItem` *const* — Returns the currently focused item, or `null` if no item is focused.
- `get_selected_column() -> int` *const* — Returns the currently focused column, or -1 if no column is focused.
- `is_column_clipping_content(column: int) -> bool` *const* — Returns `true` if the column has enabled clipping (see `set_column_clip_content`).
- `is_column_expanding(column: int) -> bool` *const* — Returns `true` if the column has enabled expanding (see `set_column_expand`).
- `scroll_to_item(item: TreeItem, center_on_item: bool = false) -> void` — Causes the Tree to jump to the specified TreeItem.
- `set_column_clip_content(column: int, enable: bool) -> void` — Allows to enable clipping for column's content, making the content size ignored.
- `set_column_custom_minimum_width(column: int, min_width: int) -> void` — Overrides the calculated minimum width of a column.
- `set_column_expand(column: int, expand: bool) -> void` — If `true`, the column will have the "Expand" flag of Control.
- `set_column_expand_ratio(column: int, ratio: int) -> void` — Sets the relative expand ratio for a column.
- `set_column_title(column: int, title: String) -> void` — Sets the title of a column.
- `set_column_title_alignment(column: int, title_alignment: HorizontalAlignment) -> void` — Sets the column title alignment.
- `set_column_title_direction(column: int, direction: Control.TextDirection) -> void` — Sets column title base writing direction.
- `set_column_title_language(column: int, language: String) -> void` — Sets the language code of the given `column`'s title to `language`.
- `set_column_title_tooltip_text(column: int, tooltip_text: String) -> void` — Sets the column title's tooltip text.
- `set_selected(item: TreeItem, column: int) -> void` — Selects the specified TreeItem and column.

## Signals

- `button_clicked(item: TreeItem, column: int, id: int, mouse_button_index: int)` — Emitted when a button on the tree was pressed (see `TreeItem.add_button`).
- `cell_selected()` — Emitted when a cell is selected.
- `check_propagated_to_item(item: TreeItem, column: int)` — Emitted when `TreeItem.propagate_check` is called.
- `column_title_clicked(column: int, mouse_button_index: int)` — Emitted when a column's title is clicked with either `MOUSE_BUTTON_LEFT` or `MOUSE_BUTTON_RIGHT`.
- `custom_item_clicked(mouse_button_index: int)` — Emitted when an item with `TreeItem.CELL_MODE_CUSTOM` is clicked with a mouse button.
- `custom_popup_edited(arrow_clicked: bool)` — Emitted when a cell with the `TreeItem.CELL_MODE_CUSTOM` is clicked to be edited.
- `empty_clicked(click_position: Vector2, mouse_button_index: int)` — Emitted when a mouse button is clicked in the empty space of the tree.
- `item_activated()` — Emitted when an item is double-clicked, or selected with a `ui_accept` input event (e.g. using `Enter` or `Space` on the keyboard).
- `item_collapsed(item: TreeItem)` — Emitted when an item is expanded or collapsed by clicking on the folding arrow or through code.
- `item_edited()` — Emitted when an item is edited.
- `item_icon_double_clicked()` — Emitted when an item's icon is double-clicked.
- `item_mouse_selected(mouse_position: Vector2, mouse_button_index: int)` — Emitted when an item is selected with a mouse button.
- `item_selected()` — Emitted when an item is selected.
- `multi_selected(item: TreeItem, column: int, selected: bool)` — Emitted instead of `item_selected` if `select_mode` is set to `SELECT_MULTI`.
- `nothing_selected()` — Emitted when a left mouse button click does not select any item.

## Enum SelectMode

- `SELECT_SINGLE = 0` — Allows selection of a single cell at a time.
- `SELECT_ROW = 1` — Allows selection of a single row at a time.
- `SELECT_MULTI = 2` — Allows selection of multiple cells at the same time.

## Enum DropModeFlags

- `DROP_MODE_DISABLED = 0` — Disables all drop sections.
- `DROP_MODE_ON_ITEM = 1` — Enables the "on item" drop section.
- `DROP_MODE_INBETWEEN = 2` — Enables "above item" and "below item" drop sections.

## Enum ScrollHintMode

- `SCROLL_HINT_MODE_DISABLED = 0` — Scroll hints will never be shown.
- `SCROLL_HINT_MODE_BOTH = 1` — Scroll hints will be shown at the top and bottom.
- `SCROLL_HINT_MODE_TOP = 2` — Only the top scroll hint will be shown.
- `SCROLL_HINT_MODE_BOTTOM = 3` — Only the bottom scroll hint will be shown.

## Theme items

- `children_hl_line_color: Color` (color) = `Color(0.27, 0.27, 0.27, 1)`
- `custom_button_font_highlight: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `drop_on_item_color: Color` (color) = `Color(1, 1, 1, 1)`
- `drop_position_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_color: Color` (color) = `Color(0.7, 0.7, 0.7, 1)`
- `font_disabled_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `font_hovered_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_hovered_dimmed_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_hovered_selected_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_selected_color: Color` (color) = `Color(1, 1, 1, 1)`
- `guide_color: Color` (color) = `Color(0.7, 0.7, 0.7, 0.25)`
- `parent_hl_line_color: Color` (color) = `Color(0.27, 0.27, 0.27, 1)`
- `relationship_line_color: Color` (color) = `Color(0.27, 0.27, 0.27, 1)`
- `scroll_hint_color: Color` (color) = `Color(0, 0, 0, 1)`
- `title_button_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `button_margin: int` (constant) = `4`
- `check_h_separation: int` (constant) = `4`
- `children_hl_line_width: int` (constant) = `1`
- `dragging_unfold_wait_msec: int` (constant) = `500`
- `draw_guides: int` (constant) = `1`
- `draw_relationship_lines: int` (constant) = `0`
- `h_separation: int` (constant) = `4`
- `icon_h_separation: int` (constant) = `4`
- `icon_max_width: int` (constant) = `0`
- `inner_item_margin_bottom: int` (constant) = `0`
- `inner_item_margin_left: int` (constant) = `0`
- `inner_item_margin_right: int` (constant) = `0`
- `inner_item_margin_top: int` (constant) = `0`
- `item_margin: int` (constant) = `16`
- `outline_size: int` (constant) = `0`
- `parent_hl_line_margin: int` (constant) = `0`
- `parent_hl_line_width: int` (constant) = `1`
- `relationship_line_width: int` (constant) = `1`
- `scroll_border: int` (constant) = `4`
- `scroll_max_sticky_items: int` (constant) = `0`
- `scroll_speed: int` (constant) = `12`
- `scrollbar_h_separation: int` (constant) = `4`
- `scrollbar_margin_bottom: int` (constant) = `-1`
- `scrollbar_margin_left: int` (constant) = `-1`
- `scrollbar_margin_right: int` (constant) = `-1`
- `scrollbar_margin_top: int` (constant) = `-1`
- `scrollbar_v_separation: int` (constant) = `4`
- `v_separation: int` (constant) = `4`
- `font: Font` (font)
- `title_button_font: Font` (font)
- `font_size: int` (font_size)
- `title_button_font_size: int` (font_size)
- `arrow: Texture2D` (icon)
- `arrow_collapsed: Texture2D` (icon)
- `arrow_collapsed_mirrored: Texture2D` (icon)
- `checked: Texture2D` (icon)
- `checked_disabled: Texture2D` (icon)
- `indeterminate: Texture2D` (icon)
- `indeterminate_disabled: Texture2D` (icon)
- `scroll_hint: Texture2D` (icon)
- `select_arrow: Texture2D` (icon)
- `unchecked: Texture2D` (icon)
- `unchecked_disabled: Texture2D` (icon)
- `updown: Texture2D` (icon)
- `focus_sound: AudioStream` (sound)
- `item_hovered_sound: AudioStream` (sound)
- `item_selected_sound: AudioStream` (sound)
- `button_hover: StyleBox` (style)
- `button_pressed: StyleBox` (style)
- `cursor: StyleBox` (style)
- `cursor_unfocused: StyleBox` (style)
- `custom_button: StyleBox` (style)
- `custom_button_hover: StyleBox` (style)
- `custom_button_pressed: StyleBox` (style)
- `focus: StyleBox` (style)
- `hovered: StyleBox` (style)
- `hovered_dimmed: StyleBox` (style)
- `hovered_selected: StyleBox` (style)
- `hovered_selected_focus: StyleBox` (style)
- `panel: StyleBox` (style)
- `selected: StyleBox` (style)
- `selected_focus: StyleBox` (style)
- `title_button_hover: StyleBox` (style)
- `title_button_normal: StyleBox` (style)
- `title_button_pressed: StyleBox` (style)
