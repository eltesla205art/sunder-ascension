# AudioStreamRandomizer

**Inherits:** AudioStream

Wraps a pool of audio streams with pitch and volume shifting.

Picks a random AudioStream from the pool, depending on the playback mode, and applies random pitch shifting and volume shifting during playback.

## Properties

- `playback_mode: AudioStreamRandomizer.PlaybackMode` = `0` — Controls how this AudioStreamRandomizer picks which AudioStream to play next.
- `random_pitch: float` = `1.0` — The largest possible frequency multiplier of the random pitch variation.
- `random_pitch_semitones: float` = `0.0` — The largest possible distance, in semitones, of the random pitch variation.
- `random_volume_offset_db: float` = `0.0` — The intensity of random volume variation.
- `stream_{index}/stream: AudioStream` — The AudioStream at `index`.
- `stream_{index}/weight: float` = `1.0` — The probability weight of the AudioStream at `index`.
- `streams_count: int` = `0` — The number of streams in the stream pool.

## Methods

- `add_stream(index: int, stream: AudioStream, weight: float = 1.0) -> void` — Insert a stream at the specified index.
- `get_stream(index: int) -> AudioStream` *const* — Returns the stream at the specified index.
- `get_stream_probability_weight(index: int) -> float` *const* — Returns the probability weight associated with the stream at the given index.
- `move_stream(index_from: int, index_to: int) -> void` — Move a stream from one index to another.
- `remove_stream(index: int) -> void` — Remove the stream at the specified index.
- `set_stream(index: int, stream: AudioStream) -> void` — Set the AudioStream at the specified index.
- `set_stream_probability_weight(index: int, weight: float) -> void` — Set the probability weight of the stream at the specified index.

## Enum PlaybackMode

- `PLAYBACK_RANDOM_NO_REPEATS = 0` — Pick a stream at random according to the probability weights chosen for each stream, but avoid playing the same stream twice in a row whenever possible.
- `PLAYBACK_RANDOM = 1` — Pick a stream at random according to the probability weights chosen for each stream.
- `PLAYBACK_SEQUENTIAL = 2` — Play streams in the order they appear in the stream pool.
