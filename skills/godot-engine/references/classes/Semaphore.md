# Semaphore

**Inherits:** RefCounted

A synchronization mechanism used to control access to a shared resource by Threads.

A synchronization semaphore that can be used to synchronize multiple Threads. Initialized to zero on creation. For a binary version, see Mutex. Warning: Semaphores must be used carefully to avoid deadlocks.

## Methods

- `post(count: int = 1) -> void` — Lowers the Semaphore, allowing one thread in, or more if `count` is specified.
- `try_wait() -> bool` — Like `wait`, but won't block, so if the value is zero, fails immediately and returns `false`.
- `wait() -> void` — Waits for the Semaphore, if its value is zero, blocks until non-zero.
