# OpenXRInteractionProfile

**Inherits:** Resource

Suggested bindings object for OpenXR.

This object stores suggested bindings for an interaction profile. Interaction profiles define the metadata for a tracked XR device such as an XR controller. For more information see the interaction profiles info in the OpenXR specification.

## Properties

- `binding_modifiers: Array` = `[]` — Binding modifiers for this interaction profile.
- `bindings: Array` = `[]` — Action bindings for this interaction profile.
- `interaction_profile_path: String` = `""` — The interaction profile path identifying the XR device.

## Methods

- `get_binding(index: int) -> OpenXRIPBinding` *const* — Retrieve the binding at this index.
- `get_binding_count() -> int` *const* — Get the number of bindings in this interaction profile.
- `get_binding_modifier(index: int) -> OpenXRIPBindingModifier` *const* — Get the OpenXRBindingModifier at this index.
- `get_binding_modifier_count() -> int` *const* — Get the number of binding modifiers in this interaction profile.
