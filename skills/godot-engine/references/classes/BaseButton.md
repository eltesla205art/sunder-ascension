# BaseButton

**Inherits:** Control

Abstract base class for GUI buttons.

BaseButton is an abstract base class for GUI buttons. It doesn't display anything by itself.

## Properties

- `action_mode: BaseButton.ActionMode` = `1` — Determines when the button is considered clicked.
- `button_group: ButtonGroup` — The ButtonGroup associated with the button.
- `button_mask: MouseButtonMask` = `1` — Binary mask to choose which mouse buttons this button will respond to.
- `button_pressed: bool` = `false` — If `true`, the button's state is pressed.
- `disabled: bool` = `false` — If `true`, the button is in disabled state and can't be clicked or toggled.
- `focus_mode: Control.FocusMode` = `2` — 
- `keep_pressed_outside: bool` = `false` — If `true`, the button stays pressed when moving the cursor outside the button while pressing it.
- `shortcut: Shortcut` — Shortcut associated to the button.
- `shortcut_feedback: bool` = `true` — If `true`, the button will highlight for a short amount of time when its shortcut is activated.
- `shortcut_in_tooltip: bool` = `true` — If `true`, the button will add information about its shortcut in the tooltip.
- `toggle_mode: bool` = `false` — If `true`, the button is in toggle mode.

## Methods

- `_pressed() -> void` *virtual* — Called when the button is pressed.
- `_toggled(toggled_on: bool) -> void` *virtual* — Called when the button is toggled (only if `toggle_mode` is active).
- `get_draw_mode() -> int[BaseButton.DrawMode]` *const* — Returns the visual state used to draw the button.
- `is_hovered() -> bool` *const* — Returns `true` if the mouse has entered the button and has not left it yet.
- `press() -> void` — Presses the button.
- `set_pressed_no_signal(pressed: bool) -> void` — Changes the `button_pressed` state of the button, without emitting `toggled`.

## Signals

- `button_down()` — Emitted when the button starts being held down.
- `button_up()` — Emitted when the button stops being held down.
- `pressed()` — Emitted when the button is toggled or pressed.
- `toggled(toggled_on: bool)` — Emitted when the button was just toggled between pressed and normal states (only if `toggle_mode` is active).

## Enum DrawMode

- `DRAW_NORMAL = 0` — The normal state (i.e. not pressed, not hovered, not toggled and enabled) of buttons.
- `DRAW_PRESSED = 1` — The state of buttons are pressed.
- `DRAW_HOVER = 2` — The state of buttons are hovered.
- `DRAW_DISABLED = 3` — The state of buttons are disabled.
- `DRAW_HOVER_PRESSED = 4` — The state of buttons are both hovered and pressed.

## Enum ActionMode

- `ACTION_MODE_BUTTON_PRESS = 0` — Require just a press to consider the button clicked.
- `ACTION_MODE_BUTTON_RELEASE = 1` — Require a press and a subsequent release before considering the button clicked.

## Theme items

- `click_margin: int` (constant) = `0`
- `focus_sound: AudioStream` (sound)
- `hover_sound: AudioStream` (sound)
- `pressed_disabled_sound: AudioStream` (sound)
- `pressed_sound: AudioStream` (sound)
