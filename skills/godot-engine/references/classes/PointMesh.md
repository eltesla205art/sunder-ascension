# PointMesh

**Inherits:** PrimitiveMesh

Mesh with a single point primitive.

A PointMesh is a primitive mesh composed of a single point. Instead of relying on triangles, points are rendered as a single rectangle on the screen with a constant size. They are intended to be used with particle systems, but can also be used as a cheap way to render billboarded sprites (for example in a point cloud). In order to be displayed, point meshes must be used with a material that has a point size.
