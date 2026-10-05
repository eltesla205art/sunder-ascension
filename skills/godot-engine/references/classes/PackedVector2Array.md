# PackedVector2Array


A packed array of Vector2s.

An array specifically designed to hold Vector2. Packs data tightly, so it saves memory for large array sizes. Differences between packed arrays, typed arrays, and untyped arrays: Packed arrays are generally faster to iterate on and modify compared to a typed array of the same type (e.g. PackedVector2Array versus `ArrayVector2`).

## Constructors

- `PackedVector2Array() -> PackedVector2Array` — Constructs an empty PackedVector2Array.
- `PackedVector2Array(from: PackedVector2Array) -> PackedVector2Array` — Constructs a PackedVector2Array as a copy of the given PackedVector2Array.
- `PackedVector2Array(from: Array) -> PackedVector2Array` — Constructs a new PackedVector2Array.

## Methods

- `append(value: Vector2) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedVector2Array) -> void` — Appends a PackedVector2Array at the end of this array.
- `bsearch(value: Vector2, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: Vector2) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedVector2Array` *const* — Creates a copy of the array, and returns it.
- `erase(value: Vector2) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: Vector2) -> void` — Assigns the given value to all elements in the array.
- `find(value: Vector2, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> Vector2` *const* — Returns the Vector2 at the given `index` in the array.
- `has(value: Vector2) -> bool` *const* — Returns `true` if the array contains `value`.
- `insert(at_index: int, value: Vector2) -> int` — Inserts a new element at a given position in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty.
- `push_back(value: Vector2) -> bool` — Inserts a Vector2 at the end.
- `remove_at(index: int) -> void` — Removes an element from the array by index.
- `resize(new_size: int) -> int` — Sets the size of the array.
- `reverse() -> void` — Reverses the order of the elements in the array.
- `rfind(value: Vector2, from: int = -1) -> int` *const* — Searches the array in reverse order.
- `set(index: int, value: Vector2) -> void` — Changes the Vector2 at the given index.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647) -> PackedVector2Array` *const* — Returns the slice of the PackedVector2Array, from `begin` (inclusive) to `end` (exclusive), as a new PackedVector2Array.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a PackedByteArray with each vector encoded as bytes.

## Operators

- `operator !=(right: PackedVector2Array) -> bool` — Returns `true` if contents of the arrays differ.
- `operator *(right: Transform2D) -> PackedVector2Array` — Returns a new PackedVector2Array with all vectors in this array inversely transformed (multiplied) by the given Transform2D transformation matrix, under the assumption that the transformation basis is orthonormal (i.e. rotation/reflection is fine, scaling/skew is not).
- `operator +(right: PackedVector2Array) -> PackedVector2Array` — Returns a new PackedVector2Array with contents of `right` added at the end of this array.
- `operator ==(right: PackedVector2Array) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal Vector2s at the corresponding indices.
- `operator [](index: int) -> Vector2` — Returns the Vector2 at index `index`.
