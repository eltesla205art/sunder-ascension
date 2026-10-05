# TubeTrailMesh

**Inherits:** PrimitiveMesh

Represents a straight tube-shaped PrimitiveMesh with variable width.

TubeTrailMesh represents a straight tube-shaped mesh with variable width. The tube is composed of a number of cylindrical sections, each with the same `section_length` and number of `section_rings`. A `curve` is sampled along the total length of the tube, meaning that the curve determines the radius of the tube along its length. This primitive mesh is usually used for particle trails.

## Properties

- `cap_bottom: bool` = `true` — If `true`, generates a cap at the bottom of the tube.
- `cap_top: bool` = `true` — If `true`, generates a cap at the top of the tube.
- `curve: Curve` — Determines the radius of the tube along its length.
- `radial_steps: int` = `8` — The number of sides on the tube.
- `radius: float` = `0.5` — The baseline radius of the tube.
- `section_length: float` = `0.2` — The length of a section of the tube.
- `section_rings: int` = `3` — The number of rings in a section.
- `sections: int` = `5` — The total number of sections on the tube.
