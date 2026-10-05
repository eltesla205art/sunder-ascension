# PackedInt64Array


A packed array of 64-bit integers.

An array specifically designed to hold 64-bit integer values. Packs data tightly, so it saves memory for large array sizes. Note: This type stores signed 64-bit integers, which means it can take values in the interval `[-2^63, 2^63 - 1]`, i.e. `[-9223372036854775808, 9223372036854775807]`.

## Constructors

- `PackedInt64Array() -> PackedInt64Array` — Constructs an empty PackedInt64Array.
- `PackedInt64Array(from: PackedInt64Array) -> PackedInt64Array` — Constructs a PackedInt64Array as a copy of the given PackedInt64Array.
- `PackedInt64Array(from: Array) -> PackedInt64Array` — Constructs a new PackedInt64Array.

## Methods

- `append(value: int) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedInt64Array) -> void` — Appends a PackedInt64Array at the end of this array.
- `bsearch(value: int, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: int) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedInt64Array` *const* — Creates a copy of the array, and returns it.
- `erase(value: int) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: int) -> void` — Assigns the given value to all elements in the array.
- `find(value: int, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> int` *const* — Returns the 64-bit integer at the given `index` in the array.
- `has(value: int) -> bool` *const* — Returns `true` if the array contains `value`.
- `insert(at_index: int, value: int) -> int` — Inserts a new integer at a given position in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty.
- `push_back(value: int) -> bool` — Appends a value to the array.
- `remove_at(index: int) -> void` — Removes an element from the array by index.
- `resize(new_size: int) -> int` — Sets the size of the array.
- `reverse() -> void` — Reverses the order of the elements in the array.
- `rfind(value: int, from: int = -1) -> int` *const* — Searches the array in reverse order.
- `set(index: int, value: int) -> void` — Changes the integer at the given index.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647) -> PackedInt64Array` *const* — Returns the slice of the PackedInt64Array, from `begin` (inclusive) to `end` (exclusive), as a new PackedInt64Array.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a copy of the data converted to a PackedByteArray, where each element has been encoded as 8 bytes.

## Operators

- `operator !=(right: PackedInt64Array) -> bool` — Returns `true` if contents of the arrays differ.
- `operator +(right: PackedInt64Array) -> PackedInt64Array` — Returns a new PackedInt64Array with contents of `right` added at the end of this array.
- `operator ==(right: PackedInt64Array) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal ints at the corresponding indices.
- `operator [](index: int) -> int` — Returns the int at index `index`.
