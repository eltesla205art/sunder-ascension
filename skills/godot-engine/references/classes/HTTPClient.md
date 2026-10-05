# HTTPClient

**Inherits:** RefCounted

Low-level hyper-text transfer protocol client.

Hyper-text transfer protocol client (sometimes called "User Agent"). Used to make HTTP requests to download web content, upload files and other data or to communicate with various services, among other use cases. See the HTTPRequest node for a higher-level alternative. Note: This client only needs to connect to a host once (see `connect_to_host`) to send multiple requests.

## Properties

- `blocking_mode_enabled: bool` = `false` — If `true`, execution will block until all data is read from the response.
- `connection: StreamPeer` — The connection to use for this client.
- `read_chunk_size: int` = `65536` — The size of the buffer used and maximum bytes to read per iteration.

## Methods

- `close() -> void` — Closes the current connection, allowing reuse of this HTTPClient.
- `connect_to_host(host: String, port: int = -1, tls_options: TLSOptions = null) -> int[Error]` — Connects to a host.
- `get_response_body_length() -> int` *const* — Returns the response's body length.
- `get_response_code() -> int` *const* — Returns the response's HTTP status code.
- `get_response_headers() -> PackedStringArray` — Returns the response headers.
- `get_response_headers_as_dictionary() -> Dictionary` — Returns all response headers as a Dictionary.
- `get_status() -> int[HTTPClient.Status]` *const* — Returns a `Status` constant.
- `has_response() -> bool` *const* — If `true`, this HTTPClient has a response available.
- `is_response_chunked() -> bool` *const* — If `true`, this HTTPClient has a response that is chunked.
- `poll() -> int[Error]` — This needs to be called in order to have any request processed.
- `query_string_from_dict(fields: Dictionary) -> String` — Generates a GET/POST application/x-www-form-urlencoded style query string from a provided dictionary, e.g.:  Furthermore, if a key has a `null` value, only the key itself is added, without equal sign and value.
- `read_response_body_chunk() -> PackedByteArray` — Reads one chunk from the response.
- `request(method: HTTPClient.Method, url: String, headers: PackedStringArray, body: String = "") -> int[Error]` — Sends an HTTP request to the connected host with the given `method`.
- `request_raw(method: HTTPClient.Method, url: String, headers: PackedStringArray, body: PackedByteArray) -> int[Error]` — Sends a raw HTTP request to the connected host with the given `method`.
- `set_http_proxy(host: String, port: int) -> void` — Sets the proxy server for HTTP requests.
- `set_https_proxy(host: String, port: int) -> void` — Sets the proxy server for HTTPS requests.

## Enum Method

- `METHOD_GET = 0` — HTTP GET method.
- `METHOD_HEAD = 1` — HTTP HEAD method.
- `METHOD_POST = 2` — HTTP POST method.
- `METHOD_PUT = 3` — HTTP PUT method.
- `METHOD_DELETE = 4` — HTTP DELETE method.
- `METHOD_OPTIONS = 5` — HTTP OPTIONS method.
- `METHOD_TRACE = 6` — HTTP TRACE method.
- `METHOD_CONNECT = 7` — HTTP CONNECT method.
- `METHOD_PATCH = 8` — HTTP PATCH method.
- `METHOD_MAX = 9` — Represents the size of the `Method` enum.

## Enum Status

- `STATUS_DISCONNECTED = 0` — Status: Disconnected from the server.
- `STATUS_RESOLVING = 1` — Status: Currently resolving the hostname for the given URL into an IP.
- `STATUS_CANT_RESOLVE = 2` — Status: DNS failure: Can't resolve the hostname for the given URL.
- `STATUS_CONNECTING = 3` — Status: Currently connecting to server.
- `STATUS_CANT_CONNECT = 4` — Status: Can't connect to the server.
- `STATUS_CONNECTED = 5` — Status: Connection established.
- `STATUS_REQUESTING = 6` — Status: Currently sending request.
- `STATUS_BODY = 7` — Status: HTTP body received.
- `STATUS_CONNECTION_ERROR = 8` — Status: Error in HTTP connection.
- `STATUS_TLS_HANDSHAKE_ERROR = 9` — Status: Error in TLS handshake.

## Enum ResponseCode

- `RESPONSE_CONTINUE = 100` — HTTP status code `100 Continue`.
- `RESPONSE_SWITCHING_PROTOCOLS = 101` — HTTP status code `101 Switching Protocol`.
- `RESPONSE_PROCESSING = 102` — HTTP status code `102 Processing` (WebDAV).
- `RESPONSE_OK = 200` — HTTP status code `200 OK`.
- `RESPONSE_CREATED = 201` — HTTP status code `201 Created`.
- `RESPONSE_ACCEPTED = 202` — HTTP status code `202 Accepted`.
- `RESPONSE_NON_AUTHORITATIVE_INFORMATION = 203` — HTTP status code `203 Non-Authoritative Information`.
- `RESPONSE_NO_CONTENT = 204` — HTTP status code `204 No Content`.
- `RESPONSE_RESET_CONTENT = 205` — HTTP status code `205 Reset Content`.
- `RESPONSE_PARTIAL_CONTENT = 206` — HTTP status code `206 Partial Content`.
- `RESPONSE_MULTI_STATUS = 207` — HTTP status code `207 Multi-Status` (WebDAV).
- `RESPONSE_ALREADY_REPORTED = 208` — HTTP status code `208 Already Reported` (WebDAV).
- `RESPONSE_IM_USED = 226` — HTTP status code `226 IM Used` (WebDAV).
- `RESPONSE_MULTIPLE_CHOICES = 300` — HTTP status code `300 Multiple Choice`.
- `RESPONSE_MOVED_PERMANENTLY = 301` — HTTP status code `301 Moved Permanently`.
- `RESPONSE_FOUND = 302` — HTTP status code `302 Found`.
- `RESPONSE_SEE_OTHER = 303` — HTTP status code `303 See Other`.
- `RESPONSE_NOT_MODIFIED = 304` — HTTP status code `304 Not Modified`.
- `RESPONSE_USE_PROXY = 305` — HTTP status code `305 Use Proxy`.
- `RESPONSE_SWITCH_PROXY = 306` — HTTP status code `306 Switch Proxy`.
- `RESPONSE_TEMPORARY_REDIRECT = 307` — HTTP status code `307 Temporary Redirect`.
- `RESPONSE_PERMANENT_REDIRECT = 308` — HTTP status code `308 Permanent Redirect`.
- `RESPONSE_BAD_REQUEST = 400` — HTTP status code `400 Bad Request`.
- `RESPONSE_UNAUTHORIZED = 401` — HTTP status code `401 Unauthorized`.
- `RESPONSE_PAYMENT_REQUIRED = 402` — HTTP status code `402 Payment Required`.
- `RESPONSE_FORBIDDEN = 403` — HTTP status code `403 Forbidden`.
- `RESPONSE_NOT_FOUND = 404` — HTTP status code `404 Not Found`.
- `RESPONSE_METHOD_NOT_ALLOWED = 405` — HTTP status code `405 Method Not Allowed`.
- `RESPONSE_NOT_ACCEPTABLE = 406` — HTTP status code `406 Not Acceptable`.
- `RESPONSE_PROXY_AUTHENTICATION_REQUIRED = 407` — HTTP status code `407 Proxy Authentication Required`.
- `RESPONSE_REQUEST_TIMEOUT = 408` — HTTP status code `408 Request Timeout`.
- `RESPONSE_CONFLICT = 409` — HTTP status code `409 Conflict`.
- `RESPONSE_GONE = 410` — HTTP status code `410 Gone`.
- `RESPONSE_LENGTH_REQUIRED = 411` — HTTP status code `411 Length Required`.
- `RESPONSE_PRECONDITION_FAILED = 412` — HTTP status code `412 Precondition Failed`.
- `RESPONSE_REQUEST_ENTITY_TOO_LARGE = 413` — HTTP status code `413 Entity Too Large`.
- `RESPONSE_REQUEST_URI_TOO_LONG = 414` — HTTP status code `414 Request-URI Too Long`.
- `RESPONSE_UNSUPPORTED_MEDIA_TYPE = 415` — HTTP status code `415 Unsupported Media Type`.
- `RESPONSE_REQUESTED_RANGE_NOT_SATISFIABLE = 416` — HTTP status code `416 Requested Range Not Satisfiable`.
- `RESPONSE_EXPECTATION_FAILED = 417` — HTTP status code `417 Expectation Failed`.
- `RESPONSE_IM_A_TEAPOT = 418` — HTTP status code `418 I'm A Teapot`.
- `RESPONSE_MISDIRECTED_REQUEST = 421` — HTTP status code `421 Misdirected Request`.
- `RESPONSE_UNPROCESSABLE_ENTITY = 422` — HTTP status code `422 Unprocessable Entity` (WebDAV).
- `RESPONSE_LOCKED = 423` — HTTP status code `423 Locked` (WebDAV).
- `RESPONSE_FAILED_DEPENDENCY = 424` — HTTP status code `424 Failed Dependency` (WebDAV).
- `RESPONSE_UPGRADE_REQUIRED = 426` — HTTP status code `426 Upgrade Required`.
- `RESPONSE_PRECONDITION_REQUIRED = 428` — HTTP status code `428 Precondition Required`.
- `RESPONSE_TOO_MANY_REQUESTS = 429` — HTTP status code `429 Too Many Requests`.
- `RESPONSE_REQUEST_HEADER_FIELDS_TOO_LARGE = 431` — HTTP status code `431 Request Header Fields Too Large`.
- `RESPONSE_UNAVAILABLE_FOR_LEGAL_REASONS = 451` — HTTP status code `451 Response Unavailable For Legal Reasons`.
- `RESPONSE_INTERNAL_SERVER_ERROR = 500` — HTTP status code `500 Internal Server Error`.
- `RESPONSE_NOT_IMPLEMENTED = 501` — HTTP status code `501 Not Implemented`.
- `RESPONSE_BAD_GATEWAY = 502` — HTTP status code `502 Bad Gateway`.
- `RESPONSE_SERVICE_UNAVAILABLE = 503` — HTTP status code `503 Service Unavailable`.
- `RESPONSE_GATEWAY_TIMEOUT = 504` — HTTP status code `504 Gateway Timeout`.
- `RESPONSE_HTTP_VERSION_NOT_SUPPORTED = 505` — HTTP status code `505 HTTP Version Not Supported`.
- `RESPONSE_VARIANT_ALSO_NEGOTIATES = 506` — HTTP status code `506 Variant Also Negotiates`.
- `RESPONSE_INSUFFICIENT_STORAGE = 507` — HTTP status code `507 Insufficient Storage`.
- `RESPONSE_LOOP_DETECTED = 508` — HTTP status code `508 Loop Detected`.
- `RESPONSE_NOT_EXTENDED = 510` — HTTP status code `510 Not Extended`.
- `RESPONSE_NETWORK_AUTH_REQUIRED = 511` — HTTP status code `511 Network Authentication Required`.
