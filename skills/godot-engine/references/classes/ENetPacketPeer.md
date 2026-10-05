# ENetPacketPeer

**Inherits:** PacketPeer

A wrapper class for an ENetPeer.

A PacketPeer implementation representing a peer of an ENetConnection. This class cannot be instantiated directly but can be retrieved during `ENetConnection.service` or via `ENetConnection.get_peers`. Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy. Otherwise, network communication of any kind will be blocked by Android.

## Methods

- `get_channels() -> int` *const* — Returns the number of channels allocated for communication with peer.
- `get_packet_flags() -> int` *const* — Returns the ENet flags of the next packet in the received queue.
- `get_remote_address() -> String` *const* — Returns the IP address of this peer.
- `get_remote_port() -> int` *const* — Returns the remote port of this peer.
- `get_state() -> int[ENetPacketPeer.PeerState]` *const* — Returns the current peer state.
- `get_statistic(statistic: ENetPacketPeer.PeerStatistic) -> float` — Returns the requested `statistic` for this peer.
- `is_active() -> bool` *const* — Returns `true` if the peer is currently active (i.e. the associated ENetConnection is still valid).
- `peer_disconnect(data: int = 0) -> void` — Request a disconnection from a peer.
- `peer_disconnect_later(data: int = 0) -> void` — Request a disconnection from a peer, but only after all queued outgoing packets are sent.
- `peer_disconnect_now(data: int = 0) -> void` — Force an immediate disconnection from a peer.
- `ping() -> void` — Sends a ping request to a peer.
- `ping_interval(ping_interval: int) -> void` — Sets the `ping_interval` in milliseconds at which pings will be sent to a peer.
- `reset() -> void` — Forcefully disconnects a peer.
- `send(channel: int, packet: PackedByteArray, flags: int) -> int[Error]` — Queues a `packet` to be sent over the specified `channel`.
- `set_timeout(timeout: int, timeout_min: int, timeout_max: int) -> void` — Sets the timeout parameters for a peer.
- `throttle_configure(interval: int, acceleration: int, deceleration: int) -> void` — Configures throttle parameter for a peer.

## Enum PeerState

- `STATE_DISCONNECTED = 0` — The peer is disconnected.
- `STATE_CONNECTING = 1` — The peer is currently attempting to connect.
- `STATE_ACKNOWLEDGING_CONNECT = 2` — The peer has acknowledged the connection request.
- `STATE_CONNECTION_PENDING = 3` — The peer is currently connecting.
- `STATE_CONNECTION_SUCCEEDED = 4` — The peer has successfully connected, but is not ready to communicate with yet (`STATE_CONNECTED`).
- `STATE_CONNECTED = 5` — The peer is currently connected and ready to communicate with.
- `STATE_DISCONNECT_LATER = 6` — The peer is expected to disconnect after it has no more outgoing packets to send.
- `STATE_DISCONNECTING = 7` — The peer is currently disconnecting.
- `STATE_ACKNOWLEDGING_DISCONNECT = 8` — The peer has acknowledged the disconnection request.
- `STATE_ZOMBIE = 9` — The peer has lost connection, but is not considered truly disconnected (as the peer didn't acknowledge the disconnection request).

## Enum PeerStatistic

- `PEER_PACKET_LOSS = 0` — Mean packet loss of reliable packets as a ratio with respect to the `PACKET_LOSS_SCALE`.
- `PEER_PACKET_LOSS_VARIANCE = 1` — Packet loss variance.
- `PEER_PACKET_LOSS_EPOCH = 2` — The time at which packet loss statistics were last updated (in milliseconds since the connection started).
- `PEER_ROUND_TRIP_TIME = 3` — Mean packet round trip time for reliable packets.
- `PEER_ROUND_TRIP_TIME_VARIANCE = 4` — Variance of the mean round trip time.
- `PEER_LAST_ROUND_TRIP_TIME = 5` — Last recorded round trip time for a reliable packet.
- `PEER_LAST_ROUND_TRIP_TIME_VARIANCE = 6` — Variance of the last trip time recorded.
- `PEER_PACKET_THROTTLE = 7` — The peer's current throttle status.
- `PEER_PACKET_THROTTLE_LIMIT = 8` — The maximum number of unreliable packets that should not be dropped.
- `PEER_PACKET_THROTTLE_COUNTER = 9` — Internal value used to increment the packet throttle counter.
- `PEER_PACKET_THROTTLE_EPOCH = 10` — The time at which throttle statistics were last updated (in milliseconds since the connection started).
- `PEER_PACKET_THROTTLE_ACCELERATION = 11` — The throttle's acceleration factor.
- `PEER_PACKET_THROTTLE_DECELERATION = 12` — The throttle's deceleration factor.
- `PEER_PACKET_THROTTLE_INTERVAL = 13` — The interval over which the lowest mean round trip time should be measured for use by the throttle mechanism (in milliseconds).

## Constants

- `PACKET_LOSS_SCALE = 65536` — The reference scale for packet loss.
- `PACKET_THROTTLE_SCALE = 32` — The reference value for throttle configuration.
- `FLAG_RELIABLE = 1` — Mark the packet to be sent as reliable.
- `FLAG_UNSEQUENCED = 2` — Mark the packet to be sent unsequenced (unreliable).
- `FLAG_UNRELIABLE_FRAGMENT = 8` — Mark the packet to be sent unreliable even if the packet is too big and needs fragmentation (increasing the chance of it being dropped).
