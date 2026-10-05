# OggPacketSequence

**Inherits:** Resource

A sequence of Ogg packets.

A sequence of Ogg packets.

## Properties

- `granule_positions: PackedInt64Array` = `PackedInt64Array()` — Contains the granule positions for each page in this packet sequence.
- `packet_data: Array[]` = `[]` — Contains the raw packets that make up this OggPacketSequence.
- `sampling_rate: float` = `0.0` — Holds sample rate information about this sequence.

## Methods

- `get_length() -> float` *const* — The length of this stream, in seconds.
