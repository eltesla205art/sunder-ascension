# RegExMatch

**Inherits:** RefCounted

Contains the results of a RegEx search.

Contains the results of a single RegEx match returned by `RegEx.search` and `RegEx.search_all`. It can be used to find the position and range of the match and its capturing groups, and it can extract its substring for you.

## Properties

- `names: Dictionary` = `{}` — A dictionary of named groups and its corresponding group number.
- `strings: PackedStringArray` = `PackedStringArray()` — An Array of the match and its capturing groups.
- `subject: String` = `""` — The source string used with the search pattern to find this matching result.

## Methods

- `get_end(name: Variant = 0) -> int` *const* — Returns the end position of the match within the source string.
- `get_group_count() -> int` *const* — Returns the number of capturing groups.
- `get_start(name: Variant = 0) -> int` *const* — Returns the starting position of the match within the source string.
- `get_string(name: Variant = 0) -> String` *const* — Returns the substring of the match from the source string.
