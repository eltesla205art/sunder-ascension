# EditorToaster

**Inherits:** HBoxContainer

Manages toast notifications within the editor.

This object manages the functionality and display of toast notifications within the editor, ensuring immediate and informative alerts are presented to the user. Note: This class shouldn't be instantiated directly. Instead, access the singleton using `EditorInterface.get_editor_toaster`.

## Methods

- `push_toast(message: String, severity: EditorToaster.Severity = 0, tooltip: String = "") -> void` — Pushes a toast notification to the editor for display.

## Enum Severity

- `SEVERITY_INFO = 0` — Toast will display with an INFO severity.
- `SEVERITY_WARNING = 1` — Toast will display with a WARNING severity and have a corresponding color.
- `SEVERITY_ERROR = 2` — Toast will display with an ERROR severity and have a corresponding color.
