# WebRTCMultiplayerPeer

**Inherits:** MultiplayerPeer

A simple interface to create a peer-to-peer mesh network composed of WebRTCPeerConnection that is compatible with the MultiplayerAPI.

This class constructs a full mesh of WebRTCPeerConnection (one connection for each peer) that can be used as a `MultiplayerAPI.multiplayer_peer`. You can add each WebRTCPeerConnection via `add_peer` or remove them via `remove_peer`. Peers must be added in `WebRTCPeerConnection.STATE_NEW` state to allow it to create the appropriate channels. This class will not create offers nor set descriptions, it will only poll them, and notify connections and disconnections.

## Methods

- `add_peer(peer: WebRTCPeerConnection, peer_id: int, unreliable_lifetime: int = 1) -> int[Error]` — Add a new peer to the mesh with the given `peer_id`.
- `create_client(peer_id: int, channels_config: Array = []) -> int[Error]` — Initialize the multiplayer peer as a client with the given `peer_id` (must be between 2 and 2147483647).
- `create_mesh(peer_id: int, channels_config: Array = []) -> int[Error]` — Initialize the multiplayer peer as a mesh (i.e. all peers connect to each other) with the given `peer_id` (must be between 1 and 2147483647).
- `create_server(channels_config: Array = []) -> int[Error]` — Initialize the multiplayer peer as a server (with unique ID of `1`).
- `get_peer(peer_id: int) -> Dictionary` — Returns a dictionary representation of the peer with given `peer_id` with three keys.
- `get_peers() -> Dictionary` — Returns a dictionary which keys are the peer ids and values the peer representation as in `get_peer`.
- `has_peer(peer_id: int) -> bool` — Returns `true` if the given `peer_id` is in the peers map (it might not be connected though).
- `remove_peer(peer_id: int) -> void` — Remove the peer with given `peer_id` from the mesh.
