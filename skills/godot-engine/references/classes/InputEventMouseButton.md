# InputEventMouseButton

**Inherits:** InputEventMouse

Represents a mouse button being pressed or released.

Stores information about mouse click events. See `Node._input`. Note: On Wear OS devices, rotary input is mapped to `MOUSE_BUTTON_WHEEL_UP` and `MOUSE_BUTTON_WHEEL_DOWN`. This can be changed to `MOUSE_BUTTON_WHEEL_LEFT` and `MOUSE_BUTTON_WHEEL_RIGHT` with the `ProjectSettings.input_devices/pointing/android/rotary_input_scroll_axis` setting.

## Properties

- `button_index: MouseButton` = `0` — The mouse button identifier, one of the `MouseButton` button or button wheel constants.
- `canceled: bool` = `false` — If `true`, the mouse button event has been canceled.
- `double_click: bool` = `false` — If `true`, the mouse button's state is a double-click.
- `factor: float` = `1.0` — The amount (or delta) of the event.
- `pressed: bool` = `false` — If `true`, the mouse button's state is pressed.
