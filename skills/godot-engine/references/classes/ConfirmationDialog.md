# ConfirmationDialog

**Inherits:** AcceptDialog

A dialog used for confirmation of actions.

A dialog used for confirmation of actions. This window is similar to AcceptDialog, but pressing its Cancel button can have a different outcome from pressing the OK button. The order of the two buttons varies depending on the host OS. Note: The dialog controls the size of its buttons, any manual size changes will be overridden.

## Properties

- `cancel_button_text: String` = `"Cancel"` — The text displayed by the cancel button (see `get_cancel_button`).
- `min_size: Vector2i` = `Vector2i(200, 70)` — 
- `size: Vector2i` = `Vector2i(200, 100)` — 

## Methods

- `get_cancel_button() -> Button` — Returns the cancel button.
