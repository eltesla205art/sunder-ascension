#!/usr/bin/env python3
"""Search the bundled Godot class reference.

  godot_api.py Area2D               # print a class's full API
  godot_api.py Area2D body_entered  # lines in Area2D (and its ancestors) matching a term
  godot_api.py -s move_and_slide    # search every class for a member/method/signal name
  godot_api.py -c Node2D            # list classes that inherit from Node2D (direct)
"""
import os, re, signal, sys

signal.signal(signal.SIGPIPE, signal.SIG_DFL)  # quiet when piped to head

REF = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "references", "classes")


def path(name):
    p = os.path.join(REF, f"{name}.md")
    if os.path.exists(p):
        return p
    for f in os.listdir(REF):
        if f[:-3].lower() == name.lower():
            return os.path.join(REF, f)
    return None


def parent(p):
    m = re.search(r"^\*\*Inherits:\*\* (\S+)", open(p).read(), re.M)
    return m.group(1) if m else None


def main(a):
    if not a:
        sys.exit(__doc__)
    if a[0] == "-s" and len(a) > 1:
        rx = re.compile(r"`" + re.escape(a[1]), re.I)
        for f in sorted(os.listdir(REF)):
            for line in open(os.path.join(REF, f)):
                if line.startswith("- ") and rx.search(line):
                    print(f"{f[:-3]}: {line.rstrip()}")
        return
    if a[0] == "-c" and len(a) > 1:
        for f in sorted(os.listdir(REF)):
            if parent(os.path.join(REF, f)) == a[1]:
                print(f[:-3])
        return
    p = path(a[0])
    if not p:
        close = [f[:-3] for f in os.listdir(REF) if a[0].lower() in f.lower()]
        sys.exit(f"No class '{a[0]}'. Similar: {', '.join(sorted(close)[:20]) or 'none'}")
    if len(a) == 1:
        print(open(p).read())
        return
    term = a[1].lower()
    while p:  # walk the inheritance chain
        name = os.path.basename(p)[:-3]
        for line in open(p):
            if line.startswith("- ") and term in line.lower():
                print(f"{name}: {line.rstrip()}")
        par = parent(p)
        p = path(par) if par else None


if __name__ == "__main__":
    main(sys.argv[1:])
