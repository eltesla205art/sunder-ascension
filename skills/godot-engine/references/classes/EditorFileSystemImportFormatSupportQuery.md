# EditorFileSystemImportFormatSupportQuery

**Inherits:** RefCounted

Used to query and configure import format support.

This class is used to query and configure a certain import format. It is used in conjunction with asset format import plugins.

## Methods

- `_get_file_extensions() -> PackedStringArray` *virtual required const* — Return the file extensions supported.
- `_is_active() -> bool` *virtual required const* — Return whether this importer is active.
- `_query() -> bool` *virtual required const* — Query support.
