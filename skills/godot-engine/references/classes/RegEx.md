# RegEx

**Inherits:** RefCounted

Class for searching text for patterns using regular expressions.

A regular expression (or regex) is a compact language that can be used to recognize strings that follow a specific pattern, such as URLs, email addresses, complete sentences, etc. For example, a regex of `ab[0-9]` would find any string that is `ab` followed by any number from `0` to `9`. For a more in-depth look, you can easily find various tutorials and detailed explanations on the Internet. To begin, the RegEx object needs to be compiled with the search pattern using `compile` before it can be used.

## Methods

- `clear() -> void` — This method resets the state of the object, as if it was freshly created.
- `compile(pattern: String, show_error: bool = true) -> int[Error]` — Compiles and assign the search pattern to use.
- `create_from_string(pattern: String, show_error: bool = true) -> RegEx` *static* — Creates and compiles a new RegEx object.
- `get_group_count() -> int` *const* — Returns the number of capturing groups in compiled pattern.
- `get_names() -> PackedStringArray` *const* — Returns an array of names of named capturing groups in the compiled pattern.
- `get_pattern() -> String` *const* — Returns the original search pattern that was compiled.
- `is_valid() -> bool` *const* — Returns whether this object has a valid search pattern assigned.
- `search(subject: String, offset: int = 0, end: int = -1) -> RegExMatch` *const* — Searches the text for the compiled pattern.
- `search_all(subject: String, offset: int = 0, end: int = -1) -> RegExMatch[]` *const* — Searches the text for the compiled pattern.
- `sub(subject: String, replacement: String, all: bool = false, offset: int = 0, end: int = -1) -> String` *const* — Searches the text for the compiled pattern and replaces it with the specified string.
