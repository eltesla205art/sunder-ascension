# AudioEffect

**Inherits:** Resource

Base class for audio effect resources.

The base Resource for every audio effect. In the editor, an audio effect can be added to the current bus layout through the Audio panel. At run-time, it is also possible to manipulate audio effects through `AudioServer.add_bus_effect`, `AudioServer.remove_bus_effect`, and `AudioServer.get_bus_effect`. When applied on a bus, an audio effect creates a corresponding AudioEffectInstance.

## Methods

- `_instantiate() -> AudioEffectInstance` *virtual required* — Override this method to customize the AudioEffectInstance created when this effect is applied on a bus in the editor's Audio panel, or through `AudioServer.add_bus_effect`.
