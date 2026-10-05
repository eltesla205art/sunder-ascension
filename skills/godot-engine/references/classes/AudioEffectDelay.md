# AudioEffectDelay

**Inherits:** AudioEffect

Adds a delay audio effect to an audio bus. Emulates an echo by playing the input audio back after a period of time.

A "delay" effect plays the input audio signal back after a period of time. Each repetition is called a "delay tap" or simply "tap". Delay taps may be played back multiple times to create the sound of a repeating, decaying echo. Delay effects range from a subtle echo to a pronounced blending of previous sounds with new sounds.

## Properties

- `dry: float` = `1.0` — The volume ratio of the original audio.
- `feedback_active: bool` = `false` — If `true`, feedback is enabled, repeating taps after they are played.
- `feedback_delay_ms: float` = `340.0` — Feedback delay time in milliseconds.
- `feedback_level_db: float` = `-6.0` — Gain for feedback, in dB.
- `feedback_lowpass: float` = `16000.0` — Low-pass filter for feedback, in Hz.
- `tap1_active: bool` = `true` — If `true`, the first tap will be enabled.
- `tap1_delay_ms: float` = `250.0` — First tap delay time in milliseconds, compared to the original audio.
- `tap1_level_db: float` = `-6.0` — Gain for the first tap, in dB.
- `tap1_pan: float` = `0.2` — Pan position for the first tap.
- `tap2_active: bool` = `true` — If `true`, the second tap will be enabled.
- `tap2_delay_ms: float` = `500.0` — Second tap delay time in milliseconds, compared to the original audio.
- `tap2_level_db: float` = `-12.0` — Gain for the second tap, in dB.
- `tap2_pan: float` = `-0.4` — Pan position for the second tap.
