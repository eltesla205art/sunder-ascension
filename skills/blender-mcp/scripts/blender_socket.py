#!/usr/bin/env python3
"""Talk to the MCP for Blender addon socket directly, without an MCP client.

Useful to check the connection, or to run bpy code when the MCP server isn't wired up.

  blender_socket.py ping
  blender_socket.py scene
  blender_socket.py exec 'print([o.name for o in bpy.data.objects])'
  blender_socket.py exec -f script.py

Host/port: --host/--port, else BLENDER_HOST/BLENDER_PORT, else localhost:9876.
"""

import argparse
import json
import os
import socket
import sys


def send(host, port, command_type, params=None, timeout=180.0):
    payload = json.dumps({"type": command_type, "params": params or {}}).encode("utf-8")
    with socket.create_connection((host, port), timeout=timeout) as sock:
        sock.sendall(payload)
        buf = b""
        while True:
            chunk = sock.recv(65536)
            if not chunk:
                break
            buf += chunk
            try:
                return json.loads(buf.decode("utf-8"))
            except ValueError:
                continue
    raise ConnectionError("Blender closed the connection without a complete reply")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default=os.environ.get("BLENDER_HOST", "localhost"))
    ap.add_argument("--port", type=int, default=int(os.environ.get("BLENDER_PORT", "9876")))
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("ping")
    sub.add_parser("scene")
    ex = sub.add_parser("exec")
    ex.add_argument("code", nargs="?")
    ex.add_argument("-f", "--file")
    args = ap.parse_args()

    try:
        if args.cmd == "ping":
            reply = send(args.host, args.port, "ping", timeout=10)
        elif args.cmd == "scene":
            reply = send(args.host, args.port, "get_scene_info")
        else:
            code = open(args.file, encoding="utf-8").read() if args.file else args.code
            if not code:
                ap.error("exec needs code or -f FILE")
            reply = send(args.host, args.port, "execute_code", {"code": code})
    except OSError as e:
        print(f"Cannot reach Blender at {args.host}:{args.port}: {e}\n"
              "Open Blender, enable the 'MCP for Blender' addon, and click Start MCP Server in the N-panel.",
              file=sys.stderr)
        return 2

    if reply.get("status") == "error":
        print(f"Blender error: {reply.get('message')}", file=sys.stderr)
        return 1
    result = reply.get("result", reply)
    if args.cmd == "exec" and isinstance(result, dict) and "result" in result:
        print(result["result"], end="")
    else:
        print(json.dumps(result, indent=2))
    return 0


if __name__ == "__main__":
    sys.exit(main())
