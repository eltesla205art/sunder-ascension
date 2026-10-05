# WebRTCDataChannelExtension

**Inherits:** WebRTCDataChannel





## Methods

- `_close() -> void` *virtual required*
- `_get_available_packet_count() -> int` *virtual required const*
- `_get_buffered_amount() -> int` *virtual required const*
- `_get_id() -> int` *virtual required const*
- `_get_label() -> String` *virtual required const*
- `_get_max_packet_life_time() -> int` *virtual required const*
- `_get_max_packet_size() -> int` *virtual required const*
- `_get_max_retransmits() -> int` *virtual required const*
- `_get_packet(r_buffer: const uint8_t **, r_buffer_size: int32_t*) -> int[Error]` *virtual*
- `_get_protocol() -> String` *virtual required const*
- `_get_ready_state() -> int[WebRTCDataChannel.ChannelState]` *virtual required const*
- `_get_write_mode() -> int[WebRTCDataChannel.WriteMode]` *virtual required const*
- `_is_negotiated() -> bool` *virtual required const*
- `_is_ordered() -> bool` *virtual required const*
- `_poll() -> int[Error]` *virtual required*
- `_put_packet(buffer: const uint8_t*, buffer_size: int) -> int[Error]` *virtual*
- `_set_write_mode(write_mode: WebRTCDataChannel.WriteMode) -> void` *virtual required*
- `_was_string_packet() -> bool` *virtual required const*
