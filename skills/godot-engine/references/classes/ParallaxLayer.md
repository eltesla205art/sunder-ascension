# ParallaxLayer

**Inherits:** Node2D
**Deprecated:** Use the Parallax2D node instead.

A parallax scrolling layer to be used with ParallaxBackground.

A ParallaxLayer must be the child of a ParallaxBackground node. Each ParallaxLayer can be set to move at different speeds relative to the camera movement or the `ParallaxBackground.scroll_offset` value. This node's children will be affected by its scroll offset. Note: Any changes to this node's position and scale made after it enters the scene will be ignored.

## Properties

- `motion_mirroring: Vector2` = `Vector2(0, 0)` — The interval, in pixels, at which the ParallaxLayer is drawn repeatedly.
- `motion_offset: Vector2` = `Vector2(0, 0)` — The ParallaxLayer's offset relative to the parent ParallaxBackground's `ParallaxBackground.scroll_offset`.
- `motion_scale: Vector2` = `Vector2(1, 1)` — Multiplies the ParallaxLayer's motion.
- `physics_interpolation_mode: Node.PhysicsInterpolationMode` = `2` —
