# EditorResourcePreview

**Inherits:** Node

A node used to generate previews of resources or files.

This node is used to generate previews for resources or files. Note: This class shouldn't be instantiated directly. Instead, access the singleton using `EditorInterface.get_resource_previewer`.

## Methods

- `add_preview_generator(generator: EditorResourcePreviewGenerator) -> void` — Create an own, custom preview generator.
- `check_for_invalidation(path: String) -> void` — Check if the resource changed, if so, it will be invalidated and the corresponding signal emitted.
- `queue_edited_resource_preview(resource: Resource, receiver: Object, receiver_func: StringName, userdata: Variant) -> void` — Queue the `resource` being edited for preview.
- `queue_resource_preview(path: String, receiver: Object, receiver_func: StringName, userdata: Variant) -> void` — Queue a resource file located at `path` for preview.
- `remove_preview_generator(generator: EditorResourcePreviewGenerator) -> void` — Removes a custom preview generator.

## Signals

- `preview_invalidated(path: String)` — Emitted if a preview was invalidated (changed).
