# StreamPeerTCP

**Inherits:** StreamPeerSocket

A stream peer that handles TCP connections.

A stream peer that handles TCP connections. This object can be used to connect to TCP servers, or also is returned by a TCP server. Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy. Otherwise, network communication of any kind will be blocked by Android.

## Methods

- `bind(port: int, host: String = "*") -> int[Error]` — Opens the TCP socket, and binds it to the specified local address.
- `connect_to_host(host: String, port: int) -> int[Error]` — Connects to the specified `host:port` pair.
- `get_connected_host() -> String` *const* — Returns the IP of this peer.
- `get_connected_port() -> int` *const* — Returns the port of this peer.
- `get_local_port() -> int` *const* — Returns the local port to which this peer is bound.
- `set_no_delay(enabled: bool) -> void` — If `enabled` is `true`, packets will be sent immediately.
