# JavaObject

**Inherits:** RefCounted

Represents an object from the Java Native Interface.

Represents an object from the Java Native Interface. It can be returned from Java methods called on JavaClass or other JavaObjects. See JavaClassWrapper for an example. Note: This class only works on Android.

## Methods

- `get_java_class() -> JavaClass` *const* — Returns the JavaClass that this object is an instance of.
- `has_java_method(method: StringName) -> bool` *const* — Returns `true` if the given `method` name exists in the object's Java methods.
