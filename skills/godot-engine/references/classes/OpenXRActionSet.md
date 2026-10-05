# OpenXRActionSet

**Inherits:** Resource

Collection of OpenXRAction resources that make up an action set.

Action sets in OpenXR define a collection of actions that can be activated in unison. This allows games to easily change between different states that require different inputs or need to reinterpret inputs. For instance we could have an action set that is active when a menu is open, an action set that is active when the player is freely walking around and an action set that is active when the player is controlling a vehicle. Action sets can contain the same action with the same name, if such action sets are active at the same time the action set with the highest priority defines which binding is active.

## Properties

- `actions: Array` = `[]` — Collection of actions for this action set.
- `localized_name: String` = `""` — The localized name of this action set.
- `priority: int` = `0` — The priority for this action set.

## Methods

- `add_action(action: OpenXRAction) -> void` — Add an action to this action set.
- `get_action_count() -> int` *const* — Retrieve the number of actions in our action set.
- `remove_action(action: OpenXRAction) -> void` — Remove an action from this action set.
