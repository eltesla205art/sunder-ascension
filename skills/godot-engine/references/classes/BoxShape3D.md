# BoxShape3D

**Inherits:** Shape3D

A 3D box shape used for physics collision.

A 3D box shape, intended for use in physics. Usually used to provide a shape for a CollisionShape3D. Performance: BoxShape3D is fast to check collisions against. It is faster than CapsuleShape3D and CylinderShape3D, but slower than SphereShape3D.

## Properties

- `size: Vector3` = `Vector3(1, 1, 1)` — The box's width, height and depth.
