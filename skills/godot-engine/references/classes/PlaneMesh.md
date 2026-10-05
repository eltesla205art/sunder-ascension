# PlaneMesh

**Inherits:** PrimitiveMesh

Class representing a planar PrimitiveMesh.

Class representing a planar PrimitiveMesh. This flat mesh does not have a thickness. By default, this mesh is aligned on the X and Z axes; this default rotation isn't suited for use with billboarded materials. For billboarded materials, change `orientation` to `FACE_Z`.

## Properties

- `center_offset: Vector3` = `Vector3(0, 0, 0)` — Offset of the generated plane.
- `orientation: PlaneMesh.Orientation` = `1` — Direction that the PlaneMesh is facing.
- `size: Vector2` = `Vector2(2, 2)` — Size of the generated plane.
- `subdivide_depth: int` = `0` — Number of subdivision along the Z axis.
- `subdivide_width: int` = `0` — Number of subdivision along the X axis.

## Enum Orientation

- `FACE_X = 0` — PlaneMesh will face the positive X-axis.
- `FACE_Y = 1` — PlaneMesh will face the positive Y-axis.
- `FACE_Z = 2` — PlaneMesh will face the positive Z-axis.
