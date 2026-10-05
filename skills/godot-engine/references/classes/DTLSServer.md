# DTLSServer

**Inherits:** RefCounted

Helper class to implement a DTLS server.

This class is used to store the state of a DTLS server. Upon `setup` it converts connected PacketPeerUDP to PacketPeerDTLS accepting them via `take_connection` as DTLS clients. Under the hood, this class is used to store the DTLS state and cookies of the server. The reason of why the state and cookies are needed is outside of the scope of this documentation.

## Methods

- `setup(server_options: TLSOptions) -> int[Error]` — Setup the DTLS server to use the given `server_options`.
- `take_connection(udp_peer: PacketPeerUDP) -> PacketPeerDTLS` — Try to initiate the DTLS handshake with the given `udp_peer` which must be already connected (see `PacketPeerUDP.connect_to_host`).
