# InputEventJoypadMotion

**Inherits:** InputEvent

Represents axis motions (such as joystick or analog triggers) from a gamepad.

Stores information about joystick motions. One InputEventJoypadMotion represents one axis at a time. For gamepad buttons, see InputEventJoypadButton.

## Properties

- `axis: JoyAxis` = `0` — Axis identifier.
- `axis_value: float` = `0.0` — Current position of the joystick on the given axis.
