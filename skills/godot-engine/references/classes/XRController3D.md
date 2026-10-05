# XRController3D

**Inherits:** XRNode3D

A 3D node representing a spatially-tracked controller.

This is a helper 3D node that is linked to the tracking of controllers. It also offers several handy passthroughs to the state of buttons and such on the controllers. Controllers are linked by their ID. You can create controller nodes before the controllers are available.

## Methods

- `get_float(name: StringName) -> float` *const* — Returns a numeric value for the input with the given `name`.
- `get_input(name: StringName) -> Variant` *const* — Returns a Variant for the input with the given `name`.
- `get_tracker_hand() -> int[XRPositionalTracker.TrackerHand]` *const* — Returns the hand holding this controller, if known.
- `get_vector2(name: StringName) -> Vector2` *const* — Returns a Vector2 for the input with the given `name`.
- `is_button_pressed(name: StringName) -> bool` *const* — Returns `true` if the button with the given `name` is pressed.

## Signals

- `button_pressed(action_name: String)` — Emitted when a button on this controller is pressed.
- `button_released(action_name: String)` — Emitted when a button on this controller is released.
- `input_float_changed(action_name: String, value: float)` — Emitted when a trigger or similar input on this controller changes value.
- `input_vector2_changed(action_name: String, value: Vector2)` — Emitted when a thumbstick or thumbpad on this controller is moved.
- `profile_changed(role: String)` — Emitted when the interaction profile on this controller is changed.
