# RDHitGroup

**Inherits:** RefCounted

Hit group (used by RenderingDevice).

Defines a hit group for use with `RenderingDevice.raytracing_pipeline_create`. A hit group combines shaders that are executed when a ray intersects geometry. It may include a closest-hit shader, any-hit shader, and intersection shader. Hit groups are referenced by index when populating hit shader binding tables using `RenderingDevice.hit_sbt_range_update`.

## Properties

- `any_hit_shader: RDPipelineShader` — Any-hit shader for this hit group.
- `closest_hit_shader: RDPipelineShader` — Closest-hit shader for this hit group.
- `intersection_shader: RDPipelineShader` — Intersection shader for this hit group.
