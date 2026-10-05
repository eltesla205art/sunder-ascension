# EditorResourceConversionPlugin

**Inherits:** RefCounted

Plugin for adding custom converters from one resource format to another in the editor resource picker context menu; for example, converting a StandardMaterial3D to a ShaderMaterial.

EditorResourceConversionPlugin is invoked when the context menu is brought up for a resource in the editor inspector. Relevant conversion plugins will appear as menu options to convert the given resource to a target type. Below shows an example of a basic plugin that will convert an ImageTexture to a PortableCompressedTexture2D. To use an EditorResourceConversionPlugin, register it using the `EditorPlugin.add_resource_conversion_plugin` method first.

## Methods

- `_convert(resource: Resource) -> Resource` *virtual const* — Takes an input Resource and converts it to the type given in `_converts_to`.
- `_converts_to() -> String` *virtual const* — Returns the class name of the target type of Resource that this plugin converts source resources to.
- `_handles(resource: Resource) -> bool` *virtual const* — Called to determine whether a particular Resource can be converted to the target resource type by this plugin.
