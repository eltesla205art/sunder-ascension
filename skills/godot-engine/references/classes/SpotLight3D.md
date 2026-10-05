# SpotLight3D

**Inherits:** Light3D

A spotlight, such as a reflector spotlight or a lantern.

A Spotlight is a type of Light3D node that emits lights in a specific direction, in the shape of a cone. The light is attenuated through the distance. This attenuation can be configured by changing the energy, radius and attenuation parameters of Light3D. Light is emitted in the -Z direction of the node's global basis.

## Properties

- `light_specular: float` = `0.5` — 
- `shadow_bias: float` = `0.03` — 
- `shadow_normal_bias: float` = `1.0` — 
- `spot_angle: float` = `45.0` — The spotlight's angle in degrees.
- `spot_angle_attenuation: float` = `1.0` — The spotlight's angular attenuation curve.
- `spot_attenuation: float` = `1.0` — Controls the distance attenuation function for spotlights.
- `spot_range: float` = `5.0` — The maximal range that can be reached by the spotlight.
