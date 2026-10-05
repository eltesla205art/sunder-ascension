# PacketPeer

**Inherits:** RefCounted

Abstraction and base class for packet-based protocols.

PacketPeer is an abstraction and base class for packet-based protocols (such as UDP). It provides an API for sending and receiving packets both as raw data or variables. This makes it easy to transfer data over a protocol, without having to encode data as low-level bytes or having to worry about network ordering. Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy.

## Properties

- `encode_buffer_max_size: int` = `8388608` — Maximum buffer size allowed when encoding Variants.

## Methods

- `get_available_packet_count() -> int` *const* — Returns the number of packets currently available in the ring-buffer.
- `get_packet() -> PackedByteArray` — Gets a raw packet.
- `get_packet_error() -> int[Error]` *const* — Returns the error state of the last packet received (via `get_packet` and `get_var`).
- `get_var(allow_objects: bool = false) -> Variant` — Gets a Variant.
- `put_packet(buffer: PackedByteArray) -> int[Error]` — Sends a raw packet.
- `put_var(var: Variant, full_objects: bool = false) -> int[Error]` — Sends a Variant as a packet.
