# VisualShaderNodeReroute

**Inherits:** VisualShaderNode

A node that allows rerouting a connection within the visual shader graph.

Automatically adapts its port type to the type of the incoming connection and ensures valid connections.

## Methods

- `get_port_type() -> int[VisualShaderNode.PortType]` *const* — Returns the port type of the reroute node.
