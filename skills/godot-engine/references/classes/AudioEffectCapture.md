# AudioEffectCapture

**Inherits:** AudioEffect

Exposes audio samples from an audio bus in real-time, such that it can be accessed as data.

Copies all audio frames, also known as "samples" or "audio samples", from the attached audio bus into its internal ring buffer. This effect does not alter the audio. Can be used for storing real-time audio data for playback, and for creating real-time audio visualizations, like an oscilloscope. Application code should consume these audio frames from this ring buffer using `get_buffer` and process it as needed, for example to capture data from an AudioStreamMicrophone, implement application-defined effects, or to transmit audio over the network.

## Properties

- `buffer_length: float` = `0.1` — Length of the internal ring buffer, in seconds.

## Methods

- `can_get_buffer(frames: int) -> bool` *const* — Returns `true` if at least `frames` samples are available to read in the internal ring buffer.
- `clear_buffer() -> void` — Clears the internal ring buffer.
- `get_buffer(frames: int) -> PackedVector2Array` — Gets the next `frames` samples from the internal ring buffer.
- `get_buffer_length_frames() -> int` *const* — Returns the total size of the internal ring buffer in number of samples.
- `get_discarded_frames() -> int` *const* — Returns the number of samples discarded from the audio bus due to full buffer.
- `get_frames_available() -> int` *const* — Returns the number of samples available to read using `get_buffer`.
- `get_pushed_frames() -> int` *const* — Returns the number of samples inserted from the audio bus.
