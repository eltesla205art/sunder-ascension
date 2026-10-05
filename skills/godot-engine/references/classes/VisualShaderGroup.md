# VisualShaderGroup

**Inherits:** Resource

A reusable group of VisualShaderNodes similar to a function in programming.

A VisualShaderGroup encapsulates a graph of VisualShaderNodes into a reusable component. It defines its own input and output ports, which become the interface when the group is used as a VisualShaderNodeGroup node inside a VisualShader or another VisualShaderGroup. Since an actual shader function is created for each VisualShaderGroup, you can only use global built-in variables. Parameter and Varying related nodes are not allowed.

## Properties

- `group_name: String` = `"NodeGroup"` — The display name of this group.
- `input_port_count: int` = `0` — The number of input ports defined for this group.
- `input_port_{index}/name: String` = `""` — The name of the input port at `index`.
- `input_port_{index}/type: int` = `0` — The `VisualShaderNode.PortType` of the input port at `index`.
- `output_port_count: int` = `0` — The number of output ports defined for this group.
- `output_port_{index}/name: String` = `""` — The name of the output port at `index`.
- `output_port_{index}/type: int` = `0` — The `VisualShaderNode.PortType` of the output port at `index`.

## Methods

- `add_node(node: VisualShaderNode, position: Vector2, id: int) -> void` — Adds the specified `node` to the group.
- `attach_node_to_frame(id: int, frame: int) -> void` — Attaches the given node to the given frame.
- `can_connect_nodes(from_node: int, from_port: int, to_node: int, to_port: int) -> bool` *const* — Returns `true` if the specified nodes and ports can be connected.
- `connect_nodes(from_node: int, from_port: int, to_node: int, to_port: int) -> int[Error]` — Connects the specified nodes and ports.
- `connect_nodes_forced(from_node: int, from_port: int, to_node: int, to_port: int) -> void` — Connects the specified nodes and ports, even if they can't be connected.
- `detach_node_from_frame(id: int) -> void` — Detaches the given node from the frame it is attached to.
- `disconnect_nodes(from_node: int, from_port: int, to_node: int, to_port: int) -> void` — Disconnects the specified nodes and ports.
- `get_input_port_name(id: int) -> String` *const* — Returns the name of the input port at the given `id`.
- `get_input_port_type(id: int) -> int[VisualShaderNode.PortType]` *const* — Returns the type of the input port at the given `id`.
- `get_node(id: int) -> VisualShaderNode` *const* — Returns the shader node instance with the specified `id`.
- `get_node_connections() -> Dictionary[]` *const* — Returns the list of connected nodes.
- `get_node_list() -> PackedInt32Array` *const* — Returns the list of all nodes in the group.
- `get_node_position(id: int) -> Vector2` *const* — Returns the position of the specified node within the shader graph.
- `get_output_port_name(id: int) -> String` *const* — Returns the name of the output port at the given `id`.
- `get_output_port_type(id: int) -> int[VisualShaderNode.PortType]` *const* — Returns the type of the output port at the given `id`.
- `get_valid_node_id() -> int` *const* — Returns the next valid node ID that can be added to the shader graph.
- `insert_input_port(id: int, type: VisualShaderNode.PortType, name: String) -> String` — Inserts an input port at the given `id` with the specified `type` and `name`.
- `insert_output_port(id: int, type: VisualShaderNode.PortType, name: String) -> String` — Inserts an output port at the given `id` with the specified `type` and `name`.
- `is_node_connection(from_node: int, from_port: int, to_node: int, to_port: int) -> bool` *const* — Returns `true` if the specified node and port connection exists.
- `move_input_port(from: int, to: int) -> void` — Moves the input port at index `from` to index `to`.
- `move_output_port(from: int, to: int) -> void` — Moves the output port at index `from` to index `to`.
- `remove_input_port(id: int) -> void` — Removes the input port at the given `id`.
- `remove_node(id: int) -> void` — Removes the specified node from the group.
- `remove_output_port(id: int) -> void` — Removes the output port at the given `id`.
- `replace_node(id: int, new_class: StringName) -> void` — Replaces the specified node with a node of the new class type.
- `set_input_port_name(id: int, name: String) -> void` — Sets the name of the input port at the given `id`.
- `set_input_port_type(id: int, type: VisualShaderNode.PortType) -> void` — Sets the type of the input port at the given `id`.
- `set_node_position(id: int, position: Vector2) -> void` — Sets the position of the specified node.
- `set_output_port_name(id: int, name: String) -> void` — Sets the name of the output port at the given `id`.
- `set_output_port_type(id: int, type: VisualShaderNode.PortType) -> void` — Sets the type of the output port at the given `id`.
