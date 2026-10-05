# HashingContext

**Inherits:** RefCounted

Provides functionality for computing cryptographic hashes chunk by chunk.

The HashingContext class provides an interface for computing cryptographic hashes over multiple iterations. Useful for computing hashes of big files (so you don't have to load them all in memory), network streams, and data streams in general (so you don't have to hold buffers). The `HashType` enum shows the supported hashing algorithms.

## Methods

- `finish() -> PackedByteArray` — Closes the current context, and return the computed hash.
- `start(type: HashingContext.HashType) -> int[Error]` — Starts a new hash computation of the given `type` (e.g.
- `update(chunk: PackedByteArray) -> int[Error]` — Updates the computation with the given `chunk` of data.

## Enum HashType

- `HASH_MD5 = 0` — Hashing algorithm: MD5.
- `HASH_SHA1 = 1` — Hashing algorithm: SHA-1.
- `HASH_SHA256 = 2` — Hashing algorithm: SHA-256.
