# CSGTorus3D

**Inherits:** CSGPrimitive3D

A CSG Torus shape.

This node allows you to create a torus for use with the CSG system. Note: CSG nodes are intended to be used for level prototyping. Creating CSG nodes has a significant CPU cost compared to creating a MeshInstance3D with a PrimitiveMesh. Moving a CSG node within another CSG node also has a significant CPU cost, so it should be avoided during gameplay.

## Properties

- `inner_radius: float` = `0.5` — The inner radius of the torus.
- `material: Material` — The material used to render the torus.
- `outer_radius: float` = `1.0` — The outer radius of the torus.
- `ring_sides: int` = `6` — The number of edges each ring of the torus is constructed of.
- `sides: int` = `8` — The number of slices the torus is constructed of.
- `smooth_faces: bool` = `true` — If `true` the normals of the torus are set to give a smooth effect making the torus seem rounded.
