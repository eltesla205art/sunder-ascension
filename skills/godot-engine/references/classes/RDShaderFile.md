# RDShaderFile

**Inherits:** Resource

Compiled shader file in SPIR-V form (used by RenderingDevice). Not to be confused with Godot's own Shader.

Compiled shader file in SPIR-V form. See also RDShaderSource. RDShaderFile is only meant to be used with the RenderingDevice API. It should not be confused with Godot's own Shader resource, which is what Godot's various nodes use for high-level shader programming.

## Properties

- `base_error: String` = `""` — The base compilation error message, which indicates errors not related to a specific shader stage if non-empty.

## Methods

- `get_spirv(version: StringName = &"") -> RDShaderSPIRV` *const* — Returns the SPIR-V intermediate representation for the specified shader `version`.
- `get_version_list() -> StringName[]` *const* — Returns the list of compiled versions for this shader.
- `set_bytecode(bytecode: RDShaderSPIRV, version: StringName = &"") -> void` — Sets the SPIR-V `bytecode` that will be compiled for the specified `version`.
