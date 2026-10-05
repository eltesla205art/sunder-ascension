# Thread

**Inherits:** RefCounted

A unit of execution in a process.

A unit of execution in a process. Can run methods on Objects simultaneously. The use of synchronization via Mutex or Semaphore is advised if working with shared objects. Warning: To ensure proper cleanup without crashes or deadlocks, when a Thread's reference count reaches zero and it is therefore destroyed, the following conditions must be met: - It must not have any Mutex objects locked. - It must not be waiting on any Semaphore objects. - `wait_to_finish` should have been called on it.

## Methods

- `get_id() -> String` *const* — Returns the current Thread's ID, uniquely identifying it among all threads.
- `is_alive() -> bool` *const* — Returns `true` if this Thread is currently running the provided function.
- `is_main_thread() -> bool` *static* — Returns `true` if the thread this method was called from is the main thread.
- `is_started() -> bool` *const* — Returns `true` if this Thread has been started.
- `set_thread_safety_checks_enabled(enabled: bool) -> void` *static* — Sets whether the thread safety checks the engine normally performs in methods of certain classes (e.g., Node) should happen on the current thread.
- `start(callable: Callable, priority: Thread.Priority = 1) -> int[Error]` — Starts a new Thread that calls `callable`.
- `wait_to_finish() -> Variant` — Joins the Thread and waits for it to finish.

## Enum Priority

- `PRIORITY_LOW = 0` — A thread running with lower priority than normally.
- `PRIORITY_NORMAL = 1` — A thread with a standard priority.
- `PRIORITY_HIGH = 2` — A thread running with higher priority than normally.
