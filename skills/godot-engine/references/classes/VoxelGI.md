# VoxelGI

**Inherits:** VisualInstance3D

Real-time global illumination (GI) probe.

VoxelGIs are used to provide high-quality real-time indirect light and reflections to scenes. They precompute the effect of objects that emit light and the effect of static geometry to simulate the behavior of complex light in real-time. VoxelGIs need to be baked before having a visible effect. However, once baked, dynamic objects will receive light from them.

## Properties

- `camera_attributes: CameraAttributes` — The CameraAttributes resource that specifies exposure levels to bake at.
- `data: VoxelGIData` — The VoxelGIData resource that holds the data for this VoxelGI.
- `size: Vector3` = `Vector3(20, 20, 20)` — The size of the area covered by the VoxelGI.
- `subdiv: VoxelGI.Subdiv` = `1` — Number of times to subdivide the grid that the VoxelGI operates on.

## Methods

- `bake(from_node: Node = null, create_visual_debug: bool = false) -> void` — Bakes the effect from all GeometryInstance3Ds marked with `GeometryInstance3D.GI_MODE_STATIC` and Light3Ds marked with either `Light3D.BAKE_STATIC` or `Light3D.BAKE_DYNAMIC`.
- `debug_bake() -> void` — Calls `bake` with `create_visual_debug` enabled.

## Enum Subdiv

- `SUBDIV_64 = 0` — Use 64 subdivisions.
- `SUBDIV_128 = 1` — Use 128 subdivisions.
- `SUBDIV_256 = 2` — Use 256 subdivisions.
- `SUBDIV_512 = 3` — Use 512 subdivisions.
- `SUBDIV_MAX = 4` — Represents the size of the `Subdiv` enum.
