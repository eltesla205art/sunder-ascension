# ENetConnection

**Inherits:** RefCounted

A wrapper class for an ENetHost.

ENet's purpose is to provide a relatively thin, simple and robust network communication layer on top of UDP (User Datagram Protocol).

## Methods

- `bandwidth_limit(in_bandwidth: int = 0, out_bandwidth: int = 0) -> void` — Adjusts the bandwidth limits of a host.
- `broadcast(channel: int, packet: PackedByteArray, flags: int) -> void` — Queues a `packet` to be sent to all peers associated with the host over the specified `channel`.
- `channel_limit(limit: int) -> void` — Limits the maximum allowed channels of future incoming connections.
- `compress(mode: ENetConnection.CompressionMode) -> void` — Sets the compression method used for network packets.
- `connect_to_host(address: String, port: int, channels: int = 0, data: int = 0) -> ENetPacketPeer` — Initiates a connection to a foreign `address` using the specified `port` and allocating the requested `channels`.
- `create_host(max_peers: int = 32, max_channels: int = 0, in_bandwidth: int = 0, out_bandwidth: int = 0) -> int[Error]` — Creates an ENetHost that allows up to `max_peers` connected peers, each allocating up to `max_channels` channels, optionally limiting bandwidth to `in_bandwidth` and `out_bandwidth` (if greater than zero).
- `create_host_bound(bind_address: String, bind_port: int, max_peers: int = 32, max_channels: int = 0, in_bandwidth: int = 0, out_bandwidth: int = 0) -> int[Error]` — Creates an ENetHost bound to the given `bind_address` and `bind_port` that allows up to `max_peers` connected peers, each allocating up to `max_channels` channels, optionally limiting bandwidth to `in_bandwidth` and `out_bandwidth` (if greater than zero).
- `destroy() -> void` — Destroys the host and all resources associated with it.
- `dtls_client_setup(hostname: String, client_options: TLSOptions = null) -> int[Error]` — Configure this ENetHost to use the custom Godot extension allowing DTLS encryption for ENet clients.
- `dtls_server_setup(server_options: TLSOptions) -> int[Error]` — Configure this ENetHost to use the custom Godot extension allowing DTLS encryption for ENet servers.
- `flush() -> void` — Sends any queued packets on the host specified to its designated peers.
- `get_local_port() -> int` *const* — Returns the local port to which this peer is bound.
- `get_max_channels() -> int` *const* — Returns the maximum number of channels allowed for connected peers.
- `get_peers() -> ENetPacketPeer[]` — Returns the list of peers associated with this host.
- `pop_statistic(statistic: ENetConnection.HostStatistic) -> float` — Returns and resets host statistics.
- `refuse_new_connections(refuse: bool) -> void` — Configures the DTLS server to automatically drop new connections.
- `service(timeout: int = 0) -> Array` — Waits for events on this connection and shuttles packets between the host and its peers, with the given `timeout` (in milliseconds).
- `socket_send(destination_address: String, destination_port: int, packet: PackedByteArray) -> void` — Sends a `packet` toward a destination from the address and port currently bound by this ENetConnection instance.

## Enum CompressionMode

- `COMPRESS_NONE = 0` — No compression.
- `COMPRESS_RANGE_CODER = 1` — ENet's built-in range encoding.
- `COMPRESS_FASTLZ = 2` — FastLZ compression.
- `COMPRESS_ZLIB = 3` — Zlib compression.
- `COMPRESS_ZSTD = 4` — Zstandard compression.

## Enum EventType

- `EVENT_ERROR = -1` — An error occurred during `service`.
- `EVENT_NONE = 0` — No event occurred within the specified time limit.
- `EVENT_CONNECT = 1` — A connection request initiated by enet_host_connect has completed.
- `EVENT_DISCONNECT = 2` — A peer has disconnected.
- `EVENT_RECEIVE = 3` — A packet has been received from a peer.

## Enum HostStatistic

- `HOST_TOTAL_SENT_DATA = 0` — Total data sent.
- `HOST_TOTAL_SENT_PACKETS = 1` — Total UDP packets sent.
- `HOST_TOTAL_RECEIVED_DATA = 2` — Total data received.
- `HOST_TOTAL_RECEIVED_PACKETS = 3` — Total UDP packets received.
