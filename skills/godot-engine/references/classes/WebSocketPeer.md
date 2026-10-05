# WebSocketPeer

**Inherits:** PacketPeer

A WebSocket connection.

This class represents WebSocket connection, and can be used as a WebSocket client (RFC 6455-compliant) or as a remote peer of a WebSocket server. You can send WebSocket binary frames using `PacketPeer.put_packet`, and WebSocket text frames using `send` (prefer text frames when interacting with text-based API). You can check the frame type of the last packet via `was_string_packet`. To start a WebSocket client, first call `connect_to_url`, then regularly call `poll` (e.g. during Node process).

## Properties

- `handshake_headers: PackedStringArray` = `PackedStringArray()` — The extra HTTP headers to be sent during the WebSocket handshake.
- `heartbeat_interval: float` = `0.0` — The interval (in seconds) at which the peer will automatically send WebSocket "ping" control frames.
- `inbound_buffer_size: int` = `65535` — The size of the input buffer in bytes (roughly the maximum amount of memory that will be allocated for the inbound packets).
- `max_queued_packets: int` = `4096` — The maximum amount of packets that will be allowed in the queues (both inbound and outbound).
- `outbound_buffer_size: int` = `65535` — The size of the input buffer in bytes (roughly the maximum amount of memory that will be allocated for the outbound packets).
- `supported_protocols: PackedStringArray` = `PackedStringArray()` — The WebSocket sub-protocols allowed during the WebSocket handshake.

## Methods

- `accept_stream(stream: StreamPeer) -> int[Error]` — Accepts a peer connection performing the HTTP handshake as a WebSocket server.
- `close(code: int = 1000, reason: String = "") -> void` — Closes this WebSocket connection.
- `connect_to_url(url: String, tls_client_options: TLSOptions = null) -> int[Error]` — Connects to the given URL.
- `get_close_code() -> int` *const* — Returns the received WebSocket close frame status code, or `-1` when the connection was not cleanly closed.
- `get_close_reason() -> String` *const* — Returns the received WebSocket close frame status reason string.
- `get_connected_host() -> String` *const* — Returns the IP address of the connected peer.
- `get_connected_port() -> int` *const* — Returns the remote port of the connected peer.
- `get_current_outbound_buffered_amount() -> int` *const* — Returns the current amount of data in the outbound websocket buffer.
- `get_ready_state() -> int[WebSocketPeer.State]` *const* — Returns the ready state of the connection.
- `get_requested_url() -> String` *const* — Returns the URL requested by this peer.
- `get_selected_protocol() -> String` *const* — Returns the selected WebSocket sub-protocol for this connection or an empty string if the sub-protocol has not been selected yet.
- `poll() -> void` — Updates the connection state and receive incoming packets.
- `send(message: PackedByteArray, write_mode: WebSocketPeer.WriteMode = 1) -> int[Error]` — Sends the given `message` using the desired `write_mode`.
- `send_text(message: String) -> int[Error]` — Sends the given `message` using WebSocket text mode.
- `set_no_delay(enabled: bool) -> void` — Disable Nagle's algorithm on the underlying TCP socket (default).
- `was_string_packet() -> bool` *const* — Returns `true` if the last received packet was sent as a text payload.

## Enum WriteMode

- `WRITE_MODE_TEXT = 0` — Specifies that WebSockets messages should be transferred as text payload (only valid UTF-8 is allowed).
- `WRITE_MODE_BINARY = 1` — Specifies that WebSockets messages should be transferred as binary payload (any byte combination is allowed).

## Enum State

- `STATE_CONNECTING = 0` — Socket has been created.
- `STATE_OPEN = 1` — The connection is open and ready to communicate.
- `STATE_CLOSING = 2` — The connection is in the process of closing.
- `STATE_CLOSED = 3` — The connection is closed or couldn't be opened.
