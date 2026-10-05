# GridMapEditorPlugin

**Inherits:** EditorPlugin

Editor for GridMap nodes.

GridMapEditorPlugin provides access to the GridMap editor functionality.

## Methods

- `clear_selection() -> void` — Deselects any currently selected cells.
- `get_current_grid_map() -> GridMap` *const* — Returns the GridMap node currently edited by the grid map editor.
- `get_selected_cells() -> Array` *const* — Returns an array of Vector3is with the selected cells' coordinates.
- `get_selected_palette_item() -> int` *const* — Returns the index of the selected MeshLibrary item in the grid map editor's palette or `-1` if no item is selected.
- `get_selection() -> AABB` *const* — Returns the cell coordinate bounds of the current selection.
- `has_selection() -> bool` *const* — Returns `true` if there are selected cells.
- `set_selected_palette_item(item: int) -> void` *const* — Selects the MeshLibrary item with the given index in the grid map editor's palette.
- `set_selection(begin: Vector3i, end: Vector3i) -> void` — Selects the cells inside the given bounds from `begin` to `end`.
