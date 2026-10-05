# ResourceImporterCSVTranslation

**Inherits:** ResourceImporter

Imports comma-separated values as Translations.

Comma-separated values are a plain text table storage format. The format's simplicity makes it easy to edit in any text editor or spreadsheet software. This makes it a common choice for game localization. In the CSV file used for translation, the first column contains string identifiers, and the first row serves as the header.

## Properties

- `compress: int` = `1` — - Disabled: Creates a Translation. - Auto: Creates an OptimizedTranslation when possible.
- `delimiter: int` = `0` — The delimiter to use in the CSV file.
- `unescape_keys: bool` = `false` — If `true`, message keys in the CSV file are unescaped using `String.c_unescape` during the import process.
- `unescape_translations: bool` = `true` — If `true`, message translations in the CSV file are unescaped using `String.c_unescape` during the import process.
