#!/usr/bin/env python3
"""Rebuild references/ from a Godot engine checkout's class XML.

Usage:
  git clone --depth 1 --filter=blob:none --sparse https://github.com/godotengine/godot.git
  cd godot && git sparse-checkout set --no-cone '/doc/classes/' '/modules/*/doc_classes/' \
      '/platform/*/doc_classes/' '/LICENSE.txt' '/version.py'
  python3 build_reference.py /path/to/godot
"""
import glob, os, re, sys, xml.etree.ElementTree as ET

SKILL = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(SKILL, "references")


def clean(text, limit=None):
    """BBCode -> markdown-ish plain text; optionally keep only the first `limit` sentences."""
    if not text:
        return ""
    t = " ".join(text.split()).replace("[lb]", "\x01").replace("[rb]", "\x02")
    t = re.sub(r"\[codeblocks?\].*?\[/codeblocks?\]", "", t)
    t = re.sub(r"\[(?:method|member|signal|constant|enum|annotation|theme_item|operator|constructor|param) ([^\]]+)\]", r"`\1`", t)
    t = re.sub(r"\[(?:code|kbd)[^\]]*\](.*?)\[/(?:code|kbd)\]", r"`\1`", t)
    t = re.sub(r"\[url=([^\]]+)\](.*?)\[/url\]", r"\2", t)
    t = re.sub(r"\[/?(?:b|i|u|s|br|center|codeblock|gdscript|csharp|url|color|font|table|cell|note|codeblock lang=\w+)(?:=[^\]]*)?\]", "", t)
    t = re.sub(r"\[([A-Za-z@][A-Za-z0-9_@.]*)\]", r"\1", t)  # [Node], [int] -> type name
    t = t.replace("\x01", "[").replace("\x02", "]")
    t = t.replace("$DOCS_URL", "https://docs.godotengine.org/en/latest").strip()
    if limit:
        parts = re.split(r"(?<=[.!?])\s+(?=[A-Z`])", t)
        t = " ".join(parts[:limit])
    return t


def typ(el):
    r = el.find("return")
    if r is None:
        return "void"
    t = r.get("type", "void")
    return f"{t}[{r.get('enum')}]" if r.get("enum") else t


def params(el):
    out = []
    for p in sorted(el.findall("param"), key=lambda p: int(p.get("index", 0))):
        s = f"{p.get('name')}: {p.get('enum') or p.get('type')}"
        if p.get("default") is not None:
            s += f" = {p.get('default')}"
        out.append(s)
    return ", ".join(out)


def convert(path):
    root = ET.parse(path).getroot()
    name, inherits = root.get("name"), root.get("inherits", "")
    L = [f"# {name}", ""]
    if inherits:
        L.append(f"**Inherits:** {inherits}")
    if root.get("deprecated") is not None:
        L.append(f"**Deprecated:** {clean(root.get('deprecated'))}")
    L += ["", clean(root.findtext("brief_description")), "", clean(root.findtext("description"), 4), ""]

    def section(title, items):
        if items:
            L.extend([f"## {title}", "", *items, ""])

    section("Properties", [
        f"- `{m.get('name')}: {m.get('enum') or m.get('type')}`"
        + (f" = `{m.get('default')}`" if m.get("default") else "")
        + (" *(deprecated)*" if m.get("deprecated") is not None else "")
        + f" — {clean(m.text, 1)}"
        for m in root.findall("members/member")])
    for tag, title in (("constructors/constructor", "Constructors"), ("methods/method", "Methods"),
                       ("operators/operator", "Operators")):
        section(title, [
            f"- `{m.get('name')}({params(m)}) -> {typ(m)}`"
            + (f" *{m.get('qualifiers')}*" if m.get("qualifiers") else "")
            + (" *(deprecated)*" if m.get("deprecated") is not None else "")
            + (f" — {clean(m.findtext('description'), 1)}" if clean(m.findtext('description')) else "")
            for m in root.findall(tag)])
    section("Signals", [f"- `{s.get('name')}({params(s)})` — {clean(s.findtext('description'), 1)}"
                        for s in root.findall("signals/signal")])
    enums, consts = {}, []
    for c in root.findall("constants/constant"):
        line = f"- `{c.get('name')} = {c.get('value')}` — {clean(c.text, 1)}"
        (enums.setdefault(c.get("enum"), []) if c.get("enum") else consts).append(line)
    for e, lines in enums.items():
        section(f"Enum {e}", lines)
    section("Constants", consts)
    section("Annotations", [f"- `{a.get('name')}({params(a)})` — {clean(a.findtext('description'), 1)}"
                            for a in root.findall("annotations/annotation")])
    section("Theme items", [f"- `{t.get('name')}: {t.get('type')}` ({t.get('data_type')})"
                            + (f" = `{t.get('default')}`" if t.get("default") else "")
                            for t in root.findall("theme_items/theme_item")])
    return name, inherits, clean(root.findtext("brief_description")), "\n".join(L).rstrip() + "\n"


def main(src):
    files = sorted(glob.glob(f"{src}/doc/classes/*.xml") + glob.glob(f"{src}/modules/*/doc_classes/*.xml")
                   + glob.glob(f"{src}/platform/*/doc_classes/*.xml"))
    cdir = os.path.join(OUT, "classes")
    os.makedirs(cdir, exist_ok=True)
    for f in glob.glob(f"{cdir}/*.md"):
        os.remove(f)
    rows = []
    for f in files:
        name, inh, brief, md = convert(f)
        with open(os.path.join(cdir, f"{name}.md"), "w") as fh:
            fh.write(md)
        rows.append((name, inh, brief))
    ver = {}
    exec(open(f"{src}/version.py").read(), ver)
    with open(os.path.join(OUT, "class-index.md"), "w") as fh:
        fh.write(f"# Godot {ver['major']}.{ver['minor']} ({ver['status']}) class index — {len(rows)} classes\n\n"
                 "Format: `Class` (Inherits) — brief. Full API: `classes/<Class>.md`.\n\n")
        for n, i, b in sorted(rows, key=lambda r: r[0].lower()):
            fh.write(f"- `{n}`" + (f" ({i})" if i else "") + f" — {b}\n")
    print(f"wrote {len(rows)} classes")


if __name__ == "__main__":
    main(sys.argv[1] if len(sys.argv) > 1 else ".")
