// SUNDER: Ascension II — title screen and hangar drawing.
#include "SunderMenuHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "SunderMenuGameMode.h"
#include "SunderSettingsSubsystem.h"
#include "Engine/GameInstance.h"

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

	// The title art, fitted to the screen height and centred; faint behind the hangar, fading out on launch.
	DrawRect(FLinearColor(0.01f, 0.01f, 0.03f), 0.f, 0.f, W, H);
	float AW = H * (480.f / 720.f);                            // the art's width on screen (the web game's 480 × 720)
	if (UTexture2D* Art = Menu->Backdrop)
	{
		const float Aspect = Art->GetSizeY() > 0 ? (float)Art->GetSizeX() / Art->GetSizeY() : 1.f;
		AW = H * Aspect;
		float Light = Screen == ESunderMenuScreen::Title ? FMath::Clamp(T / 1.2f, 0.f, 1.f)
			: (Screen == ESunderMenuScreen::Settings || Screen == ESunderMenuScreen::Controls) ? 0.25f : 0.18f;   // the hangar: a dark night, its own band on top
		if (Screen == ESunderMenuScreen::Launching) { Light *= 1.f - FMath::Clamp(T / FMath::Max(Menu->LaunchDelay, 0.01f), 0.f, 1.f); }
		DrawTexture(Art, (W - AW) * 0.5f, 0.f, AW, H, 0.f, 0.f, 1.f, 1.f, FLinearColor(Light, Light, Light, 1.f));
	}

	if (Screen == ESunderMenuScreen::Title)
	{
		DrawTitle(Menu, T, (W - AW) * 0.5f, AW);
		return;
	}

	if (Screen == ESunderMenuScreen::Settings)
	{
		DrawSettings(Menu, T);
		return;
	}
	if (Screen == ESunderMenuScreen::Controls)
	{
		DrawControls(Menu, T);
		return;
	}
	DrawHangar(Menu, T, Screen == ESunderMenuScreen::Launching);
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
	// The choice under the logo: begin (the web game's pulsing prompt) or settings; W / S moves between them.
	const float Pulse = 0.4f + 0.6f * FMath::Abs(FMath::Sin(T * 2.2f));
	const bool bBegin = Menu->GetTitleIndex() == 0;
	DrawWebText(TEXT("PRESS SPACE / ENTER TO BEGIN"), Faded(FLinearColor(1.f, 0.96f, 0.79f), A * (bBegin ? Pulse : 0.35f)), 612.f, 17.f);
	DrawWebText(bBegin ? TEXT("SETTINGS") : TEXT(">  SETTINGS  <"), Faded(FLinearColor(0.56f, 0.89f, 1.f), A * (bBegin ? 0.55f : Pulse)), 646.f, 14.f);
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

void ASunderMenuHUD::DrawHangar(const ASunderMenuGameMode* Menu, float T, bool bLaunching)
{
	// The web game's ship select (drawShipSelect), on its 480 × 720 layout centred on the screen: the hangar band behind
	// a large preview ringed in the ship's accent, its name and class, its stats card and personality, the browse
	// arrows, STORY / SWARM and the LAUNCH button. The band runs the full width of the screen.
	const float W = Canvas->ClipX, H = Canvas->ClipY, S = H / 720.f, X0 = (W - 480.f * S) * 0.5f;
	auto At = [&](float X, float Y) { return FVector2D(X0 + X * S, Y * S); };
	auto Faded = [](const FLinearColor& C, float Alpha) { return FLinearColor(C.R, C.G, C.B, FMath::Clamp(Alpha, 0.f, 1.f)); };
	auto Disc = [&](const FVector2D& C, float R, const FLinearColor& Color) { Canvas->K2_DrawPolygon(nullptr, C, FVector2D(R, R), 32, Color); };
	auto Ring = [&](const FVector2D& C, float R, const FLinearColor& Color, float Thick)
	{
		for (int32 k = 0; k < 48; ++k)
		{
			const float A0 = UE_TWO_PI * k / 48, A1 = UE_TWO_PI * (k + 1) / 48;
			DrawLine(C.X + FMath::Cos(A0) * R, C.Y + FMath::Sin(A0) * R, C.X + FMath::Cos(A1) * R, C.Y + FMath::Sin(A1) * R, Color, Thick);
		}
	};
	auto Box = [&](float X, float Y, float BW, float BH, const FLinearColor& Fill, const FLinearColor& Edge, float Thick)
	{
		const FVector2D P = At(X, Y);
		DrawRect(Fill, P.X, P.Y, BW * S, BH * S);
		DrawLine(P.X, P.Y, P.X + BW * S, P.Y, Edge, Thick);
		DrawLine(P.X, P.Y + BH * S, P.X + BW * S, P.Y + BH * S, Edge, Thick);
		DrawLine(P.X, P.Y, P.X, P.Y + BH * S, Edge, Thick);
		DrawLine(P.X + BW * S, P.Y, P.X + BW * S, P.Y + BH * S, Edge, Thick);
	};
	const FLinearColor Night(0.04f, 0.035f, 0.094f), Sand(0.79f, 0.70f, 0.41f), Gilt(0.83f, 0.69f, 0.22f), Sky(0.56f, 0.89f, 1.f);

	// The hangar band: its art at a third strength, fading into the night above and below, a dark spotlight behind the
	// ship so it reads in front.
	const float BH = 271.f * S, BY = (210.f - 135.5f) * S;
	if (UTexture2D* Bay = Menu->HangarBackdrop)
	{
		const float Aspect = Bay->GetSizeY() > 0 ? (float)Bay->GetSizeX() / Bay->GetSizeY() : 1.77f;
		const float VL = FMath::Min(1.f, BH / (W / Aspect));       // a full-width slice of the art, centred
		DrawTexture(Bay, 0.f, BY, W, BH, 0.f, (1.f - VL) * 0.5f, 1.f, VL, FLinearColor(1.f, 1.f, 1.f, 0.32f));
		for (int32 i = 0; i < 20; ++i)
		{
			const float F = i / 20.f;
			const float Fade = F < 0.22f ? 1.f - F / 0.22f : F > 0.62f ? (F - 0.62f) / 0.38f : 0.f;
			DrawRect(Faded(Night, Fade), 0.f, BY + BH * F, W, BH / 20.f + 1.f);
		}
		for (int32 k = 0; k < 8; ++k) { Disc(At(240.f, 210.f), (150.f - 15.f * k) * S, Faded(Night, 0.2f)); }
	}

	DrawWebText(TEXT("CHOOSE YOUR STARCRAFT"), Sand, 70.f, 20.f);
	if (!Menu->Ships.IsValidIndex(Menu->GetShipIndex())) { return; }
	const FSunderMenuShip& Ship = Menu->Ships[Menu->GetShipIndex()];

	// The preview at twice the web's ship size, its engine glowing in its accent, a ring pulsing round it.
	const FVector2D C = At(240.f, 210.f);
	const float Size = 84.f * 2.f * S, Flick = 0.75f + 0.25f * FMath::Sin(T * 38.f);
	for (int32 k = 0; k < 4; ++k) { Disc(FVector2D(C.X, C.Y + Size * 0.4f), Size * 0.3f * Flick * (1.f - 0.2f * k), Faded(Ship.Accent, 0.2f)); }
	if (Ship.Sprite) { DrawTexture(Ship.Sprite, C.X - Size * 0.5f, C.Y - Size * 0.5f, Size, Size, 0.f, 0.f, 1.f, 1.f, FLinearColor::White); }
	Ring(C, (105.f + 6.f * FMath::Sin(T * 3.f)) * S, Faded(Ship.Accent, 0.25f + 0.2f * FMath::Sin(T * 3.f)), 2.f);

	DrawWebText(Ship.Name, Ship.Tint, 350.f, 24.f);
	DrawWebText(FString::Printf(TEXT("\u2014 %s \u2014"), *Ship.ShipClass), Sand, 376.f, 15.f);
	DrawWebText(FString::Printf(TEXT("%d / %d"), Menu->GetShipIndex() + 1, Menu->Ships.Num()), Sand, 398.f, 13.f);

	// Its stats card: hull as hearts (small gold diamonds here), the web's ten-cell bars, bombs.
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	float RW = 0.f, RH = 0.f;
	GetTextSize(TEXT("Ay"), RW, RH, Font, 1.f);
	const float LabelScale = RH > 0.f ? 15.f * S * 1.25f / RH : 1.f;
	auto Label = [&](const TCHAR* Text, float Y) { const FVector2D P = At(110.f, Y); DrawText(Text, Gilt, P.X, P.Y - 15.f * S, Font, LabelScale); };
	auto Bar = [&](float Y, float Pct)
	{
		const int32 Filled = FMath::RoundToInt(FMath::Clamp(Pct, 0.f, 1.f) * 10.f);
		for (int32 k = 0; k < 10; ++k)
		{
			const FVector2D P = At(176.f + k * 11.f, Y - 12.f);
			DrawRect(k < Filled ? Gilt : Faded(Gilt, 0.22f), P.X, P.Y, 9.f * S, 12.f * S);
		}
	};
	Label(TEXT("HULL"), 420.f);
	for (int32 k = 0; k < Ship.Hull; ++k)
	{
		const FVector2D P = At(182.f + k * 18.f, 414.f);
		Canvas->K2_DrawPolygon(nullptr, P, FVector2D(6.f * S, 6.f * S), 4, FLinearColor(0.85f, 0.25f, 0.2f));
	}
	Label(TEXT("SPEED"), 444.f);  Bar(444.f, Ship.SpeedBar);
	Label(TEXT("FIRE"), 468.f);   Bar(468.f, Ship.FireBar);
	Label(TEXT("POWER"), 492.f);  Bar(492.f, Ship.PowerBar);
	Label(TEXT("BOMBS"), 516.f);
	{
		const FVector2D P = At(176.f, 516.f);
		DrawText(FString::FromInt(Ship.Bombs), Gilt, P.X, P.Y - 15.f * S, Font, LabelScale);
	}
	DrawWebText(Ship.Personality, FLinearColor(0.61f, 0.54f, 0.31f), 540.f, 12.f);

	// The browse arrows, the mode toggle and the LAUNCH button (the web's touch controls, here as the keys' map).
	for (const float BX : { 52.f, 428.f })
	{
		const FVector2D P = At(BX, 210.f);
		Disc(P, 40.f * S, FLinearColor(0.07f, 0.063f, 0.12f, 0.92f));
		Ring(P, 40.f * S, Sky, 2.f);
		float TW = 0.f, TH = 0.f;
		const TCHAR* Arrow = BX < 240.f ? TEXT("<") : TEXT(">");
		GetTextSize(Arrow, TW, TH, Font, LabelScale * 1.8f);
		DrawText(Arrow, Sky, P.X - TW * 0.5f, P.Y - TH * 0.5f, Font, LabelScale * 1.8f);
	}
	const bool bStory = Menu->GetModeIndex() == 0;
	for (int32 m = 0; m < 2; ++m)
	{
		const bool bOn = (m == 0) == bStory;
		const float BX = m == 0 ? 240.f - 112.f : 240.f + 4.f;
		Box(BX, 566.f, 108.f, 38.f, bOn ? FLinearColor(0.56f, 0.89f, 1.f, 0.28f) : FLinearColor(0.07f, 0.063f, 0.12f, 0.9f),
			bOn ? Sky : Faded(Sky, 0.35f), bOn ? 2.5f : 1.5f);
		const FString Mode = m == 0 ? TEXT("STORY") : TEXT("SWARM");
		float TW = 0.f, TH = 0.f;
		GetTextSize(Mode, TW, TH, Font, LabelScale);
		const FVector2D P = At(BX + 54.f, 585.f);
		DrawText(Mode, bOn ? FLinearColor(0.94f, 0.98f, 1.f) : FLinearColor(0.49f, 0.58f, 0.66f), P.X - TW * 0.5f, P.Y - TH * 0.5f, Font, LabelScale);
	}
	const float LP = bLaunching ? 1.f : 0.8f + 0.2f * FMath::Sin(T * 3.f);
	Box(240.f - 110.f, 616.f, 220.f, 48.f, Faded(Gilt, 0.9f * LP), FLinearColor(0.96f, 0.84f, 0.48f), 2.f);
	DrawWebText(bLaunching ? TEXT("LAUNCHING") : TEXT("LAUNCH"), FLinearColor(0.1f, 0.075f, 0.02f), 648.f, 20.f);
	DrawWebText(TEXT("A / D  browse    \u00B7    W / S  mode    \u00B7    SPACE  launch    \u00B7    ESC  back"), Sand, 696.f, 12.f);

	if (bLaunching)                                            // the screen goes to black as the engines take the ship out
	{
		DrawRect(FLinearColor(0.f, 0.f, 0.f, FMath::Clamp(T / FMath::Max(Menu->LaunchDelay, 0.01f), 0.f, 1.f)), 0.f, 0.f, W, H);
	}
}

void ASunderMenuHUD::DrawSettings(const ASunderMenuGameMode* Menu, float T)
{
	// A glass panel in the menus' style (DESIGN.md: night indigo, gold hairline, cyan on the focused row): each setting's
	// name on the left, its value on the right, volumes as ten-cell bars, BACK at the foot.
	const USunderSettingsSubsystem* Settings = Menu->GetGameInstance() ? Menu->GetGameInstance()->GetSubsystem<USunderSettingsSubsystem>() : nullptr;
	if (!Settings) { return; }
	const float W = Canvas->ClipX, H = Canvas->ClipY, S = H / 720.f;
	const float A = FMath::Clamp(T / 0.25f, 0.f, 1.f);
	const FLinearColor Gilt(0.83f, 0.69f, 0.22f), Sky(0.56f, 0.89f, 1.f), Sand(0.79f, 0.70f, 0.41f);
	auto Faded = [](const FLinearColor& C, float Alpha) { return FLinearColor(C.R, C.G, C.B, FMath::Clamp(Alpha, 0.f, 1.f)); };
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	float RW = 0.f, RH = 0.f;
	GetTextSize(TEXT("Ay"), RW, RH, Font, 1.f);
	const float TextScale = RH > 0.f ? 16.f * S * 1.25f / RH : 1.f;

	const float PW = FMath::Min(W * 0.8f, 560.f * S), PX = (W - PW) * 0.5f, PY = 150.f * S, Rows = (float)ESunderSetting::Back + 1;
	const float RowH = 44.f * S, PH = Rows * RowH + 40.f * S;   // ten rows fit above the hint line
	DrawRect(FLinearColor(0.043f, 0.059f, 0.165f, 0.82f * A), PX, PY, PW, PH);     // night indigo glass
	for (const float Y : { PY, PY + PH }) { DrawLine(PX, Y, PX + PW, Y, Faded(Gilt, A), 1.f); }
	for (const float X : { PX, PX + PW }) { DrawLine(X, PY, X, PY + PH, Faded(Gilt, A), 1.f); }

	DrawWebText(TEXT("SETTINGS"), Faded(FLinearColor(0.96f, 0.84f, 0.48f), A), 110.f, 30.f, FLinearColor(0.83f, 0.69f, 0.22f));
	for (int32 i = 0; i < (int32)Rows; ++i)
	{
		const ESunderSetting Setting = (ESunderSetting)i;
		const bool bOn = i == Menu->GetSettingIndex();
		const float Y = PY + 20.f * S + i * RowH, MidY = Y + RowH * 0.5f;
		if (bOn)                                              // the focused row: a cyan wash and a light sweep across it
		{
			DrawRect(Faded(Sky, 0.16f * A), PX + 8.f * S, Y + 4.f * S, PW - 16.f * S, RowH - 8.f * S);
			const float Sweep = FMath::Frac(T * 0.5f);
			DrawRect(Faded(Sky, 0.12f * A * FMath::Sin(Sweep * UE_PI)), PX + 8.f * S + (PW - 60.f * S) * Sweep, Y + 4.f * S, 44.f * S, RowH - 8.f * S);
		}
		float TW = 0.f, TH = 0.f;
		const FString Name = USunderSettingsSubsystem::Label(Setting);
		GetTextSize(Name, TW, TH, Font, TextScale);
		if (Setting == ESunderSetting::Back)
		{
			DrawText(Name, Faded(bOn ? FLinearColor(0.94f, 0.98f, 1.f) : Sand, A), (W - TW) * 0.5f, MidY - TH * 0.5f, Font, TextScale);
			continue;
		}
		DrawText(Name, Faded(bOn ? FLinearColor(0.94f, 0.98f, 1.f) : Sand, A), PX + 28.f * S, MidY - TH * 0.5f, Font, TextScale);
		const float RightX = PX + PW - 28.f * S;
		if (Setting == ESunderSetting::MusicVolume || Setting == ESunderSetting::EffectsVolume)
		{
			const int32 V = Setting == ESunderSetting::MusicVolume ? Settings->GetMusicVolume() : Settings->GetEffectsVolume();
			const float Cell = 14.f * S, BarW = 10.f * Cell;
			for (int32 k = 0; k < 10; ++k)
			{
				DrawRect(k < V ? Faded(bOn ? Sky : Gilt, A) : Faded(Gilt, 0.2f * A), RightX - BarW + k * Cell, MidY - 7.f * S, Cell - 3.f * S, 14.f * S);
			}
			const FString Num = FString::FromInt(V);
			GetTextSize(Num, TW, TH, Font, TextScale);
			DrawText(Num, Faded(Sand, A), RightX - BarW - 20.f * S - TW, MidY - TH * 0.5f, Font, TextScale);
		}
		else
		{
			const FString Value = bOn ? FString::Printf(TEXT("<  %s  >"), *Settings->Describe(Setting)) : Settings->Describe(Setting);
			GetTextSize(Value, TW, TH, Font, TextScale);
			DrawText(Value, Faded(bOn ? Sky : Gilt, A), RightX - TW, MidY - TH * 0.5f, Font, TextScale);
			if (Setting == ESunderSetting::BulletColours)          // swatches: an enemy shot, then one of yours
			{
				FLinearColor Enemy, Player;
				USunderSettingsSubsystem::PaletteFor(Settings->GetBulletColours(), Enemy, Player);
				auto Shown = [](const FLinearColor& C) { const float P = FMath::Max3(C.R, C.G, C.B); return P > 0.f ? FLinearColor(C.R / P, C.G / P, C.B / P) : C; };
				const float R = 8.f * S, SX = RightX - TW - 28.f * S;
				Canvas->K2_DrawPolygon(nullptr, FVector2D(SX - 3.f * R, MidY), FVector2D(R, R), 24, Faded(Shown(Enemy), A));
				Canvas->K2_DrawPolygon(nullptr, FVector2D(SX, MidY), FVector2D(R, R), 24, Faded(Shown(Player), A));
			}
		}
	}
	DrawWebText(TEXT("W / S  choose    \u00B7    A / D  change    \u00B7    SPACE  toggle    \u00B7    ESC  back"),
		Faded(Sand, A), 680.f, 12.f);
}

void ASunderMenuHUD::DrawControls(const ASunderMenuGameMode* Menu, float T)
{
	// The same glass panel as Settings: each control with its key on the right; the chosen row waits for a key with a
	// pulsing PRESS A KEY; RESET TO DEFAULTS and BACK at the foot; the gamepad's fixed layout noted beneath.
	const USunderSettingsSubsystem* Settings = USunderSettingsSubsystem::Get(Menu);
	if (!Settings) { return; }
	const float W = Canvas->ClipX, H = Canvas->ClipY, S = H / 720.f;
	const float A = FMath::Clamp(T / 0.25f, 0.f, 1.f);
	const FLinearColor Gilt(0.83f, 0.69f, 0.22f), Sky(0.56f, 0.89f, 1.f), Sand(0.79f, 0.70f, 0.41f), Bright(0.94f, 0.98f, 1.f);
	auto Faded = [](const FLinearColor& C, float Alpha) { return FLinearColor(C.R, C.G, C.B, FMath::Clamp(Alpha, 0.f, 1.f)); };
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	float RW = 0.f, RH = 0.f;
	GetTextSize(TEXT("Ay"), RW, RH, Font, 1.f);
	const float TextScale = RH > 0.f ? 15.f * S * 1.25f / RH : 1.f;

	const int32 Count = (int32)ESunderControl::Count, Rows = Count + 2;
	const float PW = FMath::Min(W * 0.9f, 640.f * S), PX = (W - PW) * 0.5f, PY = 140.f * S, RowH = 42.f * S, PH = Rows * RowH + 30.f * S;
	const float ColX[2] = { PX + PW * 0.52f, PX + PW * 0.80f };   // the keyboard and gamepad columns' centres
	DrawRect(FLinearColor(0.043f, 0.059f, 0.165f, 0.82f * A), PX, PY, PW, PH);
	for (const float Y : { PY, PY + PH }) { DrawLine(PX, Y, PX + PW, Y, Faded(Gilt, A), 1.f); }
	for (const float X : { PX, PX + PW }) { DrawLine(X, PY, X, PY + PH, Faded(Gilt, A), 1.f); }
	DrawWebText(TEXT("CONTROLS"), Faded(FLinearColor(0.96f, 0.84f, 0.48f), A), 104.f, 30.f, FLinearColor(0.83f, 0.69f, 0.22f));
	for (int32 c = 0; c < 2; ++c)                               // the column heads, the chosen one lit
	{
		const FString Head = c == 0 ? TEXT("KEYBOARD") : TEXT("GAMEPAD");
		float HW = 0.f, HH = 0.f;
		GetTextSize(Head, HW, HH, Font, TextScale * 0.85f);
		DrawText(Head, Faded(c == Menu->GetControlColumn() ? Sky : Sand, A), ColX[c] - HW * 0.5f, PY - HH - 6.f * S, Font, TextScale * 0.85f);
	}

	for (int32 i = 0; i < Rows; ++i)
	{
		const bool bOn = i == Menu->GetControlIndex();
		const float Y = PY + 15.f * S + i * RowH, MidY = Y + RowH * 0.5f;
		if (bOn) { DrawRect(Faded(Sky, 0.16f * A), PX + 8.f * S, Y + 3.f * S, PW - 16.f * S, RowH - 6.f * S); }
		float TW = 0.f, TH = 0.f;
		if (i >= Count)                                        // RESET TO DEFAULTS, BACK
		{
			const FString Name = i == Count ? TEXT("RESET TO DEFAULTS") : TEXT("BACK");
			GetTextSize(Name, TW, TH, Font, TextScale);
			DrawText(Name, Faded(bOn ? Bright : Sand, A), (W - TW) * 0.5f, MidY - TH * 0.5f, Font, TextScale);
			continue;
		}
		const ESunderControl Control = (ESunderControl)i;
		const FString Name = USunderSettingsSubsystem::ControlLabel(Control);
		GetTextSize(Name, TW, TH, Font, TextScale);
		DrawText(Name, Faded(bOn ? Bright : Sand, A), PX + 28.f * S, MidY - TH * 0.5f, Font, TextScale);
		for (int32 c = 0; c < 2; ++c)                           // its key, then its pad button (the moves: the left stick)
		{
			const bool bCell = bOn && c == Menu->GetControlColumn();
			const bool bFixed = c == 1 && !USunderSettingsSubsystem::HasPadButton(Control);
			const bool bWaiting = bCell && Menu->IsCapturingKey();
			const FString Key = bWaiting ? (c == 0 ? TEXT("PRESS A KEY") : TEXT("PRESS A BUTTON"))
				: c == 0 ? USunderSettingsSubsystem::KeyName(Settings->GetKey(Control))
				: bFixed ? TEXT("LEFT STICK") : USunderSettingsSubsystem::PadName(Settings->GetPadKey(Control));
			const float KA = bWaiting ? 0.45f + 0.55f * FMath::Abs(FMath::Sin(T * 4.f)) : bFixed ? 0.45f : 1.f;
			GetTextSize(Key, TW, TH, Font, TextScale);
			const float KX = ColX[c] - TW * 0.5f;
			if (!bWaiting && !bFixed)                           // the key in a keycap
			{
				DrawRect(Faded(bCell ? Sky : Gilt, (bCell ? 0.22f : 0.12f) * A), KX - 8.f * S, MidY - TH * 0.5f - 3.f * S, TW + 16.f * S, TH + 6.f * S);
			}
			DrawText(Key, Faded(bCell ? Sky : Gilt, A * KA), KX, MidY - TH * 0.5f, Font, TextScale);
		}
	}
	DrawWebText(TEXT("A key or button already in use swaps over  \u00B7  ESC or the pad's BACK cancels a rebind"),
		Faded(Sand, 0.7f * A), 140.f + (Rows * 42.f + 30.f) + 26.f, 11.f);
	DrawWebText(TEXT("W / S  choose    \u00B7    A / D  keyboard or gamepad    \u00B7    SPACE  rebind    \u00B7    ESC  back"), Faded(Sand, A), 690.f, 12.f);
}
