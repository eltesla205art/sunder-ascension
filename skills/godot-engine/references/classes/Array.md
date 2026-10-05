# Array


A built-in data structure that holds a sequence of elements.

An array data structure that can contain a sequence of elements of any Variant type by default. Values can optionally be constrained to a specific type by creating a typed array. Elements are accessed by a numerical index starting at `0`. Negative indices are used to count from the back (`-1` is the last element, `-2` is the second to last, etc.).

## Constructors

- `Array() -> Array` — Constructs an empty Array.
- `Array(base: Array, type: int, class_name: StringName, script: Variant) -> Array` — Creates a typed array from the `base` array.
- `Array(from: Array) -> Array` — Returns the same array as `from`.
- `Array(from: PackedByteArray) -> Array` — Constructs an array from a PackedByteArray.
- `Array(from: PackedColorArray) -> Array` — Constructs an array from a PackedColorArray.
- `Array(from: PackedFloat32Array) -> Array` — Constructs an array from a PackedFloat32Array.
- `Array(from: PackedFloat64Array) -> Array` — Constructs an array from a PackedFloat64Array.
- `Array(from: PackedInt32Array) -> Array` — Constructs an array from a PackedInt32Array.
- `Array(from: PackedInt64Array) -> Array` — Constructs an array from a PackedInt64Array.
- `Array(from: PackedStringArray) -> Array` — Constructs an array from a PackedStringArray.
- `Array(from: PackedVector2Array) -> Array` — Constructs an array from a PackedVector2Array.
- `Array(from: PackedVector3Array) -> Array` — Constructs an array from a PackedVector3Array.
- `Array(from: PackedVector4Array) -> Array` — Constructs an array from a PackedVector4Array.

## Methods

- `all(callable: Callable) -> bool` *const* — Calls the given Callable on each element in the array and returns `true` if the Callable returns `true` for all elements in the array.
- `any(callable: Callable) -> bool` *const* — Calls the given Callable on each element in the array and returns `true` if the Callable returns `true` for one or more elements in the array.
- `append(value: Variant) -> void` — Appends `value` at the end of the array (alias of `push_back`).
- `append_array(array: Array) -> void` — Appends another `array` at the end of this array.
- `assign(array: Array) -> void` — Assigns elements of another `array` into the array.
- `back() -> Variant` *const* — Returns the last element of the array.
- `bsearch(value: Variant, before: bool = true) -> int` *const* — Returns the index of `value` in the sorted array.
- `bsearch_custom(value: Variant, func: Callable, before: bool = true) -> int` *const* — Returns the index of `value` in the sorted array.
- `clear() -> void` — Removes all elements from the array.
- `count(value: Variant) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate(deep: bool = false) -> Array` *const* — Returns a new copy of the array.
- `duplicate_deep(deep_subresources_mode: int = 1) -> Array` *const* — Duplicates this array, deeply, like `duplicate` when passing `true`, with extra control over how subresources are handled.
- `erase(value: Variant) -> void` — Finds and removes the first occurrence of `value` from the array.
- `fill(value: Variant) -> void` — Assigns the given `value` to all elements in the array.
- `filter(callable: Callable) -> Array` *const* — Calls the given Callable on each element in the array and returns a new, filtered Array.
- `find(what: Variant, from: int = 0) -> int` *const* — Returns the index of the first occurrence of `what` in this array, or `-1` if there are none.
- `find_custom(callable: Callable, from: int = 0) -> int` *const* — Returns the index of the first element in the array that causes `callable` to return `true`, or `-1` if there are none.
- `front() -> Variant` *const* — Returns the first element of the array.
- `get(index: int) -> Variant` *const* — Returns the element at the given `index` in the array.
- `get_typed_builtin() -> int` *const* — Returns the built-in Variant type of the typed array as a `Variant.Type` constant.
- `get_typed_class_name() -> StringName` *const* — Returns the built-in class name of the typed array, if the built-in Variant type `TYPE_OBJECT`.
- `get_typed_script() -> Variant` *const* — Returns the Script instance associated with this typed array, or `null` if it does not exist.
- `has(value: Variant) -> bool` *const* — Returns `true` if the array contains the given `value`.
- `hash() -> int` *const* — Returns a hashed 32-bit integer value representing the array and its contents.
- `insert(position: int, value: Variant) -> int` — Inserts a new element (`value`) at a given index (`position`) in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty (`[]`).
- `is_read_only() -> bool` *const* — Returns `true` if the array is read-only.
- `is_same_typed(array: Array) -> bool` *const* — Returns `true` if this array is typed the same as the given `array`.
- `is_typed() -> bool` *const* — Returns `true` if the array is typed.
- `make_read_only() -> void` — Makes the array read-only.
- `map(callable: Callable) -> Array` *const* — Calls the given Callable for each element in the array and returns a new array filled with values returned by the `callable`.
- `max() -> Variant` *const* — Returns the maximum value contained in the array, if all elements can be compared.
- `min() -> Variant` *const* — Returns the minimum value contained in the array, if all elements can be compared.
- `pick_random() -> Variant` *const* — Returns a random element from the array.
- `pop_at(position: int) -> Variant` — Removes and returns the element of the array at index `position`.
- `pop_back() -> Variant` — Removes and returns the last element of the array.
- `pop_front() -> Variant` — Removes and returns the first element of the array.
- `push_back(value: Variant) -> void` — Appends an element at the end of the array.
- `push_front(value: Variant) -> void` — Adds an element at the beginning of the array.
- `reduce(callable: Callable, accum: Variant = null) -> Variant` *const* — Calls the given Callable for each element in array, accumulates the result in `accum`, then returns it.
- `remove_at(position: int) -> void` — Removes the element from the array at the given index (`position`).
- `resize(size: int) -> int` — Sets the array's number of elements to `size`.
- `reverse() -> void` — Reverses the order of all elements in the array.
- `rfind(what: Variant, from: int = -1) -> int` *const* — Returns the index of the last occurrence of `what` in this array, or `-1` if there are none.
- `rfind_custom(callable: Callable, from: int = -1) -> int` *const* — Returns the index of the last element of the array that causes `callable` to return `true`, or `-1` if there are none.
- `set(index: int, value: Variant) -> void` — Sets the value of the element at the given `index` to the given `value`.
- `shuffle() -> void` — Shuffles all elements of the array in a random order.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647, step: int = 1, deep: bool = false) -> Array` *const* — Returns a new Array containing this array's elements, from index `begin` (inclusive) to `end` (exclusive), every `step` elements.
- `sort() -> void` — Sorts the array in ascending order.
- `sort_custom(func: Callable) -> void` — Sorts the array using a custom Callable.

## Operators

- `operator !=(right: Array) -> bool` — Returns `true` if the array's size or its elements are different than `right`'s.
- `operator +(right: Array) -> Array` — Appends the `right` array to the left operand, creating a new Array.
- `operator <(right: Array) -> bool` — Compares the elements of both arrays in order, starting from index `0` and ending on the last index in common between both arrays.
- `operator <=(right: Array) -> bool` — Compares the elements of both arrays in order, starting from index `0` and ending on the last index in common between both arrays.
- `operator ==(right: Array) -> bool` — Compares the left operand Array against the `right` Array.
- `operator >(right: Array) -> bool` — Compares the elements of both arrays in order, starting from index `0` and ending on the last index in common between both arrays.
- `operator >=(right: Array) -> bool` — Compares the elements of both arrays in order, starting from index `0` and ending on the last index in common between both arrays.
- `operator [](index: int) -> Variant` — Returns the Variant element at the specified `index`.
