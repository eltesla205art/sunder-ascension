# EditorExportPlatformWeb

**Inherits:** EditorExportPlatform

Exporter for the Web.

The Web exporter customizes how a web build is handled. In the editor's "Export" window, it is created when adding a new "Web" preset. Note: Godot on Web is rendered inside a `<canvas>` tag. Normally, the canvas cannot be positioned or resized manually, but otherwise acts as the main Window of the application.

## Properties

- `custom_template/debug: String` — File path to the custom export template used for debug builds.
- `custom_template/release: String` — File path to the custom export template used for release builds.
- `html/canvas_resize_policy: int` — Determines how the canvas should be resized by Godot. - None: The canvas is not automatically resized. - Project: The size of the canvas is dependent on the ProjectSettings. - Adaptive: The canvas is automatically resized to fit as much of the web page as possible.
- `html/custom_html_shell: String` — The custom HTML page that wraps the exported web build.
- `html/experimental_virtual_keyboard: bool` — If `true`, embeds support for a virtual keyboard into the web page, which is shown when necessary on touchscreen devices.
- `html/export_icon: bool` — If `true`, the project icon will be used as the favicon for this application's web page.
- `html/focus_canvas_on_start: bool` — If `true`, the canvas will be focused as soon as the application is loaded, if the browser window is already in focus.
- `html/head_include: String` — Additional HTML tags to include inside the `<head>`, such as `<meta>` tags.
- `progressive_web_app/background_color: Color` — The background color used behind the web application.
- `progressive_web_app/display: int` — The display mode to use for this progressive web application.
- `progressive_web_app/enabled: bool` — If `true`, turns this web build into a progressive web application (PWA).
- `progressive_web_app/ensure_cross_origin_isolation_headers: bool` — When enabled, the progressive web app will make sure that each request has cross-origin isolation headers (COEP/COOP).
- `progressive_web_app/icon_144x144: String` — File path to the smallest icon for this web application.
- `progressive_web_app/icon_180x180: String` — File path to the small icon for this web application.
- `progressive_web_app/icon_512x512: String` — File path to the largest icon for this web application.
- `progressive_web_app/offline_page: String` — The page to display, should the server hosting the page not be available.
- `progressive_web_app/orientation: int` — The orientation to use when the web application is run through a mobile device. - Any: No orientation is forced. - Landscape: Forces a horizontal layout (wider than it is taller). - Portrait: Forces a vertical layout (taller than it is wider).
- `threads/emscripten_pool_size: int` — The number of threads that emscripten will allocate at startup.
- `threads/godot_pool_size: int` — Override for the default size of the WorkerThreadPool.
- `variant/extensions_support: bool` — If `true` enables GDExtension support for this web build.
- `variant/thread_support: bool` — If `true`, the exported game will support threads.
- `vram_texture_compression/for_desktop: bool` — If `true`, allows textures to be optimized for desktop through the S3TC/BPTC algorithm.
- `vram_texture_compression/for_mobile: bool` — If `true` allows textures to be optimized for mobile through the ETC2/ASTC algorithm.
