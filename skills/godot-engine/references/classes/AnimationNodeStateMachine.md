# AnimationNodeStateMachine

**Inherits:** AnimationRootNode

A state machine with multiple AnimationRootNodes, used by AnimationTree.

Contains multiple AnimationRootNodes representing animation states, connected in a graph. State transitions can be configured to happen automatically or via code, using a shortest-path algorithm. Retrieve the AnimationNodeStateMachinePlayback object from the AnimationTree node to control it programmatically.

## Properties

- `allow_transition_to_self: bool` = `false` — If `true`, allows teleport to the self state with `AnimationNodeStateMachinePlayback.travel`.
- `reset_ends: bool` = `false` — If `true`, treat the cross-fade to the start and end nodes as a blend with the RESET animation.
- `state_machine_type: AnimationNodeStateMachine.StateMachineType` = `0` — This property can define the process of transitions for different use cases.

## Methods

- `add_node(name: StringName, node: AnimationNode, position: Vector2 = Vector2(0, 0)) -> void` — Adds a new animation node to the graph.
- `add_transition(from: StringName, to: StringName, transition: AnimationNodeStateMachineTransition) -> void` — Adds a transition between the given animation nodes.
- `get_graph_offset() -> Vector2` *const* — Returns the draw offset of the graph.
- `get_node(name: StringName) -> AnimationNode` *const* — Returns the animation node with the given name.
- `get_node_list() -> StringName[]` *const* — Returns a list containing the names of all animation nodes in this state machine.
- `get_node_name(node: AnimationNode) -> StringName` *const* — Returns the given animation node's name.
- `get_node_position(name: StringName) -> Vector2` *const* — Returns the given animation node's coordinates.
- `get_transition(idx: int) -> AnimationNodeStateMachineTransition` *const* — Returns the given transition.
- `get_transition_count() -> int` *const* — Returns the number of connections in the graph.
- `get_transition_from(idx: int) -> StringName` *const* — Returns the given transition's start node.
- `get_transition_to(idx: int) -> StringName` *const* — Returns the given transition's end node.
- `has_node(name: StringName) -> bool` *const* — Returns `true` if the graph contains the given animation node.
- `has_transition(from: StringName, to: StringName) -> bool` *const* — Returns `true` if there is a transition between the given animation nodes.
- `remove_node(name: StringName) -> void` — Deletes the given animation node from the graph.
- `remove_transition(from: StringName, to: StringName) -> void` — Deletes the transition between the two specified animation nodes.
- `remove_transition_by_index(idx: int) -> void` — Deletes the given transition by index.
- `rename_node(name: StringName, new_name: StringName) -> void` — Renames the given animation node.
- `replace_node(name: StringName, node: AnimationNode) -> void` — Replaces the given animation node with a new animation node.
- `set_graph_offset(offset: Vector2) -> void` — Sets the draw offset of the graph.
- `set_node_position(name: StringName, position: Vector2) -> void` — Sets the animation node's coordinates.

## Enum StateMachineType

- `STATE_MACHINE_TYPE_ROOT = 0` — Seeking to the beginning is treated as playing from the start state.
- `STATE_MACHINE_TYPE_NESTED = 1` — Seeking to the beginning is treated as seeking to the beginning of the animation in the current state.
- `STATE_MACHINE_TYPE_GROUPED = 2` — This is a grouped state machine that can be controlled from a parent state machine.
