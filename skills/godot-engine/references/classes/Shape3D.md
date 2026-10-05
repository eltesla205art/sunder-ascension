# Shape3D

**Inherits:** Resource

Abstract base class for 3D shapes used for physics collision.

Abstract base class for all 3D shapes, intended for use in physics. Performance: Primitive shapes, especially SphereShape3D, are fast to check collisions against. ConvexPolygonShape3D and HeightMapShape3D are slower, and ConcavePolygonShape3D is the slowest.

## Properties

- `custom_solver_bias: float` = `0.0` — The shape's custom solver bias.
- `margin: float` = `0.04` — The collision margin for the shape.

## Methods

- `get_debug_mesh() -> ArrayMesh` — Returns the ArrayMesh used to draw the debug collision for this Shape3D.
