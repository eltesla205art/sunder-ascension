# NodePath


A pre-parsed scene tree path.

The NodePath built-in Variant type represents a path to a node or property in a hierarchy of nodes. It is designed to be efficiently passed into many built-in methods (such as `Node.get_node`, `Object.set_indexed`, `Tween.tween_property`, etc.) without a hard dependence on the node or property they point to. A node path is represented as a String composed of slash-separated (`/`) node names and colon-separated (`:`) property names (also called "subnames"). Similar to a filesystem path, `".."` and `"."` are special node names.

## Constructors

- `NodePath() -> NodePath` — Constructs an empty NodePath.
- `NodePath(from: NodePath) -> NodePath` — Constructs a NodePath as a copy of the given NodePath.
- `NodePath(from: String) -> NodePath` — Constructs a NodePath from a String.

## Methods

- `get_as_property_path() -> NodePath` *const* — Returns a copy of this node path with a colon character (`:`) prefixed, transforming it to a pure property path with no node names (relative to the current node).
- `get_concatenated_names() -> StringName` *const* — Returns all node names concatenated with a slash character (`/`) as a single StringName.
- `get_concatenated_subnames() -> StringName` *const* — Returns all property subnames concatenated with a colon character (`:`) as a single StringName.
- `get_name(idx: int) -> StringName` *const* — Returns the node name indicated by `idx`, starting from 0.
- `get_name_count() -> int` *const* — Returns the number of node names in the path.
- `get_subname(idx: int) -> StringName` *const* — Returns the property name indicated by `idx`, starting from 0.
- `get_subname_count() -> int` *const* — Returns the number of property names ("subnames") in the path.
- `hash() -> int` *const* — Returns the 32-bit hash value representing the node path's contents.
- `is_absolute() -> bool` *const* — Returns `true` if the node path is absolute.
- `is_empty() -> bool` *const* — Returns `true` if the node path has been constructed from an empty String (`""`).
- `slice(begin: int, end: int = 2147483647) -> NodePath` *const* — Returns the slice of the NodePath, from `begin` (inclusive) to `end` (exclusive), as a new NodePath.

## Operators

- `operator !=(right: NodePath) -> bool` — Returns `true` if two node paths are not equal.
- `operator ==(right: NodePath) -> bool` — Returns `true` if two node paths are equal, that is, they are composed of the same node names and subnames in the same order.
