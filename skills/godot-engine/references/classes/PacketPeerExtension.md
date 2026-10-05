# PacketPeerExtension

**Inherits:** PacketPeer





## Methods

- `_get_available_packet_count() -> int` *virtual required const*
- `_get_max_packet_size() -> int` *virtual required const*
- `_get_packet(r_buffer: const uint8_t **, r_buffer_size: int32_t*) -> int[Error]` *virtual*
- `_put_packet(buffer: const uint8_t*, buffer_size: int) -> int[Error]` *virtual*
