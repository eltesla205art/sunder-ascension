# SkeletonModificationStack2D

**Inherits:** Resource

A resource that holds a stack of SkeletonModification2Ds.

This resource is used by the Skeleton and holds a stack of SkeletonModification2Ds. This controls the order of the modifications and how they are applied. Modification order is especially important for full-body IK setups, as you need to execute the modifications in the correct order to get the desired results. For example, you want to execute a modification on the spine before the arms on a humanoid skeleton.

## Properties

- `enabled: bool` = `false` — If `true`, the modifications in the stack will be called.
- `modification_count: int` = `0` — The number of modifications in the stack.
- `strength: float` = `1.0` — The interpolation strength of the modifications in stack.

## Methods

- `add_modification(modification: SkeletonModification2D) -> void` — Adds the passed-in SkeletonModification2D to the stack.
- `delete_modification(mod_idx: int) -> void` — Deletes the SkeletonModification2D at the index position `mod_idx`, if it exists.
- `enable_all_modifications(enabled: bool) -> void` — Enables all SkeletonModification2Ds in the stack.
- `execute(delta: float, execution_mode: int) -> void` — Executes all of the SkeletonModification2Ds in the stack that use the same execution mode as the passed-in `execution_mode`, starting from index `0` to `modification_count`.
- `get_is_setup() -> bool` *const* — Returns a boolean that indicates whether the modification stack is setup and can execute.
- `get_modification(mod_idx: int) -> SkeletonModification2D` *const* — Returns the SkeletonModification2D at the passed-in index, `mod_idx`.
- `get_skeleton() -> Skeleton2D` *const* — Returns the Skeleton2D node that the SkeletonModificationStack2D is bound to.
- `set_modification(mod_idx: int, modification: SkeletonModification2D) -> void` — Sets the modification at `mod_idx` to the passed-in modification, `modification`.
- `setup() -> void` — Sets up the modification stack so it can execute.
