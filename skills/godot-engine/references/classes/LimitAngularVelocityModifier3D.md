# LimitAngularVelocityModifier3D

**Inherits:** SkeletonModifier3D

Limit bone rotation angular velocity.

This modifier limits bone rotation angular velocity by comparing poses between previous and current frame. You can add bone chains by specifying their root and end bones, then add the bones between them to a list. Modifier processes either that list or the bones excluding those in the list depending on the option `exclude`. Note: Most methods in this class take an `index` parameter.

## Properties

- `chain_count: int` = `0` — The number of chains.
- `exclude: bool` = `false` — If `true`, the modifier processes bones not included in the bone list.
- `joint_count: int` = `0` — The number of joints in the list which created by chains dynamically.
- `max_angular_velocity: float` = `6.2831855` — The maximum angular velocity per second.

## Methods

- `clear_chains() -> void` — Clear all chains.
- `get_end_bone(index: int) -> int` *const* — Returns the end bone index of the bone chain.
- `get_end_bone_name(index: int) -> String` *const* — Returns the end bone name of the bone chain.
- `get_root_bone(index: int) -> int` *const* — Returns the root bone index of the bone chain.
- `get_root_bone_name(index: int) -> String` *const* — Returns the root bone name of the bone chain.
- `reset() -> void` — Sets the reference pose for angle comparison to the current pose with the influence of constraints removed.
- `set_end_bone(index: int, bone: int) -> void` — Sets the end bone index of the bone chain.
- `set_end_bone_name(index: int, bone_name: String) -> void` — Sets the end bone name of the bone chain.
- `set_root_bone(index: int, bone: int) -> void` — Sets the root bone index of the bone chain.
- `set_root_bone_name(index: int, bone_name: String) -> void` — Sets the root bone name of the bone chain.
