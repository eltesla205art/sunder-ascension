# CryptoKey

**Inherits:** Resource

A cryptographic key (RSA or elliptic-curve).

The CryptoKey class represents a cryptographic key. Keys can be loaded and saved like any other Resource. They can be used to generate a self-signed X509Certificate via `Crypto.generate_self_signed_certificate` and as private key in `StreamPeerTLS.accept_stream` along with the appropriate certificate.

## Methods

- `is_public_only() -> bool` *const* — Returns `true` if this CryptoKey only has the public part, and not the private one.
- `load(path: String, public_only: bool = false) -> int[Error]` — Loads a key from `path`.
- `load_from_string(string_key: String, public_only: bool = false) -> int[Error]` — Loads a key from the given `string_key`.
- `save(path: String, public_only: bool = false) -> int[Error]` — Saves a key to the given `path`.
- `save_to_string(public_only: bool = false) -> String` — Returns a string containing the key in PEM format.
