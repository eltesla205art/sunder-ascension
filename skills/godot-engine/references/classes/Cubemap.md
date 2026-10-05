# Cubemap

**Inherits:** ImageTextureLayered

Six square textures representing the faces of a cube. Commonly used as a skybox.

A cubemap is made of 6 textures organized in layers. They are typically used for faking reflections in 3D rendering (see ReflectionProbe). It can be used to make an object look as if it's reflecting its surroundings. This usually delivers much better performance than other reflection methods.

## Methods

- `create_placeholder() -> Resource` *const* — Creates a placeholder version of this resource (PlaceholderCubemap).
