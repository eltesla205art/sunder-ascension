# SUNDER: Ascension — The Nine Bows

A vertical scrolling shooter by **Ascension Media Group**. Nine stages, nine bosses,
three starcraft, a swarm survival mode, and a global arcade leaderboard —
all in one dependency-free HTML file that runs on phones and computers.

**Play the current build:** https://deep-lantern-408.higgsfield.gg/
**Playtest hub:** https://lazy-circle-633.higgsfield.gg/ · **Domain:** https://sunderascension.com

## Repo layout

| Path | What it is |
|---|---|
| `web/game.html` | The whole game (engine, art, audio, UI) — one file, zero dependencies |
| `web/index.html` | Landing page: email signup gate, play links, comments, leaderboard panel |
| `godot/` | The original Godot 4 project the game was ported from |
| `docs/` | Storyline and design notes |
| `supabase.sql` | One-shot setup for the online leaderboard / signups / comments |
| `skills/sunder-ascension-dev/` | Claude Agent Skill — dev/test/balance/deploy workflow for this project |

## Battle math (the balance law)

1. **Player damage** = (base + blue-weapon bonus) × power level — leveling up matters.
2. **Boss hull** = stage data × 1.3 — bosses demand a leveled ship.
3. **Enemy bullets deal 1**; boss bullets deal 2 from stage 5; boss contact deals 2 —
   regular enemies are always slightly weaker than their boss.
4. **Stages are 1.6× longer** and drop more pickups — time to level before the boss.
5. **Every stage clear:** +1 life (cap hull+2), +1 bomb (cap 9), +1 shield (cap 3).

All stage numbers live in the `STAGES` array in `web/game.html`; the law constants
(`STAGE_LEN`, `BOSS_HULL`) sit at the top of the script.

## Going online (Supabase)

1. Create a free project at https://supabase.com
2. Open the SQL editor, paste `supabase.sql`, run it.
3. Copy **Project URL** and **anon public key** (Settings → API) into the
   `SUNDER_CONFIG` block at the top of BOTH `web/game.html` and `web/index.html`.
4. Re-upload the two files — leaderboard, signups and comments are now global.

## Deploying

- **Own domain (cPanel):** upload `web/index.html` and `web/game.html` to `public_html`
  (permissions 644).
- **Test locally:** just double-click `web/game.html`.

## Claude Agent Skill

`skills/sunder-ascension-dev/SKILL.md` packages the full dev workflow for this
project (battle-math law, testing harness, Higgsfield deploy steps, domain
packaging) as a Claude Agent Skill, so Claude picks up the right context
automatically when asked to update, balance, test, or redeploy SUNDER.

To install: zip the `skills/sunder-ascension-dev/` folder into
`sunder-ascension-dev.skill` (a zip with a `.skill` extension) and add it via
Claude's skill settings, or point Claude at this repo path directly.

## Publishing this repo to GitHub

```bash
cd repo
git remote add origin https://github.com/YOURNAME/sunder-ascension.git
git push -u origin main
```
(or create the repo on github.com and drag-and-drop the folder contents).

---
© Ascension Media Group. All rights reserved. SUNDER: Ascension and the Nine Bows
campaign are original IP; do not redistribute without permission.
