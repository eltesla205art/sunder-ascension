# WorldBoundaryShape3D

**Inherits:** Shape3D

A 3D world boundary (half-space) shape used for physics collision.

A 3D world boundary shape, intended for use in physics. WorldBoundaryShape3D works like an infinite plane that forces all physics bodies to stay above it. The `plane`'s normal determines which direction is considered as "above" and in the editor, the line over the plane represents this direction. It can for example be used for endless flat floors.

## Properties

- `plane: Plane` = `Plane(0, 1, 0, 0)` — The Plane used by the WorldBoundaryShape3D for collision.
