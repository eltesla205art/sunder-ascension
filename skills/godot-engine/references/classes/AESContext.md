# AESContext

**Inherits:** RefCounted

Provides access to AES encryption/decryption of raw data.

This class holds the context information required for encryption and decryption operations with AES (Advanced Encryption Standard). Both AES-ECB and AES-CBC modes are supported.

## Methods

- `finish() -> void` — Close this AES context so it can be started again.
- `get_iv_state() -> PackedByteArray` *(deprecated)* — Returns an empty PackedByteArray.
- `start(mode: AESContext.Mode, key: PackedByteArray, iv: PackedByteArray = PackedByteArray()) -> int[Error]` — Start the AES context in the given `mode`.
- `update(src: PackedByteArray) -> PackedByteArray` — Run the desired operation for this AES context.

## Enum Mode

- `MODE_ECB_ENCRYPT = 0` — AES electronic codebook encryption mode.
- `MODE_ECB_DECRYPT = 1` — AES electronic codebook decryption mode.
- `MODE_CBC_ENCRYPT = 2` — AES cipher block chaining encryption mode.
- `MODE_CBC_DECRYPT = 3` — AES cipher block chaining decryption mode.
- `MODE_MAX = 4` — Maximum value for the mode enum.
