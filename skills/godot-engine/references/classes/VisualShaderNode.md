# VisualShaderNode

**Inherits:** Resource

Base class for VisualShader nodes. Not related to scene nodes.

A visual shader graph consists of various nodes. Each node in a graph is an individual resource, represented as a rectangular box containing a title and several related properties. Each node can also be connected to other nodes through their connection ports in order to control the shader's flow.

## Properties

- `linked_parent_graph_frame: int` = `-1` — Represents the index of the frame this node is linked to.
- `output_port_for_preview: int` = `-1` — Sets the output port index which will be showed for preview.

## Methods

- `clear_default_input_values() -> void` — Clears the default input ports value.
- `get_default_input_port(type: VisualShaderNode.PortType) -> int` *const* — Returns the input port which should be connected by default when this node is created as a result of dragging a connection from an existing node to the empty space on the graph.
- `get_default_input_values() -> Array` *const* — Returns an Array containing default values for all of the input ports of the node in the form `[index0, value0, index1, value1, ...]`.
- `get_input_port_default_value(port: int) -> Variant` *const* — Returns the default value of the input `port`.
- `remove_input_port_default_value(port: int) -> void` — Removes the default value of the input `port`.
- `set_default_input_values(values: Array) -> void` — Sets the default input ports values using an Array of the form `[index0, value0, index1, value1, ...]`.
- `set_input_port_default_value(port: int, value: Variant, prev_value: Variant = null) -> void` — Sets the default `value` for the selected input `port`.

## Enum PortType

- `PORT_TYPE_SCALAR = 0` — Floating-point scalar.
- `PORT_TYPE_SCALAR_INT = 1` — Integer scalar.
- `PORT_TYPE_SCALAR_UINT = 2` — Unsigned integer scalar.
- `PORT_TYPE_VECTOR_2D = 3` — 2D vector of floating-point values.
- `PORT_TYPE_VECTOR_3D = 4` — 3D vector of floating-point values.
- `PORT_TYPE_VECTOR_4D = 5` — 4D vector of floating-point values.
- `PORT_TYPE_BOOLEAN = 6` — Boolean type.
- `PORT_TYPE_TRANSFORM = 7` — Transform type.
- `PORT_TYPE_SAMPLER = 8` — Sampler type.
- `PORT_TYPE_MAX = 9` — Represents the size of the `PortType` enum.
