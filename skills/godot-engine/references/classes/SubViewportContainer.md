# SubViewportContainer

**Inherits:** Container

A container used for displaying the contents of a SubViewport.

A container that displays the contents of underlying SubViewport child nodes. It uses the combined size of the SubViewports as minimum size, unless `stretch` is enabled. Note: Changing a SubViewportContainer's `Control.scale` will cause its contents to appear distorted. To change its visual size without causing distortion, adjust the node's offset properties instead (if it's not already in a container).

## Properties

- `focus_mode: Control.FocusMode` = `1` — 
- `mouse_target: bool` = `false` — Configure, if either the SubViewportContainer or alternatively the Control nodes of its SubViewport children should be available as targets of mouse-related functionalities, like identifying the drop target in drag-and-drop operations or cursor shape of hovered Control node.
- `stretch: bool` = `false` — If `true`, the sub-viewport will be automatically resized to the control's size.
- `stretch_shrink: int` = `1` — Divides the sub-viewport's effective resolution by this value while preserving its scale.

## Methods

- `_propagate_input_event(event: InputEvent) -> bool` *virtual const* — Virtual method to be implemented by the user.
