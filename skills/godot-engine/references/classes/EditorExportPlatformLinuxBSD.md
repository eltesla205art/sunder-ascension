# EditorExportPlatformLinuxBSD

**Inherits:** EditorExportPlatformPC

Exporter for Linux/BSD.



## Properties

- `binary_format/architecture: String` — Application executable architecture.
- `binary_format/embed_pck: bool` — If `true`, project resources are embedded into the executable.
- `custom_template/debug: String` — Path to the custom export template.
- `custom_template/release: String` — Path to the custom export template.
- `debug/export_console_wrapper: int` — If `true`, a console wrapper is exported alongside the main executable, which allows running the project with enabled console output.
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
