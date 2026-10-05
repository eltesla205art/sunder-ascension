# RDAccelerationStructureGeometry

**Inherits:** RefCounted

Acceleration structure geometry (used by RenderingDevice).

RDAccelerationStructureGeometry describes a set of triangles used as raytracing geometry in the `RenderingDevice.blas_create` method. The geometry is always in triangle list form, either indexed or non-indexed. Triangle strips are not supported.

## Properties

- `flags: RenderingDevice.AccelerationStructureGeometryFlagBits` = `0` — Flags for the geometry.
- `index_buffer: RID` = `RID()` — Buffer containing vertex indices.
- `index_count: int` = `0` — Number of indices used by this geometry in `index_buffer`.
- `index_offset: int` = `0` — Byte offset of the first index in `index_buffer`.
- `vertex_buffer: RID` = `RID()` — Buffer containing vertices.
- `vertex_count: int` = `0` — Number of vertices used by this geometry in `vertex_buffer`.
- `vertex_format: RenderingDevice.DataFormat` = `232` — Format of the vertices in `vertex_buffer`.
- `vertex_offset: int` = `0` — Byte offset of the first vertex in `vertex_buffer`.
- `vertex_stride: int` = `0` — Number of bytes between each vertex in `vertex_buffer`.
