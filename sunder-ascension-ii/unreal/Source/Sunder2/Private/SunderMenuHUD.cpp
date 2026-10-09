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
	float AW = H * (480.f / 720.f);                            // the art's width on screen (the web game's 480 × 720)
	if (UTexture2D* Art = Menu->Backdrop)
	{
		const float Aspect = Art->GetSizeY() > 0 ? (float)Art->GetSizeX() / Art->GetSizeY() : 1.f;
		AW = H * Aspect;
		float Light = Screen == ESunderMenuScreen::Title ? FMath::Clamp(T / 1.2f, 0.f, 1.f) : 0.45f;
		if (Screen == ESunderMenuScreen::Launching) { Light *= 1.f - FMath::Clamp(T / FMath::Max(Menu->LaunchDelay, 0.01f), 0.f, 1.f); }
		DrawTexture(Art, (W - AW) * 0.5f, 0.f, AW, H, 0.f, 0.f, 1.f, 1.f, FLinearColor(Light, Light, Light, 1.f));
	}

	if (Screen == ESunderMenuScreen::Title)
	{
		DrawTitle(Menu, T, (W - AW) * 0.5f, AW);
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


void ASunderMenuHUD::DrawTitle(const ASunderMenuGameMode* Menu, float T, float ArtX, float ArtW)
{
	// The web game's title (drawTitle), on the same art: places are its 480 × 720 canvas's, mapped onto the backdrop.
	const float H = Canvas->ClipY, S = H / 720.f;
	const float Light = FMath::Clamp(T / 1.2f, 0.f, 1.f), A = FMath::Clamp((T - 0.6f) / 1.0f, 0.f, 1.f);
	auto At = [&](float X, float Y) { return FVector2D(ArtX + X / 480.f * ArtW, Y * S); };
	auto Disc = [&](const FVector2D& C, float R, const FLinearColor& Color)
	{
		Canvas->K2_DrawPolygon(nullptr, C, FVector2D(R, R), 32, Color);
	};
	auto Ring = [&](const FVector2D& C, float R, const FLinearColor& Color, float Thick)
	{
		for (int32 k = 0; k < 48; ++k)
		{
			const float A0 = UE_TWO_PI * k / 48, A1 = UE_TWO_PI * (k + 1) / 48;
			DrawLine(C.X + FMath::Cos(A0) * R, C.Y + FMath::Sin(A0) * R, C.X + FMath::Cos(A1) * R, C.Y + FMath::Sin(A1) * R, Color, Thick);
		}
	};
	auto Faded = [](const FLinearColor& C, float Alpha) { return FLinearColor(C.R, C.G, C.B, FMath::Clamp(Alpha, 0.f, 1.f)); };

	// The gate breathes: a pink glow in the crystal portal (stacked soft discs stand in for the web's radial gradient).
	const FVector2D Portal = At(240.f, 455.f);
	const float PA = (0.16f + 0.10f * FMath::Sin(T * 1.8f)) * Light;
	for (int32 k = 0; k < 8; ++k)
	{
		Disc(Portal, (150.f - 16.f * k) * S, Faded(FMath::Lerp(FLinearColor(0.47f, 0.08f, 0.63f), FLinearColor(1.f, 0.35f, 0.78f), k / 7.f), PA * 0.22f));
	}
	// The eclipse's rim flickers: a band of warm light peaking a little outside the dark disc.
	const FVector2D Eclipse = At(240.f, 289.f);
	const float EA = (0.10f + 0.07f * FMath::Sin(T * 0.9f + 1.f) + 0.03f * FMath::Sin(T * 7.3f)) * Light;
	for (float R = 34.f; R <= 98.f; R += 4.f)
	{
		const float F = (R - 30.f) / 70.f;                       // the web's stops: 0 → 0.4 (peak) → 1
		const float Band = F < 0.4f ? F / 0.4f : (1.f - F) / 0.6f;
		Ring(Eclipse, R * S, Faded(FLinearColor(1.f, 0.65f, 0.3f), EA * Band * 1.6f), 4.f * S);
	}
	// Embers and crystal dust rising out of the sand.
	for (int32 i = 0; i < 46; ++i)
	{
		const float Speed = 14.f + (i % 7) * 6.f;
		const float Y = 720.f + 20.f - FMath::Fmod(T * Speed + i * 97.f, 780.f);
		const float X = (i * 137) % 480 + FMath::Sin(T * 0.7f + i) * 12.f;
		const float EmA = FMath::Max(0.f, 0.35f + 0.35f * FMath::Sin(T * 2.f + i)) * Light;
		const FVector2D P = At(X, Y);
		DrawRect(Faded(i % 3 ? FLinearColor(1.f, 0.44f, 0.82f) : FLinearColor(0.96f, 0.77f, 0.42f), EmA), P.X, P.Y, 2.f * S, 2.f * S);
	}

	// The chosen ship rises out of the gate, then holds and hovers, its engine flickering in its colour.
	if (Menu->Ships.IsValidIndex(Menu->GetShipIndex()))
	{
		const FSunderMenuShip& Ship = Menu->Ships[Menu->GetShipIndex()];
		const float K = FMath::Clamp(T / 2.4f, 0.f, 1.f), Ease = 1.f - FMath::Pow(1.f - K, 3.f);
		const float SY = 455.f + 70.f - Ease * 110.f + (K >= 1.f ? FMath::Sin(T * 1.6f) * 6.f : 0.f);
		const float Size = 84.f * (0.7f + 0.8f * Ease) * S, ShipA = 0.35f + 0.65f * Ease;
		const FVector2D C = At(240.f, SY);
		const float Flick = 0.75f + 0.25f * FMath::Sin(T * 38.f);
		for (int32 k = 0; k < 4; ++k) { Disc(FVector2D(C.X, C.Y + Size * 0.4f), Size * 0.3f * Flick * (1.f - 0.2f * k), Faded(Ship.Tint, 0.18f * ShipA)); }
		if (Ship.Sprite)
		{
			DrawTexture(Ship.Sprite, C.X - Size * 0.5f, C.Y - Size * 0.5f, Size, Size, 0.f, 0.f, 1.f, 1.f, FLinearColor(1.f, 1.f, 1.f, ShipA));
		}
	}

	// Legibility bands for the logo and the prompts (the web's gradients, as flat strips).
	const float W = Canvas->ClipX;
	for (int32 i = 0; i < 24; ++i)
	{
		const float F = i / 24.f;
		DrawRect(FLinearColor(0.016f, 0.012f, 0.047f, 0.85f * (1.f - F)), 0.f, 230.f * S * F, W, 230.f * S / 24.f + 1.f);
		const float G = F < 0.45f ? 0.7f * F / 0.45f : FMath::Lerp(0.7f, 0.92f, (F - 0.45f) / 0.55f);
		DrawRect(FLinearColor(0.016f, 0.012f, 0.047f, G), 0.f, (560.f + 160.f * F) * S, W, 160.f * S / 24.f + 1.f);
	}

	// The logo: SUNDER in glowing gold, A S C E N S I O N   I I in cyan, the subtitle beneath.
	DrawWebText(TEXT("SUNDER"), Faded(FLinearColor(0.96f, 0.84f, 0.48f), A), 100.f, 62.f, FLinearColor(0.83f, 0.69f, 0.22f));
	DrawWebText(TEXT("A S C E N S I O N   I I"), Faded(FLinearColor(0.56f, 0.89f, 1.f), A), 136.f, 22.f, FLinearColor(0.56f, 0.89f, 1.f));
	DrawWebText(TEXT("\u2014\u2014  THE TWELVE GATES  \u2014\u2014"), Faded(FLinearColor(0.83f, 0.69f, 0.22f), A), 168.f, 15.f);

	// The prompts and the credits.
	const float Pulse = 0.4f + 0.6f * FMath::Abs(FMath::Sin(T * 2.2f));
	DrawWebText(TEXT("PRESS SPACE / ENTER TO BEGIN"), Faded(FLinearColor(1.f, 0.96f, 0.79f), A * Pulse), 612.f, 17.f);
	DrawWebText(TEXT("PART II  \u00B7  EARLY BUILD"), Faded(FLinearColor(0.56f, 0.89f, 1.f), 0.55f * A), 720.f - 34.f, 11.f);
	DrawWebText(TEXT("AN ASCENSION MEDIA GROUP PRODUCTION"), Faded(FLinearColor(0.79f, 0.70f, 0.41f), 0.6f * A), 720.f - 16.f, 11.f);
}

void ASunderMenuHUD::DrawWebText(const FString& Text, const FLinearColor& Color, float BaselineY, float Px, const FLinearColor& Glow)
{
	// Centred text at the web game's baseline and pixel size (on its 720-high canvas); an optional soft glow behind it
	// for the web's shadowBlur.
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	const float S = Canvas->ClipY / 720.f;
	float RW = 0.f, RH = 0.f;
	GetTextSize(TEXT("Ay"), RW, RH, Font, 1.f);
	const float Scale = RH > 0.f ? Px * S * 1.25f / RH : 1.f;
	float TW = 0.f, TH = 0.f;
	GetTextSize(Text, TW, TH, Font, Scale);
	const float X = (Canvas->ClipX - TW) * 0.5f, Y = BaselineY * S - TH * 0.8f;
	if (Glow.A > 0.f)
	{
		const float O = FMath::Max(2.f, Px * S * 0.06f);
		for (const FVector2D D : { FVector2D(-O, 0.f), FVector2D(O, 0.f), FVector2D(0.f, -O), FVector2D(0.f, O) })
		{
			DrawText(Text, FLinearColor(Glow.R, Glow.G, Glow.B, 0.22f * Color.A), X + D.X, Y + D.Y, Font, Scale);
		}
	}
	DrawText(Text, Color, X, Y, Font, Scale);
}
