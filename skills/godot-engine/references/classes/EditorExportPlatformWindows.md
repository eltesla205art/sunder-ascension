# EditorExportPlatformWindows

**Inherits:** EditorExportPlatformPC

Exporter for Windows.

The Windows exporter customizes how a Windows build is handled. In the editor's "Export" window, it is created when adding a new "Windows" preset.

## Properties

- `application/company_name: String` — Company that produced the application.
- `application/console_wrapper_icon: String` — Console wrapper icon file.
- `application/copyright: String` — Copyright notice for the bundle visible to the user.
- `application/d3d12_agility_sdk_multiarch: bool` — If `true`, and `application/export_d3d12` is set, the Agility SDK DLLs will be stored in arch-specific subdirectories.
- `application/export_angle: int` — If set to `1`, ANGLE libraries are exported with the exported application.
- `application/export_d3d12: int` — If set to `1`, the Direct3D 12 runtime libraries (Agility SDK, PIX) are exported with the exported application.
- `application/file_description: String` — File description to be presented to users.
- `application/file_version: String` — Version number of the file.
- `application/icon: String` — Application icon file.
- `application/icon_interpolation: int` — Interpolation method used to resize application icon.
- `application/modify_resources: bool` — If enabled, icon and metadata of the exported executable is set according to the other `application/*` values.
- `application/product_name: String` — Name of the application.
- `application/product_version: String` — Application version visible to the user.
- `application/trademarks: String` — Trademarks and registered trademarks that apply to the file.
- `binary_format/architecture: String` — Application executable architecture.
- `binary_format/embed_pck: bool` — If `true`, project resources are embedded into the executable.
- `codesign/custom_options: PackedStringArray` — Array of the additional command line arguments passed to the code signing tool.
- `codesign/description: String` — Description of the signed content.
- `codesign/digest_algorithm: int` — Digest algorithm to use for creating signature.
- `codesign/enable: bool` — If `true`, executable signing is enabled.
- `codesign/identity: String` — PKCS #12 certificate file used to sign executable or certificate SHA-1 hash (if `codesign/identity_type` is set to "Use certificate store").
- `codesign/identity_type: int` — Type of identity to use.
- `codesign/password: String` — Password for the certificate file used to sign executable.
- `codesign/timestamp: bool` — If `true`, time-stamp is added to the signature.
- `codesign/timestamp_server_url: String` — URL of the time stamp server.
- `custom_template/debug: String` — Path to the custom export template.
- `custom_template/release: String` — Path to the custom export template.
- `debug/export_console_wrapper: int` — If `true`, a console wrapper executable is exported alongside the main executable, which allows running the project with enabled console output.
- `shader_baker/enabled: bool` — If `true`, shaders will be compiled and embedded in the application.
- `ssh_remote_deploy/cleanup_script: String` — Script code to execute on the remote host when app is finished.
- `ssh_remote_deploy/enabled: bool` — Enables remote deploy using SSH/SCP.
- `ssh_remote_deploy/extra_args_scp: String` — Array of the additional command line arguments passed to the SCP.
- `ssh_remote_deploy/extra_args_ssh: String` — Array of the additional command line arguments passed to the SSH.
- `ssh_remote_deploy/host: String` — Remote host SSH user name and address, in `user@address` format.
- `ssh_remote_deploy/port: String` — Remote host SSH port number.
- `ssh_remote_deploy/run_script: String` — Script code to execute on the remote host when running the app.
- `texture_format/etc2_astc: bool` — If `true`, project textures are exported in the ETC2/ASTC format.
- `texture_format/s3tc_bptc: bool` — If `true`, project textures are exported in the S3TC/BPTC format.
