# CSGCylinder3D

**Inherits:** CSGPrimitive3D

A CSG Cylinder shape.

This node allows you to create a cylinder (or cone) for use with the CSG system. Note: CSG nodes are intended to be used for level prototyping. Creating CSG nodes has a significant CPU cost compared to creating a MeshInstance3D with a PrimitiveMesh. Moving a CSG node within another CSG node also has a significant CPU cost, so it should be avoided during gameplay.

## Properties

- `cone: bool` = `false` — If `true` a cone is created, the `radius` will only apply to one side.
- `height: float` = `2.0` — The height of the cylinder.
- `material: Material` — The material used to render the cylinder.
- `radius: float` = `0.5` — The radius of the cylinder.
- `sides: int` = `8` — The number of sides of the cylinder, the higher this number the more detail there will be in the cylinder.
- `smooth_faces: bool` = `true` — If `true` the normals of the cylinder are set to give a smooth effect making the cylinder seem rounded.
