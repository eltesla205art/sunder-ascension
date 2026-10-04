// SUNDER: Ascension II — render the web game's synthesised audio (web/keeper_audio.js, stage_audio.js, menu_audio.js) to WAV
// for Unreal, so both versions sound the same.
//
//   node unreal/Tools/render_web_audio.cjs [keepers|stages|menus|all] [out_root] [gain]
//   (defaults: all, unreal/Content/Audio, 1.6; needs Playwright with Chromium: npm i -g playwright)
//
// keepers → Audio/Keepers: Music/MUS_Keeper_<Name>_L1..3 (each theme in three layers) and
//           Voices/SFX_Keeper_<Name>_Intro/Attack/Phase/Hurt/Death
// stages  → Audio/Stages:  Music/MUS_Stage_<Name>_L1..3, Ambience/AMB_Stage_<Name> and
//           Cues/SFX_Stage_<Name>_Start/Wave/Down/Clear
// menus   → Audio/Menus:   Music/MUS_Menu_Title|Hangar_L1..3, Ambience/AMB_Menu_Title|Hangar,
//           Cues/SFX_Menu_Title_Start/Leaderboard, SFX_Menu_Hangar_Move/Mode/Back/Launch, SFX_Ship_<Ship>_Rev
// Music loops are exactly one loop, cut from the second pass of two so notes ringing over the loop point are already
// at its start: seamless, and the three layers of a theme are the same length so they play in step and crossfade.
// Ambience is a 24 s loop (22.05 kHz) of the beds and their scattered events, its seam hidden with an equal-power
// crossfade; a place with a steady pulse (the Heart's heartbeat) gets a loop a whole number of beats long.
// Voices and cues are trimmed after their tails. Music and cues are 32 kHz. Mono, 16-bit. Everything gets the same gain
// (default 1.6, +4 dB: the web game leans on the browser's volume), so the web game's balance between music, voices
// and ambience is kept. Prints a JSON report (lengths, peaks) at the end.
'use strict';
const fs = require('fs');
const path = require('path');
let chromium;
try { ({ chromium } = require('playwright')); }
catch (e) { ({ chromium } = require(path.join(require('child_process').execSync('npm root -g').toString().trim(), 'playwright'))); }

const HERE = __dirname;
const PACK = process.argv[2] || 'all';
const ROOT = path.resolve(process.argv[3] || path.join(HERE, '..', 'Content', 'Audio'));
const GAIN = Number(process.argv[4] || 1.6);
const RATE = 32000, AMB_RATE = 22050, AMB_LOOP = 24, AMB_FADE = 3, AMB_WARMUP = 4;
const WEB = path.join(HERE, '..', '..', 'web');
const ENGINE = fs.readFileSync(path.join(WEB, 'keeper_audio.js'), 'utf8');
const STAGES = fs.readFileSync(path.join(WEB, 'stage_audio.js'), 'utf8');
const MENUS = fs.readFileSync(path.join(WEB, 'menu_audio.js'), 'utf8');
if (!['keepers', 'stages', 'menus', 'all'].includes(PACK)) { console.error('pack must be keepers, stages, menus or all'); process.exit(2); }

const camel = id => id.replace(/^(stage|menu|ship)_/, '').split('_').map(p => p[0].toUpperCase() + p.slice(1)).join('');

function wav(samples, rate){
  const data = Buffer.alloc(samples.length * 2);
  for (let i = 0; i < samples.length; i++){
    const s = Math.max(-1, Math.min(1, samples[i]));
    data.writeInt16LE(Math.round(s * 32767), i * 2);
  }
  const h = Buffer.alloc(44);
  h.write('RIFF', 0); h.writeUInt32LE(36 + data.length, 4); h.write('WAVE', 8);
  h.write('fmt ', 12); h.writeUInt32LE(16, 16); h.writeUInt16LE(1, 20); h.writeUInt16LE(1, 22);
  h.writeUInt32LE(rate, 24); h.writeUInt32LE(rate * 2, 28); h.writeUInt16LE(2, 32); h.writeUInt16LE(16, 34);
  h.write('data', 36); h.writeUInt32LE(data.length, 40);
  return Buffer.concat([h, data]);
}

(async () => {
  const browser = await chromium.launch(process.env.PLAYWRIGHT_BROWSERS_PATH ? {} : {});
  const page = await browser.newPage();
  await page.setContent('<html><body></body></html>');
  await page.addScriptTag({ content: ENGINE });
  await page.addScriptTag({ content: STAGES });
  await page.addScriptTag({ content: MENUS });

  const plan = await page.evaluate(({ ambLoop }) => {
    const K = window.KeeperAudio;
    const gcd = (a, b) => b ? gcd(b, a % b) : a, lcm = (a, b) => a * b / gcd(a, b);
    // every id belongs to one pack: stage_*, menu_* / ship_*, or a Keeper
    const packOf = id => /^stage_/.test(id) ? 'stages' : /^(menu|ship)_/.test(id) ? 'menus' : 'keepers';
    const themes = Object.keys(K.COMPILED).map(id => {
      const t = K.COMPILED[id];
      const steps = lcm(lcm(t.bass.length, t.lead.length), t.drums.length);
      return { id, pack: packOf(id), steps, loop: steps * t.stepDur, bpm: t.bpm };
    });
    const voices = [];
    for (const id in K.VOICES) {
      const pack = packOf(id);
      const cues = pack === 'keepers' ? K.CUES : Object.keys(K.VOICES[id]);
      for (const cue of cues) {
        const layers = K.VOICES[id][cue]; if (!layers) continue;
        const end = Math.max(...layers.map(L => (L.at || 0) + (L.rep ? (L.rep - 1) * (L.gap || 0) : 0) + L.d));
        voices.push({ id, pack, cue, end });
      }
    }
    const ambience = Object.keys(K.AMBIENCE).filter(id => packOf(id) !== 'keepers').map(id => {
      // a steady pulse (every [p, p]) must land on the loop point, or the crossfade doubles a beat
      const fixed = K.AMBIENCE[id].events.filter(E => E.every[0] === E.every[1]).map(E => E.every[0]);
      const loop = fixed.length ? Math.round(ambLoop / fixed[0]) * fixed[0] : ambLoop;
      return { id, pack: packOf(id), loop };
    });
    return { themes, voices, ambience };
  }, { ambLoop: AMB_LOOP });

  // Render in the page, hand back 16-bit PCM as base64 (small enough to pass through evaluate).
  const render = (kind, args, rate) => page.evaluate(async ({ kind, args, rate, gain, fade, warm }) => {
    const K = window.KeeperAudio;
    let ctx, from, to;
    if (kind === 'ambience'){
      const { id, loop } = args;
      const total = warm + loop + fade + 2;
      ctx = new OfflineAudioContext(1, Math.ceil(total * rate), rate);
      K.createEngine(ctx, ctx.destination).scheduleAmbience(id, total, 0);
      from = Math.round(warm * rate); to = from + Math.round((loop + fade) * rate);
    } else if (kind === 'theme'){
      const { id, loop, lvl } = args;
      ctx = new OfflineAudioContext(1, Math.ceil((2 * loop + 0.25) * rate), rate);
      K.createEngine(ctx, ctx.destination).scheduleTheme(id, 2 * loop - 1e-6, lvl, 1e-6);
      from = Math.round(loop * rate); to = Math.round(2 * loop * rate);
    } else {
      const { id, cue, end } = args;
      ctx = new OfflineAudioContext(1, Math.ceil((end + 0.6) * rate), rate);
      K.createEngine(ctx, ctx.destination).voice(id, cue, 0.01);
      from = 0; to = ctx.length;
    }
    const buf = await ctx.startRendering();
    let ch = buf.getChannelData(0).subarray(from, to).map(s => s * gain);
    if (kind === 'ambience'){                             // fold the extra tail over the head: an equal-power crossfade
      const F = Math.round(fade * rate), N = ch.length - F, out = ch.slice(0, N);
      for (let i = 0; i < F; i++){ const x = i / F; out[i] = ch[i] * Math.sqrt(x) + ch[N + i] * Math.sqrt(1 - x); }
      ch = out;
    }
    let peak = 0; for (const s of ch) peak = Math.max(peak, Math.abs(s));
    if (kind === 'voice'){                                // trim the silence after the tail, with a 10 ms fade
      let last = ch.length - 1; while (last > 0 && Math.abs(ch[last]) < 0.0005) last--;
      const n = Math.min(ch.length, last + Math.round(0.02 * rate));
      ch = ch.slice(0, n);
      const f = Math.round(0.01 * rate); for (let i = 0; i < f && i < n; i++) ch[n - 1 - i] *= i / f;
    }
    const pcm = new Int16Array(ch.length);
    for (let i = 0; i < ch.length; i++) pcm[i] = Math.round(Math.max(-1, Math.min(1, ch[i])) * 32767);
    const bytes = new Uint8Array(pcm.buffer); let bin = '';
    for (let i = 0; i < bytes.length; i += 0x8000) bin += String.fromCharCode.apply(null, bytes.subarray(i, i + 0x8000));
    return { b64: btoa(bin), peak, seconds: ch.length / rate };
  }, { kind, args, rate, gain: GAIN, fade: AMB_FADE, warm: AMB_WARMUP });

  const save = (file, r, rate) => {
    const pcm = Buffer.from(r.b64, 'base64');
    const samples = new Float32Array(pcm.length / 2);
    for (let i = 0; i < samples.length; i++) samples[i] = pcm.readInt16LE(i * 2) / 32767;
    fs.mkdirSync(path.dirname(file), { recursive: true });
    fs.writeFileSync(file, wav(samples, rate));
  };

  const report = { gain: GAIN, music: [], voices: [], ambience: [] };
  const wanted = item => PACK === 'all' || PACK === item.pack;
  const dir = item => path.join(ROOT, { keepers: 'Keepers', stages: 'Stages', menus: 'Menus' }[item.pack]);
  const prefix = item => item.id.startsWith('ship_') ? 'Ship' : { keepers: 'Keeper', stages: 'Stage', menus: 'Menu' }[item.pack];
  const title = s => s[0].toUpperCase() + s.slice(1);
  for (const t of plan.themes.filter(wanted)){
    for (const lvl of [1, 2, 3]){
      const r = await render('theme', { id: t.id, loop: t.loop, lvl }, RATE);
      const name = `MUS_${prefix(t)}_${camel(t.id)}_L${lvl}`;
      save(path.join(dir(t), 'Music', name + '.wav'), r, RATE);
      report.music.push({ name, bpm: t.bpm, steps: t.steps, seconds: +r.seconds.toFixed(4), peak: +r.peak.toFixed(3) });
    }
  }
  for (const v of plan.voices.filter(wanted)){
    const r = await render('voice', v, RATE);
    const name = `SFX_${prefix(v)}_${camel(v.id)}_${title(v.cue)}`;
    save(path.join(dir(v), v.pack === 'keepers' ? 'Voices' : 'Cues', name + '.wav'), r, RATE);
    report.voices.push({ name, seconds: +r.seconds.toFixed(3), peak: +r.peak.toFixed(3) });
  }
  for (const a of plan.ambience.filter(wanted)){
    const r = await render('ambience', a, AMB_RATE);
    const name = `AMB_${prefix(a)}_${camel(a.id)}`;
    save(path.join(dir(a), 'Ambience', name + '.wav'), r, AMB_RATE);
    report.ambience.push({ name, seconds: +r.seconds.toFixed(3), peak: +r.peak.toFixed(3) });
  }
  await browser.close();
  console.log(JSON.stringify(report, null, 1));
})().catch(e => { console.error(e); process.exit(1); });
