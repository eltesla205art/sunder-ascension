# PhysicsTestMotionParameters2D

**Inherits:** RefCounted

Provides parameters for `PhysicsServer2D.body_test_motion`.

By changing various properties of this object, such as the motion, you can configure the parameters for `PhysicsServer2D.body_test_motion`.

## Properties

- `collide_separation_ray: bool` = `false` — If set to `true`, shapes of type `PhysicsServer2D.SHAPE_SEPARATION_RAY` are used to detect collisions and can stop the motion.
- `exclude_bodies: RID[]` = `[]` — Optional array of body RID to exclude from collision.
- `exclude_objects: int[]` = `[]` — Optional array of object unique instance ID to exclude from collision.
- `from: Transform2D` = `Transform2D(1, 0, 0, 1, 0, 0)` — Transform in global space where the motion should start.
- `margin: float` = `0.08` — Increases the size of the shapes involved in the collision detection.
- `motion: Vector2` = `Vector2(0, 0)` — Motion vector to define the length and direction of the motion to test.
- `recovery_as_collision: bool` = `false` — If set to `true`, any depenetration from the recovery phase is reported as a collision; this is used e.g. by CharacterBody2D for improving floor detection during floor snapping.
