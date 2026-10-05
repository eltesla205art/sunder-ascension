# LookAtModifier3D

**Inherits:** SkeletonModifier3D

The LookAtModifier3D rotates a bone to look at a target.

This SkeletonModifier3D rotates a bone to look at a target. This is helpful for moving a character's head to look at the player, rotating a turret to look at a target, or any other case where you want to make a bone rotate towards something quickly and easily. When applying multiple LookAtModifier3Ds, the LookAtModifier3D assigned to the parent bone must be put above the LookAtModifier3D assigned to the child bone in the list in order for the child bone results to be correct.

## Properties

- `bone: int` = `-1` — Index of the `bone_name` in the parent Skeleton3D.
- `bone_name: String` = `""` — The bone name of the Skeleton3D that the modification will operate on.
- `duration: float` = `0.0` — The duration of the time-based interpolation.
- `ease_type: Tween.EaseType` = `0` — The ease type of the time-based interpolation.
- `forward_axis: SkeletonModifier3D.BoneAxis` = `4` — The forward axis of the bone.
- `origin_bone: int` — Index of the `origin_bone_name` in the parent Skeleton3D.
- `origin_bone_name: String` — If `origin_from` is `ORIGIN_FROM_SPECIFIC_BONE`, the bone global pose position specified for this is used as origin.
- `origin_external_node: NodePath` — If `origin_from` is `ORIGIN_FROM_EXTERNAL_NODE`, the global position of the Node3D specified for this is used as origin.
- `origin_from: LookAtModifier3D.OriginFrom` = `0` — This value determines from what origin is retrieved for use in the calculation of the forward vector.
- `origin_offset: Vector3` = `Vector3(0, 0, 0)` — The offset of the bone pose origin.
- `origin_safe_margin: float` = `0.1` — If the target passes through too close to the origin than this value, time-based interpolation is used even if the target is within the angular limitations, to prevent the angular velocity from becoming too high.
- `primary_damp_threshold: float` — The threshold to start damping for `primary_limit_angle`.
- `primary_limit_angle: float` — The limit angle of the primary rotation when `symmetry_limitation` is `true`, in radians.
- `primary_negative_damp_threshold: float` — The threshold to start damping for `primary_negative_limit_angle`.
- `primary_negative_limit_angle: float` — The limit angle of negative side of the primary rotation when `symmetry_limitation` is `false`, in radians.
- `primary_positive_damp_threshold: float` — The threshold to start damping for `primary_positive_limit_angle`.
- `primary_positive_limit_angle: float` — The limit angle of positive side of the primary rotation when `symmetry_limitation` is `false`, in radians.
- `primary_rotation_axis: Vector3.Axis` = `1` — The axis of the first rotation.
- `relative: bool` = `false` — The relative option.
- `secondary_damp_threshold: float` — The threshold to start damping for `secondary_limit_angle`.
- `secondary_limit_angle: float` — The limit angle of the secondary rotation when `symmetry_limitation` is `true`, in radians.
- `secondary_negative_damp_threshold: float` — The threshold to start damping for `secondary_negative_limit_angle`.
- `secondary_negative_limit_angle: float` — The limit angle of negative side of the secondary rotation when `symmetry_limitation` is `false`, in radians.
- `secondary_positive_damp_threshold: float` — The threshold to start damping for `secondary_positive_limit_angle`.
- `secondary_positive_limit_angle: float` — The limit angle of positive side of the secondary rotation when `symmetry_limitation` is `false`, in radians.
- `symmetry_limitation: bool` — If `true`, the limitations are spread from the bone symmetrically.
- `target_node: NodePath` = `NodePath("")` — The NodePath to the node that is the target for the look at modification.
- `transition_type: Tween.TransitionType` = `0` — The transition type of the time-based interpolation.
- `use_angle_limitation: bool` = `false` — If `true`, limits the amount of rotation.
- `use_rest_for_limitation: bool` — If `true`, the angle limitation and the rotation axes are applied based on the `Skeleton3D.get_bone_rest`.
- `use_secondary_rotation: bool` = `true` — If `true`, provides rotation by two axes.

## Methods

- `get_interpolation_remaining() -> float` *const* — Returns the remaining seconds of the time-based interpolation.
- `is_interpolating() -> bool` *const* — Returns `true` if time-based interpolation is running.
- `is_target_within_limitation() -> bool` *const* — Returns whether the target is within the angle limitations.

## Enum OriginFrom

- `ORIGIN_FROM_SELF = 0` — The bone rest position of the bone specified in `bone` is used as origin.
- `ORIGIN_FROM_SPECIFIC_BONE = 1` — The bone global pose position of the bone specified in `origin_bone` is used as origin.
- `ORIGIN_FROM_EXTERNAL_NODE = 2` — The global position of the Node3D specified in `origin_external_node` is used as origin.
