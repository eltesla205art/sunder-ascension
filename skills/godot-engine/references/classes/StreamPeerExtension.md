# StreamPeerExtension

**Inherits:** StreamPeer





## Methods

- `_get_available_bytes() -> int` *virtual required const*
- `_get_data(r_buffer: uint8_t*, r_bytes: int, r_received: int32_t*) -> int[Error]` *virtual*
- `_get_partial_data(r_buffer: uint8_t*, r_bytes: int, r_received: int32_t*) -> int[Error]` *virtual*
- `_put_data(data: const uint8_t*, bytes: int, r_sent: int32_t*) -> int[Error]` *virtual*
- `_put_partial_data(data: const uint8_t*, bytes: int, r_sent: int32_t*) -> int[Error]` *virtual*
