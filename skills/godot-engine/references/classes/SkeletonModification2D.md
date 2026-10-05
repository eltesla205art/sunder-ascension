# SkeletonModification2D

**Inherits:** Resource

Base class for resources that operate on Bone2Ds in a Skeleton2D.

This resource provides an interface that can be expanded so code that operates on Bone2D nodes in a Skeleton2D can be mixed and matched together to create complex interactions. This is used to provide Godot with a flexible and powerful Inverse Kinematics solution that can be adapted for many different uses.

## Properties

- `enabled: bool` = `true` — If `true`, the modification's `_execute` function will be called by the SkeletonModificationStack2D.
- `execution_mode: int` = `0` — The execution mode for the modification.

## Methods

- `_draw_editor_gizmo() -> void` *virtual* — Used for drawing editor-only modification gizmos.
- `_execute(delta: float) -> void` *virtual* — Executes the given modification.
- `_setup_modification(modification_stack: SkeletonModificationStack2D) -> void` *virtual* — Called when the modification is setup.
- `clamp_angle(angle: float, min: float, max: float, invert: bool) -> float` — Takes an angle and clamps it so it is within the passed-in `min` and `max` range.
- `get_editor_draw_gizmo() -> bool` *const* — Returns whether this modification will call `_draw_editor_gizmo` in the Godot editor to draw modification-specific gizmos.
- `get_is_setup() -> bool` *const* — Returns whether this modification has been successfully setup or not.
- `get_modification_stack() -> SkeletonModificationStack2D` — Returns the SkeletonModificationStack2D that this modification is bound to.
- `set_editor_draw_gizmo(draw_gizmo: bool) -> void` — Sets whether this modification will call `_draw_editor_gizmo` in the Godot editor to draw modification-specific gizmos.
- `set_is_setup(is_setup: bool) -> void` — Manually allows you to set the setup state of the modification.
