# CodeHighlighter

**Inherits:** SyntaxHighlighter

A syntax highlighter intended for code.

By adjusting various properties of this resource, you can change the colors of strings, comments, numbers, and other text patterns inside a TextEdit control.

## Properties

- `color_regions: Dictionary` = `{}` — Sets the color regions.
- `function_color: Color` = `Color(0, 0, 0, 1)` — Sets color for functions.
- `keyword_colors: Dictionary` = `{}` — Sets the keyword colors.
- `member_keyword_colors: Dictionary` = `{}` — Sets the member keyword colors.
- `member_variable_color: Color` = `Color(0, 0, 0, 1)` — Sets color for member variables.
- `number_color: Color` = `Color(0, 0, 0, 1)` — Sets the color for numbers.
- `symbol_color: Color` = `Color(0, 0, 0, 1)` — Sets the color for symbols.

## Methods

- `add_color_region(start_key: String, end_key: String, color: Color, line_only: bool = false) -> void` — Adds a color region (such as for comments or strings) from `start_key` to `end_key`.
- `add_keyword_color(keyword: String, color: Color) -> void` — Sets the color for a keyword.
- `add_member_keyword_color(member_keyword: String, color: Color) -> void` — Sets the color for a member keyword.
- `clear_color_regions() -> void` — Removes all color regions.
- `clear_keyword_colors() -> void` — Removes all keywords.
- `clear_member_keyword_colors() -> void` — Removes all member keywords.
- `get_keyword_color(keyword: String) -> Color` *const* — Returns the color for a keyword.
- `get_member_keyword_color(member_keyword: String) -> Color` *const* — Returns the color for a member keyword.
- `has_color_region(start_key: String) -> bool` *const* — Returns `true` if the start key exists, else `false`.
- `has_keyword_color(keyword: String) -> bool` *const* — Returns `true` if the keyword exists, else `false`.
- `has_member_keyword_color(member_keyword: String) -> bool` *const* — Returns `true` if the member keyword exists, else `false`.
- `remove_color_region(start_key: String) -> void` — Removes the color region that uses that start key.
- `remove_keyword_color(keyword: String) -> void` — Removes the keyword.
- `remove_member_keyword_color(member_keyword: String) -> void` — Removes the member keyword.
