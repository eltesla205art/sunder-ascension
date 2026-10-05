# EditorResourcePicker

**Inherits:** HBoxContainer

Godot editor's control for selecting Resource type properties.

This Control node is used in the editor's Inspector dock to allow editing of Resource type properties. It provides options for creating, loading, saving and converting resources. Can be used with EditorInspectorPlugin to recreate the same behavior. Note: This Control does not include any editor for the resource, as editing is controlled by the Inspector dock itself or sub-Inspectors.

## Properties

- `base_type: String` = `""` — The base type of allowed resource types.
- `editable: bool` = `true` — If `true`, the value can be selected and edited.
- `edited_resource: Resource` — The edited resource value.
- `toggle_mode: bool` = `false` — If `true`, the main button with the resource preview works in the toggle mode.

## Methods

- `_handle_menu_selected(id: int) -> bool` *virtual* — This virtual method can be implemented to handle context menu items not handled by default.
- `_set_create_options(menu_node: Object) -> void` *virtual* — This virtual method is called when updating the context menu of an `editable` EditorResourcePicker.
- `get_allowed_types() -> PackedStringArray` *const* — Returns a list of all allowed types and subtypes corresponding to the `base_type`.
- `set_toggle_pressed(pressed: bool) -> void` — Sets the toggle mode state for the main button.

## Signals

- `resource_changed(resource: Resource)` — Emitted when the value of the edited resource was changed.
- `resource_selected(resource: Resource, inspect: bool)` — Emitted when the resource value was set and user clicked to edit it.
