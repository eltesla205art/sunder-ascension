# VisualShaderNodeSample3D

**Inherits:** VisualShaderNode

A base node for nodes which samples 3D textures in the visual shader graph.

A virtual class, use the descendants instead.

## Properties

- `source: VisualShaderNodeSample3D.Source` = `0` — An input source type.

## Enum Source

- `SOURCE_TEXTURE = 0` — Creates internal uniform and provides a way to assign it within node.
- `SOURCE_PORT = 1` — Use the uniform texture from sampler port.
- `SOURCE_MAX = 2` — Represents the size of the `Source` enum.
