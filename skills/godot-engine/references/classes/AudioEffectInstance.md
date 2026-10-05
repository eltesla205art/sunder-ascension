# AudioEffectInstance

**Inherits:** RefCounted

Manipulates the audio it receives for a given effect.

An audio effect instance manipulates the audio it receives for a given effect. This instance is automatically created by an AudioEffect when it is added to a bus, and should usually not be created directly. If necessary, it can be fetched at run-time with `AudioServer.get_bus_effect_instance`.

## Methods

- `_process(src_buffer: const AudioFrame*, r_dst_buffer: AudioFrame*, frame_count: int) -> void` *virtual required* — Called by the AudioServer to process this effect.
- `_process_silence() -> bool` *virtual const* — Override this method to customize the processing behavior of this effect instance.
