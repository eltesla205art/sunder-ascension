# OpenXRActionMap

**Inherits:** Resource

Collection of OpenXRActionSet and OpenXRInteractionProfile resources for the OpenXR module.

OpenXR uses an action system similar to Godots Input map system to bind inputs and outputs on various types of XR controllers to named actions. OpenXR specifies more detail on these inputs and outputs than Godot supports. Another important distinction is that OpenXR offers no control over these bindings. The bindings we register are suggestions, it is up to the XR runtime to offer users the ability to change these bindings.

## Properties

- `action_sets: Array` = `[]` — Collection of OpenXRActionSets that are part of this action map.
- `interaction_profiles: Array` = `[]` — Collection of OpenXRInteractionProfiles that are part of this action map.

## Methods

- `add_action_set(action_set: OpenXRActionSet) -> void` — Add an action set.
- `add_interaction_profile(interaction_profile: OpenXRInteractionProfile) -> void` — Add an interaction profile.
- `create_default_action_sets() -> void` — Setup this action set with our default actions.
- `find_action_set(name: String) -> OpenXRActionSet` *const* — Retrieve an action set by name.
- `find_interaction_profile(name: String) -> OpenXRInteractionProfile` *const* — Find an interaction profile by its name (path).
- `get_action_set(idx: int) -> OpenXRActionSet` *const* — Retrieve the action set at this index.
- `get_action_set_count() -> int` *const* — Retrieve the number of actions sets in our action map.
- `get_interaction_profile(idx: int) -> OpenXRInteractionProfile` *const* — Get the interaction profile at this index.
- `get_interaction_profile_count() -> int` *const* — Retrieve the number of interaction profiles in our action map.
- `remove_action_set(action_set: OpenXRActionSet) -> void` — Remove an action set.
- `remove_interaction_profile(interaction_profile: OpenXRInteractionProfile) -> void` — Remove an interaction profile.
