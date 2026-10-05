# InputEventAction

**Inherits:** InputEvent

An input event type for actions.

Contains a generic action which can be targeted from several types of inputs. Actions and their events can be set in the Input Map tab in Project > Project Settings, or with the InputMap class. Note: Unlike the other InputEvent subclasses which map to unique physical events, this virtual one is not emitted by the engine. This class is useful to emit actions manually with `Input.parse_input_event`, which are then received in `Node._input`.

## Properties

- `action: StringName` = `&""` — The action's name.
- `event_index: int` = `-1` — The real event index in action this event corresponds to (from events defined for this action in the InputMap).
- `pressed: bool` = `false` — If `true`, the action's state is pressed.
- `strength: float` = `1.0` — The action's strength between 0 and 1.
