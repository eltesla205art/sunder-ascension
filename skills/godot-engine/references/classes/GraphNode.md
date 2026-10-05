# GraphNode

**Inherits:** GraphElement

A container with connection ports, representing a node in a GraphEdit.

GraphNode allows to create nodes for a GraphEdit graph with customizable content based on its child controls. GraphNode is derived from Container and it is responsible for placing its children on screen. This works similar to VBoxContainer. Children, in turn, provide GraphNode with so-called slots, each of which can have a connection port on either side.

## Properties

- `focus_mode: Control.FocusMode` = `3` — 
- `ignore_invalid_connection_type: bool` = `false` — If `true`, you can connect ports with different types, even if the connection was not explicitly allowed in the parent GraphEdit.
- `mouse_filter: Control.MouseFilter` = `0` — 
- `slots_focus_mode: Control.FocusMode` = `3` — Determines how connection slots can be focused. - If set to `Control.FOCUS_CLICK`, connections can only be made with the mouse. - If set to `Control.FOCUS_ALL`, slots can also be focused using the `ProjectSettings.input/ui_up` and `ProjectSettings.input/ui_down` and connected using `ProjectSettings.input/ui_left` and `ProjectSettings.input/ui_right` input actions. - If set to `Control.FOCUS_ACCESSIBILITY`, slot input actions are only enabled when the screen reader is active.
- `title: String` = `""` — The text displayed in the GraphNode's title bar.

## Methods

- `_draw_port(slot_index: int, position: Vector2i, left: bool, color: Color) -> void` *virtual*
- `clear_all_slots() -> void` — Disables all slots of the GraphNode.
- `clear_slot(slot_index: int) -> void` — Disables the slot with the given `slot_index`.
- `get_input_port_color(port_idx: int) -> Color` — Returns the Color of the input port with the given `port_idx`.
- `get_input_port_count() -> int` — Returns the number of slots with an enabled input port.
- `get_input_port_position(port_idx: int) -> Vector2` — Returns the position of the input port with the given `port_idx`.
- `get_input_port_slot(port_idx: int) -> int` — Returns the corresponding slot index of the input port with the given `port_idx`.
- `get_input_port_type(port_idx: int) -> int` — Returns the type of the input port with the given `port_idx`.
- `get_output_port_color(port_idx: int) -> Color` — Returns the Color of the output port with the given `port_idx`.
- `get_output_port_count() -> int` — Returns the number of slots with an enabled output port.
- `get_output_port_position(port_idx: int) -> Vector2` — Returns the position of the output port with the given `port_idx`.
- `get_output_port_slot(port_idx: int) -> int` — Returns the corresponding slot index of the output port with the given `port_idx`.
- `get_output_port_type(port_idx: int) -> int` — Returns the type of the output port with the given `port_idx`.
- `get_slot_color_left(slot_index: int) -> Color` *const* — Returns the left (input) Color of the slot with the given `slot_index`.
- `get_slot_color_right(slot_index: int) -> Color` *const* — Returns the right (output) Color of the slot with the given `slot_index`.
- `get_slot_custom_icon_left(slot_index: int) -> Texture2D` *const* — Returns the left (input) custom Texture2D of the slot with the given `slot_index`.
- `get_slot_custom_icon_right(slot_index: int) -> Texture2D` *const* — Returns the right (output) custom Texture2D of the slot with the given `slot_index`.
- `get_slot_metadata_left(slot_index: int) -> Variant` *const* — Returns the left (input) metadata of the slot with the given `slot_index`.
- `get_slot_metadata_right(slot_index: int) -> Variant` *const* — Returns the right (output) metadata of the slot with the given `slot_index`.
- `get_slot_type_left(slot_index: int) -> int` *const* — Returns the left (input) type of the slot with the given `slot_index`.
- `get_slot_type_right(slot_index: int) -> int` *const* — Returns the right (output) type of the slot with the given `slot_index`.
- `get_titlebar_hbox() -> HBoxContainer` — Returns the HBoxContainer used for the title bar, only containing a Label for displaying the title by default.
- `is_slot_draw_stylebox(slot_index: int) -> bool` *const* — Returns `true` if the background StyleBox of the slot with the given `slot_index` is drawn.
- `is_slot_enabled_left(slot_index: int) -> bool` *const* — Returns `true` if left (input) side of the slot with the given `slot_index` is enabled.
- `is_slot_enabled_right(slot_index: int) -> bool` *const* — Returns `true` if right (output) side of the slot with the given `slot_index` is enabled.
- `set_slot(slot_index: int, enable_left_port: bool, type_left: int, color_left: Color, enable_right_port: bool, type_right: int, color_right: Color, custom_icon_left: Texture2D = null, custom_icon_right: Texture2D = null, draw_stylebox: bool = true) -> void` — Sets properties of the slot with the given `slot_index`.
- `set_slot_color_left(slot_index: int, color: Color) -> void` — Sets the Color of the left (input) side of the slot with the given `slot_index` to `color`.
- `set_slot_color_right(slot_index: int, color: Color) -> void` — Sets the Color of the right (output) side of the slot with the given `slot_index` to `color`.
- `set_slot_custom_icon_left(slot_index: int, custom_icon: Texture2D) -> void` — Sets the custom Texture2D of the left (input) side of the slot with the given `slot_index` to `custom_icon`.
- `set_slot_custom_icon_right(slot_index: int, custom_icon: Texture2D) -> void` — Sets the custom Texture2D of the right (output) side of the slot with the given `slot_index` to `custom_icon`.
- `set_slot_draw_stylebox(slot_index: int, enable: bool) -> void` — Toggles the background StyleBox of the slot with the given `slot_index`.
- `set_slot_enabled_left(slot_index: int, enable: bool) -> void` — Toggles the left (input) side of the slot with the given `slot_index`.
- `set_slot_enabled_right(slot_index: int, enable: bool) -> void` — Toggles the right (output) side of the slot with the given `slot_index`.
- `set_slot_metadata_left(slot_index: int, value: Variant) -> void` — Sets the custom metadata for the left (input) side of the slot with the given `slot_index` to `value`.
- `set_slot_metadata_right(slot_index: int, value: Variant) -> void` — Sets the custom metadata for the right (output) side of the slot with the given `slot_index` to `value`.
- `set_slot_type_left(slot_index: int, type: int) -> void` — Sets the left (input) type of the slot with the given `slot_index` to `type`.
- `set_slot_type_right(slot_index: int, type: int) -> void` — Sets the right (output) type of the slot with the given `slot_index` to `type`.

## Signals

- `slot_sizes_changed()` — Emitted when any slot's size might have changed.
- `slot_updated(slot_index: int)` — Emitted when any GraphNode's slot is updated.

## Theme items

- `resizer_color: Color` (color) = `Color(0.875, 0.875, 0.875, 1)`
- `port_h_offset: int` (constant) = `0`
- `separation: int` (constant) = `2`
- `port: Texture2D` (icon)
- `panel: StyleBox` (style)
- `panel_focus: StyleBox` (style)
- `panel_selected: StyleBox` (style)
- `slot: StyleBox` (style)
- `slot_selected: StyleBox` (style)
- `titlebar: StyleBox` (style)
- `titlebar_selected: StyleBox` (style)
