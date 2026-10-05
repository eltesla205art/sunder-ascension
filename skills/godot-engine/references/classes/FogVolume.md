# FogVolume

**Inherits:** VisualInstance3D

A region that contributes to the default volumetric fog from the world environment.

FogVolumes are used to add localized fog into the global volumetric fog effect. FogVolumes can also remove volumetric fog from specific areas if using a FogMaterial with a negative `FogMaterial.density`. Performance of FogVolumes is directly related to their relative size on the screen and the complexity of their attached FogMaterial. It is best to keep FogVolumes relatively small and simple where possible.

## Properties

- `material: Material` — The Material used by the FogVolume.
- `shape: RenderingServer.FogVolumeShape` = `3` — The shape of the FogVolume.
- `size: Vector3` = `Vector3(2, 2, 2)` — The size of the FogVolume when `shape` is `RenderingServer.FOG_VOLUME_SHAPE_ELLIPSOID`, `RenderingServer.FOG_VOLUME_SHAPE_CONE`, `RenderingServer.FOG_VOLUME_SHAPE_CYLINDER` or `RenderingServer.FOG_VOLUME_SHAPE_BOX`.
