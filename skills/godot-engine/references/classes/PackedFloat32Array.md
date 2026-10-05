# PackedFloat32Array


A packed array of 32-bit floating-point values.

An array specifically designed to hold 32-bit floating-point values (float). Packs data tightly, so it saves memory for large array sizes. If you need to pack 64-bit floats tightly, see PackedFloat64Array. Note: Packed arrays are always passed by reference.

## Constructors

- `PackedFloat32Array() -> PackedFloat32Array` — Constructs an empty PackedFloat32Array.
- `PackedFloat32Array(from: PackedFloat32Array) -> PackedFloat32Array` — Constructs a PackedFloat32Array as a copy of the given PackedFloat32Array.
- `PackedFloat32Array(from: Array) -> PackedFloat32Array` — Constructs a new PackedFloat32Array.

## Methods

- `append(value: float) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedFloat32Array) -> void` — Appends a PackedFloat32Array at the end of this array.
- `bsearch(value: float, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: float) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedFloat32Array` *const* — Creates a copy of the array, and returns it.
- `erase(value: float) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: float) -> void` — Assigns the given value to all elements in the array.
- `find(value: float, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> float` *const* — Returns the 32-bit float at the given `index` in the array.
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
- `slice(begin: int, end: int = 2147483647) -> PackedFloat32Array` *const* — Returns the slice of the PackedFloat32Array, from `begin` (inclusive) to `end` (exclusive), as a new PackedFloat32Array.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a copy of the data converted to a PackedByteArray, where each element has been encoded as 4 bytes.

## Operators

- `operator !=(right: PackedFloat32Array) -> bool` — Returns `true` if contents of the arrays differ.
- `operator +(right: PackedFloat32Array) -> PackedFloat32Array` — Returns a new PackedFloat32Array with contents of `right` added at the end of this array.
- `operator ==(right: PackedFloat32Array) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal floats at the corresponding indices.
- `operator [](index: int) -> float` — Returns the float at index `index`.
