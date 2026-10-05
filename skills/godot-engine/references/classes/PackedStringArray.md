# PackedStringArray


A packed array of Strings.

An array specifically designed to hold Strings. Packs data tightly, so it saves memory for large array sizes. If you want to join the strings in the array, use `String.join`. Differences between packed arrays, typed arrays, and untyped arrays: Packed arrays are generally faster to iterate on and modify compared to a typed array of the same type (e.g.

## Constructors

- `PackedStringArray() -> PackedStringArray` — Constructs an empty PackedStringArray.
- `PackedStringArray(from: PackedStringArray) -> PackedStringArray` — Constructs a PackedStringArray as a copy of the given PackedStringArray.
- `PackedStringArray(from: Array) -> PackedStringArray` — Constructs a new PackedStringArray.

## Methods

- `append(value: String) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedStringArray) -> void` — Appends a PackedStringArray at the end of this array.
- `bsearch(value: String, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: String) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedStringArray` *const* — Creates a copy of the array, and returns it.
- `erase(value: String) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: String) -> void` — Assigns the given value to all elements in the array.
- `find(value: String, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> String` *const* — Returns the String at the given `index` in the array.
- `has(value: String) -> bool` *const* — Returns `true` if the array contains `value`.
- `insert(at_index: int, value: String) -> int` — Inserts a new element at a given position in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty.
- `push_back(value: String) -> bool` — Appends a string element at end of the array.
- `remove_at(index: int) -> void` — Removes an element from the array by index.
- `resize(new_size: int) -> int` — Sets the size of the array.
- `reverse() -> void` — Reverses the order of the elements in the array.
- `rfind(value: String, from: int = -1) -> int` *const* — Searches the array in reverse order.
- `set(index: int, value: String) -> void` — Changes the String at the given index.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647) -> PackedStringArray` *const* — Returns the slice of the PackedStringArray, from `begin` (inclusive) to `end` (exclusive), as a new PackedStringArray.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a PackedByteArray with each string encoded as UTF-8.

## Operators

- `operator !=(right: PackedStringArray) -> bool` — Returns `true` if contents of the arrays differ.
- `operator +(right: PackedStringArray) -> PackedStringArray` — Returns a new PackedStringArray with contents of `right` added at the end of this array.
- `operator ==(right: PackedStringArray) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal Strings at the corresponding indices.
- `operator [](index: int) -> String` — Returns the String at index `index`.
