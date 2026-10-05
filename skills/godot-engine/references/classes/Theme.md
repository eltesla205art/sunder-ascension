# Theme

**Inherits:** Resource

A resource used for styling/skinning Controls and Windows.

A resource used for styling/skinning Control and Window nodes. While individual controls can be styled using their local theme overrides (see `Control.add_theme_color_override`), theme resources allow you to store and apply the same settings across all controls sharing the same type (e.g. style all Buttons the same). One theme resource can be used for the entire project, but you can also set a separate theme resource to a branch of control nodes. A theme resource assigned to a control applies to the control itself, as well as all of its direct and indirect children (as long as a chain of controls is uninterrupted).

## Properties

- `default_base_scale: float` = `0.0` — The default base scale factor of this theme resource.
- `default_font: Font` — The default font of this theme resource.
- `default_font_size: int` = `-1` — The default font size of this theme resource.

## Methods

- `add_type(theme_type: StringName) -> void` — Adds an empty theme type for every valid data type.
- `clear() -> void` — Removes all the theme properties defined on the theme resource.
- `clear_color(name: StringName, theme_type: StringName) -> void` — Removes the Color property defined by `name` and `theme_type`, if it exists.
- `clear_constant(name: StringName, theme_type: StringName) -> void` — Removes the constant property defined by `name` and `theme_type`, if it exists.
- `clear_font(name: StringName, theme_type: StringName) -> void` — Removes the Font property defined by `name` and `theme_type`, if it exists.
- `clear_font_size(name: StringName, theme_type: StringName) -> void` — Removes the font size property defined by `name` and `theme_type`, if it exists.
- `clear_icon(name: StringName, theme_type: StringName) -> void` — Removes the icon property defined by `name` and `theme_type`, if it exists.
- `clear_sound(name: StringName, theme_type: StringName) -> void` — Removes the sound property defined by `name` and `theme_type`, if it exists.
- `clear_stylebox(name: StringName, theme_type: StringName) -> void` — Removes the StyleBox property defined by `name` and `theme_type`, if it exists.
- `clear_theme_item(data_type: Theme.DataType, name: StringName, theme_type: StringName) -> void` — Removes the theme property of `data_type` defined by `name` and `theme_type`, if it exists.
- `clear_type_variation(theme_type: StringName) -> void` — Unmarks `theme_type` as being a variation of another theme type.
- `get_color(name: StringName, theme_type: StringName) -> Color` *const* — Returns the Color property defined by `name` and `theme_type`, if it exists.
- `get_color_list(theme_type: String) -> PackedStringArray` *const* — Returns a list of names for Color properties defined with `theme_type`.
- `get_color_type_list() -> PackedStringArray` *const* — Returns a list of all unique theme type names for Color properties.
- `get_constant(name: StringName, theme_type: StringName) -> int` *const* — Returns the constant property defined by `name` and `theme_type`, if it exists.
- `get_constant_list(theme_type: String) -> PackedStringArray` *const* — Returns a list of names for constant properties defined with `theme_type`.
- `get_constant_type_list() -> PackedStringArray` *const* — Returns a list of all unique theme type names for constant properties.
- `get_font(name: StringName, theme_type: StringName) -> Font` *const* — Returns the Font property defined by `name` and `theme_type`, if it exists.
- `get_font_list(theme_type: String) -> PackedStringArray` *const* — Returns a list of names for Font properties defined with `theme_type`.
- `get_font_size(name: StringName, theme_type: StringName) -> int` *const* — Returns the font size property defined by `name` and `theme_type`, if it exists.
- `get_font_size_list(theme_type: String) -> PackedStringArray` *const* — Returns a list of names for font size properties defined with `theme_type`.
- `get_font_size_type_list() -> PackedStringArray` *const* — Returns a list of all unique theme type names for font size properties.
- `get_font_type_list() -> PackedStringArray` *const* — Returns a list of all unique theme type names for Font properties.
- `get_icon(name: StringName, theme_type: StringName) -> Texture2D` *const* — Returns the icon property defined by `name` and `theme_type`, if it exists.
- `get_icon_list(theme_type: String) -> PackedStringArray` *const* — Returns a list of names for icon properties defined with `theme_type`.
- `get_icon_type_list() -> PackedStringArray` *const* — Returns a list of all unique theme type names for icon properties.
- `get_sound(name: StringName, theme_type: StringName) -> AudioStream` *const* — Returns the sound property defined by `name` and `theme_type`, if it exists.
- `get_sound_list(theme_type: String) -> PackedStringArray` *const* — Returns a list of names for sound properties defined with `theme_type`.
- `get_sound_type_list() -> PackedStringArray` *const* — Returns a list of all unique theme type names for sound properties.
- `get_stylebox(name: StringName, theme_type: StringName) -> StyleBox` *const* — Returns the StyleBox property defined by `name` and `theme_type`, if it exists.
- `get_stylebox_list(theme_type: String) -> PackedStringArray` *const* — Returns a list of names for StyleBox properties defined with `theme_type`.
- `get_stylebox_type_list() -> PackedStringArray` *const* — Returns a list of all unique theme type names for StyleBox properties.
- `get_theme_item(data_type: Theme.DataType, name: StringName, theme_type: StringName) -> Variant` *const* — Returns the theme property of `data_type` defined by `name` and `theme_type`, if it exists.
- `get_theme_item_list(data_type: Theme.DataType, theme_type: String) -> PackedStringArray` *const* — Returns a list of names for properties of `data_type` defined with `theme_type`.
- `get_theme_item_type_list(data_type: Theme.DataType) -> PackedStringArray` *const* — Returns a list of all unique theme type names for `data_type` properties.
- `get_type_list() -> PackedStringArray` *const* — Returns a list of all unique theme type names.
- `get_type_variation_base(theme_type: StringName) -> StringName` *const* — Returns the name of the base theme type if `theme_type` is a valid variation type.
- `get_type_variation_list(base_type: StringName) -> PackedStringArray` *const* — Returns a list of all type variations for the given `base_type`.
- `has_color(name: StringName, theme_type: StringName) -> bool` *const* — Returns `true` if the Color property defined by `name` and `theme_type` exists.
- `has_constant(name: StringName, theme_type: StringName) -> bool` *const* — Returns `true` if the constant property defined by `name` and `theme_type` exists.
- `has_default_base_scale() -> bool` *const* — Returns `true` if `default_base_scale` has a valid value.
- `has_default_font() -> bool` *const* — Returns `true` if `default_font` has a valid value.
- `has_default_font_size() -> bool` *const* — Returns `true` if `default_font_size` has a valid value.
- `has_font(name: StringName, theme_type: StringName) -> bool` *const* — Returns `true` if the Font property defined by `name` and `theme_type` exists, or if the default theme font is set up (see `has_default_font`).
- `has_font_size(name: StringName, theme_type: StringName) -> bool` *const* — Returns `true` if the font size property defined by `name` and `theme_type` exists, or if the default theme font size is set up (see `has_default_font_size`).
- `has_icon(name: StringName, theme_type: StringName) -> bool` *const* — Returns `true` if the icon property defined by `name` and `theme_type` exists.
- `has_sound(name: StringName, theme_type: StringName) -> bool` *const* — Returns `true` if the sound property defined by `name` and `theme_type` exists.
- `has_stylebox(name: StringName, theme_type: StringName) -> bool` *const* — Returns `true` if the StyleBox property defined by `name` and `theme_type` exists.
- `has_theme_item(data_type: Theme.DataType, name: StringName, theme_type: StringName) -> bool` *const* — Returns `true` if the theme property of `data_type` defined by `name` and `theme_type` exists.
- `is_type_variation(theme_type: StringName, base_type: StringName) -> bool` *const* — Returns `true` if `theme_type` is marked as a variation of `base_type`.
- `merge_with(other: Theme) -> void` — Adds missing and overrides existing definitions with values from the `other` theme resource.
- `remove_type(theme_type: StringName) -> void` — Removes the theme type, gracefully discarding defined theme items.
- `rename_color(old_name: StringName, name: StringName, theme_type: StringName) -> void` — Renames the Color property defined by `old_name` and `theme_type` to `name`, if it exists.
- `rename_constant(old_name: StringName, name: StringName, theme_type: StringName) -> void` — Renames the constant property defined by `old_name` and `theme_type` to `name`, if it exists.
- `rename_font(old_name: StringName, name: StringName, theme_type: StringName) -> void` — Renames the Font property defined by `old_name` and `theme_type` to `name`, if it exists.
- `rename_font_size(old_name: StringName, name: StringName, theme_type: StringName) -> void` — Renames the font size property defined by `old_name` and `theme_type` to `name`, if it exists.
- `rename_icon(old_name: StringName, name: StringName, theme_type: StringName) -> void` — Renames the icon property defined by `old_name` and `theme_type` to `name`, if it exists.
- `rename_sound(old_name: StringName, name: StringName, theme_type: StringName) -> void` — Renames the sound property defined by `old_name` and `theme_type` to `name`, if it exists.
- `rename_stylebox(old_name: StringName, name: StringName, theme_type: StringName) -> void` — Renames the StyleBox property defined by `old_name` and `theme_type` to `name`, if it exists.
- `rename_theme_item(data_type: Theme.DataType, old_name: StringName, name: StringName, theme_type: StringName) -> void` — Renames the theme property of `data_type` defined by `old_name` and `theme_type` to `name`, if it exists.
- `rename_type(old_theme_type: StringName, theme_type: StringName) -> void` — Renames the theme type `old_theme_type` to `theme_type`, if the old type exists and the new one doesn't exist.
- `set_color(name: StringName, theme_type: StringName, color: Color) -> void` — Creates or changes the value of the Color property defined by `name` and `theme_type`.
- `set_constant(name: StringName, theme_type: StringName, constant: int) -> void` — Creates or changes the value of the constant property defined by `name` and `theme_type`.
- `set_font(name: StringName, theme_type: StringName, font: Font) -> void` — Creates or changes the value of the Font property defined by `name` and `theme_type`.
- `set_font_size(name: StringName, theme_type: StringName, font_size: int) -> void` — Creates or changes the value of the font size property defined by `name` and `theme_type`.
- `set_icon(name: StringName, theme_type: StringName, texture: Texture2D) -> void` — Creates or changes the value of the icon property defined by `name` and `theme_type`.
- `set_sound(name: StringName, theme_type: StringName, sound: AudioStream) -> void` — Creates or changes the value of the sound property defined by `name` and `theme_type`.
- `set_stylebox(name: StringName, theme_type: StringName, texture: StyleBox) -> void` — Creates or changes the value of the StyleBox property defined by `name` and `theme_type`.
- `set_theme_item(data_type: Theme.DataType, name: StringName, theme_type: StringName, value: Variant) -> void` — Creates or changes the value of the theme property of `data_type` defined by `name` and `theme_type`.
- `set_type_variation(theme_type: StringName, base_type: StringName) -> void` — Marks `theme_type` as a variation of `base_type`.

## Enum DataType

- `DATA_TYPE_COLOR = 0` — Theme's Color item type.
- `DATA_TYPE_CONSTANT = 1` — Theme's constant item type.
- `DATA_TYPE_FONT = 2` — Theme's Font item type.
- `DATA_TYPE_FONT_SIZE = 3` — Theme's font size item type.
- `DATA_TYPE_ICON = 4` — Theme's icon Texture2D item type.
- `DATA_TYPE_STYLEBOX = 5` — Theme's StyleBox item type.
- `DATA_TYPE_SOUND = 6` — Theme's AudioStream item type.
- `DATA_TYPE_MAX = 7` — Maximum value for the DataType enum.
