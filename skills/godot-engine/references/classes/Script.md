# Script

**Inherits:** Resource

A class stored as a resource.

A class stored as a resource. A script extends the functionality of all objects that instantiate it. This is the base class for all scripts and should not be used directly. Trying to create a new script with this class will result in an error.

## Properties

- `source_code: String` — The script source code or an empty string if source code is not available.

## Methods

- `can_instantiate() -> bool` *const* — Returns `true` if the script can be instantiated.
- `get_base_script() -> Script` *const* — Returns the script directly inherited by this script.
- `get_global_name() -> StringName` *const* — Returns the class name associated with the script, if there is one.
- `get_instance_base_type() -> StringName` *const* — Returns the script's base type.
- `get_property_default_value(property: StringName) -> Variant` — Returns the default value of the specified property.
- `get_rpc_config() -> Variant` *const* — Returns a Dictionary mapping method names to their RPC configuration defined by this script.
- `get_script_constant_map() -> Dictionary` — Returns a dictionary containing constant names and their values.
- `get_script_method_list() -> Dictionary[]` — Returns the list of methods in this Script.
- `get_script_property_list() -> Dictionary[]` — Returns the list of properties in this Script.
- `get_script_signal_list() -> Dictionary[]` — Returns the list of signals defined in this Script.
- `has_script_method(method_name: StringName) -> bool` *const* — Returns `true` if the script, or a base class, defines a method with the given name.
- `has_script_signal(signal_name: StringName) -> bool` *const* — Returns `true` if the script, or a base class, defines a signal with the given name.
- `has_source_code() -> bool` *const* — Returns `true` if the script contains non-empty source code.
- `instance_has(base_object: Object) -> bool` *const* *(deprecated)* — Returns `true` if `base_object` is an instance of this script.
- `is_abstract() -> bool` *const* — Returns `true` if the script is an abstract script.
- `is_tool() -> bool` *const* — Returns `true` if the script is a tool script.
- `reload(keep_state: bool = false) -> int[Error]` — Reloads the script's class implementation.
