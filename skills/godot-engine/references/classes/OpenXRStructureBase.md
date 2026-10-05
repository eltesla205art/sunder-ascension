# OpenXRStructureBase

**Inherits:** RefCounted

Object for storing OpenXR structure data.

Object for storing OpenXR structure data that is passed when calling into OpenXR APIs.

## Properties

- `next: OpenXRStructureBase` — Setting another structure object here chains these structures together to extend the API functionality.

## Methods

- `_get_header(next: int) -> int` *virtual*
- `get_header(next: int) -> int` — Returns the structure pointer (any OpenXR structure that has an `XrStructureType`) used for this structure.
- `get_structure_type() -> int` — Returns the structure type (OpenXR `XrStructureType`) used for this structure.
