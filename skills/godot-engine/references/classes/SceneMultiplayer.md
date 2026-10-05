# SceneMultiplayer

**Inherits:** MultiplayerAPI

High-level multiplayer API implementation.

This class is the default implementation of MultiplayerAPI, used to provide multiplayer functionalities in Godot Engine. This implementation supports RPCs via `Node.rpc` and `Node.rpc_id` and requires `MultiplayerAPI.rpc` to be passed a Node (it will fail for other object types). This implementation additionally provide SceneTree replication via the MultiplayerSpawner and MultiplayerSynchronizer nodes, and the SceneReplicationConfig resource. Note: The high-level multiplayer API protocol is an implementation detail and isn't meant to be used by non-Godot servers.

## Properties

- `allow_object_decoding: bool` = `false` — If `true`, the MultiplayerAPI will allow encoding and decoding of object during RPCs.
- `auth_callback: Callable` = `Callable()` — The callback to execute when receiving authentication data sent via `send_auth`.
- `auth_timeout: float` = `3.0` — If set to a value greater than `0.0`, the maximum duration in seconds peers can stay in the authenticating state, after which the authentication will automatically fail.
- `max_delta_packet_size: int` = `65535` — Maximum size of each delta packet.
- `max_sync_packet_size: int` = `1350` — Maximum size of each synchronization packet.
- `refuse_new_connections: bool` = `false` — If `true`, the MultiplayerAPI's `MultiplayerAPI.multiplayer_peer` refuses new incoming connections.
- `root_path: NodePath` = `NodePath("")` — The root path to use for RPCs and replication.
- `server_relay: bool` = `true` — Enable or disable the server feature that notifies clients of other peers' connection/disconnection, and relays messages between them.

## Methods

- `clear() -> void` — Clears the current SceneMultiplayer network state (you shouldn't call this unless you know what you are doing).
- `complete_auth(id: int) -> int[Error]` — Mark the authentication step as completed for the remote peer identified by `id`.
- `disconnect_peer(id: int) -> void` — Disconnects the peer identified by `id`, removing it from the list of connected peers, and closing the underlying connection with it.
- `get_authenticating_peers() -> PackedInt32Array` — Returns the IDs of the peers currently trying to authenticate with this MultiplayerAPI.
- `send_auth(id: int, data: PackedByteArray) -> int[Error]` — Sends the specified `data` to the remote peer identified by `id` as part of an authentication message.
- `send_bytes(bytes: PackedByteArray, id: int = 0, mode: MultiplayerPeer.TransferMode = 2, channel: int = 0) -> int[Error]` — Sends the given raw `bytes` to a specific peer identified by `id` (see `MultiplayerPeer.set_target_peer`).

## Signals

- `peer_authenticating(id: int)` — Emitted when this MultiplayerAPI's `MultiplayerAPI.multiplayer_peer` connects to a new peer and a valid `auth_callback` is set.
- `peer_authentication_failed(id: int)` — Emitted when this MultiplayerAPI's `MultiplayerAPI.multiplayer_peer` disconnects from a peer for which authentication had not yet completed.
- `peer_packet(id: int, packet: PackedByteArray)` — Emitted when this MultiplayerAPI's `MultiplayerAPI.multiplayer_peer` receives a `packet` with custom data (see `send_bytes`).
