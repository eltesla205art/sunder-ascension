// SUNDER: Ascension II — minimal canvas HUD.
#include "SunderHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "SunderGameMode.h"
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

	if (const ASunderShipPawn* Ship = Cast<ASunderShipPawn>(GetOwningPawn()))
	{
		const float Max = FMath::Max(Ship->MaxHealth, 1.f);
		const float Frac = FMath::Clamp(Ship->GetHealth() / Max, 0.f, 1.f);
		DrawRect(FLinearColor(0.f, 0.f, 0.f, 0.5f), 24.f, 84.f, 180.f, 10.f);
		DrawRect(Frac > 0.34f ? Cyan : FLinearColor(1.f, 0.25f, 0.6f), 24.f, 84.f, 180.f * Frac, 10.f);
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

	if (Mode->IsGameOver())
	{
		const FString Text = TEXT("DAWN DENIED");
		float TW = 0.f, TH = 0.f;
		GetTextSize(Text, TW, TH, Font, 2.4f);
		DrawText(Text, FLinearColor(1.f, 0.25f, 0.6f), (W - TW) * 0.5f, H * 0.42f, Font, 2.4f);
	}
}
