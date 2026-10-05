# PackedVector3Array


A packed array of Vector3s.

An array specifically designed to hold Vector3. Packs data tightly, so it saves memory for large array sizes. Differences between packed arrays, typed arrays, and untyped arrays: Packed arrays are generally faster to iterate on and modify compared to a typed array of the same type (e.g. PackedVector3Array versus `ArrayVector3`).

## Constructors

- `PackedVector3Array() -> PackedVector3Array` — Constructs an empty PackedVector3Array.
- `PackedVector3Array(from: PackedVector3Array) -> PackedVector3Array` — Constructs a PackedVector3Array as a copy of the given PackedVector3Array.
- `PackedVector3Array(from: Array) -> PackedVector3Array` — Constructs a new PackedVector3Array.

## Methods

- `append(value: Vector3) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedVector3Array) -> void` — Appends a PackedVector3Array at the end of this array.
- `bsearch(value: Vector3, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `clear() -> void` — Clears the array.
- `count(value: Vector3) -> int` *const* — Returns the number of times an element is in the array.
- `duplicate() -> PackedVector3Array` *const* — Creates a copy of the array, and returns it.
- `erase(value: Vector3) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: Vector3) -> void` — Assigns the given value to all elements in the array.
- `find(value: Vector3, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> Vector3` *const* — Returns the Vector3 at the given `index` in the array.
- `has(value: Vector3) -> bool` *const* — Returns `true` if the array contains `value`.
- `insert(at_index: int, value: Vector3) -> int` — Inserts a new element at a given position in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty.
- `push_back(value: Vector3) -> bool` — Inserts a Vector3 at the end.
- `remove_at(index: int) -> void` — Removes an element from the array by index.
- `resize(new_size: int) -> int` — Sets the size of the array.
- `reverse() -> void` — Reverses the order of the elements in the array.
- `rfind(value: Vector3, from: int = -1) -> int` *const* — Searches the array in reverse order.
- `set(index: int, value: Vector3) -> void` — Changes the Vector3 at the given index.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647) -> PackedVector3Array` *const* — Returns the slice of the PackedVector3Array, from `begin` (inclusive) to `end` (exclusive), as a new PackedVector3Array.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_byte_array() -> PackedByteArray` *const* — Returns a PackedByteArray with each vector encoded as bytes.

## Operators

- `operator !=(right: PackedVector3Array) -> bool` — Returns `true` if contents of the arrays differ.
- `operator *(right: Transform3D) -> PackedVector3Array` — Returns a new PackedVector3Array with all vectors in this array inversely transformed (multiplied) by the given Transform3D transformation matrix, under the assumption that the transformation basis is orthonormal (i.e. rotation/reflection is fine, scaling/skew is not).
- `operator +(right: PackedVector3Array) -> PackedVector3Array` — Returns a new PackedVector3Array with contents of `right` added at the end of this array.
- `operator ==(right: PackedVector3Array) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal Vector3s at the corresponding indices.
- `operator [](index: int) -> Vector3` — Returns the Vector3 at index `index`.
