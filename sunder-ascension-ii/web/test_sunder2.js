// SUNDER II headless test: extracts the game script from game.html and checks the
// 12-Hour campaign against the battle-math law.   Run: node test_sunder2.js
const fs = require('fs');
const path = require('path');
const assert = require('assert');

const html = fs.readFileSync(path.join(__dirname, 'game.html'), 'utf8');
const scripts = [...html.matchAll(/<script>([\s\S]*?)<\/script>/g)].map(m => m[1]);
const src = scripts.sort((a, b) => b.length - a.length)[0];
const tmp = path.join(require('os').tmpdir(), 'sunder2_test_' + process.pid + '.js');
fs.writeFileSync(tmp, src);
const g = require(tmp);
fs.unlinkSync(tmp);
const { G, STAGES, SHIPS, INTERLUDES } = g;

let passed = 0;
function test(name, fn){ fn(); passed++; console.log('ok  -', name); }
function run(sec){ for (let i = 0; i < sec * 60; i++) g.update(1/60); }

test('12 Hours, 4 acts, numbered 1..12', () => {
  assert.strictEqual(STAGES.length, 12);
  STAGES.forEach((s, i) => assert.strictEqual(s.num, i + 1));
  assert.deepStrictEqual(Object.keys(INTERLUDES).map(Number), [4, 7, 10]);
});

test('difficulty never eases off between Hours', () => {
  for (let i = 1; i < 12; i++){
    const a = STAGES[i-1], b = STAGES[i];
    assert(b.boss_health >= a.boss_health, 'boss_health ' + b.num);
    assert(b.score_to_boss >= a.score_to_boss, 'score_to_boss ' + b.num);
    assert(b.enemy_bullet_speed >= a.enemy_bullet_speed, 'bullet speed ' + b.num);
    assert(b.spawn_interval <= a.spawn_interval, 'spawn interval ' + b.num);
  }
});

test('full campaign obeys the battle-math law, Hour 1 to victory', () => {
  G.shipIndex = 0;
  g.launchCampaign();
  assert.strictEqual(G.state, 'OPENING');
  for (let i = 0; i < 12; i++){
    g.beginStage(i);
    assert.strictEqual(G.state, 'BRIEFING');
    assert(G.banner.startsWith('HOUR ' + (i + 1) + ' / 12'), G.banner.slice(0, 20));
    g.startPlaying();
    const cfg = G.cfg;
    // law 4: stage length
    assert.strictEqual(g.bossThreshold(cfg), Math.round(cfg.score_to_boss * 1.6));
    G.player.hp = 99;
    G.stageScore = g.bossThreshold(cfg);
    // play on until the Keeper arrives, tapping fire through the taunt card like a player
    for (let k = 0; k < 60 * 20 && !G.boss; k++){ G.player.hp = 99; g.input.fire = k % 2 === 0; g.update(1/60); }
    g.input.fire = false;
    assert(G.boss, 'boss spawned in hour ' + cfg.num + ' (state ' + G.state + ')');
    // law 2: boss hull
    assert.strictEqual(G.boss.maxHp, Math.round(cfg.boss_health * 1.3 / 10) * 10);
    // law 3: boss bullets deal 2 from Hour 7, enemy bullets always 1
    for (let k = 0; k < 600; k++){ G.player.hp = 99; g.update(1/60); }
    const bossDmg = new Set(G.eBullets.map(b => b.dmg));
    if (G.eBullets.length){
      for (const d of bossDmg) assert(d === 1 || d === (cfg.num >= 7 ? 2 : 1), 'hour ' + cfg.num + ' dmg ' + d);
      if (cfg.num < 7) assert(!bossDmg.has(2), 'hour ' + cfg.num + ' has 2-damage bullets');
    }
    if (cfg.num >= 7) assert(bossDmg.has(2), 'hour ' + cfg.num + ': no 2-damage boss bullets seen');
    const before = { hp: 1, bombs: G.player.bombs, shield: G.player.shield };
    G.player.hp = 1;
    g.bossTakeDamage(1e9);
    if (i < 11){
      assert.strictEqual(G.state, 'STAGE_CLEAR');
      // law 5: +1 life, +1 bomb, +1 shield, with caps
      assert.strictEqual(G.player.hp, Math.min(before.hp + 1, G.player.maxHp + 2));
      assert.strictEqual(G.player.bombs, Math.min(before.bombs + 1, 9));
      assert.strictEqual(G.player.shield, Math.min(before.shield + 1, 3));
      assert(G.banner.startsWith('HOUR ' + cfg.num + ' SURVIVED'));
      if (INTERLUDES[cfg.num + 1]) assert(G.banner.includes(INTERLUDES[cfg.num + 1].split('\n')[0]));
    } else {
      assert.strictEqual(G.state, 'VICTORY');
      assert(G.banner.includes('ASCENSION COMPLETE.'));
    }
  }
});

test('every ship flies a full Hour without errors', () => {
  for (let s = 0; s < SHIPS.length; s++){
    G.shipIndex = s;
    g.launchCampaign();
    g.beginStage(0);
    g.startPlaying();
    for (let k = 0; k < 60 * 30; k++){ G.player.hp = 99; g.input.fire = true; g.update(1/60); }
    g.input.fire = false;
    assert(G.totalScore > 0, SHIPS[s].id + ' scored nothing in 30 s');
  }
});

test('swarm mode survives an 80 s soak', () => {
  G.shipIndex = 0;
  g.startSwarm();
  for (let k = 0; k < 60 * 80; k++){ if (G.player) G.player.hp = 99; g.input.fire = G.state === 'PLAYING' || k % 2 === 0; g.update(1/60); }
  g.input.fire = false;
  assert(['PLAYING', 'BRIEFING'].includes(G.state), G.state);
});

test('defeat banner says DAWN DENIED', () => {
  G.shipIndex = 0;
  g.launchCampaign();
  g.beginStage(6);
  g.startPlaying();
  G.player.hp = 1; G.player.shield = 0; G.player.inv = false;
  g.playerTakeDamage(5);
  for (let k = 0; k < 60 && G.state !== 'DEFEAT'; k++) g.update(1/60);
  assert.strictEqual(G.state, 'DEFEAT');
  assert(G.banner.startsWith('DAWN DENIED\n\nHour 7'));
});

test('every Hour has a Blender Keeper and its own stage backdrop', () => {
  for (const st of STAGES) assert(/^keeper_/.test(st.art), 'Hour ' + st.num + ' art ' + st.art);
  for (const st of STAGES) assert(/^stage_/.test(st.stage || '') && new RegExp(st.stage + ':').test(src), 'Hour ' + st.num + ' has no embedded stage backdrop');
  assert.strictEqual(new Set(STAGES.map(st => st.stage)).size, 12, 'two Hours share a backdrop');
  assert(/keeper_apep_p3:/.test(src), "Apep's final-phase render is not embedded");
});

test('every image the game references ships in web/assets as a real WebP', () => {
  const refs = [...new Set(src.match(/assets\/[a-z0-9_]+\.webp/g))];
  assert(refs.length >= 43, 'expected the Blender art set, found ' + refs.length);
  for (const r of refs){
    const f = path.join(__dirname, r);
    assert(fs.existsSync(f), r + ' is missing');
    const head = fs.readFileSync(f).subarray(0, 12).toString('latin1');
    assert(head.startsWith('RIFF') && head.endsWith('WEBP'), r + ' is not WebP');
  }
  assert(!/data:image\/webp/.test(src), 'art is still embedded in game.html');
});

test('sequel never talks to the Part 1 leaderboard', () => {
  assert.strictEqual(g.SUNDER_CONFIG.SUPABASE_URL, '');
  assert.strictEqual(g.SUNDER_CONFIG.SUPABASE_ANON_KEY, '');
  assert(!/sunder_scores'/.test(src), 'still uses the Part 1 localStorage key');
});

console.log('\n' + passed + ' tests passed');
