# GLTFObjectModelProperty

**Inherits:** RefCounted

Describes how to access a property as defined in the glTF object model.

GLTFObjectModelProperty defines a mapping between a property in the glTF object model and a NodePath in the Godot scene tree. This can be used to animate properties in a glTF file using the `KHR_animation_pointer` extension, or to access them through an engine-agnostic script such as a behavior graph as defined by the `KHR_interactivity` extension. The glTF property is identified by JSON pointer(s) stored in `json_pointers`, while the Godot property it maps to is defined by `node_paths`. In most cases `json_pointers` and `node_paths` will each only have one item, but in some cases a single glTF JSON pointer will map to multiple Godot properties, or a single Godot property will be mapped to multiple glTF JSON pointers, or it might be a many-to-many relationship.

## Properties

- `gltf_to_godot_expression: Expression` — If set, this Expression will be used to convert the property value from the glTF object model to the value expected by the Godot property.
- `godot_to_gltf_expression: Expression` — If set, this Expression will be used to convert the property value from the Godot property to the value expected by the glTF object model.
- `json_pointers: PackedStringArray[]` = `[]` — The glTF object model JSON pointers used to identify the property in the glTF object model.
- `node_paths: NodePath[]` = `[]` — An array of NodePaths that point to a property, or multiple properties, in the Godot scene tree.
- `object_model_type: GLTFObjectModelProperty.GLTFObjectModelType` = `0` — The type of data stored in the glTF file as defined by the object model.
- `variant_type: Variant.Type` = `0` — The type of data stored in the Godot property.

## Methods

- `append_node_path(node_path: NodePath) -> void` — Appends a NodePath to `node_paths`.
- `append_path_to_property(node_path: NodePath, prop_name: StringName) -> void` — High-level wrapper over `append_node_path` that handles the most common cases.
- `get_accessor_type() -> int[GLTFAccessor.GLTFAccessorType]` *const* — The GLTF accessor type associated with this property's `object_model_type`.
- `has_json_pointers() -> bool` *const* — Returns `true` if `json_pointers` is not empty.
- `has_node_paths() -> bool` *const* — Returns `true` if `node_paths` is not empty.
- `set_types(variant_type: Variant.Type, obj_model_type: GLTFObjectModelProperty.GLTFObjectModelType) -> void` — Sets the `variant_type` and `object_model_type` properties.

## Enum GLTFObjectModelType

- `GLTF_OBJECT_MODEL_TYPE_UNKNOWN = 0` — Unknown or not set object model type.
- `GLTF_OBJECT_MODEL_TYPE_BOOL = 1` — Object model type "bool".
- `GLTF_OBJECT_MODEL_TYPE_FLOAT = 2` — Object model type "float".
- `GLTF_OBJECT_MODEL_TYPE_FLOAT_ARRAY = 3` — Object model type "float[]".
- `GLTF_OBJECT_MODEL_TYPE_FLOAT2 = 4` — Object model type "float2".
- `GLTF_OBJECT_MODEL_TYPE_FLOAT3 = 5` — Object model type "float3".
- `GLTF_OBJECT_MODEL_TYPE_FLOAT4 = 6` — Object model type "float4".
- `GLTF_OBJECT_MODEL_TYPE_FLOAT2X2 = 7` — Object model type "float2x2".
- `GLTF_OBJECT_MODEL_TYPE_FLOAT3X3 = 8` — Object model type "float3x3".
- `GLTF_OBJECT_MODEL_TYPE_FLOAT4X4 = 9` — Object model type "float4x4".
- `GLTF_OBJECT_MODEL_TYPE_INT = 10` — Object model type "int".
