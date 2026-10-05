# OpenXRInteractionProfileMetadata

**Inherits:** Object

Meta class registering supported devices in OpenXR.

This class allows OpenXR core and extensions to register metadata relating to supported interaction devices such as controllers, trackers, haptic devices, etc. It is primarily used by the action map editor and to sanitize any action map by removing extension-dependent entries when applicable.

## Methods

- `register_interaction_profile(display_name: String, openxr_path: String, openxr_extension_names: String) -> void` — Registers an interaction profile using its OpenXR designation (e.g.
- `register_io_path(interaction_profile: String, display_name: String, toplevel_path: String, openxr_path: String, openxr_extension_names: String, action_type: OpenXRAction.ActionType) -> void` — Registers an input/output path for the given `interaction_profile`.
- `register_path_rename(old_name: String, new_name: String) -> void` — Allows for renaming old input/output paths to new paths in order to load and process older action maps.
- `register_profile_rename(old_name: String, new_name: String) -> void` — Allows for renaming old interaction profile paths to new paths in order to load and process older action maps.
- `register_top_level_path(display_name: String, openxr_path: String, openxr_extension_names: String) -> void` — Registers a top level path to which profiles can be bound.
