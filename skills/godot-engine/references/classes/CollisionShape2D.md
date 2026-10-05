# CollisionShape2D

**Inherits:** Node2D

A node that provides a Shape2D to a CollisionObject2D parent.

A node that provides a Shape2D to a CollisionObject2D parent and allows it to be edited. This can give a detection shape to an Area2D or turn a PhysicsBody2D into a solid object.

## Properties

- `debug_color: Color` = `Color(0, 0, 0, 0)` — The collision shape color that is displayed in the editor, or in the running project if Debug > Visible Collision Shapes is checked at the top of the editor.
- `disabled: bool` = `false` — A disabled collision shape has no effect in the world.
- `one_way_collision: bool` = `false` — Sets whether this collision shape should only detect collision on one side (top or bottom).
- `one_way_collision_direction: Vector2` = `Vector2(0, 1)` — The direction used for one-way collision.
- `one_way_collision_margin: float` = `1.0` — The margin used for one-way collision (in pixels).
- `shape: Shape2D` — The actual shape owned by this collision shape.
