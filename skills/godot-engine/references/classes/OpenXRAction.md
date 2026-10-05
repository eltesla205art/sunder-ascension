# OpenXRAction

**Inherits:** Resource

An OpenXR action.

This resource defines an OpenXR action. Actions can be used both for inputs (buttons, joysticks, triggers, etc.) and outputs (haptics). OpenXR performs automatic conversion between action type and input type whenever possible. An analog trigger bound to a boolean action will thus return `false` if the trigger is depressed and `true` if pressed fully.

## Properties

- `action_type: OpenXRAction.ActionType` = `1` — The type of action.
- `localized_name: String` = `""` — The localized description of this action.
- `toplevel_paths: PackedStringArray` = `PackedStringArray()` — A collections of toplevel paths to which this action can be bound.

## Enum ActionType

- `OPENXR_ACTION_BOOL = 0` — This action provides a boolean value.
- `OPENXR_ACTION_FLOAT = 1` — This action provides a float value between `0.0` and `1.0` for any analog input such as triggers.
- `OPENXR_ACTION_VECTOR2 = 2` — This action provides a Vector2 value and can be bound to embedded trackpads and joysticks.
- `OPENXR_ACTION_POSE = 3` —
