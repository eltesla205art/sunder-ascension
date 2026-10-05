# PackedColorArray


A packed array of Colors.

An array specifically designed to hold Color. Packs data tightly, so it saves memory for large array sizes. Differences between packed arrays, typed arrays, and untyped arrays: Packed arrays are generally faster to iterate on and modify compared to a typed array of the same type (e.g. PackedColorArray versus `ArrayColor`).

## Constructors

- `PackedColorArray() -> PackedColorArray` — Constructs an empty PackedColorArray.
- `PackedColorArray(from: PackedColorArray) -> PackedColorArray` — Constructs a PackedColorArray as a copy of the given PackedColorArray.
- `PackedColorArray(from: Array) -> PackedColorArray` — Constructs a new PackedColorArray.

## Methods

- `append(value: Color) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedColorArray) -> void` — Appends a PackedColorArray at the end of this array.
- `bsearch(value: Color, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: Color) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedColorArray` *const* — Creates a copy of the array, and returns it.
- `erase(value: Color) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: Color) -> void` — Assigns the given value to all elements in the array.
- `find(value: Color, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> Color` *const* — Returns the Color at the given `index` in the array.
- `has(value: Color) -> bool` *const* — Returns `true` if the array contains `value`.
- `insert(at_index: int, value: Color) -> int` — Inserts a new element at a given position in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty.
- `push_back(value: Color) -> bool` — Appends a value to the array.
- `remove_at(index: int) -> void` — Removes an element from the array by index.
- `resize(new_size: int) -> int` — Sets the size of the array.
- `reverse() -> void` — Reverses the order of the elements in the array.
- `rfind(value: Color, from: int = -1) -> int` *const* — Searches the array in reverse order.
- `set(index: int, value: Color) -> void` — Changes the Color at the given index.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647) -> PackedColorArray` *const* — Returns the slice of the PackedColorArray, from `begin` (inclusive) to `end` (exclusive), as a new PackedColorArray.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a PackedByteArray with each color encoded as bytes.

## Operators

- `operator !=(right: PackedColorArray) -> bool` — Returns `true` if contents of the arrays differ.
- `operator +(right: PackedColorArray) -> PackedColorArray` — Returns a new PackedColorArray with contents of `right` added at the end of this array.
- `operator ==(right: PackedColorArray) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal Colors at the corresponding indices.
- `operator [](index: int) -> Color` — Returns the Color at index `index`.
