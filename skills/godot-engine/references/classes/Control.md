# Control

**Inherits:** CanvasItem

Base class for all GUI controls. Adapts its position and size based on its parent control.

Base class for all UI-related nodes. Control features a bounding rectangle that defines its extents, an anchor position relative to its parent control or the current viewport, and offsets relative to the anchor. The offsets update automatically when the node, any of its parents, or the screen size change. For more information on Godot's UI system, anchors, offsets, and containers, see the related tutorials in the manual.

## Properties

- `accessibility_controls_nodes: NodePath[]` = `[]` — The paths to the nodes which are controlled by this node.
- `accessibility_described_by_nodes: NodePath[]` = `[]` — The paths to the nodes which are describing this node.
- `accessibility_description: String` = `""` — The human-readable node description that is reported to assistive apps.
- `accessibility_flow_to_nodes: NodePath[]` = `[]` — The paths to the nodes which this node flows into.
- `accessibility_labeled_by_nodes: NodePath[]` = `[]` — The paths to the nodes which label this node.
- `accessibility_live: AccessibilityServer.AccessibilityLiveMode` = `0` — The mode with which a live region updates.
- `accessibility_name: String` = `""` — The human-readable node name that is reported to assistive apps.
- `anchor_bottom: float` = `0.0` — Anchors the bottom edge of the node to the origin, the center, or the end of its parent control.
- `anchor_left: float` = `0.0` — Anchors the left edge of the node to the origin, the center or the end of its parent control.
- `anchor_right: float` = `0.0` — Anchors the right edge of the node to the origin, the center or the end of its parent control.
- `anchor_top: float` = `0.0` — Anchors the top edge of the node to the origin, the center or the end of its parent control.
- `auto_translate: bool` *(deprecated)* — Toggles if any text should automatically change to its translated version depending on the current locale.
- `clip_contents: bool` = `false` — Enables whether rendering of CanvasItem based children should be clipped to this control's rectangle.
- `custom_maximum_size: Vector2` = `Vector2(-1, -1)` — The maximum size of the node's bounding rectangle.
- `custom_minimum_size: Vector2` = `Vector2(0, 0)` — The minimum size of the node's bounding rectangle.
- `focus_behavior_recursive: Control.FocusBehaviorRecursive` = `0` — Determines which controls can be focused together with `focus_mode`.
- `focus_mode: Control.FocusMode` = `0` — Determines which controls can be focused.
- `focus_neighbor_bottom: NodePath` = `NodePath("")` — Tells Godot which node it should give focus to if the user presses the down arrow on the keyboard or down on a gamepad by default.
- `focus_neighbor_left: NodePath` = `NodePath("")` — Tells Godot which node it should give focus to if the user presses the left arrow on the keyboard or left on a gamepad by default.
- `focus_neighbor_right: NodePath` = `NodePath("")` — Tells Godot which node it should give focus to if the user presses the right arrow on the keyboard or right on a gamepad by default.
- `focus_neighbor_top: NodePath` = `NodePath("")` — Tells Godot which node it should give focus to if the user presses the top arrow on the keyboard or top on a gamepad by default.
- `focus_next: NodePath` = `NodePath("")` — Tells Godot which node it should give focus to if the user presses `Tab` on a keyboard by default.
- `focus_previous: NodePath` = `NodePath("")` — Tells Godot which node it should give focus to if the user presses `Shift + Tab` on a keyboard by default.
- `global_position: Vector2` — The node's global position, relative to the world (usually to the CanvasLayer).
- `grow_horizontal: Control.GrowDirection` = `1` — Controls the direction on the horizontal axis in which the control should grow or shrink if its horizontal size is changed.
- `grow_vertical: Control.GrowDirection` = `1` — Controls the direction on the vertical axis in which the control should grow or shrink if its vertical size is changed.
- `layout_direction: Control.LayoutDirection` = `0` — Controls layout direction and text writing direction.
- `localize_numeral_system: bool` = `true` — If `true`, automatically converts code line numbers, list indices, SpinBox and ProgressBar values from the Western Arabic (0..9) to the numeral systems used in current locale.
- `mouse_behavior_recursive: Control.MouseBehaviorRecursive` = `0` — Determines which controls can receive mouse input together with `mouse_filter`.
- `mouse_default_cursor_shape: Control.CursorShape` = `0` — The default cursor shape for this control.
- `mouse_filter: Control.MouseFilter` = `0` — Determines which controls will be able to receive mouse button input events through `_gui_input` and the `mouse_entered`, and `mouse_exited` signals.
- `mouse_force_pass_scroll_events: bool` = `true` — When enabled, scroll wheel events processed by `_gui_input` will be passed to the parent control even if `mouse_filter` is set to `MOUSE_FILTER_STOP`.
- `offset_bottom: float` = `0.0` — Distance between the node's bottom edge and its parent control, based on `anchor_bottom`.
- `offset_left: float` = `0.0` — Distance between the node's left edge and its parent control, based on `anchor_left`.
- `offset_right: float` = `0.0` — Distance between the node's right edge and its parent control, based on `anchor_right`.
- `offset_top: float` = `0.0` — Distance between the node's top edge and its parent control, based on `anchor_top`.
- `offset_transform_enabled: bool` = `false` — If `true`, applies all offset transform properties.
- `offset_transform_pivot: Vector2` = `Vector2(0, 0)` — Pivot used by `offset_transform_rotation` and `offset_transform_scale` in absolute units.
- `offset_transform_pivot_ratio: Vector2` = `Vector2(0.5, 0.5)` — Same as `offset_transform_pivot` but expressed in units relative to the Control `size` where `Vector2(0, 0)` is the top-left corner of this control, and `Vector2(1, 1)` is its bottom-right corner.
- `offset_transform_position: Vector2` = `Vector2(0, 0)` — Position offset in absolute units.
- `offset_transform_position_ratio: Vector2` = `Vector2(0, 0)` — Same as `offset_transform_position` but expressed in units relative to the Control `size` where `Vector2(0, 0)` is the top-left corner of this control, and `Vector2(1, 1)` is its bottom-right corner.
- `offset_transform_rotation: float` = `0.0` — Rotation offset.
- `offset_transform_scale: Vector2` = `Vector2(1, 1)` — Scale offset.
- `offset_transform_visual_only: bool` = `true` — If `true`, the offset transforms is only applied visually and does not affect input.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` — 
- `pivot_offset: Vector2` = `Vector2(0, 0)` — By default, the node's pivot is its top-left corner.
- `pivot_offset_ratio: Vector2` = `Vector2(0, 0)` — Same as `pivot_offset`, but expressed as uniform vector, where `Vector2(0, 0)` is the top-left corner of this control, and `Vector2(1, 1)` is its bottom-right corner.
- `position: Vector2` = `Vector2(0, 0)` — The node's position, relative to its containing node.
- `propagate_maximum_size: bool` = `false` — If `true`, this Control's children will use the value returned by `get_combined_maximum_size` in their own size calculations.
- `rotation: float` = `0.0` — The node's rotation around its pivot, in radians.
- `rotation_degrees: float` — Helper property to access `rotation` in degrees instead of radians.
- `scale: Vector2` = `Vector2(1, 1)` — The node's scale, relative to its `size`.
- `shortcut_context: Node` — The Node which must be a parent of the focused Control for the shortcut to be activated.
- `size: Vector2` = `Vector2(0, 0)` — The size of the node's bounding rectangle, in the node's coordinate system.
- `size_flags_horizontal: Control.SizeFlags` = `1` — Tells the parent Container nodes how they should resize and place the node on the X axis.
- `size_flags_stretch_ratio: float` = `1.0` — If the node and at least one of its neighbors uses the `SIZE_EXPAND` size flag, the parent Container will let it take more or less space depending on this property.
- `size_flags_vertical: Control.SizeFlags` = `1` — Tells the parent Container nodes how they should resize and place the node on the Y axis.
- `theme: Theme` — The Theme resource this node and all its Control and Window children use.
- `theme_type_variation: StringName` = `&""` — The name of a theme type variation used by this Control to look up its own theme items.
- `tooltip_auto_translate_mode: Node.AutoTranslateMode` = `0` — Defines if tooltip text should automatically change to its translated version depending on the current locale.
- `tooltip_text: String` = `""` — The default tooltip text.
- `translation_context: StringName` = `&""` — The translation context used when translating this control's displayed text, if it has any.

## Methods

- `_accessibility_get_contextual_info() -> String` *virtual const* — Return the description of the keyboard shortcuts and other contextual help for this control.
- `_can_drop_data(at_position: Vector2, data: Variant) -> bool` *virtual const* — Godot calls this method to test if `data` from a control's `_get_drag_data` can be dropped at `at_position`.
- `_drop_data(at_position: Vector2, data: Variant) -> void` *virtual* — Godot calls this method to pass you the `data` from a control's `_get_drag_data` result.
- `_get_accessibility_container_name(node: Node) -> String` *virtual const* — Override this method to return a human-readable description of the position of the child `node` in the custom container, added to the `accessibility_name`.
- `_get_cursor_shape(at_position: Vector2) -> int` *virtual const* — Virtual method to be implemented by the user.
- `_get_drag_data(at_position: Vector2) -> Variant` *virtual* — Godot calls this method to get data that can be dragged and dropped onto controls that expect drop data.
- `_get_maximum_size() -> Vector2` *virtual const* — Virtual method to be implemented by the user.
- `_get_minimum_size() -> Vector2` *virtual const* — Virtual method to be implemented by the user.
- `_get_tooltip(at_position: Vector2) -> String` *virtual const* — Virtual method to be implemented by the user.
- `_get_tooltip_auto_translate_mode_at(at_position: Vector2) -> int[Node.AutoTranslateMode]` *virtual const* — Return the auto-translation mode at the given `at_position`.
- `_gui_input(event: InputEvent) -> void` *virtual* — Virtual method to be implemented by the user.
- `_has_point(point: Vector2) -> bool` *virtual const* — Virtual method to be implemented by the user.
- `_make_custom_tooltip(for_text: String) -> Object` *virtual const* — Virtual method to be implemented by the user.
- `_structured_text_parser(args: Array, text: String) -> Vector3i[]` *virtual const* — User defined BiDi algorithm override function.
- `accept_event() -> void` — Marks an input event as handled.
- `accessibility_drag() -> void` — Starts drag-and-drop operation without using a mouse.
- `accessibility_drop() -> void` — Ends drag-and-drop operation without using a mouse.
- `add_theme_color_override(name: StringName, color: Color) -> void` — Creates a local override for a theme Color with the specified `name`.
- `add_theme_constant_override(name: StringName, constant: int) -> void` — Creates a local override for a theme constant with the specified `name`.
- `add_theme_font_override(name: StringName, font: Font) -> void` — Creates a local override for a theme Font with the specified `name`.
- `add_theme_font_size_override(name: StringName, font_size: int) -> void` — Creates a local override for a theme font size with the specified `name`.
- `add_theme_icon_override(name: StringName, texture: Texture2D) -> void` — Creates a local override for a theme icon with the specified `name`.
- `add_theme_sound_override(name: StringName, audio: AudioStream) -> void` — Creates a local override for a theme sound with the specified `name`.
- `add_theme_stylebox_override(name: StringName, stylebox: StyleBox) -> void` — Creates a local override for a theme StyleBox with the specified `name`.
- `begin_bulk_theme_override() -> void` — Prevents `*_theme_*_override` methods from emitting `NOTIFICATION_THEME_CHANGED` until `end_bulk_theme_override` is called.
- `end_bulk_theme_override() -> void` — Ends a bulk theme override update.
- `find_next_valid_focus() -> Control` *const* — Finds the next (below in the tree) Control that can receive the focus.
- `find_prev_valid_focus() -> Control` *const* — Finds the previous (above in the tree) Control that can receive the focus.
- `find_valid_focus_neighbor(side: Side) -> Control` *const* — Finds the next Control that can receive the focus on the specified `Side`.
- `force_drag(data: Variant, preview: Control) -> void` — Forces drag and bypasses `_get_drag_data` and `set_drag_preview` by passing `data` and `preview`.
- `get_anchor(side: Side) -> float` *const* — Returns the anchor for the specified `Side`.
- `get_begin() -> Vector2` *const* — Returns `offset_left` and `offset_top`.
- `get_bound_minimum_size() -> Vector2` *const* — Returns the bound value of `get_combined_minimum_size` by `get_combined_maximum_size`.
- `get_combined_maximum_size() -> Vector2` *const* — Returns the combined maximum size from `custom_maximum_size` and `get_maximum_size`, as well as the `custom_maximum_size` of this node's parent if it is a Control node with `propagate_maximum_size` set to `true`.
- `get_combined_minimum_size() -> Vector2` *const* — Returns the combined minimum size from `custom_minimum_size` and `get_minimum_size`.
- `get_combined_pivot_offset() -> Vector2` *const* — Returns the combined value of `pivot_offset` and `pivot_offset_ratio`, in pixels.
- `get_cursor_shape(at_position: Vector2 = Vector2(0, 0)) -> int[Control.CursorShape]` *const* — Returns the mouse cursor shape for this control when hovered over `at_position` in local coordinates.
- `get_end() -> Vector2` *const* — Returns `offset_right` and `offset_bottom`.
- `get_focus_mode_with_override() -> int[Control.FocusMode]` *const* — Returns the `focus_mode`, but takes the `focus_behavior_recursive` into account.
- `get_focus_neighbor(side: Side) -> NodePath` *const* — Returns the focus neighbor for the specified `Side`.
- `get_global_rect() -> Rect2` *const* — Returns the position and size of the control relative to the containing canvas.
- `get_maximum_size() -> Vector2` *const* — Returns the maximum size for this control.
- `get_minimum_size() -> Vector2` *const* — Returns the minimum size for this control.
- `get_mouse_filter_with_override() -> int[Control.MouseFilter]` *const* — Returns the `mouse_filter`, but takes the `mouse_behavior_recursive` into account.
- `get_offset(offset: Side) -> float` *const* — Returns the offset for the specified `Side`.
- `get_parent_area_size() -> Vector2` *const* — Returns the width/height occupied in the parent control.
- `get_parent_control() -> Control` *const* — Returns the parent control node.
- `get_rect() -> Rect2` *const* — Returns the position and size of the control in the coordinate system of the containing node.
- `get_screen_position() -> Vector2` *const* — Returns the position of this Control in global screen coordinates (i.e. taking window position into account).
- `get_theme_color(name: StringName, theme_type: StringName = &"") -> Color` *const* — Returns a Color from the first matching Theme in the tree if that Theme has a color item with the specified `name` and `theme_type`.
- `get_theme_constant(name: StringName, theme_type: StringName = &"") -> int` *const* — Returns a constant from the first matching Theme in the tree if that Theme has a constant item with the specified `name` and `theme_type`.
- `get_theme_default_base_scale() -> float` *const* — Returns the default base scale value from the first matching Theme in the tree if that Theme has a valid `Theme.default_base_scale` value.
- `get_theme_default_font() -> Font` *const* — Returns the default font from the first matching Theme in the tree if that Theme has a valid `Theme.default_font` value.
- `get_theme_default_font_size() -> int` *const* — Returns the default font size value from the first matching Theme in the tree if that Theme has a valid `Theme.default_font_size` value.
- `get_theme_font(name: StringName, theme_type: StringName = &"") -> Font` *const* — Returns a Font from the first matching Theme in the tree if that Theme has a font item with the specified `name` and `theme_type`.
- `get_theme_font_size(name: StringName, theme_type: StringName = &"") -> int` *const* — Returns a font size from the first matching Theme in the tree if that Theme has a font size item with the specified `name` and `theme_type`.
- `get_theme_icon(name: StringName, theme_type: StringName = &"") -> Texture2D` *const* — Returns an icon from the first matching Theme in the tree if that Theme has an icon item with the specified `name` and `theme_type`.
- `get_theme_sound(name: StringName, theme_type: StringName = &"") -> AudioStream` *const* — Returns a sound from the first matching Theme in the tree if that Theme has a sound item with the specified `name` and `theme_type`.
- `get_theme_stylebox(name: StringName, theme_type: StringName = &"") -> StyleBox` *const* — Returns a StyleBox from the first matching Theme in the tree if that Theme has a stylebox item with the specified `name` and `theme_type`.
- `get_tooltip(at_position: Vector2 = Vector2(0, 0)) -> String` *const* — Returns the tooltip text for the position `at_position` in the control's local coordinates, which will typically appear when the cursor is resting over this control.
- `grab_click_focus() -> void` — Creates an InputEventMouseButton that attempts to click the control.
- `grab_focus(hide_focus: bool = false) -> void` — Steal the focus from another control and become the focused control (see `focus_mode`).
- `has_focus(ignore_hidden_focus: bool = false) -> bool` *const* — Returns `true` if this is the current focused control.
- `has_theme_color(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a color item with the specified `name` and `theme_type`.
- `has_theme_color_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme Color with the specified `name` in this Control node.
- `has_theme_constant(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a constant item with the specified `name` and `theme_type`.
- `has_theme_constant_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme constant with the specified `name` in this Control node.
- `has_theme_font(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a font item with the specified `name` and `theme_type`.
- `has_theme_font_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme Font with the specified `name` in this Control node.
- `has_theme_font_size(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a font size item with the specified `name` and `theme_type`.
- `has_theme_font_size_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme font size with the specified `name` in this Control node.
- `has_theme_icon(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has an icon item with the specified `name` and `theme_type`.
- `has_theme_icon_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme icon with the specified `name` in this Control node.
- `has_theme_sound(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a sound item with the specified `name` and `theme_type`.
- `has_theme_sound_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme sound with the specified `name` in this Control node.
- `has_theme_stylebox(name: StringName, theme_type: StringName = &"") -> bool` *const* — Returns `true` if there is a matching Theme in the tree that has a stylebox item with the specified `name` and `theme_type`.
- `has_theme_stylebox_override(name: StringName) -> bool` *const* — Returns `true` if there is a local override for a theme StyleBox with the specified `name` in this Control node.
- `is_drag_successful() -> bool` *const* — Returns `true` if a drag operation is successful.
- `is_layout_rtl() -> bool` *const* — Returns `true` if the layout is right-to-left.
- `play_theme_sound(stream: AudioStream) -> void` — Plays the sound from the `stream` resource non-positionally in the bus specified by the `ProjectSettings.audio/buses/gui_theme_bus` project setting.
- `release_focus() -> void` — Give up the focus.
- `remove_theme_color_override(name: StringName) -> void` — Removes a local override for a theme Color with the specified `name` previously added by `add_theme_color_override` or via the Inspector dock.
- `remove_theme_constant_override(name: StringName) -> void` — Removes a local override for a theme constant with the specified `name` previously added by `add_theme_constant_override` or via the Inspector dock.
- `remove_theme_font_override(name: StringName) -> void` — Removes a local override for a theme Font with the specified `name` previously added by `add_theme_font_override` or via the Inspector dock.
- `remove_theme_font_size_override(name: StringName) -> void` — Removes a local override for a theme font size with the specified `name` previously added by `add_theme_font_size_override` or via the Inspector dock.
- `remove_theme_icon_override(name: StringName) -> void` — Removes a local override for a theme icon with the specified `name` previously added by `add_theme_icon_override` or via the Inspector dock.
- `remove_theme_sound_override(name: StringName) -> void` — Removes a local override for a theme sound with the specified `name` previously added by `add_theme_sound_override` or via the Inspector dock.
- `remove_theme_stylebox_override(name: StringName) -> void` — Removes a local override for a theme StyleBox with the specified `name` previously added by `add_theme_stylebox_override` or via the Inspector dock.
- `reset_size() -> void` — Resets the size to `get_combined_minimum_size`.
- `set_anchor(side: Side, anchor: float, keep_offset: bool = false, push_opposite_anchor: bool = true) -> void` — Sets the anchor for the specified `Side` to `anchor`.
- `set_anchor_and_offset(side: Side, anchor: float, offset: float, push_opposite_anchor: bool = false) -> void` — Works the same as `set_anchor`, but instead of `keep_offset` argument and automatic update of offset, it allows to set the offset yourself (see `set_offset`).
- `set_anchors_and_offsets_preset(preset: Control.LayoutPreset, resize_mode: Control.LayoutPresetMode = 0, margin: int = 0) -> void` — Sets both anchor preset and offset preset.
- `set_anchors_preset(preset: Control.LayoutPreset, keep_offsets: bool = false) -> void` — Sets the anchors to a `preset` from `Control.LayoutPreset` enum.
- `set_begin(position: Vector2) -> void` — Sets `offset_left` and `offset_top` at the same time.
- `set_drag_forwarding(drag_func: Callable, can_drop_func: Callable, drop_func: Callable) -> void` — Sets the given callables to be used instead of the control's own drag-and-drop virtual methods.
- `set_drag_preview(control: Control) -> void` — Shows the given control at the mouse pointer.
- `set_end(position: Vector2) -> void` — Sets `offset_right` and `offset_bottom` at the same time.
- `set_focus_neighbor(side: Side, neighbor: NodePath) -> void` — Sets the focus neighbor for the specified `Side` to the Control at `neighbor` node path.
- `set_global_position(position: Vector2, keep_offsets: bool = false) -> void` — Sets the `global_position` to given `position`.
- `set_offset(side: Side, offset: float) -> void` — Sets the offset for the specified `Side` to `offset`.
- `set_offsets_preset(preset: Control.LayoutPreset, resize_mode: Control.LayoutPresetMode = 0, margin: int = 0) -> void` — Sets the offsets to a `preset` from `Control.LayoutPreset` enum.
- `set_position(position: Vector2, keep_offsets: bool = false) -> void` — Sets the `position` to given `position`.
- `set_size(size: Vector2, keep_offsets: bool = false) -> void` — Sets the size (see `size`).
- `update_maximum_size() -> void` — Invalidates the maximum size cache in this node and in child nodes with `CanvasItem.top_level` set to `false`.
- `update_minimum_size() -> void` — Invalidates the minimum size cache in this node and in parent nodes up to top level.
- `warp_mouse(position: Vector2) -> void` — Moves the mouse cursor to `position`, relative to `position` of this Control.

## Signals

- `focus_entered()` — Emitted when the node gains focus.
- `focus_exited()` — Emitted when the node loses focus.
- `gui_input(event: InputEvent)` — Emitted when the node receives an InputEvent.
- `maximum_size_changed()` — Emitted when the node's maximum size changes.
- `minimum_size_changed()` — Emitted when the node's minimum size changes.
- `mouse_entered()` — Emitted when the mouse cursor enters the control's (or any child control's) visible area, that is not occluded behind other Controls or Windows, provided its `mouse_filter` lets the event reach it and regardless if it's currently focused or not.
- `mouse_exited()` — Emitted when the mouse cursor leaves the control's (and all child control's) visible area, that is not occluded behind other Controls or Windows, provided its `mouse_filter` lets the event reach it and regardless if it's currently focused or not.
- `resized()` — Emitted when the control changes size.
- `size_flags_changed()` — Emitted when one of the size flags changes.
- `theme_changed()` — Emitted when the `NOTIFICATION_THEME_CHANGED` notification is sent.

## Enum FocusMode

- `FOCUS_NONE = 0` — The node cannot grab focus.
- `FOCUS_CLICK = 1` — The node can only grab focus on mouse clicks.
- `FOCUS_ALL = 2` — The node can grab focus on mouse click, using the arrows and the Tab keys on the keyboard, or using the D-pad buttons on a gamepad.
- `FOCUS_ACCESSIBILITY = 3` — The node can grab focus only when screen reader is active.

## Enum FocusBehaviorRecursive

- `FOCUS_BEHAVIOR_INHERITED = 0` — Inherits the `focus_behavior_recursive` from the parent control.
- `FOCUS_BEHAVIOR_DISABLED = 1` — Prevents the control from getting focused.
- `FOCUS_BEHAVIOR_ENABLED = 2` — Allows the control to be focused, depending on the `focus_mode`.

## Enum MouseBehaviorRecursive

- `MOUSE_BEHAVIOR_INHERITED = 0` — Inherits the `mouse_behavior_recursive` from the parent control.
- `MOUSE_BEHAVIOR_DISABLED = 1` — Prevents the control from receiving mouse input.
- `MOUSE_BEHAVIOR_ENABLED = 2` — Allows the control to receive mouse input, depending on the `mouse_filter`.

## Enum CursorShape

- `CURSOR_ARROW = 0` — Show the system's arrow mouse cursor when the user hovers the node.
- `CURSOR_IBEAM = 1` — Show the system's I-beam mouse cursor when the user hovers the node.
- `CURSOR_POINTING_HAND = 2` — Show the system's pointing hand mouse cursor when the user hovers the node.
- `CURSOR_CROSS = 3` — Show the system's cross mouse cursor when the user hovers the node.
- `CURSOR_WAIT = 4` — Show the system's wait mouse cursor when the user hovers the node.
- `CURSOR_BUSY = 5` — Show the system's busy mouse cursor when the user hovers the node.
- `CURSOR_DRAG = 6` — Show the system's drag mouse cursor, often a closed fist or a cross symbol, when the user hovers the node.
- `CURSOR_CAN_DROP = 7` — Show the system's drop mouse cursor when the user hovers the node.
- `CURSOR_FORBIDDEN = 8` — Show the system's forbidden mouse cursor when the user hovers the node.
- `CURSOR_VSIZE = 9` — Show the system's vertical resize mouse cursor when the user hovers the node.
- `CURSOR_HSIZE = 10` — Show the system's horizontal resize mouse cursor when the user hovers the node.
- `CURSOR_BDIAGSIZE = 11` — Show the system's window resize mouse cursor when the user hovers the node.
- `CURSOR_FDIAGSIZE = 12` — Show the system's window resize mouse cursor when the user hovers the node.
- `CURSOR_MOVE = 13` — Show the system's move mouse cursor when the user hovers the node.
- `CURSOR_VSPLIT = 14` — Show the system's vertical split mouse cursor when the user hovers the node.
- `CURSOR_HSPLIT = 15` — Show the system's horizontal split mouse cursor when the user hovers the node.
- `CURSOR_HELP = 16` — Show the system's help mouse cursor when the user hovers the node, a question mark.

## Enum LayoutPreset

- `PRESET_TOP_LEFT = 0` — Snap all 4 anchors to the top-left of the parent control's bounds.
- `PRESET_TOP_RIGHT = 1` — Snap all 4 anchors to the top-right of the parent control's bounds.
- `PRESET_BOTTOM_LEFT = 2` — Snap all 4 anchors to the bottom-left of the parent control's bounds.
- `PRESET_BOTTOM_RIGHT = 3` — Snap all 4 anchors to the bottom-right of the parent control's bounds.
- `PRESET_CENTER_LEFT = 4` — Snap all 4 anchors to the center of the left edge of the parent control's bounds.
- `PRESET_CENTER_TOP = 5` — Snap all 4 anchors to the center of the top edge of the parent control's bounds.
- `PRESET_CENTER_RIGHT = 6` — Snap all 4 anchors to the center of the right edge of the parent control's bounds.
- `PRESET_CENTER_BOTTOM = 7` — Snap all 4 anchors to the center of the bottom edge of the parent control's bounds.
- `PRESET_CENTER = 8` — Snap all 4 anchors to the center of the parent control's bounds.
- `PRESET_LEFT_WIDE = 9` — Snap all 4 anchors to the left edge of the parent control.
- `PRESET_TOP_WIDE = 10` — Snap all 4 anchors to the top edge of the parent control.
- `PRESET_RIGHT_WIDE = 11` — Snap all 4 anchors to the right edge of the parent control.
- `PRESET_BOTTOM_WIDE = 12` — Snap all 4 anchors to the bottom edge of the parent control.
- `PRESET_VCENTER_WIDE = 13` — Snap all 4 anchors to a vertical line that cuts the parent control in half.
- `PRESET_HCENTER_WIDE = 14` — Snap all 4 anchors to a horizontal line that cuts the parent control in half.
- `PRESET_FULL_RECT = 15` — Snap all 4 anchors to the respective corners of the parent control.

## Enum LayoutPresetMode

- `PRESET_MODE_MINSIZE = 0` — The control will be resized to its minimum size.
- `PRESET_MODE_KEEP_WIDTH = 1` — The control's width will not change.
- `PRESET_MODE_KEEP_HEIGHT = 2` — The control's height will not change.
- `PRESET_MODE_KEEP_SIZE = 3` — The control's size will not change.

## Enum SizeFlags

- `SIZE_SHRINK_BEGIN = 0` — Tells the parent Container to align the node with its start, either the top or the left edge.
- `SIZE_FILL = 1` — Tells the parent Container to expand the bounds of this node to fill all the available space without pushing any other node.
- `SIZE_EXPAND = 2` — Tells the parent Container to let this node take all the available space on the axis you flag.
- `SIZE_EXPAND_FILL = 3` — Sets the node's size flags to both fill and expand.
- `SIZE_SHRINK_CENTER = 4` — Tells the parent Container to center the node in the available space.
- `SIZE_SHRINK_END = 8` — Tells the parent Container to align the node with its end, either the bottom or the right edge.
- `SIZE_MAXIMIZE = 16` — Tells the parent Container to use the node's `custom_maximum_size` when doing minimum size calculations.

## Enum MouseFilter

- `MOUSE_FILTER_STOP = 0` — The control will receive mouse movement input events and mouse button input events if clicked on through `_gui_input`.
- `MOUSE_FILTER_PASS = 1` — The control will receive mouse movement input events and mouse button input events if clicked on through `_gui_input`.
- `MOUSE_FILTER_IGNORE = 2` — The control will not receive any mouse movement input events nor mouse button input events through `_gui_input`.

## Enum GrowDirection

- `GROW_DIRECTION_BEGIN = 0` — The control will grow/shrink to the left or top if its size is changed to be larger/smaller than its current size on the respective axis.
- `GROW_DIRECTION_END = 1` — The control will grow/shrink to the right or bottom if its size is changed to be larger/smaller than its current size on the respective axis.
- `GROW_DIRECTION_BOTH = 2` — The control will grow/shrink in both directions equally if its size is changed to be larger/smaller than its current size.

## Enum Anchor

- `ANCHOR_BEGIN = 0` — Snaps one of the 4 anchor's sides to the origin of the node's `Rect`, in the top left.
- `ANCHOR_END = 1` — Snaps one of the 4 anchor's sides to the end of the node's `Rect`, in the bottom right.

## Enum LayoutDirection

- `LAYOUT_DIRECTION_INHERITED = 0` — Automatic layout direction, determined from the parent control layout direction.
- `LAYOUT_DIRECTION_APPLICATION_LOCALE = 1` — Automatic layout direction, determined from the current locale.
- `LAYOUT_DIRECTION_LTR = 2` — Left-to-right layout direction.
- `LAYOUT_DIRECTION_RTL = 3` — Right-to-left layout direction.
- `LAYOUT_DIRECTION_SYSTEM_LOCALE = 4` — Automatic layout direction, determined from the system locale.
- `LAYOUT_DIRECTION_MAX = 5` — Represents the size of the `LayoutDirection` enum.
- `LAYOUT_DIRECTION_LOCALE = 1` — 

## Enum TextDirection

- `TEXT_DIRECTION_INHERITED = 3` — Text writing direction is the same as layout direction.
- `TEXT_DIRECTION_AUTO = 0` — Automatic text writing direction, determined from the current locale and text content.
- `TEXT_DIRECTION_LTR = 1` — Left-to-right text writing direction.
- `TEXT_DIRECTION_RTL = 2` — Right-to-left text writing direction.

## Constants

- `NOTIFICATION_RESIZED = 40` — Sent when the node changes size.
- `NOTIFICATION_MOUSE_ENTER = 41` — Sent when the mouse cursor enters the control's (or any child control's) visible area, that is not occluded behind other Controls or Windows, provided its `mouse_filter` lets the event reach it and regardless if it's currently focused or not.
- `NOTIFICATION_MOUSE_EXIT = 42` — Sent when the mouse cursor leaves the control's (and all child control's) visible area, that is not occluded behind other Controls or Windows, provided its `mouse_filter` lets the event reach it and regardless if it's currently focused or not.
- `NOTIFICATION_MOUSE_ENTER_SELF = 60` — Sent when the mouse cursor enters the control's visible area, that is not occluded behind other Controls or Windows, provided its `mouse_filter` lets the event reach it and regardless if it's currently focused or not.
- `NOTIFICATION_MOUSE_EXIT_SELF = 61` — Sent when the mouse cursor leaves the control's visible area, that is not occluded behind other Controls or Windows, provided its `mouse_filter` lets the event reach it and regardless if it's currently focused or not.
- `NOTIFICATION_FOCUS_ENTER = 43` — Sent when the node grabs focus.
- `NOTIFICATION_FOCUS_EXIT = 44` — Sent when the node loses focus.
- `NOTIFICATION_THEME_CHANGED = 45` — Sent when the node needs to refresh its theme items.
- `NOTIFICATION_SCROLL_BEGIN = 47` — Sent when this node is inside a ScrollContainer which has begun being scrolled when dragging the scrollable area with a touch event.
- `NOTIFICATION_SCROLL_END = 48` — Sent when this node is inside a ScrollContainer which has stopped being scrolled when dragging the scrollable area with a touch event.
- `NOTIFICATION_LAYOUT_DIRECTION_CHANGED = 49` — Sent when the control layout direction is changed from LTR or RTL or vice versa.
