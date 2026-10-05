# AudioEffectPanner

**Inherits:** AudioEffect

Adds a panner audio effect to an audio bus. Pans the sound left or right.

Determines how much of the audio signal is sent to the left and right channels. This helps with audio spatialization, giving sounds distinct places in a mix. AudioStreamPlayer2D and AudioStreamPlayer3D handle panning automatically, following where the source of the sound is on the screen.

## Properties

- `pan: float` = `0.0` — Pan position.
