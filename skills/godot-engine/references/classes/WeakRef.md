# WeakRef

**Inherits:** RefCounted

Holds an Object. If the object is RefCounted, it doesn't update the reference count.

A weakref can hold a RefCounted without contributing to the reference counter. A weakref can be created from an Object using `@GlobalScope.weakref`. If this object is not a reference, weakref still works, however, it does not have any effect on the object. Weakrefs are useful in cases where multiple classes have variables that refer to each other.

## Methods

- `get_ref() -> Variant` *const* — Returns the Object this weakref is referring to.
