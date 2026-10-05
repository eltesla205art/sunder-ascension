# AnimationNodeSub2

**Inherits:** AnimationNodeSync

Blends two animations subtractively inside of an AnimationNodeBlendTree.

A resource to add to an AnimationNodeBlendTree. Blends two animations subtractively based on the amount value. This animation node is usually used for pre-calculation to cancel out any extra poses from the animation for the "add" animation source in AnimationNodeAdd2 or AnimationNodeAdd3. In general, the blend value should be in the `[0.0, 1.0]` range, but values outside of this range can be used for amplified or inverted animations.
