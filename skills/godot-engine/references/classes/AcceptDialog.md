# AcceptDialog

**Inherits:** Window

A base dialog used for user notification.

The default use of AcceptDialog is to allow it to only be accepted or closed, with the same result. However, the `confirmed` and `canceled` signals allow to make the two actions different, and the `add_button` method allows to add custom buttons and actions. Note: The dialog controls the size of its buttons, any manual size changes will be overridden. Use the `buttons_min_width` and `buttons_min_height` theme constants instead.

## Properties

- `dialog_autowrap: bool` = `false` — Sets autowrapping for the text in the dialog.
- `dialog_close_on_escape: bool` = `true` — If `true`, the dialog will be hidden when the `ui_close_dialog` action is pressed (by default, this action is bound to `Escape`, or `Cmd + W` on macOS).
- `dialog_hide_on_ok: bool` = `true` — If `true`, the dialog is hidden when the OK button is pressed.
- `dialog_text: String` = `""` — The text displayed by the dialog.
- `exclusive: bool` = `true` — 
- `keep_title_visible: bool` = `true` — 
- `maximize_disabled: bool` = `true` — 
- `minimize_disabled: bool` = `true` — 
- `ok_button_text: String` = `""` — The text displayed by the OK button (see `get_ok_button`).
- `transient: bool` = `true` — 
- `visible: bool` = `false` — 
- `wrap_controls: bool` = `true` — 

## Methods

- `add_button(text: String, right: bool = false, action: String = "") -> Button` — Adds a button with label `text` and a custom `action` to the dialog and returns the created button.
- `add_cancel_button(name: String) -> Button` — Adds a button with label `name` and a cancel action to the dialog and returns the created button.
- `get_label() -> Label` — Returns the label used for built-in text.
- `get_ok_button() -> Button` — Returns the OK Button instance.
- `register_text_enter(line_edit: LineEdit) -> void` — Registers a LineEdit in the dialog.
- `remove_button(button: Button) -> void` — Removes the `button` from the dialog.

## Signals

- `canceled()` — Emitted when the dialog is closed or the button created with `add_cancel_button` is pressed.
- `confirmed()` — Emitted when the dialog is accepted, i.e. the OK button is pressed.
- `custom_action(action: StringName)` — Emitted when a custom button with an action is pressed.

## Theme items

- `buttons_min_height: int` (constant) = `0`
- `buttons_min_width: int` (constant) = `0`
- `buttons_separation: int` (constant) = `10`
- `panel: StyleBox` (style)
