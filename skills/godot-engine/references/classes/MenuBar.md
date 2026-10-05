# MenuBar

**Inherits:** Control

A horizontal menu bar that creates a menu for each PopupMenu child.

A horizontal menu bar that creates a menu for each PopupMenu child. New items are created by adding PopupMenus to this node. Item title is determined by `Window.title`, or node name if `Window.title` is empty. Item title can be overridden using `set_menu_title`.

## Properties

- `flat: bool` = `false` — Flat MenuBar don't display item decoration.
- `focus_mode: Control.FocusMode` = `3` — 
- `language: String` = `""` — Language code used for line-breaking and text shaping algorithms.
- `prefer_global_menu: bool` = `true` — If `true`, MenuBar will use system global menu when supported.
- `start_index: int` = `-1` — Position order in the global menu to insert MenuBar items at.
- `switch_on_hover: bool` = `true` — If `true`, when the cursor hovers above menu item, it will close the current PopupMenu and open the other one.
- `text_direction: Control.TextDirection` = `0` — Base text writing direction.

## Methods

- `get_menu_count() -> int` *const* — Returns number of menu items.
- `get_menu_popup(menu: int) -> PopupMenu` *const* — Returns PopupMenu associated with menu item.
- `get_menu_title(menu: int) -> String` *const* — Returns menu item title.
- `get_menu_tooltip(menu: int) -> String` *const* — Returns menu item tooltip.
- `is_menu_disabled(menu: int) -> bool` *const* — Returns `true` if the menu item is disabled.
- `is_menu_hidden(menu: int) -> bool` *const* — Returns `true` if the menu item is hidden.
- `is_native_menu() -> bool` *const* — Returns `true` if the current system's global menu is supported and used by this MenuBar.
- `set_disable_shortcuts(disabled: bool) -> void` — If `true`, shortcuts are disabled and cannot be used to trigger the button.
- `set_menu_disabled(menu: int, disabled: bool) -> void` — If `true`, menu item is disabled.
- `set_menu_hidden(menu: int, hidden: bool) -> void` — If `true`, menu item is hidden.
- `set_menu_title(menu: int, title: String) -> void` — Sets menu item title.
- `set_menu_tooltip(menu: int, tooltip: String) -> void` — Sets menu item tooltip.

## Theme items

- `font_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `font_disabled_color: Color` (color) = `Color(0.875, 0.875, 0.875, 0.5)`
- `font_focus_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_hover_color: Color` (color) = `Color(0.95, 0.95, 0.95, 1)`
- `font_hover_pressed_color: Color` (color) = `Color(1, 1, 1, 1)`
- `font_outline_color: Color` (color) = `Color(0, 0, 0, 1)`
- `font_pressed_color: Color` (color) = `Color(1, 1, 1, 1)`
- `h_separation: int` (constant) = `4`
- `outline_size: int` (constant) = `0`
- `font: Font` (font)
- `font_size: int` (font_size)
- `disabled: StyleBox` (style)
- `disabled_mirrored: StyleBox` (style)
- `hover: StyleBox` (style)
- `hover_mirrored: StyleBox` (style)
- `hover_pressed: StyleBox` (style)
- `hover_pressed_mirrored: StyleBox` (style)
- `normal: StyleBox` (style)
- `normal_mirrored: StyleBox` (style)
- `pressed: StyleBox` (style)
- `pressed_mirrored: StyleBox` (style)
