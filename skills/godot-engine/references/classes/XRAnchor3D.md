# XRAnchor3D

**Inherits:** XRNode3D

An anchor point in AR space.

The XRAnchor3D point is an XRNode3D that maps a real world location identified by the AR platform to a position within the game world. For example, as long as plane detection in ARKit is on, ARKit will identify and update the position of planes (tables, floors, etc.) and create anchors for them. This node is mapped to one of the anchors through its unique ID. When you receive a signal that a new anchor is available, you should add this node to your scene for that anchor.

## Methods

- `get_plane() -> Plane` *const* — Returns a plane aligned with our anchor; handy for intersection testing.
- `get_size() -> Vector3` *const* — Returns the estimated size of the plane that was detected.
