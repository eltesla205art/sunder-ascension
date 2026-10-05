# Joint3D

**Inherits:** Node3D

Abstract base class for all 3D physics joints.

Abstract base class for all joints in 3D physics. 3D joints bind together two physics bodies (`node_a` and `node_b`) and apply a constraint. If only one body is defined, it is attached to a fixed StaticBody3D without collision shapes.

## Properties

- `exclude_nodes_from_collision: bool` = `true` — If `true`, the two bodies bound together do not collide with each other.
- `node_a: NodePath` = `NodePath("")` — Path to the first node (A) attached to the joint.
- `node_b: NodePath` = `NodePath("")` — Path to the second node (B) attached to the joint.
- `solver_priority: int` = `1` — The priority specifies how accurately a joint is solved.

## Methods

- `get_rid() -> RID` *const* — Returns the joint's internal RID from the PhysicsServer3D.
