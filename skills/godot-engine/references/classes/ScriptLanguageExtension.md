# ScriptLanguageExtension

**Inherits:** ScriptLanguage





## Methods

- `_add_global_constant(name: StringName, value: Variant) -> void` *virtual required*
- `_add_named_global_constant(name: StringName, value: Variant) -> void` *virtual required*
- `_auto_indent_code(code: String, from_line: int, to_line: int) -> String` *virtual required const*
- `_can_inherit_from_file() -> bool` *virtual required const*
- `_can_make_function() -> bool` *virtual required const*
- `_complete_code(code: String, path: String, owner: Object) -> Dictionary` *virtual required const*
- `_create_script() -> Object` *virtual const* *(deprecated)*
- `_debug_get_current_stack_info() -> Dictionary[]` *virtual required*
- `_debug_get_error() -> String` *virtual required const*
- `_debug_get_globals(max_subitems: int, max_depth: int) -> Dictionary` *virtual required*
- `_debug_get_stack_level_count() -> int` *virtual required const*
- `_debug_get_stack_level_function(level: int) -> String` *virtual required const*
- `_debug_get_stack_level_instance(level: int) -> void*` *virtual required*
- `_debug_get_stack_level_line(level: int) -> int` *virtual required const*
- `_debug_get_stack_level_locals(level: int, max_subitems: int, max_depth: int) -> Dictionary` *virtual required*
- `_debug_get_stack_level_members(level: int, max_subitems: int, max_depth: int) -> Dictionary` *virtual required*
- `_debug_get_stack_level_source(level: int) -> String` *virtual required const* — Returns the source associated with a given debug stack position.
- `_debug_parse_stack_level_expression(level: int, expression: String, max_subitems: int, max_depth: int) -> String` *virtual required*
- `_find_function(function: String, code: String) -> int` *virtual required const* — Returns the line where the function is defined in the code, or `-1` if the function is not present.
- `_finish() -> void` *virtual required*
- `_frame() -> void` *virtual required*
- `_get_built_in_templates(object: StringName) -> Dictionary[]` *virtual required const*
- `_get_comment_delimiters() -> PackedStringArray` *virtual required const*
- `_get_doc_comment_delimiters() -> PackedStringArray` *virtual const*
- `_get_extension() -> String` *virtual required const*
- `_get_global_class_name(path: String) -> Dictionary` *virtual required const*
- `_get_name() -> String` *virtual required const*
- `_get_public_annotations() -> Dictionary[]` *virtual required const*
- `_get_public_constants() -> Dictionary` *virtual required const*
- `_get_public_functions() -> Dictionary[]` *virtual required const*
- `_get_recognized_extensions() -> PackedStringArray` *virtual const* *(deprecated)*
- `_get_reserved_words() -> PackedStringArray` *virtual required const*
- `_get_string_delimiters() -> PackedStringArray` *virtual required const*
- `_get_type() -> String` *virtual required const*
- `_handles_global_class_type(type: String) -> bool` *virtual required const*
- `_has_named_classes() -> bool` *virtual const* *(deprecated)*
- `_init() -> void` *virtual required*
- `_is_control_flow_keyword(keyword: String) -> bool` *virtual required const*
- `_is_using_templates() -> bool` *virtual required*
- `_lookup_code(code: String, symbol: String, path: String, owner: Object) -> Dictionary` *virtual required const*
- `_make_function(class_name: String, function_name: String, function_args: PackedStringArray) -> String` *virtual required const*
- `_make_template(template: String, class_name: String, base_class_name: String) -> Script` *virtual required const*
- `_open_in_external_editor(script: Script, line: int, column: int) -> int[Error]` *virtual required*
- `_overrides_external_editor() -> bool` *virtual required*
- `_preferred_file_name_casing() -> int[ScriptLanguage.ScriptNameCasing]` *virtual const*
- `_profiling_get_accumulated_data(info_array: ScriptLanguageExtensionProfilingInfo*, info_max: int) -> int` *virtual required*
- `_profiling_get_frame_data(info_array: ScriptLanguageExtensionProfilingInfo*, info_max: int) -> int` *virtual required*
- `_profiling_set_save_native_calls(enable: bool) -> void` *virtual required*
- `_profiling_start() -> void` *virtual required*
- `_profiling_stop() -> void` *virtual required*
- `_reload_all_scripts() -> void` *virtual required*
- `_reload_scripts(scripts: Array, soft_reload: bool) -> void` *virtual required* — Reloads all `scripts` from disk and the specifics of how that happens is ScriptLanguageExtension specific.
- `_reload_tool_script(script: Script, soft_reload: bool) -> void` *virtual required* — Reloads the given `script` from disk and the specifics of how that happens is ScriptLanguageExtension specific.
- `_remove_named_global_constant(name: StringName) -> void` *virtual required*
- `_supports_builtin_mode() -> bool` *virtual required const*
- `_supports_documentation() -> bool` *virtual required const*
- `_thread_enter() -> void` *virtual required*
- `_thread_exit() -> void` *virtual required*
- `_validate(script: String, path: String, validate_functions: bool, validate_errors: bool, validate_warnings: bool, validate_safe_lines: bool) -> Dictionary` *virtual required const*
- `_validate_path(path: String) -> String` *virtual required const*

## Enum LookupResultType

- `LOOKUP_RESULT_SCRIPT_LOCATION = 0` — 
- `LOOKUP_RESULT_CLASS = 1` — 
- `LOOKUP_RESULT_CLASS_CONSTANT = 2` — 
- `LOOKUP_RESULT_CLASS_PROPERTY = 3` — 
- `LOOKUP_RESULT_CLASS_METHOD = 4` — 
- `LOOKUP_RESULT_CLASS_SIGNAL = 5` — 
- `LOOKUP_RESULT_CLASS_ENUM = 6` — 
- `LOOKUP_RESULT_CLASS_TBD_GLOBALSCOPE = 7` — 
- `LOOKUP_RESULT_CLASS_ANNOTATION = 8` — 
- `LOOKUP_RESULT_LOCAL_CONSTANT = 9` — 
- `LOOKUP_RESULT_LOCAL_VARIABLE = 10` — 
- `LOOKUP_RESULT_MAX = 11` — 

## Enum CodeCompletionLocation

- `LOCATION_LOCAL = 0` — The option is local to the location of the code completion query - e.g. a local variable.
- `LOCATION_PARENT_MASK = 256` — The option is from the containing class or a parent class, relative to the location of the code completion query.
- `LOCATION_OTHER_USER_CODE = 512` — The option is from user code which is not local and not in a derived class (e.g.
- `LOCATION_OTHER = 1024` — The option is from other engine code, not covered by the other enum constants - e.g. built-in classes.

## Enum CodeCompletionKind

- `CODE_COMPLETION_KIND_CLASS = 0` — 
- `CODE_COMPLETION_KIND_FUNCTION = 1` — 
- `CODE_COMPLETION_KIND_SIGNAL = 2` — 
- `CODE_COMPLETION_KIND_VARIABLE = 3` — 
- `CODE_COMPLETION_KIND_MEMBER = 4` — 
- `CODE_COMPLETION_KIND_ENUM = 5` — 
- `CODE_COMPLETION_KIND_CONSTANT = 6` — 
- `CODE_COMPLETION_KIND_NODE_PATH = 7` — 
- `CODE_COMPLETION_KIND_FILE_PATH = 8` — 
- `CODE_COMPLETION_KIND_PLAIN_TEXT = 9` — 
- `CODE_COMPLETION_KIND_KEYWORD = 10` — 
- `CODE_COMPLETION_KIND_MAX = 11` —
