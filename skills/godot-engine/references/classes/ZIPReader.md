# ZIPReader

**Inherits:** RefCounted

Allows reading the content of a ZIP file.

This class implements a reader that can extract the content of individual files inside a ZIP archive. See also ZIPPacker.

## Methods

- `close() -> int[Error]` — Closes the underlying resources used by this instance.
- `file_exists(path: String, case_sensitive: bool = true) -> bool` — Returns `true` if the file exists in the loaded zip archive.
- `get_compression_level(path: String, case_sensitive: bool = true) -> int` — Returns the compression level of the file in the loaded zip archive.
- `get_files() -> PackedStringArray` — Returns the list of names of all files in the loaded archive.
- `open(path: String) -> int[Error]` — Opens the zip archive at the given `path` and reads its file index.
- `read_file(path: String, case_sensitive: bool = true) -> PackedByteArray` — Loads the whole content of a file in the loaded zip archive into memory and returns it.
