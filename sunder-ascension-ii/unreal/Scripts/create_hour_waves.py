"""SUNDER: Ascension II — a wave set for each of the Twelve Hours, from the web game's stage tuning.

Run inside the Unreal Editor (Tools → Execute Python Script…) AFTER create_enemies_and_waves.py (the five enemy
Blueprints) and create_keepers.py; run create_stage_audio.py and create_story_level.py before or after (this script
links to what exists, and create_story_level.py picks these up if they are there first).

Reads unreal/Content/Story/story.json (unreal/Tools/export_story_text.cjs, from web/game.html STAGES): each Hour's
enemy health, speed, fire interval, movement, bullet speed, points, spawn interval and score to its Keeper.

Makes /Game/Sunder/Waves/Hours/DA_Waves_HourNN_<Stage>, twelve wave sets that:
  • play like their web Hour: its movement style picks the main enemy (dive → Divers in a V, weave → Scouts in columns,
    rush → Divers abreast, zigzag → Skimmers, circle → Scouts from the sides, evade → Skimmers scattered,
    formation → Scouts in lines), with the web game's scripted scout lines (three across at 20 / 50 / 80 %) and bomber
    runs (one, two from Hour 4); each Hour has a second enemy type from its briefing, and later acts bring gunship
    waves in sooner;
  • last at least as long: waves are added until their worth reaches the web Hour's score to its Keeper (with a margin
    for the ones that get away), and each act's Hours have more waves than the last's (MIN_WAVES);
  • scale like it: enemy speed, fire rate, bullet speed, points and health by the web ratios to Hour 1 (HEALTH_CURVE
    can soften health), and drop pickups at the web Hour's rate + 4 % (battle math #4);
  • end with the Hour's Keeper, in the Hour's own sound (its DA_StageAudio), and don't loop;
  • burst its enemies in the Hour's colour when they're shot down, as the web game does (Explosion Tint).
Then gives each Hour its set in DA_StoryData (if made), and, with ARENA_HOUR set, puts that Hour in L_SunderArena.

Safe to run again. Untested until its first run.
"""
import json
import os

import unreal

ARENA_HOUR = 0        # 1–12: point the arena's wave director at that Hour's set (to test it); 0 = leave the arena alone
HEALTH_CURVE = 1.0    # enemy health = (web health ratio to Hour 1) ** this; 1 = the web game's full ratio (the ship
                      # powers up through three forms, as in the web game; lower it to soften the later Hours)
MARGIN = 1.3          # spawn this much more worth than the score to the Keeper (not every enemy gets shot down)
MIN_WAVES = [4, 5, 6, 7]
FIT = 1.15                 # a longer Hour may carry this much over its budget before its groups are thinned   # per act: each act's Hours are longer than the last's
MAX_WAVES = 8
SOURCE_DIR = None     # None = the repo layout next to this script

ENEMY_DIR = "/Game/Sunder/Blueprints/Enemies"
KEEPER_DIR = "/Game/Sunder/Blueprints/Keepers"
WAVE_DIR = "/Game/Sunder/Waves/Hours"
STAGE_AUDIO_DIR = "/Game/Sunder/Audio/Stages"
STORY_DATA = "/Game/Sunder/Audio/Story/DA_StoryData"
MAP_PATH = "/Game/Sunder/Maps/L_SunderArena"

# Unreal enemy Blueprints (create_enemies_and_waves.py) and what each kill is worth in web "normal enemies"
# (its ScoreValue / 100, the web Hour 1 enemy's points).
WORTH = {"Scout": 1.0, "Diver": 1.2, "Skimmer": 1.5, "Gunship": 4.0, "Bomber": 6.0}

# The web game's enemy movement → the main enemy of the Hour and how it comes in.
MOVES = {
    "dive": ("Diver", "V"), "weave": ("Scout", "COLUMN"), "rush": ("Diver", "LINE"), "zigzag": ("Skimmer", "RANDOM"),
    "circle": ("Scout", "SIDES"), "evade": ("Skimmer", "RANDOM"), "formation": ("Scout", "LINE"),
}
# Each Hour's second enemy type, and (where its briefing asks for it) a different way in for its main one.
SECOND = {"horizon": "Scout", "delta": "Diver", "mirror": "Scout", "spires": "Scout", "sokar": "Skimmer",
          "firelake": "Skimmer", "coils": "Diver", "ironsky": "Gunship", "judgement": "Diver", "starfall": "Diver",
          "heart": "Scout", "apep": "Diver"}
ENTRY = {"starfall": "SIDES", "apep": "V"}           # shards falling in from the edges; up the coils
# The order of the wave templates in each act (see plan_hour): later acts bring the heavy waves in sooner.
ORDER = [[0, 1, 2, 3, 1, 3], [0, 2, 3, 4, 1, 3], [0, 4, 2, 3, 4, 1], [0, 4, 2, 4, 3, 4]]

# Wave names, from each Hour's briefing.
NAMES = {
    "horizon":   ["JACKAL RUN", "WESTERN PICKETS", "CRYSTAL COLUMNS", "WAR-WALKERS", "THE THRESHOLD", "OPENER'S HOUNDS",
                  "LAST LIGHT", "THE WEST GATE"],
    "delta":     ["BLACK WATER", "MARSH FIRE", "REED LINES", "THE DROWNED FIELDS", "DREADNOUGHT WAKE", "FLOODTIDE",
                  "CROCODILE RUN", "THE SECOND GATE"],
    "mirror":    ["GLASS DESERT", "REFLECTIONS", "TWO SHIPS", "MIRROR LINES", "THE COPY", "SHATTER", "SHADOW HEIR",
                  "THE THIRD GATE"],
    "spires":    ["SUNKEN SPIRES", "ATLANTIS GLOW", "CLOSING RINGS", "THE DEEP", "HEART SIGNAL", "PRIMEVAL TIDE",
                  "SPIRE FALL", "THE FOURTH GATE"],
    "sokar":     ["SAND-SEA", "SHIFTING DUNES", "CROSSFIRE", "HIDDEN HAWKS", "DUNE BREAK", "THE DARK SANDS",
                  "KEEP MOVING", "THE FIFTH GATE"],
    "firelake":  ["BURNING LAKE", "SPIRAL FIRE", "SERAPH WINGS", "LAKE OF FIRE", "EMBER STORM", "TAKE THE SKY",
                  "WEIGHED IN FIRE", "THE SIXTH GATE"],
    "coils":     ["THE COILS", "SEVENTH DARK", "COLDER, FASTER", "TWICE AS DEEP", "SERPENT LINES", "UMBRA RETURNS",
                  "COIL STRIKE", "THE SEVENTH GATE"],
    "ironsky":   ["IRON SKY", "WALLS OF FIRE", "RINGS OF STEEL", "THE ENGINE WAKES", "BROKEN BOW", "TEN THOUSAND YEARS",
                  "SETTLE THE SCORE", "THE EIGHTH GATE"],
    "judgement": ["THE HALL", "THE SCALES", "FIGHT CLEAN", "FIGHT FAST", "HEAVY HEARTS", "THE DEVOURER'S COURT",
                  "WEIGHED", "THE NINTH GATE"],
    "starfall":  ["FALLING SHARDS", "THE ECHO", "LAST STORM", "STARFALL", "WHAT IS LEFT", "FOUR HOURS TO DAWN",
                  "THE BROKEN ENEMY", "THE TENTH GATE"],
    "heart":     ["HEARTBEAT", "THE MASK", "BENEATH THE GATE", "THE LAST TIME", "END IT HERE", "ATLANTIS BEATS",
                  "UMBRA WAITS", "THE ELEVENTH GATE"],
    "apep":      ["THE COILS RISE", "SUN BARQUE", "UP THE COILS", "INTO THE JAWS", "DAWN OR NOTHING", "THE BOTTOM OF THE DUAT",
                  "TO THE HEART", "THE TWELFTH GATE"],
}

TOOLS = unreal.AssetToolsHelpers.get_asset_tools()
EAL = unreal.EditorAssetLibrary

DONE = []
MANUAL = []


def log(msg):
    unreal.log("[SunderHours] " + msg)


def step(label, fn, *args):
    try:
        result = fn(*args)
        DONE.append(label)
        return result
    except Exception as exc:   # the editor's Python API differs a little between versions
        MANUAL.append("{}  (script error: {})".format(label, exc))
        unreal.log_warning("[SunderHours] {} failed: {}".format(label, exc))
        return None


def repo_path(*parts):
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.normpath(os.path.join(SOURCE_DIR or os.path.join(here, ".."), *parts))


def camel(text):
    return "".join(part.capitalize() for part in text.split("_"))


# ------------------------------------------------------------------ the plan (pure Python: no editor calls)
EXPLOSION_GLOW = 3.0   # the Hour's colour, brightest channel at this for bloom


def hdr(hex_rgb, strength):
    """sRGB hex → linear HDR colour, brightest channel = strength."""
    rgb = [int(hex_rgb[i:i + 2], 16) / 255.0 for i in (1, 3, 5)]
    lin = [c / 12.92 if c <= 0.04045 else ((c + 0.055) / 1.055) ** 2.4 for c in rgb]
    peak = max(max(lin), 1e-4)
    return [c / peak * strength for c in lin]


def difficulty(t, first):
    """The Hour's scales relative to Hour 1, from the web game's tuning."""
    return {
        "health_scale": round((t["enemy_health"] / first["enemy_health"]) ** HEALTH_CURVE, 3),
        "speed_scale": round(t["enemy_speed"] / first["enemy_speed"], 3),
        "fire_rate_scale": round(first["enemy_fire_interval"] / t["enemy_fire_interval"], 3),
        "shot_speed_scale": round(t["enemy_bullet_speed"] / first["enemy_bullet_speed"], 3),
        "score_scale": round(t["enemy_points"] / first["enemy_points"], 3),
        "drop_chance": round(t.get("drop_chance", 0.2) + 0.04, 3),
    }


def plan_hour(hour):
    """Waves for one Hour as plain data: [(name, [(enemy, count, formation, delay, interval, lane, spacing)], rest)]."""
    num, t = hour["num"], hour["tuning"]
    act = (num - 1) // 3
    main, entry = MOVES.get(t["enemy_move"], ("Scout", "COLUMN"))
    entry = ENTRY.get(hour["stage"], entry)
    second = SECOND.get(hour["stage"], "Scout")
    second_count = (lambda n: min(n, 2 + act // 2)) if second == "Gunship" else (lambda n: n)   # gunships are heavy
    gap = round(max(0.25, min(0.6, t["spawn_interval"] * 0.45)), 2)   # the web Hour's spawn rate, in bursts
    bombers = 2 if num >= 4 else 1                                      # web spawnBomberWave
    rest = round(max(0.8, 2.0 - act * 0.35), 2)
    # web score to the Keeper, in kills of that Hour's normal enemy
    budget = t["score_to_boss"] / float(t["enemy_points"]) * MARGIN

    def scout_line(delay):                                              # web spawnScoutWave: 20 / 50 / 80 % across
        return ("Scout", 3, "LINE", delay, 0.0, 0.0, 700.0)

    templates = [
        lambda: [(main, 5 + act, entry, 0.0, gap, 0.0, 160.0), scout_line(3.0)],
        lambda: [scout_line(0.0), scout_line(2.5), (main, 3 + act, "RANDOM", 4.0, gap, 0.0, 160.0)],
        lambda: [("Bomber", bombers, "LINE", 0.0, 0.0, 0.0, 900.0), (main, 4 + act, "SIDES", 2.5, gap, 0.0, 160.0)],
        lambda: [(second, second_count(5 + act), "LINE" if second == "Gunship" else "V" if second == "Diver" else "COLUMN",
                  0.0, gap, -0.4, 1000.0 if second == "Gunship" else 140.0),
                 (main, 4 + act, entry, 2.0, gap, 0.4, 160.0)],
        lambda: [("Gunship", 2, "LINE", 0.0, 0.0, 0.0, 1000.0), ("Scout", 6 + act, "SIDES", 2.0, gap, 0.0, 160.0),
                 (main, 3 + act, "RANDOM", 5.0, gap, 0.0, 160.0)],
    ]
    order = ORDER[min(act, len(ORDER) - 1)]
    waves, worth, k = [], 0.0, 0
    names = NAMES.get(hour["stage"], [])
    while (worth < budget or len(waves) < MIN_WAVES[min(act, 3)]) and len(waves) < MAX_WAVES:
        groups = templates[order[k % len(order)]]()
        worth += sum(WORTH[g[0]] * g[1] for g in groups)
        name = names[len(waves)] if len(waves) < len(names) else "WAVE {}".format(len(waves) + 1)
        waves.append((name, groups, rest))
        k += 1
    # More waves than the score needs (MIN_WAVES): thin the light groups so the Hour is longer, not three times fuller.
    # Bombers, gunships and the scripted scout lines keep their numbers.
    if worth > budget * FIT:
        f = budget * FIT / worth
        def thin(g):
            fixed = g[0] in ("Bomber", "Gunship") or (g[0] == "Scout" and g[1] == 3 and g[2] == "LINE")
            return g if fixed else (g[0], max(3, int(round(g[1] * f)))) + g[2:]
        waves = [(n, [thin(g) for g in groups], r) for n, groups, r in waves]
        worth = sum(WORTH[g[0]] * g[1] for _, groups, _ in waves for g in groups)
    return waves, worth, budget


# ------------------------------------------------------------------ the editor
def enemy_classes():
    classes = {}
    for kind in WORTH:
        full = "{}/BP_Enemy_{}".format(ENEMY_DIR, kind)
        if not EAL.does_asset_exist(full):
            raise RuntimeError(full + " not found; run create_enemies_and_waves.py first")
        classes[kind] = EAL.load_blueprint_class(full)
    return classes


def make_group(classes, spec):
    kind, count, formation, delay, interval, lane, spacing = spec
    g = unreal.SunderSpawnGroup()
    g.set_editor_property("enemy_class", classes[kind])
    g.set_editor_property("count", count)
    g.set_editor_property("formation", getattr(unreal.SunderFormation, formation))
    g.set_editor_property("delay", delay)
    g.set_editor_property("interval", interval)
    g.set_editor_property("lane", lane)
    g.set_editor_property("spacing", spacing)
    return g


def make_wave(name, groups, rest, keeper=None):
    w = unreal.SunderWave()
    w.set_editor_property("wave_name", name)
    w.set_editor_property("groups", groups)
    w.set_editor_property("wait_for_clear", True)        # UE Python drops the b prefix of bools
    w.set_editor_property("max_duration", 600.0 if keeper else 35.0)
    w.set_editor_property("break_after", rest)
    if keeper is not None:
        w.set_editor_property("keeper", keeper)
    return w


def build_hour(hour, classes, first):
    stage = hour["stage"]
    name = "DA_Waves_Hour{:02d}_{}".format(hour["num"], camel(stage))
    full = "{}/{}".format(WAVE_DIR, name)
    if EAL.does_asset_exist(full):
        data = EAL.load_asset(full)
    else:
        factory = unreal.DataAssetFactory()
        factory.set_editor_property("data_asset_class", unreal.SunderWaveSet)
        data = TOOLS.create_asset(name, WAVE_DIR, unreal.SunderWaveSet, factory)
        if data is None:
            raise RuntimeError("could not create " + full)
    plan, worth, budget = plan_hour(hour)
    waves = [make_wave(n, [make_group(classes, g) for g in groups], rest) for n, groups, rest in plan]
    keeper_bp = "{}/BP_Keeper_{}".format(KEEPER_DIR, camel(hour["keeper_id"]))
    if EAL.does_asset_exist(keeper_bp):
        waves.append(make_wave("KEEPER  ·  " + hour["keeper"].split(",")[0].upper(), [], 0.0,
                               EAL.load_blueprint_class(keeper_bp)))
    else:
        MANUAL.append("{}: no {} for its last wave (run create_keepers.py, then this again)".format(name, keeper_bp))
    data.set_editor_property("waves", waves)
    data.set_editor_property("loop", False)
    for prop, value in difficulty(hour["tuning"], first).items():
        data.set_editor_property(prop, value)
    if hour.get("tint"):
        r, g, b = hdr(hour["tint"], EXPLOSION_GLOW)
        try:
            data.set_editor_property("explosion_tint", unreal.LinearColor(r, g, b, 1.0))
        except Exception as exc:   # C++ from before Explosion Tint: compile unreal/Source again
            MANUAL.append("{}: Explosion Tint not set ({})".format(name, exc))
    stage_audio = "{}/DA_StageAudio_{}".format(STAGE_AUDIO_DIR, camel(stage))
    if EAL.does_asset_exist(stage_audio):
        data.set_editor_property("stage_audio", EAL.load_asset(stage_audio))
    EAL.save_loaded_asset(data)
    log("{}: {} waves, worth {:.0f} of {:.0f} needed".format(name, len(plan), worth, budget))
    return data


def give_story(sets):
    if not EAL.does_asset_exist(STORY_DATA):
        log("DA_StoryData not made yet; create_story_level.py will pick these up")
        return
    data = EAL.load_asset(STORY_DATA)
    hours = list(data.get_editor_property("hours"))
    for i, hour in enumerate(hours):
        if sets.get(i + 1) is not None:
            hour.set_editor_property("waves", sets[i + 1])
            hours[i] = hour
    data.set_editor_property("hours", hours)
    EAL.save_loaded_asset(data)


def arena_hour(wave_set):
    levels = unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    actors = unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
    if not levels.load_level(MAP_PATH):
        raise RuntimeError("could not open " + MAP_PATH)
    directors = [a for a in actors.get_all_level_actors() if isinstance(a, unreal.SunderWaveDirector)]
    if not directors:
        raise RuntimeError("no SunderWaveDirector in the arena; run create_enemies_and_waves.py first")
    directors[0].set_editor_property("wave_set", wave_set)
    levels.save_current_level()


def main():
    missing = [n for n in ("SunderWaveSet", "SunderWave", "SunderSpawnGroup", "SunderFormation") if not hasattr(unreal, n)]
    if missing:
        unreal.log_error("[SunderHours] C++ types not found: {}. Compile unreal/Source first.".format(", ".join(missing)))
        return
    story_file = repo_path("Content", "Story", "story.json")
    if not os.path.isfile(story_file):
        unreal.log_error("[SunderHours] not found: {} (run node unreal/Tools/export_story_text.cjs)".format(story_file))
        return
    with open(story_file, encoding="utf-8") as f:
        hours = json.load(f)["hours"]
    EAL.make_directory(WAVE_DIR)
    classes = step("the five enemy Blueprints", enemy_classes)
    if classes is None:
        unreal.log_error("[SunderHours] run create_enemies_and_waves.py first")
        return

    sets = {}
    for hour in hours:
        sets[hour["num"]] = step("DA_Waves_Hour{:02d}_{}".format(hour["num"], camel(hour["stage"])),
                                 build_hour, hour, classes, hours[0]["tuning"])
    step("DA_StoryData: each Hour's waves", give_story, sets)
    if ARENA_HOUR and sets.get(ARENA_HOUR) is not None:
        step("L_SunderArena → Hour {}".format(ARENA_HOUR), arena_hour, sets[ARENA_HOUR])

    log("---- done ({}) ----".format(len(DONE)))
    for label in DONE:
        log("  ok  " + label)
    log("---- still to do by hand ({}) ----".format(len(MANUAL)))
    for item in MANUAL:
        log("  •   " + item)
    log("Story mode now flies each Hour's own waves. To try one Hour in the arena, set ARENA_HOUR and run this again.")


main()
