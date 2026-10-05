# GLTFAccessor

**Inherits:** Resource

Represents a glTF accessor.

GLTFAccessor is a data structure representing a glTF `accessor` that would be found in the `"accessors"` array. A buffer is a blob of binary data. A buffer view is a slice of a buffer. An accessor is a typed interpretation of the data in a buffer view.

## Properties

- `accessor_type: GLTFAccessor.GLTFAccessorType` = `0` — The glTF accessor type, as an enum.
- `buffer_view: int` = `-1` — The index of the buffer view this accessor is referencing.
- `byte_offset: int` = `0` — The offset relative to the start of the buffer view in bytes.
- `component_type: GLTFAccessor.GLTFComponentType` = `0` — The glTF component type as an enum.
- `count: int` = `0` — The number of elements referenced by this accessor.
- `max: PackedFloat64Array` = `PackedFloat64Array()` — Maximum value of each component in this accessor.
- `min: PackedFloat64Array` = `PackedFloat64Array()` — Minimum value of each component in this accessor.
- `normalized: bool` = `false` — Specifies whether integer data values are normalized before usage.
- `sparse_count: int` = `0` — Number of deviating accessor values stored in the sparse array.
- `sparse_indices_buffer_view: int` = `0` — The index of the buffer view with sparse indices.
- `sparse_indices_byte_offset: int` = `0` — The offset relative to the start of the buffer view in bytes.
- `sparse_indices_component_type: GLTFAccessor.GLTFComponentType` = `0` — The indices component data type as an enum.
- `sparse_values_buffer_view: int` = `0` — The index of the bufferView with sparse values.
- `sparse_values_byte_offset: int` = `0` — The offset relative to the start of the bufferView in bytes.
- `type: int` *(deprecated)* — The glTF accessor type, as an int.

## Methods

- `from_dictionary(dictionary: Dictionary) -> GLTFAccessor` *static* — Creates a new GLTFAccessor instance by parsing the given Dictionary.
- `to_dictionary() -> Dictionary` *const* — Serializes this GLTFAccessor instance into a Dictionary.

## Enum GLTFAccessorType

- `TYPE_SCALAR = 0` — Accessor type "SCALAR".
- `TYPE_VEC2 = 1` — Accessor type "VEC2".
- `TYPE_VEC3 = 2` — Accessor type "VEC3".
- `TYPE_VEC4 = 3` — Accessor type "VEC4".
- `TYPE_MAT2 = 4` — Accessor type "MAT2".
- `TYPE_MAT3 = 5` — Accessor type "MAT3".
- `TYPE_MAT4 = 6` — Accessor type "MAT4".

## Enum GLTFComponentType

- `COMPONENT_TYPE_NONE = 0` — Component type "NONE".
- `COMPONENT_TYPE_SIGNED_BYTE = 5120` — Component type "BYTE".
- `COMPONENT_TYPE_UNSIGNED_BYTE = 5121` — Component type "UNSIGNED_BYTE".
- `COMPONENT_TYPE_SIGNED_SHORT = 5122` — Component type "SHORT".
- `COMPONENT_TYPE_UNSIGNED_SHORT = 5123` — Component type "UNSIGNED_SHORT".
- `COMPONENT_TYPE_SIGNED_INT = 5124` — Component type "INT".
- `COMPONENT_TYPE_UNSIGNED_INT = 5125` — Component type "UNSIGNED_INT".
- `COMPONENT_TYPE_SINGLE_FLOAT = 5126` — Component type "FLOAT".
- `COMPONENT_TYPE_DOUBLE_FLOAT = 5130` — Component type "DOUBLE".
- `COMPONENT_TYPE_HALF_FLOAT = 5131` — Component type "HALF_FLOAT".
- `COMPONENT_TYPE_SIGNED_LONG = 5134` — Component type "LONG".
- `COMPONENT_TYPE_UNSIGNED_LONG = 5135` — Component type "UNSIGNED_LONG".
