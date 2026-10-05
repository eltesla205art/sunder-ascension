# PackedFloat64Array


A packed array of 64-bit floating-point values.

An array specifically designed to hold 64-bit floating-point values (double). Packs data tightly, so it saves memory for large array sizes. If you only need to pack 32-bit floats tightly, see PackedFloat32Array for a more memory-friendly alternative. Differences between packed arrays, typed arrays, and untyped arrays: Packed arrays are generally faster to iterate on and modify compared to a typed array of the same type (e.g.

## Constructors

- `PackedFloat64Array() -> PackedFloat64Array` — Constructs an empty PackedFloat64Array.
- `PackedFloat64Array(from: PackedFloat64Array) -> PackedFloat64Array` — Constructs a PackedFloat64Array as a copy of the given PackedFloat64Array.
- `PackedFloat64Array(from: Array) -> PackedFloat64Array` — Constructs a new PackedFloat64Array.

## Methods

- `append(value: float) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedFloat64Array) -> void` — Appends a PackedFloat64Array at the end of this array.
- `bsearch(value: float, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: float) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedFloat64Array` *const* — Creates a copy of the array, and returns it.
- `erase(value: float) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: float) -> void` — Assigns the given value to all elements in the array.
- `find(value: float, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> float` *const* — Returns the 64-bit float at the given `index` in the array.
- `has(value: float) -> bool` *const* — Returns `true` if the array contains `value`.
- `insert(at_index: int, value: float) -> int` — Inserts a new element at a given position in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty.
- `push_back(value: float) -> bool` — Appends an element at the end of the array.
- `remove_at(index: int) -> void` — Removes an element from the array by index.
- `resize(new_size: int) -> int` — Sets the size of the array.
- `reverse() -> void` — Reverses the order of the elements in the array.
- `rfind(value: float, from: int = -1) -> int` *const* — Searches the array in reverse order.
- `set(index: int, value: float) -> void` — Changes the float at the given index.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647) -> PackedFloat64Array` *const* — Returns the slice of the PackedFloat64Array, from `begin` (inclusive) to `end` (exclusive), as a new PackedFloat64Array.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a copy of the data converted to a PackedByteArray, where each element has been encoded as 8 bytes.

## Operators

- `operator !=(right: PackedFloat64Array) -> bool` — Returns `true` if contents of the arrays differ.
- `operator +(right: PackedFloat64Array) -> PackedFloat64Array` — Returns a new PackedFloat64Array with contents of `right` added at the end of this array.
- `operator ==(right: PackedFloat64Array) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal doubles at the corresponding indices.
- `operator [](index: int) -> float` — Returns the float at index `index`.
