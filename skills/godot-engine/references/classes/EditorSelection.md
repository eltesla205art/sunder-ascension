# EditorSelection

**Inherits:** Object

Manages the SceneTree selection in the editor.

This object manages the SceneTree selection in the editor. Note: This class shouldn't be instantiated directly. Instead, access the singleton using `EditorInterface.get_selection`.

## Methods

- `add_node(node: Node) -> void` — Adds a node to the selection.
- `clear() -> void` — Clear the selection.
- `get_selected_nodes() -> Node[]` — Returns the list of selected nodes.
- `get_top_selected_nodes() -> Node[]` — Returns the list of top selected nodes only, excluding any children.
- `get_transformable_selected_nodes() -> Node[]` *(deprecated)* — Returns the list of top selected nodes only, excluding any children.
- `remove_node(node: Node) -> void` — Removes a node from the selection.

## Signals

- `selection_changed()` — Emitted when the selection changes.
