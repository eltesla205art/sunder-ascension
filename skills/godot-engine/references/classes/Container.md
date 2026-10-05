# Container

**Inherits:** Control

Base class for all GUI containers.

Base class for all GUI containers. A Container automatically arranges its child controls in a certain way. This class can be inherited to make custom container types.

## Properties

- `accessibility_region: bool` = `false` — If `true`, this container is marked as a region for accessibility.
- `mouse_filter: Control.MouseFilter` = `1` — 
- `propagate_maximum_size: bool` = `true` — 

## Methods

- `_get_allowed_size_flags_horizontal() -> PackedInt32Array` *virtual const* — Implement to return a list of allowed horizontal `Control.SizeFlags` for child nodes.
- `_get_allowed_size_flags_vertical() -> PackedInt32Array` *virtual const* — Implement to return a list of allowed vertical `Control.SizeFlags` for child nodes.
- `fit_child_in_rect(child: Control, rect: Rect2) -> void` — Fit a child control in a given rect.
- `queue_sort() -> void` — Queue resort of the contained children.

## Signals

- `pre_sort_children()` — Emitted when children are going to be sorted.
- `sort_children()` — Emitted when sorting the children is needed.

## Constants

- `NOTIFICATION_PRE_SORT_CHILDREN = 50` — Notification just before children are going to be sorted, in case there's something to process beforehand.
- `NOTIFICATION_SORT_CHILDREN = 51` — Notification for when sorting the children, it must be obeyed immediately.
