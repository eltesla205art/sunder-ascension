# CSGPrimitive3D

**Inherits:** CSGShape3D

Base class for CSG primitives.

Parent class for various CSG primitives. It contains code and functionality that is common between them. It cannot be used directly. Instead use one of the various classes that inherit from it.

## Properties

- `flip_faces: bool` = `false` — If set, the order of the vertices in each triangle are reversed resulting in the backside of the mesh being drawn.
