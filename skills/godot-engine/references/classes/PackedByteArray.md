# PackedByteArray


A packed array of bytes.

An array specifically designed to hold bytes (integers between `0` and `255`). Packs data tightly, so it saves memory for large array sizes. PackedByteArray also provides methods to encode/decode various types to/from bytes. The way values are encoded is an implementation detail and shouldn't be relied upon when interacting with external apps.

## Constructors

- `PackedByteArray() -> PackedByteArray` — Constructs an empty PackedByteArray.
- `PackedByteArray(from: PackedByteArray) -> PackedByteArray` — Constructs a PackedByteArray as a copy of the given PackedByteArray.
- `PackedByteArray(from: Array) -> PackedByteArray` — Constructs a new PackedByteArray from a generic Array.

## Methods

- `append(value: int) -> bool` — Appends an element at the end of the array (alias of `push_back`).
- `append_array(array: PackedByteArray) -> void` — Appends a PackedByteArray at the end of this array.
- `bsearch(value: int, before: bool = true) -> int` *const* — Finds the index of an existing value (or the insertion index that maintains sorting order, if the value is not yet present in the array) using binary search.
- `bswap16(offset: int = 0, count: int = -1) -> void` — Swaps the byte order of `count` 16-bit segments of the array starting at `offset`.
- `bswap32(offset: int = 0, count: int = -1) -> void` — Swaps the byte order of `count` 32-bit segments of the array starting at `offset`.
- `bswap64(offset: int = 0, count: int = -1) -> void` — Swaps the byte order of `count` 64-bit segments of the array starting at `offset`.
- `clear() -> void` — Clears the array.
- `compress(compression_mode: int = 0) -> PackedByteArray` *const* — Returns a new PackedByteArray with the data compressed.
- `count(value: int) -> int` *const* — Returns the number of times an element is in the array.
- `decode_double(byte_offset: int) -> float` *const* — Decodes a 64-bit floating-point number from the bytes starting at `byte_offset`.
- `decode_float(byte_offset: int) -> float` *const* — Decodes a 32-bit floating-point number from the bytes starting at `byte_offset`.
- `decode_half(byte_offset: int) -> float` *const* — Decodes a 16-bit floating-point number from the bytes starting at `byte_offset`.
- `decode_s8(byte_offset: int) -> int` *const* — Decodes a 8-bit signed integer number from the bytes starting at `byte_offset`.
- `decode_s16(byte_offset: int) -> int` *const* — Decodes a 16-bit signed integer number from the bytes starting at `byte_offset`.
- `decode_s32(byte_offset: int) -> int` *const* — Decodes a 32-bit signed integer number from the bytes starting at `byte_offset`.
- `decode_s64(byte_offset: int) -> int` *const* — Decodes a 64-bit signed integer number from the bytes starting at `byte_offset`.
- `decode_u8(byte_offset: int) -> int` *const* — Decodes a 8-bit unsigned integer number from the bytes starting at `byte_offset`.
- `decode_u16(byte_offset: int) -> int` *const* — Decodes a 16-bit unsigned integer number from the bytes starting at `byte_offset`.
- `decode_u32(byte_offset: int) -> int` *const* — Decodes a 32-bit unsigned integer number from the bytes starting at `byte_offset`.
- `decode_u64(byte_offset: int) -> int` *const* — Decodes a 64-bit unsigned integer number from the bytes starting at `byte_offset`.
- `decode_var(byte_offset: int, allow_objects: bool = false) -> Variant` *const* — Decodes a Variant from the bytes starting at `byte_offset`.
- `decode_var_size(byte_offset: int, allow_objects: bool = false) -> int` *const* — Decodes a size of a Variant from the bytes starting at `byte_offset`.
- `decompress(buffer_size: int, compression_mode: int = 0) -> PackedByteArray` *const* — Returns a new PackedByteArray with the data decompressed.
- `decompress_dynamic(max_output_size: int, compression_mode: int = 0) -> PackedByteArray` *const* — Returns a new PackedByteArray with the data decompressed.
- `duplicate() -> PackedByteArray` *const* — Creates a copy of the array, and returns it.
- `encode_double(byte_offset: int, value: float) -> void` — Encodes a 64-bit floating-point number as bytes at the index of `byte_offset` bytes.
- `encode_float(byte_offset: int, value: float) -> void` — Encodes a 32-bit floating-point number as bytes at the index of `byte_offset` bytes.
- `encode_half(byte_offset: int, value: float) -> void` — Encodes a 16-bit floating-point number as bytes at the index of `byte_offset` bytes.
- `encode_s8(byte_offset: int, value: int) -> void` — Encodes a 8-bit signed integer number (signed byte) at the index of `byte_offset` bytes.
- `encode_s16(byte_offset: int, value: int) -> void` — Encodes a 16-bit signed integer number as bytes at the index of `byte_offset` bytes.
- `encode_s32(byte_offset: int, value: int) -> void` — Encodes a 32-bit signed integer number as bytes at the index of `byte_offset` bytes.
- `encode_s64(byte_offset: int, value: int) -> void` — Encodes a 64-bit signed integer number as bytes at the index of `byte_offset` bytes.
- `encode_u8(byte_offset: int, value: int) -> void` — Encodes a 8-bit unsigned integer number (byte) at the index of `byte_offset` bytes.
- `encode_u16(byte_offset: int, value: int) -> void` — Encodes a 16-bit unsigned integer number as bytes at the index of `byte_offset` bytes.
- `encode_u32(byte_offset: int, value: int) -> void` — Encodes a 32-bit unsigned integer number as bytes at the index of `byte_offset` bytes.
- `encode_u64(byte_offset: int, value: int) -> void` — Encodes a 64-bit unsigned integer number as bytes at the index of `byte_offset` bytes.
- `encode_var(byte_offset: int, value: Variant, allow_objects: bool = false) -> int` — Encodes a Variant at the index of `byte_offset` bytes.
- `erase(value: int) -> bool` — Removes the first occurrence of a value from the array and returns `true`.
- `fill(value: int) -> void` — Assigns the given value to all elements in the array.
- `find(value: int, from: int = 0) -> int` *const* — Searches the array for a value and returns its index or `-1` if not found.
- `get(index: int) -> int` *const* — Returns the byte at the given `index` in the array.
- `get_string_from_ascii() -> String` *const* — Converts ASCII/Latin-1 encoded array to String.
- `get_string_from_multibyte_char(encoding: String = "") -> String` *const* — Converts system multibyte code page encoded array to String.
- `get_string_from_utf8() -> String` *const* — Converts UTF-8 encoded array to String.
- `get_string_from_utf16() -> String` *const* — Converts UTF-16 encoded array to String.
- `get_string_from_utf32() -> String` *const* — Converts UTF-32 encoded array to String.
- `get_string_from_wchar() -> String` *const* — Converts wide character (`wchar_t`, UTF-16 on Windows, UTF-32 on other platforms) encoded array to String.
- `has(value: int) -> bool` *const* — Returns `true` if the array contains `value`.
- `has_encoded_var(byte_offset: int, allow_objects: bool = false) -> bool` *const* — Returns `true` if a valid Variant value can be decoded at the `byte_offset`.
- `hex_encode() -> String` *const* — Returns a hexadecimal representation of this array as a String.
- `insert(at_index: int, value: int) -> int` — Inserts a new element at a given position in the array.
- `is_empty() -> bool` *const* — Returns `true` if the array is empty.
- `push_back(value: int) -> bool` — Appends an element at the end of the array.
- `remove_at(index: int) -> void` — Removes an element from the array by index.
- `resize(new_size: int) -> int` — Sets the size of the array.
- `reverse() -> void` — Reverses the order of the elements in the array.
- `rfind(value: int, from: int = -1) -> int` *const* — Searches the array in reverse order.
- `set(index: int, value: int) -> void` — Changes the byte at the given index.
- `size() -> int` *const* — Returns the number of elements in the array.
- `slice(begin: int, end: int = 2147483647) -> PackedByteArray` *const* — Returns the slice of the PackedByteArray, from `begin` (inclusive) to `end` (exclusive), as a new PackedByteArray.
- `sort() -> void` — Sorts the elements of the array in ascending order.
- `to_color_array() -> PackedColorArray` *const* — Returns a copy of the data converted to a PackedColorArray, where each block of 16 bytes has been converted to a Color variant.
- `to_float32_array() -> PackedFloat32Array` *const* — Returns a copy of the data converted to a PackedFloat32Array, where each block of 4 bytes has been converted to a 32-bit float (C++ `float`).
- `to_float64_array() -> PackedFloat64Array` *const* — Returns a copy of the data converted to a PackedFloat64Array, where each block of 8 bytes has been converted to a 64-bit float (C++ `double`, Godot float).
- `to_int32_array() -> PackedInt32Array` *const* — Returns a copy of the data converted to a PackedInt32Array, where each block of 4 bytes has been converted to a signed 32-bit integer (C++ `int32_t`).
- `to_int64_array() -> PackedInt64Array` *const* — Returns a copy of the data converted to a PackedInt64Array, where each block of 8 bytes has been converted to a signed 64-bit integer (C++ `int64_t`, Godot int).
- `to_vector2_array() -> PackedVector2Array` *const* — Returns a copy of the data converted to a PackedVector2Array, where each block of 8 bytes or 16 bytes (32-bit or 64-bit) has been converted to a Vector2 variant.
- `to_vector3_array() -> PackedVector3Array` *const* — Returns a copy of the data converted to a PackedVector3Array, where each block of 12 or 24 bytes (32-bit or 64-bit) has been converted to a Vector3 variant.
- `to_vector4_array() -> PackedVector4Array` *const* — Returns a copy of the data converted to a PackedVector4Array, where each block of 16 or 32 bytes (32-bit or 64-bit) has been converted to a Vector4 variant.

## Operators

- `operator !=(right: PackedByteArray) -> bool` — Returns `true` if contents of the arrays differ.
- `operator +(right: PackedByteArray) -> PackedByteArray` — Returns a new PackedByteArray with contents of `right` added at the end of this array.
- `operator ==(right: PackedByteArray) -> bool` — Returns `true` if contents of both arrays are the same, i.e. they have all equal bytes at the corresponding indices.
- `operator [](index: int) -> int` — Returns the byte at index `index`.
