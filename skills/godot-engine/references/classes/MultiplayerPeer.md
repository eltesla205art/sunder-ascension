# MultiplayerPeer

**Inherits:** PacketPeer

Abstract class for specialized PacketPeers used by the MultiplayerAPI.

Manages the connection with one or more remote peers acting as server or client and assigning unique IDs to each of them. See also MultiplayerAPI. Note: The MultiplayerAPI protocol is an implementation detail and isn't meant to be used by non-Godot servers. It may change without notice.

## Properties

- `refuse_new_connections: bool` = `false` — If `true`, this MultiplayerPeer refuses new connections.
- `transfer_channel: int` = `0` — The channel to use to send packets.
- `transfer_mode: MultiplayerPeer.TransferMode` = `2` — The manner in which to send packets to the target peer.

## Methods

- `close() -> void` — Immediately close the multiplayer peer returning to the state `CONNECTION_DISCONNECTED`.
- `disconnect_peer(peer: int, force: bool = false) -> void` — Disconnects the given `peer` from this host.
- `generate_unique_id() -> int` *const* — Returns a randomly generated integer that can be used as a network unique ID.
- `get_connection_status() -> int[MultiplayerPeer.ConnectionStatus]` *const* — Returns the current state of the connection.
- `get_packet_channel() -> int` *const* — Returns the channel over which the next available packet was received.
- `get_packet_mode() -> int[MultiplayerPeer.TransferMode]` *const* — Returns the transfer mode the remote peer used to send the next available packet.
- `get_packet_peer() -> int` *const* — Returns the ID of the MultiplayerPeer who sent the next available packet.
- `get_unique_id() -> int` *const* — Returns the ID of this MultiplayerPeer.
- `is_server_relay_supported() -> bool` *const* — Returns `true` if the server can act as a relay in the current configuration.
- `poll() -> void` — Waits up to 1 second to receive a new network event.
- `set_target_peer(id: int) -> void` — Sets the peer to which packets will be sent.

## Signals

- `peer_connected(id: int)` — Emitted when a remote peer connects.
- `peer_disconnected(id: int)` — Emitted when a remote peer has disconnected.

## Enum ConnectionStatus

- `CONNECTION_DISCONNECTED = 0` — The MultiplayerPeer is disconnected.
- `CONNECTION_CONNECTING = 1` — The MultiplayerPeer is currently connecting to a server.
- `CONNECTION_CONNECTED = 2` — This MultiplayerPeer is connected.

## Enum TransferMode

- `TRANSFER_MODE_UNRELIABLE = 0` — Packets are not acknowledged, no resend attempts are made for lost packets.
- `TRANSFER_MODE_UNRELIABLE_ORDERED = 1` — Packets are not acknowledged, no resend attempts are made for lost packets.
- `TRANSFER_MODE_RELIABLE = 2` — Packets must be received and resend attempts should be made until the packets are acknowledged.

## Constants

- `TARGET_PEER_BROADCAST = 0` — Packets are sent to all connected peers.
- `TARGET_PEER_SERVER = 1` — Packets are sent to the remote peer acting as server.
