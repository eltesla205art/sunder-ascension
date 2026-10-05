# AnimationNodeExtension

**Inherits:** AnimationNode

Base class for extending AnimationRootNodes from GDScript, C#, or C++.

AnimationNodeExtension exposes the APIs of AnimationRootNode to allow users to extend it from GDScript, C#, or C++. This class is not meant to be used directly, but to be extended by other classes. It is used to create custom nodes for the AnimationTree system.

## Methods

- `_process_animation_node(playback_info: PackedFloat64Array, test_only: bool) -> PackedFloat32Array` *virtual required* — A version of the `AnimationNode._process` method that is meant to be overridden by custom nodes.
- `get_remaining_time(node_info: PackedFloat32Array, break_loop: bool) -> float` *static* — Returns the animation's remaining time for the given node info.
- `is_looping(node_info: PackedFloat32Array) -> bool` *static* — Returns `true` if the animation for the given `node_info` is looping.
