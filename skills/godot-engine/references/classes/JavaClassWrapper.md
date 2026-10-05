# JavaClassWrapper

**Inherits:** Object

Provides access to the Java Native Interface.

The JavaClassWrapper singleton provides a way for the Godot application to send and receive data through the Java Native Interface (JNI). Note: This singleton is only available in Android builds. Warning: When calling Java methods, be sure to check `JavaClassWrapper.get_exception` to check if the method threw an exception.

## Methods

- `create_proxy(object: Object, interfaces: PackedStringArray) -> JavaObject` — Creates a JavaObject implementing the given Java interfaces using the given Object as the implementation.
- `create_sam_callback(sam_interface: String, callable: Callable) -> JavaObject` — Creates a JavaObject implementing the Java Single Abstract Method (SAM) interface using the Godot Callable as the implementation.
- `get_exception() -> JavaObject` — Returns the Java exception from the last call into a Java class.
- `wrap(name: String) -> JavaClass` — Wraps a class defined in Java, and returns it as a JavaClass Object type that Godot can interact with.
