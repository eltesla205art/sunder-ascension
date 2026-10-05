# ZIPPacker

**Inherits:** RefCounted

Allows the creation of ZIP files.

This class implements a writer that allows storing the multiple blobs in a ZIP archive. See also ZIPReader and PCKPacker.

## Properties

- `compression_level: int` = `-1` — The compression level used when `start_file` is called.

## Methods

- `add_directory(path: String, permissions: FileAccess.UnixPermissionFlags = 493, modified_time: int = 0) -> int[Error]` — Adds directory to the archive.
- `close() -> int[Error]` — Closes the underlying resources used by this instance.
- `close_file() -> int[Error]` — Stops writing to a file within the archive.
- `open(path: String, append: ZIPPacker.ZipAppend = 0) -> int[Error]` — Opens a zip file for writing at the given path using the specified write mode.
- `start_file(path: String, permissions: FileAccess.UnixPermissionFlags = 420, modified_time: int = 0) -> int[Error]` — Starts writing to a file within the archive.
- `write_file(data: PackedByteArray) -> int[Error]` — Write the given `data` to the file.

## Enum ZipAppend

- `APPEND_CREATE = 0` — Create a new zip archive at the given path.
- `APPEND_CREATEAFTER = 1` — Append a new zip archive to the end of the already existing file at the given path.
- `APPEND_ADDINZIP = 2` — Add new files to the existing zip archive at the given path.

## Enum CompressionLevel

- `COMPRESSION_DEFAULT = -1` — Start a file with the default Deflate compression level (`6`).
- `COMPRESSION_NONE = 0` — Start a file with no compression.
- `COMPRESSION_FAST = 1` — Start a file with the fastest Deflate compression level (`1`).
- `COMPRESSION_BEST = 9` — Start a file with the best Deflate compression level (`9`).
