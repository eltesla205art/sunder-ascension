// SUNDER: Ascension II — export the story's words from the web game (web/game.html) for Unreal, so both tell it the
// same: the opening crawl, each Hour's name, act, Keeper, briefing and gate-open line, the act interludes, the dawn
// ending and DAWN DENIED. create_story_level.py reads the JSON into DA_StoryData.
//
//   node unreal/Tools/export_story_text.cjs [out.json]     (default: unreal/Content/Story/story.json)
'use strict';
const fs = require('fs');
const path = require('path');

const OUT = path.resolve(process.argv[2] || path.join(__dirname, '..', 'Content', 'Story', 'story.json'));
const html = fs.readFileSync(path.join(__dirname, '..', '..', 'web', 'game.html'), 'utf8');

function grab(name){
  const m = html.match(new RegExp('const ' + name + ' = ([\\s\\S]*?);\\n'));
  if (!m) throw new Error('not found in game.html: ' + name);
  return Function('"use strict"; return (' + m[1] + ');')();
}
// STAGES holds SVG and asset references too; only the fields the story needs are read
const stagesSrc = html.match(/const STAGES = (\[[\s\S]*?\n\]);/);
if (!stagesSrc) throw new Error('not found in game.html: STAGES');
const STAGES = Function('"use strict"; return (' + stagesSrc[1] + ');')();

const OPENING = grab('OPENING'), INTERLUDES = grab('INTERLUDES'), VICTORY_TEXT = grab('VICTORY_TEXT');
const DEFEAT_TAG = grab('DEFEAT_TAG'), CLEAR_LINES = grab('CLEAR_LINES'), BRIEFINGS = grab('BRIEFINGS');

const story = {
  opening: OPENING,
  victory: VICTORY_TEXT,
  defeat: DEFEAT_TAG,
  hours: STAGES.map(s => ({
    num: s.num,
    name: s.name,
    subtitle: s.subtitle,
    keeper: s.boss_name,
    keeper_id: (s.art || '').replace(/^keeper_/, ''),
    stage: (s.stage || '').replace(/^stage_/, ''),
    tint: s.tint,
    quote: (BRIEFINGS[s.num] || {}).quote || '',
    brief: (BRIEFINGS[s.num] || {}).brief || '',
    clear: CLEAR_LINES[s.num] || '',
    interlude: INTERLUDES[s.num + 1] || '',          // shown when this Hour is cleared and a new act begins
  })),
};
fs.mkdirSync(path.dirname(OUT), { recursive: true });
fs.writeFileSync(OUT, JSON.stringify(story, null, 1) + '\n');
console.log('wrote ' + OUT + ': ' + story.hours.length + ' hours, ' + story.hours.filter(h => h.interlude).length + ' interludes');
