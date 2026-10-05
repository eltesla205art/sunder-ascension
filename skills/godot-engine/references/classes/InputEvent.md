# InputEvent

**Inherits:** Resource

Abstract base class for input events.

Abstract base class of all types of input events. See `Node._input`.

## Properties

- `device: int` = `0` — The event's device ID.

## Methods

- `accumulate(with_event: InputEvent) -> bool` — Returns `true` if the given input event and this input event can be added together (only for events of type InputEventMouseMotion).
- `as_text() -> String` *const* — Returns a String representation of the event.
- `get_action_strength(action: StringName, exact_match: bool = false) -> float` *const* — Returns a value between `0.0` and `1.0` depending on the given action's state.
- `is_action(action: StringName, exact_match: bool = false) -> bool` *const* — Returns `true` if this input event matches a pre-defined action of any type.
- `is_action_pressed(action: StringName, allow_echo: bool = false, exact_match: bool = false) -> bool` *const* — Returns `true` if the given action matches this event and is being pressed (and is not an echo event for InputEventKey events, unless `allow_echo` is `true`).
- `is_action_released(action: StringName, exact_match: bool = false) -> bool` *const* — Returns `true` if the given action matches this event and is released (i.e. not pressed).
- `is_action_type() -> bool` *const* — Returns `true` if this input event's type is one that can be assigned to an input action: InputEventKey, InputEventMouseButton, InputEventJoypadButton, InputEventJoypadMotion, InputEventAction.
- `is_canceled() -> bool` *const* — Returns `true` if this input event has been canceled.
- `is_echo() -> bool` *const* — Returns `true` if this input event is an echo event (only for events of type InputEventKey).
- `is_match(event: InputEvent, exact_match: bool = true) -> bool` *const* — Returns `true` if the specified `event` matches this event.
- `is_pressed() -> bool` *const* — Returns `true` if this input event is pressed.
- `is_released() -> bool` *const* — Returns `true` if this input event is released.
- `xformed_by(xform: Transform2D, local_ofs: Vector2 = Vector2(0, 0)) -> InputEvent` *const* — Returns a copy of the given input event which has been offset by `local_ofs` and transformed by `xform`.

## Constants

- `DEVICE_ID_EMULATION = -1` — Device ID used for emulated mouse input from a touchscreen, or for emulated touch input from a mouse.
- `DEVICE_ID_KEYBOARD = 16` — Device ID used for input from a keyboard.
- `DEVICE_ID_MOUSE = 32` — Device ID used for input from a mouse.
