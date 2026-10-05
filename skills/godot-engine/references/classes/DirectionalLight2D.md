# DirectionalLight2D

**Inherits:** Light2D

Directional 2D light from a distance.

A directional light is a type of Light2D node that models an infinite number of parallel rays covering the entire scene. It is used for lights with strong intensity that are located far away from the scene (for example: to model sunlight or moonlight). Light is emitted in the +Y direction of the node's global basis. For an unrotated light, this means that the light is emitted downwards.

## Properties

- `height: float` = `0.0` — The height of the light.
- `max_distance: float` = `10000.0` — The maximum distance from the camera center objects can be before their shadows are culled (in pixels).
