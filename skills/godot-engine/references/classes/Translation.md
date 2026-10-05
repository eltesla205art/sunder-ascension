# Translation

**Inherits:** Resource

A language translation that maps a collection of strings to their individual translations.

Translation maps a collection of strings to their individual translations, and also provides convenience methods for pluralization. A Translation consists of messages. A message is identified by its context and untranslated string. Unlike gettext, using an empty context string in Godot means not using any context.

## Properties

- `locale: String` = `"en"` — The locale of the translation.
- `plural_rules_override: String` = `""` — The plural rules string to enforce.

## Methods

- `_get_message(src_message: StringName, context: StringName) -> StringName` *virtual const* — Virtual method to override `get_message`.
- `_get_plural_message(src_message: StringName, src_plural_message: StringName, n: int, context: StringName) -> StringName` *virtual const* — Virtual method to override `get_plural_message`.
- `add_message(src_message: StringName, xlated_message: StringName, context: StringName = &"") -> void` — Adds a message if nonexistent, followed by its translation.
- `add_plural_message(src_message: StringName, xlated_messages: PackedStringArray, context: StringName = &"") -> void` — Adds a message involving plural translation if nonexistent, followed by its translation.
- `erase_message(src_message: StringName, context: StringName = &"") -> void` — Erases a message.
- `get_message(src_message: StringName, context: StringName = &"") -> StringName` *const* — Returns a message's translation.
- `get_message_count() -> int` *const* — Returns the number of existing messages.
- `get_message_list() -> PackedStringArray` *const* — Returns the keys of all messages, that is, the context and untranslated strings of each message.
- `get_plural_message(src_message: StringName, src_plural_message: StringName, n: int, context: StringName = &"") -> StringName` *const* — Returns a message's translation involving plurals.
- `get_translated_message_list() -> PackedStringArray` *const* — Returns all the translated strings.
