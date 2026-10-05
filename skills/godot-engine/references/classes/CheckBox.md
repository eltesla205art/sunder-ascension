# CheckBox

**Inherits:** Button

A button that represents a binary choice.

CheckBox allows the user to choose one of only two possible options. It's similar to CheckButton in functionality, but it has a different appearance. To follow established UX patterns, it's recommended to use CheckBox when toggling it has no immediate effect on something. For example, it could be used when toggling it will only do something once a confirmation button is pressed.

## Properties

- `alignment: HorizontalAlignment` = `0` — 
- `toggle_mode: bool` = `true` — 

## Theme items

- `checkbox_checked_color: Color` (color) = `Color(1, 1, 1, 1)`
- `checkbox_unchecked_color: Color` (color) = `Color(1, 1, 1, 1)`
- `check_v_offset: int` (constant) = `0`
- `checked: Texture2D` (icon)
- `checked_disabled: Texture2D` (icon)
- `radio_checked: Texture2D` (icon)
- `radio_checked_disabled: Texture2D` (icon)
- `radio_unchecked: Texture2D` (icon)
- `radio_unchecked_disabled: Texture2D` (icon)
- `unchecked: Texture2D` (icon)
- `unchecked_disabled: Texture2D` (icon)
