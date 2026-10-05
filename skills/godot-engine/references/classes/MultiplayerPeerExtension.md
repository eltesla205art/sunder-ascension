# MultiplayerPeerExtension

**Inherits:** MultiplayerPeer

Class that can be inherited to implement custom multiplayer API networking layers via GDExtension.

This class is designed to be inherited from a GDExtension plugin to implement custom networking layers for the multiplayer API (such as WebRTC). All the methods below must be implemented to have a working custom multiplayer implementation. See also MultiplayerAPI.

## Methods

- `_close() -> void` *virtual required* — Called when the multiplayer peer should be immediately closed (see `MultiplayerPeer.close`).
- `_disconnect_peer(peer: int, force: bool) -> void` *virtual required* — Called when the connected `peer` should be forcibly disconnected (see `MultiplayerPeer.disconnect_peer`).
- `_get_available_packet_count() -> int` *virtual required const* — Called when the available packet count is internally requested by the MultiplayerAPI.
- `_get_connection_status() -> int[MultiplayerPeer.ConnectionStatus]` *virtual required const* — Called when the connection status is requested on the MultiplayerPeer (see `MultiplayerPeer.get_connection_status`).
- `_get_max_packet_size() -> int` *virtual required const* — Called when the maximum allowed packet size (in bytes) is requested by the MultiplayerAPI.
- `_get_packet(r_buffer: const uint8_t **, r_buffer_size: int32_t*) -> int[Error]` *virtual* — Called when a packet needs to be received by the MultiplayerAPI, with `r_buffer_size` being the size of the binary `r_buffer` in bytes.
- `_get_packet_channel() -> int` *virtual required const* — Called to get the channel over which the next available packet was received.
- `_get_packet_mode() -> int[MultiplayerPeer.TransferMode]` *virtual required const* — Called to get the transfer mode the remote peer used to send the next available packet.
- `_get_packet_peer() -> int` *virtual required const* — Called when the ID of the MultiplayerPeer who sent the most recent packet is requested (see `MultiplayerPeer.get_packet_peer`).
- `_get_packet_script() -> PackedByteArray` *virtual* — Called when a packet needs to be received by the MultiplayerAPI, if `_get_packet` isn't implemented.
- `_get_transfer_channel() -> int` *virtual required const* — Called when the transfer channel to use is read on this MultiplayerPeer (see `MultiplayerPeer.transfer_channel`).
- `_get_transfer_mode() -> int[MultiplayerPeer.TransferMode]` *virtual required const* — Called when the transfer mode to use is read on this MultiplayerPeer (see `MultiplayerPeer.transfer_mode`).
- `_get_unique_id() -> int` *virtual required const* — Called when the unique ID of this MultiplayerPeer is requested (see `MultiplayerPeer.get_unique_id`).
- `_is_refusing_new_connections() -> bool` *virtual const* — Called when the "refuse new connections" status is requested on this MultiplayerPeer (see `MultiplayerPeer.refuse_new_connections`).
- `_is_server() -> bool` *virtual required const* — Called when the "is server" status is requested on the MultiplayerAPI.
- `_is_server_relay_supported() -> bool` *virtual const* — Called to check if the server can act as a relay in the current configuration.
- `_poll() -> void` *virtual required* — Called when the MultiplayerAPI is polled.
- `_put_packet(buffer: const uint8_t*, buffer_size: int) -> int[Error]` *virtual* — Called when a packet needs to be sent by the MultiplayerAPI, with `buffer_size` being the size of the binary `buffer` in bytes.
- `_put_packet_script(buffer: PackedByteArray) -> int[Error]` *virtual* — Called when a packet needs to be sent by the MultiplayerAPI, if `_put_packet` isn't implemented.
- `_set_refuse_new_connections(enable: bool) -> void` *virtual* — Called when the "refuse new connections" status is set on this MultiplayerPeer (see `MultiplayerPeer.refuse_new_connections`).
- `_set_target_peer(peer: int) -> void` *virtual required* — Called when the target peer to use is set for this MultiplayerPeer (see `MultiplayerPeer.set_target_peer`).
- `_set_transfer_channel(channel: int) -> void` *virtual required* — Called when the channel to use is set for this MultiplayerPeer (see `MultiplayerPeer.transfer_channel`).
- `_set_transfer_mode(mode: MultiplayerPeer.TransferMode) -> void` *virtual required* — Called when the transfer mode is set on this MultiplayerPeer (see `MultiplayerPeer.transfer_mode`).
