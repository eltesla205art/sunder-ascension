# MissingNode

**Inherits:** Node

An internal editor class intended for keeping the data of unrecognized nodes.

This is an internal editor class intended for keeping data of nodes of unknown type (most likely this type was supplied by an extension that is no longer loaded). It can't be manually instantiated or placed in a scene. Warning: Ignore missing nodes unless you know what you are doing. Existing properties on a missing node can be freely modified in code, regardless of the type they are intended to be.

## Properties

- `original_class: String` — The name of the class this node was supposed to be (see `Object.get_class`).
- `original_scene: String` — Returns the path of the scene this node was instance of originally.
- `recording_properties: bool` — If `true`, allows new properties to be set along with existing ones.
- `recording_signals: bool` — If `true`, allows new signals to be connected to along with existing ones.
