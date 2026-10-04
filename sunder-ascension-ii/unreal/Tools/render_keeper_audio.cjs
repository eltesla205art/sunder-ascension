// SUNDER: Ascension II — render the Keepers' music and voices from the web game's synth (web/keeper_audio.js) to WAV
// for Unreal, so both versions sound the same.
//
//   node unreal/Tools/render_keeper_audio.cjs [out_dir] [sample_rate] [gain]
//   (defaults: unreal/Content/Audio/Keepers, 32000, 1.6; needs Playwright with Chromium: npm i -g playwright)
//
// Music: every theme × layer 1, 2, 3 (MUS_Keeper_<Name>_L<n>.wav). Each file is exactly one loop, cut from the second
// pass of two so notes ringing over the loop point are already at its start: the loops are seamless, and the three
// layers of a theme are the same length so they can play in sync and crossfade with the Keeper's phase.
// Voices: every Keeper × intro, attack, phase, hurt, death (SFX_Keeper_<Name>_<Cue>.wav), trimmed after the tail.
// Mono, 16-bit. Everything gets the same gain (default 1.6, +4 dB: the web game leans on the browser's volume), so
// music and voices keep the web game's balance; the loudest file peaks near −1.5 dBFS. Prints a JSON report (loop lengths, peaks) at the end.
'use strict';
const fs = require('fs');
const path = require('path');
let chromium;
try { ({ chromium } = require('playwright')); }
catch (e) { ({ chromium } = require(path.join(require('child_process').execSync('npm root -g').toString().trim(), 'playwright'))); }

const HERE = __dirname;
const OUT = path.resolve(process.argv[2] || path.join(HERE, '..', 'Content', 'Audio', 'Keepers'));
const RATE = Number(process.argv[3] || 32000);
const GAIN = Number(process.argv[4] || 1.6);
const ENGINE = fs.readFileSync(path.join(HERE, '..', '..', 'web', 'keeper_audio.js'), 'utf8');

const camel = id => id.split('_').map(p => p[0].toUpperCase() + p.slice(1)).join('');

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

  const plan = await page.evaluate(() => {
    const K = window.KeeperAudio;
    const gcd = (a, b) => b ? gcd(b, a % b) : a, lcm = (a, b) => a * b / gcd(a, b);
    const themes = Object.keys(K.COMPILED).map(id => {
      const t = K.COMPILED[id];
      const steps = lcm(lcm(t.bass.length, t.lead.length), t.drums.length);
      return { id, steps, loop: steps * t.stepDur, bpm: t.bpm };
    });
    const voices = [];
    for (const id in K.VOICES) for (const cue of K.CUES) {
      const layers = K.VOICES[id][cue]; if (!layers) continue;
      const end = Math.max(...layers.map(L => (L.at || 0) + (L.rep ? (L.rep - 1) * (L.gap || 0) : 0) + L.d));
      voices.push({ id, cue, end });
    }
    return { themes, voices };
  });

  // Render in the page, hand back 16-bit PCM as base64 (small enough to pass through evaluate).
  const render = (kind, args) => page.evaluate(async ({ kind, args, rate, gain }) => {
    const K = window.KeeperAudio;
    let ctx, from, to;
    if (kind === 'theme'){
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
  }, { kind, args, rate: RATE, gain: GAIN });

  const save = (file, r) => {
    const pcm = Buffer.from(r.b64, 'base64');
    const samples = new Float32Array(pcm.length / 2);
    for (let i = 0; i < samples.length; i++) samples[i] = pcm.readInt16LE(i * 2) / 32767;
    fs.mkdirSync(path.dirname(file), { recursive: true });
    fs.writeFileSync(file, wav(samples, RATE));
  };

  const report = { rate: RATE, gain: GAIN, music: [], voices: [] };
  for (const t of plan.themes){
    for (const lvl of [1, 2, 3]){
      const r = await render('theme', { id: t.id, loop: t.loop, lvl });
      const name = `MUS_Keeper_${camel(t.id)}_L${lvl}`;
      save(path.join(OUT, 'Music', name + '.wav'), r);
      report.music.push({ name, bpm: t.bpm, steps: t.steps, seconds: +r.seconds.toFixed(4), peak: +r.peak.toFixed(3) });
    }
  }
  for (const v of plan.voices){
    const r = await render('voice', v);
    const name = `SFX_Keeper_${camel(v.id)}_${v.cue[0].toUpperCase() + v.cue.slice(1)}`;
    save(path.join(OUT, 'Voices', name + '.wav'), r);
    report.voices.push({ name, seconds: +r.seconds.toFixed(3), peak: +r.peak.toFixed(3) });
  }
  await browser.close();
  console.log(JSON.stringify(report, null, 1));
})().catch(e => { console.error(e); process.exit(1); });
