# OpenXRIPBinding

**Inherits:** Resource

Defines a binding between an OpenXRAction and an XR input or output.

This binding resource binds an OpenXRAction to an input or output. As most controllers have left hand and right versions that are handled by the same interaction profile we can specify multiple bindings. For instance an action "Fire" could be bound to both "/user/hand/left/input/trigger" and "/user/hand/right/input/trigger". This would require two binding entries.

## Properties

- `action: OpenXRAction` — OpenXRAction that is bound to `binding_path`.
- `binding_modifiers: Array` = `[]` — Binding modifiers for this binding.
- `binding_path: String` = `""` — Binding path that defines the input or output bound to `action`.
- `paths: PackedStringArray` *(deprecated)* — Paths that define the inputs or outputs bound on the device.

## Methods

- `add_path(path: String) -> void` *(deprecated)* — Add an input/output path to this binding.
- `get_binding_modifier(index: int) -> OpenXRActionBindingModifier` *const* — Get the OpenXRBindingModifier at this index.
- `get_binding_modifier_count() -> int` *const* — Get the number of binding modifiers for this binding.
- `get_path_count() -> int` *const* *(deprecated)* — Get the number of input/output paths in this binding.
- `has_path(path: String) -> bool` *const* *(deprecated)* — Returns `true` if this input/output path is part of this binding.
- `remove_path(path: String) -> void` *(deprecated)* — Removes this input/output path from this binding.
