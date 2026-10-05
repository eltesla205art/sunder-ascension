# ImmediateMesh

**Inherits:** Mesh

Mesh optimized for creating geometry manually.

A mesh type optimized for creating geometry manually, similar to OpenGL 1.x immediate mode. Here's a sample on how to generate a triangular face:  Note: Generating complex geometries with ImmediateMesh is highly inefficient. Instead, it is designed to generate simple geometry that changes often.

## Methods

- `clear_surfaces() -> void` — Clear all surfaces.
- `surface_add_vertex(vertex: Vector3) -> void` — Add a 3D vertex using the current attributes previously set.
- `surface_add_vertex_2d(vertex: Vector2) -> void` — Add a 2D vertex using the current attributes previously set.
- `surface_begin(primitive: Mesh.PrimitiveType, material: Material = null) -> void` — Begin a new surface.
- `surface_end() -> void` — End and commit current surface.
- `surface_set_color(color: Color) -> void` — Set the color attribute that will be pushed with the next vertex.
- `surface_set_normal(normal: Vector3) -> void` — Set the normal attribute that will be pushed with the next vertex.
- `surface_set_tangent(tangent: Plane) -> void` — Set the tangent attribute that will be pushed with the next vertex.
- `surface_set_uv(uv: Vector2) -> void` — Set the UV attribute that will be pushed with the next vertex.
- `surface_set_uv2(uv2: Vector2) -> void` — Set the UV2 attribute that will be pushed with the next vertex.
