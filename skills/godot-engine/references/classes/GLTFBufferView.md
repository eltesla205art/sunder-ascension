# GLTFBufferView

**Inherits:** Resource

Represents a glTF buffer view.

GLTFBufferView is a data structure representing a glTF `bufferView` that would be found in the `"bufferViews"` array. A buffer is a blob of binary data. A buffer view is a slice of a buffer that can be used to identify and extract data from the buffer. Most custom uses of buffers only need to use the `buffer`, `byte_length`, and `byte_offset`.

## Properties

- `buffer: int` = `-1` — The index of the buffer this buffer view is referencing.
- `byte_length: int` = `0` — The length, in bytes, of this buffer view.
- `byte_offset: int` = `0` — The offset, in bytes, from the start of the buffer to the start of this buffer view.
- `byte_stride: int` = `-1` — The stride, in bytes, between interleaved data.
- `indices: bool` = `false` — `true` if the GLTFBufferView's OpenGL GPU buffer type is an `ELEMENT_ARRAY_BUFFER` used for vertex indices (integer constant `34963`).
- `vertex_attributes: bool` = `false` — `true` if the GLTFBufferView's OpenGL GPU buffer type is an `ARRAY_BUFFER` used for vertex attributes (integer constant `34962`).

## Methods

- `from_dictionary(dictionary: Dictionary) -> GLTFBufferView` *static* — Creates a new GLTFBufferView instance by parsing the given Dictionary.
- `load_buffer_view_data(state: GLTFState) -> PackedByteArray` *const* — Loads the buffer view data from the buffer referenced by this buffer view in the given GLTFState.
- `to_dictionary() -> Dictionary` *const* — Serializes this GLTFBufferView instance into a Dictionary.
