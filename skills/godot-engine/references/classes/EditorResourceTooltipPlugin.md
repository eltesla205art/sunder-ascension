# EditorResourceTooltipPlugin

**Inherits:** RefCounted

A plugin that advanced tooltip for its handled resource type.

Resource tooltip plugins are used by FileSystemDock to generate customized tooltips for specific resources. E.g. tooltip for a Texture2D displays a bigger preview and the texture's dimensions. A plugin must be first registered with `FileSystemDock.add_resource_tooltip_plugin`. When the user hovers a resource in filesystem dock which is handled by the plugin, `_make_tooltip_for_path` is called to create the tooltip.

## Methods

- `_handles(type: String) -> bool` *virtual const* — Return `true` if the plugin is going to handle the given Resource `type`.
- `_make_tooltip_for_path(path: String, metadata: Dictionary, base: Control) -> Control` *virtual const* — Create and return a tooltip that will be displayed when the user hovers a resource under the given `path` in filesystem dock.
- `request_thumbnail(path: String, control: TextureRect) -> void` *const* — Requests a thumbnail for the given TextureRect.
