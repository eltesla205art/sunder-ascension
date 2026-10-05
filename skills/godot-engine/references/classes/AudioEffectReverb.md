# AudioEffectReverb

**Inherits:** AudioEffect

Adds a reverberation audio effect to an audio bus. Emulates an echo by playing a blurred version of the input audio.

A "reverb" effect plays the input audio back continuously, decaying over a period of time. It simulates sounds in different kinds of spaces, ranging from small rooms, to big caverns. See also AudioEffectDelay for a non-blurry type of echo.

## Properties

- `damping: float` = `0.5` — Defines how reflective the imaginary room's walls are.
- `dry: float` = `1.0` — The volume ratio of the original audio.
- `hipass: float` = `0.0` — High-pass filter allows frequencies higher than a certain cutoff threshold and attenuates frequencies lower than the cutoff threshold.
- `predelay_feedback: float` = `0.4` — Gain of early reflection copies.
- `predelay_msec: float` = `150.0` — Time between the original audio and the early reflections of the reverb signal, in milliseconds.
- `room_size: float` = `0.8` — Dimensions of simulated room.
- `spread: float` = `1.0` — Widens or narrows the stereo image of the reverb tail.
- `wet: float` = `0.5` — The volume ratio of the modified audio.
