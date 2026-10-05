# VisualShaderNodeCustom

**Inherits:** VisualShaderNode

Virtual class to define custom VisualShaderNodes for use in the Visual Shader Editor.

By inheriting this class you can create a custom VisualShader script addon which will be automatically added to the Visual Shader Editor. The VisualShaderNode's behavior is defined by overriding the provided virtual methods. In order for the node to be registered as an editor addon, you must use the `@tool` annotation and provide a `class_name` for your custom script. For example:

## Methods

- `_get_category() -> String` *virtual const* — Override this method to define the path to the associated custom node in the Visual Shader Editor's members dialog.
- `_get_code(input_vars: String[], output_vars: String[], mode: Shader.Mode, type: VisualShader.Type) -> String` *virtual const* — Override this method to define the actual shader code of the associated custom node.
- `_get_default_input_port(type: VisualShaderNode.PortType) -> int` *virtual const* — Override this method to define the input port which should be connected by default when this node is created as a result of dragging a connection from an existing node to the empty space on the graph.
- `_get_description() -> String` *virtual const* — Override this method to define the description of the associated custom node in the Visual Shader Editor's members dialog.
- `_get_func_code(mode: Shader.Mode, type: VisualShader.Type) -> String` *virtual const* — Override this method to add a shader code to the beginning of each shader function (once).
- `_get_global_code(mode: Shader.Mode) -> String` *virtual const* — Override this method to add shader code on top of the global shader, to define your own standard library of reusable methods, varyings, constants, uniforms, etc.
- `_get_input_port_count() -> int` *virtual const* — Override this method to define the number of input ports of the associated custom node.
- `_get_input_port_default_value(port: int) -> Variant` *virtual const* — Override this method to define the default value for the specified input port.
- `_get_input_port_name(port: int) -> String` *virtual const* — Override this method to define the names of input ports of the associated custom node.
- `_get_input_port_type(port: int) -> int[VisualShaderNode.PortType]` *virtual const* — Override this method to define the returned type of each input port of the associated custom node.
- `_get_name() -> String` *virtual const* — Override this method to define the name of the associated custom node in the Visual Shader Editor's members dialog and graph.
- `_get_output_port_count() -> int` *virtual const* — Override this method to define the number of output ports of the associated custom node.
- `_get_output_port_name(port: int) -> String` *virtual const* — Override this method to define the names of output ports of the associated custom node.
- `_get_output_port_type(port: int) -> int[VisualShaderNode.PortType]` *virtual const* — Override this method to define the returned type of each output port of the associated custom node.
- `_get_property_count() -> int` *virtual const* — Override this method to define the number of the properties.
- `_get_property_default_index(index: int) -> int` *virtual const* — Override this method to define the default index of the property of the associated custom node.
- `_get_property_name(index: int) -> String` *virtual const* — Override this method to define the names of the property of the associated custom node.
- `_get_property_options(index: int) -> PackedStringArray` *virtual const* — Override this method to define the options inside the drop-down list property of the associated custom node.
- `_get_return_icon_type() -> int[VisualShaderNode.PortType]` *virtual const* — Override this method to define the return icon of the associated custom node in the Visual Shader Editor's members dialog.
- `_is_available(mode: Shader.Mode, type: VisualShader.Type) -> bool` *virtual const* — Override this method to prevent the node to be visible in the member dialog for the certain `mode` and/or `type`.
- `_is_highend() -> bool` *virtual const* — Override this method to enable the high-end mark in the Visual Shader Editor's members dialog.
- `get_option_index(option: int) -> int` *const* — Returns the selected index of the drop-down list option within a graph.
