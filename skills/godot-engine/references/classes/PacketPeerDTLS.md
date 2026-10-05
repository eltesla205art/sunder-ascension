# PacketPeerDTLS

**Inherits:** PacketPeer

DTLS packet peer.

This class represents a DTLS peer connection. It can be used to connect to a DTLS server, and is returned by `DTLSServer.take_connection`. Note: When exporting to Android, make sure to enable the `INTERNET` permission in the Android export preset before exporting the project or using remote deploy. Otherwise, network communication of any kind will be blocked by Android.

## Methods

- `connect_to_peer(packet_peer: PacketPeerUDP, hostname: String, client_options: TLSOptions = null) -> int[Error]` — Connects a `packet_peer` beginning the DTLS handshake using the underlying PacketPeerUDP which must be connected (see `PacketPeerUDP.connect_to_host`).
- `disconnect_from_peer() -> void` — Disconnects this peer, terminating the DTLS session.
- `get_status() -> int[PacketPeerDTLS.Status]` *const* — Returns the status of the connection.
- `poll() -> void` — Poll the connection to check for incoming packets.

## Enum Status

- `STATUS_DISCONNECTED = 0` — A status representing a PacketPeerDTLS that is disconnected.
- `STATUS_HANDSHAKING = 1` — A status representing a PacketPeerDTLS that is currently performing the handshake with a remote peer.
- `STATUS_CONNECTED = 2` — A status representing a PacketPeerDTLS that is connected to a remote peer.
- `STATUS_ERROR = 3` — A status representing a PacketPeerDTLS in a generic error state.
- `STATUS_ERROR_HOSTNAME_MISMATCH = 4` — An error status that shows a mismatch in the DTLS certificate domain presented by the host and the domain requested for validation.
