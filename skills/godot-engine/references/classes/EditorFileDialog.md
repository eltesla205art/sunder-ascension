# EditorFileDialog

**Inherits:** FileDialog

A modified version of FileDialog used by the editor.

EditorFileDialog is a FileDialog tweaked to work in the editor. It automatically handles favorite and recent directory lists, and synchronizes some properties with their corresponding editor settings. EditorFileDialog will automatically show a native dialog based on the `EditorSettings.interface/editor/appearance/use_native_file_dialogs` editor setting and ignores `FileDialog.use_native_dialog`. Note: EditorFileDialog is invisible by default.

## Properties

- `disable_overwrite_warning: bool` = `false` *(deprecated)* — If `true`, the EditorFileDialog will not warn the user before overwriting files.

## Methods

- `add_side_menu(menu: Control, title: String = "") -> void` *(deprecated)* — This method is kept for compatibility and does nothing.
