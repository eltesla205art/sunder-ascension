# Shape2D

**Inherits:** Resource

Abstract base class for 2D shapes used for physics collision.

Abstract base class for all 2D shapes, intended for use in physics. Performance: Primitive shapes, especially CircleShape2D, are fast to check collisions against. ConvexPolygonShape2D is slower, and ConcavePolygonShape2D is the slowest.

## Properties

- `custom_solver_bias: float` = `0.0` — The shape's custom solver bias.

## Methods

- `collide(local_xform: Transform2D, with_shape: Shape2D, shape_xform: Transform2D) -> bool` — Returns `true` if this shape is colliding with another.
- `collide_and_get_contacts(local_xform: Transform2D, with_shape: Shape2D, shape_xform: Transform2D) -> PackedVector2Array` — Returns a list of contact point pairs where this shape touches another.
- `collide_with_motion(local_xform: Transform2D, local_motion: Vector2, with_shape: Shape2D, shape_xform: Transform2D, shape_motion: Vector2) -> bool` — Returns whether this shape would collide with another, if a given movement was applied.
- `collide_with_motion_and_get_contacts(local_xform: Transform2D, local_motion: Vector2, with_shape: Shape2D, shape_xform: Transform2D, shape_motion: Vector2) -> PackedVector2Array` — Returns a list of contact point pairs where this shape would touch another, if a given movement was applied.
- `draw(canvas_item: RID, color: Color) -> void` — Draws a solid shape onto a CanvasItem with the RenderingServer API filled with the specified `color`.
- `get_rect() -> Rect2` *const* — Returns a Rect2 representing the shapes boundary.
