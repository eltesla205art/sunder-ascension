# ConfigFile

**Inherits:** RefCounted

Helper class to handle INI-style files.

This helper class can be used to store Variant values on the filesystem using INI-style formatting. The stored values are identified by a section and a key: ` section some_key=42 string_example="Hello World3D!" a_vector=Vector3(1, 0, 2)  The stored data can be saved to or parsed from a file, though ConfigFile objects can also be used directly without accessing the filesystem. The following example shows how to create a simple ConfigFile and save it on disc:  This example shows how the above file could be loaded:  Any operation that mutates the ConfigFile such as `set_value`, `clear`, or `erase_section`, only changes what is loaded in memory. If you want to write the change to a file, you have to save the changes with `save`, `save_encrypted`, or `save_encrypted_pass`.

## Methods

- `clear() -> void` — Removes the entire contents of the config.
- `encode_to_text() -> String` *const* — Obtain the text version of this config file (the same text that would be written to a file).
- `erase_section(section: String) -> void` — Deletes the specified section along with all the key-value pairs inside.
- `erase_section_key(section: String, key: String) -> void` — Deletes the specified key in a section.
- `get_section_keys(section: String) -> PackedStringArray` *const* — Returns an array of all defined key identifiers in the specified section.
- `get_sections() -> PackedStringArray` *const* — Returns an array of all defined section identifiers.
- `get_value(section: String, key: String, default: Variant = null) -> Variant` *const* — Returns the current value for the specified section and key.
- `has_section(section: String) -> bool` *const* — Returns `true` if the specified section exists.
- `has_section_key(section: String, key: String) -> bool` *const* — Returns `true` if the specified section-key pair exists.
- `load(path: String) -> int[Error]` — Loads the config file specified as a parameter.
- `load_encrypted(path: String, key: PackedByteArray) -> int[Error]` — Loads the encrypted config file specified as a parameter, using the provided `key` to decrypt it.
- `load_encrypted_pass(path: String, password: String) -> int[Error]` — Loads the encrypted config file specified as a parameter, using the provided `password` to decrypt it.
- `parse(data: String) -> int[Error]` — Parses the passed string as the contents of a config file.
- `save(path: String) -> int[Error]` — Saves the contents of the ConfigFile object to the file specified as a parameter.
- `save_encrypted(path: String, key: PackedByteArray) -> int[Error]` — Saves the contents of the ConfigFile object to the AES-256 encrypted file specified as a parameter, using the provided `key` to encrypt it.
- `save_encrypted_pass(path: String, password: String) -> int[Error]` — Saves the contents of the ConfigFile object to the AES-256 encrypted file specified as a parameter, using the provided `password` to encrypt it.
- `set_value(section: String, key: String, value: Variant) -> void` — Assigns a value to the specified key of the specified section.
