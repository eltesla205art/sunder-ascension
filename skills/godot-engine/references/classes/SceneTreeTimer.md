# SceneTreeTimer

**Inherits:** RefCounted

One-shot timer.

A one-shot timer managed by the scene tree, which emits `timeout` on completion. See also `SceneTree.create_timer`. As opposed to Timer, it does not require the instantiation of a node. Commonly used to create a one-shot delay timer as in the following example:  The timer will be dereferenced after its time elapses.

## Properties

- `time_left: float` — The time remaining (in seconds).

## Signals

- `timeout()` — Emitted when the timer reaches 0.
