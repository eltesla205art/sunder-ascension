# CSGMesh3D

**Inherits:** CSGPrimitive3D

A CSG Mesh shape that uses a mesh resource.

This CSG node allows you to use any mesh resource as a CSG shape, provided it is manifold. A manifold shape is closed, does not self-intersect, does not contain internal faces and has no edges that connect to more than two faces. See also CSGPolygon3D for drawing 2D extruded polygons to be used as CSG nodes. Note: CSG nodes are intended to be used for level prototyping.

## Properties

- `material: Material` — The Material used in drawing the CSG shape.
- `mesh: Mesh` — The Mesh resource to use as a CSG shape.
