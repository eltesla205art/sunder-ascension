# EditorSpinSlider

**Inherits:** Range

Godot editor's control for editing numeric values.

This Control node is used in the editor's Inspector dock to allow editing of numeric values. Can be used with EditorInspectorPlugin to recreate the same behavior. If the `Range.step` value is `1`, the EditorSpinSlider will display up/down arrows, similar to SpinBox. If the `Range.step` value is not `1`, a slider will be displayed instead.

## Properties

- `control_state: EditorSpinSlider.ControlState` = `0` — The state in which the control used to manipulate the value will be.
- `deferred_drag_mode: bool` = `false` — If `true`, changing via dragging is applied only at the end of the input (for example, when the user releases a mouse button).
- `editing_integer: bool` = `false` — If `true`, the EditorSpinSlider is considered to be editing an integer value.
- `flat: bool` = `false` — If `true`, the slider will not draw background.
- `focus_mode: Control.FocusMode` = `2` — 
- `hide_slider: bool` = `false` *(deprecated)* — If `true`, the slider and up/down arrows are hidden.
- `label: String` = `""` — The text that displays to the left of the value.
- `read_only: bool` = `false` — If `true`, the slider can't be interacted with.
- `size_flags_vertical: Control.SizeFlags` = `1` — 
- `step: float` = `1.0` — 
- `suffix: String` = `""` — The suffix to display after the value (in a faded color).

## Signals

- `grabbed()` — Emitted when the spinner/slider is grabbed.
- `ungrabbed()` — Emitted when the spinner/slider is ungrabbed.
- `updown_pressed()` — Emitted when the updown button is pressed.
- `value_focus_entered()` — Emitted when the value form gains focus.
- `value_focus_exited()` — Emitted when the value form loses focus.

## Enum ControlState

- `CONTROL_STATE_DEFAULT = 0` — The type of control used will depend on the value of `editing_integer`.
- `CONTROL_STATE_PREFER_SLIDER = 1` — A slider will always be used, even if `editing_integer` is enabled.
- `CONTROL_STATE_HIDE = 2` — Neither the up-down arrows nor the slider will be shown.

## Theme items

- `label_color: Color` (color) = `Color(0, 0, 0, 1)`
- `read_only_label_color: Color` (color) = `Color(0, 0, 0, 1)`
- `line_edit_margin: int` (constant) = `0`
- `line_edit_margin_empty: int` (constant) = `0`
- `updown: Texture2D` (icon)
- `updown_disabled: Texture2D` (icon)
- `label_bg: StyleBox` (style)
