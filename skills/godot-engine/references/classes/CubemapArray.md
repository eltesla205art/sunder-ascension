# CubemapArray

**Inherits:** ImageTextureLayered

An array of Cubemaps, stored together and with a single reference.

CubemapArrays are made of an array of Cubemaps. Like Cubemaps, they are made of multiple textures, the amount of which must be divisible by 6 (one for each face of the cube). The primary benefit of CubemapArrays is that they can be accessed in shader code using a single texture reference. In other words, you can pass multiple Cubemaps into a shader using a single CubemapArray.

## Methods

- `create_placeholder() -> Resource` *const* — Creates a placeholder version of this resource (PlaceholderCubemapArray).
