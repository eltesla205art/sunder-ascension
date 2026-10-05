# CanvasLayer

**Inherits:** Node

A node used for independent rendering of objects within a 2D scene.

CanvasItem-derived nodes that are direct or indirect children of a CanvasLayer will be drawn in that layer. The layer is a numeric index that defines the draw order. The default 2D scene renders with index `0`, so a CanvasLayer with index `-1` will be drawn below, and a CanvasLayer with index `1` will be drawn above. This order will hold regardless of the `CanvasItem.z_index` of the nodes within each layer.

## Properties

- `custom_viewport: Node` — The custom Viewport node assigned to the CanvasLayer.
- `follow_viewport_enabled: bool` = `false` — If enabled, the CanvasLayer maintains its position in world space.
- `follow_viewport_scale: float` = `1.0` — Scales the layer when using `follow_viewport_enabled`.
- `layer: int` = `1` — Layer index for draw order.
- `offset: Vector2` = `Vector2(0, 0)` — The layer's base offset.
- `rotation: float` = `0.0` — The layer's rotation in radians.
- `scale: Vector2` = `Vector2(1, 1)` — The layer's scale.
- `transform: Transform2D` = `Transform2D(1, 0, 0, 1, 0, 0)` — The layer's transform.
- `visible: bool` = `true` — If `false`, any CanvasItem under this CanvasLayer will be hidden.

## Methods

- `get_canvas() -> RID` *const* — Returns the RID of the canvas used by this layer.
- `get_final_transform() -> Transform2D` *const* — Returns the transform from the CanvasLayer's coordinate system to the Viewport's coordinate system.
- `hide() -> void` — Hides any CanvasItem under this CanvasLayer.
- `show() -> void` — Shows any CanvasItem under this CanvasLayer.

## Signals

- `visibility_changed()` — Emitted when visibility of the layer is changed.
