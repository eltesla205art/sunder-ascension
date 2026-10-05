# FuzzySearch

**Inherits:** RefCounted

Provides fuzzy string searching and matching capabilities.

The fuzzy search algorithm is designed to find target strings which mostly match a query string while allowing for breaks, typos, and out of order matches.

## Properties

- `case_sensitive: bool` = `false` — Whether the query character casing should be matched exactly or not.
- `filter_cutoff: float` = `30.0` — Minimum score for filtering results returned by `search_all`.
- `filter_factor: float` = `0.1` — Biases the filtering cutoff score between the average score and max score.
- `filter_low_scores: bool` = `true` — If `true`, lower quality matches are not returned by `search_all`.
- `max_misses: int` = `2` — Maximum number of non-matched characters in the query before skipping a target as non-matching.
- `max_results: int` = `100` — Maximum number of results which can be returned by `search_all`.
- `start_offset: int` = `0` — Number of leading characters to omit from matching.
- `use_exact_tokens: bool` = `false` — If `true`, only targets which contain each token as a non-overlapping substring are returned.

## Methods

- `search(query: String, target: String) -> FuzzySearchMatch` *const* — Searches the `target` for `query`, returning a FuzzySearchMatch instance on success or `null` otherwise.
- `search_all(query: String, targets: PackedStringArray) -> FuzzySearchMatch[]` *const* — Searches all of `targets` for `query` and returns up to the top `max_results` scoring values.
