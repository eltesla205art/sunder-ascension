# StreamPeerBuffer

**Inherits:** StreamPeer

A stream peer used to handle binary data streams.

A data buffer stream peer that uses a byte array as the stream. This object can be used to handle binary data from network sessions. To handle binary data stored in files, FileAccess can be used directly. A StreamPeerBuffer object keeps an internal cursor which is the offset in bytes to the start of the buffer.

## Properties

- `data_array: PackedByteArray` = `PackedByteArray()` — The underlying data buffer.

## Methods

- `clear() -> void` — Clears the `data_array` and resets the cursor.
- `duplicate() -> StreamPeerBuffer` *const* — Returns a new StreamPeerBuffer with the same `data_array` content.
- `get_position() -> int` *const* — Returns the current cursor position.
- `get_size() -> int` *const* — Returns the size of `data_array`.
- `resize(size: int) -> void` — Resizes the `data_array`.
- `seek(position: int) -> void` — Moves the cursor to the specified position.
