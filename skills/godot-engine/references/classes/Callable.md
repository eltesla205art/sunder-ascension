# Callable


A built-in type representing a method or a standalone function.

Callable is a built-in Variant type that represents a function. It can either be a method within an Object instance, or a custom callable used for different purposes (see `is_custom`). Like all Variant types, it can be stored in variables and passed to other functions. It is most commonly used for signal callbacks.

## Constructors

- `Callable() -> Callable` — Constructs an empty Callable, with no object nor method bound.
- `Callable(from: Callable) -> Callable` — Constructs a Callable as a copy of the given Callable.
- `Callable(object: Object, method: StringName) -> Callable` — Creates a new Callable for the method named `method` in the specified `object`.

## Methods

- `bind() -> Callable` *vararg const* — Returns a copy of this Callable with one or more arguments bound.
- `bindv(arguments: Array) -> Callable` — Returns a copy of this Callable with one or more arguments bound, reading them from an array.
- `call() -> Variant` *vararg const* — Calls the method represented by this Callable.
- `call_deferred() -> void` *vararg const* — Calls the method represented by this Callable in deferred mode, i.e. at the end of the current frame.
- `callv(arguments: Array) -> Variant` *const* — Calls the method represented by this Callable.
- `create(variant: Variant, method: StringName) -> Callable` *static* — Creates a new Callable for the method named `method` in the specified `variant`.
- `get_argument_count() -> int` *const* — Returns the total number of arguments this Callable should take, including optional arguments.
- `get_bound_arguments() -> Array` *const* — Returns the array of arguments bound via successive `bind` or `unbind` calls.
- `get_bound_arguments_count() -> int` *const* — Returns the total amount of arguments bound via successive `bind` or `unbind` calls.
- `get_method() -> StringName` *const* — Returns the name of the method represented by this Callable.
- `get_object() -> Object` *const* — Returns the object on which this Callable is called.
- `get_object_id() -> int` *const* — Returns the ID of this Callable's object (see `Object.get_instance_id`).
- `get_unbound_arguments_count() -> int` *const* — Returns the total amount of arguments unbound via successive `bind` or `unbind` calls.
- `hash() -> int` *const* — Returns the 32-bit hash value of this Callable's object.
- `is_custom() -> bool` *const* — Returns `true` if this Callable is a custom callable.
- `is_null() -> bool` *const* — Returns `true` if this Callable has no target to call the method on.
- `is_standard() -> bool` *const* — Returns `true` if this Callable is a standard callable.
- `is_valid() -> bool` *const* — Returns `true` if the callable's object exists and has a valid method name assigned, or is a custom callable.
- `rpc() -> void` *vararg const* — Perform an RPC (Remote Procedure Call) on all connected peers.
- `rpc_id(peer_id: int) -> void` *vararg const* — Perform an RPC (Remote Procedure Call) on a specific peer ID (see multiplayer documentation for reference).
- `unbind(argcount: int) -> Callable` *const* — Returns a copy of this Callable with a number of arguments unbound.

## Operators

- `operator !=(right: Callable) -> bool` — Returns `true` if both Callables invoke different targets.
- `operator ==(right: Callable) -> bool` — Returns `true` if both Callables invoke the same custom target.
