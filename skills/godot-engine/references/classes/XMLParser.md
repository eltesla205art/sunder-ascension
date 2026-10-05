# XMLParser

**Inherits:** RefCounted

Provides a low-level interface for creating parsers for XML files.

Provides a low-level interface for creating parsers for XML files. This class can serve as base to make custom XML parsers. To parse XML, you must open a file with the `open` method or a buffer with the `open_buffer` method. Then, the `read` method must be called to parse the next nodes.

## Methods

- `get_attribute_count() -> int` *const* — Returns the number of attributes in the currently parsed element.
- `get_attribute_name(idx: int) -> String` *const* — Returns the name of an attribute of the currently parsed element, specified by the `idx` index.
- `get_attribute_value(idx: int) -> String` *const* — Returns the value of an attribute of the currently parsed element, specified by the `idx` index.
- `get_current_line() -> int` *const* — Returns the current line in the parsed file, counting from 0.
- `get_named_attribute_value(name: String) -> String` *const* — Returns the value of an attribute of the currently parsed element, specified by its `name`.
- `get_named_attribute_value_safe(name: String) -> String` *const* — Returns the value of an attribute of the currently parsed element, specified by its `name`.
- `get_node_data() -> String` *const* — Returns the contents of a text node.
- `get_node_name() -> String` *const* — Returns the name of a node.
- `get_node_offset() -> int` *const* — Returns the byte offset of the currently parsed node since the beginning of the file or buffer.
- `get_node_type() -> int[XMLParser.NodeType]` — Returns the type of the current node.
- `has_attribute(name: String) -> bool` *const* — Returns `true` if the currently parsed element has an attribute with the `name`.
- `is_empty() -> bool` *const* — Returns `true` if the currently parsed element is empty, e.g.
- `open(file: String) -> int[Error]` — Opens an XML `file` for parsing.
- `open_buffer(buffer: PackedByteArray) -> int[Error]` — Opens an XML raw `buffer` for parsing.
- `read() -> int[Error]` — Parses the next node in the file.
- `seek(position: int) -> int[Error]` — Moves the buffer cursor to a certain offset (since the beginning) and reads the next node there.
- `skip_section() -> void` — Skips the current section.

## Enum NodeType

- `NODE_NONE = 0` — There's no node (no file or buffer opened).
- `NODE_ELEMENT = 1` — An element node type, also known as a tag, e.g.
- `NODE_ELEMENT_END = 2` — An end of element node type, e.g.
- `NODE_TEXT = 3` — A text node type, i.e. text that is not inside an element.
- `NODE_COMMENT = 4` — A comment node type, e.g.
- `NODE_CDATA = 5` — A node type for CDATA (Character Data) sections, e.g.
- `NODE_UNKNOWN = 6` — An unknown node type.
