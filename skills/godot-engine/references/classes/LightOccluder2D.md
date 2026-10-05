# LightOccluder2D

**Inherits:** Node2D

Occludes light cast by a Light2D, casting shadows.

Occludes light cast by a Light2D, casting shadows. The LightOccluder2D must be provided with an OccluderPolygon2D in order for the shadow to be computed.

## Properties

- `occluder: OccluderPolygon2D` — The OccluderPolygon2D used to compute the shadow.
- `occluder_light_mask: int` = `1` — The LightOccluder2D's occluder light mask.
- `sdf_collision: bool` = `true` — If enabled, the occluder will be part of a real-time generated signed distance field that can be used in custom shaders.
