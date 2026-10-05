# CSGBox3D

**Inherits:** CSGPrimitive3D

A CSG Box shape.

This node allows you to create a box for use with the CSG system. Note: CSG nodes are intended to be used for level prototyping. Creating CSG nodes has a significant CPU cost compared to creating a MeshInstance3D with a PrimitiveMesh. Moving a CSG node within another CSG node also has a significant CPU cost, so it should be avoided during gameplay.

## Properties

- `material: Material` — The material used to render the box.
- `size: Vector3` = `Vector3(1, 1, 1)` — The box's width, height and depth.
