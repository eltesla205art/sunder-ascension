# ClassDB

**Inherits:** Object

A class information repository.

Provides access to metadata stored for every available engine class. Note: Script-defined classes with `class_name` are not part of ClassDB, so they will not return reflection data such as a method or property list. However, GDExtension-defined classes are part of ClassDB, so they will return reflection data.

## Methods

- `can_instantiate(class: StringName) -> bool` *const* — Returns `true` if objects can be instantiated from the specified `class`, otherwise returns `false`.
- `class_call_static(class: StringName, method: StringName) -> Variant` *vararg* — Calls a static method on a class.
- `class_exists(class: StringName) -> bool` *const* — Returns whether the specified `class` is available or not.
- `class_get_api_type(class: StringName) -> int[ClassDB.APIType]` *const* — Returns the API type of the specified `class`.
- `class_get_enum_constants(class: StringName, enum: StringName, no_inheritance: bool = false) -> PackedStringArray` *const* — Returns an array with all the keys in `enum` of `class` or its ancestry.
- `class_get_enum_list(class: StringName, no_inheritance: bool = false) -> PackedStringArray` *const* — Returns an array with all the enums of `class` or its ancestry.
- `class_get_integer_constant(class: StringName, name: StringName) -> int` *const* — Returns the value of the integer constant `name` of `class` or its ancestry.
- `class_get_integer_constant_enum(class: StringName, name: StringName, no_inheritance: bool = false) -> StringName` *const* — Returns which enum the integer constant `name` of `class` or its ancestry belongs to.
- `class_get_integer_constant_list(class: StringName, no_inheritance: bool = false) -> PackedStringArray` *const* — Returns an array with the names all the integer constants of `class` or its ancestry.
- `class_get_method_argument_count(class: StringName, method: StringName, no_inheritance: bool = false) -> int` *const* — Returns the number of arguments of the method `method` of `class` or its ancestry if `no_inheritance` is `false`.
- `class_get_method_list(class: StringName, no_inheritance: bool = false) -> Dictionary[]` *const* — Returns an array with all the methods of `class` or its ancestry if `no_inheritance` is `false`.
- `class_get_property(object: Object, property: StringName) -> Variant` *const* — Returns the value of `property` of `object` or its ancestry.
- `class_get_property_default_value(class: StringName, property: StringName) -> Variant` *const* — Returns the default value of `property` of `class` or its ancestor classes.
- `class_get_property_getter(class: StringName, property: StringName) -> StringName` — Returns the getter method name of `property` of `class`.
- `class_get_property_list(class: StringName, no_inheritance: bool = false) -> Dictionary[]` *const* — Returns an array with all the properties of `class` or its ancestry if `no_inheritance` is `false`.
- `class_get_property_setter(class: StringName, property: StringName) -> StringName` — Returns the setter method name of `property` of `class`.
- `class_get_signal(class: StringName, signal: StringName) -> Dictionary` *const* — Returns the `signal` data of `class` or its ancestry.
- `class_get_signal_list(class: StringName, no_inheritance: bool = false) -> Dictionary[]` *const* — Returns an array with all the signals of `class` or its ancestry if `no_inheritance` is `false`.
- `class_has_enum(class: StringName, name: StringName, no_inheritance: bool = false) -> bool` *const* — Returns whether `class` or its ancestry has an enum called `name` or not.
- `class_has_integer_constant(class: StringName, name: StringName) -> bool` *const* — Returns whether `class` or its ancestry has an integer constant called `name` or not.
- `class_has_method(class: StringName, method: StringName, no_inheritance: bool = false) -> bool` *const* — Returns whether `class` (or its ancestry if `no_inheritance` is `false`) has a method called `method` or not.
- `class_has_signal(class: StringName, signal: StringName) -> bool` *const* — Returns whether `class` or its ancestry has a signal called `signal` or not.
- `class_set_property(object: Object, property: StringName, value: Variant) -> int[Error]` *const* — Sets `property` value of `object` to `value`.
- `get_class_list() -> PackedStringArray` *const* — Returns the names of all engine classes available.
- `get_inheriters_from_class(class: StringName) -> PackedStringArray` *const* — Returns the names of all engine classes that directly or indirectly inherit from `class`.
- `get_parent_class(class: StringName) -> StringName` *const* — Returns the parent class of `class`.
- `instantiate(class: StringName) -> Variant` *const* — Creates an instance of `class`.
- `is_class_enabled(class: StringName) -> bool` *const* — Returns whether this `class` is enabled or not.
- `is_class_enum_bitfield(class: StringName, enum: StringName, no_inheritance: bool = false) -> bool` *const* — Returns whether `class` (or its ancestor classes if `no_inheritance` is `false`) has an enum called `enum` that is a bitfield.
- `is_class_exposed(class: StringName) -> bool` *const* — Returns whether this `class` is exposed or not.
- `is_parent_class(class: StringName, inherits: StringName) -> bool` *const* — Returns whether `inherits` is an ancestor of `class` or not.

## Enum APIType

- `API_CORE = 0` — Native Core class type.
- `API_EDITOR = 1` — Native Editor class type.
- `API_EXTENSION = 2` — GDExtension class type.
- `API_EDITOR_EXTENSION = 3` — GDExtension Editor class type.
- `API_NONE = 4` — Unknown class type.
