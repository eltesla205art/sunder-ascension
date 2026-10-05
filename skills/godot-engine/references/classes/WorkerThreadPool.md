# WorkerThreadPool

**Inherits:** Object

A singleton that allocates some Threads on startup, used to offload tasks to these threads.

The WorkerThreadPool singleton allocates a set of Threads (called worker threads) on project startup and provides methods for offloading tasks to them. This can be used for simple multithreading without having to create Threads. Tasks hold the Callable to be run by the threads. WorkerThreadPool can be used to create regular tasks, which will be taken by one worker thread, or group tasks, which can be distributed between multiple worker threads.

## Methods

- `add_group_task(action: Callable, elements: int, tasks_needed: int = -1, high_priority: bool = false, description: String = "") -> int` — Adds `action` as a group task to be executed by the worker threads.
- `add_task(action: Callable, high_priority: bool = false, description: String = "") -> int` — Adds `action` as a task to be executed by a worker thread.
- `get_caller_group_id() -> int` *const* — Returns the task group ID of the current thread calling this method, or `-1` if invalid or the current thread is not part of a task group.
- `get_caller_task_id() -> int` *const* — Returns the task ID of the current thread calling this method, or `-1` if the task is a group task, invalid or the current thread is not part of the thread pool (e.g. the main thread).
- `get_group_processed_element_count(group_id: int) -> int` *const* — Returns how many times the Callable of the group task with the given ID has already been executed by the worker threads.
- `is_group_task_completed(group_id: int) -> bool` *const* — Returns `true` if the group task with the given ID is completed.
- `is_task_completed(task_id: int) -> bool` *const* — Returns `true` if the task with the given ID is completed.
- `wait_for_group_task_completion(group_id: int) -> void` — Pauses the thread that calls this method until the group task with the given ID is completed.
- `wait_for_task_completion(task_id: int) -> int[Error]` — Pauses the thread that calls this method until the task with the given ID is completed.
