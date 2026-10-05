# UDSServer

**Inherits:** SocketServer

A Unix Domain Socket (UDS) server.

A Unix Domain Socket (UDS) server. Listens to connections on a socket path and returns a StreamPeerUDS when it gets an incoming connection. Unix Domain Sockets provide inter-process communication on the same machine using the filesystem namespace. Note: Unix Domain Sockets are only available on Unix-like systems (Linux, macOS, etc.) and are not supported on Windows.

## Methods

- `listen(path: String) -> int[Error]` — Listens on the socket at `path`.
- `take_connection() -> StreamPeerUDS` — If a connection is available, returns a StreamPeerUDS with the connection.
