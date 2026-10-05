# AnimationNode

**Inherits:** Resource

Base class for AnimationTree nodes. Not related to scene nodes.

Base resource for AnimationTree nodes. In general, it's not used directly, but you can create custom ones with custom blending formulas. Inherit this when creating animation nodes mainly for use in AnimationNodeBlendTree, otherwise AnimationRootNode should be used instead. You can access the time information as read-only parameter which is processed and stored in the previous frame for all nodes except AnimationNodeOutput.

## Properties

- `filter_enabled: bool` — If `true`, filtering is enabled.

## Methods

- `_get_caption() -> String` *virtual const* — When inheriting from AnimationRootNode, implement this virtual method to override the text caption for this animation node.
- `_get_child_by_name(name: StringName) -> AnimationNode` *virtual const* — When inheriting from AnimationRootNode, implement this virtual method to return a child animation node by its `name`.
- `_get_child_nodes() -> Dictionary` *virtual const* — When inheriting from AnimationRootNode, implement this virtual method to return all child animation nodes in order as a `name: node` dictionary.
- `_get_parameter_default_value(parameter: StringName) -> Variant` *virtual const* — When inheriting from AnimationRootNode, implement this virtual method to return the default value of a `parameter`.
- `_get_parameter_list() -> Array` *virtual const* — When inheriting from AnimationRootNode, implement this virtual method to return a list of the properties on this animation node.
- `_has_filter() -> bool` *virtual const* — When inheriting from AnimationRootNode, implement this virtual method to return whether the blend tree editor should display filter editing on this animation node.
- `_is_parameter_read_only(parameter: StringName) -> bool` *virtual const* — When inheriting from AnimationRootNode, implement this virtual method to return whether the `parameter` is read-only.
- `_process(time: float, seek: bool, is_external_seeking: bool, test_only: bool) -> float` *virtual* *(deprecated)* — When inheriting from AnimationRootNode, implement this virtual method to run some code when this animation node is processed.
- `add_input(name: String) -> bool` — Adds an input to the animation node.
- `blend_animation(animation: StringName, time: float, delta: float, seeked: bool, is_external_seeking: bool, blend: float, looped_flag: Animation.LoopedFlag = 0) -> void` — Blends an animation by `blend` amount (name must be valid in the linked AnimationPlayer).
- `blend_input(input_index: int, time: float, seek: bool, is_external_seeking: bool, blend: float, filter: AnimationNode.FilterAction = 0, sync: bool = true, test_only: bool = false) -> float` — Blends an input.
- `blend_node(name: StringName, node: AnimationNode, time: float, seek: bool, is_external_seeking: bool, blend: float, filter: AnimationNode.FilterAction = 0, sync: bool = true, test_only: bool = false) -> float` — Blend another animation node (in case this animation node contains child animation nodes).
- `find_input(name: String) -> int` *const* — Returns the input index which corresponds to `name`.
- `get_input_count() -> int` *const* — Amount of inputs in this animation node, only useful for animation nodes that go into AnimationNodeBlendTree.
- `get_input_name(input: int) -> String` *const* — Gets the name of an input by index.
- `get_parameter(name: StringName) -> Variant` *const* — Gets the value of a parameter.
- `get_processing_animation_tree_instance_id() -> int` *const* — Returns the object id of the AnimationTree that owns this node.
- `is_path_filtered(path: NodePath) -> bool` *const* — Returns `true` if the given path is filtered.
- `is_process_testing() -> bool` *const* — Returns `true` if this animation node is being processed in test-only mode.
- `remove_input(index: int) -> void` — Removes an input, call this only when inactive.
- `set_filter_path(path: NodePath, enable: bool) -> void` — Adds or removes a path for the filter.
- `set_input_name(input: int, name: String) -> bool` — Sets the name of the input at the given `input` index.
- `set_parameter(name: StringName, value: Variant) -> void` — Sets a custom parameter.

## Signals

- `animation_node_removed(object_id: int, node_name: String)` — Emitted by nodes that inherit from this class and that have an internal tree when one of their animation nodes removes.
- `animation_node_renamed(object_id: int, old_name: String, new_name: String)` — Emitted by nodes that inherit from this class and that have an internal tree when one of their animation node names changes.
- `node_updated(object_id: int)` — Emitted by AnimationNodeAnimation when its `AnimationNodeAnimation.animation` resource is changed, or by AnimationNodeBlendTree when its connections change.
- `tree_changed()` — Emitted by nodes that inherit from this class and that have an internal tree when one of their animation nodes changes.

## Enum FilterAction

- `FILTER_IGNORE = 0` — Do not use filtering.
- `FILTER_PASS = 1` — Paths matching the filter will be allowed to pass.
- `FILTER_STOP = 2` — Paths matching the filter will be discarded.
- `FILTER_BLEND = 3` — Paths matching the filter will be blended (by the blend value).
