# ENetMultiplayerPeer

**Inherits:** MultiplayerPeer

A MultiplayerPeer implementation using the ENet library.

A MultiplayerPeer implementation that should be passed to `MultiplayerAPI.multiplayer_peer` after being initialized as either a client, server, or mesh. Events can then be handled by connecting to MultiplayerAPI signals. See ENetConnection for more information on the ENet library wrapper. Note: ENet only uses UDP, not TCP.

## Properties

- `host: ENetConnection` — The underlying ENetConnection created after `create_client` and `create_server`.

## Methods

- `add_mesh_peer(peer_id: int, host: ENetConnection) -> int[Error]` — Add a new remote peer with the given `peer_id` connected to the given `host`.
- `create_client(address: String, port: int, channel_count: int = 0, in_bandwidth: int = 0, out_bandwidth: int = 0, local_port: int = 0) -> int[Error]` — Create client that connects to a server at `address` using specified `port`.
- `create_mesh(unique_id: int) -> int[Error]` — Initialize this MultiplayerPeer in mesh mode.
- `create_server(port: int, max_clients: int = 32, max_channels: int = 0, in_bandwidth: int = 0, out_bandwidth: int = 0) -> int[Error]` — Create server that listens to connections via `port`.
- `get_peer(id: int) -> ENetPacketPeer` *const* — Returns the ENetPacketPeer associated to the given `id`.
- `set_bind_ip(ip: String) -> void` — The IP used when creating a server.
