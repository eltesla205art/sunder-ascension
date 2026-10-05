# XROrigin3D

**Inherits:** Node3D

The origin point in AR/VR.

This is a special node within the AR/VR system that maps the physical location of the center of our tracking space to the virtual location within our game world. Multiple origin points can be added to the scene tree, but only one can used at a time. All the XRCamera3D, XRController3D, and XRAnchor3D nodes should be direct children of this node for spatial tracking to work correctly. It is the position of this node that you update when your character needs to move through your game world while we're not moving in the real world.

## Properties

- `current: bool` = `false` — If `true`, this origin node is currently being used by the XRServer.
- `world_scale: float` = `1.0` — The scale of the game world compared to the real world.
