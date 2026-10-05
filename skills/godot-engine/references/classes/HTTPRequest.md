# HTTPRequest

**Inherits:** Node

A node with the ability to send HTTP(S) requests.

A node with the ability to send HTTP requests. Uses HTTPClient internally. Can be used to make HTTP requests, i.e. download or upload files or web content via HTTP. Warning: See the notes and warnings on HTTPClient for limitations, especially regarding TLS security.

## Properties

- `accept_gzip: bool` = `true` — If `true`, this header will be added to each request: `Accept-Encoding: gzip, deflate` telling servers that it's okay to compress response bodies.
- `append_to_download_file: bool` = `false` — If `true` and the server responds with HTTP status code `206 Partial Content`, the response body will be appended to the existing `download_file` instead of overwriting it.
- `body_size_limit: int` = `-1` — Maximum allowed size for response bodies.
- `download_chunk_size: int` = `65536` — The size of the buffer used and maximum bytes to read per iteration.
- `download_file: String` = `""` — The file to download into.
- `keep_partial_download: bool` = `false` — If `true`, the partially downloaded file set via `download_file` will not be deleted when the request fails or is canceled.
- `max_redirects: int` = `8` — Maximum number of allowed redirects.
- `timeout: float` = `0.0` — The duration to wait before a request times out, in seconds (independent of `Engine.time_scale`).
- `use_threads: bool` = `false` — If `true`, multithreading is used to improve performance.

## Methods

- `cancel_request() -> void` — Cancels the current request.
- `get_body_size() -> int` *const* — Returns the response body length.
- `get_downloaded_bytes() -> int` *const* — Returns the number of bytes this HTTPRequest downloaded.
- `get_http_client_status() -> int[HTTPClient.Status]` *const* — Returns the current status of the underlying HTTPClient.
- `request(url: String, custom_headers: PackedStringArray = PackedStringArray(), method: HTTPClient.Method = 0, request_data: String = "") -> int[Error]` — Creates request on the underlying HTTPClient.
- `request_raw(url: String, custom_headers: PackedStringArray = PackedStringArray(), method: HTTPClient.Method = 0, request_data_raw: PackedByteArray = PackedByteArray()) -> int[Error]` — Creates request on the underlying HTTPClient using a raw array of bytes for the request body.
- `set_http_proxy(host: String, port: int) -> void` — Sets the proxy server for HTTP requests.
- `set_https_proxy(host: String, port: int) -> void` — Sets the proxy server for HTTPS requests.
- `set_tls_options(client_options: TLSOptions) -> void` — Sets the TLSOptions to be used when connecting to an HTTPS server.

## Signals

- `request_completed(result: int, response_code: int, headers: PackedStringArray, body: PackedByteArray)` — Emitted when a request is completed.

## Enum Result

- `RESULT_SUCCESS = 0` — Request successful.
- `RESULT_CHUNKED_BODY_SIZE_MISMATCH = 1` — Request failed due to a mismatch between the expected and actual chunked body size during transfer.
- `RESULT_CANT_CONNECT = 2` — Request failed while connecting.
- `RESULT_CANT_RESOLVE = 3` — Request failed while resolving.
- `RESULT_CONNECTION_ERROR = 4` — Request failed due to connection (read/write) error.
- `RESULT_TLS_HANDSHAKE_ERROR = 5` — Request failed on TLS handshake.
- `RESULT_NO_RESPONSE = 6` — Request does not have a response (yet).
- `RESULT_BODY_SIZE_LIMIT_EXCEEDED = 7` — Request exceeded its maximum size limit, see `body_size_limit`.
- `RESULT_BODY_DECOMPRESS_FAILED = 8` — Request failed due to an error while decompressing the response body.
- `RESULT_REQUEST_FAILED = 9` — Request failed (currently unused).
- `RESULT_DOWNLOAD_FILE_CANT_OPEN = 10` — HTTPRequest couldn't open the download file.
- `RESULT_DOWNLOAD_FILE_WRITE_ERROR = 11` — HTTPRequest couldn't write to the download file.
- `RESULT_REDIRECT_LIMIT_REACHED = 12` — Request reached its maximum redirect limit, see `max_redirects`.
- `RESULT_TIMEOUT = 13` — Request failed due to a timeout.
