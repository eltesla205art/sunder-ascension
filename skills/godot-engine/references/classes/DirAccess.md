# DirAccess

**Inherits:** RefCounted

Provides methods for managing directories and their content.

This class is used to manage directories and their content, even outside of the project folder. DirAccess can't be instantiated directly. Instead it is created with a static method that takes a path for which it will be opened. Most of the methods have a static alternative that can be used without creating a DirAccess.

## Properties

- `include_hidden: bool` — If `true`, hidden files are included when navigating the directory.
- `include_navigational: bool` — If `true`, `.` and `..` are included when navigating the directory.

## Methods

- `change_dir(to_dir: String) -> int[Error]` — Changes the currently opened directory to the one passed as an argument.
- `copy(from: String, to: String, chmod_flags: int = -1) -> int[Error]` — Copies the `from` file to the `to` destination.
- `copy_absolute(from: String, to: String, chmod_flags: int = -1) -> int[Error]` *static* — Static version of `copy`.
- `create_link(source: String, target: String) -> int[Error]` — Creates symbolic link between files or folders.
- `create_temp(prefix: String = "", keep: bool = false) -> DirAccess` *static* — Creates a temporary directory.
- `current_is_dir() -> bool` *const* — Returns whether the current item processed with the last `get_next` call is a directory (`.` and `..` are considered directories).
- `dir_exists(path: String) -> bool` — Returns whether the target directory exists.
- `dir_exists_absolute(path: String) -> bool` *static* — Static version of `dir_exists`.
- `file_exists(path: String) -> bool` — Returns whether the target file exists.
- `get_current_dir(include_drive: bool = true) -> String` *const* — Returns the absolute path to the currently opened directory (e.g.
- `get_current_drive() -> int` — Returns the currently opened directory's drive index.
- `get_directories() -> PackedStringArray` — Returns a PackedStringArray containing filenames of the directory contents, excluding files.
- `get_directories_at(path: String) -> PackedStringArray` *static* — Returns a PackedStringArray containing filenames of the directory contents, excluding files, at the given `path`.
- `get_drive_count() -> int` *static* — On Windows, returns the number of drives (partitions) mounted on the current filesystem.
- `get_drive_label(idx: int) -> String` *static* — On Windows, returns the label of the drive (partition) passed as an argument.
- `get_drive_name(idx: int) -> String` *static* — On Windows, returns the name of the drive (partition) passed as an argument (e.g.
- `get_files() -> PackedStringArray` — Returns a PackedStringArray containing filenames of the directory contents, excluding directories.
- `get_files_at(path: String) -> PackedStringArray` *static* — Returns a PackedStringArray containing filenames of the directory contents, excluding directories, at the given `path`.
- `get_filesystem_type() -> String` *const* — Returns file system type name of the current directory's disk.
- `get_next() -> String` — Returns the next element (file or directory) in the current directory.
- `get_open_error() -> int[Error]` *static* — Returns the result of the last `open` call in the current thread.
- `get_space_left() -> int` — Returns the available space on the current directory's disk, in bytes.
- `is_bundle(path: String) -> bool` *const* — Returns `true` if the directory is a macOS bundle.
- `is_case_sensitive(path: String) -> bool` *const* — Returns `true` if the file system or directory use case sensitive file names.
- `is_equivalent(path_a: String, path_b: String) -> bool` *const* — Returns `true` if paths `path_a` and `path_b` resolve to the same file system object.
- `is_link(path: String) -> bool` — Returns `true` if the file or directory is a symbolic link, directory junction, or other reparse point.
- `list_dir_begin() -> int[Error]` — Initializes the stream used to list all files and directories using the `get_next` function, closing the currently opened stream if needed.
- `list_dir_end() -> void` — Closes the current stream opened with `list_dir_begin` (whether it has been fully processed with `get_next` does not matter).
- `make_dir(path: String) -> int[Error]` — Creates a directory.
- `make_dir_absolute(path: String) -> int[Error]` *static* — Static version of `make_dir`.
- `make_dir_recursive(path: String) -> int[Error]` — Creates a target directory and all necessary intermediate directories in its path, by calling `make_dir` recursively.
- `make_dir_recursive_absolute(path: String) -> int[Error]` *static* — Static version of `make_dir_recursive`.
- `open(path: String) -> DirAccess` *static* — Creates a new DirAccess object and opens an existing directory of the filesystem.
- `read_link(path: String) -> String` — Returns target of the symbolic link.
- `remove(path: String) -> int[Error]` — Permanently deletes the target file or an empty directory.
- `remove_absolute(path: String) -> int[Error]` *static* — Static version of `remove`.
- `rename(from: String, to: String) -> int[Error]` — Renames (move) the `from` file or directory to the `to` destination.
- `rename_absolute(from: String, to: String) -> int[Error]` *static* — Static version of `rename`.
