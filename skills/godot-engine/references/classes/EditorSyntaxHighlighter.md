# EditorSyntaxHighlighter

**Inherits:** SyntaxHighlighter

Base class for SyntaxHighlighter used by the ScriptEditor.

Base class that all SyntaxHighlighters used by the ScriptEditor extend from. Add a syntax highlighter to an individual script by calling `ScriptEditorBase.add_syntax_highlighter`. To apply to all scripts on open, call `ScriptEditor.register_syntax_highlighter`.

## Methods

- `_create() -> EditorSyntaxHighlighter` *virtual const* — Virtual method which creates a new instance of the syntax highlighter.
- `_get_name() -> String` *virtual const* — Virtual method which can be overridden to return the syntax highlighter name.
- `_get_supported_languages() -> PackedStringArray` *virtual const* — Virtual method which can be overridden to return the supported language names.
