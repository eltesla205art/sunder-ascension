# RDAccelerationStructureInstance

**Inherits:** RefCounted

Acceleration structure instance (used by RenderingDevice).

RDAccelerationStructureInstance describes an instance of a Bottom-Level Acceleration Structure (BLAS) used in the `RenderingDevice.tlas_build` method.

## Properties

- `blas: RID` = `RID()` — The BLAS referenced by this instance.
- `flags: RenderingDevice.AccelerationStructureInstanceFlagBits` = `0` — Flags for the instance.
- `hit_sbt_range: int` = `0` — Hit shader binding table range used for this instance, allocated using the `RenderingDevice.hit_sbt_range_alloc` method.
- `id: int` = `0` — Custom instance ID that can be accessed in GLSL using `gl_InstanceCustomIndexEXT`.
- `mask: int` = `255` — Visibility mask used to control which rays can intersect this instance.
- `transform: Transform3D` = `Transform3D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)` — Transform applied to the referenced BLAS for this instance.
