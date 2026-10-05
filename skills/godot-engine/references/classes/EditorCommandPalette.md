# EditorCommandPalette

**Inherits:** ConfirmationDialog

Godot editor's command palette.

Object that holds all the available Commands and their shortcuts text. These Commands can be accessed through Editor > Command Palette menu. Command key names use slash delimiters to distinguish sections, for example: `"example/command1"` then `example` will be the section name. Note: This class shouldn't be instantiated directly.

## Methods

- `add_command(command_name: String, key_name: String, binded_callable: Callable, shortcut_text: String = "None") -> void` — Adds a custom command to EditorCommandPalette. - `command_name`: String (Name of the Command.
- `remove_command(key_name: String) -> void` — Removes the custom command from EditorCommandPalette. - `key_name`: String (Name of the key for a particular Command.)
