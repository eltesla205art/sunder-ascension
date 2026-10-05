# EditorExportPlugin

**Inherits:** RefCounted

A script that is executed when exporting the project.

EditorExportPlugins are automatically invoked whenever the user exports the project. They can be used to modify scenes and resources during project export based on what Feature Tags are set. For each plugin, `_export_begin` is called at the beginning of the export process and then `_export_file` is called for each exported file. Register a EditorExportPlugin by creating a new EditorPlugin and calling its `EditorPlugin.add_export_plugin` method.

## Methods

- `_begin_customize_resources(platform: EditorExportPlatform, features: PackedStringArray) -> bool` *virtual const* — Return `true` if this plugin will customize resources based on the platform and features used.
- `_begin_customize_scenes(platform: EditorExportPlatform, features: PackedStringArray) -> bool` *virtual const* — Return `true` if this plugin will customize scenes based on the platform and features used.
- `_customize_resource(resource: Resource, path: String) -> Resource` *virtual required* — Customize a resource.
- `_customize_scene(scene: Node, path: String) -> Node` *virtual required* — Customize a scene.
- `_end_customize_resources() -> void` *virtual* — This is called when the customization process for resources ends.
- `_end_customize_scenes() -> void` *virtual* — This is called when the customization process for scenes ends.
- `_end_generate_apple_embedded_project(path: String, will_build_archive: bool) -> void` *virtual* — This is called after Xcode project generation, but before it is built.
- `_export_begin(features: PackedStringArray, is_debug: bool, path: String, flags: int) -> void` *virtual* — Virtual method to be overridden by the user.
- `_export_end() -> void` *virtual* — Virtual method to be overridden by the user.
- `_export_file(path: String, type: String, features: PackedStringArray) -> void` *virtual* — Virtual method to be overridden by the user.
- `_get_android_dependencies(platform: EditorExportPlatform, debug: bool) -> PackedStringArray` *virtual const* — Virtual method to be overridden by the user.
- `_get_android_dependencies_maven_repos(platform: EditorExportPlatform, debug: bool) -> PackedStringArray` *virtual const* — Virtual method to be overridden by the user.
- `_get_android_libraries(platform: EditorExportPlatform, debug: bool) -> PackedStringArray` *virtual const* — Virtual method to be overridden by the user.
- `_get_android_manifest_activity_element_contents(platform: EditorExportPlatform, debug: bool) -> String` *virtual const* — Virtual method to be overridden by the user.
- `_get_android_manifest_application_element_contents(platform: EditorExportPlatform, debug: bool) -> String` *virtual const* — Virtual method to be overridden by the user.
- `_get_android_manifest_element_contents(platform: EditorExportPlatform, debug: bool) -> String` *virtual const* — Virtual method to be overridden by the user.
- `_get_customization_configuration_hash() -> int` *virtual required const* — Return a hash based on the configuration passed (for both scenes and resources).
- `_get_export_features(platform: EditorExportPlatform, debug: bool) -> PackedStringArray` *virtual const* — Return a PackedStringArray of additional features this preset, for the given `platform`, should have.
- `_get_export_option_visibility(platform: EditorExportPlatform, option: String) -> bool` *virtual const* — Validates `option` and returns the visibility for the specified `platform`.
- `_get_export_option_warning(platform: EditorExportPlatform, option: String) -> String` *virtual const* — Check the requirements for the given `option` and return a non-empty warning string if they are not met.
- `_get_export_options(platform: EditorExportPlatform) -> Dictionary[]` *virtual const* — Return a list of export options that can be configured for this export plugin.
- `_get_export_options_overrides(platform: EditorExportPlatform) -> Dictionary` *virtual const* — Return a Dictionary of override values for export options, that will be used instead of user-provided values.
- `_get_name() -> String` *virtual required const* — Return the name identifier of this plugin (for future identification by the exporter).
- `_should_update_export_options(platform: EditorExportPlatform) -> bool` *virtual const* — Return `true` if the result of `_get_export_options` has changed and the export options of the preset corresponding to `platform` should be updated.
- `_supports_platform(platform: EditorExportPlatform) -> bool` *virtual const* — Return `true` if the plugin supports the given `platform`.
- `_update_android_prebuilt_manifest(platform: EditorExportPlatform, manifest_data: PackedByteArray) -> PackedByteArray` *virtual const* — Provide access to the Android prebuilt manifest and allows the plugin to modify it if needed.
- `add_apple_embedded_platform_bundle_file(path: String) -> void` — Adds an Apple embedded platform bundle file from the given `path` to the exported project.
- `add_apple_embedded_platform_cpp_code(code: String) -> void` — Adds C++ code to the Apple embedded platform export.
- `add_apple_embedded_platform_embedded_framework(path: String) -> void` — Adds a dynamic library (*.dylib, *.framework) to the Linking Phase in the Apple embedded platform's Xcode project and embeds it into the resulting binary.
- `add_apple_embedded_platform_framework(path: String) -> void` — Adds a static library (*.a) or a dynamic library (*.dylib, *.framework) to the Linking Phase to the Apple embedded platform's Xcode project.
- `add_apple_embedded_platform_linker_flags(flags: String) -> void` — Adds linker flags for the Apple embedded platform export.
- `add_apple_embedded_platform_plist_content(plist_content: String) -> void` — Adds additional fields to the Apple embedded platform's project Info.plist file.
- `add_apple_embedded_platform_project_static_lib(path: String) -> void` — Adds a static library from the given `path` to the Apple embedded platform project.
- `add_apple_embedded_platform_spm_package(url: String, version: String, products: PackedStringArray) -> void` — Adds a Swift Package Manager package to the Apple embedded platform's Xcode project.
- `add_file(path: String, file: PackedByteArray, remap: bool) -> void` — Adds a custom file to be exported.
- `add_ios_bundle_file(path: String) -> void` *(deprecated)* — Adds an iOS bundle file from the given `path` to the exported project.
- `add_ios_cpp_code(code: String) -> void` *(deprecated)* — Adds C++ code to the iOS export.
- `add_ios_embedded_framework(path: String) -> void` *(deprecated)* — Adds a dynamic library (*.dylib, *.framework) to Linking Phase in iOS's Xcode project and embeds it into resulting binary.
- `add_ios_framework(path: String) -> void` *(deprecated)* — Adds a static library (*.a) or a dynamic library (*.dylib, *.framework) to the Linking Phase to the iOS Xcode project.
- `add_ios_linker_flags(flags: String) -> void` *(deprecated)* — Adds linker flags for the iOS export.
- `add_ios_plist_content(plist_content: String) -> void` *(deprecated)* — Adds additional fields to the iOS project Info.plist file.
- `add_ios_project_static_lib(path: String) -> void` *(deprecated)* — Adds a static library from the given `path` to the iOS project.
- `add_macos_plugin_file(path: String) -> void` — Adds file or directory matching `path` to `PlugIns` directory of macOS app bundle.
- `add_shared_object(path: String, tags: PackedStringArray, target: String) -> void` — Adds a shared object or a directory containing only shared objects with the given `tags` and destination `path`.
- `get_export_platform() -> EditorExportPlatform` *const* — Returns currently used export platform.
- `get_export_preset() -> EditorExportPreset` *const* — Returns currently used export preset.
- `get_option(name: StringName) -> Variant` *const* — Returns the current value of an export option supplied by `_get_export_options`.
- `skip() -> void` — To be called inside `_export_file`.
