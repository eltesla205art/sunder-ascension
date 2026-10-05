# InputEventWithModifiers

**Inherits:** InputEventFromWindow

Abstract base class for input events affected by modifier keys like `Shift` and `Alt`.

Stores information about mouse, keyboard, and touch gesture input events. This includes information about which modifier keys are pressed, such as `Shift` or `Alt`. See `Node._input`. Note: Modifier keys are considered modifiers only when used in combination with another key.

## Properties

- `alt_pressed: bool` = `false` — State of the `Alt` modifier.
- `command_or_control_autoremap: bool` = `false` — Automatically use `Meta` (`Cmd`) on macOS and `Ctrl` on other platforms.
- `ctrl_pressed: bool` = `false` — State of the `Ctrl` modifier.
- `device: int` = `16` — 
- `meta_pressed: bool` = `false` — State of the `Meta` modifier.
- `shift_pressed: bool` = `false` — State of the `Shift` modifier.

## Methods

- `get_modifiers_mask() -> int[KeyModifierMask]` *const* — Returns the keycode combination of modifier keys.
- `is_command_or_control_pressed() -> bool` *const* — On macOS, returns `true` if `Meta` (`Cmd`) is pressed.
