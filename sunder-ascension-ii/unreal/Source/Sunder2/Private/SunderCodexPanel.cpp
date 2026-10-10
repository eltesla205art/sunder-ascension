// SUNDER: Ascension II — the Codex panel.
#include "SunderCodexPanel.h"

#include "Components/AudioComponent.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "GameFramework/HUD.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "SunderCodexStage.h"
#include "SunderCodexSubsystem.h"
#include "SunderSettingsSubsystem.h"

#include "SunderCodexEntries.inl"

namespace
{
	const TCHAR* Tabs[3] = { TEXT("KEEPERS"), TEXT("HOURS"), TEXT("SHIPS") };
	const TCHAR* ActNames[5] = { TEXT(""), TEXT("ACT I: DUSK"), TEXT("ACT II: MIDNIGHT"), TEXT("ACT III: THE DEEP NIGHT"), TEXT("ACT IV: DAWN OR NOTHING") };
	FLinearColor AccentOf(uint32 Hex) { return FLinearColor(FColor((Hex >> 16) & 255, (Hex >> 8) & 255, Hex & 255)); }
	void Frame(AHUD* Hud, float X, float Y, float W, float H, const FLinearColor& C, float T)
	{
		Hud->DrawRect(C, X, Y, W, T); Hud->DrawRect(C, X, Y + H - T, W, T);
		Hud->DrawRect(C, X, Y + T, T, H - 2.f * T); Hud->DrawRect(C, X + W - T, Y + T, T, H - 2.f * T);
	}
	FLinearColor Faded(const FLinearColor& C, float A) { return FLinearColor(C.R, C.G, C.B, FMath::Clamp(A, 0.f, 1.f)); }
	float ScaleFor(AHUD* Hud, UFont* Font, float Px)
	{
		float W = 0.f, H = 0.f;
		Hud->GetTextSize(TEXT("Ay"), W, H, Font, 1.f);
		return H > 0.f ? Px * (Hud->Canvas->ClipY / 720.f) * 1.25f / H : 1.f;
	}
}

void FSunderCodexPanel::Open(float Now, const UObject* WorldContext)
{
	OpenedAt = Now;
	PlayingHour = 0;
	PlayKeeper(WorldContext);
}

bool FSunderCodexPanel::ToggleSound(const UObject* WorldContext)
{
	bSound = !bSound;
	if (bSound) { PlayingHour = 0; PlayKeeper(WorldContext); }
	else { StopSound(0.4f); }
	return bSound;
}

void FSunderCodexPanel::StopSound(float FadeOut)
{
	if (UAudioComponent* Old = Theme.Get())
	{
		Old->bAutoDestroy = true;                               // fades out, then cleans itself up
		Old->FadeOut(FadeOut, 0.f);
	}
	Theme.Reset();
	PlayingHour = 0;
}

void FSunderCodexPanel::PlayKeeper(const UObject* WorldContext)
{
	// The web Codex's show(): with SOUND on, the chosen Keeper's theme at its full layer (startTheme(id, 2)) and its
	// intro line (voice(id, 'intro')). A Keeper not yet met stays silent. Both are UI sounds, so they play in the pause.
	if (!bSound || Tab != 0 || !WorldContext) { return; }
	const FSunderCodexKeeper& K = GCodexKeepers[Index[0]];
	if (K.Hour == PlayingHour) { return; }
	StopSound(0.3f);
	const USunderCodexSubsystem* Codex = USunderCodexSubsystem::Get(WorldContext);
	if (!Codex || !Codex->IsMet(K.Hour)) { return; }
	PlayingHour = K.Hour;
	DuckGain = 1.f;
	const FString Theme2 = FString::Printf(TEXT("MUS_Keeper_%s_L2"), K.Id), Intro = FString::Printf(TEXT("SFX_Keeper_%s_Intro"), K.Id);
	if (USoundBase* Music = LoadObject<USoundBase>(nullptr, *FString::Printf(TEXT("/Game/Sunder/Audio/Keepers/Music/%s.%s"), *Theme2, *Theme2)))
	{
		ThemeGain = USunderSettingsSubsystem::MusicGain(WorldContext);
		if (UAudioComponent* C = UGameplayStatics::CreateSound2D(WorldContext, Music, 1.f, 1.f, 0.f, nullptr, false, false))
		{
			C->bIsUISound = true;
			C->FadeIn(0.4f, ThemeGain);                          // the loop is set to repeat by create_keeper_audio.py
			Theme.Reset(C);
		}
	}
	if (USoundBase* Voice = LoadObject<USoundBase>(nullptr, *FString::Printf(TEXT("/Game/Sunder/Audio/Keepers/Voices/%s.%s"), *Intro, *Intro)))
	{
		UGameplayStatics::PlaySound2D(WorldContext, Voice, USunderSettingsSubsystem::EffectsGain(WorldContext), 1.f, 0.f, nullptr, nullptr, /*bIsUISound*/ true);
		VoiceAt = WorldContext->GetWorld() ? WorldContext->GetWorld()->GetRealTimeSeconds() : 0.f;
		DuckFor = Voice->GetDuration() * 0.7f;
	}
}

void FSunderCodexPanel::UpdateDuck(float Now) const
{
	// keeper_audio.js's duck: the music bus to 0.4 of 0.85 in 0.08 s, held for 70 % of the line, back over 0.6 s.
	UAudioComponent* C = Theme.Get();
	if (!C) { return; }
	const float T = Now - VoiceAt;
	const float Low = 0.4f / 0.85f;
	const float Want = T < 0.f || T > DuckFor + 0.6f ? 1.f
		: T < 0.08f ? FMath::Lerp(1.f, Low, T / 0.08f)
		: T < DuckFor ? Low : FMath::Lerp(Low, 1.f, (T - DuckFor) / 0.6f);
	if (FMath::IsNearlyEqual(Want, DuckGain, 0.001f)) { return; }
	DuckGain = Want;
	C->AdjustVolume(0.05f, ThemeGain * Want);
}

int32 FSunderCodexPanel::Count() const
{
	return Tab == 0 ? UE_ARRAY_COUNT(GCodexKeepers) : Tab == 1 ? UE_ARRAY_COUNT(GCodexHours) : UE_ARRAY_COUNT(GCodexShips);
}

bool FSunderCodexPanel::Navigate(int32 X, int32 Y, float Now, const UObject* WorldContext)
{
	if (X != 0) { Tab = (Tab + (X > 0 ? 1 : -1) + 3) % 3; OpenedAt = Now; return true; }
	if (Y != 0) { Index[Tab] = (Index[Tab] - Y + Count()) % Count(); MovedAt = Now; PlayKeeper(WorldContext); return true; }   // up is +1
	return false;
}

UTexture2D* FSunderCodexPanel::Portrait(int32 i) const
{
	// The Keeper portraits create_story_level.py imports (art/blender/keepers), loaded on first sight.
	if (Portraits.Num() < UE_ARRAY_COUNT(GCodexKeepers)) { Portraits.SetNum(UE_ARRAY_COUNT(GCodexKeepers)); }
	if (!Portraits[i].IsValid()) { Portraits[i].Reset(LoadObject<UTexture2D>(nullptr, GCodexKeepers[i].Portrait)); }
	return Portraits[i].Get();
}

float FSunderCodexPanel::DrawWrapped(AHUD* Hud, const FString& Text, const FLinearColor& Color, float X, float Y, float Width, float Px) const
{
	// Left-aligned text wrapped to Width, paragraphs on blank lines; returns the Y below it.
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	const float Scale = ScaleFor(Hud, Font, Px);
	float LW = 0.f, LH = 0.f;
	Hud->GetTextSize(TEXT("Ay"), LW, LH, Font, Scale);
	TArray<FString> Paragraphs;
	Text.ParseIntoArray(Paragraphs, TEXT("\n"), false);
	for (const FString& Paragraph : Paragraphs)
	{
		if (Paragraph.IsEmpty()) { Y += LH * 0.5f; continue; }
		TArray<FString> Words;
		Paragraph.ParseIntoArrayWS(Words);
		FString Line;
		for (const FString& Word : Words)
		{
			const FString Try = Line.IsEmpty() ? Word : Line + TEXT(" ") + Word;
			float TW = 0.f, TH = 0.f;
			Hud->GetTextSize(Try, TW, TH, Font, Scale);
			if (TW > Width && !Line.IsEmpty()) { Hud->DrawText(Line, Color, X, Y, Font, Scale); Y += LH * 1.1f; Line = Word; }
			else { Line = Try; }
		}
		if (!Line.IsEmpty()) { Hud->DrawText(Line, Color, X, Y, Font, Scale); Y += LH * 1.1f; }
	}
	return Y;
}

void FSunderCodexPanel::Draw(AHUD* Hud, const USunderCodexSubsystem* Codex, float Now) const
{
	if (!Hud || !Hud->Canvas) { return; }
	UpdateDuck(Now);
	const float W = Hud->Canvas->ClipX, H = Hud->Canvas->ClipY, S = H / 720.f;
	const float A = FMath::Clamp((Now - OpenedAt) / 0.25f, 0.f, 1.f);
	const FLinearColor Gold(0.96f, 0.84f, 0.48f), Gilt(0.83f, 0.69f, 0.22f), Sky(0.56f, 0.89f, 1.f), Sand(0.79f, 0.70f, 0.41f),
		Pale(0.85f, 0.85f, 0.9f), Dim(0.45f, 0.45f, 0.52f);
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	auto Centre = [&](const FString& Text, const FLinearColor& Color, float BaselineY, float Px)
	{
		const float Scale = ScaleFor(Hud, Font, Px);
		float TW = 0.f, TH = 0.f;
		Hud->GetTextSize(Text, TW, TH, Font, Scale);
		Hud->DrawText(Text, Color, (W - TW) * 0.5f, BaselineY * S - TH * 0.8f, Font, Scale);
	};

	// The glass panel (the settings' style), the title and the tabs.
	const float PW = FMath::Min(W * 0.92f, 900.f * S), PX = (W - PW) * 0.5f, PY = 118.f * S, PH = 530.f * S;
	Hud->DrawRect(FLinearColor(0.043f, 0.059f, 0.165f, 0.86f * A), PX, PY, PW, PH);
	for (const float Y : { PY, PY + PH }) { Hud->DrawLine(PX, Y, PX + PW, Y, Faded(Gilt, A), 1.f); }
	for (const float X : { PX, PX + PW }) { Hud->DrawLine(X, PY, X, PY + PH, Faded(Gilt, A), 1.f); }
	Centre(TEXT("CODEX"), Faded(Gold, A), 62.f, 30.f);
	{
		const float TabScale = ScaleFor(Hud, Font, 14.f);
		float X = 0.f, Total = 0.f;
		for (int32 t = 0; t < 3; ++t) { float TW = 0.f, TH = 0.f; Hud->GetTextSize(Tabs[t], TW, TH, Font, TabScale); Total += TW + (t ? 48.f * S : 0.f); }
		X = (W - Total) * 0.5f;
		for (int32 t = 0; t < 3; ++t)
		{
			float TW = 0.f, TH = 0.f;
			Hud->GetTextSize(Tabs[t], TW, TH, Font, TabScale);
			const bool bOn = t == Tab;
			Hud->DrawText(Tabs[t], Faded(bOn ? Sky : Sand, A), X, 92.f * S - TH * 0.5f, Font, TabScale);
			if (bOn) { Hud->DrawRect(Faded(Sky, A), X, 92.f * S + TH * 0.55f, TW, 2.f * S); }
			X += TW + 48.f * S;
		}
	}

	if (Tab == 0)
	{
		DrawKeepers(Hud, Codex, PX, PY, PW, PH, A, Now);
		Centre(TEXT("W / S  Keepers    ·    ENTER  sound    ·    A / D  tabs    ·    ESC  back"), Faded(Sand, A), 690.f, 12.f);
		return;
	}

	// The list on the left: number and name, or ??? while locked.
	const int32 N = Count(), Sel = Index[Tab];
	const float ListX = PX + 18.f * S, ListW = PW * 0.32f, RowH = FMath::Min(40.f * S, (PH - 30.f * S) / FMath::Max(N, 1));
	const float RowScale = ScaleFor(Hud, Font, 13.f);
	for (int32 i = 0; i < N; ++i)
	{
		FString Label;
		bool bOpen = true;
		if (Tab == 1)
		{
			bOpen = Codex && Codex->IsReached(GCodexHours[i].Num);
			FString Short = GCodexHours[i].Name;
			Short.RemoveFromStart(TEXT("Hour of "));
			Label = FString::Printf(TEXT("%2d  %s"), GCodexHours[i].Num, bOpen ? *Short.ToUpper() : TEXT("???"));
		}
		else { Label = GCodexShips[i].Name; }
		const float Y = PY + 15.f * S + i * RowH;
		const bool bOn = i == Sel;
		if (bOn) { Hud->DrawRect(Faded(Sky, 0.16f * A), ListX - 6.f * S, Y, ListW, RowH - 4.f * S); }
		float TW = 0.f, TH = 0.f;
		Hud->GetTextSize(Label, TW, TH, Font, RowScale);
		Hud->DrawText(Label, Faded(bOn ? FLinearColor(0.94f, 0.98f, 1.f) : bOpen ? Sand : Dim, A), ListX, Y + (RowH - 4.f * S - TH) * 0.5f, Font, RowScale);
	}
	Hud->DrawLine(PX + PW * 0.35f, PY + 14.f * S, PX + PW * 0.35f, PY + PH - 14.f * S, Faded(Gilt, 0.5f * A), 1.f);

	Centre(TEXT("W / S  entries    ·    A / D  tabs    ·    ESC  back"), Faded(Sand, A), 690.f, 12.f);

	// The entry on the right.
	const float DX = PX + PW * 0.38f, DW = PW * 0.58f;
	float Y = PY + 22.f * S;
	if (Tab == 1)
	{
		const FSunderCodexHour& Hr = GCodexHours[Sel];
		if (!Codex || !Codex->IsReached(Hr.Num))
		{
			Y = DrawWrapped(Hud, TEXT("???"), Faded(Dim, A), DX, Y, DW, 24.f);
			DrawWrapped(Hud, FString::Printf(TEXT("Gate %d is still closed."), Hr.Num), Faded(Sand, A), DX, Y + 8.f * S, DW, 13.f);
			return;
		}
		Y = DrawWrapped(Hud, FString::Printf(TEXT("HOUR %d"), Hr.Num), Faded(Sky, A), DX, Y, DW, 13.f);
		Y = DrawWrapped(Hud, FString(Hr.Name).ToUpper(), Faded(Gold, A), DX, Y, DW, 22.f);
		Y = DrawWrapped(Hud, Hr.Act, Faded(Sand, A), DX, Y + 2.f * S, DW, 12.f);
		Y = DrawWrapped(Hud, Hr.Quote, Faded(Gilt, A), DX, Y + 12.f * S, DW, 13.f);
		Y = DrawWrapped(Hud, Hr.Brief, Faded(Pale, A), DX, Y + 10.f * S, DW, 13.f);
		if (Codex->IsBeaten(Hr.Num) && FCString::Strlen(Hr.Clear) > 0)
		{
			DrawWrapped(Hud, FString::Printf(TEXT("GATE OPEN  ·  %s"), Hr.Clear), Faded(Sky, A), DX, Y + 14.f * S, DW, 12.f);
		}
	}
	else
	{
		const FSunderCodexShip& Sh = GCodexShips[Sel];
		Y = DrawWrapped(Hud, Sh.Name, Faded(Gold, A), DX, Y, DW, 22.f);
		Y = DrawWrapped(Hud, FString::Printf(TEXT("— %s —"), Sh.Class), Faded(Sky, A), DX, Y + 2.f * S, DW, 14.f);
		Y = DrawWrapped(Hud, Sh.Personality, Faded(Pale, A), DX, Y + 14.f * S, DW, 13.f);
		DrawWrapped(Hud, FString::Printf(TEXT("FORMS  %s"), Sh.Forms), Faded(Sand, A), DX, Y + 14.f * S, DW, 12.f);
	}
}

void FSunderCodexPanel::DrawKeepers(AHUD* Hud, const USunderCodexSubsystem* Codex, float PX, float PY, float PW, float PH, float A, float Now) const
{
	// The web Codex (keepers.html): a row of glass portrait cards, one per Keeper with its Hour beneath, a gold rule
	// between the acts, the chosen card lifted and ringed in cyan; above it the chosen Keeper, its portrait large in the
	// glow of its accent colour. A Keeper not yet met is a dark silhouette.
	const float S = Hud->Canvas->ClipY / 720.f;
	const FLinearColor Gold(0.96f, 0.84f, 0.48f), Gilt(0.83f, 0.69f, 0.22f), Sky(0.56f, 0.89f, 1.f), Sand(0.79f, 0.70f, 0.41f),
		Pale(0.85f, 0.85f, 0.9f), Dim(0.45f, 0.45f, 0.52f), Glass(0.043f, 0.059f, 0.165f, 0.75f), Shadow(0.015f, 0.012f, 0.04f, 0.92f);
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	const int32 N = UE_ARRAY_COUNT(GCodexKeepers), Sel = Index[0];
	auto Met = [&](int32 i) { return Codex && Codex->IsMet(GCodexKeepers[i].Hour); };

	// The cards: 60 wide (48 of portrait), 8 apart, 16 between acts; shrunk to fit a narrow panel.
	int32 ActGaps = 0;
	for (int32 i = 1; i < N; ++i) { ActGaps += GCodexKeepers[i].Act != GCodexKeepers[i - 1].Act; }
	const float Natural = N * 60.f + (N - 1 - ActGaps) * 8.f + ActGaps * 16.f;
	const float K = FMath::Min(1.f, (PW / S - 40.f) / Natural) * S;
	const float CW = 60.f * K, CH = 78.f * K, Pad = 6.f * K, PS = 48.f * K;
	const float Top = PY + PH - 12.f * S - CH;
	const float LabelScale = ScaleFor(Hud, Font, 10.f * K / S);
	float X = PX + (PW - Natural * K) * 0.5f;
	for (int32 i = 0; i < N; ++i)
	{
		if (i > 0 && GCodexKeepers[i].Act != GCodexKeepers[i - 1].Act)
		{
			Hud->DrawRect(Faded(Gilt, 0.45f * A), X + 7.5f * K, Top + CH * 0.12f, 1.f, CH * 0.76f);   // the act's rule
			X += 16.f * K;
		}
		else if (i > 0) { X += 8.f * K; }
		const bool bOn = i == Sel, bMet = Met(i);
		const float Lift = bOn ? FMath::Clamp((Now - MovedAt) / 0.15f, 0.f, 1.f) : 0.f;   // rises 8 and grows 6 %
		const float Grow = 1.f + 0.06f * Lift, W = CW * Grow, H = CH * Grow;
		const float CX = X + (CW - W) * 0.5f, CY = Top + (CH - H) * 0.5f - 8.f * K * Lift;
		Hud->DrawRect(Faded(Glass, Glass.A * A), CX, CY, W, H);
		if (bOn)
		{
			for (int32 g = 1; g <= 4; ++g)                                     // the cyan glow, fading outward
			{
				const float O = g * 3.f * K;
				Frame(Hud, CX - O, CY - O, W + 2.f * O, H + 2.f * O, Faded(Sky, 0.1f * (5 - g) / 4.f * A), 3.f * K);
			}
			Frame(Hud, CX, CY, W, H, Faded(Sky, A), FMath::Max(1.f, 1.5f * K));
		}
		else { Frame(Hud, CX, CY, W, H, Faded(Pale, 0.16f * A), 1.f); }
		const float P = PS * Grow, IX = CX + Pad * Grow, IY = CY + Pad * Grow;
		if (UTexture2D* Tex = Portrait(i))
		{
			Hud->DrawTexture(Tex, IX + 2.f * K, IY + 4.f * K, P, P, 0.f, 0.f, 1.f, 1.f, Faded(Shadow, 0.6f * A));   // the drop shadow
			Hud->DrawTexture(Tex, IX, IY, P, P, 0.f, 0.f, 1.f, 1.f, bMet ? FLinearColor(1.f, 1.f, 1.f, A) : Faded(Shadow, A));
		}
		if (!bMet)
		{
			float TW = 0.f, TH = 0.f;
			const float QScale = ScaleFor(Hud, Font, 18.f * K / S);
			Hud->GetTextSize(TEXT("?"), TW, TH, Font, QScale);
			Hud->DrawText(TEXT("?"), Faded(Dim, A), IX + (P - TW) * 0.5f, IY + (P - TH) * 0.5f, Font, QScale);
		}
		const FString Label = FString::Printf(TEXT("HOUR %d"), GCodexKeepers[i].Hour);
		float TW = 0.f, TH = 0.f;
		Hud->GetTextSize(Label, TW, TH, Font, LabelScale * Grow);
		Hud->DrawText(Label, Faded(bOn ? Sky : bMet ? Sand : Dim, A), CX + (W - TW) * 0.5f, IY + P + 4.f * K * Grow, Font, LabelScale * Grow);
		X += CW;
	}

	{                                                                        // the web Codex's ♪ SOUND button
		const FString Label = bSound ? TEXT("SOUND ON") : TEXT("SOUND OFF");
		const float SScale = ScaleFor(Hud, Font, 11.f);
		float TW = 0.f, TH = 0.f;
		Hud->GetTextSize(Label, TW, TH, Font, SScale);
		const float BW = TW + 20.f * S, BH = TH + 8.f * S, BX0 = PX + PW - 16.f * S - BW, BY0 = PY + 14.f * S;
		Hud->DrawRect(Faded(Glass, Glass.A * A), BX0, BY0, BW, BH);
		Frame(Hud, BX0, BY0, BW, BH, Faded(bSound ? Sky : Pale, (bSound ? 0.9f : 0.25f) * A), 1.f);
		Hud->DrawText(Label, Faded(bSound ? Sky : Dim, A), BX0 + 10.f * S, BY0 + 4.f * S, Font, SScale);
	}

	// The chosen Keeper: its portrait large on the left in its accent's glow, its words on the right.
	const FSunderCodexKeeper& Kp = GCodexKeepers[Sel];
	const float BY = PY + 40.f * S, Big = FMath::Min(260.f * S, Top - 30.f * S - BY), BX = PX + 40.f * S;   // its glow stays inside the panel
	const float TX = BX + Big + 32.f * S, TextW = PX + PW - 36.f * S - TX;
	float Y = PY + 26.f * S;
	UTexture2D* Tex = Portrait(Sel);
	if (!Met(Sel))
	{
		if (Tex) { Hud->DrawTexture(Tex, BX, BY, Big, Big, 0.f, 0.f, 1.f, 1.f, Faded(Shadow, A)); }
		Y = DrawWrapped(Hud, FString::Printf(TEXT("KEEPER CODEX \u2014 %s"), ActNames[FMath::Clamp(Kp.Act, 0, 4)]), Faded(Sky, A), TX, Y, TextW, 11.f);
		Y = DrawWrapped(Hud, TEXT("???"), Faded(Dim, A), TX, Y + 6.f * S, TextW, 26.f);
		DrawWrapped(Hud, FString::Printf(TEXT("A Keeper waits beyond gate %d. Reach Hour %d to meet it."), Kp.Hour, Kp.Hour), Faded(Sand, A), TX, Y + 8.f * S, TextW, 13.f);
		return;
	}
	// The web Codex's 3D viewer: the Keeper's model turning on its plinth under the viewer's lights, in a window ringed
	// in its accent colour (ASunderCodexStage). The practical light is Wepwawet's pink for Wepwawet, as on the web.
	ASunderCodexStage* Viewer = Stage.Get();
	if (!Viewer) { Viewer = ASunderCodexStage::Get(Hud->GetWorld()); Stage = Viewer; }
	const FLinearColor Accent = FCString::Strcmp(Kp.Id, TEXT("Wepwawet")) == 0 ? AccentOf(0xff3fa4) : AccentOf(Kp.Accent);
	UTextureRenderTarget2D* View = Viewer && Viewer->Show(Kp.Id, Accent, Now) ? Viewer->Render(Now) : nullptr;
	if (View)
	{
		const FLinearColor Glow = AccentOf(Kp.Accent);
		for (int32 g = 1; g <= 4; ++g)
		{
			const float O = g * 3.f * S;
			Frame(Hud, BX - O, BY - O, Big + 2.f * O, Big + 2.f * O, FLinearColor(Glow.R, Glow.G, Glow.B, 0.1f * (5 - g) / 4.f * A), 3.f * S);
		}
		Hud->DrawTexture(View, BX, BY, Big, Big, 0.f, 0.f, 1.f, 1.f, FLinearColor(A, A, A, 1.f), BLEND_Opaque);
		Frame(Hud, BX, BY, Big, Big, Faded(Glow, 0.8f * A), 1.f);
	}
	else if (Tex)                                            // no model yet (create_keepers.py not run): the portrait
	{
		const FLinearColor Glow = AccentOf(Kp.Accent);
		const float Breath = 0.85f + 0.15f * FMath::Sin(Now * 1.6f);       // the glow breathes, as on the intro card
		const float GS = Big * 1.35f;
		Hud->DrawTexture(Tex, BX - (GS - Big) * 0.5f, BY - (GS - Big) * 0.5f, GS, GS, 0.f, 0.f, 1.f, 1.f,
			FLinearColor(Glow.R, Glow.G, Glow.B, 0.35f * Breath * A), BLEND_Additive);
		Hud->DrawTexture(Tex, BX, BY, Big, Big, 0.f, 0.f, 1.f, 1.f, FLinearColor(1.f, 1.f, 1.f, A), BLEND_Translucent);
	}
	Y = DrawWrapped(Hud, FString::Printf(TEXT("KEEPER CODEX \u2014 %s"), ActNames[FMath::Clamp(Kp.Act, 0, 4)]), Faded(Sky, A), TX, Y, TextW, 11.f);
	Y = DrawWrapped(Hud, Kp.Name, Faded(Gold, A), TX, Y + 6.f * S, TextW, 26.f);
	Y = DrawWrapped(Hud, Kp.Epithet, Faded(Sky, A), TX, Y, TextW, 15.f);
	Y = DrawWrapped(Hud, Kp.HourLine, Faded(Sand, A), TX, Y + 6.f * S, TextW, 12.f);
	Y = DrawWrapped(Hud, Kp.Quote, Faded(Gilt, A), TX, Y + 10.f * S, TextW, 13.f);
	if (!Codex->IsBeaten(Kp.Hour))
	{
		DrawWrapped(Hud, TEXT("Beat it to learn what it is."), Faded(Dim, A), TX, Y + 10.f * S, TextW, 13.f);
		return;
	}
	Y = DrawWrapped(Hud, Kp.Lore, Faded(Pale, A), TX, Y + 10.f * S, TextW, 13.f);
	Y = DrawWrapped(Hud, FString::Printf(TEXT("ATTACKS  %s"), Kp.Patterns), Faded(Sand, A), TX, Y + 12.f * S, TextW, 12.f);
	DrawWrapped(Hud, FString::Printf(TEXT("ARENA  %s"), Kp.Arena), Faded(Sand, A), TX, Y + 4.f * S, TextW, 12.f);
}
