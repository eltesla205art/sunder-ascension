# InputEventMIDI

**Inherits:** InputEvent

Represents a MIDI message from a MIDI device, such as a musical keyboard.

InputEventMIDI stores information about messages from MIDI (Musical Instrument Digital Interface) devices. These may include musical keyboards, synthesizers, and drum machines. MIDI messages can be received over a 5-pin MIDI connector or over USB. If your device supports both be sure to check the settings in the device to see which output it is using.

## Properties

- `channel: int` = `0` — The MIDI channel of this message, ranging from `0` to `15`.
- `controller_number: int` = `0` — The unique number of the controller, if `message` is `MIDI_MESSAGE_CONTROL_CHANGE`, otherwise this is `0`.
- `controller_value: int` = `0` — The value applied to the controller.
- `instrument: int` = `0` — The instrument (also called program or preset) used on this MIDI message.
- `message: MIDIMessage` = `0` — Represents the type of MIDI message (see the `MIDIMessage` enum).
- `pitch: int` = `0` — The pitch index number of this MIDI message.
- `pressure: int` = `0` — The strength of the key being pressed.
- `velocity: int` = `0` — The velocity of the MIDI message.
