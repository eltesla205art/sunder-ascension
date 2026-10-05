# TextEdit

**Inherits:** Control

A multiline text editor.

A multiline text editor. It also has limited facilities for editing code, such as syntax highlighting support. For more advanced facilities for editing code, see CodeEdit. While entering text, it is possible to insert special characters using Unicode, OEM or Windows alt codes: - To enter Unicode codepoints, hold `Alt` and type the codepoint on the numpad.

## Properties

- `autowrap_mode: TextServer.AutowrapMode` = `3` — If `wrap_mode` is set to `LINE_WRAPPING_BOUNDARY`, sets text wrapping mode.
- `backspace_deletes_composite_character_enabled: bool` = `false` — If `true` and `caret_mid_grapheme` is `false`, backspace deletes an entire composite character such as ❤️‍🩹, instead of deleting part of the composite character.
- `caret_blink: bool` = `false` — If `true`, makes the caret blink.
- `caret_blink_interval: float` = `0.65` — The interval at which the caret blinks (in seconds).
- `caret_draw_when_editable_disabled: bool` = `false` — If `true`, caret will be visible when `editable` is disabled.
- `caret_mid_grapheme: bool` = `false` — Allow moving caret, selecting and removing the individual composite character components.
- `caret_move_on_right_click: bool` = `true` — If `true`, a right-click moves the caret at the mouse position before displaying the context menu.
- `caret_multiple: bool` = `true` — If `true`, multiple carets are allowed.
- `caret_type: TextEdit.CaretType` = `0` — Set the type of caret to draw.
- `context_menu_enabled: bool` = `true` — If `true`, a right-click displays the context menu.
- `custom_word_separators: String` = `""` — The characters to consider as word delimiters if `use_custom_word_separators` is `true`.
- `deselect_on_focus_loss_enabled: bool` = `true` — If `true`, the selected text will be deselected when focus is lost.
- `drag_and_drop_selection_enabled: bool` = `true` — If `true`, allow drag and drop of selected text.
- `draw_control_chars: bool` = `false` — If `true`, control characters are displayed.
- `draw_spaces: bool` = `false` — If `true`, the "space" character will have a visible representation.
- `draw_tabs: bool` = `false` — If `true`, the "tab" character will have a visible representation.
- `editable: bool` = `true` — If `false`, existing text cannot be modified and new text cannot be added.
- `emoji_menu_enabled: bool` = `true` — If `true`, "Emoji and Symbols" menu is enabled.
- `empty_selection_clipboard_enabled: bool` = `true` — If `true`, copying or cutting without a selection is performed on all lines with a caret.
- `focus_mode: Control.FocusMode` = `2` — 
- `highlight_all_occurrences: bool` = `false` — If `true`, all occurrences of the selected text will be highlighted.
- `highlight_current_line: bool` = `false` — If `true`, the line containing the cursor is highlighted.
- `indent_wrapped_lines: bool` = `false` — If `true`, all wrapped lines are indented to the same amount as the unwrapped line.
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `middle_mouse_paste_enabled: bool` = `true` — If `false`, using middle mouse button to paste clipboard will be disabled.
- `minimap_draw: bool` = `false` — If `true`, a minimap is shown, providing an outline of your source code.
- `minimap_width: int` = `80` — The width, in pixels, of the minimap.
- `mouse_default_cursor_shape: Control.CursorShape` = `1` — 
- `placeholder_text: String` = `""` — Text shown when the TextEdit is empty.
- `scroll_fit_content_height: bool` = `false` — If `true`, TextEdit fits its minimum height to the number of visible lines instead of scrolling vertically.
- `scroll_fit_content_width: bool` = `false` — If `true`, TextEdit fits its minimum width to the widest line instead of scrolling horizontally.
- `scroll_horizontal: int` = `0` — If there is a horizontal scrollbar, this determines the current horizontal scroll value in pixels.
- `scroll_past_end_of_file: bool` = `false` — Allow scrolling past the last line into "virtual" space.
- `scroll_smooth: bool` = `false` — Scroll smoothly over the text rather than jumping to the next location.
- `scroll_v_scroll_speed: float` = `80.0` — Sets the scroll speed with the minimap or when `scroll_smooth` is enabled.
- `scroll_vertical: float` = `0.0` — If there is a vertical scrollbar, this determines the current vertical scroll value in line numbers, starting at 0 for the top line.
- `selecting_enabled: bool` = `true` — If `true`, text can be selected.
- `selection_handle_enabled: bool` = `true` — If `true`, enables the handles used for text selection.
- `shortcut_keys_enabled: bool` = `true` — If `true`, shortcut keys for context menu items are enabled, even if the context menu is disabled.
- `structured_text_bidi_override: TextServer.StructuredTextParser` = `0` — Set BiDi algorithm override for the structured text.
- `structured_text_bidi_override_options: Array` = `[]` — Set additional options for BiDi override.
- `syntax_highlighter: SyntaxHighlighter` — The syntax highlighter to use.
- `tab_input_mode: bool` = `true` — If `true`, `ProjectSettings.input/ui_text_indent` input `Tab` character, otherwise it moves keyboard focus to the next Control in the scene.
- `text: String` = `""` — String value of the TextEdit.
- `text_direction: Control.TextDirection` = `0` — Base text writing direction.
- `use_custom_word_separators: bool` = `false` — If `false`, using `Ctrl + Left` or `Ctrl + Right` (`Cmd + Left` or `Cmd + Right` on macOS) bindings will use the behavior of `use_default_word_separators`.
- `use_default_word_separators: bool` = `true` — If `false`, using `Ctrl + Left` or `Ctrl + Right` (`Cmd + Left` or `Cmd + Right` on macOS) bindings will stop moving caret only if a space or punctuation is detected.
- `virtual_keyboard_enabled: bool` = `true` — If `true`, the native virtual keyboard is enabled on platforms that support it.
- `virtual_keyboard_show_on_focus: bool` = `true` — If `true`, the native virtual keyboard is shown on focus events on platforms that support it.
- `wrap_mode: TextEdit.LineWrappingMode` = `0` — Sets the line wrapping mode to use.

## Methods

- `_backspace(caret_index: int) -> void` *virtual* — Override this method to define what happens when the user presses the backspace key.
- `_copy(caret_index: int) -> void` *virtual* — Override this method to define what happens when the user performs a copy operation.
- `_cut(caret_index: int) -> void` *virtual* — Override this method to define what happens when the user performs a cut operation.
- `_handle_unicode_input(unicode_char: int, caret_index: int) -> void` *virtual* — Override this method to define what happens when the user types in the provided key `unicode_char`.
- `_paste(caret_index: int) -> void` *virtual* — Override this method to define what happens when the user performs a paste operation.
- `_paste_primary_clipboard(caret_index: int) -> void` *virtual* — Override this method to define what happens when the user performs a paste operation with middle mouse button.
- `add_caret(line: int, column: int) -> int` — Adds a new caret at the given location.
- `add_caret_at_carets(below: bool) -> void` — Adds an additional caret above or below every caret.
- `add_gutter(at: int = -1) -> void` — Register a new gutter to this TextEdit.
- `add_selection_for_next_occurrence() -> void` — Adds a selection and a caret for the next occurrence of the current selection.
- `adjust_carets_after_edit(caret: int, from_line: int, from_col: int, to_line: int, to_col: int) -> void` *(deprecated)* — This method does nothing.
- `adjust_viewport_to_caret(caret_index: int = 0) -> void` — Adjust the viewport so the caret is visible.
- `apply_ime() -> void` — Applies text from the Input Method Editor (IME) to each caret and closes the IME if it is open.
- `backspace(caret_index: int = -1) -> void` — Called when the user presses the backspace key.
- `begin_complex_operation() -> void` — Starts a multipart edit.
- `begin_multicaret_edit() -> void` — Starts an edit for multiple carets.
- `cancel_ime() -> void` — Closes the Input Method Editor (IME) if it is open.
- `center_viewport_to_caret(caret_index: int = 0) -> void` — Centers the viewport on the line the editing caret is at.
- `clear() -> void` — Clears all text and related state.
- `clear_undo_history() -> void` — Clears the undo history.
- `collapse_carets(from_line: int, from_column: int, to_line: int, to_column: int, inclusive: bool = false) -> void` — Collapse all carets in the given range to the `from_line` and `from_column` position.
- `copy(caret_index: int = -1) -> void` — Copies the current text selection.
- `cut(caret_index: int = -1) -> void` — Cuts the current selection.
- `delete_selection(caret_index: int = -1) -> void` — Deletes the selected text.
- `deselect(caret_index: int = -1) -> void` — Deselects the current selection.
- `end_action() -> void` — Marks the end of steps in the current action started with `start_action`.
- `end_complex_operation() -> void` — Ends a multipart edit, started with `begin_complex_operation`.
- `end_multicaret_edit() -> void` — Ends an edit for multiple carets, that was started with `begin_multicaret_edit`.
- `get_caret_column(caret_index: int = 0) -> int` *const* — Returns the column the editing caret is at.
- `get_caret_count() -> int` *const* — Returns the number of carets in this TextEdit.
- `get_caret_draw_pos(caret_index: int = 0) -> Vector2` *const* — Returns the caret pixel draw position.
- `get_caret_index_edit_order() -> PackedInt32Array` *(deprecated)* — Returns a list of caret indexes in their edit order, this done from bottom to top.
- `get_caret_line(caret_index: int = 0) -> int` *const* — Returns the line the editing caret is on.
- `get_caret_wrap_index(caret_index: int = 0) -> int` *const* — Returns the wrap index the editing caret is on.
- `get_first_non_whitespace_column(line: int) -> int` *const* — Returns the first column containing a non-whitespace character on the given line.
- `get_first_visible_line() -> int` *const* — Returns the first visible line.
- `get_gutter_count() -> int` *const* — Returns the number of gutters registered.
- `get_gutter_name(gutter: int) -> String` *const* — Returns the name of the gutter at the given index.
- `get_gutter_type(gutter: int) -> int[TextEdit.GutterType]` *const* — Returns the type of the gutter at the given index.
- `get_gutter_width(gutter: int) -> int` *const* — Returns the width of the gutter at the given index.
- `get_h_scroll_bar() -> HScrollBar` *const* — Returns the HScrollBar used by TextEdit.
- `get_indent_level(line: int) -> int` *const* — Returns the indent level of the given line.
- `get_last_full_visible_line() -> int` *const* — Returns the last visible line.
- `get_last_full_visible_line_wrap_index() -> int` *const* — Returns the last visible wrap index of the last visible line.
- `get_last_unhidden_line() -> int` *const* — Returns the last unhidden line in the entire TextEdit.
- `get_line(line: int) -> String` *const* — Returns the text of a specific line.
- `get_line_background_color(line: int) -> Color` *const* — Returns the custom background color of the given line.
- `get_line_column_at_pos(position: Vector2i, clamp_line: bool = true, clamp_column: bool = true) -> Vector2i` *const* — Returns the line and column at the given position.
- `get_line_count() -> int` *const* — Returns the number of lines in the text.
- `get_line_gutter_icon(line: int, gutter: int) -> Texture2D` *const* — Returns the icon currently in `gutter` at `line`.
- `get_line_gutter_item_color(line: int, gutter: int) -> Color` *const* — Returns the color currently in `gutter` at `line`.
- `get_line_gutter_metadata(line: int, gutter: int) -> Variant` *const* — Returns the metadata currently in `gutter` at `line`.
- `get_line_gutter_text(line: int, gutter: int) -> String` *const* — Returns the text currently in `gutter` at `line`.
- `get_line_height() -> int` *const* — Returns the maximum value of the line height among all lines.
- `get_line_ranges_from_carets(only_selections: bool = false, merge_adjacent: bool = true) -> Vector2i[]` *const* — Returns an Array of line ranges where `x` is the first line and `y` is the last line.
- `get_line_width(line: int, wrap_index: int = -1) -> int` *const* — Returns the width in pixels of the `wrap_index` on `line`.
- `get_line_with_ime(line: int) -> String` *const* — Returns line text as it is currently displayed, including IME composition string.
- `get_line_wrap_count(line: int) -> int` *const* — Returns the number of times the given line is wrapped.
- `get_line_wrap_index_at_column(line: int, column: int) -> int` *const* — Returns the wrap index of the given column on the given line.
- `get_line_wrapped_text(line: int) -> PackedStringArray` *const* — Returns an array of Strings representing each wrapped index.
- `get_local_mouse_pos() -> Vector2` *const* — Returns the local mouse position adjusted for the text direction.
- `get_menu() -> PopupMenu` *const* — Returns the PopupMenu of this TextEdit.
- `get_minimap_line_at_pos(position: Vector2i) -> int` *const* — Returns the equivalent minimap line at `position`.
- `get_minimap_visible_lines() -> int` *const* — Returns the number of lines that may be drawn on the minimap.
- `get_next_composite_character_column(line: int, column: int) -> int` *const* — Returns the correct column at the end of a composite character like ❤️‍🩹 (mending heart; Unicode: `U+2764 U+FE0F U+200D U+1FA79`) which is comprised of more than one Unicode code point, if the caret is at the start of the composite character.
- `get_next_visible_line_index_offset_from(line: int, wrap_index: int, visible_amount: int) -> Vector2i` *const* — Similar to `get_next_visible_line_offset_from`, but takes into account the line wrap indexes.
- `get_next_visible_line_offset_from(line: int, visible_amount: int) -> int` *const* — Returns the count to the next visible line from `line` to `line + visible_amount`.
- `get_pos_at_line_column(line: int, column: int) -> Vector2i` *const* — Returns the local position for the given `line` and `column`.
- `get_previous_composite_character_column(line: int, column: int) -> int` *const* — Returns the correct column at the start of a composite character like ❤️‍🩹 (mending heart; Unicode: `U+2764 U+FE0F U+200D U+1FA79`) which is comprised of more than one Unicode code point, if the caret is at the end of the composite character.
- `get_rect_at_line_column(line: int, column: int) -> Rect2i` *const* — Returns the local position and size for the grapheme at the given `line` and `column`.
- `get_saved_version() -> int` *const* — Returns the last tagged saved version from `tag_saved_version`.
- `get_scroll_pos_for_line(line: int, wrap_index: int = 0) -> float` *const* — Returns the scroll position for `wrap_index` of `line`.
- `get_selected_text(caret_index: int = -1) -> String` — Returns the text inside the selection of a caret, or all the carets if `caret_index` is its default value `-1`.
- `get_selection_at_line_column(line: int, column: int, include_edges: bool = true, only_selections: bool = true) -> int` *const* — Returns the caret index of the selection at the given `line` and `column`, or `-1` if there is none.
- `get_selection_column(caret_index: int = 0) -> int` *const* *(deprecated)* — Returns the original start column of the selection.
- `get_selection_from_column(caret_index: int = 0) -> int` *const* — Returns the selection begin column.
- `get_selection_from_line(caret_index: int = 0) -> int` *const* — Returns the selection begin line.
- `get_selection_line(caret_index: int = 0) -> int` *const* *(deprecated)* — Returns the original start line of the selection.
- `get_selection_mode() -> int[TextEdit.SelectionMode]` *const* — Returns the current selection mode.
- `get_selection_origin_column(caret_index: int = 0) -> int` *const* — Returns the origin column of the selection.
- `get_selection_origin_line(caret_index: int = 0) -> int` *const* — Returns the origin line of the selection.
- `get_selection_to_column(caret_index: int = 0) -> int` *const* — Returns the selection end column.
- `get_selection_to_line(caret_index: int = 0) -> int` *const* — Returns the selection end line.
- `get_sorted_carets(include_ignored_carets: bool = false) -> PackedInt32Array` *const* — Returns the carets sorted by selection beginning from lowest line and column to highest (from top to bottom of text).
- `get_tab_size() -> int` *const* — Returns the TextEdit's tab size.
- `get_total_gutter_width() -> int` *const* — Returns the total width of all gutters and internal padding.
- `get_total_visible_line_count() -> int` *const* — Returns the total number of lines in the text.
- `get_v_scroll_bar() -> VScrollBar` *const* — Returns the VScrollBar of the TextEdit.
- `get_version() -> int` *const* — Returns the current version of the TextEdit.
- `get_visible_line_count() -> int` *const* — Returns the number of lines that can visually fit, rounded down, based on this control's height.
- `get_visible_line_count_in_range(from_line: int, to_line: int) -> int` *const* — Returns the total number of lines between `from_line` and `to_line` (inclusive) in the text.
- `get_word_at_pos(position: Vector2) -> String` *const* — Returns the word at `position` (in pixels).
- `get_word_under_caret(caret_index: int = -1) -> String` *const* — Returns a String text with the word under the caret's location.
- `has_ime_text() -> bool` *const* — Returns `true` if the user has text in the Input Method Editor (IME).
- `has_redo() -> bool` *const* — Returns `true` if a "redo" action is available.
- `has_selection(caret_index: int = -1) -> bool` *const* — Returns `true` if the user has selected text.
- `has_undo() -> bool` *const* — Returns `true` if an "undo" action is available.
- `insert_line_at(line: int, text: String) -> void` — Inserts a new line with `text` at `line`.
- `insert_text(text: String, line: int, column: int, before_selection_begin: bool = true, before_selection_end: bool = false) -> void` — Inserts the `text` at `line` and `column`.
- `insert_text_at_caret(text: String, caret_index: int = -1) -> void` — Insert the specified text at the caret position.
- `is_caret_after_selection_origin(caret_index: int = 0) -> bool` *const* — Returns `true` if the caret of the selection is after the selection origin.
- `is_caret_visible(caret_index: int = 0) -> bool` *const* — Returns `true` if the caret is visible, `false` otherwise.
- `is_dragging_cursor() -> bool` *const* — Returns `true` if the user is dragging their mouse for scrolling, selecting, or text dragging.
- `is_gutter_clickable(gutter: int) -> bool` *const* — Returns `true` if the gutter at the given index is clickable.
- `is_gutter_drawn(gutter: int) -> bool` *const* — Returns `true` if the gutter at the given index is currently drawn.
- `is_gutter_overwritable(gutter: int) -> bool` *const* — Returns `true` if the gutter at the given index is overwritable.
- `is_in_mulitcaret_edit() -> bool` *const* — Returns `true` if a `begin_multicaret_edit` has been called and `end_multicaret_edit` has not yet been called.
- `is_line_gutter_clickable(line: int, gutter: int) -> bool` *const* — Returns `true` if the gutter at the given index on the given line is clickable.
- `is_line_in_viewport(line: int) -> bool` *const* — Returns `true` if the given line is within the scope of the scrollable area of the viewport.
- `is_line_wrapped(line: int) -> bool` *const* — Returns if the given line is wrapped.
- `is_menu_visible() -> bool` *const* — Returns `true` if the menu is visible.
- `is_mouse_over_selection(edges: bool, caret_index: int = -1) -> bool` *const* — Returns `true` if the mouse is over a selection.
- `is_overtype_mode_enabled() -> bool` *const* — Returns `true` if overtype mode is enabled.
- `menu_option(option: int) -> void` — Executes a given action as defined in the `MenuItems` enum.
- `merge_gutters(from_line: int, to_line: int) -> void` — Merge the gutters from `from_line` into `to_line`.
- `merge_overlapping_carets() -> void` — Merges any overlapping carets.
- `multicaret_edit_ignore_caret(caret_index: int) -> bool` *const* — Returns `true` if the given `caret_index` should be ignored as part of a multicaret edit.
- `paste(caret_index: int = -1) -> void` — Paste at the current location.
- `paste_primary_clipboard(caret_index: int = -1) -> void` — Pastes the primary clipboard.
- `redo() -> void` — Perform redo operation.
- `remove_caret(caret: int) -> void` — Removes the given caret index.
- `remove_gutter(gutter: int) -> void` — Removes the gutter at the given index.
- `remove_line_at(line: int, move_carets_down: bool = true) -> void` — Removes the line of text at `line`.
- `remove_secondary_carets() -> void` — Removes all additional carets.
- `remove_text(from_line: int, from_column: int, to_line: int, to_column: int) -> void` — Removes text between the given positions.
- `search(text: String, flags: int, from_line: int, from_column: int) -> Vector2i` *const* — Perform a search inside the text.
- `select(origin_line: int, origin_column: int, caret_line: int, caret_column: int, caret_index: int = 0) -> void` — Selects text from `origin_line` and `origin_column` to `caret_line` and `caret_column` for the given `caret_index`.
- `select_all() -> void` — Select all the text.
- `select_word_under_caret(caret_index: int = -1) -> void` — Selects the word under the caret.
- `set_caret_column(column: int, adjust_viewport: bool = true, caret_index: int = 0) -> void` — Moves the caret to the specified `column` index.
- `set_caret_line(line: int, adjust_viewport: bool = true, can_be_hidden: bool = true, wrap_index: int = 0, caret_index: int = 0) -> void` — Moves the caret to the specified `line` index.
- `set_gutter_clickable(gutter: int, clickable: bool) -> void` — If `true`, the mouse cursor will change to a pointing hand (`Control.CURSOR_POINTING_HAND`) when hovering over the gutter at the given index.
- `set_gutter_custom_draw(column: int, draw_callback: Callable) -> void` — Set a custom draw callback for the gutter at the given index.
- `set_gutter_draw(gutter: int, draw: bool) -> void` — If `true`, the gutter at the given index is drawn.
- `set_gutter_name(gutter: int, name: String) -> void` — Sets the name of the gutter at the given index.
- `set_gutter_overwritable(gutter: int, overwritable: bool) -> void` — If `true`, the line data of the gutter at the given index can be overridden when using `merge_gutters`.
- `set_gutter_type(gutter: int, type: TextEdit.GutterType) -> void` — Sets the type of gutter at the given index.
- `set_gutter_width(gutter: int, width: int) -> void` — Set the width of the gutter at the given index.
- `set_line(line: int, new_text: String) -> void` — Sets the text for a specific `line`.
- `set_line_as_center_visible(line: int, wrap_index: int = 0) -> void` — Positions the `wrap_index` of `line` at the center of the viewport.
- `set_line_as_first_visible(line: int, wrap_index: int = 0) -> void` — Positions the `wrap_index` of `line` at the top of the viewport.
- `set_line_as_last_visible(line: int, wrap_index: int = 0) -> void` — Positions the `wrap_index` of `line` at the bottom of the viewport.
- `set_line_background_color(line: int, color: Color) -> void` — Sets the custom background color of the given line.
- `set_line_gutter_clickable(line: int, gutter: int, clickable: bool) -> void` — If `clickable` is `true`, makes the `gutter` on the given `line` clickable.
- `set_line_gutter_icon(line: int, gutter: int, icon: Texture2D) -> void` — Sets the icon for `gutter` on `line` to `icon`.
- `set_line_gutter_item_color(line: int, gutter: int, color: Color) -> void` — Sets the color for `gutter` on `line` to `color`.
- `set_line_gutter_metadata(line: int, gutter: int, metadata: Variant) -> void` — Sets the metadata for `gutter` on `line` to `metadata`.
- `set_line_gutter_text(line: int, gutter: int, text: String) -> void` — Sets the text for `gutter` on `line` to `text`.
- `set_overtype_mode_enabled(enabled: bool) -> void` — If `true`, enables overtype mode.
- `set_search_flags(flags: int) -> void` — Sets the search `flags`.
- `set_search_text(search_text: String) -> void` — Sets the search text.
- `set_selection_mode(mode: TextEdit.SelectionMode) -> void` — Sets the current selection mode.
- `set_selection_origin_column(column: int, caret_index: int = 0) -> void` — Sets the selection origin column to the `column` for the given `caret_index`.
- `set_selection_origin_line(line: int, can_be_hidden: bool = true, wrap_index: int = -1, caret_index: int = 0) -> void` — Sets the selection origin line to the `line` for the given `caret_index`.
- `set_tab_size(size: int) -> void` — Sets the tab size for the TextEdit to use.
- `set_tooltip_request_func(callback: Callable) -> void` — Provide custom tooltip text.
- `skip_selection_for_next_occurrence() -> void` — Moves a selection and a caret for the next occurrence of the current selection.
- `start_action(action: TextEdit.EditAction) -> void` — Starts an action, will end the current action if `action` is different.
- `swap_lines(from_line: int, to_line: int) -> void` — Swaps the two lines.
- `tag_saved_version() -> void` — Tag the current version as saved.
- `undo() -> void` — Perform undo operation.

## Signals

- `caret_changed()` — Emitted when any caret changes position.
- `gutter_added()` — Emitted when a gutter is added.
- `gutter_clicked(line: int, gutter: int)` — Emitted when a gutter is clicked.
- `gutter_removed()` — Emitted when a gutter is removed.
- `lines_edited_from(from_line: int, to_line: int)` — Emitted immediately when the text changes.
- `text_changed()` — Emitted when the text changes.
- `text_set()` — Emitted when `clear` is called or `text` is set.

## Enum MenuItems

- `MENU_CUT = 0` — Cuts (copies and clears) the selected text.
- `MENU_COPY = 1` — Copies the selected text.
- `MENU_PASTE = 2` — Pastes the clipboard text over the selected text (or at the cursor's position).
- `MENU_CLEAR = 3` — Erases the whole TextEdit text.
- `MENU_SELECT_ALL = 4` — Selects the whole TextEdit text.
- `MENU_UNDO = 5` — Undoes the previous action.
- `MENU_REDO = 6` — Redoes the previous action.
- `MENU_SUBMENU_TEXT_DIR = 7` — ID of "Text Writing Direction" submenu.
- `MENU_DIR_INHERITED = 8` — Sets text direction to inherited.
- `MENU_DIR_AUTO = 9` — Sets text direction to automatic.
- `MENU_DIR_LTR = 10` — Sets text direction to left-to-right.
- `MENU_DIR_RTL = 11` — Sets text direction to right-to-left.
- `MENU_DISPLAY_UCC = 12` — Toggles control character display.
- `MENU_SUBMENU_INSERT_UCC = 13` — ID of "Insert Control Character" submenu.
- `MENU_INSERT_LRM = 14` — Inserts left-to-right mark (LRM) character.
- `MENU_INSERT_RLM = 15` — Inserts right-to-left mark (RLM) character.
- `MENU_INSERT_LRE = 16` — Inserts start of left-to-right embedding (LRE) character.
- `MENU_INSERT_RLE = 17` — Inserts start of right-to-left embedding (RLE) character.
- `MENU_INSERT_LRO = 18` — Inserts start of left-to-right override (LRO) character.
- `MENU_INSERT_RLO = 19` — Inserts start of right-to-left override (RLO) character.
- `MENU_INSERT_PDF = 20` — Inserts pop direction formatting (PDF) character.
- `MENU_INSERT_ALM = 21` — Inserts Arabic letter mark (ALM) character.
- `MENU_INSERT_LRI = 22` — Inserts left-to-right isolate (LRI) character.
- `MENU_INSERT_RLI = 23` — Inserts right-to-left isolate (RLI) character.
- `MENU_INSERT_FSI = 24` — Inserts first strong isolate (FSI) character.
- `MENU_INSERT_PDI = 25` — Inserts pop direction isolate (PDI) character.
- `MENU_INSERT_ZWJ = 26` — Inserts zero width joiner (ZWJ) character.
- `MENU_INSERT_ZWNJ = 27` — Inserts zero width non-joiner (ZWNJ) character.
- `MENU_INSERT_WJ = 28` — Inserts word joiner (WJ) character.
- `MENU_INSERT_SHY = 29` — Inserts soft hyphen (SHY) character.
- `MENU_EMOJI_AND_SYMBOL = 30` — Opens system emoji and symbol picker.
- `MENU_MAX = 31` — Represents the size of the `MenuItems` enum.

## Enum EditAction

- `ACTION_NONE = 0` — No current action.
- `ACTION_TYPING = 1` — A typing action.
- `ACTION_BACKSPACE = 2` — A backwards delete action.
- `ACTION_DELETE = 3` — A forward delete action.

## Enum SearchFlags

- `SEARCH_MATCH_CASE = 1` — Match case when searching.
- `SEARCH_WHOLE_WORDS = 2` — Match whole words when searching.
- `SEARCH_BACKWARDS = 4` — Search from end to beginning.

## Enum CaretType

- `CARET_TYPE_LINE = 0` — Vertical line caret.
- `CARET_TYPE_BLOCK = 1` — Block caret.

## Enum SelectionMode

- `SELECTION_MODE_NONE = 0` — Not selecting.
- `SELECTION_MODE_SHIFT = 1` — Select as if `shift` is pressed.
- `SELECTION_MODE_POINTER = 2` — Select single characters as if the user single clicked.
- `SELECTION_MODE_WORD = 3` — Select whole words as if the user double clicked.
- `SELECTION_MODE_LINE = 4` — Select whole lines as if the user triple clicked.

## Enum LineWrappingMode

- `LINE_WRAPPING_NONE = 0` — Line wrapping is disabled.
- `LINE_WRAPPING_BOUNDARY = 1` — Line wrapping occurs at the control boundary, beyond what would normally be visible.

## Enum GutterType

- `GUTTER_TYPE_STRING = 0` — When a gutter is set to string using `set_gutter_type`, it is used to contain text set via the `set_line_gutter_text` method.
- `GUTTER_TYPE_ICON = 1` — When a gutter is set to icon using `set_gutter_type`, it is used to contain an icon set via the `set_line_gutter_icon` method.
- `GUTTER_TYPE_CUSTOM = 2` — When a gutter is set to custom using `set_gutter_type`, it is used to contain custom visuals controlled by a callback method set via the `set_gutter_custom_draw` method.

## Theme items

- `background_color: Color` (color) = `Color(0, 0, 0, 0)`
- `caret_background_color: Color` (color) = `Color(0, 0, 0, 1)`
- `caret_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `current_line_color: Color` (color) = `Color(0.25, 0.25, 0.26, 0.8)`
- `font_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_placeholder_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.6)`
- `font_readonly_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `font_selected_color: Color` (color) = `Color(0, 0, 0, 0)`
- `search_result_border_color: Color` (color) = `Color(0.3, 0.3, 0.3, 0.4)`
- `search_result_color: Color` (color) = `Color(0.3, 0.3, 0.3, 1)`
- `selection_color: Color` (color) = `Color(0.5, 0.5, 0.5, 1)`
- `word_highlighted_color: Color` (color) = `Color(0.5, 0.5, 0.5, 0.25)`
- `caret_width: int` (constant) = `1`
- `line_spacing: int` (constant) = `4`
- `outline_size: int` (constant) = `0`
- `wrap_offset: int` (constant) = `10`
- `font: Font` (font)
- `font_size: int` (font_size)
- `space: Texture2D` (icon)
- `tab: Texture2D` (icon)
- `caret_move_rejected_sound: AudioStream` (sound)
- `caret_moved_sound: AudioStream` (sound)
- `focus_sound: AudioStream` (sound)
- `text_change_rejected_sound: AudioStream` (sound)
- `text_changed_sound: AudioStream` (sound)
- `focus: StyleBox` (style)
- `normal: StyleBox` (style)
- `read_only: StyleBox` (style)
