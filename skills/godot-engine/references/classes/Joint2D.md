# Joint2D

**Inherits:** Node2D

Abstract base class for all 2D physics joints.

Abstract base class for all joints in 2D physics. 2D joints bind together two physics bodies (`node_a` and `node_b`) and apply a constraint.

## Properties

- `bias: float` = `0.0` — When `node_a` and `node_b` move in different directions the `bias` controls how fast the joint pulls them back to their original position.
- `disable_collision: bool` = `true` — If `true`, the two bodies bound together do not collide with each other.
- `node_a: NodePath` = `NodePath("")` — Path to the first body (A) attached to the joint.
- `node_b: NodePath` = `NodePath("")` — Path to the second body (B) attached to the joint.

## Methods

- `get_rid() -> RID` *const* — Returns the joint's internal RID from the PhysicsServer2D.
