# Marshalls

**Inherits:** Object

Data transformation (marshaling) and encoding helpers.

Provides data transformation and encoding utility functions.

## Methods

- `base64_to_raw(base64_str: String) -> PackedByteArray` — Returns a decoded PackedByteArray corresponding to the Base64-encoded string `base64_str`.
- `base64_to_utf8(base64_str: String) -> String` — Returns a decoded string corresponding to the Base64-encoded string `base64_str`.
- `base64_to_variant(base64_str: String, allow_objects: bool = false) -> Variant` — Returns a decoded Variant corresponding to the Base64-encoded string `base64_str`.
- `raw_to_base64(array: PackedByteArray) -> String` — Returns a Base64-encoded string of a given PackedByteArray.
- `utf8_to_base64(utf8_str: String) -> String` — Returns a Base64-encoded string of the UTF-8 string `utf8_str`.
- `variant_to_base64(variant: Variant, full_objects: bool = false) -> String` — Returns a Base64-encoded string of the Variant `variant`.
