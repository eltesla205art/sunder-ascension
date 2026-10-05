# PacketPeerUDP

**Inherits:** PacketPeer

UDP packet peer.

UDP packet peer. Can be used to send and receive raw UDP packets as well as Variants. Example: Send a packet:  Example: Listen for packets:  Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy. Otherwise, network communication of any kind will be blocked by Android.

## Methods

- `bind(port: int, bind_address: String = "*", recv_buf_size: int = 65536) -> int[Error]` — Binds this PacketPeerUDP to the specified `port` and `bind_address` with a buffer size `recv_buf_size`, allowing it to receive incoming packets.
- `close() -> void` — Closes the PacketPeerUDP's underlying UDP socket.
- `connect_to_host(host: String, port: int) -> int[Error]` — Calling this method connects this UDP peer to the given `host`/`port` pair.
- `get_local_port() -> int` *const* — Returns the local port to which this peer is bound.
- `get_packet_ip() -> String` *const* — Returns the IP of the remote peer that sent the last packet(that was received with `PacketPeer.get_packet` or `PacketPeer.get_var`).
- `get_packet_port() -> int` *const* — Returns the port of the remote peer that sent the last packet(that was received with `PacketPeer.get_packet` or `PacketPeer.get_var`).
- `is_bound() -> bool` *const* — Returns whether this PacketPeerUDP is bound to an address and can receive packets.
- `is_socket_connected() -> bool` *const* — Returns `true` if the UDP socket is open and has been connected to a remote address.
- `join_multicast_group(multicast_address: String, interface_name: String) -> int[Error]` — Joins the multicast group specified by `multicast_address` using the interface identified by `interface_name`.
- `leave_multicast_group(multicast_address: String, interface_name: String) -> int[Error]` — Removes the interface identified by `interface_name` from the multicast group specified by `multicast_address`.
- `set_broadcast_enabled(enabled: bool) -> void` — Enable or disable sending of broadcast packets (e.g.
- `set_dest_address(host: String, port: int) -> int[Error]` — Sets the destination address and port for sending packets and variables.
- `wait() -> int[Error]` — Waits for a packet to arrive on the bound address.
