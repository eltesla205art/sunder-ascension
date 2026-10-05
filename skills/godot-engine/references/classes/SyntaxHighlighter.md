# SyntaxHighlighter

**Inherits:** Resource

Base class for syntax highlighters. Provides syntax highlighting data to a TextEdit.

Base class for syntax highlighters. Provides syntax highlighting data to a TextEdit. The associated TextEdit will call into the SyntaxHighlighter on an as-needed basis. Note: A SyntaxHighlighter instance should not be used across multiple TextEdit nodes.

## Methods

- `_clear_highlighting_cache() -> void` *virtual* — Virtual method which can be overridden to clear any local caches.
- `_get_line_syntax_highlighting(line: int) -> Dictionary` *virtual const* — Virtual method which can be overridden to return syntax highlighting data.
- `_update_cache() -> void` *virtual* — Virtual method which can be overridden to update any local caches.
- `clear_highlighting_cache() -> void` — Clears all cached syntax highlighting data.
- `get_line_syntax_highlighting(line: int) -> Dictionary` — Returns the syntax highlighting data for the line at index `line`.
- `get_text_edit() -> TextEdit` *const* — Returns the associated TextEdit node.
- `update_cache() -> void` — Clears then updates the SyntaxHighlighter caches.
