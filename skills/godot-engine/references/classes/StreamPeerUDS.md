# StreamPeerUDS

**Inherits:** StreamPeerSocket

A stream peer that handles UNIX Domain Socket (UDS) connections.

A stream peer that handles UNIX Domain Socket (UDS) connections. This object can be used to connect to UDS servers, or also is returned by a UDS server. Unix Domain Sockets provide inter-process communication on the same machine using the filesystem namespace. Note: UNIX Domain Sockets are only available on UNIX-like systems (Linux, macOS, etc.) and are not supported on Windows.

## Methods

- `bind(path: String) -> int[Error]` — Opens the UDS socket, and binds it to the specified socket path.
- `connect_to_host(path: String) -> int[Error]` — Connects to the specified UNIX Domain Socket path.
- `get_connected_path() -> String` *const* — Returns the socket path of this peer.
