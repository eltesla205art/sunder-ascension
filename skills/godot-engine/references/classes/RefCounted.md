# RefCounted

**Inherits:** Object

Base class for reference-counted objects.

Base class for any object that keeps a reference count. Resource and many other helper objects inherit this class. Unlike other Object types, RefCounteds keep an internal reference counter so that they are automatically released when no longer in use, and only then. RefCounteds therefore do not need to be freed manually with `Object.free`.

## Methods

- `get_reference_count() -> int` *const* — Returns the current reference count.
- `init_ref() -> bool` — Initializes the internal reference counter.
- `reference() -> bool` — Increments the internal reference counter.
- `unreference() -> bool` — Decrements the internal reference counter.
