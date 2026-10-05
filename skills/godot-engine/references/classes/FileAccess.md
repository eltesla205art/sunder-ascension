# FileAccess

**Inherits:** RefCounted

Provides methods for file reading and writing operations.

This class can be used to permanently store data in the user device's file system and to read from it. This is useful for storing game save data or player configuration files. Example: How to write and read from a file. The file named `"save_game.dat"` will be stored in the user data folder, as specified in the Data paths documentation:  A FileAccess instance has its own file cursor, which is the position in bytes in the file where the next read/write operation will occur.

## Properties

- `big_endian: bool` — If `true`, the file is read with big-endian endianness.

## Methods

- `close() -> void` — Closes the currently opened file and prevents subsequent read/write operations.
- `create_temp(mode_flags: FileAccess.ModeFlags, prefix: String = "", extension: String = "", keep: bool = false) -> FileAccess` *static* — Creates a temporary file.
- `eof_reached() -> bool` *const* — Returns `true` if the file cursor has already read past the end of the file.
- `file_exists(path: String) -> bool` *static* — Returns `true` if the file exists in the given path.
- `flush() -> void` — Writes the file's buffer to disk.
- `get_8() -> int` *const* — Returns the next 8 bits from the file as an integer.
- `get_16() -> int` *const* — Returns the next 16 bits from the file as an integer.
- `get_32() -> int` *const* — Returns the next 32 bits from the file as an integer.
- `get_64() -> int` *const* — Returns the next 64 bits from the file as an integer.
- `get_access_time(file: String) -> int` *static* — Returns the last time the `file` was accessed in Unix timestamp format, or `0` on error.
- `get_as_text() -> String` *const* — Returns the whole file as a String.
- `get_buffer(length: int) -> PackedByteArray` *const* — Returns next `length` bytes of the file as a PackedByteArray.
- `get_csv_line(delim: String = ",") -> PackedStringArray` *const* — Returns the next value of the file in CSV (Comma-Separated Values) format.
- `get_double() -> float` *const* — Returns the next 64 bits from the file as a floating-point number.
- `get_error() -> int[Error]` *const* — Returns the last error that happened when trying to perform operations.
- `get_extended_attribute(file: String, attribute_name: String) -> PackedByteArray` *static* — Reads the file extended attribute with name `attribute_name` as a byte array.
- `get_extended_attribute_string(file: String, attribute_name: String) -> String` *static* — Reads the file extended attribute with name `attribute_name` as a UTF-8 encoded string.
- `get_extended_attributes_list(file: String) -> PackedStringArray` *static* — Returns a list of file extended attributes.
- `get_file_as_bytes(path: String) -> PackedByteArray` *static* — Returns the whole `path` file contents as a PackedByteArray without any decoding.
- `get_file_as_string(path: String) -> String` *static* — Returns the whole `path` file contents as a String.
- `get_float() -> float` *const* — Returns the next 32 bits from the file as a floating-point number.
- `get_half() -> float` *const* — Returns the next 16 bits from the file as a half-precision floating-point number.
- `get_hidden_attribute(file: String) -> bool` *static* — Returns `true` if the hidden attribute is set on the file at the given path.
- `get_length() -> int` *const* — Returns the size of the file in bytes.
- `get_line() -> String` *const* — Returns the next line of the file as a String.
- `get_md5(path: String) -> String` *static* — Returns an MD5 String representing the file at the given path or an empty String on failure.
- `get_modified_time(file: String) -> int` *static* — Returns the last time the `file` was modified in Unix timestamp format, or `0` on error.
- `get_open_error() -> int[Error]` *static* — Returns the result of the last `open` call in the current thread.
- `get_pascal_string() -> String` — Returns a String saved in Pascal format from the file, meaning that the length of the string is explicitly stored at the start.
- `get_path() -> String` *const* — Returns the path as a String for the current open file.
- `get_path_absolute() -> String` *const* — Returns the absolute path as a String for the current open file.
- `get_position() -> int` *const* — Returns the file cursor's position in bytes from the beginning of the file.
- `get_read_only_attribute(file: String) -> bool` *static* — Returns `true` if the read only attribute is set on the file at the given path.
- `get_real() -> float` *const* — Returns the next bits from the file as a floating-point number.
- `get_sha256(path: String) -> String` *static* — Returns an SHA-256 String representing the file at the given path or an empty String on failure.
- `get_size(file: String) -> int` *static* — Returns the size of the file at the given path, in bytes, or `-1` on error.
- `get_unix_permissions(file: String) -> int[FileAccess.UnixPermissionFlags]` *static* — Returns the UNIX permissions of the file at the given path.
- `get_var(allow_objects: bool = false) -> Variant` *const* — Returns the next Variant value from the file.
- `is_open() -> bool` *const* — Returns `true` if the file is currently opened.
- `open(path: String, flags: FileAccess.ModeFlags) -> FileAccess` *static* — Creates a new FileAccess object and opens the file for writing or reading, depending on the flags.
- `open_compressed(path: String, mode_flags: FileAccess.ModeFlags, compression_mode: FileAccess.CompressionMode = 0) -> FileAccess` *static* — Creates a new FileAccess object and opens a compressed file for reading or writing.
- `open_encrypted(path: String, mode_flags: FileAccess.ModeFlags, key: PackedByteArray, iv: PackedByteArray = PackedByteArray()) -> FileAccess` *static* — Creates a new FileAccess object and opens an encrypted file in write or read mode.
- `open_encrypted_with_pass(path: String, mode_flags: FileAccess.ModeFlags, pass: String) -> FileAccess` *static* — Creates a new FileAccess object and opens an encrypted file in write or read mode.
- `remove_extended_attribute(file: String, attribute_name: String) -> int[Error]` *static* — Removes file extended attribute with name `attribute_name`.
- `resize(length: int) -> int[Error]` — Resizes the file to a specified length.
- `seek(position: int) -> void` — Sets the file cursor to the specified position in bytes, from the beginning of the file.
- `seek_end(position: int = 0) -> void` — Sets the file cursor to the specified position in bytes, from the end of the file.
- `set_extended_attribute(file: String, attribute_name: String, data: PackedByteArray) -> int[Error]` *static* — Writes file extended attribute with name `attribute_name` as a byte array.
- `set_extended_attribute_string(file: String, attribute_name: String, data: String) -> int[Error]` *static* — Writes file extended attribute with name `attribute_name` as a UTF-8 encoded string.
- `set_hidden_attribute(file: String, hidden: bool) -> int[Error]` *static* — Sets file hidden attribute.
- `set_read_only_attribute(file: String, ro: bool) -> int[Error]` *static* — Sets file read only attribute.
- `set_unix_permissions(file: String, permissions: FileAccess.UnixPermissionFlags) -> int[Error]` *static* — Sets file UNIX permissions.
- `store_8(value: int) -> bool` — Stores an integer as 8 bits in the file.
- `store_16(value: int) -> bool` — Stores an integer as 16 bits in the file.
- `store_32(value: int) -> bool` — Stores an integer as 32 bits in the file.
- `store_64(value: int) -> bool` — Stores an integer as 64 bits in the file.
- `store_buffer(buffer: PackedByteArray) -> bool` — Stores the given array of bytes in the file.
- `store_csv_line(values: PackedStringArray, delim: String = ",") -> bool` — Stores the given PackedStringArray in the file as a line formatted in the CSV (Comma-Separated Values) format.
- `store_double(value: float) -> bool` — Stores a floating-point number as 64 bits in the file.
- `store_float(value: float) -> bool` — Stores a floating-point number as 32 bits in the file.
- `store_half(value: float) -> bool` — Stores a half-precision floating-point number as 16 bits in the file.
- `store_line(line: String) -> bool` — Stores `line` in the file followed by a newline character (`\n`), encoding the text as UTF-8.
- `store_pascal_string(string: String) -> bool` — Stores the given String as a line in the file in Pascal format (i.e. also store the length of the string).
- `store_real(value: float) -> bool` — Stores a floating-point number in the file.
- `store_string(string: String) -> bool` — Stores `string` in the file without a newline character (`\n`), encoding the text as UTF-8.
- `store_var(value: Variant, full_objects: bool = false) -> bool` — Stores any Variant value in the file.

## Enum ModeFlags

- `READ = 1` — Opens the file for read operations.
- `WRITE = 2` — Opens the file for write operations.
- `READ_WRITE = 3` — Opens the file for read and write operations.
- `WRITE_READ = 7` — Opens the file for read and write operations.

## Enum CompressionMode

- `COMPRESSION_FASTLZ = 0` — Uses the FastLZ compression method.
- `COMPRESSION_DEFLATE = 1` — Uses the DEFLATE compression method.
- `COMPRESSION_ZSTD = 2` — Uses the Zstandard compression method.
- `COMPRESSION_GZIP = 3` — Uses the gzip compression method.
- `COMPRESSION_BROTLI = 4` — Uses the brotli compression method (only decompression is supported).

## Enum UnixPermissionFlags

- `UNIX_READ_OWNER = 256` — Read for owner bit.
- `UNIX_WRITE_OWNER = 128` — Write for owner bit.
- `UNIX_EXECUTE_OWNER = 64` — Execute for owner bit.
- `UNIX_READ_GROUP = 32` — Read for group bit.
- `UNIX_WRITE_GROUP = 16` — Write for group bit.
- `UNIX_EXECUTE_GROUP = 8` — Execute for group bit.
- `UNIX_READ_OTHER = 4` — Read for other bit.
- `UNIX_WRITE_OTHER = 2` — Write for other bit.
- `UNIX_EXECUTE_OTHER = 1` — Execute for other bit.
- `UNIX_SET_USER_ID = 2048` — Set user id on execution bit.
- `UNIX_SET_GROUP_ID = 1024` — Set group id on execution bit.
- `UNIX_RESTRICTED_DELETE = 512` — Restricted deletion (sticky) bit.
