# EditorInspector

**Inherits:** ScrollContainer

A control used to edit properties of an object.

This is the control that implements property editing in the editor's Settings dialogs, the Inspector dock, etc. To get the EditorInspector used in the editor's Inspector dock, use `EditorInterface.get_inspector`. EditorInspector will show properties in the same order as the array returned by `Object.get_property_list`. If a property's name is path-like (i.e. if it contains forward slashes), EditorInspector will create nested sections for "directories" along the path.

## Properties

- `draw_focus_border: bool` = `true` — 
- `focus_mode: Control.FocusMode` = `2` — 
- `follow_focus: bool` = `true` — 
- `horizontal_scroll_mode: ScrollContainer.ScrollMode` = `0` — 

## Methods

- `collapse_all_folding() -> void` — Collapses all foldable sections.
- `create_default_inspector(filter_line_edit: LineEdit = null) -> EditorInspector` *static* — Creates an inspector with the same configuration as the one used in the editor's Inspector dock.
- `edit(object: Object) -> void` — Shows the properties of the given `object` in this inspector for editing.
- `expand_all_folding() -> void` — Expands all foldable sections.
- `expand_revertable() -> void` — Expands only the foldable sections that contain a revertable (i.e. non-default) property.
- `get_edited_object() -> Object` — Returns the object currently selected in this inspector.
- `get_property_clipboard() -> Variant` *static* — Gets the value currently in the property clipboard.
- `get_selected_path() -> String` *const* — Gets the path of the currently selected property.
- `instantiate_property_editor(object: Object, type: Variant.Type, path: String, hint: PropertyHint, hint_text: String, usage: int, wide: bool = false) -> EditorProperty` *static* — Creates a property editor that can be used by plugin UI to edit the specified property of an `object`.
- `set_property_clipboard(value: Variant) -> void` *static* — Sets the property clipboard's content to the given value.

## Signals

- `edited_object_changed()` — Emitted when the object being edited by the inspector has changed.
- `object_id_selected(id: int)` — Emitted when the Edit button of an Object has been pressed in the inspector.
- `property_deleted(property: String)` — Emitted when a property is removed from the inspector.
- `property_edited(property: String)` — Emitted when a property is edited in the inspector.
- `property_keyed(property: String, value: Variant, advance: bool)` — Emitted when a property is keyed in the inspector.
- `property_selected(property: String)` — Emitted when a property is selected in the inspector.
- `property_toggled(property: String, checked: bool)` — Emitted when a boolean property is toggled in the inspector.
- `resource_selected(resource: Resource, path: String)` — Emitted when a resource is selected in the inspector.
- `restart_requested()` — Emitted when a property that requires a restart to be applied is edited in the inspector.
