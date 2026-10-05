# TranslationServer

**Inherits:** Object

The server responsible for language translations.

The translation server is the API backend that manages all language translations. Translations are stored in TranslationDomains, which can be accessed by name. The most commonly used translation domain is the main translation domain. It always exists and can be accessed using an empty StringName.

## Properties

- `pseudolocalization_enabled: bool` = `false` — If `true`, enables the use of pseudolocalization on the main translation domain.

## Methods

- `add_translation(translation: Translation) -> void` — Adds a translation to the main translation domain.
- `clear() -> void` — Removes all translations from the main translation domain.
- `compare_locales(locale_a: String, locale_b: String) -> int` *const* — Compares two locales and returns a similarity score between `0` (no match) and `10` (full match).
- `find_translations(locale: String, exact: bool) -> Translation[]` *const* — Returns the Translation instances in the main translation domain that match `locale` (see `compare_locales`).
- `format_number(number: String, locale: String) -> String` *const* — Converts a number from Western Arabic (0..9) to the numeral system used in the given `locale`.
- `get_all_countries() -> PackedStringArray` *const* — Returns an array of known country codes.
- `get_all_languages() -> PackedStringArray` *const* — Returns array of known language codes.
- `get_all_scripts() -> PackedStringArray` *const* — Returns an array of known script codes.
- `get_country_name(country: String) -> String` *const* — Returns a readable country name for the `country` code.
- `get_language_name(language: String) -> String` *const* — Returns a readable language name for the `language` code.
- `get_loaded_locales() -> PackedStringArray` *const* — Returns an array of all loaded locales of the project.
- `get_locale() -> String` *const* — Returns the current locale of the project.
- `get_locale_name(locale: String) -> String` *const* — Returns a locale's language and its variant (e.g.
- `get_or_add_domain(domain: StringName) -> TranslationDomain` — Returns the translation domain with the specified name.
- `get_percent_sign(locale: String) -> String` *const* — Returns the percent sign used in the given `locale`.
- `get_plural_rules(locale: String) -> String` *const* — Returns the default plural rules for the `locale`.
- `get_script_name(script: String) -> String` *const* — Returns a readable script name for the `script` code.
- `get_tool_locale() -> String` — Returns the current locale of the editor.
- `get_translation_object(locale: String) -> Translation` *(deprecated)* — Returns the Translation instance that best matches `locale` in the main translation domain.
- `get_translations() -> Translation[]` *const* — Returns all available Translation instances in the main translation domain as added by `add_translation`.
- `has_domain(domain: StringName) -> bool` *const* — Returns `true` if a translation domain with the specified name exists.
- `has_translation(translation: Translation) -> bool` *const* — Returns `true` if the main translation domain contains the given `translation`.
- `has_translation_for_locale(locale: String, exact: bool) -> bool` *const* — Returns `true` if there are any Translation instances in the main translation domain that match `locale` (see `compare_locales`).
- `parse_number(number: String, locale: String) -> String` *const* — Converts `number` from the numeral system used in the given `locale` to Western Arabic (0..9).
- `pseudolocalize(message: StringName) -> StringName` *const* — Returns the pseudolocalized string based on the `message` passed in.
- `reload_pseudolocalization() -> void` — Reparses the pseudolocalization options and reloads the translation for the main translation domain.
- `remove_domain(domain: StringName) -> void` — Removes the translation domain with the specified name.
- `remove_translation(translation: Translation) -> void` — Removes the given translation from the main translation domain.
- `set_locale(locale: String) -> void` — Sets the locale of the project.
- `standardize_locale(locale: String, add_defaults: bool = false) -> String` *const* — Returns a `locale` string standardized to match known locales (e.g.
- `translate(message: StringName, context: StringName = &"") -> StringName` *const* — Returns the current locale's translation for the given message and context.
- `translate_plural(message: StringName, plural_message: StringName, n: int, context: StringName = &"") -> StringName` *const* — Returns the current locale's translation for the given message, plural message and context.
