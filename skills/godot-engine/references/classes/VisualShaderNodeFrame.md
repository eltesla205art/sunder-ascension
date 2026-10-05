# VisualShaderNodeFrame

**Inherits:** VisualShaderNodeResizableBase

A frame other visual shader nodes can be attached to for better organization.

A rectangular frame that can be used to group visual shader nodes together to improve organization. Nodes attached to the frame will move with it when it is dragged and it can automatically resize to enclose all attached nodes. Its title, description and color can be customized.

## Properties

- `attached_nodes: PackedInt32Array` = `PackedInt32Array()` — The list of nodes attached to the frame.
- `autoshrink: bool` = `true` — If `true`, the frame will automatically resize to enclose all attached nodes.
- `tint_color: Color` = `Color(0.3, 0.3, 0.3, 0.75)` — The color of the frame when `tint_color_enabled` is `true`.
- `tint_color_enabled: bool` = `false` — If `true`, the frame will be tinted with the color specified in `tint_color`.
- `title: String` = `"Title"` — The title of the node.

## Methods

- `add_attached_node(node: int) -> void` — Adds a node to the list of nodes attached to the frame.
- `remove_attached_node(node: int) -> void` — Removes a node from the list of nodes attached to the frame.
