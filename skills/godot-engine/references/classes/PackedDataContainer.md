# PackedDataContainer

**Inherits:** Resource
**Deprecated:** Use `@GlobalScope.var_to_bytes` or `FileAccess.store_var` instead. To enable data compression, use `PackedByteArray.compress` or `FileAccess.open_compressed`.

Efficiently packs and serializes Array or Dictionary.

PackedDataContainer can be used to efficiently store data from untyped containers. The data is packed into raw bytes and can be saved to file. Only Array and Dictionary can be stored this way. You can retrieve the data by iterating on the container, which will work as if iterating on the packed data itself.

## Methods

- `pack(value: Variant) -> int[Error]` — Packs the given container into a binary representation.
- `size() -> int` *const* — Returns the size of the packed container (see `Array.size` and `Dictionary.size`).
