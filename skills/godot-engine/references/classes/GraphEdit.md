# GraphEdit

**Inherits:** Control

An editor for graph-like structures, using GraphNodes.

GraphEdit provides tools for creation, manipulation, and display of various graphs. Its main purpose in the engine is to power the visual programming systems, such as visual shaders, but it is also available for use in user projects. GraphEdit by itself is only an empty container, representing an infinite grid where GraphNodes can be placed. Each GraphNode represents a node in the graph, a single unit of data in the connected scheme.

## Properties

- `clip_contents: bool` = `true` — 
- `connection_lines_antialiased: bool` = `true` — If `true`, the lines between nodes will use antialiasing.
- `connection_lines_curvature: float` = `0.5` — The curvature of the lines between the nodes. 0 results in straight lines.
- `connection_lines_thickness: float` = `4.0` — The thickness of the lines between the nodes.
- `connections: Dictionary[]` = `[]` — The connections between GraphNodes.
- `focus_mode: Control.FocusMode` = `2` — 
- `grid_pattern: GraphEdit.GridPattern` = `0` — The pattern used for drawing the grid.
- `minimap_enabled: bool` = `true` — If `true`, the minimap is visible.
- `minimap_opacity: float` = `0.65` — The opacity of the minimap rectangle.
- `minimap_size: Vector2` = `Vector2(240, 160)` — The size of the minimap rectangle.
- `panning_scheme: GraphEdit.PanningScheme` = `0` — Defines the control scheme for panning with mouse wheel.
- `right_disconnects: bool` = `false` — If `true`, enables disconnection of existing connections in the GraphEdit by dragging the right end.
- `scroll_offset: Vector2` = `Vector2(0, 0)` — The scroll offset.
- `show_arrange_button: bool` = `true` — If `true`, the button to automatically arrange graph nodes is visible.
- `show_grid: bool` = `true` — If `true`, the grid is visible.
- `show_grid_buttons: bool` = `true` — If `true`, buttons that allow to configure grid and snapping options are visible.
- `show_menu: bool` = `true` — If `true`, the menu toolbar is visible.
- `show_minimap_button: bool` = `true` — If `true`, the button to toggle the minimap is visible.
- `show_zoom_buttons: bool` = `true` — If `true`, buttons that allow to change and reset the zoom level are visible.
- `show_zoom_label: bool` = `false` — If `true`, the label with the current zoom level is visible.
- `snapping_distance: int` = `20` — The snapping distance in pixels, also determines the grid line distance.
- `snapping_enabled: bool` = `true` — If `true`, enables snapping.
- `type_names: Dictionary` = `{}` — Dictionary of human-readable port type names.
- `zoom: float` = `1.0` — The current zoom value.
- `zoom_max: float` = `2.0736003` — The upper zoom limit.
- `zoom_min: float` = `0.23256795` — The lower zoom limit.
- `zoom_step: float` = `1.2` — The step of each zoom level.

## Methods

- `_get_connection_line(from_position: Vector2, to_position: Vector2) -> PackedVector2Array` *virtual const* — Virtual method which can be overridden to customize how connections are drawn.
- `_is_in_input_hotzone(in_node: Object, in_port: int, mouse_position: Vector2) -> bool` *virtual* — Returns whether the `mouse_position` is in the input hot zone.
- `_is_in_output_hotzone(in_node: Object, in_port: int, mouse_position: Vector2) -> bool` *virtual* — Returns whether the `mouse_position` is in the output hot zone.
- `_is_node_hover_valid(from_node: StringName, from_port: int, to_node: StringName, to_port: int) -> bool` *virtual* — This virtual method can be used to insert additional error detection while the user is dragging a connection over a valid port.
- `add_valid_connection_type(from_type: int, to_type: int) -> void` — Allows the connection between two different port types.
- `add_valid_left_disconnect_type(type: int) -> void` — Allows to disconnect nodes when dragging from the left port of the GraphNode's slot if it has the specified type.
- `add_valid_right_disconnect_type(type: int) -> void` — Allows to disconnect nodes when dragging from the right port of the GraphNode's slot if it has the specified type.
- `arrange_nodes() -> void` — Rearranges selected nodes in a layout with minimum crossings between connections and uniform horizontal and vertical gap between nodes.
- `attach_graph_element_to_frame(element: StringName, frame: StringName) -> void` — Attaches the `element` GraphElement to the `frame` GraphFrame.
- `clear_connections() -> void` — Removes all connections between nodes.
- `connect_node(from_node: StringName, from_port: int, to_node: StringName, to_port: int, keep_alive: bool = false) -> int[Error]` — Create a connection between the `from_port` of the `from_node` GraphNode and the `to_port` of the `to_node` GraphNode.
- `detach_graph_element_from_frame(element: StringName) -> void` — Detaches the `element` GraphElement from the GraphFrame it is currently attached to.
- `disconnect_node(from_node: StringName, from_port: int, to_node: StringName, to_port: int) -> void` — Removes the connection between the `from_port` of the `from_node` GraphNode and the `to_port` of the `to_node` GraphNode.
- `force_connection_drag_end() -> void` — Ends the creation of the current connection.
- `get_attached_nodes_of_frame(frame: StringName) -> StringName[]` — Returns an array of node names that are attached to the GraphFrame with the given name.
- `get_closest_connection_at_point(point: Vector2, max_distance: float = 4.0) -> Dictionary` *const* — Returns the closest connection to the given point in screen space.
- `get_connection_count(from_node: StringName, from_port: int) -> int` — Returns the number of connections from `from_port` of `from_node`.
- `get_connection_line(from_node: Vector2, to_node: Vector2) -> PackedVector2Array` *const* — Returns the points which would make up a connection between `from_node` and `to_node`.
- `get_connection_list_from_node(node: StringName) -> Dictionary[]` *const* — Returns an Array containing a list of all connections for `node`.
- `get_connections_intersecting_with_rect(rect: Rect2) -> Dictionary[]` *const* — Returns an Array containing the list of connections that intersect with the given Rect2.
- `get_element_frame(element: StringName) -> GraphFrame` — Returns the GraphFrame that contains the GraphElement with the given name.
- `get_menu_hbox() -> HBoxContainer` — Gets the HBoxContainer that contains the zooming and grid snap controls in the top left of the graph.
- `is_node_connected(from_node: StringName, from_port: int, to_node: StringName, to_port: int) -> bool` — Returns `true` if the `from_port` of the `from_node` GraphNode is connected to the `to_port` of the `to_node` GraphNode.
- `is_valid_connection_type(from_type: int, to_type: int) -> bool` *const* — Returns whether it's possible to make a connection between two different port types.
- `remove_valid_connection_type(from_type: int, to_type: int) -> void` — Disallows the connection between two different port types previously allowed by `add_valid_connection_type`.
- `remove_valid_left_disconnect_type(type: int) -> void` — Disallows to disconnect nodes when dragging from the left port of the GraphNode's slot if it has the specified type.
- `remove_valid_right_disconnect_type(type: int) -> void` — Disallows to disconnect nodes when dragging from the right port of the GraphNode's slot if it has the specified type.
- `set_connection_activity(from_node: StringName, from_port: int, to_node: StringName, to_port: int, amount: float) -> void` — Sets the coloration of the connection between `from_node`'s `from_port` and `to_node`'s `to_port` with the color provided in the `activity` theme property.
- `set_selected(node: Node) -> void` — Sets the specified `node` as the one selected.

## Signals

- `begin_node_move()` — Emitted at the beginning of a GraphElement's movement.
- `connection_drag_ended()` — Emitted at the end of a connection drag.
- `connection_drag_started(from_node: StringName, from_port: int, is_output: bool)` — Emitted at the beginning of a connection drag.
- `connection_from_empty(to_node: StringName, to_port: int, release_position: Vector2)` — Emitted when user drags a connection from an input port into the empty space of the graph.
- `connection_request(from_node: StringName, from_port: int, to_node: StringName, to_port: int)` — Emitted to the GraphEdit when the connection between the `from_port` of the `from_node` GraphNode and the `to_port` of the `to_node` GraphNode is attempted to be created.
- `connection_to_empty(from_node: StringName, from_port: int, release_position: Vector2)` — Emitted when user drags a connection from an output port into the empty space of the graph.
- `copy_nodes_request()` — Emitted when this GraphEdit captures a `ui_copy` action (`Ctrl + C` by default).
- `cut_nodes_request()` — Emitted when this GraphEdit captures a `ui_cut` action (`Ctrl + X` by default).
- `delete_nodes_request(nodes: StringName[])` — Emitted when this GraphEdit captures a `ui_graph_delete` action (`Delete` by default).
- `disconnection_request(from_node: StringName, from_port: int, to_node: StringName, to_port: int)` — Emitted to the GraphEdit when the connection between `from_port` of `from_node` GraphNode and `to_port` of `to_node` GraphNode is attempted to be removed.
- `duplicate_nodes_request()` — Emitted when this GraphEdit captures a `ui_graph_duplicate` action (`Ctrl + D` by default).
- `end_node_move()` — Emitted at the end of a GraphElement's movement.
- `frame_rect_changed(frame: GraphFrame, new_rect: Rect2)` — Emitted when the GraphFrame `frame` is resized to `new_rect`.
- `graph_elements_linked_to_frame_request(elements: Array, frame: StringName)` — Emitted when one or more GraphElements are dropped onto the GraphFrame named `frame`, when they were not previously attached to any other one.
- `node_deselected(node: Node)` — Emitted when the given GraphElement node is deselected.
- `node_selected(node: Node)` — Emitted when the given GraphElement node is selected.
- `paste_nodes_request()` — Emitted when this GraphEdit captures a `ui_paste` action (`Ctrl + V` by default).
- `popup_request(at_position: Vector2)` — Emitted when a popup is requested.
- `scroll_offset_changed(offset: Vector2)` — Emitted when the scroll offset is changed by the user.

## Enum PanningScheme

- `SCROLL_ZOOMS = 0` — `Mouse Wheel` will zoom, `Ctrl + Mouse Wheel` will move the view.
- `SCROLL_PANS = 1` — `Mouse Wheel` will move the view, `Ctrl + Mouse Wheel` will zoom.

## Enum GridPattern

- `GRID_PATTERN_LINES = 0` — Draw the grid using solid lines.
- `GRID_PATTERN_DOTS = 1` — Draw the grid using dots.

## Theme items

- `activity: Color` (color) = `Color(1, 1, 1, 1)`
- `connection_hover_tint_color: Color` (color) = `Color(0, 0, 0, 0.3)`
- `connection_rim_color: Color` (color) = `Color(0.1, 0.1, 0.1, 0.6)`
- `connection_valid_target_tint_color: Color` (color) = `Color(1, 1, 1, 0.4)`
- `grid_major: Color` (color) = `Color(1, 1, 1, 0.2)`
- `grid_minor: Color` (color) = `Color(1, 1, 1, 0.05)`
- `selection_fill: Color` (color) = `Color(1, 1, 1, 0.3)`
- `selection_stroke: Color` (color) = `Color(1, 1, 1, 0.8)`
- `connection_hover_thickness: int` (constant) = `0`
- `port_hotzone_inner_extent: int` (constant) = `22`
- `port_hotzone_outer_extent: int` (constant) = `26`
- `grid_toggle: Texture2D` (icon)
- `layout: Texture2D` (icon)
- `minimap_toggle: Texture2D` (icon)
- `snapping_toggle: Texture2D` (icon)
- `zoom_in: Texture2D` (icon)
- `zoom_out: Texture2D` (icon)
- `zoom_reset: Texture2D` (icon)
- `menu_panel: StyleBox` (style)
- `panel: StyleBox` (style)
- `panel_focus: StyleBox` (style)
