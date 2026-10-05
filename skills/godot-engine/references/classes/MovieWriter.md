# MovieWriter

**Inherits:** Object

Abstract class for non-real-time video recording encoders.

Godot can record videos with non-real-time simulation. Like the `--fixed-fps` command line argument, this forces the reported `delta` in `Node._process` functions to be identical across frames, regardless of how long it actually took to render the frame. This can be used to record high-quality videos with perfect frame pacing regardless of your hardware's capabilities. Godot has 3 built-in MovieWriters: - OGV container with Theora for video and Vorbis for audio (`.ogv` file extension).

## Methods

- `_get_audio_mix_rate() -> int` *virtual required const* — Called when the audio sample rate used for recording the audio is requested by the engine.
- `_get_audio_speaker_mode() -> int[AudioServer.SpeakerMode]` *virtual required const* — Called when the audio speaker mode used for recording the audio is requested by the engine.
- `_get_supported_extensions() -> PackedStringArray` *virtual required const* — Returns the list of supported filename extensions for movies written with this MovieWriter.
- `_handles_file(path: String) -> bool` *virtual required const* — Called when the engine determines whether this MovieWriter is able to handle the file at `path`.
- `_write_begin(movie_size: Vector2i, fps: int, base_path: String) -> int[Error]` *virtual required* — Called once before the engine starts writing video and audio data.
- `_write_end() -> void` *virtual required* — Called when the engine finishes writing.
- `_write_frame(frame_image: Image, audio_frame_block: const int32_t*) -> int[Error]` *virtual required* — Called at the end of every rendered frame.
- `add_writer(writer: MovieWriter) -> void` *static* — Adds a writer to be usable by the engine.
