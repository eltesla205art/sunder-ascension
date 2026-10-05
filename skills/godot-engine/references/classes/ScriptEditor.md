# ScriptEditor

**Inherits:** EditorDock

Godot editor's script editor.

Godot editor's script editor. Note: This class shouldn't be instantiated directly. Instead, access the singleton using `EditorInterface.get_script_editor`.

## Methods

- `clear_docs_from_script(script: Script) -> void` — Removes the documentation for the given `script`.
- `close_file(path: String) -> int[Error]` — Closes the file at the given `path`, discarding any unsaved changes.
- `get_breakpoints() -> PackedStringArray` — Returns array of breakpoints.
- `get_current_editor() -> ScriptEditorBase` *const* — Returns the ScriptEditorBase object that the user is currently editing.
- `get_current_script() -> Script` — Returns a Script that is currently active in editor.
- `get_open_script_editors() -> ScriptEditorBase[]` *const* — Returns an array with all ScriptEditorBase objects which are currently open in editor.
- `get_open_scripts() -> Script[]` *const* — Returns an array with all Script objects which are currently open in editor.
- `get_unsaved_files() -> PackedStringArray` *const* — Returns an array of file paths of scripts with unsaved changes open in the editor.
- `goto_help(topic: String) -> void` — Opens help for the given topic.
- `goto_line(line_number: int) -> void` — Goes to the specified line in the current script.
- `open_script_create_dialog(base_name: String, base_path: String) -> void` — Opens the script create dialog.
- `register_syntax_highlighter(syntax_highlighter: EditorSyntaxHighlighter) -> void` — Registers the EditorSyntaxHighlighter to the editor, the EditorSyntaxHighlighter will be available on all open scripts.
- `reload_open_files() -> void` — Reloads all currently opened files.
- `save_all_scripts() -> void` — Saves all open scripts.
- `unregister_syntax_highlighter(syntax_highlighter: EditorSyntaxHighlighter) -> void` — Unregisters the EditorSyntaxHighlighter from the editor.
- `update_docs_from_script(script: Script) -> void` — Updates the documentation for the given `script`.

## Signals

- `editor_script_changed(script: Script)` — Emitted when user changed active script.
- `script_close(script: Script)` — Emitted when editor is about to close the active script.
