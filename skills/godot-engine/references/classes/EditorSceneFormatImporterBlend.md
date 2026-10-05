# EditorSceneFormatImporterBlend

**Inherits:** EditorSceneFormatImporter

Importer for Blender's `.blend` scene file format.

Imports Blender scenes in the `.blend` file format through the glTF 2.0 3D import pipeline. This importer requires Blender to be installed by the user, so that it can be used to export the scene as glTF 2.0. The location of the Blender binary is set via the `EditorSettings.filesystem/import/blender/blender_path` setting. This importer is only used if `ProjectSettings.filesystem/import/blender/enabled` is enabled, otherwise `.blend` files present in the project folder are not imported.
