# StreamPeerTLS

**Inherits:** StreamPeer

A stream peer that handles TLS connections.

A stream peer that handles TLS connections. This object can be used to connect to a TLS server or accept a single TLS client connection. Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy. Otherwise, network communication of any kind will be blocked by Android.

## Methods

- `accept_stream(stream: StreamPeer, server_options: TLSOptions) -> int[Error]` — Accepts a peer connection as a server using the given `server_options`.
- `connect_to_stream(stream: StreamPeer, common_name: String, client_options: TLSOptions = null) -> int[Error]` — Connects to a peer using an underlying StreamPeer `stream` and verifying the remote certificate is correctly signed for the given `common_name`.
- `disconnect_from_stream() -> void` — Disconnects from host.
- `get_status() -> int[StreamPeerTLS.Status]` *const* — Returns the status of the connection.
- `get_stream() -> StreamPeer` *const* — Returns the underlying StreamPeer connection, used in `accept_stream` or `connect_to_stream`.
- `poll() -> void` — Poll the connection to check for incoming bytes.

## Enum Status

- `STATUS_DISCONNECTED = 0` — A status representing a StreamPeerTLS that is disconnected.
- `STATUS_HANDSHAKING = 1` — A status representing a StreamPeerTLS during handshaking.
- `STATUS_CONNECTED = 2` — A status representing a StreamPeerTLS that is connected to a host.
- `STATUS_ERROR = 3` — A status representing a StreamPeerTLS in error state.
- `STATUS_ERROR_HOSTNAME_MISMATCH = 4` — An error status that shows a mismatch in the TLS certificate domain presented by the host and the domain requested for validation.
