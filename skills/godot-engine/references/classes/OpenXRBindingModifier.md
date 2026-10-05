# OpenXRBindingModifier

**Inherits:** Resource

Binding modifier base class.

Binding modifier base class. Subclasses implement various modifiers that alter how an OpenXR runtime processes inputs.

## Methods

- `_get_description() -> String` *virtual required const* — Return the description of this class that is used for the title bar of the binding modifier editor.
- `_get_ip_modification() -> PackedByteArray` *virtual required* — Returns the data that is sent to OpenXR when submitting the suggested interacting bindings this modifier is a part of.
