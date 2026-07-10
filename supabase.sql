-- SUNDER: Ascension — run this once in your Supabase project (SQL editor)
create table if not exists leaderboard (
  id bigint generated always as identity primary key,
  initials text not null check (char_length(initials) <= 3),
  score integer not null check (score >= 0),
  stage integer not null default 1,
  mode text not null default 'story',
  created_at timestamptz not null default now()
);
create table if not exists signups (
  id bigint generated always as identity primary key,
  email text not null,
  created_at timestamptz not null default now()
);
create table if not exists comments (
  id bigint generated always as identity primary key,
  name text,
  text text not null check (char_length(text) <= 280),
  created_at timestamptz not null default now()
);
alter table leaderboard enable row level security;
alter table signups enable row level security;
alter table comments enable row level security;
create policy "public read scores"  on leaderboard for select using (true);
create policy "public write scores" on leaderboard for insert with check (true);
create policy "public write signups" on signups for insert with check (true);
create policy "public read comments"  on comments for select using (true);
create policy "public write comments" on comments for insert with check (true);
