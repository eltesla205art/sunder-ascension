# WebSocketMultiplayerPeer

**Inherits:** MultiplayerPeer

Base class for WebSocket server and client.

Base class for WebSocket server and client, allowing them to be used as multiplayer peer for the MultiplayerAPI. Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy. Otherwise, network communication of any kind will be blocked by Android.

## Properties

- `handshake_headers: PackedStringArray` = `PackedStringArray()` — The extra headers to use during handshake.
- `handshake_timeout: float` = `3.0` — The maximum time each peer can stay in a connecting state before being dropped.
- `inbound_buffer_size: int` = `65535` — The inbound buffer size for connected peers.
- `max_queued_packets: int` = `4096` — The maximum number of queued packets for connected peers.
- `outbound_buffer_size: int` = `65535` — The outbound buffer size for connected peers.
- `supported_protocols: PackedStringArray` = `PackedStringArray()` — The supported WebSocket sub-protocols.

## Methods

- `create_client(url: String, tls_client_options: TLSOptions = null) -> int[Error]` — Starts a new multiplayer client connecting to the given `url`.
- `create_server(port: int, bind_address: String = "*", tls_server_options: TLSOptions = null) -> int[Error]` — Starts a new multiplayer server listening on the given `port`.
- `get_peer(peer_id: int) -> WebSocketPeer` *const* — Returns the WebSocketPeer associated to the given `peer_id`.
- `get_peer_address(id: int) -> String` *const* — Returns the IP address of the given peer.
- `get_peer_port(id: int) -> int` *const* — Returns the remote port of the given peer.
