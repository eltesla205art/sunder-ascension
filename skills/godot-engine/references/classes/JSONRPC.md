# JSONRPC

**Inherits:** Object

A helper to handle dictionaries which look like JSONRPC documents.

JSON-RPC is a standard which wraps a method call in a JSON object. The object has a particular structure and identifies which method is called, the parameters to that function, and carries an ID to keep track of responses. This class implements that standard on top of Dictionary; you will have to convert between a Dictionary and JSON with other functions.

## Methods

- `make_notification(method: String, params: Variant) -> Dictionary` — Returns a dictionary in the form of a JSON-RPC notification.
- `make_request(method: String, params: Variant, id: Variant) -> Dictionary` — Returns a dictionary in the form of a JSON-RPC request.
- `make_response(result: Variant, id: Variant) -> Dictionary` — When a server has received and processed a request, it is expected to send a response.
- `make_response_error(code: int, message: String, id: Variant = null) -> Dictionary` *const* — Creates a response which indicates a previous reply has failed in some way. - `code`: The error code corresponding to what kind of error this is.
- `process_action(action: Variant, recurse: bool = false) -> Variant` — Given a Dictionary which takes the form of a JSON-RPC request: unpack the request and run it.
- `process_string(action: String) -> String`
- `set_method(name: String, callback: Callable) -> void` — Registers a callback for the given method name. - `name`: The name that clients can use to access the callback. - `callback`: The callback which will handle the specified method.

## Enum ErrorCode

- `PARSE_ERROR = -32700` — The request could not be parsed as it was not valid by JSON standard (`JSON.parse` failed).
- `INVALID_REQUEST = -32600` — A method call was requested but the request's format is not valid.
- `METHOD_NOT_FOUND = -32601` — A method call was requested but no function of that name existed in the JSONRPC subclass.
- `INVALID_PARAMS = -32602` — A method call was requested but the given method parameters are not valid.
- `INTERNAL_ERROR = -32603` — An internal error occurred while processing the request.
