# Mutex

**Inherits:** RefCounted

A binary Semaphore for synchronization of multiple Threads.

A synchronization mutex (mutual exclusion). This is used to synchronize multiple Threads, and is equivalent to a binary Semaphore. It guarantees that only one thread can access a critical section at a time. This is a reentrant mutex, meaning that it can be locked multiple times by one thread, provided it also unlocks it as many times.

## Methods

- `lock() -> void` — Locks this Mutex, blocks until it is unlocked by the current owner.
- `try_lock() -> bool` — Tries locking this Mutex, but does not block.
- `unlock() -> void` — Unlocks this Mutex, leaving it to other threads.
