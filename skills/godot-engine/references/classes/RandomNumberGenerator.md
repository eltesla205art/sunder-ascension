# RandomNumberGenerator

**Inherits:** RefCounted

Provides methods for generating pseudo-random numbers.

RandomNumberGenerator is a class for generating pseudo-random numbers. It currently uses PCG32. Note: The underlying algorithm is an implementation detail and should not be depended upon. To generate a random float number (within a given range) based on a time-dependent seed:

## Properties

- `seed: int` = `0` — Initializes the random number generator state based on the given seed value.
- `state: int` = `0` — The current state of the random number generator.

## Methods

- `rand_weighted(weights: PackedFloat32Array) -> int` — Returns a random integer between `0` and the size of the array that is passed as a parameter.
- `randf() -> float` — Returns a pseudo-random float between `0.0` and `1.0` (inclusive).
- `randf_range(from: float, to: float) -> float` — Returns a pseudo-random float between `from` and `to` (inclusive).
- `randfn(mean: float = 0.0, deviation: float = 1.0) -> float` — Returns a normally-distributed, pseudo-random floating-point number from the specified `mean` and a standard `deviation`.
- `randi() -> int` — Returns a pseudo-random 32-bit unsigned integer between `0` and `4294967295` (inclusive).
- `randi_range(from: int, to: int) -> int` — Returns a pseudo-random 32-bit signed integer between `from` and `to` (inclusive).
- `randomize() -> void` — Sets up a time-based seed for this RandomNumberGenerator instance.
