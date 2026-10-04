// SUNDER: Ascension II — title screen and hangar drawing.
#include "SunderMenuHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "SunderMenuGameMode.h"

namespace
{
	const FLinearColor Gold(0.90f, 0.76f, 0.32f);
	const FLinearColor Cyan(0.55f, 0.85f, 1.0f);
	const FLinearColor Dim(0.55f, 0.55f, 0.62f);
	const FLinearColor Magenta(1.f, 0.25f, 0.6f);
}

void ASunderMenuHUD::DrawCentered(const FString& Text, const FLinearColor& Color, float Y, float Scale)
{
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	float TW = 0.f, TH = 0.f;
	GetTextSize(Text, TW, TH, Font, Scale);
	DrawText(Text, Color, (Canvas->ClipX - TW) * 0.5f, Y, Font, Scale);
}

void ASunderMenuHUD::DrawHUD()
{
	Super::DrawHUD();
	const ASunderMenuGameMode* Menu = GetWorld()->GetAuthGameMode<ASunderMenuGameMode>();
	if (!Menu || !Canvas) { return; }
	const float W = Canvas->ClipX, H = Canvas->ClipY, T = Menu->GetScreenTime();
	const ESunderMenuScreen Screen = Menu->GetScreen();

	// The title art, fitted to the screen height and centred; dimmer in the hangar, fading out on launch.
	DrawRect(FLinearColor(0.01f, 0.01f, 0.03f), 0.f, 0.f, W, H);
	if (UTexture2D* Art = Menu->Backdrop)
	{
		const float Aspect = Art->GetSizeY() > 0 ? (float)Art->GetSizeX() / Art->GetSizeY() : 1.f;
		const float AW = H * Aspect;
		float Light = Screen == ESunderMenuScreen::Title ? FMath::Clamp(T / 1.2f, 0.f, 1.f) : 0.45f;
		if (Screen == ESunderMenuScreen::Launching) { Light *= 1.f - FMath::Clamp(T / FMath::Max(Menu->LaunchDelay, 0.01f), 0.f, 1.f); }
		DrawTexture(Art, (W - AW) * 0.5f, 0.f, AW, H, 0.f, 0.f, 1.f, 1.f, FLinearColor(Light, Light, Light, 1.f));
	}

	if (Screen == ESunderMenuScreen::Title)
	{
		const float A = FMath::Clamp((T - 0.6f) / 1.0f, 0.f, 1.f);
		DrawCentered(TEXT("SUNDER: ASCENSION II"), FLinearColor(Gold.R, Gold.G, Gold.B, A), H * 0.16f, 3.0f);
		DrawCentered(TEXT("THE TWELVE GATES"), FLinearColor(Cyan.R, Cyan.G, Cyan.B, A), H * 0.16f + 64.f, 1.6f);
		const float Blink = 0.55f + 0.45f * FMath::Sin(T * 3.f);
		DrawCentered(TEXT("PRESS SPACE / ENTER"), FLinearColor(1.f, 1.f, 1.f, A * Blink), H * 0.80f, 1.3f);
		return;
	}

	// The hangar: three bays across the screen; the chosen one lit in its colour.
	DrawCentered(TEXT("HANGAR  ·  CHOOSE YOUR SHIP"), Gold, H * 0.08f, 1.6f);
	const TArray<FSunderMenuShip>& Ships = Menu->Ships;
	const int32 N = Ships.Num();
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	for (int32 i = 0; i < N; ++i)
	{
		const FSunderMenuShip& Ship = Ships[i];
		const bool bOn = i == Menu->GetShipIndex();
		const float CX = W * (i + 1) / (N + 1);
		const float Size = FMath::Min(W / (N + 1), H * 0.32f) * (bOn ? 1.f : 0.75f);
		const float Bob = bOn ? 6.f * FMath::Sin(T * 2.4f) : 0.f;
		const float Top = H * 0.24f + (bOn ? 0.f : Size * 0.15f) + Bob;
		if (bOn) { DrawRect(FLinearColor(Ship.Tint.R, Ship.Tint.G, Ship.Tint.B, 0.12f), CX - Size * 0.6f, Top - 12.f, Size * 1.2f, Size + 24.f); }
		if (Ship.Sprite)
		{
			const float L = bOn ? 1.f : 0.45f;
			DrawTexture(Ship.Sprite, CX - Size * 0.5f, Top, Size, Size, 0.f, 0.f, 1.f, 1.f, FLinearColor(L, L, L, 1.f));
		}
		float TW = 0.f, TH = 0.f;
		GetTextSize(Ship.Name, TW, TH, Font, bOn ? 1.1f : 0.9f);
		DrawText(Ship.Name, bOn ? Ship.Tint : Dim, CX - TW * 0.5f, Top + Size + 18.f, Font, bOn ? 1.1f : 0.9f);
		if (bOn)
		{
			GetTextSize(Ship.ShipClass, TW, TH, Font, 0.9f);
			DrawText(Ship.ShipClass, Cyan, CX - TW * 0.5f, Top + Size + 48.f, Font, 0.9f);
		}
	}

	const bool bStory = Menu->GetModeIndex() == 0;
	DrawCentered(bStory ? TEXT("[ STORY ]      SWARM  ") : TEXT("  STORY      [ SWARM ]"), bStory ? Gold : Magenta, H * 0.78f, 1.3f);
	if (Screen == ESunderMenuScreen::Launching)
	{
		const FString Name = Ships.IsValidIndex(Menu->GetShipIndex()) ? Ships[Menu->GetShipIndex()].Name : FString();
		DrawCentered(FString::Printf(TEXT("LAUNCH  ·  %s"), *Name), Gold, H * 0.88f, 1.4f);
		DrawRect(FLinearColor(0.f, 0.f, 0.f, FMath::Clamp(T / FMath::Max(Menu->LaunchDelay, 0.01f), 0.f, 1.f)), 0.f, 0.f, W, H);
	}
	else
	{
		DrawCentered(TEXT("A / D  ship    ·    W / S  mode    ·    SPACE  launch    ·    ESC  back"), Dim, H * 0.88f, 0.9f);
	}
}
