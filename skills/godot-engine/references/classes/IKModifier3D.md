# IKModifier3D

**Inherits:** SkeletonModifier3D

A node for inverse kinematics which may modify more than one bone.

Base class of SkeletonModifier3Ds that has some joint lists and applies inverse kinematics. This class has some structs, enums, and helper methods which are useful to solve inverse kinematics.

## Properties

- `mutable_bone_axes: bool` = `true` — If `true`, the solver retrieves the bone axis from the bone pose every frame.

## Methods

- `clear_settings() -> void` — Clears all settings.
- `get_setting_count() -> int` *const* — Returns the number of settings.
- `reset() -> void` — Resets a state with respect to the current bone pose.
- `set_setting_count(count: int) -> void` — Sets the number of settings.
