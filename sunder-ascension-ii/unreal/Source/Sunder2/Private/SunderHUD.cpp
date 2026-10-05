// SUNDER: Ascension II — minimal canvas HUD.
#include "SunderHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "SunderGameMode.h"
#include "SunderKeeper.h"
#include "SunderShipPawn.h"

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

	const float Since = GetWorld()->GetTimeSeconds() - Mode->GetWaveAnnouncedAt();
	if (!Mode->GetWaveName().IsEmpty() && Since < 2.2f)
	{
		const FLinearColor Fade(Gold.R, Gold.G, Gold.B, FMath::Clamp(2.2f - Since, 0.f, 1.f));
		const FString Banner = FString::Printf(TEXT("WAVE %d  ·  %s"), Mode->GetWaveNumber(), *Mode->GetWaveName());
		float TW = 0.f, TH = 0.f;
		GetTextSize(Banner, TW, TH, Font, 1.6f);
		DrawText(Banner, Fade, (W - TW) * 0.5f, H * 0.3f, Font, 1.6f);
	}

	// A Keeper: banner and taunt as it arrives, then a boss bar across the top while it lives.
	const float SinceKeeper = GetWorld()->GetTimeSeconds() - Mode->GetKeeperAnnouncedAt();
	if (SinceKeeper < 3.5f && !Mode->GetKeeperTitle().IsEmpty())
	{
		const float A = FMath::Clamp(3.5f - SinceKeeper, 0.f, 1.f);
		float TW = 0.f, TH = 0.f;
		GetTextSize(Mode->GetKeeperTitle(), TW, TH, Font, 1.8f);
		DrawText(Mode->GetKeeperTitle(), FLinearColor(1.f, 0.25f, 0.6f, A), (W - TW) * 0.5f, H * 0.36f, Font, 1.8f);
		GetTextSize(Mode->GetKeeperTaunt(), TW, TH, Font, 1.1f);
		DrawText(Mode->GetKeeperTaunt(), FLinearColor(Gold.R, Gold.G, Gold.B, A), (W - TW) * 0.5f, H * 0.36f + 44.f, Font, 1.1f);
	}
	if (const ASunderKeeper* Keeper = Mode->GetActiveKeeper())
	{
		const float BarW = W * 0.5f, X = (W - BarW) * 0.5f;
		DrawRect(FLinearColor(0.f, 0.f, 0.f, 0.55f), X, 22.f, BarW, 12.f);
		const FLinearColor Fill = Keeper->GetPhase() == 3 ? FLinearColor(1.f, 0.25f, 0.6f) : Keeper->GetPhase() == 2 ? Gold : Cyan;
		DrawRect(Fill, X, 22.f, BarW * Keeper->GetHealthFraction(), 12.f);
		DrawText(Keeper->KeeperName, Gold, X, 38.f, Font, 0.9f);
	}

	if (Mode->IsGameOver())
	{
		const FString Text = TEXT("DAWN DENIED");
		float TW = 0.f, TH = 0.f;
		GetTextSize(Text, TW, TH, Font, 2.4f);
		DrawText(Text, FLinearColor(1.f, 0.25f, 0.6f), (W - TW) * 0.5f, H * 0.42f, Font, 2.4f);
	}
}
