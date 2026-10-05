# GraphElement

**Inherits:** Container

A container that represents a basic element that can be placed inside a GraphEdit control.

GraphElement allows to create custom elements for a GraphEdit graph. By default such elements can be selected, resized, and repositioned, but they cannot be connected. For a graph element that allows for connections see GraphNode.

## Properties

- `draggable: bool` = `true` — If `true`, the user can drag the GraphElement.
- `position_offset: Vector2` = `Vector2(0, 0)` — The offset of the GraphElement, relative to the scroll offset of the GraphEdit.
- `resizable: bool` = `false` — If `true`, the user can resize the GraphElement.
- `scaling_menus: bool` = `false` — If `true`, PopupMenus that are descendants of the GraphElement are scaled with the GraphEdit zoom.
- `selectable: bool` = `true` — If `true`, the user can select the GraphElement.
- `selected: bool` = `false` — If `true`, the GraphElement is selected.

## Signals

- `delete_request()` — Emitted when removing the GraphElement is requested.
- `dragged(from: Vector2, to: Vector2)` — Emitted when the GraphElement is dragged.
- `node_deselected()` — Emitted when the GraphElement is deselected.
- `node_selected()` — Emitted when the GraphElement is selected.
- `position_offset_changed()` — Emitted when the GraphElement is moved.
- `raise_request()` — Emitted when displaying the GraphElement over other ones is requested.
- `resize_end(new_size: Vector2)` — Emitted when releasing the mouse button after dragging the resizer handle (see `resizable`).
- `resize_request(new_size: Vector2)` — Emitted when resizing the GraphElement is requested.

## Theme items

- `resizer: Texture2D` (icon)
