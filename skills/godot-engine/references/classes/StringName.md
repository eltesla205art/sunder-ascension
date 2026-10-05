# StringName


A built-in type for unique strings.

StringNames are immutable strings designed for general-purpose representation of unique names (also called "string interning"). Two StringNames with the same value are the same object. Comparing them is extremely fast compared to regular Strings. You will usually pass a String to methods expecting a StringName and it will be automatically converted (often at compile time), but in rare cases you can construct a StringName ahead of time with the StringName constructor or, in GDScript, the literal syntax `&"example"`.

## Constructors

- `StringName() -> StringName` — Constructs an empty StringName.
- `StringName(from: StringName) -> StringName` — Constructs a StringName as a copy of the given StringName.
- `StringName(from: String) -> StringName` — Creates a new StringName from the given String.

## Methods

- `begins_with(text: String) -> bool` *const* — Returns `true` if the string begins with the given `text`.
- `bigrams() -> PackedStringArray` *const* — Returns an array containing the bigrams (pairs of consecutive characters) of this string.
- `bin_to_int() -> int` *const* — Converts the string representing a binary number into an int.
- `c_escape() -> String` *const* — Returns a copy of the string with special characters escaped using the C language standard.
- `c_unescape() -> String` *const* — Returns a copy of the string with escaped characters replaced by their meanings.
- `capitalize() -> String` *const* — Changes the appearance of the string: replaces underscores (`_`) with spaces, adds spaces before uppercase letters in the middle of a word, converts all letters to lowercase, then converts the first one and each one following a space to uppercase.
- `casecmp_to(to: String) -> int` *const* — Performs a case-sensitive comparison to another string.
- `contains(what: String) -> bool` *const* — Returns `true` if the string contains `what`.
- `containsn(what: String) -> bool` *const* — Returns `true` if the string contains `what`, ignoring case.
- `count(what: String, from: int = 0, to: int = 0) -> int` *const* — Returns the number of occurrences of the substring `what` between `from` and `to` positions.
- `countn(what: String, from: int = 0, to: int = 0) -> int` *const* — Returns the number of occurrences of the substring `what` between `from` and `to` positions, ignoring case.
- `dedent() -> String` *const* — Returns a copy of the string with indentation (leading tabs and spaces) removed.
- `ends_with(text: String) -> bool` *const* — Returns `true` if the string ends with the given `text`.
- `erase(position: int, chars: int = 1) -> String` *const* — Returns a string with `chars` characters erased starting from `position`.
- `filecasecmp_to(to: String) -> int` *const* — Like `naturalcasecmp_to` but prioritizes strings that begin with periods (`.`) and underscores (`_`) before any other character.
- `filenocasecmp_to(to: String) -> int` *const* — Like `naturalnocasecmp_to` but prioritizes strings that begin with periods (`.`) and underscores (`_`) before any other character.
- `find(what: String, from: int = 0) -> int` *const* — Returns the index of the first occurrence of `what` in this string, or `-1` if there are none.
- `findn(what: String, from: int = 0) -> int` *const* — Returns the index of the first case-insensitive occurrence of `what` in this string, or `-1` if there are none.
- `format(values: Variant, placeholder: String = "{_}") -> String` *const* — Formats the string by replacing all occurrences of `placeholder` with the elements of `values`.
- `get_base_dir() -> String` *const* — If the string is a valid file path, returns the base directory name.
- `get_basename() -> String` *const* — If the string is a valid file path, returns the full file path, without the extension.
- `get_extension() -> String` *const* — If the string is a valid file name or path, returns the file extension without the leading period (`.`).
- `get_file() -> String` *const* — If the string is a valid file path, returns the file name, including the extension.
- `get_slice(delimiter: String, slice: int) -> String` *const* — Splits the string using a `delimiter` and returns the substring at index `slice`.
- `get_slice_count(delimiter: String) -> int` *const* — Returns the total number of slices when the string is split with the given `delimiter` (see `split`).
- `get_slicec(delimiter: int, slice: int) -> String` *const* — Splits the string using a Unicode character with code `delimiter` and returns the substring at index `slice`.
- `hash() -> int` *const* — Returns the 32-bit hash value representing the string's contents.
- `hex_decode() -> PackedByteArray` *const* — Decodes a hexadecimal string as a PackedByteArray.
- `hex_to_int() -> int` *const* — Converts the string representing a hexadecimal number into an int.
- `indent(prefix: String) -> String` *const* — Indents every line of the string with the given `prefix`.
- `insert(position: int, what: String) -> String` *const* — Inserts `what` at the given `position` in the string.
- `is_absolute_path() -> bool` *const* — Returns `true` if the string is a path to a file or directory, and its starting point is explicitly defined.
- `is_empty() -> bool` *const* — Returns `true` if the string's length is `0` (`""`).
- `is_relative_path() -> bool` *const* — Returns `true` if the string is a path, and its starting point is dependent on context.
- `is_subsequence_of(text: String) -> bool` *const* — Returns `true` if all characters of this string can be found in `text` in their original order.
- `is_subsequence_ofn(text: String) -> bool` *const* — Returns `true` if all characters of this string can be found in `text` in their original order, ignoring case.
- `is_valid_ascii_identifier() -> bool` *const* — Returns `true` if this string is a valid ASCII identifier.
- `is_valid_filename() -> bool` *const* — Returns `true` if this string is a valid file name.
- `is_valid_float() -> bool` *const* — Returns `true` if this string represents a valid floating-point number.
- `is_valid_hex_number(with_prefix: bool = false) -> bool` *const* — Returns `true` if this string is a valid hexadecimal number.
- `is_valid_html_color() -> bool` *const* — Returns `true` if this string is a valid color in hexadecimal HTML notation.
- `is_valid_identifier() -> bool` *const* *(deprecated)* — Returns `true` if this string is a valid identifier.
- `is_valid_int() -> bool` *const* — Returns `true` if this string represents a valid integer.
- `is_valid_ip_address() -> bool` *const* — Returns `true` if this string represents a well-formatted IPv4 or IPv6 address.
- `is_valid_unicode_identifier() -> bool` *const* — Returns `true` if this string is a valid Unicode identifier.
- `join(parts: PackedStringArray) -> String` *const* — Returns the concatenation of `parts`' elements, with each element separated by the string calling this method.
- `json_escape() -> String` *const* — Returns a copy of the string with special characters escaped using the JSON standard.
- `left(length: int) -> String` *const* — Returns the first `length` characters from the beginning of the string.
- `length() -> int` *const* — Returns the number of characters in the string.
- `lpad(min_length: int, character: String = " ") -> String` *const* — Formats the string to be at least `min_length` long by adding `character`s to the left of the string, if necessary.
- `lstrip(chars: String) -> String` *const* — Removes a set of characters defined in `chars` from the string's beginning.
- `match(expr: String) -> bool` *const* — Does a simple expression match (also called "glob" or "globbing"), where `*` matches zero or more arbitrary characters and `?` matches any single character except a period (`.`).
- `matchn(expr: String) -> bool` *const* — Does a simple case-insensitive expression match, where `*` matches zero or more arbitrary characters and `?` matches any single character except a period (`.`).
- `md5_buffer() -> PackedByteArray` *const* — Returns the MD5 hash of the string as a PackedByteArray.
- `md5_text() -> String` *const* — Returns the MD5 hash of the string as another String.
- `naturalcasecmp_to(to: String) -> int` *const* — Performs a case-sensitive, natural order comparison to another string.
- `naturalnocasecmp_to(to: String) -> int` *const* — Performs a case-insensitive, natural order comparison to another string.
- `nocasecmp_to(to: String) -> int` *const* — Performs a case-insensitive comparison to another string.
- `pad_decimals(digits: int) -> String` *const* — Formats the string representing a number to have an exact number of `digits` after the decimal point.
- `pad_zeros(digits: int) -> String` *const* — Formats the string representing a number to have an exact number of `digits` before the decimal point.
- `path_join(path: String) -> String` *const* — Concatenates `path` at the end of the string as a subpath, adding `/` if necessary.
- `remove_char(what: int) -> String` *const* — Removes all occurrences of the Unicode character with code `what`.
- `remove_chars(chars: String) -> String` *const* — Removes all occurrences of the characters in `chars`.
- `repeat(count: int) -> String` *const* — Repeats this string a number of times.
- `replace(what: String, forwhat: String) -> String` *const* — Replaces all occurrences of `what` inside the string with the given `forwhat`.
- `replace_char(key: int, with: int) -> String` *const* — Replaces all occurrences of the Unicode character with code `key` with the Unicode character with code `with`.
- `replace_chars(keys: String, with: int) -> String` *const* — Replaces any occurrence of the characters in `keys` with the Unicode character with code `with`.
- `replacen(what: String, forwhat: String) -> String` *const* — Replaces all case-insensitive occurrences of `what` inside the string with the given `forwhat`.
- `reverse() -> String` *const* — Returns the copy of this string in reverse order.
- `rfind(what: String, from: int = -1) -> int` *const* — Returns the index of the last occurrence of `what` in this string, or `-1` if there are none.
- `rfindn(what: String, from: int = -1) -> int` *const* — Returns the index of the last case-insensitive occurrence of `what` in this string, or `-1` if there are none.
- `right(length: int) -> String` *const* — Returns the last `length` characters from the end of the string.
- `rpad(min_length: int, character: String = " ") -> String` *const* — Formats the string to be at least `min_length` long, by adding `character`s to the right of the string, if necessary.
- `rsplit(delimiter: String = "", allow_empty: bool = true, maxsplit: int = 0) -> PackedStringArray` *const* — Splits the string using a `delimiter` and returns an array of the substrings, starting from the end of the string.
- `rstrip(chars: String) -> String` *const* — Removes a set of characters defined in `chars` from the string's end.
- `sha1_buffer() -> PackedByteArray` *const* — Returns the SHA-1 hash of the string as a PackedByteArray.
- `sha1_text() -> String` *const* — Returns the SHA-1 hash of the string as another String.
- `sha256_buffer() -> PackedByteArray` *const* — Returns the SHA-256 hash of the string as a PackedByteArray.
- `sha256_text() -> String` *const* — Returns the SHA-256 hash of the string as another String.
- `similarity(text: String) -> float` *const* — Returns the similarity index (Sørensen-Dice coefficient) of this string compared to another.
- `simplify_path() -> String` *const* — If the string is a valid file path, converts the string into a canonical path.
- `split(delimiter: String = "", allow_empty: bool = true, maxsplit: int = 0) -> PackedStringArray` *const* — Splits the string using a `delimiter` and returns an array of the substrings.
- `split_floats(delimiter: String, allow_empty: bool = true) -> PackedFloat64Array` *const* — Splits the string into floats by using a `delimiter` and returns a PackedFloat64Array.
- `strip_edges(left: bool = true, right: bool = true) -> String` *const* — Strips all non-printable characters from the beginning and the end of the string.
- `strip_escapes() -> String` *const* — Strips all escape characters from the string.
- `substr(from: int, len: int = -1) -> String` *const* — Returns part of the string from the position `from` with length `len`.
- `to_ascii_buffer() -> PackedByteArray` *const* — Converts the string to an ASCII/Latin-1 encoded PackedByteArray.
- `to_camel_case() -> String` *const* — Returns the string converted to `camelCase`.
- `to_float() -> float` *const* — Converts the string representing a decimal number into a float.
- `to_int() -> int` *const* — Converts the string representing an integer number into an int.
- `to_kebab_case() -> String` *const* — Returns the string converted to `kebab-case`.
- `to_lower() -> String` *const* — Returns the string converted to `lowercase`.
- `to_multibyte_char_buffer(encoding: String = "") -> PackedByteArray` *const* — Converts the string to system multibyte code page encoded PackedByteArray.
- `to_pascal_case() -> String` *const* — Returns the string converted to `PascalCase`.
- `to_snake_case() -> String` *const* — Returns the string converted to `snake_case`.
- `to_upper() -> String` *const* — Returns the string converted to `UPPERCASE`.
- `to_utf8_buffer() -> PackedByteArray` *const* — Converts the string to a UTF-8 encoded PackedByteArray.
- `to_utf16_buffer() -> PackedByteArray` *const* — Converts the string to a UTF-16 encoded PackedByteArray.
- `to_utf32_buffer() -> PackedByteArray` *const* — Converts the string to a UTF-32 encoded PackedByteArray.
- `to_wchar_buffer() -> PackedByteArray` *const* — Converts the string to a wide character (`wchar_t`, UTF-16 on Windows, UTF-32 on other platforms) encoded PackedByteArray.
- `trim_prefix(prefix: String) -> String` *const* — Removes the given `prefix` from the start of the string, or returns the string unchanged.
- `trim_suffix(suffix: String) -> String` *const* — Removes the given `suffix` from the end of the string, or returns the string unchanged.
- `unicode_at(at: int) -> int` *const* — Returns the character code at position `at`.
- `uri_decode() -> String` *const* — Decodes the string from its URL-encoded format.
- `uri_encode() -> String` *const* — Encodes the string to URL-friendly format.
- `uri_file_decode() -> String` *const* — Decodes the file path from its URL-encoded format.
- `validate_filename() -> String` *const* — Returns a copy of the string with all characters that are not allowed in `is_valid_filename` replaced with underscores.
- `validate_node_name() -> String` *const* — Returns a copy of the string with all characters that are not allowed in `Node.name` (`.` `:` `@` `/` `"` `%`) replaced with underscores.
- `xml_escape(escape_quotes: bool = false) -> String` *const* — Returns a copy of the string with special characters escaped using the XML standard.
- `xml_unescape() -> String` *const* — Returns a copy of the string with escaped characters replaced by their meanings according to the XML standard.

## Operators

- `operator !=(right: String) -> bool` — Returns `true` if this StringName is not equivalent to the given String.
- `operator !=(right: StringName) -> bool` — Returns `true` if the StringName and `right` do not refer to the same name.
- `operator %(right: Variant) -> String` — Formats the StringName, replacing the placeholders with one or more parameters, returning a String.
- `operator +(right: String) -> String` — Appends `right` at the end of this StringName, returning a String.
- `operator +(right: StringName) -> String` — Appends `right` at the end of this StringName, returning a String.
- `operator <(right: StringName) -> bool` — Returns `true` if the left StringName's pointer comes before `right`.
- `operator <=(right: StringName) -> bool` — Returns `true` if the left StringName's pointer comes before `right` or if they are the same.
- `operator ==(right: String) -> bool` — Returns `true` if this StringName is equivalent to the given String.
- `operator ==(right: StringName) -> bool` — Returns `true` if the StringName and `right` refer to the same name.
- `operator >(right: StringName) -> bool` — Returns `true` if the left StringName's pointer comes after `right`.
- `operator >=(right: StringName) -> bool` — Returns `true` if the left StringName's pointer comes after `right` or if they are the same.
