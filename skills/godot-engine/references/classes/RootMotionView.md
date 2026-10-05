# RootMotionView

**Inherits:** VisualInstance3D

Editor-only helper for setting up root motion in AnimationMixer.

Root motion refers to an animation technique where a mesh's skeleton is used to give impulse to a character. When working with 3D animations, a popular technique is for animators to use the root skeleton bone to give motion to the rest of the skeleton. This allows animating characters in a way where steps actually match the floor below. It also allows precise interaction with objects during cinematics.

## Properties

- `animation_path: NodePath` = `NodePath("")` — Path to an AnimationMixer node to use as a basis for root motion.
- `cell_size: float` = `1.0` — The grid's cell size in 3D units.
- `color: Color` = `Color(0.5, 0.5, 1, 1)` — The grid's color.
- `radius: float` = `10.0` — The grid's radius in 3D units.
- `zero_y: bool` = `true` — If `true`, the grid's points will all be on the same Y coordinate (local Y = 0).
