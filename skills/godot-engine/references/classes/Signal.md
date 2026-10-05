# Signal


A built-in type representing a signal of an Object.

Signal is a built-in Variant type that represents a signal of an Object instance. Like all Variant types, it can be stored in variables and passed to functions. Signals allow all connected Callables (and by extension their respective objects) to listen and react to events, without directly referencing one another. This keeps the code flexible and easier to manage.

## Constructors

- `Signal() -> Signal` — Constructs an empty Signal with no object nor signal name bound.
- `Signal(from: Signal) -> Signal` — Constructs a Signal as a copy of the given Signal.
- `Signal(object: Object, signal: StringName) -> Signal` — Creates a Signal object referencing a signal named `signal` in the specified `object`.

## Methods

- `connect(callable: Callable, flags: int = 0) -> int` — Connects this signal to the specified `callable`.
- `disconnect(callable: Callable) -> void` — Disconnects this signal from the specified Callable.
- `emit() -> void` *vararg const* — Emits this signal.
- `get_connections() -> Array` *const* — Returns an Array of connections for this signal.
- `get_name() -> StringName` *const* — Returns the name of this signal.
- `get_object() -> Object` *const* — Returns the object emitting this signal.
- `get_object_id() -> int` *const* — Returns the ID of the object emitting this signal (see `Object.get_instance_id`).
- `has_connections() -> bool` *const* — Returns `true` if any Callable is connected to this signal.
- `is_connected(callable: Callable) -> bool` *const* — Returns `true` if the specified Callable is connected to this signal.
- `is_null() -> bool` *const* — Returns `true` if this Signal has no object and the signal name is empty.

## Operators

- `operator !=(right: Signal) -> bool` — Returns `true` if the signals do not share the same object and name.
- `operator ==(right: Signal) -> bool` — Returns `true` if both signals share the same object and name.
