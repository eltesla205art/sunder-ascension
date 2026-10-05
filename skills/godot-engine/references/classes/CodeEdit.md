# CodeEdit

**Inherits:** TextEdit

A multiline text editor designed for editing code.

CodeEdit is a specialized TextEdit designed for editing plain text code files. It has many features commonly found in code editors such as line numbers, line folding, code completion, indent management, and string/comment management. Note: Regardless of locale, CodeEdit will by default always use left-to-right text direction to correctly display source code. Being a subclass of TextEdit, line and column numbers are zero-based, like elements of an array.

## Properties

- `auto_brace_completion_enabled: bool` = `false` — If `true`, uses `auto_brace_completion_pairs` to automatically insert the closing brace when the opening brace is inserted by typing or autocompletion.
- `auto_brace_completion_highlight_matching: bool` = `false` — If `true`, highlights brace pairs when the caret is on either one, using `auto_brace_completion_pairs`.
- `auto_brace_completion_pairs: Dictionary` = `{ "\"": "\"", "'": "'", "(": ")", "[": "]", "{": "}" }` — Sets the brace pairs to be autocompleted.
- `code_completion_enabled: bool` = `false` — If `true`, the `ProjectSettings.input/ui_text_completion_query` action requests code completion.
- `code_completion_prefixes: String[]` = `[]` — Sets prefixes that will trigger code completion.
- `delimiter_comments: String[]` = `[]` — Sets the comment delimiters.
- `delimiter_strings: String[]` = `["' '", "\" \""]` — Sets the string delimiters.
- `gutters_draw_bookmarks: bool` = `false` — If `true`, bookmarks are drawn in the gutter.
- `gutters_draw_breakpoints_gutter: bool` = `false` — If `true`, breakpoints are drawn in the gutter.
- `gutters_draw_executing_lines: bool` = `false` — If `true`, executing lines are marked in the gutter.
- `gutters_draw_fold_gutter: bool` = `false` — If `true`, the fold gutter is drawn.
- `gutters_draw_line_numbers: bool` = `false` — If `true`, the line number gutter is drawn.
- `gutters_line_numbers_min_digits: int` = `3` — The minimum width in digits reserved for the line number gutter.
- `gutters_zero_pad_line_numbers: bool` = `false` — If `true`, line numbers drawn in the gutter are zero padded based on the total line count.
- `indent_automatic: bool` = `false` — If `true`, an extra indent is automatically inserted when a new line is added and a prefix in `indent_automatic_prefixes` is found.
- `indent_automatic_prefixes: String[]` = `[":", "{", "[", "("]` — Prefixes to trigger an automatic indent.
- `indent_size: int` = `4` — Size of the tabulation indent (one `Tab` press) in characters.
- `indent_use_spaces: bool` = `false` — Use spaces instead of tabs for indentation.
- `layout_direction: Control.LayoutDirection` = `2` — 
- `line_folding: bool` = `false` — If `true`, lines can be folded.
- `line_length_guidelines: int[]` = `[]` — Draws vertical lines at the provided columns.
- `symbol_lookup_on_click: bool` = `false` — Set when a validated word from `symbol_validate` is clicked, the `symbol_lookup` should be emitted.
- `symbol_tooltip_on_hover: bool` = `false` — If `true`, the `symbol_hovered` signal is emitted when hovering over a word.
- `text_direction: Control.TextDirection` = `1` — 

## Methods

- `_confirm_code_completion(replace: bool) -> void` *virtual* — Override this method to define how the selected entry should be inserted.
- `_filter_code_completion_candidates(candidates: Dictionary[]) -> Dictionary[]` *virtual const* — Override this method to define what items in `candidates` should be displayed.
- `_request_code_completion(force: bool) -> void` *virtual* — Override this method to define what happens when the user requests code completion.
- `add_auto_brace_completion_pair(start_key: String, end_key: String) -> void` — Adds a brace pair.
- `add_code_completion_option(type: CodeEdit.CodeCompletionKind, display_text: String, insert_text: String, text_color: Color = Color(1, 1, 1, 1), icon: Resource = null, value: Variant = null, location: int = 1024) -> void` — Submits an item to the queue of potential candidates for the autocomplete menu.
- `add_comment_delimiter(start_key: String, end_key: String, line_only: bool = false) -> void` — Adds a comment delimiter from `start_key` to `end_key`.
- `add_string_delimiter(start_key: String, end_key: String, line_only: bool = false) -> void` — Defines a string delimiter from `start_key` to `end_key`.
- `can_fold_line(line: int) -> bool` *const* — Returns `true` if the given line is foldable.
- `cancel_code_completion() -> void` — Cancels the autocomplete menu.
- `clear_bookmarked_lines() -> void` — Clears all bookmarked lines.
- `clear_breakpointed_lines() -> void` — Clears all breakpointed lines.
- `clear_comment_delimiters() -> void` — Removes all comment delimiters.
- `clear_executing_lines() -> void` — Clears all executed lines.
- `clear_string_delimiters() -> void` — Removes all string delimiters.
- `confirm_code_completion(replace: bool = false) -> void` — Inserts the selected entry into the text.
- `convert_indent(from_line: int = -1, to_line: int = -1) -> void` — Converts the indents of lines between `from_line` and `to_line` to tabs or spaces as set by `indent_use_spaces`.
- `create_code_region() -> void` — Creates a new code region with the selection.
- `delete_lines() -> void` — Deletes all lines that are selected or have a caret on them.
- `do_indent() -> void` — If there is no selection, indentation is inserted at the caret.
- `duplicate_lines() -> void` — Duplicates all lines currently selected with any caret.
- `duplicate_selection() -> void` — Duplicates all selected text and duplicates all lines with a caret on them.
- `fold_all_lines() -> void` — Folds all lines that are possible to be folded (see `can_fold_line`).
- `fold_line(line: int) -> void` — Folds the given line, if possible (see `can_fold_line`).
- `get_auto_brace_completion_close_key(open_key: String) -> String` *const* — Gets the matching auto brace close key for `open_key`.
- `get_bookmarked_lines() -> PackedInt32Array` *const* — Gets all bookmarked lines.
- `get_breakpointed_lines() -> PackedInt32Array` *const* — Gets all breakpointed lines.
- `get_code_completion_option(index: int) -> Dictionary` *const* — Gets the completion option at `index`.
- `get_code_completion_options() -> Dictionary[]` *const* — Gets all completion options, see `get_code_completion_option` for return content.
- `get_code_completion_selected_index() -> int` *const* — Gets the index of the current selected completion option.
- `get_code_region_end_tag() -> String` *const* — Returns the code region end tag (without comment delimiter).
- `get_code_region_start_tag() -> String` *const* — Returns the code region start tag (without comment delimiter).
- `get_delimiter_end_key(delimiter_index: int) -> String` *const* — Gets the end key for a string or comment region index.
- `get_delimiter_end_position(line: int, column: int) -> Vector2` *const* — If `line` `column` is in a string or comment, returns the end position of the region.
- `get_delimiter_start_key(delimiter_index: int) -> String` *const* — Gets the start key for a string or comment region index.
- `get_delimiter_start_position(line: int, column: int) -> Vector2` *const* — If `line` `column` is in a string or comment, returns the start position of the region.
- `get_executing_lines() -> PackedInt32Array` *const* — Gets all executing lines.
- `get_folded_lines() -> int[]` *const* — Returns all lines that are currently folded.
- `get_text_for_code_completion() -> String` *const* — Returns the full text with char `0xFFFF` at the caret location.
- `get_text_for_symbol_lookup() -> String` *const* — Returns the full text with char `0xFFFF` at the cursor location.
- `get_text_with_cursor_char(line: int, column: int) -> String` *const* — Returns the full text with char `0xFFFF` at the specified location.
- `has_auto_brace_completion_close_key(close_key: String) -> bool` *const* — Returns `true` if close key `close_key` exists.
- `has_auto_brace_completion_open_key(open_key: String) -> bool` *const* — Returns `true` if open key `open_key` exists.
- `has_comment_delimiter(start_key: String) -> bool` *const* — Returns `true` if comment `start_key` exists.
- `has_string_delimiter(start_key: String) -> bool` *const* — Returns `true` if string `start_key` exists.
- `indent_lines() -> void` — Indents all lines that are selected or have a caret on them.
- `is_in_comment(line: int, column: int = -1) -> int` *const* — Returns delimiter index if `line` `column` is in a comment.
- `is_in_string(line: int, column: int = -1) -> int` *const* — Returns the delimiter index if `line` `column` is in a string.
- `is_line_bookmarked(line: int) -> bool` *const* — Returns `true` if the given line is bookmarked.
- `is_line_breakpointed(line: int) -> bool` *const* — Returns `true` if the given line is breakpointed.
- `is_line_code_region_end(line: int) -> bool` *const* — Returns `true` if the given line is a code region end.
- `is_line_code_region_start(line: int) -> bool` *const* — Returns `true` if the given line is a code region start.
- `is_line_executing(line: int) -> bool` *const* — Returns `true` if the given line is marked as executing.
- `is_line_folded(line: int) -> bool` *const* — Returns `true` if the given line is folded.
- `join_lines(line_ending: String = " ") -> void` — Joins all selected lines or lines containing a caret with their next line.
- `move_lines_down() -> void` — Moves all lines down that are selected or have a caret on them.
- `move_lines_up() -> void` — Moves all lines up that are selected or have a caret on them.
- `remove_comment_delimiter(start_key: String) -> void` — Removes the comment delimiter with `start_key`.
- `remove_string_delimiter(start_key: String) -> void` — Removes the string delimiter with `start_key`.
- `request_code_completion(force: bool = false) -> void` — Emits `code_completion_requested`, if `force` is `true` will bypass all checks.
- `set_code_completion_selected_index(index: int) -> void` — Sets the current selected completion option.
- `set_code_hint(code_hint: String) -> void` — Sets the code hint text.
- `set_code_hint_draw_below(draw_below: bool) -> void` — If `true`, the code hint will draw below the main caret.
- `set_code_region_tags(start: String = "region", end: String = "endregion") -> void` — Sets the code region start and end tags (without comment delimiter).
- `set_line_as_bookmarked(line: int, bookmarked: bool) -> void` — Sets the given line as bookmarked.
- `set_line_as_breakpoint(line: int, breakpointed: bool) -> void` — Sets the given line as a breakpoint.
- `set_line_as_executing(line: int, executing: bool) -> void` — Sets the given line as executing.
- `set_symbol_lookup_word_as_valid(valid: bool) -> void` — Sets the symbol emitted by `symbol_validate` as a valid lookup.
- `toggle_foldable_line(line: int) -> void` — Toggle the folding of the code block at the given line.
- `toggle_foldable_lines_at_carets() -> void` — Toggle the folding of the code block on all lines with a caret on them.
- `unfold_all_lines() -> void` — Unfolds all lines that are folded.
- `unfold_line(line: int) -> void` — Unfolds the given line if it is folded or if it is hidden under a folded line.
- `unindent_lines() -> void` — Unindents all lines that are selected or have a caret on them.
- `update_code_completion_options(force: bool) -> void` — Submits all completion options added with `add_code_completion_option`.

## Signals

- `breakpoint_toggled(line: int)` — Emitted when a breakpoint is added or removed from a line.
- `code_completion_requested()` — Emitted when the user requests code completion.
- `symbol_hovered(symbol: String, line: int, column: int)` — Emitted when the user hovers over a symbol.
- `symbol_lookup(symbol: String, line: int, column: int)` — Emitted when the user has clicked on a valid symbol.
- `symbol_validate(symbol: String)` — Emitted when the user hovers over a symbol.

## Enum CodeCompletionKind

- `KIND_CLASS = 0` — Marks the option as a class.
- `KIND_FUNCTION = 1` — Marks the option as a function.
- `KIND_SIGNAL = 2` — Marks the option as a Godot signal.
- `KIND_VARIABLE = 3` — Marks the option as a variable.
- `KIND_MEMBER = 4` — Marks the option as a member.
- `KIND_ENUM = 5` — Marks the option as an enum entry.
- `KIND_CONSTANT = 6` — Marks the option as a constant.
- `KIND_NODE_PATH = 7` — Marks the option as a Godot node path.
- `KIND_FILE_PATH = 8` — Marks the option as a file path.
- `KIND_PLAIN_TEXT = 9` — Marks the option as unclassified or plain text.
- `KIND_KEYWORD = 10` — Marks the option as a keyword.

## Enum CodeCompletionLocation

- `LOCATION_LOCAL = 0` — The option is local to the location of the code completion query - e.g. a local variable.
- `LOCATION_PARENT_MASK = 256` — The option is from the containing class or a parent class, relative to the location of the code completion query.
- `LOCATION_OTHER_USER_CODE = 512` — The option is from user code which is not local and not in a derived class (e.g.
- `LOCATION_OTHER = 1024` — The option is from other engine code, not covered by the other enum constants - e.g. built-in classes.

## Theme items

- `bookmark_color: Color` (color) = `Color(0.5, 0.64, 1, 0.8)`
- `brace_mismatch_color: Color` (color) = `Color(1, 0.2, 0.2, 1)`
- `breakpoint_color: Color` (color) = `Color(0.9, 0.29, 0.3, 1)`
- `code_folding_color: Color` (color) = `Color(0.8, 0.8, 0.8, 0.8)`
- `completion_background_color: Color` (color) = `Color(0.17, 0.16, 0.2, 1)`
- `completion_existing_color: Color` (color) = `Color(0.87, 0.87, 0.87, 0.13)`
- `completion_scroll_color: Color` (color) = `Color(1, 1, 1, 0.29)`
- `completion_scroll_hovered_color: Color` (color) = `Color(1, 1, 1, 0.4)`
- `completion_selected_color: Color` (color) = `Color(0.26, 0.26, 0.27, 1)`
- `executing_line_color: Color` (color) = `Color(0.98, 0.89, 0.27, 1)`
- `folded_code_region_color: Color` (color) = `Color(0.68, 0.46, 0.77, 0.2)`
- `line_length_guideline_color: Color` (color) = `Color(0.3, 0.5, 0.8, 0.1)`
- `line_number_color: Color` (color) = `Color(0.67, 0.67, 0.67, 0.4)`
- `completion_lines: int` (constant) = `7`
- `completion_max_width: int` (constant) = `50`
- `completion_scroll_width: int` (constant) = `6`
- `bookmark: Texture2D` (icon)
- `breakpoint: Texture2D` (icon)
- `can_fold: Texture2D` (icon)
- `can_fold_code_region: Texture2D` (icon)
- `completion_color_bg: Texture2D` (icon)
- `executing_line: Texture2D` (icon)
- `folded: Texture2D` (icon)
- `folded_code_region: Texture2D` (icon)
- `folded_eol_icon: Texture2D` (icon)
- `completion: StyleBox` (style)
