# RDShaderSPIRV

**Inherits:** Resource

SPIR-V intermediate representation as part of an RDShaderFile (used by RenderingDevice).

RDShaderSPIRV represents an RDShaderFile's SPIR-V code for various shader stages, as well as possible compilation error messages. SPIR-V is a low-level intermediate shader representation. This intermediate representation is not used directly by GPUs for rendering, but it can be compiled into binary shaders that GPUs can understand. Unlike compiled shaders, SPIR-V is portable across GPU models and driver versions.

## Properties

- `bytecode_any_hit: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the any hit shader stage.
- `bytecode_closest_hit: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the closest hit shader stage.
- `bytecode_compute: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the compute shader stage.
- `bytecode_fragment: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the fragment shader stage.
- `bytecode_intersection: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the intersection shader stage.
- `bytecode_miss: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the miss shader stage.
- `bytecode_raygen: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the ray generation shader stage.
- `bytecode_tesselation_control: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the tessellation control shader stage.
- `bytecode_tesselation_evaluation: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the tessellation evaluation shader stage.
- `bytecode_vertex: PackedByteArray` = `PackedByteArray()` — The SPIR-V bytecode for the vertex shader stage.
- `compile_error_any_hit: String` = `""` — The compilation error message for the any hit shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_closest_hit: String` = `""` — The compilation error message for the closest hit shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_compute: String` = `""` — The compilation error message for the compute shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_fragment: String` = `""` — The compilation error message for the fragment shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_intersection: String` = `""` — The compilation error message for the intersection shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_miss: String` = `""` — The compilation error message for the miss shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_raygen: String` = `""` — The compilation error message for the ray generation shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_tesselation_control: String` = `""` — The compilation error message for the tessellation control shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_tesselation_evaluation: String` = `""` — The compilation error message for the tessellation evaluation shader stage (set by the SPIR-V compiler and Godot).
- `compile_error_vertex: String` = `""` — The compilation error message for the vertex shader stage (set by the SPIR-V compiler and Godot).

## Methods

- `get_stage_bytecode(stage: RenderingDevice.ShaderStage) -> PackedByteArray` *const* — Equivalent to getting one of `bytecode_compute`, `bytecode_fragment`, `bytecode_tesselation_control`, `bytecode_tesselation_evaluation`, `bytecode_vertex`.
- `get_stage_compile_error(stage: RenderingDevice.ShaderStage) -> String` *const* — Returns the compilation error message for the given shader `stage`.
- `set_stage_bytecode(stage: RenderingDevice.ShaderStage, bytecode: PackedByteArray) -> void` — Sets the SPIR-V `bytecode` for the given shader `stage`.
- `set_stage_compile_error(stage: RenderingDevice.ShaderStage, compile_error: String) -> void` — Sets the compilation error message for the given shader `stage` to `compile_error`.
