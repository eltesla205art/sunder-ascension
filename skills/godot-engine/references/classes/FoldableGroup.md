# FoldableGroup

**Inherits:** Resource

A group of foldable containers that doesn't allow more than one container to be expanded at a time.

A group of FoldableContainer-derived nodes. Only one container can be expanded at a time.

## Properties

- `allow_folding_all: bool` = `false` — If `true`, it is possible to fold all containers in this FoldableGroup.
- `resource_local_to_scene: bool` = `true` — 

## Methods

- `get_containers() -> FoldableContainer[]` *const* — Returns an Array of FoldableContainers that have this as their FoldableGroup (see `FoldableContainer.foldable_group`).
- `get_expanded_container() -> FoldableContainer` *const* — Returns the current expanded container.

## Signals

- `expanded(container: FoldableContainer)` — Emitted when one of the containers of the group is expanded.
