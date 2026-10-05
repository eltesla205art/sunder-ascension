# SkeletonModification2DJiggle

**Inherits:** SkeletonModification2D

A modification that jiggles Bone2D nodes as they move towards a target.

This modification moves a series of bones, typically called a bone chain, towards a target. What makes this modification special is that it calculates the velocity and acceleration for each bone in the bone chain, and runs a very light physics-like calculation using the inputted values. This allows the bones to overshoot the target and "jiggle" around. It can be configured to act more like a spring, or sway around like cloth might.

## Properties

- `damping: float` = `0.75` — The default amount of damping applied to the Jiggle joints, if they are not overridden.
- `gravity: Vector2` = `Vector2(0, 6)` — The default amount of gravity applied to the Jiggle joints, if they are not overridden.
- `jiggle_data_chain_length: int` = `0` — The amount of Jiggle joints in the Jiggle modification.
- `mass: float` = `0.75` — The default amount of mass assigned to the Jiggle joints, if they are not overridden.
- `stiffness: float` = `3.0` — The default amount of stiffness assigned to the Jiggle joints, if they are not overridden.
- `target_nodepath: NodePath` = `NodePath("")` — The NodePath to the node that is the target for the Jiggle modification.
- `use_gravity: bool` = `false` — Whether the gravity vector, `gravity`, should be applied to the Jiggle joints, assuming they are not overriding the default settings.

## Methods

- `get_collision_mask() -> int` *const* — Returns the collision mask used by the Jiggle modifier when collisions are enabled.
- `get_jiggle_joint_bone2d_node(joint_idx: int) -> NodePath` *const* — Returns the Bone2D node assigned to the Jiggle joint at `joint_idx`.
- `get_jiggle_joint_bone_index(joint_idx: int) -> int` *const* — Returns the index of the Bone2D node assigned to the Jiggle joint at `joint_idx`.
- `get_jiggle_joint_damping(joint_idx: int) -> float` *const* — Returns the amount of damping of the Jiggle joint at `joint_idx`.
- `get_jiggle_joint_gravity(joint_idx: int) -> Vector2` *const* — Returns a Vector2 representing the amount of gravity the Jiggle joint at `joint_idx` is influenced by.
- `get_jiggle_joint_mass(joint_idx: int) -> float` *const* — Returns the amount of mass of the jiggle joint at `joint_idx`.
- `get_jiggle_joint_override(joint_idx: int) -> bool` *const* — Returns a boolean that indicates whether the joint at `joint_idx` is overriding the default Jiggle joint data defined in the modification.
- `get_jiggle_joint_stiffness(joint_idx: int) -> float` *const* — Returns the stiffness of the Jiggle joint at `joint_idx`.
- `get_jiggle_joint_use_gravity(joint_idx: int) -> bool` *const* — Returns a boolean that indicates whether the joint at `joint_idx` is using gravity or not.
- `get_use_colliders() -> bool` *const* — Returns whether the jiggle modifier is taking physics colliders into account when solving.
- `reset() -> void` — Resets the internal jiggle simulation state to the current bone positions, clearing velocity, acceleration, and accumulated forces.
- `set_collision_mask(collision_mask: int) -> void` — Sets the collision mask that the Jiggle modifier will use when reacting to colliders, if the Jiggle modifier is set to take colliders into account.
- `set_jiggle_joint_bone2d_node(joint_idx: int, bone2d_node: NodePath) -> void` — Sets the Bone2D node assigned to the Jiggle joint at `joint_idx`.
- `set_jiggle_joint_bone_index(joint_idx: int, bone_idx: int) -> void` — Sets the bone index, `bone_idx`, of the Jiggle joint at `joint_idx`.
- `set_jiggle_joint_damping(joint_idx: int, damping: float) -> void` — Sets the amount of damping of the Jiggle joint at `joint_idx`.
- `set_jiggle_joint_gravity(joint_idx: int, gravity: Vector2) -> void` — Sets the gravity vector of the Jiggle joint at `joint_idx`.
- `set_jiggle_joint_mass(joint_idx: int, mass: float) -> void` — Sets the of mass of the Jiggle joint at `joint_idx`.
- `set_jiggle_joint_override(joint_idx: int, override: bool) -> void` — Sets whether the Jiggle joint at `joint_idx` should override the default Jiggle joint settings.
- `set_jiggle_joint_stiffness(joint_idx: int, stiffness: float) -> void` — Sets the of stiffness of the Jiggle joint at `joint_idx`.
- `set_jiggle_joint_use_gravity(joint_idx: int, use_gravity: bool) -> void` — Sets whether the Jiggle joint at `joint_idx` should use gravity.
- `set_use_colliders(use_colliders: bool) -> void` — If `true`, the Jiggle modifier will take colliders into account, keeping them from entering into these collision objects.
