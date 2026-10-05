# CapsuleShape3D

**Inherits:** Shape3D

A 3D capsule shape used for physics collision.

A 3D capsule shape, intended for use in physics. Usually used to provide a shape for a CollisionShape3D. Performance: CapsuleShape3D is fast to check collisions against. It is faster than CylinderShape3D, but slower than SphereShape3D and BoxShape3D.

## Properties

- `height: float` = `2.0` — The capsule's full height, including the hemispheres.
- `mid_height: float` — The capsule's height, excluding the hemispheres.
- `radius: float` = `0.5` — The capsule's radius.
