# EncodedObjectAsID

**Inherits:** RefCounted

Holds a reference to an Object's instance ID.

Utility class which holds a reference to the internal identifier of an Object instance, as given by `Object.get_instance_id`. This ID can then be used to retrieve the object instance with `@GlobalScope.instance_from_id`. This class is used internally by the editor inspector and script debugger, but can also be used in plugins to pass and display objects as their IDs.

## Properties

- `object_id: int` = `0` — The Object identifier stored in this EncodedObjectAsID instance.
