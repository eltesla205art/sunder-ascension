# TextServerFallback

**Inherits:** TextServerExtension

A fallback implementation of Godot's text server, without support for BiDi and complex text layout.

A fallback implementation of Godot's text server. This fallback is faster than TextServerAdvanced for processing a lot of text, but it does not support BiDi and complex text layout. Note: This text server is not part of official Godot binaries. If you want to use it, compile the engine with the option `module_text_server_fb_enabled=yes`.
