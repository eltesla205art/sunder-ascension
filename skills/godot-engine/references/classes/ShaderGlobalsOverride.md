# ShaderGlobalsOverride

**Inherits:** Node

A node used to override global shader parameters' values in a scene.

Similar to how a WorldEnvironment node can be used to override the environment while a specific scene is loaded, ShaderGlobalsOverride can be used to override global shader parameters temporarily. Once the node is removed, the project-wide values for the global shader parameters are restored. See the RenderingServer `global_shader_parameter_*` methods for more information. Note: Only one ShaderGlobalsOverride can be used per scene.
