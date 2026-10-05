# WebRTCDataChannel

**Inherits:** PacketPeer





## Properties

- `write_mode: WebRTCDataChannel.WriteMode` = `1` — The transfer mode to use when sending outgoing packet.

## Methods

- `close() -> void` — Closes this data channel, notifying the other peer.
- `get_buffered_amount() -> int` *const* — Returns the number of bytes currently queued to be sent over this channel.
- `get_id() -> int` *const* — Returns the ID assigned to this channel during creation (or auto-assigned during negotiation).
- `get_label() -> String` *const* — Returns the label assigned to this channel during creation.
- `get_max_packet_life_time() -> int` *const* — Returns the `maxPacketLifeTime` value assigned to this channel during creation.
- `get_max_retransmits() -> int` *const* — Returns the `maxRetransmits` value assigned to this channel during creation.
- `get_protocol() -> String` *const* — Returns the sub-protocol assigned to this channel during creation.
- `get_ready_state() -> int[WebRTCDataChannel.ChannelState]` *const* — Returns the current state of this channel.
- `is_negotiated() -> bool` *const* — Returns `true` if this channel was created with out-of-band configuration.
- `is_ordered() -> bool` *const* — Returns `true` if this channel was created with ordering enabled (default).
- `poll() -> int[Error]` — Reserved, but not used for now.
- `was_string_packet() -> bool` *const* — Returns `true` if the last received packet was transferred as text.

## Enum WriteMode

- `WRITE_MODE_TEXT = 0` — Tells the channel to send data over this channel as text.
- `WRITE_MODE_BINARY = 1` — Tells the channel to send data over this channel as binary.

## Enum ChannelState

- `STATE_CONNECTING = 0` — The channel was created, but it's still trying to connect.
- `STATE_OPEN = 1` — The channel is currently open, and data can flow over it.
- `STATE_CLOSING = 2` — The channel is being closed, no new messages will be accepted, but those already in queue will be flushed.
- `STATE_CLOSED = 3` — The channel was closed, or connection failed.
