# TLSOptions

**Inherits:** RefCounted

TLS configuration for clients and servers.

TLSOptions abstracts the configuration options for the StreamPeerTLS and PacketPeerDTLS classes. Objects of this class cannot be instantiated directly, and one of the static methods `client`, `client_unsafe`, or `server` should be used instead.

## Methods

- `client(trusted_chain: X509Certificate = null, common_name_override: String = "") -> TLSOptions` *static* — Creates a TLS client configuration which validates certificates and their common names (fully qualified domain names).
- `client_unsafe(trusted_chain: X509Certificate = null) -> TLSOptions` *static* — Creates an unsafe TLS client configuration where certificate validation is optional.
- `get_common_name_override() -> String` *const* — Returns the common name (domain name) override specified when creating with `TLSOptions.client`.
- `get_own_certificate() -> X509Certificate` *const* — Returns the X509Certificate specified when creating with `TLSOptions.server`.
- `get_private_key() -> CryptoKey` *const* — Returns the CryptoKey specified when creating with `TLSOptions.server`.
- `get_trusted_ca_chain() -> X509Certificate` *const* — Returns the CA X509Certificate chain specified when creating with `TLSOptions.client` or `TLSOptions.client_unsafe`.
- `is_server() -> bool` *const* — Returns `true` if created with `TLSOptions.server`, `false` otherwise.
- `is_unsafe_client() -> bool` *const* — Returns `true` if created with `TLSOptions.client_unsafe`, `false` otherwise.
- `server(key: CryptoKey, certificate: X509Certificate) -> TLSOptions` *static* — Creates a TLS server configuration using the provided `key` and `certificate`.
