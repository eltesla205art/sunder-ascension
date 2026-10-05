# EditorTranslationParserPlugin

**Inherits:** RefCounted

Plugin for adding custom parsers to extract strings that are to be translated from custom files (.csv, .json etc.).

EditorTranslationParserPlugin is invoked when a file is being parsed to extract strings that require translation. To define the parsing and string extraction logic, override the `_parse_file` method in script. The return value should be an Array of PackedStringArrays, one for each extracted translatable string. Each entry should contain `[msgid, msgctxt, msgid_plural, comment, source_line]`, where all except `msgid` are optional.

## Methods

- `_customize_strings(strings: PackedStringArray[]) -> PackedStringArray[]` *virtual const* — Called after parsing all files.
- `_get_recognized_extensions() -> PackedStringArray` *virtual const* — Gets the list of file extensions to associate with this parser, e.g.
- `_parse_file(path: String) -> PackedStringArray[]` *virtual* — Override this method to define a custom parsing logic to extract the translatable strings.
