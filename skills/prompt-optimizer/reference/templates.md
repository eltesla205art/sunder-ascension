# Output templates by mode

Fill in the brackets. Remove any section that doesn't apply rather than padding it out.
Keep every `{{variable}}` from the input exactly as written.

---

## user-basic

Plain prose. The original request, rewritten with:
- the goal stated up front
- the context the model needs (who it's for, why, background facts)
- the expected result (format, length, depth)
- any constraints the author implied

## user-professional

Same as user-basic, and also:
- each abstract term swapped for a measurable one ("short" → "under 150 words";
  "modern" → "uses ES2022+, no jQuery")
- the scope and its boundaries (what's in and what's out)
- one short example of the expected output, when it helps
- leave some flexibility; don't over-specify creative choices

## user-planning

```markdown
# Task: [title derived from the request]

## 1. Role and Goal
You will act as [best-fit expert]. Your goal is to [specific, measurable result].

## 2. Background and Context
[Key background the original request implied, or "None".]

## 3. Key Steps
1. **[Step name]**: [what to do]
2. **[Step name]**: [what to do]
3. **[Step name]**: [what to do]

## 4. Output Requirements
- **Format**: [markdown table / JSON / list / prose …]
- **Style**: [tone, register, audience]
- **Constraints**:
  - [rule]
  - [rule]
  - Respond with the final result only, without step narration.
```

## system-general

```markdown
# Role: [Role name]

## Profile
- language: [language]
- description: [what this assistant is and does]
- background: [relevant expertise and experience]
- personality: [tone and demeanor]
- expertise: [domains]
- target_audience: [who it serves]

## Skills
1. [Core skill group]
   - [skill]: [one line]
2. [Supporting skill group]
   - [skill]: [one line]

## Rules
1. Principles:
   - [rule]: [detail]
2. Behavior:
   - [rule]: [detail]
3. Constraints:
   - [hard limit]: [detail]

## Workflows
- Goal: [objective]
- Step 1: [...]
- Step 2: [...]
- Step 3: [...]
- Expected result: [...]

## Initialization
As [Role name], follow the Rules and carry out tasks according to the Workflows.
```

## system-output-format

system-general, plus the following section before Initialization:

```markdown
## OutputFormat
1. Format:
   - type: [text / markdown / json / …]
   - structure: [sections or schema]
   - style: [...]
2. Validation:
   - [rule the output must pass, e.g. valid JSON, all fields present]
   - error_handling: [what to do when input is missing or invalid]
3. Examples:
   - Example 1: [short, realistic sample output]
```

The Initialization line should end with "…and respond in the OutputFormat."

## system-analytical

First, reason internally about the goal, the users, likely failure modes, and ambiguous inputs.
Then produce system-general or system-output-format, adding:
- an **Edge cases** list under Rules (empty input, off-topic request, conflicting instructions)
- explicit **refusal / escalation** behavior, if the domain calls for it
- a **Quality bar** line that says what a good answer must include

## iterate

Return the full original prompt with the requirement worked in. Examples:

| Original | Requirement | Correct result | Wrong |
|---|---|---|---|
| "You are a support assistant, help users solve problems" | "No back-and-forth" | …add: "Give a complete solution in one reply; don't ask confirming questions." | Replying "OK, I won't ask questions." |
| "Analyze the data and give suggestions" | "JSON output" | …add: "Return the analysis as JSON: {findings:[], suggestions:[]}" | Replying with JSON |
| "You are a writing assistant" | "More professional" | "You are a professional writing consultant with …" | Answering in a more formal tone |

## image-t2i (natural language)

Write 3–6 coherent sentences. Don't use tag lists, weights like `(word:1.3)`, seeds or steps.
Cover the following:
1. **Subject**: 2–3 precise modifiers, plus one action or interaction
2. **Environment**: a recognizable setting, and what's in the foreground, midground and background
3. **Composition**: shot distance, camera angle, aspect ratio (keep the original wording, e.g. "4:5 portrait")
4. **Light and time**: quality and direction of light, time of day, and what the light does to the subject
5. **Color and material**: main palette and contrast, textures (film grain, brushed metal, paper)
6. **Mood and style**: a few style words that tie it together

If the input is JSON, return JSON with the same keys and rewrite only the visual-description strings.
Keep all hard constraints, including counts, text to render, forbidden items and "avoid …" phrases.

## image-edit (image-to-image / multi-image)

- **Change**: exactly what to change, and where
- **Keep**: identity, pose, layout, text, brand marks, or anything else that must stay the same
- **References**: for multiple images, which image supplies what (e.g. "image 1 = subject, image 2 = style")
- **Finish**: lighting and color should match the source so the edit blends in
