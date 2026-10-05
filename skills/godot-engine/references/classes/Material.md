# Material

**Inherits:** Resource

Virtual base class for applying visual properties to an object, such as color and roughness.

Material is a base resource used for coloring and shading geometry. All materials inherit from it and almost all VisualInstance3D derived nodes carry a Material. A few flags and parameters are shared between all material types and are configured here. Importantly, you can inherit from Material to create your own custom material type in script or in GDExtension.

## Properties

- `next_pass: Material` — Sets the Material to be used for the next pass.
- `render_priority: int` — Sets the render priority for objects in 3D scenes.

## Methods

- `_can_do_next_pass() -> bool` *virtual const* — Only exposed for the purpose of overriding.
- `_can_use_render_priority() -> bool` *virtual const* — Only exposed for the purpose of overriding.
- `_get_shader_mode() -> int[Shader.Mode]` *virtual required const* — Only exposed for the purpose of overriding.
- `_get_shader_rid() -> RID` *virtual required const* — Only exposed for the purpose of overriding.
- `create_placeholder() -> Resource` *const* — Creates a placeholder version of this resource (PlaceholderMaterial).
- `inspect_native_shader_code() -> void` — Only available when running in the editor.

## Constants

- `RENDER_PRIORITY_MAX = 127` — Maximum value for the `render_priority` parameter.
- `RENDER_PRIORITY_MIN = -128` — Minimum value for the `render_priority` parameter.
