# RibbonTrailMesh

**Inherits:** PrimitiveMesh

Represents a straight ribbon-shaped PrimitiveMesh with variable width.

RibbonTrailMesh represents a straight ribbon-shaped mesh with variable width. The ribbon is composed of a number of flat or cross-shaped sections, each with the same `section_length` and number of `section_segments`. A `curve` is sampled along the total length of the ribbon, meaning that the curve determines the size of the ribbon along its length. This primitive mesh is usually used for particle trails.

## Properties

- `curve: Curve` — Determines the size of the ribbon along its length.
- `section_length: float` = `0.2` — The length of a section of the ribbon.
- `section_segments: int` = `3` — The number of segments in a section.
- `sections: int` = `5` — The total number of sections on the ribbon.
- `shape: RibbonTrailMesh.Shape` = `1` — Determines the shape of the ribbon.
- `size: float` = `1.0` — The baseline size of the ribbon.

## Enum Shape

- `SHAPE_FLAT = 0` — Gives the mesh a single flat face.
- `SHAPE_CROSS = 1` — Gives the mesh two perpendicular flat faces, making a cross shape.
