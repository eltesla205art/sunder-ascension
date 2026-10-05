# VirtualJoystick

**Inherits:** Control

A virtual joystick control for touchscreen devices.

A customizable on-screen joystick control designed for touchscreen devices. It allows users to provide directional input by dragging a virtual tip within a defined circular area. This control can simulate directional actions (see `action_up`, `action_down`, `action_left`, and `action_right`), which are triggered when the joystick is moved in the corresponding directions.

## Properties

- `action_down: StringName` = `&"ui_down"` — The action to trigger when the joystick is moved down.
- `action_left: StringName` = `&"ui_left"` — The action to trigger when the joystick is moved left.
- `action_right: StringName` = `&"ui_right"` — The action to trigger when the joystick is moved right.
- `action_up: StringName` = `&"ui_up"` — The action to trigger when the joystick is moved up.
- `clampzone_ratio: float` = `1.0` — The multiplier applied to the joystick's radius that defines the clamp zone.
- `deadzone_ratio: float` = `0.0` — The ratio of the joystick size that defines the joystick deadzone.
- `initial_offset_ratio: Vector2` = `Vector2(0.5, 0.5)` — The initial position of the joystick as a ratio of the control's size.
- `joystick_mode: VirtualJoystick.JoystickMode` = `0` — The joystick mode to use.
- `joystick_size: float` = `100.0` — The size of the joystick in pixels.
- `tip_size: float` = `50.0` — The size of the joystick tip in pixels.
- `visibility_mode: VirtualJoystick.VisibilityMode` = `0` — The visibility mode to use.

## Signals

- `flick_canceled()` — Emitted when the tip enters the deadzone after being outside of it.
- `flicked(input_vector: Vector2)` — Emitted when the tip moved outside the deadzone and the joystick is released.
- `pressed()` — Emitted when the joystick is pressed.
- `released(input_vector: Vector2)` — Emitted when the joystick is released.
- `tapped()` — Emitted when the joystick is released without moving the tip.

## Enum JoystickMode

- `JOYSTICK_FIXED = 0` — The joystick doesn't move.
- `JOYSTICK_DYNAMIC = 1` — The joystick is moved to the initial touch position as long as it's within the joystick's bounds.
- `JOYSTICK_FOLLOWING = 2` — The joystick is moved to the initial touch position as long as it's within the joystick's bounds.

## Enum VisibilityMode

- `VISIBILITY_ALWAYS = 0` — The joystick is always visible.
- `VISIBILITY_WHEN_TOUCHED = 1` — The joystick is only visible when being touched.

## Theme items

- `normal_joystick: StyleBox` (style)
- `normal_tip: StyleBox` (style)
- `pressed_joystick: StyleBox` (style)
- `pressed_tip: StyleBox` (style)
