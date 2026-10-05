# TranslationDomain

**Inherits:** RefCounted

A self-contained collection of Translation resources.

TranslationDomain is a self-contained collection of Translation resources. Translations can be added to or removed from it. If you're working with the main translation domain, it is more convenient to use the wrap methods on TranslationServer.

## Properties

- `enabled: bool` = `true` — If `true`, translation is enabled.
- `pseudolocalization_accents_enabled: bool` = `true` — Replace all characters with their accented variants during pseudolocalization.
- `pseudolocalization_double_vowels_enabled: bool` = `false` — Double vowels in strings during pseudolocalization to simulate the lengthening of text due to localization.
- `pseudolocalization_enabled: bool` = `false` — If `true`, enables pseudolocalization for the project.
- `pseudolocalization_expansion_ratio: float` = `0.0` — The expansion ratio to use during pseudolocalization.
- `pseudolocalization_fake_bidi_enabled: bool` = `false` — If `true`, emulate bidirectional (right-to-left) text when pseudolocalization is enabled.
- `pseudolocalization_override_enabled: bool` = `false` — Replace all characters in the string with `*`.
- `pseudolocalization_prefix: String` = `"["` — Prefix that will be prepended to the pseudolocalized string.
- `pseudolocalization_skip_placeholders_enabled: bool` = `true` — Skip placeholders for string formatting like `%s` or `%f` during pseudolocalization.
- `pseudolocalization_suffix: String` = `"]"` — Suffix that will be appended to the pseudolocalized string.

## Methods

- `add_translation(translation: Translation) -> void` — Adds a translation.
- `clear() -> void` — Removes all translations.
- `find_translations(locale: String, exact: bool) -> Translation[]` *const* — Returns the Translation instances that match `locale` (see `TranslationServer.compare_locales`).
- `get_locale_override() -> String` *const* — Returns the locale override of the domain.
- `get_translation_object(locale: String) -> Translation` *const* *(deprecated)* — Returns the Translation instance that best matches `locale`.
- `get_translations() -> Translation[]` *const* — Returns all available Translation instances as added by `add_translation`.
- `has_translation(translation: Translation) -> bool` *const* — Returns `true` if this translation domain contains the given `translation`.
- `has_translation_for_locale(locale: String, exact: bool) -> bool` *const* — Returns `true` if there are any Translation instances that match `locale` (see `TranslationServer.compare_locales`).
- `pseudolocalize(message: StringName) -> StringName` *const* — Returns the pseudolocalized string based on the `message` passed in.
- `remove_translation(translation: Translation) -> void` — Removes the given translation.
- `set_locale_override(locale: String) -> void` — Sets the locale override of the domain.
- `translate(message: StringName, context: StringName = &"") -> StringName` *const* — Returns the current locale's translation for the given message and context.
- `translate_plural(message: StringName, message_plural: StringName, n: int, context: StringName = &"") -> StringName` *const* — Returns the current locale's translation for the given message, plural message and context.
