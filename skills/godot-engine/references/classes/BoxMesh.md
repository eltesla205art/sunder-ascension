# BoxMesh

**Inherits:** PrimitiveMesh

Generate an axis-aligned box PrimitiveMesh.

Generate an axis-aligned box PrimitiveMesh. The box's UV layout is arranged in a 3×2 layout that allows texturing each face individually. To apply the same texture on all faces, change the material's UV property to `Vector3(3, 2, 1)`. This is equivalent to adding `UV *= vec2(3.0, 2.0)` in a vertex shader.

## Properties

- `size: Vector3` = `Vector3(1, 1, 1)` — The box's width, height and depth.
- `subdivide_depth: int` = `0` — Number of extra edge loops inserted along the Z axis.
- `subdivide_height: int` = `0` — Number of extra edge loops inserted along the Y axis.
- `subdivide_width: int` = `0` — Number of extra edge loops inserted along the X axis.
