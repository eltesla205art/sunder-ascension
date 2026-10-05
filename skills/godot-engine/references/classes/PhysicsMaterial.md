# PhysicsMaterial

**Inherits:** Resource

Holds physics-related properties of a surface, namely its roughness and bounciness.

Holds physics-related properties of a surface, namely its roughness and bounciness. This class is used to apply these properties to a physics body.

## Properties

- `absorbent: bool` = `false` — If `true`, subtracts the bounciness from the colliding object's bounciness instead of adding it.
- `bounce: float` = `0.0` — The body's bounciness.
- `friction: float` = `1.0` — The body's friction.
- `rough: bool` = `false` — If `true`, the physics engine will use the friction of the object marked as "rough" when two objects collide.
