# EditorProperty

**Inherits:** Container

Custom control for editing properties that can be added to the EditorInspector.

A custom control for editing properties that can be added to the EditorInspector. It is added via EditorInspectorPlugin.

## Properties

- `checkable: bool` = `false` — Used by the inspector, set to `true` when the property is checkable.
- `checked: bool` = `false` — Used by the inspector, set to `true` when the property is checked.
- `deletable: bool` = `false` — Used by the inspector, set to `true` when the property can be deleted by the user.
- `draw_background: bool` = `true` — Used by the inspector, set to `true` when the property background is drawn.
- `draw_label: bool` = `true` — Used by the inspector, set to `true` when the property label is drawn.
- `draw_warning: bool` = `false` — Used by the inspector, set to `true` when the property is drawn with the editor theme's warning color.
- `focus_mode: Control.FocusMode` = `3` — 
- `keying: bool` = `false` — Used by the inspector, set to `true` when the property can add keys for animation.
- `label: String` = `""` — Set this property to change the label (if you want to show one).
- `name_split_ratio: float` = `0.5` — Space distribution ratio between the label and the editing field.
- `read_only: bool` = `false` — Used by the inspector, set to `true` when the property is read-only.
- `selectable: bool` = `true` — Used by the inspector, set to `true` when the property is selectable.
- `use_folding: bool` = `false` — Used by the inspector, set to `true` when the property is using folding.

## Methods

- `_set_read_only(read_only: bool) -> void` *virtual* — Called when the read-only status of the property is changed.
- `_update_property() -> void` *virtual* — When this virtual function is called, you must update your editor.
- `add_focusable(control: Control) -> void` — If any of the controls added can gain keyboard focus, add it here.
- `deselect() -> void` — Draw property as not selected.
- `emit_changed(property: StringName, value: Variant, field: StringName = &"", changing: bool = false) -> void` — If one or several properties have changed, this must be called.
- `get_edited_object() -> Object` — Returns the edited object.
- `get_edited_property() -> StringName` *const* — Returns the edited property.
- `is_selected() -> bool` *const* — Returns `true` if property is drawn as selected.
- `select(focusable: int = -1) -> void` — Draw property as selected.
- `set_bottom_editor(editor: Control) -> void` — Puts the `editor` control below the property label.
- `set_label_reference(control: Control) -> void` — Used by the inspector, set to a control that will be used as a reference to calculate the size of the label.
- `set_object_and_property(object: Object, property: StringName) -> void` — Assigns object and property to edit.
- `update_property() -> void` — Forces a refresh of the property display.

## Signals

- `multiple_properties_changed(properties: PackedStringArray, value: Array)` — Emit it if you want multiple properties modified at the same time.
- `object_id_selected(property: StringName, id: int)` — Used by sub-inspectors.
- `property_can_revert_changed(property: StringName, can_revert: bool)` — Emitted when the revertability (i.e., whether it has a non-default value and thus is displayed with a revert icon) of a property has changed.
- `property_changed(property: StringName, value: Variant, field: StringName, changing: bool)` — Do not emit this manually, use the `emit_changed` method instead.
- `property_checked(property: StringName, checked: bool)` — Emitted when a property was checked.
- `property_deleted(property: StringName)` — Emitted when a property was deleted.
- `property_favorited(property: StringName, favorited: bool)` — Emit it if you want to mark a property as favorited, making it appear at the top of the inspector.
- `property_keyed(property: StringName)` — Emit it if you want to add this value as an animation key (check for keying being enabled first).
- `property_keyed_with_value(property: StringName, value: Variant)` — Emit it if you want to key a property with a single value.
- `property_overridden()` — Emitted when a setting override for the current project is requested.
- `property_pinned(property: StringName, pinned: bool)` — Emit it if you want to mark (or unmark) the value of a property for being saved regardless of being equal to the default value.
- `resource_selected(path: String, resource: Resource)` — If you want a sub-resource to be edited, emit this signal with the resource.
- `selected(path: String, focusable_idx: int)` — Emitted when selected.
