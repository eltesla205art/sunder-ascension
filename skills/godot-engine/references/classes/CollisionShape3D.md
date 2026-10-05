# CollisionShape3D

**Inherits:** Node3D

A node that provides a Shape3D to a CollisionObject3D parent.

A node that provides a Shape3D to a CollisionObject3D parent and allows it to be edited. This can give a detection shape to an Area3D or turn a PhysicsBody3D into a solid object. Warning: A non-uniformly scaled CollisionShape3D will likely not behave as expected. Make sure to keep its scale the same on all axes and adjust its `shape` resource instead.

## Properties

- `debug_color: Color` = `Color(0, 0, 0, 0)` — The collision shape color that is displayed in the editor, or in the running project if Debug > Visible Collision Shapes is checked at the top of the editor.
- `debug_fill: bool` = `true` — If `true`, when the shape is displayed, it will show a solid fill color in addition to its wireframe.
- `disabled: bool` = `false` — A disabled collision shape has no effect in the world.
- `shape: Shape3D` — The actual shape owned by this collision shape.

## Methods

- `make_convex_from_siblings() -> void` — Sets the collision shape's shape to the addition of all its convexed MeshInstance3D siblings geometry.
- `resource_changed(resource: Resource) -> void` *(deprecated)* — This method does nothing.
