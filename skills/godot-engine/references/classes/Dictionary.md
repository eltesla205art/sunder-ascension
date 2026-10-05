# Dictionary


A built-in data structure that holds key-value pairs.

Dictionaries are associative containers that contain values referenced by unique keys. Dictionaries will preserve the insertion order when adding new entries. In other programming languages, this data structure is often referred to as a hash map or an associative array. You can define a dictionary by placing a comma-separated list of `key: value` pairs inside curly braces `{}`.

## Constructors

- `Dictionary() -> Dictionary` — Constructs an empty Dictionary.
- `Dictionary(base: Dictionary, key_type: int, key_class_name: StringName, key_script: Variant, value_type: int, value_class_name: StringName, value_script: Variant) -> Dictionary` — Creates a typed dictionary from the `base` dictionary.
- `Dictionary(from: Dictionary) -> Dictionary` — Returns the same dictionary as `from`.

## Methods

- `assign(dictionary: Dictionary) -> void` — Assigns elements of another `dictionary` into the dictionary.
- `clear() -> void` — Clears the dictionary, removing all entries from it.
- `duplicate(deep: bool = false) -> Dictionary` *const* — Returns a new copy of the dictionary.
- `duplicate_deep(deep_subresources_mode: int = 1) -> Dictionary` *const* — Duplicates this dictionary, deeply, like `duplicate` when passing `true`, with extra control over how subresources are handled.
- `erase(key: Variant) -> bool` — Removes the dictionary entry by key, if it exists.
- `find_key(value: Variant) -> Variant` *const* — Finds and returns the first key whose associated value is equal to `value`, or `null` if it is not found.
- `get(key: Variant, default: Variant = null) -> Variant` *const* — Returns the corresponding value for the given `key` in the dictionary.
- `get_or_add(key: Variant, default: Variant = null) -> Variant` — Gets a value and ensures the key is set.
- `get_typed_key_builtin() -> int` *const* — Returns the built-in Variant type of the typed dictionary's keys as a `Variant.Type` constant.
- `get_typed_key_class_name() -> StringName` *const* — Returns the built-in class name of the typed dictionary's keys, if the built-in Variant type is `TYPE_OBJECT`.
- `get_typed_key_script() -> Variant` *const* — Returns the Script instance associated with this typed dictionary's keys, or `null` if it does not exist.
- `get_typed_value_builtin() -> int` *const* — Returns the built-in Variant type of the typed dictionary's values as a `Variant.Type` constant.
- `get_typed_value_class_name() -> StringName` *const* — Returns the built-in class name of the typed dictionary's values, if the built-in Variant type is `TYPE_OBJECT`.
- `get_typed_value_script() -> Variant` *const* — Returns the Script instance associated with this typed dictionary's values, or `null` if it does not exist.
- `has(key: Variant) -> bool` *const* — Returns `true` if the dictionary contains an entry with the given `key`.
- `has_all(keys: Array) -> bool` *const* — Returns `true` if the dictionary contains all keys in the given `keys` array.
- `hash() -> int` *const* — Returns a hashed 32-bit integer value representing the dictionary contents.
- `is_empty() -> bool` *const* — Returns `true` if the dictionary is empty (its size is `0`).
- `is_read_only() -> bool` *const* — Returns `true` if the dictionary is read-only.
- `is_same_typed(dictionary: Dictionary) -> bool` *const* — Returns `true` if the dictionary is typed the same as `dictionary`.
- `is_same_typed_key(dictionary: Dictionary) -> bool` *const* — Returns `true` if the dictionary's keys are typed the same as `dictionary`'s keys.
- `is_same_typed_value(dictionary: Dictionary) -> bool` *const* — Returns `true` if the dictionary's values are typed the same as `dictionary`'s values.
- `is_typed() -> bool` *const* — Returns `true` if the dictionary is typed.
- `is_typed_key() -> bool` *const* — Returns `true` if the dictionary's keys are typed.
- `is_typed_value() -> bool` *const* — Returns `true` if the dictionary's values are typed.
- `keys() -> Array` *const* — Returns the list of keys in the dictionary.
- `make_read_only() -> void` — Makes the dictionary read-only, i.e. disables modification of the dictionary's contents.
- `merge(dictionary: Dictionary, overwrite: bool = false) -> void` — Adds entries from `dictionary` to this dictionary.
- `merged(dictionary: Dictionary, overwrite: bool = false) -> Dictionary` *const* — Returns a copy of this dictionary merged with the other `dictionary`.
- `recursive_equal(dictionary: Dictionary, recursion_count: int) -> bool` *const* — Returns `true` if the two dictionaries contain the same keys and values, inner Dictionary and Array keys and values are compared recursively.
- `set(key: Variant, value: Variant) -> bool` — Sets the value of the element at the given `key` to the given `value`.
- `size() -> int` *const* — Returns the number of entries in the dictionary.
- `sort() -> void` — Sorts the dictionary in ascending order, by key.
- `values() -> Array` *const* — Returns the list of values in this dictionary.

## Operators

- `operator !=(right: Dictionary) -> bool` — Returns `true` if the two dictionaries do not contain the same keys and values.
- `operator ==(right: Dictionary) -> bool` — Returns `true` if the two dictionaries contain the same keys and values.
- `operator [](key: Variant) -> Variant` — Returns the corresponding value for the given `key` in the dictionary.
