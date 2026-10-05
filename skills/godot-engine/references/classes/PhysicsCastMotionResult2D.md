# PhysicsCastMotionResult2D

**Inherits:** RefCounted

Stores the result of a shape motion cast query.

This class contains the safe and unsafe fractions computed by `PhysicsDirectSpaceState2D.cast_motion_into`.

## Properties

- `safe_fraction: float` = `1.0` — The maximum fraction of the motion that can be made without a collision.
- `unsafe_fraction: float` = `1.0` — The minimum fraction of the distance that must be moved for a collision.
