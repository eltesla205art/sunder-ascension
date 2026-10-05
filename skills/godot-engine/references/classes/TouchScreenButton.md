# TouchScreenButton

**Inherits:** Node2D

Button for touch screen devices for gameplay use.

TouchScreenButton allows you to create on-screen buttons for touch devices. It's intended for gameplay use, such as a unit you have to touch to move. Unlike Button, TouchScreenButton supports multitouch out of the box. Several TouchScreenButtons can be pressed at the same time with touch input.

## Properties

- `action: String` = `""` — The button's action.
- `bitmask: BitMap` — The button's bitmask.
- `passby_press: bool` = `false` — If `true`, the `pressed` and `released` signals are emitted whenever a pressed finger goes in and out of the button, even if the pressure started outside the active area of the button.
- `shape: Shape2D` — The button's shape.
- `shape_centered: bool` = `true` — If `true`, the button's shape is centered in the provided texture.
- `shape_visible: bool` = `true` — If `true`, the button's shape is visible in the editor.
- `texture_normal: Texture2D` — The button's texture for the normal state.
- `texture_pressed: Texture2D` — The button's texture for the pressed state.
- `visibility_mode: TouchScreenButton.VisibilityMode` = `0` — The button's visibility mode.

## Methods

- `is_pressed() -> bool` *const* — Returns `true` if this button is currently pressed.

## Signals

- `pressed()` — Emitted when the button is pressed (down).
- `released()` — Emitted when the button is released (up).

## Enum VisibilityMode

- `VISIBILITY_ALWAYS = 0` — Always visible.
- `VISIBILITY_TOUCHSCREEN_ONLY = 1` — Visible on touch screens only.
