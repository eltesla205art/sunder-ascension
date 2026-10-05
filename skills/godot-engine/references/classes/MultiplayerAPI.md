# MultiplayerAPI

**Inherits:** RefCounted

High-level multiplayer API interface.

Base class for high-level multiplayer API implementations. See also MultiplayerPeer. By default, SceneTree has a reference to an implementation of this class and uses it to provide multiplayer capabilities (i.e. RPCs) across the whole scene.

## Properties

- `multiplayer_peer: MultiplayerPeer` — The peer object to handle the RPC system (effectively enabling networking when set).

## Methods

- `create_default_interface() -> MultiplayerAPI` *static* — Returns a new instance of the default MultiplayerAPI.
- `get_default_interface() -> StringName` *static* — Returns the default MultiplayerAPI implementation class name.
- `get_peers() -> PackedInt32Array` — Returns the peer IDs of all connected peers of this MultiplayerAPI's `multiplayer_peer`.
- `get_remote_sender_id() -> int` — Returns the sender's peer ID for the RPC currently being executed.
- `get_unique_id() -> int` — Returns the unique peer ID of this MultiplayerAPI's `multiplayer_peer`.
- `has_multiplayer_peer() -> bool` — Returns `true` if there is a `multiplayer_peer` set.
- `is_server() -> bool` — Returns `true` if this MultiplayerAPI's `multiplayer_peer` is valid and in server mode (listening for connections).
- `object_configuration_add(object: Object, configuration: Variant) -> int[Error]` — Notifies the MultiplayerAPI of a new `configuration` for the given `object`.
- `object_configuration_remove(object: Object, configuration: Variant) -> int[Error]` — Notifies the MultiplayerAPI to remove a `configuration` for the given `object`.
- `poll() -> int[Error]` — Method used for polling the MultiplayerAPI.
- `rpc(peer: int, object: Object, method: StringName, arguments: Array = []) -> int[Error]` — Sends an RPC to the target `peer`.
- `set_default_interface(interface_name: StringName) -> void` *static* — Sets the default MultiplayerAPI implementation class.

## Signals

- `connected_to_server()` — Emitted when this MultiplayerAPI's `multiplayer_peer` successfully connected to a server.
- `connection_failed()` — Emitted when this MultiplayerAPI's `multiplayer_peer` fails to establish a connection to a server.
- `peer_connected(id: int)` — Emitted when this MultiplayerAPI's `multiplayer_peer` connects with a new peer.
- `peer_disconnected(id: int)` — Emitted when this MultiplayerAPI's `multiplayer_peer` disconnects from a peer.
- `server_disconnected()` — Emitted when this MultiplayerAPI's `multiplayer_peer` disconnects from server.

## Enum RPCMode

- `RPC_MODE_DISABLED = 0` — Used with `Node.rpc_config` to disable a method or property for all RPC calls, making it unavailable.
- `RPC_MODE_ANY_PEER = 1` — Used with `Node.rpc_config` to set a method to be callable remotely by any peer.
- `RPC_MODE_AUTHORITY = 2` — Used with `Node.rpc_config` to set a method to be callable remotely only by the current multiplayer authority (which is the server by default).
