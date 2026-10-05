# Setup and troubleshooting

Upstream: https://github.com/ahujasid/mcp-for-blender (MIT). PyPI package `mcp-for-blender` (formerly `blender-mcp`; `uvx blender-mcp` still works).

Requirements: Blender ≥3.0, Python ≥3.10, [uv](https://docs.astral.sh/uv/) from its official installer (not `pip install uv`).

## Install

Automatic (configures Claude Desktop, Claude Code, Codex, Cursor, VS Code, Windsurf, OpenCode, Antigravity; keeps a `.bak` of each config it edits):

```bash
curl -LsSf https://www.mcp-for-blender.com/install.sh | sh                       # macOS / Linux
powershell -ExecutionPolicy ByPass -c "irm https://www.mcp-for-blender.com/install.ps1 | iex"   # Windows
uvx mcp-for-blender setup                                                         # uv already installed
```

Manual:

```bash
claude mcp add blender uvx mcp-for-blender         # Claude Code
uvx mcp-for-blender install-addon                  # copy addon into Blender's user addons dir
uvx mcp-for-blender addon-paths                    # list the dirs it found
```

Then Blender → Edit → Preferences → Add-ons → enable **Interface: MCP for Blender**.

Claude Desktop / project `.mcp.json`:

```json
{
  "mcpServers": {
    "blender": {
      "command": "uvx",
      "args": ["--python", "3.11", "mcp-for-blender"],
      "env": { "UV_PYTHON_PREFERENCE": "only-managed" }
    }
  }
}
```

`--python 3.11` + `only-managed` avoids conda / pyenv / asdf interpreters breaking the install. A copy of this is in `../mcp.json.example`.

Without uv: `pipx install mcp-for-blender`, then use the absolute path of `mcp-for-blender` as `command`.

Run only one MCP server instance per Blender (not Claude Desktop and Cursor at once).

## Connect

The addon starts its server when Blender opens. To check: `N` in the 3D viewport → **MCP for Blender** tab → **Start MCP Server**. Then fully quit and relaunch the MCP client (Windows: quit from the tray; macOS: Cmd+Q).

## Environment / flags

| Variable | Flag | Default | Meaning |
| --- | --- | --- | --- |
| `BLENDER_HOST` | `--host` | `localhost` | addon socket host |
| `BLENDER_PORT` | `--port` | `9876` | addon socket port (match the addon panel) |
| `BLENDER_MCP_SAFE_MODE` | | off | `1` = validate scripts, block file/process/network access |
| `DISABLE_TELEMETRY` | | | `true` disables anonymous telemetry |

Several Blenders: one client entry per instance, e.g. `"args": ["mcp-for-blender", "--port", "9877"]`, and set that port in each addon panel.

Docker (server only; Blender stays on the host): `docker build -t mcp-for-blender .` in the upstream repo, then `"command": "docker", "args": ["run","-i","--rm","mcp-for-blender"]`. On Linux add `"--network=host","-e","BLENDER_HOST=localhost"`.

## Troubleshooting

| Symptom | Fix |
| --- | --- |
| `spawn uvx ENOENT` | GUI apps don't inherit shell PATH. Use the full path from `which uvx` / `where uvx` as `command`, or on Windows `"command":"cmd","args":["/c","uvx","mcp-for-blender"]` |
| Connection refused / "Not connected to Blender" | Blender closed, addon disabled, or server not started in the N-panel; port mismatch |
| Addon outdated warning from `get_addon_status` | `uvx mcp-for-blender install-addon`, then restart Blender or re-enable the addon |
| Old failure keeps replaying | `uv cache clean mcp-for-blender blender-mcp && uvx --refresh mcp-for-blender` |
| Timeouts on big operations | Split the script into smaller steps |
| Poly Haven / Sketchfab / generators missing | Enable them in the addon N-panel (Sketchfab, Tripo, Rodin, Hunyuan need keys there or Premium) |

`python3 <this-skill-dir>/scripts/blender_socket.py ping` tests the socket directly, bypassing MCP.
