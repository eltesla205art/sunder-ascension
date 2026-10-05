# UDPServer

**Inherits:** RefCounted

Helper class to implement a UDP server.

A simple server that opens a UDP socket and returns connected PacketPeerUDP upon receiving new packets. See also `PacketPeerUDP.connect_to_host`. After starting the server (`listen`), you will need to `poll` it at regular intervals (e.g. inside `Node._process`) for it to process new packets, delivering them to the appropriate PacketPeerUDP, and taking new connections. Below a small example of how it can be used:

## Properties

- `max_pending_connections: int` = `16` — Define the maximum number of pending connections, during `poll`, any new pending connection exceeding that value will be automatically dropped.

## Methods

- `get_local_port() -> int` *const* — Returns the local port this server is listening to.
- `is_connection_available() -> bool` *const* — Returns `true` if a packet with a new address/port combination was received on the socket.
- `is_listening() -> bool` *const* — Returns `true` if the socket is open and listening on a port.
- `listen(port: int, bind_address: String = "*") -> int[Error]` — Starts the server by opening a UDP socket listening on the given `port`.
- `poll() -> int[Error]` — Call this method at regular intervals (e.g. inside `Node._process`) to process new packets.
- `stop() -> void` — Stops the server, closing the UDP socket if open.
- `take_connection() -> PacketPeerUDP` — Returns the first pending connection (connected to the appropriate address/port).
