# AudioEffectCompressor

**Inherits:** AudioEffect

Adds a downward compressor audio effect to an audio bus. Allows control of the dynamic range via a volume threshold and timing controls.

A "compressor" decreases the volume of sounds when it exceeds a certain volume threshold level. A compressor can have many uses in a mix: - To compress the whole volume in the Master bus (although an AudioEffectHardLimiter is probably better). - To ensure balance of voice audio clips. - To sidechain, using another bus as a trigger. This decreases the volume of the bus it is attached to, by using the volume from another audio bus for threshold detection. This technique is common in video game mixing to decrease the volume of music and SFX while voices are being heard.

## Properties

- `attack_us: float` = `20.0` — Compressor's reaction time when the audio exceeds the volume threshold level, in microseconds.
- `gain: float` = `0.0` — Gain of the audio signal, in dB.
- `mix: float` = `1.0` — Balance between the original audio and the compressed audio.
- `ratio: float` = `4.0` — Amount of compression applied to the audio once it passes the volume threshold level.
- `release_ms: float` = `250.0` — Compressor's delay time to stop decreasing the volume after the it falls below the volume threshold level, in milliseconds.
- `sidechain: StringName` = `&""` — Audio bus to use for the volume threshold detection.
- `threshold: float` = `0.0` — The volume level above which compression is applied to the audio, in dB.
