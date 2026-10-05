# CollisionPolygon3D

**Inherits:** Node3D

A node that provides a thickened polygon shape (a prism) to a CollisionObject3D parent.

A node that provides a thickened polygon shape (a prism) to a CollisionObject3D parent and allows it to be edited. The polygon can be concave or convex. This can give a detection shape to an Area3D or turn a PhysicsBody3D into a solid object. Warning: A non-uniformly scaled CollisionShape3D will likely not behave as expected.

## Properties

- `debug_color: Color` = `Color(0, 0, 0, 0)` — The collision shape color that is displayed in the editor, or in the running project if Debug > Visible Collision Shapes is checked at the top of the editor.
- `debug_fill: bool` = `true` — If `true`, when the shape is displayed, it will show a solid fill color in addition to its wireframe.
- `depth: float` = `1.0` — Length that the resulting collision extends in either direction perpendicular to its 2D polygon.
- `disabled: bool` = `false` — If `true`, no collision will be produced.
- `margin: float` = `0.04` — The collision margin for the generated Shape3D.
- `polygon: PackedVector2Array` = `PackedVector2Array()` — Array of vertices which define the 2D polygon in the local XY plane.
