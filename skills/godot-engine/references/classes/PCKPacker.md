# PCKPacker

**Inherits:** RefCounted

Creates packages that can be loaded into a running project.

The PCKPacker is used to create packages that can be loaded into a running project using `ProjectSettings.load_resource_pack`. The above PCKPacker creates package `test.pck`, then adds a file named `text.txt` at the root of the package. Note: PCK is Godot's own pack file format. To create ZIP archives that can be read by any program, use ZIPPacker instead.

## Methods

- `add_file(target_path: String, source_path: String, encrypt: bool = false) -> int[Error]` — Adds the `source_path` file to the current PCK package at the `target_path` internal path.
- `add_file_from_buffer(target_path: String, data: PackedByteArray, encrypt: bool = false) -> int[Error]` — Adds the `data` to the current PCK package at the `target_path` internal path.
- `add_file_removal(target_path: String) -> int[Error]` — Registers a file removal of the `target_path` internal path to the PCK.
- `flush(verbose: bool = false) -> int[Error]` — Writes the file directory and closes the PCK.
- `pck_start(pck_path: String, alignment: int = 32, key: String = "0000000000000000000000000000000000000000000000000000000000000000", encrypt_directory: bool = false) -> int[Error]` — Creates a new PCK file at the file path `pck_path`.
