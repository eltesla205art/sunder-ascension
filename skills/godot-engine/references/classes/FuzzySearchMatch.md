# FuzzySearchMatch

**Inherits:** RefCounted

Result returned by FuzzySearch containing match information.



## Properties

- `original_index: int` = `-1` — The original index of `target` in the provided array of targets when using `FuzzySearch.search_all` otherwise `-1`.
- `score: int` = `0` — Match score determined by FuzzySearch.
- `target: String` = `""` — Target string which was matched against.

## Methods

- `get_matched_substrings() -> Vector2i[]` *const* — Returns each matched substring interval of `target`.
