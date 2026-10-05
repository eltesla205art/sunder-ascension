# CapsuleShape2D

**Inherits:** Shape2D

A 2D capsule shape used for physics collision.

A 2D capsule shape, intended for use in physics. Usually used to provide a shape for a CollisionShape2D. Performance: CapsuleShape2D is fast to check collisions against, but it is slower than RectangleShape2D and CircleShape2D.

## Properties

- `height: float` = `30.0` — The capsule's full height, including the semicircles.
- `mid_height: float` — The capsule's height, excluding the semicircles.
- `radius: float` = `10.0` — The capsule's radius.
