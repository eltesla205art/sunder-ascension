# StreamPeerSocket

**Inherits:** StreamPeer

Abstract base class for interacting with socket streams.

StreamPeerSocket is an abstract base class that defines common behavior for socket-based streams.

## Methods

- `disconnect_from_host() -> void` — Disconnects from host.
- `get_status() -> int[StreamPeerSocket.Status]` *const* — Returns the status of the connection.
- `poll() -> int[Error]` — Polls the socket, updating its state.

## Enum Status

- `STATUS_NONE = 0` — The initial status of the StreamPeerSocket.
- `STATUS_CONNECTING = 1` — A status representing a StreamPeerSocket that is connecting to a host.
- `STATUS_CONNECTED = 2` — A status representing a StreamPeerSocket that is connected to a host.
- `STATUS_ERROR = 3` — A status representing a StreamPeerSocket in error state.
