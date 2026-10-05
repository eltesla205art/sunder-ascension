# CanvasItem

**Inherits:** Node

Abstract base class for everything in 2D space.

Abstract base class for everything in 2D space. Canvas items are laid out in a tree; children inherit and extend their parent's transform. CanvasItem is extended by Control for GUI-related nodes, and by Node2D for 2D game objects. Any CanvasItem can draw.

## Properties

- `clip_children: CanvasItem.ClipChildrenMode` = `0` — The mode in which this node clips its children, acting as a mask.
- `light_mask: int` = `1` — The rendering layers in which this CanvasItem responds to Light2D nodes.
- `material: Material` — The material applied to this CanvasItem.
- `modulate: Color` = `Color(1, 1, 1, 1)` — The color applied to this CanvasItem.
- `oversampling_with_scale: CanvasItem.OversamplingWithScale` = `0` — If enabled, oversampling for this CanvasItem is automatically adjusted with scale.
- `self_modulate: Color` = `Color(1, 1, 1, 1)` — The color applied to this CanvasItem.
- `show_behind_parent: bool` = `false` — If `true`, this node draws behind its parent.
- `texture_filter: CanvasItem.TextureFilter` = `0` — The filtering mode used to render this CanvasItem's texture(s).
- `texture_repeat: CanvasItem.TextureRepeat` = `0` — The repeating mode used to render this CanvasItem's texture(s).
- `top_level: bool` = `false` — If `true`, this CanvasItem will not inherit its transform from parent CanvasItems.
- `use_parent_material: bool` = `false` — If `true`, the parent CanvasItem's `material` is used as this node's material.
- `visibility_layer: int` = `1` — The rendering layer in which this CanvasItem is rendered by Viewport nodes.
- `visible: bool` = `true` — If `true`, this CanvasItem may be drawn.
- `y_sort_enabled: bool` = `false` — If `true`, this and child CanvasItem nodes with a higher Y position are rendered in front of nodes with a lower Y position.
- `z_as_relative: bool` = `true` — If `true`, this node's final Z index is relative to its parent's Z index.
- `z_index: int` = `0` — The order in which this node is drawn.

## Methods

- `_draw() -> void` *virtual* — Called when CanvasItem has been requested to redraw (after `queue_redraw` is called, either manually or by the engine).
- `draw_animation_slice(animation_length: float, slice_begin: float, slice_end: float, offset: float = 0.0) -> void` — Subsequent drawing commands will be ignored unless they fall within the specified animation slice.
- `draw_arc(center: Vector2, radius: float, start_angle: float, end_angle: float, point_count: int, color: Color, width: float = -1.0, antialiased: bool = false) -> void` — Draws an unfilled arc between the given angles with a uniform `color` and `width` and optional antialiasing (supported only for positive `width`).
- `draw_char(font: Font, pos: Vector2, char: String, font_size: int = 16, modulate: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draws a string first character using a custom font.
- `draw_char_outline(font: Font, pos: Vector2, char: String, font_size: int = 16, size: int = -1, modulate: Color = Color(1, 1, 1, 1), oversampling: float = 0.0) -> void` *const* — Draws a string first character outline using a custom font.
- `draw_circle(position: Vector2, radius: float, color: Color, filled: bool = true, width: float = -1.0, antialiased: bool = false) -> void` — Draws a circle, with `position` defined in local space.
- `draw_colored_polygon(points: PackedVector2Array, color: Color, uvs: PackedVector2Array = PackedVector2Array(), texture: Texture2D = null) -> void` — Draws a colored polygon of any number of points, convex or concave.
- `draw_dashed_line(from: Vector2, to: Vector2, color: Color, width: float = -1.0, dash: float = 2.0, aligned: bool = true, antialiased: bool = false) -> void` — Draws a dashed line from a 2D point to another, with a given color and width.
- `draw_ellipse(position: Vector2, major: float, minor: float, color: Color, filled: bool = true, width: float = -1.0, antialiased: bool = false) -> void` — Draws an ellipse with semi-major axis `major` and semi-minor axis `minor`.
- `draw_ellipse_arc(center: Vector2, major: float, minor: float, start_angle: float, end_angle: float, point_count: int, color: Color, width: float = -1.0, antialiased: bool = false) -> void` — Draws an unfilled elliptical arc between the given angles with a uniform `color` and `width` and optional antialiasing (supported only for positive `width`).
- `draw_end_animation() -> void` — After submitting all animations slices via `draw_animation_slice`, this function can be used to revert drawing to its default state (all subsequent drawing commands will be visible).
- `draw_lcd_texture_rect_region(texture: Texture2D, rect: Rect2, src_rect: Rect2, modulate: Color = Color(1, 1, 1, 1)) -> void` — Draws a textured rectangle region of the font texture with LCD subpixel anti-aliasing at a given position, optionally modulated by a color.
- `draw_line(from: Vector2, to: Vector2, color: Color, width: float = -1.0, antialiased: bool = false) -> void` — Draws a line from a 2D point to another, with a given color and width.
- `draw_mesh(mesh: Mesh, texture: Texture2D, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), modulate: Color = Color(1, 1, 1, 1)) -> void` — Draws a Mesh in 2D, using the provided texture.
- `draw_msdf_texture_rect_region(texture: Texture2D, rect: Rect2, src_rect: Rect2, modulate: Color = Color(1, 1, 1, 1), outline: float = 0.0, pixel_range: float = 4.0, scale: float = 1.0) -> void` — Draws a textured rectangle region of the multichannel signed distance field texture at a given position, optionally modulated by a color.
- `draw_multiline(points: PackedVector2Array, color: Color, width: float = -1.0, antialiased: bool = false) -> void` — Draws multiple disconnected lines with a uniform `width` and `color`.
- `draw_multiline_colors(points: PackedVector2Array, colors: PackedColorArray, width: float = -1.0, antialiased: bool = false) -> void` — Draws multiple disconnected lines with a uniform `width` and segment-by-segment coloring.
- `draw_multiline_string(font: Font, pos: Vector2, text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, max_lines: int = -1, modulate: Color = Color(1, 1, 1, 1), brk_flags: TextServer.LineBreakFlag = 3, justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0, oversampling: float = 0.0) -> void` *const* — Breaks `text` into lines and draws it using the specified `font` at the `pos` in local space (top-left corner).
- `draw_multiline_string_outline(font: Font, pos: Vector2, text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, max_lines: int = -1, size: int = 1, modulate: Color = Color(1, 1, 1, 1), brk_flags: TextServer.LineBreakFlag = 3, justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0, oversampling: float = 0.0) -> void` *const* — Breaks `text` to the lines and draws text outline using the specified `font` at the `pos` in local space (top-left corner).
- `draw_multimesh(multimesh: MultiMesh, texture: Texture2D) -> void` — Draws a MultiMesh in 2D with the provided texture.
- `draw_polygon(points: PackedVector2Array, colors: PackedColorArray, uvs: PackedVector2Array = PackedVector2Array(), texture: Texture2D = null) -> void` — Draws a solid polygon of any number of points, convex or concave.
- `draw_polyline(points: PackedVector2Array, color: Color, width: float = -1.0, antialiased: bool = false) -> void` — Draws interconnected line segments with a uniform `color` and `width` and optional antialiasing (supported only for positive `width`).
- `draw_polyline_colors(points: PackedVector2Array, colors: PackedColorArray, width: float = -1.0, antialiased: bool = false) -> void` — Draws interconnected line segments with a uniform `width`, point-by-point coloring, and optional antialiasing (supported only for positive `width`).
- `draw_primitive(points: PackedVector2Array, colors: PackedColorArray, uvs: PackedVector2Array, texture: Texture2D = null) -> void` — Draws a custom primitive. 1 point for a point, 2 points for a line, 3 points for a triangle, and 4 points for a quad.
- `draw_rect(rect: Rect2, color: Color, filled: bool = true, width: float = -1.0, antialiased: bool = false) -> void` — Draws a rectangle.
- `draw_set_transform(position: Vector2, rotation: float = 0.0, scale: Vector2 = Vector2(1, 1)) -> void` — Sets a custom local transform for drawing via components.
- `draw_set_transform_matrix(xform: Transform2D) -> void` — Sets a custom local transform for drawing via matrix.
- `draw_string(font: Font, pos: Vector2, text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, modulate: Color = Color(1, 1, 1, 1), justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0, oversampling: float = 0.0) -> void` *const* — Draws `text` using the specified `font` at the `pos` in local space (bottom-left corner using the baseline of the font).
- `draw_string_outline(font: Font, pos: Vector2, text: String, alignment: HorizontalAlignment = 0, width: float = -1, font_size: int = 16, size: int = 1, modulate: Color = Color(1, 1, 1, 1), justification_flags: TextServer.JustificationFlag = 3, direction: TextServer.Direction = 0, orientation: TextServer.Orientation = 0, oversampling: float = 0.0) -> void` *const* — Draws `text` outline using the specified `font` at the `pos` in local space (bottom-left corner using the baseline of the font).
- `draw_style_box(style_box: StyleBox, rect: Rect2) -> void` — Draws a styled rectangle.
- `draw_texture(texture: Texture2D, position: Vector2, modulate: Color = Color(1, 1, 1, 1)) -> void` — Draws a texture at a given position.
- `draw_texture_rect(texture: Texture2D, rect: Rect2, tile: bool, modulate: Color = Color(1, 1, 1, 1), transpose: bool = false) -> void` — Draws a textured rectangle at a given position, optionally modulated by a color.
- `draw_texture_rect_region(texture: Texture2D, rect: Rect2, src_rect: Rect2, modulate: Color = Color(1, 1, 1, 1), transpose: bool = false, clip_uv: bool = true) -> void` — Draws a textured rectangle from a texture's region (specified by `src_rect`) at a given position in local space, optionally modulated by a color.
- `force_update_transform() -> void` — Forces the node's transform to update.
- `get_canvas() -> RID` *const* — Returns the RID of the World2D canvas where this node is registered to, used by the RenderingServer.
- `get_canvas_item() -> RID` *const* — Returns the internal canvas item RID used by the RenderingServer for this node.
- `get_canvas_layer_node() -> CanvasLayer` *const* — Returns the CanvasLayer that contains this node, or `null` if the node is not in any CanvasLayer.
- `get_canvas_transform() -> Transform2D` *const* — Returns the transform of this node, converted from its registered canvas's coordinate system to its viewport's coordinate system.
- `get_global_mouse_position() -> Vector2` *const* — Returns mouse cursor's global position relative to the CanvasLayer that contains this node.
- `get_global_transform() -> Transform2D` *const* — Returns the global transform matrix of this item, i.e. the combined transform up to the topmost CanvasItem node.
- `get_global_transform_with_canvas() -> Transform2D` *const* — Returns the transform from the local coordinate system of this CanvasItem to the Viewport's coordinate system.
- `get_instance_shader_parameter(name: StringName) -> Variant` *const* — Get the value of a shader parameter as set on this instance.
- `get_local_mouse_position() -> Vector2` *const* — Returns the mouse's position in this CanvasItem using the local coordinate system of this CanvasItem.
- `get_screen_transform() -> Transform2D` *const* — Returns the transform of this CanvasItem in global screen coordinates (i.e. taking window position into account).
- `get_transform() -> Transform2D` *const* — Returns the transform matrix of this CanvasItem.
- `get_viewport_rect() -> Rect2` *const* — Returns this node's viewport boundaries as a Rect2.
- `get_viewport_transform() -> Transform2D` *const* — Returns the transform of this node, converted from its registered canvas's coordinate system to its viewport embedder's coordinate system.
- `get_visibility_layer_bit(layer: int) -> bool` *const* — Returns `true` if the layer at the given index is set in `visibility_layer`.
- `get_world_2d() -> World2D` *const* — Returns the World2D this node is registered to.
- `hide() -> void` — Hide the CanvasItem if it's currently visible.
- `is_local_transform_notification_enabled() -> bool` *const* — Returns `true` if the node receives `NOTIFICATION_LOCAL_TRANSFORM_CHANGED` whenever its local transform changes.
- `is_transform_notification_enabled() -> bool` *const* — Returns `true` if the node receives `NOTIFICATION_TRANSFORM_CHANGED` whenever its global transform changes.
- `is_visible_in_tree() -> bool` *const* — Returns `true` if the node is present in the SceneTree, its `visible` property is `true` and all its ancestors are also visible.
- `make_canvas_position_local(viewport_point: Vector2) -> Vector2` *const* — Transforms `viewport_point` from the viewport's coordinates to this node's local coordinates.
- `make_input_local(event: InputEvent) -> InputEvent` *const* — Returns a copy of the given `event` with its coordinates converted from global space to this CanvasItem's local space.
- `move_to_front() -> void` — Moves this node below its siblings, usually causing the node to draw on top of its siblings.
- `queue_redraw() -> void` — Queues the CanvasItem to redraw.
- `set_instance_shader_parameter(name: StringName, value: Variant) -> void` — Set the value of a shader uniform for this instance only (per-instance uniform).
- `set_notify_local_transform(enable: bool) -> void` — If `true`, the node will receive `NOTIFICATION_LOCAL_TRANSFORM_CHANGED` whenever its local transform changes.
- `set_notify_transform(enable: bool) -> void` — If `true`, the node will receive `NOTIFICATION_TRANSFORM_CHANGED` whenever its global transform changes.
- `set_visibility_layer_bit(layer: int, enabled: bool) -> void` — Set/clear individual bits on the rendering visibility layer (`layer` is between `0` and `31`).
- `show() -> void` — Show the CanvasItem if it's currently hidden.

## Signals

- `draw()` — Emitted when the CanvasItem must redraw, after the related `NOTIFICATION_DRAW` notification, and before `_draw` is called.
- `hidden()` — Emitted when this node becomes hidden, i.e. it's no longer visible in the tree (see `is_visible_in_tree`).
- `item_rect_changed()` — Emitted when the CanvasItem's boundaries (position or size) change, or when an action took place that may have affected these boundaries (e.g. changing `Sprite2D.texture`).
- `visibility_changed()` — Emitted when the CanvasItem's visibility changes, either because its own `visible` property changed or because its visibility in the tree changed (see `is_visible_in_tree`).

## Enum TextureFilter

- `TEXTURE_FILTER_PARENT_NODE = 0` — The CanvasItem will inherit the filter from its parent.
- `TEXTURE_FILTER_NEAREST = 1` — The texture filter reads from the nearest pixel only.
- `TEXTURE_FILTER_LINEAR = 2` — The texture filter blends between the nearest 4 pixels.
- `TEXTURE_FILTER_NEAREST_WITH_MIPMAPS = 3` — The texture filter reads from the nearest pixel and blends between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `TEXTURE_FILTER_LINEAR_WITH_MIPMAPS = 4` — The texture filter blends between the nearest 4 pixels and between the nearest 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`).
- `TEXTURE_FILTER_NEAREST_WITH_MIPMAPS_ANISOTROPIC = 5` — The texture filter reads from the nearest pixel and blends between 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`) based on the angle between the surface and the camera view.
- `TEXTURE_FILTER_LINEAR_WITH_MIPMAPS_ANISOTROPIC = 6` — The texture filter blends between the nearest 4 pixels and blends between 2 mipmaps (or uses the nearest mipmap if `ProjectSettings.rendering/textures/default_filters/use_nearest_mipmap_filter` is `true`) based on the angle between the surface and the camera view.
- `TEXTURE_FILTER_MAX = 7` — Represents the size of the `TextureFilter` enum.

## Enum TextureRepeat

- `TEXTURE_REPEAT_PARENT_NODE = 0` — The CanvasItem will inherit the repeat mode from its parent.
- `TEXTURE_REPEAT_DISABLED = 1` — The texture does not repeat.
- `TEXTURE_REPEAT_ENABLED = 2` — The texture repeats when exceeding the texture's size.
- `TEXTURE_REPEAT_MIRROR = 3` — The texture repeats when the exceeding the texture's size in a "2×2 tiled mode".
- `TEXTURE_REPEAT_MAX = 4` — Represents the size of the `TextureRepeat` enum.

## Enum ClipChildrenMode

- `CLIP_CHILDREN_DISABLED = 0` — Children are drawn over this node and are not clipped.
- `CLIP_CHILDREN_ONLY = 1` — This node is used as a mask and is not drawn.
- `CLIP_CHILDREN_AND_DRAW = 2` — This node is used as a mask and is also drawn.
- `CLIP_CHILDREN_MAX = 3` — Represents the size of the `ClipChildrenMode` enum.

## Enum OversamplingWithScale

- `OVERSAMPLING_WITH_SCALE_PARENT_NODE = 0` — The CanvasItem will inherit the oversampling mode from its parent.
- `OVERSAMPLING_WITH_SCALE_DISABLED = 1` — The oversampling is not affected by CanvasItem scale, and is equal to the Viewport oversampling.
- `OVERSAMPLING_WITH_SCALE_ENABLED = 2` — The oversampling is a product of CanvasItem scale and Viewport oversampling.
- `OVERSAMPLING_WITH_SCALE_MAX = 3` — Represents the size of the `OversamplingWithScale` enum.

## Constants

- `NOTIFICATION_TRANSFORM_CHANGED = 2000` — Notification received when this node's global transform changes, if `is_transform_notification_enabled` is `true`.
- `NOTIFICATION_LOCAL_TRANSFORM_CHANGED = 35` — Notification received when this node's transform changes, if `is_local_transform_notification_enabled` is `true`.
- `NOTIFICATION_DRAW = 30` — The CanvasItem is requested to draw (see `_draw`).
- `NOTIFICATION_VISIBILITY_CHANGED = 31` — Notification received when this node's visibility changes (see `visible` and `is_visible_in_tree`).
- `NOTIFICATION_ENTER_CANVAS = 32` — The CanvasItem has entered the canvas.
- `NOTIFICATION_EXIT_CANVAS = 33` — The CanvasItem has exited the canvas.
- `NOTIFICATION_WORLD_2D_CHANGED = 36` — Notification received when this CanvasItem is registered to a new World2D (see `get_world_2d`).
