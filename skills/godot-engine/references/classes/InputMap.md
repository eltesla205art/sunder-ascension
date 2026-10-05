# InputMap

**Inherits:** Object

A singleton that manages all InputEventActions.

Manages all InputEventAction which can be created/modified from the project settings menu Project > Project Settings > Input Map or in code with `add_action` and `action_add_event`. See `Node._input`.

## Methods

- `action_add_event(action: StringName, event: InputEvent) -> void` — Adds an InputEvent to an action.
- `action_erase_event(action: StringName, event: InputEvent) -> void` — Removes an InputEvent from an action.
- `action_erase_events(action: StringName) -> void` — Removes all events from an action.
- `action_get_deadzone(action: StringName) -> float` — Returns a deadzone value for the action.
- `action_get_events(action: StringName) -> InputEvent[]` — Returns an array of InputEvents associated with a given action.
- `action_has_event(action: StringName, event: InputEvent) -> bool` — Returns `true` if the action has the given InputEvent associated with it.
- `action_set_deadzone(action: StringName, deadzone: float) -> void` — Sets a deadzone value for the action.
- `add_action(action: StringName, deadzone: float = 0.2) -> void` — Adds an empty action to the InputMap with a configurable `deadzone`.
- `erase_action(action: StringName) -> void` — Removes an action from the InputMap.
- `event_is_action(event: InputEvent, action: StringName, exact_match: bool = false) -> bool` *const* — Returns `true` if the given event is part of an existing action.
- `get_action_description(action: StringName) -> String` *const* — Returns the human-readable description of the given action.
- `get_actions() -> StringName[]` — Returns an array of all actions in the InputMap.
- `has_action(action: StringName) -> bool` *const* — Returns `true` if the InputMap has a registered action with the given name.
- `load_from_project_settings() -> void` — Clears all InputEventAction in the InputMap and load it anew from ProjectSettings.

## Signals

- `project_settings_loaded()` — Emitted when the ProjectSettings InputMap has been loaded.
