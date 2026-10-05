# SpinBox

**Inherits:** Range

An input field for numbers.

SpinBox is a numerical input text field. It allows entering integers and floating-point numbers. The SpinBox also has up and down buttons that can be clicked to increase or decrease the value. The value can also be changed by dragging the mouse up or down over the SpinBox's arrows.

## Properties

- `alignment: HorizontalAlignment` = `0` — Changes the alignment of the underlying LineEdit.
- `custom_arrow_round: bool` = `false` — If `true`, the value will be rounded to a multiple of `custom_arrow_step` when interacting with the arrow buttons.
- `custom_arrow_step: float` = `0.0` — If not `0`, sets the step when interacting with the arrow buttons of the SpinBox.
- `editable: bool` = `true` — If `true`, the SpinBox will be editable.
- `format: String` = `""` — The formatting of the displayed numeric value, using the same rules as String's `%` operator (see GDScript format strings).
- `format_auto_translate_mode: Node.AutoTranslateMode` = `2` — Auto-translation mode for the `format`.
- `plural_format: String` — Plural version of `format`.
- `prefix: String` = `""` *(deprecated)* — Adds the specified prefix string before the numerical value of the SpinBox.
- `select_all_on_focus: bool` = `false` — If `true`, the SpinBox will select the whole text when the LineEdit gains focus.
- `size_flags_vertical: Control.SizeFlags` = `1` — 
- `step: float` = `1.0` — 
- `suffix: String` = `""` *(deprecated)* — Adds the specified suffix string after the numerical value of the SpinBox.
- `update_on_text_changed: bool` = `false` — Sets the value of the Range for this SpinBox when the LineEdit text is changed instead of submitted.

## Methods

- `apply() -> void` — Applies the current value of this SpinBox.
- `get_line_edit() -> LineEdit` — Returns the LineEdit instance from this SpinBox.

## Theme items

- `down_disabled_icon_modulate: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `down_hover_icon_modulate: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `down_icon_modulate: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `down_pressed_icon_modulate: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `up_disabled_icon_modulate: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `up_hover_icon_modulate: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `up_icon_modulate: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `up_pressed_icon_modulate: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `buttons_vertical_separation: int` (constant) = `0`
- `buttons_width: int` (constant) = `16`
- `field_and_buttons_separation: int` (constant) = `2`
- `icon_max_width: int` (constant) = `0`
- `set_min_buttons_width_from_icons: int` (constant) = `1`
- `down: Texture2D` (icon)
- `down_disabled: Texture2D` (icon)
- `down_hover: Texture2D` (icon)
- `down_pressed: Texture2D` (icon)
- `up: Texture2D` (icon)
- `up_disabled: Texture2D` (icon)
- `up_hover: Texture2D` (icon)
- `up_pressed: Texture2D` (icon)
- `updown: Texture2D` (icon)
- `focus_sound: AudioStream` (sound)
- `pressed_disabled_sound: AudioStream` (sound)
- `pressed_sound: AudioStream` (sound)
- `down_background: StyleBox` (style)
- `down_background_disabled: StyleBox` (style)
- `down_background_hovered: StyleBox` (style)
- `down_background_pressed: StyleBox` (style)
- `field_and_buttons_separator: StyleBox` (style)
- `up_background: StyleBox` (style)
- `up_background_disabled: StyleBox` (style)
- `up_background_hovered: StyleBox` (style)
- `up_background_pressed: StyleBox` (style)
- `up_down_buttons_separator: StyleBox` (style)
