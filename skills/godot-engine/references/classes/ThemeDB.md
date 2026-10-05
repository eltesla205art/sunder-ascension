# ThemeDB

**Inherits:** Object

A singleton that provides access to static information about Theme resources used by the engine and by your project.

This singleton provides access to static information about Theme resources used by the engine and by your projects. You can fetch the default engine theme, as well as your project configured theme. ThemeDB also contains fallback values for theme properties.

## Properties

- `fallback_base_scale: float` = `1.0` — The fallback base scale factor of every Control node and Theme resource.
- `fallback_font: Font` — The fallback font of every Control node and Theme resource.
- `fallback_font_size: int` = `16` — The fallback font size of every Control node and Theme resource.
- `fallback_icon: Texture2D` — The fallback icon of every Control node and Theme resource.
- `fallback_sound: AudioStream` — The fallback sound of every Control node and Theme resource.
- `fallback_stylebox: StyleBox` — The fallback stylebox of every Control node and Theme resource.

## Methods

- `get_default_theme() -> Theme` — Returns a reference to the default engine Theme.
- `get_project_theme() -> Theme` — Returns a reference to the custom project Theme.

## Signals

- `fallback_changed()` — Emitted when one of the fallback values had been changed.
