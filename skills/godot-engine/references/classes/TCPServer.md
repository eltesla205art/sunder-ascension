# TCPServer

**Inherits:** SocketServer

A TCP server.

A TCP server. Listens to connections on a port and returns a StreamPeerTCP when it gets an incoming connection. Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy. Otherwise, network communication of any kind will be blocked by Android.

## Methods

- `get_local_port() -> int` *const* — Returns the local port this server is listening to.
- `listen(port: int, bind_address: String = "*") -> int[Error]` — Listen on the `port` binding to `bind_address`.
- `take_connection() -> StreamPeerTCP` — If a connection is available, returns a StreamPeerTCP with the connection.
