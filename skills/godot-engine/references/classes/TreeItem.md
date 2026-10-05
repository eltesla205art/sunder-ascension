# TreeItem

**Inherits:** Object

An internal control for a single item inside Tree.

A single item of a Tree control. It can contain other TreeItems as children, which allows it to create a hierarchy. It can also contain text and buttons. TreeItem is not a Node, it is internal to the Tree.

## Properties

- `collapsed: bool` — If `true`, the TreeItem is collapsed.
- `custom_minimum_height: int` — The custom minimum height.
- `disable_folding: bool` — If `true`, folding is disabled for this TreeItem.
- `visible: bool` — If `true`, the TreeItem is visible (default).

## Methods

- `add_button(column: int, button: Texture2D, id: int = -1, disabled: bool = false, tooltip_text: String = "", description: String = "") -> void` — Adds a button with Texture2D `button` to the end of the cell at column `column`.
- `add_child(child: TreeItem) -> void` — Adds a previously unparented TreeItem as a direct child of this one.
- `call_recursive(method: StringName) -> void` *vararg* — Calls the `method` on the actual TreeItem and its children recursively.
- `clear_buttons() -> void` — Removes all buttons from all columns of this item.
- `clear_custom_bg_color(column: int) -> void` — Resets the background color for the given column to default.
- `clear_custom_color(column: int) -> void` — Resets the color for the given column to default.
- `create_child(index: int = -1) -> TreeItem` — Creates an item and adds it as a child.
- `deselect(column: int) -> void` — Deselects the given column.
- `erase_button(column: int, button_index: int) -> void` — Removes the button at index `button_index` in column `column`.
- `get_auto_translate_mode(column: int) -> int[Node.AutoTranslateMode]` *const* — Returns the column's auto translate mode.
- `get_autowrap_mode(column: int) -> int[TextServer.AutowrapMode]` *const* — Returns the text autowrap mode in the given `column`.
- `get_autowrap_trim_flags(column: int) -> int[TextServer.LineBreakFlag]` *const* — Returns the autowrap trim flags for the given `column`.
- `get_button(column: int, button_index: int) -> Texture2D` *const* — Returns the Texture2D of the button at index `button_index` in column `column`.
- `get_button_by_id(column: int, id: int) -> int` *const* — Returns the button index if there is a button with ID `id` in column `column`, otherwise returns -1.
- `get_button_color(column: int, id: int) -> Color` *const* — Returns the color of the button with ID `id` in column `column`.
- `get_button_count(column: int) -> int` *const* — Returns the number of buttons in column `column`.
- `get_button_id(column: int, button_index: int) -> int` *const* — Returns the ID for the button at index `button_index` in column `column`.
- `get_button_tooltip_text(column: int, button_index: int) -> String` *const* — Returns the tooltip text for the button at index `button_index` in column `column`.
- `get_cell_mode(column: int) -> int[TreeItem.TreeCellMode]` *const* — Returns the column's cell mode.
- `get_child(index: int) -> TreeItem` — Returns a child item by its `index` (see `get_child_count`).
- `get_child_count() -> int` — Returns the number of child items.
- `get_children() -> TreeItem[]` — Returns an array of references to the item's children.
- `get_custom_bg_color(column: int) -> Color` *const* — Returns the custom background color of column `column`.
- `get_custom_color(column: int) -> Color` *const* — Returns the custom color of column `column`.
- `get_custom_draw_callback(column: int) -> Callable` *const* — Returns the custom callback of column `column`.
- `get_custom_font(column: int) -> Font` *const* — Returns custom font used to draw text in the column `column`.
- `get_custom_font_size(column: int) -> int` *const* — Returns custom font size used to draw text in the column `column`.
- `get_custom_stylebox(column: int) -> StyleBox` *const* — Returns the given column's custom StyleBox used to draw the background.
- `get_description(column: int) -> String` *const* — Returns the given column's description for assistive apps.
- `get_expand_right(column: int) -> bool` *const* — Returns `true` if `expand_right` is set.
- `get_first_child() -> TreeItem` *const* — Returns the TreeItem's first child.
- `get_icon(column: int) -> Texture2D` *const* — Returns the given column's icon Texture2D.
- `get_icon_max_width(column: int) -> int` *const* — Returns the maximum allowed width of the icon in the given `column`.
- `get_icon_modulate(column: int) -> Color` *const* — Returns the Color modulating the column's icon.
- `get_icon_overlay(column: int) -> Texture2D` *const* — Returns the given column's icon overlay Texture2D.
- `get_icon_region(column: int) -> Rect2` *const* — Returns the icon Texture2D region as Rect2.
- `get_index() -> int` — Returns the node's order in the tree.
- `get_language(column: int) -> String` *const* — Returns item's text language code.
- `get_metadata(column: int) -> Variant` *const* — Returns the metadata value that was set for the given column using `set_metadata`.
- `get_next() -> TreeItem` *const* — Returns the next sibling TreeItem in the tree or a `null` object if there is none.
- `get_next_in_tree(wrap: bool = false) -> TreeItem` — Returns the next TreeItem in the tree (in the context of a depth-first search) or a `null` object if there is none.
- `get_next_visible(wrap: bool = false) -> TreeItem` — Returns the next visible TreeItem in the tree (in the context of a depth-first search) or a `null` object if there is none.
- `get_parent() -> TreeItem` *const* — Returns the parent TreeItem or a `null` object if there is none.
- `get_prev() -> TreeItem` — Returns the previous sibling TreeItem in the tree or a `null` object if there is none.
- `get_prev_in_tree(wrap: bool = false) -> TreeItem` — Returns the previous TreeItem in the tree (in the context of a depth-first search) or a `null` object if there is none.
- `get_prev_visible(wrap: bool = false) -> TreeItem` — Returns the previous visible sibling TreeItem in the tree (in the context of a depth-first search) or a `null` object if there is none.
- `get_range(column: int) -> float` *const* — Returns the value of a `CELL_MODE_RANGE` column.
- `get_range_config(column: int) -> Dictionary` — Returns a dictionary containing the range parameters for a given column.
- `get_structured_text_bidi_override(column: int) -> int[TextServer.StructuredTextParser]` *const* — Returns the BiDi algorithm override set for this cell.
- `get_structured_text_bidi_override_options(column: int) -> Array` *const* — Returns the additional BiDi options set for this cell.
- `get_suffix(column: int) -> String` *const* — Gets the suffix string shown after the column value.
- `get_text(column: int) -> String` *const* — Returns the given column's text.
- `get_text_alignment(column: int) -> int[HorizontalAlignment]` *const* — Returns the given column's text alignment.
- `get_text_direction(column: int) -> int[Control.TextDirection]` *const* — Returns item's text base writing direction.
- `get_text_overrun_behavior(column: int) -> int[TextServer.OverrunBehavior]` *const* — Returns the clipping behavior when the text exceeds the item's bounding rectangle in the given `column`.
- `get_tooltip_text(column: int) -> String` *const* — Returns the given column's tooltip text.
- `get_tree() -> Tree` *const* — Returns the Tree that owns this TreeItem.
- `is_accepting_children() -> bool` *const* — Returns `true` if this TreeItem is allowed to accept children.
- `is_any_collapsed(only_visible: bool = false) -> bool` — Returns `true` if this TreeItem, or any of its descendants, is collapsed.
- `is_button_disabled(column: int, button_index: int) -> bool` *const* — Returns `true` if the button at index `button_index` for the given `column` is disabled.
- `is_checked(column: int) -> bool` *const* — Returns `true` if the given `column` is checked.
- `is_custom_set_as_button(column: int) -> bool` *const* — Returns `true` if the cell was made into a button with `set_custom_as_button`.
- `is_edit_multiline(column: int) -> bool` *const* — Returns `true` if the given `column` is multiline editable.
- `is_editable(column: int) -> bool` — Returns `true` if the given `column` is editable.
- `is_indeterminate(column: int) -> bool` *const* — Returns `true` if the given `column` is indeterminate.
- `is_selectable(column: int) -> bool` *const* — Returns `true` if the given `column` is selectable.
- `is_selected(column: int) -> bool` — Returns `true` if the given `column` is selected.
- `is_visible_in_tree() -> bool` *const* — Returns `true` if `visible` is `true` and all its ancestors are also visible.
- `move_after(item: TreeItem) -> void` — Moves this TreeItem right after the given `item`.
- `move_before(item: TreeItem) -> void` — Moves this TreeItem right before the given `item`.
- `propagate_check(column: int, emit_signal: bool = true) -> void` — Propagates this item's checked status to its children and parents for the given `column`.
- `remove_child(child: TreeItem) -> void` — Removes the given child TreeItem and all its children from the Tree.
- `select(column: int, set_as_cursor: bool = true) -> void` — Selects the given `column`.
- `set_accept_children(allowed: bool) -> void` — Sets TreeItem's ability to accept children.
- `set_auto_translate_mode(column: int, mode: Node.AutoTranslateMode) -> void` — Sets the given column's auto translate mode to `mode`.
- `set_autowrap_mode(column: int, autowrap_mode: TextServer.AutowrapMode) -> void` — Sets the autowrap mode in the given `column`.
- `set_autowrap_trim_flags(column: int, flags: TextServer.LineBreakFlag) -> void` — Sets the autowrap trim flags for the given `column`.
- `set_button(column: int, button_index: int, button: Texture2D) -> void` — Sets the given column's button Texture2D at index `button_index` to `button`.
- `set_button_color(column: int, button_index: int, color: Color) -> void` — Sets the given column's button color at index `button_index` to `color`.
- `set_button_description(column: int, button_index: int, description: String) -> void` — Sets the given column's button description at index `button_index` for assistive apps.
- `set_button_disabled(column: int, button_index: int, disabled: bool) -> void` — If `true`, disables the button at index `button_index` in the given `column`.
- `set_button_tooltip_text(column: int, button_index: int, tooltip: String) -> void` — Sets the tooltip text for the button at index `button_index` in the given `column`.
- `set_cell_mode(column: int, mode: TreeItem.TreeCellMode) -> void` — Sets the given column's cell mode to `mode`.
- `set_checked(column: int, checked: bool) -> void` — If `checked` is `true`, the given `column` is checked.
- `set_collapsed_recursive(enable: bool) -> void` — Collapses or uncollapses this TreeItem and all the descendants of this item.
- `set_custom_as_button(column: int, enable: bool) -> void` — Makes a cell with `CELL_MODE_CUSTOM` display as a non-flat button with a StyleBox.
- `set_custom_bg_color(column: int, color: Color, just_outline: bool = false) -> void` — Sets the given column's custom background color and whether to just use it as an outline.
- `set_custom_color(column: int, color: Color) -> void` — Sets the given column's custom color.
- `set_custom_draw(column: int, object: Object, callback: StringName) -> void` *(deprecated)* — Sets the given column's custom draw callback to the `callback` method on `object`.
- `set_custom_draw_callback(column: int, callback: Callable) -> void` — Sets the given column's custom draw callback.
- `set_custom_font(column: int, font: Font) -> void` — Sets custom font used to draw text in the given `column`.
- `set_custom_font_size(column: int, font_size: int) -> void` — Sets custom font size used to draw text in the given `column`.
- `set_custom_stylebox(column: int, stylebox: StyleBox) -> void` — Sets the given column's custom StyleBox used to draw the background.
- `set_description(column: int, description: String) -> void` — Sets the given column's description for assistive apps.
- `set_edit_multiline(column: int, multiline: bool) -> void` — If `multiline` is `true`, the given `column` is multiline editable.
- `set_editable(column: int, enabled: bool) -> void` — If `enabled` is `true`, the given `column` is editable.
- `set_expand_right(column: int, enable: bool) -> void` — If `enable` is `true`, the given `column` is expanded to the right.
- `set_icon(column: int, texture: Texture2D) -> void` — Sets the given cell's icon Texture2D.
- `set_icon_max_width(column: int, width: int) -> void` — Sets the maximum allowed width of the icon in the given `column`.
- `set_icon_modulate(column: int, modulate: Color) -> void` — Modulates the given column's icon with `modulate`.
- `set_icon_overlay(column: int, texture: Texture2D) -> void` — Sets the given cell's icon overlay Texture2D.
- `set_icon_region(column: int, region: Rect2) -> void` — Sets the given column's icon's texture region.
- `set_indeterminate(column: int, indeterminate: bool) -> void` — If `indeterminate` is `true`, the given `column` is marked indeterminate.
- `set_language(column: int, language: String) -> void` — Sets the language code of the given `column`'s text to `language`.
- `set_metadata(column: int, meta: Variant) -> void` — Sets the metadata value for the given column, which can be retrieved later using `get_metadata`.
- `set_range(column: int, value: float) -> void` — Sets the value of a `CELL_MODE_RANGE` column.
- `set_range_config(column: int, min: float, max: float, step: float, expr: bool = false) -> void` — Sets the range of accepted values for a column.
- `set_selectable(column: int, selectable: bool) -> void` — If `selectable` is `true`, the given `column` is selectable.
- `set_structured_text_bidi_override(column: int, parser: TextServer.StructuredTextParser) -> void` — Set BiDi algorithm override for the structured text.
- `set_structured_text_bidi_override_options(column: int, args: Array) -> void` — Set additional options for BiDi override.
- `set_suffix(column: int, text: String) -> void` — Sets a string to be shown after a column's value (for example, a unit abbreviation).
- `set_text(column: int, text: String) -> void` — Sets the given column's text value.
- `set_text_alignment(column: int, text_alignment: HorizontalAlignment) -> void` — Sets the given column's text alignment to `text_alignment`.
- `set_text_direction(column: int, direction: Control.TextDirection) -> void` — Sets item's text base writing direction.
- `set_text_overrun_behavior(column: int, overrun_behavior: TextServer.OverrunBehavior) -> void` — Sets the clipping behavior when the text exceeds the item's bounding rectangle in the given `column`.
- `set_tooltip_text(column: int, tooltip: String) -> void` — Sets the given column's tooltip text.
- `uncollapse_tree() -> void` — Uncollapses all TreeItems necessary to reveal this TreeItem, i.e. all ancestor TreeItems.

## Enum TreeCellMode

- `CELL_MODE_STRING = 0` — Cell shows a string label, optionally with an icon.
- `CELL_MODE_CHECK = 1` — Cell shows a checkbox, optionally with text and an icon.
- `CELL_MODE_RANGE = 2` — Cell shows a numeric range.
- `CELL_MODE_ICON = 3` — Cell shows an icon.
- `CELL_MODE_CUSTOM = 4` — Cell shows as a clickable button.
