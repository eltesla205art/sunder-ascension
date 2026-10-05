# HMACContext

**Inherits:** RefCounted

Used to create an HMAC for a message using a key.

The HMACContext class is useful for advanced HMAC use cases, such as streaming the message as it supports creating the message over time rather than providing it all at once.

## Methods

- `finish() -> PackedByteArray` — Returns the resulting HMAC.
- `start(hash_type: HashingContext.HashType, key: PackedByteArray) -> int[Error]` — Initializes the HMACContext.
- `update(data: PackedByteArray) -> int[Error]` — Updates the message to be HMACed.
