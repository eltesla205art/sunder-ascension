# SocketServer

**Inherits:** RefCounted

An abstract class for servers based on sockets.

A socket server.

## Methods

- `is_connection_available() -> bool` *const* — Returns `true` if a connection is available for taking.
- `is_listening() -> bool` *const* — Returns `true` if the server is currently listening for connections.
- `stop() -> void` — Stops listening.
- `take_socket_connection() -> StreamPeerSocket` — If a connection is available, returns a StreamPeerSocket with the connection.
