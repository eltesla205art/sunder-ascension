# StreamPeer

**Inherits:** RefCounted

Abstract base class for interacting with streams.

StreamPeer is an abstract base class mostly used for stream-based protocols (such as TCP). It provides an API for sending and receiving data through streams as raw data or strings. Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy. Otherwise, network communication of any kind will be blocked by Android.

## Properties

- `big_endian: bool` = `false` — If `true`, this StreamPeer will using big-endian format for encoding and decoding.

## Methods

- `get_8() -> int` — Gets a signed byte from the stream.
- `get_16() -> int` — Gets a signed 16-bit value from the stream.
- `get_32() -> int` — Gets a signed 32-bit value from the stream.
- `get_64() -> int` — Gets a signed 64-bit value from the stream.
- `get_available_bytes() -> int` *const* — Returns the number of bytes this StreamPeer has available.
- `get_data(bytes: int) -> Array` — Returns a chunk data with the received bytes, as an Array containing two elements: an `Error` constant and a PackedByteArray.
- `get_double() -> float` — Gets a double-precision float from the stream.
- `get_float() -> float` — Gets a single-precision float from the stream.
- `get_half() -> float` — Gets a half-precision float from the stream.
- `get_partial_data(bytes: int) -> Array` — Returns a chunk data with the received bytes, as an Array containing two elements: an `Error` constant and a PackedByteArray.
- `get_string(bytes: int = -1) -> String` — Gets an ASCII string with byte-length `bytes` from the stream.
- `get_u8() -> int` — Gets an unsigned byte from the stream.
- `get_u16() -> int` — Gets an unsigned 16-bit value from the stream.
- `get_u32() -> int` — Gets an unsigned 32-bit value from the stream.
- `get_u64() -> int` — Gets an unsigned 64-bit value from the stream.
- `get_utf8_string(bytes: int = -1) -> String` — Gets a UTF-8 string with byte-length `bytes` from the stream (this decodes the string sent as UTF-8).
- `get_var(allow_objects: bool = false) -> Variant` — Gets a Variant from the stream.
- `put_8(value: int) -> void` — Puts a signed byte into the stream.
- `put_16(value: int) -> void` — Puts a signed 16-bit value into the stream.
- `put_32(value: int) -> void` — Puts a signed 32-bit value into the stream.
- `put_64(value: int) -> void` — Puts a signed 64-bit value into the stream.
- `put_data(data: PackedByteArray) -> int[Error]` — Sends a chunk of data through the connection, blocking if necessary until the data is done sending.
- `put_double(value: float) -> void` — Puts a double-precision float into the stream.
- `put_float(value: float) -> void` — Puts a single-precision float into the stream.
- `put_half(value: float) -> void` — Puts a half-precision float into the stream.
- `put_partial_data(data: PackedByteArray) -> Array` — Sends a chunk of data through the connection.
- `put_string(value: String) -> void` — Puts a zero-terminated ASCII string into the stream prepended by a 32-bit unsigned integer representing its size.
- `put_u8(value: int) -> void` — Puts an unsigned byte into the stream.
- `put_u16(value: int) -> void` — Puts an unsigned 16-bit value into the stream.
- `put_u32(value: int) -> void` — Puts an unsigned 32-bit value into the stream.
- `put_u64(value: int) -> void` — Puts an unsigned 64-bit value into the stream.
- `put_utf8_string(value: String) -> void` — Puts a zero-terminated UTF-8 string into the stream prepended by a 32 bits unsigned integer representing its size.
- `put_var(value: Variant, full_objects: bool = false) -> void` — Puts a Variant into the stream.
