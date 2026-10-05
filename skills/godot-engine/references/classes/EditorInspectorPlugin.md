# EditorInspectorPlugin

**Inherits:** RefCounted

Plugin for adding custom property editors on the inspector.

EditorInspectorPlugin allows adding custom property editors to EditorInspector. When an object is edited, the `_can_handle` function is called and must return `true` if the object type is supported. If supported, the function `_parse_begin` will be called, allowing to place custom controls at the beginning of the class. Subsequently, the `_parse_category` and `_parse_property` are called for every category and property.

## Methods

- `_can_handle(object: Object) -> bool` *virtual const* — Returns `true` if this object can be handled by this plugin.
- `_parse_begin(object: Object) -> void` *virtual* — Called to allow adding controls at the beginning of the property list for `object`.
- `_parse_category(object: Object, category: String) -> void` *virtual* — Called to allow adding controls at the beginning of a category in the property list for `object`.
- `_parse_end(object: Object) -> void` *virtual* — Called to allow adding controls at the end of the property list for `object`.
- `_parse_group(object: Object, group: String) -> void` *virtual* — Called to allow adding controls at the beginning of a group or a sub-group in the property list for `object`.
- `_parse_property(object: Object, type: Variant.Type, name: String, hint_type: PropertyHint, hint_string: String, usage_flags: PropertyUsageFlags, wide: bool) -> bool` *virtual* — Called to allow adding property-specific editors to the property list for `object`.
- `add_custom_control(control: Control) -> void` — Adds a custom control, which is not necessarily a property editor.
- `add_property_editor(property: String, editor: Control, add_to_end: bool = false, label: String = "") -> void` — Adds a property editor for an individual property.
- `add_property_editor_for_multiple_properties(label: String, properties: PackedStringArray, editor: Control) -> void` — Adds an editor that allows modifying multiple properties.
