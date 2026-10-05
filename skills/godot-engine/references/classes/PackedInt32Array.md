# PackedInt32Array


A packed array of 32-bit integers.

An array specifically designed to hold 32-bit integer values. Packs data tightly, so it saves memory for large array sizes. Note: This type stores signed 32-bit integers, which means it can take values in the interval `[-2^31, 2^31 - 1]`, i.e. `[-2147483648, 2147483647]`.

## Constructors

- `PackedInt32Array() -> PackedInt32Array` — Constructs an empty PackedInt32Array.
- `PackedInt32Array(from: PackedInt32Array) -> PackedInt32Array` — Constructs a PackedInt32Array as a copy of the given PackedInt32Array.
- `PackedInt32Array(from: Array) -> PackedInt32Array` — Constructs a new PackedInt32Array.

## Methods

- `append(value: int) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedInt32Array) -> void` — Appends a PackedInt32Array at the end of this array.
- `bsearch(value: int, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: int) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedInt32Array` *const* — Creates a copy of the array, and returns it.
- `erase(value: int) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: int) -> void` — Assigns the given value to all elements in the array.
- `find(value: int, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> int` *const* — Returns the 32-bit integer at the given `index` in the array.
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
- `slice(begin: int, end: int = 2147483647) -> PackedInt32Array` *const* — Returns the slice of the PackedInt32Array, from `begin` (inclusive) to `end` (exclusive), as a new PackedInt32Array.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a copy of the data converted to a PackedByteArray, where each element has been encoded as 4 bytes.

## Operators

- `operator !=(right: PackedInt32Array) -> bool` — Returns `true` if contents of the arrays differ.
- `operator +(right: PackedInt32Array) -> PackedInt32Array` — Returns a new PackedInt32Array with contents of `right` added at the end of this array.
- `operator ==(right: PackedInt32Array) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal ints at the corresponding indices.
- `operator [](index: int) -> int` — Returns the int at index `index`.
