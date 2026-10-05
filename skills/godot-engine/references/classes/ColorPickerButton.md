# ColorPickerButton

**Inherits:** Button

A button that brings up a ColorPicker when pressed.

Encapsulates a ColorPicker, making it accessible by pressing a button. Pressing the button will toggle the ColorPicker's visibility. See also BaseButton which contains common properties and methods associated with this node. Note: By default, the button may not be wide enough for the color preview swatch to be visible.

## Properties

- `color: Color` = `Color(0, 0, 0, 1)` — The currently selected color.
- `edit_alpha: bool` = `true` — If `true`, the alpha channel in the displayed ColorPicker will be visible.
- `edit_intensity: bool` = `true` — If `true`, the intensity slider in the displayed ColorPicker will be visible.
- `toggle_mode: bool` = `true` — 

## Methods

- `get_picker() -> ColorPicker` — Returns the ColorPicker that this node toggles.
- `get_popup() -> PopupPanel` — Returns the control's PopupPanel which allows you to connect to popup signals.

## Signals

- `color_changed(color: Color)` — Emitted when the color changes.
- `picker_created()` — Emitted when the ColorPicker is created (the button is pressed for the first time).
- `popup_closed()` — Emitted when the ColorPicker is closed.

## Theme items

- `bg: Texture2D` (icon)
