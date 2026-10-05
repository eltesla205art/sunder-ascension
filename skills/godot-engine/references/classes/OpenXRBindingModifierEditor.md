# OpenXRBindingModifierEditor

**Inherits:** PanelContainer

Binding modifier editor.

This is the default binding modifier editor used in the OpenXR action map.

## Methods

- `get_binding_modifier() -> OpenXRBindingModifier` *const* — Returns the OpenXRBindingModifier currently being edited.
- `setup(action_map: OpenXRActionMap, binding_modifier: OpenXRBindingModifier) -> void` — Setup this editor for the provided `action_map` and `binding_modifier`.

## Signals

- `binding_modifier_removed(binding_modifier_editor: Object)` — Signal emitted when the user presses the delete binding modifier button for this modifier.
