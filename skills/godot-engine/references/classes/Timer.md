# Timer

**Inherits:** Node

A countdown timer.

The Timer node is a countdown timer and is the simplest way to handle time-based logic in the engine. When a timer reaches the end of its `wait_time`, it will emit the `timeout` signal. After a timer enters the scene tree, it can be manually started with `start`. A timer node is also started automatically if `autostart` is `true`.

## Properties

- `autostart: bool` = `false` — If `true`, the timer will start immediately when it enters the scene tree.
- `ignore_time_scale: bool` = `false` — If `true`, the timer will ignore `Engine.time_scale` and update with the real, elapsed time.
- `one_shot: bool` = `false` — If `true`, the timer will stop after reaching the end.
- `paused: bool` — If `true`, the timer is paused.
- `process_callback: Timer.TimerProcessCallback` = `1` — Specifies when the timer is updated during the main loop.
- `time_left: float` — The timer's remaining time in seconds.
- `wait_time: float` = `1.0` — The time required for the timer to end, in seconds.

## Methods

- `is_stopped() -> bool` *const* — Returns `true` if the timer is stopped or has not started.
- `start(time_sec: float = -1) -> void` — Starts the timer, or resets the timer if it was started already.
- `stop() -> void` — Stops the timer.

## Signals

- `timeout()` — Emitted when the timer reaches the end.

## Enum TimerProcessCallback

- `TIMER_PROCESS_PHYSICS = 0` — Update the timer every physics process frame (see `Node.NOTIFICATION_INTERNAL_PHYSICS_PROCESS`).
- `TIMER_PROCESS_IDLE = 1` — Update the timer every process (rendered) frame (see `Node.NOTIFICATION_INTERNAL_PROCESS`).
