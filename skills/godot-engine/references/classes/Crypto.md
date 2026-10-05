# Crypto

**Inherits:** RefCounted

Provides access to advanced cryptographic functionalities.

The Crypto class provides access to advanced cryptographic functionalities. Currently, this includes asymmetric key encryption/decryption, signing/verification, and generating cryptographically secure random bytes, RSA keys, HMAC digests, and self-signed X509Certificates.

## Methods

- `constant_time_compare(trusted: PackedByteArray, received: PackedByteArray) -> bool` — Compares two PackedByteArrays for equality without leaking timing information in order to prevent timing attacks.
- `decrypt(key: CryptoKey, ciphertext: PackedByteArray) -> PackedByteArray` — Decrypt the given `ciphertext` with the provided private `key`.
- `encrypt(key: CryptoKey, plaintext: PackedByteArray) -> PackedByteArray` — Encrypt the given `plaintext` with the provided public `key`.
- `generate_random_bytes(size: int) -> PackedByteArray` — Generates a PackedByteArray of cryptographically secure random bytes with given `size`.
- `generate_rsa(size: int) -> CryptoKey` — Generates an RSA CryptoKey that can be used for creating self-signed certificates and passed to `StreamPeerTLS.accept_stream`.
- `generate_self_signed_certificate(key: CryptoKey, issuer_name: String = "CN=myserver,O=myorganisation,C=IT", not_before: String = "20140101000000", not_after: String = "20340101000000") -> X509Certificate` — Generates a self-signed X509Certificate from the given CryptoKey and `issuer_name`.
- `hmac_digest(hash_type: HashingContext.HashType, key: PackedByteArray, msg: PackedByteArray) -> PackedByteArray` — Generates an HMAC digest of `msg` using `key`.
- `sign(hash_type: HashingContext.HashType, hash: PackedByteArray, key: CryptoKey) -> PackedByteArray` — Sign a given `hash` of type `hash_type` with the provided private `key`.
- `verify(hash_type: HashingContext.HashType, hash: PackedByteArray, signature: PackedByteArray, key: CryptoKey) -> bool` — Verify that a given `signature` for `hash` of type `hash_type` against the provided public `key`.
