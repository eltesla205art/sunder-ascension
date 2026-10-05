# PackedVector4Array


A packed array of Vector4s.

An array specifically designed to hold Vector4. Packs data tightly, so it saves memory for large array sizes. Differences between packed arrays, typed arrays, and untyped arrays: Packed arrays are generally faster to iterate on and modify compared to a typed array of the same type (e.g. PackedVector4Array versus `ArrayVector4`).

## Constructors

- `PackedVector4Array() -> PackedVector4Array` — Constructs an empty PackedVector4Array.
- `PackedVector4Array(from: PackedVector4Array) -> PackedVector4Array` — Constructs a PackedVector4Array as a copy of the given PackedVector4Array.
- `PackedVector4Array(from: Array) -> PackedVector4Array` — Constructs a new PackedVector4Array.

## Methods

- `append(value: Vector4) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedVector4Array) -> void` — Appends a PackedVector4Array at the end of this array.
- `bsearch(value: Vector4, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: Vector4) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedVector4Array` *const* — Creates a copy of the array, and returns it.
- `erase(value: Vector4) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: Vector4) -> void` — Assigns the given value to all elements in the array.
- `find(value: Vector4, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> Vector4` *const* — Returns the Vector4 at the given `index` in the array.
- `has(value: Vector4) -> bool` *const* — Returns `true` if the array contains `value`.
- `insert(at_index: int, value: Vector4) -> int` — Inserts a new element at a given position in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty.
- `push_back(value: Vector4) -> bool` — Inserts a Vector4 at the end.
- `remove_at(index: int) -> void` — Removes an element from the array by index.
- `resize(new_size: int) -> int` — Sets the size of the array.
- `reverse() -> void` — Reverses the order of the elements in the array.
- `rfind(value: Vector4, from: int = -1) -> int` *const* — Searches the array in reverse order.
- `set(index: int, value: Vector4) -> void` — Changes the Vector4 at the given index.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647) -> PackedVector4Array` *const* — Returns the slice of the PackedVector4Array, from `begin` (inclusive) to `end` (exclusive), as a new PackedVector4Array.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a PackedByteArray with each vector encoded as bytes.

## Operators

- `operator !=(right: PackedVector4Array) -> bool` — Returns `true` if contents of the arrays differ.
- `operator +(right: PackedVector4Array) -> PackedVector4Array` — Returns a new PackedVector4Array with contents of `right` added at the end of this array.
- `operator ==(right: PackedVector4Array) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal Vector4s at the corresponding indices.
- `operator [](index: int) -> Vector4` — Returns the Vector4 at index `index`.
