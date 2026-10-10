// SUNDER: Ascension II — minimal canvas HUD.
#include "SunderHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "SunderGameMode.h"
#include "SunderKeeper.h"
#include "SunderShipPawn.h"
#include "SunderSettingsSubsystem.h"
#include "Components/SphereComponent.h"
#include "Engine/GameInstance.h"

void ASunderHUD::DrawHUD()
{
	Super::DrawHUD();
	const ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>();
	if (!Mode || !Canvas) { return; }

	const FLinearColor Gold(0.90f, 0.76f, 0.32f);
	const FLinearColor Cyan(0.55f, 0.85f, 1.0f);
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	const float W = Canvas->ClipX, H = Canvas->ClipY;

	DrawText(FString::Printf(TEXT("SCORE  %07d"), Mode->GetScore()), Gold, 24.f, 20.f, Font, 1.2f);
	DrawText(FString::Printf(TEXT("LIVES  %d"), Mode->GetLives()), Cyan, 24.f, 52.f, Font, 1.0f);
	if (const FSunderShipLoadout* Ship = Mode->GetShipLoadout())
	{
		DrawText(Ship->Name, Ship->Tint, 24.f, 100.f, Font, 0.8f);         // under the hull bar
	}
	if (Mode->IsSwarm())
	{
		const int32 Secs = FMath::FloorToInt(Mode->GetSwarmTime());
		const FString Clock = FString::Printf(TEXT("SWARM  %d:%02d"), Secs / 60, Secs % 60);
		float CW = 0.f, CH = 0.f;
		GetTextSize(Clock, CW, CH, Font, 1.1f);
		DrawText(Clock, FLinearColor(1.f, 0.25f, 0.6f), W - CW - 24.f, 20.f, Font, 1.1f);
		if (GetWorld()->GetTimeSeconds() < 3.f)                            // the web game's Swarm Protocol card
		{
			const FString Card = TEXT("SWARM PROTOCOL  ·  No Keepers. No mercy. Faster and faster.");
			GetTextSize(Card, CW, CH, Font, 1.2f);
			DrawText(Card, Gold, (W - CW) * 0.5f, H * 0.22f, Font, 1.2f);
		}
	}

	// Accessibility (Settings → SHOW HITBOX): the ship's real hit sphere as a ring, always visible.
	const USunderSettingsSubsystem* Settings = GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderSettingsSubsystem>() : nullptr;
	if (const ASunderShipPawn* Ship = Cast<ASunderShipPawn>(GetOwningPawn()); Ship && Settings && Settings->ShowHitbox() && Ship->IsAlive() && Ship->Collision)
	{
		const FVector Centre = Ship->Collision->GetComponentLocation();
		const FVector C = Project(Centre), Edge = Project(Centre + FVector(0.f, Ship->Collision->GetScaledSphereRadius(), 0.f));
		const float R = FMath::Max(FVector2D(Edge.X - C.X, Edge.Y - C.Y).Size(), 3.f);
		const FLinearColor Ring(0.56f, 0.89f, 1.f, 0.9f);
		for (int32 k = 0; k < 32; ++k)
		{
			const float A0 = UE_TWO_PI * k / 32, A1 = UE_TWO_PI * (k + 1) / 32;
			DrawLine(C.X + FMath::Cos(A0) * R, C.Y + FMath::Sin(A0) * R, C.X + FMath::Cos(A1) * R, C.Y + FMath::Sin(A1) * R, Ring, 2.f);
		}
		DrawRect(FLinearColor::White, C.X - 2.f, C.Y - 2.f, 4.f, 4.f);
	}

	if (const ASunderShipPawn* Ship = Cast<ASunderShipPawn>(GetOwningPawn()))
	{
		// The hull bar has room for the 2 over full that Life pickups can give (drawn in pale blue).
		const float Max = FMath::Max(Ship->MaxHealth, 1.f), Cap = Max + 2.f, BarW = 180.f;
		const float Hull = FMath::Clamp(Ship->GetHealth(), 0.f, Cap);
		DrawRect(FLinearColor(0.f, 0.f, 0.f, 0.5f), 24.f, 84.f, BarW, 10.f);
		DrawRect(Hull / Max > 0.34f ? Cyan : FLinearColor(1.f, 0.25f, 0.6f), 24.f, 84.f, BarW * FMath::Min(Hull, Max) / Cap, 10.f);
		if (Hull > Max) { DrawRect(FLinearColor(0.56f, 0.89f, 1.f), 24.f + BarW * Max / Cap, 84.f, BarW * (Hull - Max) / Cap, 10.f); }
		DrawLine(24.f + BarW * Max / Cap, 82.f, 24.f + BarW * Max / Cap, 96.f, FLinearColor(1.f, 1.f, 1.f, 0.6f));

		// Bombs and shields bottom left; weapon, level and form bottom right (the web game's corners).
		DrawText(FString::Printf(TEXT("BOMB %d   SHLD %d"), Ship->GetBombs(), Ship->GetShield()), Cyan, 24.f, H - 44.f, Font, 1.0f);
		const bool bLaser = Ship->GetWeapon() == ESunderWeapon::Laser;
		const FString Gun = FString::Printf(TEXT("%s Lv%d"), bLaser ? TEXT("LASER") : TEXT("SPREAD"), Ship->GetPower());
		const FString Form = Ship->GetFormName().ToUpper();
		float GW = 0.f, GH = 0.f;
		GetTextSize(Gun, GW, GH, Font, 1.0f);
		DrawText(Gun, bLaser ? FLinearColor(0.49f, 0.78f, 1.f) : FLinearColor(1.f, 0.62f, 0.37f), W - GW - 24.f, H - 70.f, Font, 1.0f);
		GetTextSize(Form, GW, GH, Font, 1.0f);
		DrawText(Form, Gold, W - GW - 24.f, H - 44.f, Font, 1.0f);
		if (!Ship->GetToast().IsEmpty())                                   // "FORM: SOLAR HORUS"
		{
			GetTextSize(Ship->GetToast(), GW, GH, Font, 1.4f);
			DrawText(Ship->GetToast(), Gold, (W - GW) * 0.5f, H * 0.62f, Font, 1.4f);
		}
	}

	// A Keeper's intro card (the web game's BOSS_INTRO) holds while it waits to descend; the wave banner gives way to it.
	const ASunderKeeper* Keeper = Mode->GetActiveKeeper();
	const float SinceKeeper = GetWorld()->GetTimeSeconds() - Mode->GetKeeperAnnouncedAt();
	const float Hold = Keeper ? Keeper->IntroHold : 2.4f;
	const bool bKeeperCard = !Mode->GetKeeperTitle().IsEmpty() && SinceKeeper < Hold + 0.5f;

	const float Since = GetWorld()->GetTimeSeconds() - Mode->GetWaveAnnouncedAt();
	if (!bKeeperCard && !Mode->GetWaveName().IsEmpty() && Since < 2.2f)
	{
		const FLinearColor Fade(Gold.R, Gold.G, Gold.B, FMath::Clamp(2.2f - Since, 0.f, 1.f));
		const FString Banner = FString::Printf(TEXT("WAVE %d  ·  %s"), Mode->GetWaveNumber(), *Mode->GetWaveName());
		float TW = 0.f, TH = 0.f;
		GetTextSize(Banner, TW, TH, Font, 1.6f);
		DrawText(Banner, Fade, (W - TW) * 0.5f, H * 0.3f, Font, 1.6f);
	}

	// A Keeper: its intro card as it arrives, then a boss bar across the top while it lives.
	if (bKeeperCard) { DrawKeeperCard(Keeper, Mode->GetKeeperTitle(), Mode->GetKeeperTaunt(), SinceKeeper, Hold, Font); }
	if (Keeper && SinceKeeper >= Hold)                         // the boss bar once it starts to descend
	{
		const float BarW = W * 0.5f, X = (W - BarW) * 0.5f;
		DrawRect(FLinearColor(0.f, 0.f, 0.f, 0.55f), X, 22.f, BarW, 12.f);
		const FLinearColor Fill = Keeper->GetPhase() == 3 ? FLinearColor(1.f, 0.25f, 0.6f) : Keeper->GetPhase() == 2 ? Gold : Cyan;
		DrawRect(Fill, X, 22.f, BarW * Keeper->GetHealthFraction(), 12.f);
		DrawText(Keeper->KeeperName, Gold, X, 38.f, Font, 0.9f);
	}

	const float SinceFallen = GetWorld()->GetTimeSeconds() - Mode->GetKeeperFallenAt();
	if (SinceFallen < ClearCardTime && !Mode->IsGameOver()) { DrawClearCard(Mode, SinceFallen, Font); }

	if (Mode->IsGameOver()) { DrawDefeatCard(Mode, GetWorld()->GetTimeSeconds() - Mode->GetGameOverAt(), Font); }

	if (Mode->IsCombatPaused())                                // the web game's pause overlay, now a small menu
	{
		DrawRect(FLinearColor(0.02f, 0.016f, 0.047f, 0.74f), 0.f, 0.f, W, H);
		const float Now = GetWorld()->GetRealTimeSeconds();   // the world is paused; the menu still breathes
		if (Mode->IsPauseSettingsOpen())                       // the same settings / controls pages as the title's
		{
			Mode->GetSettingsPanel().Draw(this, USunderSettingsSubsystem::Get(this), Now);
		}
		else
		{
			const float Wrap = FMath::Min(W * 0.8f, 1100.f);
			float Y = DrawCentredWrapped(TEXT("PAUSED"), FLinearColor(0.96f, 0.84f, 0.48f), H * 0.5f - 110.f, 2.4f, Wrap, Font);
			static const TCHAR* Rows[3] = { TEXT("RESUME"), TEXT("SETTINGS"), TEXT("QUIT TO SHIP SELECT") };
			for (int32 i = 0; i < 3; ++i)
			{
				const bool bOn = i == Mode->GetPauseRow();
				const float Pulse = 0.7f + 0.3f * FMath::Sin(Now * 4.f);
				const FString Row = bOn ? FString::Printf(TEXT(">  %s  <"), Rows[i]) : FString(Rows[i]);
				Y = DrawCentredWrapped(Row, bOn ? FLinearColor(0.56f, 0.89f, 1.f, Pulse) : FLinearColor(0.79f, 0.70f, 0.41f), Y + 14.f, 1.3f, Wrap, Font);
			}
			const USunderSettingsSubsystem* Keys = USunderSettingsSubsystem::Get(this);   // the keys as remapped
			const FString PauseKey = USunderSettingsSubsystem::KeyName(Keys ? Keys->GetKey(ESunderControl::Pause) : EKeys::P);
			DrawCentredWrapped(FString::Printf(TEXT("%s  resume    \u00B7    UP / DOWN  choose    \u00B7    SPACE  select    \u00B7    ESC  quit"), *PauseKey),
				FLinearColor(0.79f, 0.70f, 0.41f, 0.8f), Y + 30.f, 0.9f, Wrap, Font);
		}
	}

}

void ASunderHUD::DrawKeeperCard(const ASunderKeeper* Keeper, const FString& Name, const FString& Quote, float Since, float Hold,
	UFont* Font)
{
	// The web game's card: the screen dims, the Keeper's portrait fades in in its Hour's glow, its name, then its words.
	const float W = Canvas->ClipX, H = Canvas->ClipY;
	const float In = FMath::Clamp(Since / 0.25f, 0.f, 1.f), Out = FMath::Clamp((Hold + 0.5f - Since) / 0.5f, 0.f, 1.f);
	const float A = FMath::Min(In, Out);
	DrawRect(FLinearColor(0.02f, 0.016f, 0.047f, 0.6f * A), 0.f, 0.f, W, H);   // the web's rgba(5,4,12) veil, lighter: the fight goes on

	FLinearColor Glow(1.f, 0.25f, 0.6f);
	if (Keeper)
	{
		const FLinearColor& C = Keeper->KeeperColor;
		const float Peak = FMath::Max3(C.R, C.G, C.B);
		if (Peak > 0.f) { Glow = FLinearColor(C.R / Peak, C.G / Peak, C.B / Peak); }
	}
	float Y = H * 0.40f;
	if (Keeper && Keeper->Portrait)
	{
		const float PS = H * 0.30f, PX = (W - PS) * 0.5f, PY = H * 0.47f - PS - 24.f;
		const float PA = FMath::Min(FMath::Min(1.f, Since * 2.f + 0.2f), Out);
		const float GS = PS * 1.35f;                                         // the glow: the portrait again, larger, additive
		DrawTexture(Keeper->Portrait, (W - GS) * 0.5f, PY - (GS - PS) * 0.5f, GS, GS, 0.f, 0.f, 1.f, 1.f,
			FLinearColor(Glow.R, Glow.G, Glow.B, 0.35f * PA), BLEND_Additive);
		DrawTexture(Keeper->Portrait, PX, PY, PS, PS, 0.f, 0.f, 1.f, 1.f, FLinearColor(1.f, 1.f, 1.f, PA), BLEND_Translucent);
		Y = H * 0.47f;
	}
	float TW = 0.f, TH = 0.f;
	if (Keeper)
	{
		const FString Header = FString::Printf(TEXT("HOUR %d  ·  THE KEEPER"), Keeper->Hour);
		GetTextSize(Header, TW, TH, Font, 0.9f);
		DrawText(Header, FLinearColor(Glow.R, Glow.G, Glow.B, A), (W - TW) * 0.5f, Y - 30.f, Font, 0.9f);
	}
	GetTextSize(Name, TW, TH, Font, 1.8f);
	DrawText(Name, FLinearColor(0.96f, 0.84f, 0.48f, A), (W - TW) * 0.5f, Y, Font, 1.8f);   // #F4D77B
	GetTextSize(Quote, TW, TH, Font, 1.1f);
	DrawText(Quote, FLinearColor(0.79f, 0.70f, 0.41f, A), (W - TW) * 0.5f, Y + 54.f, Font, 1.1f);   // #C9B368
}

void ASunderHUD::DrawClearCard(const ASunderGameMode* Mode, float Since, UFont* Font)
{
	// The web game's STAGE_CLEAR banner, over the arena as the Keeper's last burst fades.
	const float W = Canvas->ClipX, H = Canvas->ClipY;
	const float In = FMath::Clamp((Since - 0.3f) / 0.5f, 0.f, 1.f), Out = FMath::Clamp((ClearCardTime - Since) / 0.5f, 0.f, 1.f);
	const float A = FMath::Min(In, Out);
	DrawRect(FLinearColor(0.02f, 0.016f, 0.047f, 0.5f * A), 0.f, 0.f, W, H);
	const FLinearColor Tint = Mode->GetFallenTint();
	const float Wrap = FMath::Min(W * 0.8f, 1100.f);
	float Y = H * 0.30f;
	if (Mode->WasFinalKeeper())
	{
		// The web game goes straight to its ending here: its first and last words, then the story's Victory screen.
		Y = DrawCentredWrapped(TEXT("THE TWELFTH GATE IS OPEN."), FLinearColor(0.96f, 0.84f, 0.48f, A), Y, 1.9f, Wrap, Font);
		Y = DrawCentredWrapped(TEXT("ASCENSION COMPLETE."), FLinearColor(1.f, 0.86f, 0.5f, A), Y + 6.f, 1.2f, Wrap, Font);
	}
	else if (Mode->HasFallenHourName())
	{
		Y = DrawCentredWrapped(FString::Printf(TEXT("HOUR %d SURVIVED"), Mode->GetFallenHour()), FLinearColor(0.96f, 0.84f, 0.48f, A), Y, 1.9f, Wrap, Font);
		Y = DrawCentredWrapped(Mode->GetFallenName().ToUpper() + TEXT("  ·  GATE OPEN"), FLinearColor(Tint.R, Tint.G, Tint.B, A), Y + 6.f, 1.1f, Wrap, Font);
	}
	else
	{
		Y = DrawCentredWrapped(TEXT("THE KEEPER FALLS"), FLinearColor(0.96f, 0.84f, 0.48f, A), Y, 1.9f, Wrap, Font);
		Y = DrawCentredWrapped(Mode->GetFallenName().ToUpper(), FLinearColor(Tint.R, Tint.G, Tint.B, A), Y + 6.f, 1.1f, Wrap, Font);
	}
	if (!Mode->GetFallenLine().IsEmpty())                     // its closing line, a beat later
	{
		const float LA = FMath::Min(FMath::Clamp((Since - 0.9f) / 0.6f, 0.f, 1.f), Out);
		DrawCentredWrapped(Mode->GetFallenLine(), FLinearColor(0.79f, 0.70f, 0.41f, LA), Y + 22.f, 1.0f, Wrap, Font);
	}
}

float ASunderHUD::DrawCentredWrapped(const FString& Text, const FLinearColor& Color, float Y, float Scale, float MaxWidth, UFont* Font)
{
	TArray<FString> Words;
	Text.ParseIntoArray(Words, TEXT(" "), true);
	FString Line;
	float TW = 0.f, TH = 0.f;
	auto Flush = [&]()
	{
		if (Line.IsEmpty()) { return; }
		GetTextSize(Line, TW, TH, Font, Scale);
		DrawText(Line, Color, (Canvas->ClipX - TW) * 0.5f, Y, Font, Scale);
		Y += TH + 4.f;
		Line.Reset();
	};
	for (const FString& Word : Words)
	{
		const FString Try = Line.IsEmpty() ? Word : Line + TEXT(" ") + Word;
		GetTextSize(Try, TW, TH, Font, Scale);
		if (TW > MaxWidth && !Line.IsEmpty()) { Flush(); Line = Word; }
		else { Line = Try; }
	}
	Flush();
	return Y;
}

void ASunderHUD::DrawDefeatCard(const ASunderGameMode* Mode, float Since, UFont* Font)
{
	// The web game's DEFEAT banner, over the arena while the ship's last explosion plays out and the Keeper gloats; in
	// story mode its full screen (the Hour, the tag, rise again) follows (ASunderGameMode::RestartDelay).
	const float W = Canvas->ClipX, H = Canvas->ClipY;
	DrawRect(FLinearColor(0.02f, 0.f, 0.03f, 0.7f * FMath::Clamp(Since / 1.5f, 0.f, 1.f)), 0.f, 0.f, W, H);   // the night closes in
	const float A = FMath::Clamp((Since - 0.4f) / 0.8f, 0.f, 1.f);
	const float Wrap = FMath::Min(W * 0.8f, 1100.f);
	float Y = DrawCentredWrapped(TEXT("DAWN DENIED"), FLinearColor(1.f, 0.25f, 0.6f, A), H * 0.38f, 2.6f, Wrap, Font);
	const float B = FMath::Clamp((Since - 1.2f) / 0.8f, 0.f, 1.f);
	FString Tally = FString::Printf(TEXT("SCORE  %d"), Mode->GetScore());
	if (Mode->IsSwarm())
	{
		const int32 Secs = FMath::FloorToInt(Mode->GetSwarmTime());
		Tally = FString::Printf(TEXT("SURVIVED  %d:%02d    ·    SCORE  %d"), Secs / 60, Secs % 60, Mode->GetScore());
	}
	DrawCentredWrapped(Tally, FLinearColor(0.96f, 0.84f, 0.48f, B), Y + 18.f, 1.1f, Wrap, Font);
}
