# GDScriptLanguageProtocol

**Inherits:** JSONRPC

GDScript language server.

Provides access to certain features that are implemented in the language server. Note: This class is not a language server client that can be used to access LSP functionality. It only provides access to a limited set of features that is implemented using the same technical foundation as the language server.

## Methods

- `get_text_document() -> GDScriptTextDocument` *(deprecated)* — Returns the language server's GDScriptTextDocument instance.
- `get_workspace() -> GDScriptWorkspace` — Returns the language server's GDScriptWorkspace instance.
- `initialize(params: Dictionary) -> Variant` *(deprecated)*
- `initialized(params: Variant) -> void` *(deprecated)*
- `is_initialized() -> bool` *const* — Returns `true` if the language server was initialized by a language server client, `false` otherwise.
- `is_smart_resolve_enabled() -> bool` *const* — Returns `true` if the language server is providing the smart resolve feature, `false` otherwise.
- `notify_client(method: String, params: Variant = null, client_id: int = -1) -> void` *(deprecated)*
- `on_client_connected() -> int[Error]` *(deprecated)*
- `on_client_disconnected(client_id: int) -> void` *(deprecated)*
