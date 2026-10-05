# RDVertexAttribute

**Inherits:** RefCounted

Vertex attribute (used by RenderingDevice).

This object is used by RenderingDevice.

## Properties

- `binding: int` = `4294967295` — The index of the buffer in the vertex buffer array to bind this vertex attribute.
- `format: RenderingDevice.DataFormat` = `232` — The way that this attribute's data is interpreted when sent to a shader.
- `frequency: RenderingDevice.VertexFrequency` = `0` — The rate at which this attribute is pulled from its vertex buffer.
- `location: int` = `0` — The location in the shader that this attribute is bound to.
- `offset: int` = `0` — The number of bytes between the start of the vertex buffer and the first instance of this attribute.
- `stride: int` = `0` — The number of bytes between the starts of consecutive instances of this attribute.
