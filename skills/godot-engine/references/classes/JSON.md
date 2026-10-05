# JSON

**Inherits:** Resource

Helper class for creating and parsing JSON data.

The JSON class enables all data types to be converted to and from a JSON string. This is useful for serializing data, e.g. to save to a file or send over the network. `stringify` is used to convert any data type into a JSON string. `parse` is used to convert any existing JSON data into a Variant that can be used within Godot.

## Properties

- `data: Variant` = `null` — Contains the parsed JSON data in Variant form.

## Methods

- `from_native(variant: Variant, full_objects: bool = false) -> Variant` *static* — Converts a native engine type to a JSON-compliant value.
- `get_error_line() -> int` *const* — Returns `0` if the last call to `parse` was successful, or the line number where the parse failed.
- `get_error_message() -> String` *const* — Returns an empty string if the last call to `parse` was successful, or the error message if it failed.
- `get_parsed_text() -> String` *const* — Return the text parsed by `parse` (requires passing `keep_text` to `parse`).
- `parse(json_text: String, keep_text: bool = false) -> int[Error]` — Attempts to parse the `json_text` provided.
- `parse_string(json_string: String) -> Variant` *static* — Attempts to parse the `json_string` provided and returns the parsed data.
- `stringify(data: Variant, indent: String = "", sort_keys: bool = true, full_precision: bool = false) -> String` *static* — Converts a Variant var to JSON text and returns the result.
- `to_native(json: Variant, allow_objects: bool = false) -> Variant` *static* — Converts a JSON-compliant value that was created with `from_native` back to native engine types.
