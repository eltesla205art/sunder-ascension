# CSGSphere3D

**Inherits:** CSGPrimitive3D

A CSG Sphere shape.

This node allows you to create a sphere for use with the CSG system. Note: CSG nodes are intended to be used for level prototyping. Creating CSG nodes has a significant CPU cost compared to creating a MeshInstance3D with a PrimitiveMesh. Moving a CSG node within another CSG node also has a significant CPU cost, so it should be avoided during gameplay.

## Properties

- `material: Material` — The material used to render the sphere.
- `radial_segments: int` = `12` — Number of vertical slices for the sphere.
- `radius: float` = `0.5` — Radius of the sphere.
- `rings: int` = `6` — Number of horizontal slices for the sphere.
- `smooth_faces: bool` = `true` — If `true` the normals of the sphere are set to give a smooth effect making the sphere seem rounded.
