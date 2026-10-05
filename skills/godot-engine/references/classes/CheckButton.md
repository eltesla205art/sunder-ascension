# CheckButton

**Inherits:** Button

A button that represents a binary choice.

CheckButton is a toggle button displayed as a check field. It's similar to CheckBox in functionality, but it has a different appearance. To follow established UX patterns, it's recommended to use CheckButton when toggling it has an immediate effect on something. For example, it can be used when pressing it shows or hides advanced settings, without asking the user to confirm this action.

## Properties

- `alignment: HorizontalAlignment` = `0` — 
- `toggle_mode: bool` = `true` — 

## Theme items

- `button_checked_color: Color` (color) = `Color(1, 1, 1, 1)`
- `button_unchecked_color: Color` (color) = `Color(1, 1, 1, 1)`
- `check_v_offset: int` (constant) = `0`
- `checked: Texture2D` (icon)
- `checked_disabled: Texture2D` (icon)
- `checked_disabled_mirrored: Texture2D` (icon)
- `checked_mirrored: Texture2D` (icon)
- `unchecked: Texture2D` (icon)
- `unchecked_disabled: Texture2D` (icon)
- `unchecked_disabled_mirrored: Texture2D` (icon)
- `unchecked_mirrored: Texture2D` (icon)
