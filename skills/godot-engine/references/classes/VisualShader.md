# VisualShader

**Inherits:** Shader

A custom shader program with a visual editor.

This class provides a graph-like visual editor for creating a Shader. Although VisualShaders do not require coding, they share the same logic with script shaders. They use VisualShaderNodes that can be connected to each other to control the flow of the shader. The visual shader graph is converted to a script shader behind the scenes.

## Properties

- `graph_offset: Vector2` *(deprecated)* — Deprecated.

## Methods

- `add_node(type: VisualShader.Type, node: VisualShaderNode, position: Vector2, id: int) -> void` — Adds the specified `node` to the shader.
- `add_varying(name: String, mode: VisualShader.VaryingMode, type: VisualShader.VaryingType) -> void` — Adds a new varying value node to the shader.
- `attach_node_to_frame(type: VisualShader.Type, id: int, frame: int) -> void` — Attaches the given node to the given frame.
- `can_connect_nodes(type: VisualShader.Type, from_node: int, from_port: int, to_node: int, to_port: int) -> bool` *const* — Returns `true` if the specified nodes and ports can be connected together.
- `connect_nodes(type: VisualShader.Type, from_node: int, from_port: int, to_node: int, to_port: int) -> int[Error]` — Connects the specified nodes and ports.
- `connect_nodes_forced(type: VisualShader.Type, from_node: int, from_port: int, to_node: int, to_port: int) -> void` — Connects the specified nodes and ports, even if they can't be connected.
- `detach_node_from_frame(type: VisualShader.Type, id: int) -> void` — Detaches the given node from the frame it is attached to.
- `disconnect_nodes(type: VisualShader.Type, from_node: int, from_port: int, to_node: int, to_port: int) -> void` — Connects the specified nodes and ports.
- `get_node(type: VisualShader.Type, id: int) -> VisualShaderNode` *const* — Returns the shader node instance with specified `type` and `id`.
- `get_node_connections(type: VisualShader.Type) -> Dictionary[]` *const* — Returns the list of connected nodes with the specified type.
- `get_node_list(type: VisualShader.Type) -> PackedInt32Array` *const* — Returns the list of all nodes in the shader with the specified type.
- `get_node_position(type: VisualShader.Type, id: int) -> Vector2` *const* — Returns the position of the specified node within the shader graph.
- `get_valid_node_id(type: VisualShader.Type) -> int` *const* — Returns next valid node ID that can be added to the shader graph.
- `has_varying(name: String) -> bool` *const* — Returns `true` if the shader has a varying with the given `name`.
- `is_node_connection(type: VisualShader.Type, from_node: int, from_port: int, to_node: int, to_port: int) -> bool` *const* — Returns `true` if the specified node and port connection exists.
- `remove_node(type: VisualShader.Type, id: int) -> void` — Removes the specified node from the shader.
- `remove_varying(name: String) -> void` — Removes a varying value node with the given `name`.
- `replace_node(type: VisualShader.Type, id: int, new_class: StringName) -> void` — Replaces the specified node with a node of new class type.
- `set_mode(mode: Shader.Mode) -> void` — Sets the mode of this shader.
- `set_node_position(type: VisualShader.Type, id: int, position: Vector2) -> void` — Sets the position of the specified node.

## Enum Type

- `TYPE_VERTEX = 0` — A vertex shader, operating on vertices.
- `TYPE_FRAGMENT = 1` — A fragment shader, operating on fragments (pixels).
- `TYPE_LIGHT = 2` — A shader for light calculations.
- `TYPE_START = 3` — A function for the "start" stage of particle shader.
- `TYPE_PROCESS = 4` — A function for the "process" stage of particle shader.
- `TYPE_COLLIDE = 5` — A function for the "collide" stage (particle collision handler) of particle shader.
- `TYPE_START_CUSTOM = 6` — A function for the "start" stage of particle shader, with customized output.
- `TYPE_PROCESS_CUSTOM = 7` — A function for the "process" stage of particle shader, with customized output.
- `TYPE_SKY = 8` — A shader for 3D environment's sky.
- `TYPE_FOG = 9` — A compute shader that runs for each froxel of the volumetric fog map.
- `TYPE_TEXTURE_BLIT = 10` — A shader used to process blit calls to a DrawableTexture.
- `TYPE_MAX = 11` — Represents the size of the `Type` enum.

## Enum VaryingMode

- `VARYING_MODE_VERTEX_TO_FRAG_LIGHT = 0` — Varying is passed from `Vertex` function to `Fragment` and `Light` functions.
- `VARYING_MODE_FRAG_TO_LIGHT = 1` — Varying is passed from `Fragment` function to `Light` function.
- `VARYING_MODE_MAX = 2` — Represents the size of the `VaryingMode` enum.

## Enum VaryingType

- `VARYING_TYPE_FLOAT = 0` — Varying is of type float.
- `VARYING_TYPE_INT = 1` — Varying is of type int.
- `VARYING_TYPE_UINT = 2` — Varying is of type unsigned int.
- `VARYING_TYPE_VECTOR_2D = 3` — Varying is of type Vector2.
- `VARYING_TYPE_VECTOR_3D = 4` — Varying is of type Vector3.
- `VARYING_TYPE_VECTOR_4D = 5` — Varying is of type Vector4.
- `VARYING_TYPE_BOOLEAN = 6` — Varying is of type bool.
- `VARYING_TYPE_TRANSFORM = 7` — Varying is of type Transform3D.
- `VARYING_TYPE_MAX = 8` — Represents the size of the `VaryingType` enum.

## Constants

- `NODE_ID_INVALID = -1` — Indicates an invalid VisualShader node.
- `NODE_ID_OUTPUT = 0` — Indicates an output node of VisualShader.
