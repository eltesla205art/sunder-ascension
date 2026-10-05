# ScriptExtension

**Inherits:** Script





## Methods

- `_can_instantiate() -> bool` *virtual required const*
- `_editor_can_reload_from_file() -> bool` *virtual required*
- `_get_base_script() -> Script` *virtual required const*
- `_get_class_icon_path() -> String` *virtual const*
- `_get_constants() -> Dictionary` *virtual required const*
- `_get_doc_class_name() -> StringName` *virtual required const*
- `_get_documentation() -> Dictionary[]` *virtual required const*
- `_get_global_name() -> StringName` *virtual required const*
- `_get_instance_base_type() -> StringName` *virtual required const*
- `_get_language() -> ScriptLanguage` *virtual required const*
- `_get_member_line(member: StringName) -> int` *virtual required const*
- `_get_members() -> StringName[]` *virtual required const*
- `_get_method_info(method: StringName) -> Dictionary` *virtual required const*
- `_get_property_default_value(property: StringName) -> Variant` *virtual required const*
- `_get_rpc_config() -> Variant` *virtual required const*
- `_get_script_method_argument_count(method: StringName) -> Variant` *virtual const* — Return the expected argument count for the given `method`, or `null` if it can't be determined (which will then fall back to the default behavior).
- `_get_script_method_list() -> Dictionary[]` *virtual required const*
- `_get_script_property_list() -> Dictionary[]` *virtual required const*
- `_get_script_signal_list() -> Dictionary[]` *virtual required const*
- `_get_source_code() -> String` *virtual required const*
- `_has_method(method: StringName) -> bool` *virtual required const*
- `_has_property_default_value(property: StringName) -> bool` *virtual required const*
- `_has_script_signal(signal: StringName) -> bool` *virtual required const*
- `_has_source_code() -> bool` *virtual required const*
- `_has_static_method(method: StringName) -> bool` *virtual required const*
- `_inherits_script(script: Script) -> bool` *virtual required const*
- `_instance_create(for_object: Object) -> void*` *virtual required const*
- `_instance_has(object: Object) -> bool` *virtual const* *(deprecated)*
- `_is_abstract() -> bool` *virtual const* — Returns `true` if the script is an abstract script.
- `_is_placeholder_fallback_enabled() -> bool` *virtual required const*
- `_is_tool() -> bool` *virtual required const*
- `_is_valid() -> bool` *virtual required const*
- `_placeholder_erased(placeholder: void*) -> void` *virtual*
- `_placeholder_instance_create(for_object: Object) -> void*` *virtual required const*
- `_reload(keep_state: bool) -> int[Error]` *virtual required*
- `_set_source_code(code: String) -> void` *virtual required*
- `_update_exports() -> void` *virtual required*
