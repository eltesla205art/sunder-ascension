# CylinderMesh

**Inherits:** PrimitiveMesh

Class representing a cylindrical PrimitiveMesh.

Class representing a cylindrical PrimitiveMesh. This class can be used to create cones by setting either the `top_radius` or `bottom_radius` properties to `0.0`.

## Properties

- `bottom_radius: float` = `0.5` — Bottom radius of the cylinder.
- `cap_bottom: bool` = `true` — If `true`, generates a cap at the bottom of the cylinder.
- `cap_top: bool` = `true` — If `true`, generates a cap at the top of the cylinder.
- `height: float` = `2.0` — Full height of the cylinder.
- `radial_segments: int` = `64` — Number of radial segments on the cylinder.
- `rings: int` = `4` — Number of edge rings along the height of the cylinder.
- `top_radius: float` = `0.5` — Top radius of the cylinder.
