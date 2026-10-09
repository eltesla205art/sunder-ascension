// SUNDER: Ascension II — story screens and the hour map.
#include "SunderStoryHUD.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "Engine/World.h"
#include "SunderStoryGameMode.h"

namespace
{
	const FLinearColor Gold(0.90f, 0.76f, 0.32f);
	const FLinearColor Cyan(0.55f, 0.85f, 1.0f);
	const FLinearColor Pale(0.85f, 0.85f, 0.9f);
	const FLinearColor Dim(0.45f, 0.45f, 0.52f);
	const FLinearColor Magenta(1.f, 0.25f, 0.6f);

	FLinearColor Faded(const FLinearColor& C, float A) { return FLinearColor(C.R, C.G, C.B, C.A * FMath::Clamp(A, 0.f, 1.f)); }
	UFont* HudFont() { return GEngine ? GEngine->GetLargeFont() : nullptr; }
}

void ASunderStoryHUD::DrawBackdrop(UTexture2D* Art, float Light)
{
	const float W = Canvas->ClipX, H = Canvas->ClipY;
	DrawRect(FLinearColor(0.01f, 0.01f, 0.03f), 0.f, 0.f, W, H);
	if (!Art) { return; }
	const float Aspect = Art->GetSizeY() > 0 ? (float)Art->GetSizeX() / Art->GetSizeY() : 1.f;
	const float AW = H * Aspect;
	DrawTexture(Art, (W - AW) * 0.5f, 0.f, AW, H, 0.f, 0.f, 1.f, 1.f, FLinearColor(Light, Light, Light, 1.f));
}

float ASunderStoryHUD::DrawWrapped(const FString& Text, const FLinearColor& Color, float Y, float Scale, float MaxWidth)
{
	UFont* Font = HudFont();
	TArray<FString> Paragraphs;
	Text.ParseIntoArray(Paragraphs, TEXT("\n"), /*CullEmpty*/ false);
	float LineH = 0.f, Dummy = 0.f;
	GetTextSize(TEXT("Ay"), Dummy, LineH, Font, Scale);
	for (const FString& Paragraph : Paragraphs)
	{
		TArray<FString> Words;
		Paragraph.ParseIntoArrayWS(Words);
		FString Line;
		auto Flush = [&]()
		{
			float TW = 0.f, TH = 0.f;
			GetTextSize(Line, TW, TH, Font, Scale);
			DrawText(Line, Color, (Canvas->ClipX - TW) * 0.5f, Y, Font, Scale);
			Y += LineH * 1.15f;
			Line.Reset();
		};
		if (Words.Num() == 0) { Y += LineH * 0.7f; continue; }   // a blank line between paragraphs
		for (const FString& Word : Words)
		{
			const FString Try = Line.IsEmpty() ? Word : Line + TEXT(" ") + Word;
			float TW = 0.f, TH = 0.f;
			GetTextSize(Try, TW, TH, Font, Scale);
			if (TW > MaxWidth && !Line.IsEmpty()) { Flush(); Line = Word; }
			else { Line = Try; }
		}
		if (!Line.IsEmpty()) { Flush(); }
	}
	return Y;
}

void ASunderStoryHUD::DrawPrompt(const FString& Text, float T)
{
	const float Blink = 0.55f + 0.45f * FMath::Sin(T * 3.f);
	DrawWrapped(Text, Faded(FLinearColor::White, FMath::Clamp(T - 1.f, 0.f, 1.f) * Blink), Canvas->ClipY * 0.92f, 0.95f, Canvas->ClipX * 0.9f);
}

void ASunderStoryHUD::DrawMap(USunderStoryData* Data, int32 Next, float T)
{
	// The web game's hour map (MAP_NODES): twelve gates in four acts of three, a road snaking up from Hour 1 at the
	// bottom toward dawn at the top. Opened gates are gold, the next one is ringed in cyan and pulses, the rest wait dim.
	const float W = Canvas->ClipX, H = Canvas->ClipY;
	UFont* Font = HudFont();
	const int32 N = Data->Hours.Num();
	static const float WebNodes[12][2] = {                   // web/game.html MAP_NODES, on its 480 × 720 canvas
		{ 100.f, 630.f }, { 240.f, 600.f }, { 380.f, 630.f }, { 380.f, 500.f }, { 240.f, 470.f }, { 100.f, 500.f },
		{ 100.f, 370.f }, { 240.f, 340.f }, { 380.f, 370.f }, { 380.f, 240.f }, { 240.f, 210.f }, { 100.f, 170.f } };
	const float Half = H * 0.30f;                             // the web's 280 px across, kept in proportion
	auto GatePos = [&](int32 i)
	{
		const float* Web = WebNodes[FMath::Clamp(i, 0, 11)];
		return FVector2D(W * 0.5f + (Web[0] - 240.f) / 140.f * Half, H * (0.23f + (Web[1] - 170.f) / 460.f * 0.57f));
	};
	const float Scale = H / 720.f;                            // the web's node sizes, at this screen's height

	// Dawn waits at the road's end, a little brighter for every gate opened.
	const FVector2D End = GatePos(N - 1);
	for (int32 k = 0; k < 4; ++k)
	{
		DrawDisc(End, (56.f - 9.f * k) * Scale, Faded(FLinearColor(1.f, 0.8f, 0.4f), (0.025f + 0.05f * Next / FMath::Max(N, 1)) * (k + 1) * 0.5f));
	}
	for (int32 i = 0; i + 1 < N; ++i)                         // the road: gold where travelled
	{
		const FVector2D A = GatePos(i), B = GatePos(i + 1);
		DrawLine(A.X, A.Y, B.X, B.Y, i + 1 <= Next ? Faded(Gold, 0.85f) : Faded(Gold, 0.35f), 2.f);
	}
	if (Next > 0 && Next < N)                                  // a spark travels the last road into the next gate
	{
		const float F = FMath::Fmod(T * 0.6f, 1.f);
		const FVector2D P = FMath::Lerp(GatePos(Next - 1), GatePos(Next), F);
		DrawDisc(P, 4.f * Scale, Faded(Cyan, 1.f - F * 0.5f));
	}
	for (int32 i = 0; i < N; ++i)
	{
		const FVector2D P = GatePos(i);
		const bool bDone = i < Next, bNext = i == Next;
		const float R = (bNext ? 20.f : 15.f) * Scale;
		DrawDisc(P, R, bDone ? FLinearColor(0.83f, 0.69f, 0.22f) : bNext ? FLinearColor(0.07f, 0.19f, 0.29f) : FLinearColor(0.08f, 0.07f, 0.13f));
		DrawRing(P, R, bDone ? FLinearColor(0.96f, 0.84f, 0.48f) : bNext ? FLinearColor(0.56f, 0.89f, 1.f) : Faded(FLinearColor(0.61f, 0.54f, 0.31f), 0.5f),
			bNext ? 3.f : 1.5f);
		if (bNext)                                             // the pulse around the gate to open
		{
			const float Pulse = FMath::Sin(T * 4.f);
			DrawRing(P, (28.f + 3.f * Pulse) * Scale, Faded(FLinearColor(0.56f, 0.89f, 1.f), 0.4f + 0.3f * Pulse), 2.f);
		}
		const FString Num = FString::FromInt(i + 1);
		float TW = 0.f, TH = 0.f;
		GetTextSize(Num, TW, TH, Font, 0.8f);
		DrawText(Num, bDone ? FLinearColor(0.1f, 0.075f, 0.02f) : bNext ? FLinearColor(0.94f, 0.98f, 1.f) : FLinearColor(0.42f, 0.37f, 0.23f),
			P.X - TW * 0.5f, P.Y - TH * 0.5f, Font, 0.8f);
	}
	for (int32 Act = 0; Act * 3 < N; ++Act)                   // each act's name beside its row of three
	{
		const FString& Sub = Data->Hours[Act * 3].Subtitle;
		float TW = 0.f, TH = 0.f;
		GetTextSize(Sub, TW, TH, Font, 0.8f);
		const float RowY = (GatePos(Act * 3).Y + GatePos(FMath::Min(Act * 3 + 1, N - 1)).Y) * 0.5f;
		DrawText(Sub, Faded(Cyan, Next >= Act * 3 ? 0.85f : 0.3f), W * 0.5f - Half - 40.f * Scale - TW, RowY - TH * 0.5f, Font, 0.8f);
	}
}

void ASunderStoryHUD::DrawDisc(const FVector2D& Centre, float Radius, const FLinearColor& Color)
{
	Canvas->K2_DrawPolygon(nullptr, Centre, FVector2D(Radius, Radius), 32, Color);
}

void ASunderStoryHUD::DrawRing(const FVector2D& Centre, float Radius, const FLinearColor& Color, float Thickness)
{
	const int32 Sides = 40;
	for (int32 k = 0; k < Sides; ++k)
	{
		const float A0 = UE_TWO_PI * k / Sides, A1 = UE_TWO_PI * (k + 1) / Sides;
		DrawLine(Centre.X + FMath::Cos(A0) * Radius, Centre.Y + FMath::Sin(A0) * Radius,
			Centre.X + FMath::Cos(A1) * Radius, Centre.Y + FMath::Sin(A1) * Radius, Color, Thickness);
	}
}

void ASunderStoryHUD::DrawHUD()
{
	Super::DrawHUD();
	const ASunderStoryGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderStoryGameMode>();
	USunderStorySubsystem* Story = Mode ? Mode->Story() : nullptr;
	USunderStoryData* Data = Story ? Story->GetData() : nullptr;
	if (!Canvas || !Data) { return; }
	const float W = Canvas->ClipX, H = Canvas->ClipY, T = Mode->GetScreenTime();
	const float Wrap = FMath::Min(W * 0.8f, 1100.f);
	const int32 Index = Story->GetHourIndex();
	const FSunderStoryHour* Hour = Story->GetHour();
	const FString HourName = Hour ? Hour->Name.ToUpper() : FString();

	switch (Mode->GetScreen())
	{
	case ESunderStoryScreen::Opening:
	{
		// The crawl rises into place and holds.
		DrawBackdrop(Data->MapBackdrop, 0.25f);
		const float Rise = FMath::Max(0.f, 1.f - T / 6.f);
		float Y = H * 0.10f + Rise * H * 0.5f;
		for (int32 i = 0; i < Data->Opening.Num(); ++i)
		{
			const bool bHead = i < 2;
			const float A = FMath::Clamp((T - i * 0.25f) / 1.2f, 0.f, 1.f);
			Y = DrawWrapped(Data->Opening[i], Faded(bHead ? Gold : Pale, A), Y, bHead ? (i == 0 ? 1.8f : 1.2f) : 1.0f, Wrap);
		}
		DrawPrompt(TEXT("SPACE  begin    ·    ESC  title"), T);
		break;
	}
	case ESunderStoryScreen::Map:
	{
		DrawBackdrop(Data->MapBackdrop, 0.3f);
		DrawWrapped(TEXT("THE TWELVE GATES  ·  HOUR MAP"), Gold, H * 0.04f, 1.5f, Wrap);
		if (Hour)                                              // the web game's target card: the next Hour and its act
		{
			FString Short = Hour->Name;
			Short.RemoveFromStart(TEXT("Hour of "));
			const float Y = DrawWrapped(FString::Printf(TEXT("NEXT:  HOUR %d  ·  %s"), Index + 1, *Short.ToUpper()), Cyan, H * 0.10f, 1.1f, Wrap);
			DrawWrapped(Hour->Subtitle, Faded(Gold, 0.85f), Y, 0.9f, Wrap);
		}
		DrawMap(Data, Index, T);
		DrawWrapped(FString::Printf(TEXT("%d / %d gates opened    ·    SCORE  %d"), Index, Data->Hours.Num(), Story->GetTotalScore()),
			Faded(Gold, 0.8f), H * 0.875f, 0.9f, Wrap);
		DrawPrompt(TEXT("SPACE  open the marked gate    ·    ESC  title"), T);
		break;
	}
	case ESunderStoryScreen::Briefing:
	{
		if (!Hour) { break; }
		// The stage comes up out of the dark, the Keeper's portrait in its Hour's glow, then the words in turn: the Hour,
		// its name, act and Keeper, the quote, the brief (the web game's BRIEFING, revealed rather than all at once).
		DrawBackdrop(Hour->Backdrop, 0.35f * FMath::Clamp(T / 1.2f, 0.f, 1.f));
		auto Reveal = [T](float At) { return FMath::Clamp((T - At) / 0.6f, 0.f, 1.f); };
		if (Hour->KeeperPortrait)
		{
			const float S = FMath::Min(H * 0.28f, 300.f), PA = FMath::Clamp(T / 1.0f, 0.f, 1.f);
			const float G = S * (1.35f + 0.04f * FMath::Sin(T * 2.f));     // a slow breath in the Hour's colour behind it
			DrawTexture(Hour->KeeperPortrait, (W - G) * 0.5f, H * 0.04f - (G - S) * 0.5f, G, G, 0.f, 0.f, 1.f, 1.f,
				Faded(Hour->Tint, 0.35f * PA), BLEND_Additive);
			DrawTexture(Hour->KeeperPortrait, (W - S) * 0.5f, H * 0.04f, S, S, 0.f, 0.f, 1.f, 1.f, Faded(FLinearColor::White, PA));
		}
		float Y = H * 0.36f;
		Y = DrawWrapped(FString::Printf(TEXT("HOUR %d / %d"), Index + 1, Data->Hours.Num()), Faded(Cyan, Reveal(0.3f)), Y, 1.0f, Wrap);
		Y = DrawWrapped(HourName, Faded(Hour->Tint, Reveal(0.5f)), Y, 1.7f, Wrap);
		Y = DrawWrapped(FString::Printf(TEXT("%s  ·  Keeper: %s"), *Hour->Subtitle, *Hour->KeeperName), Faded(Pale, Reveal(0.8f)), Y, 0.95f, Wrap);
		Y = DrawWrapped(Hour->Quote, Faded(Gold, Reveal(1.3f)), Y + 18.f, 1.0f, Wrap);
		DrawWrapped(Hour->Brief, Faded(Pale, Reveal(1.9f)), Y + 14.f, 0.95f, Wrap);
		DrawPrompt(TEXT("SPACE  engage"), T);
		break;
	}
	case ESunderStoryScreen::Clear:
	{
		if (!Hour) { break; }
		DrawBackdrop(Hour->Backdrop, 0.2f);
		float Y = H * 0.12f;
		Y = DrawWrapped(FString::Printf(TEXT("HOUR %d SURVIVED"), Index + 1), Gold, Y, 1.8f, Wrap);
		Y = DrawWrapped(HourName + TEXT("  ·  GATE OPEN"), Hour->Tint, Y, 1.1f, Wrap);
		Y = DrawWrapped(Hour->ClearLine, Pale, Y + 16.f, 1.0f, Wrap);
		if (!Hour->Interlude.IsEmpty())
		{
			Y = DrawWrapped(Hour->Interlude, Faded(Cyan, (T - 0.6f) / 1.5f), Y + 24.f, 0.95f, Wrap);
		}
		Y = DrawWrapped(TEXT("+1 LIFE  ·  +1 BOMB  ·  +1 SHIELD"), Faded(Cyan, (T - 0.3f) / 0.8f), Y + 20.f, 1.0f, Wrap);   // battle math #5
		DrawWrapped(FString::Printf(TEXT("SCORE  %d"), Story->GetTotalScore()), Gold, Y + 14.f, 1.0f, Wrap);
		DrawPrompt(TEXT("SPACE  hour map"), T);
		break;
	}
	case ESunderStoryScreen::Victory:
	{
		DrawBackdrop(Data->MapBackdrop, FMath::Clamp(T / 4.f, 0.f, 0.8f));     // the light comes back
		DrawDawn(T);                                                           // and for the first time in forty days, dawn
		float Y = H * 0.10f;
		for (int32 i = 0; i < Data->Victory.Num(); ++i)
		{
			// The gate line opens it; ASCENSION COMPLETE and the Heir's name stand apart in gold (all-caps lines).
			const FString& Line = Data->Victory[i];
			const bool bHead = !Line.IsEmpty() && Line == Line.ToUpper() && Line != Line.ToLower();
			const float A = FMath::Clamp((T - 0.6f - i * 0.3f) / 1.2f, 0.f, 1.f);
			Y = DrawWrapped(Line, Faded(bHead ? Gold : Pale, A), Y, i == 0 ? 1.6f : bHead ? 1.25f : 1.0f, Wrap);
		}
		const float SA = FMath::Clamp((T - 0.6f - Data->Victory.Num() * 0.3f) / 1.2f, 0.f, 1.f);
		DrawWrapped(FString::Printf(TEXT("FINAL SCORE  %d"), Story->GetTotalScore()), Faded(Gold, SA), Y + 20.f, 1.3f, Wrap);
		DrawPrompt(TEXT("SPACE  title"), T);
		break;
	}
	case ESunderStoryScreen::Defeat:
	{
		DrawBackdrop(Hour ? Hour->Backdrop.Get() : nullptr, FMath::Lerp(0.3f, 0.12f, FMath::Clamp(T / 3.f, 0.f, 1.f)));   // the night closes in
		DrawDusk(T);
		float Y = H * 0.22f;
		Y = DrawWrapped(TEXT("DAWN DENIED"), Faded(Magenta, T / 0.8f), Y, 2.6f, Wrap);
		if (Hour) { Y = DrawWrapped(FString::Printf(TEXT("Hour %d  ·  %s"), Index + 1, *Hour->Name), Pale, Y + 10.f, 1.1f, Wrap); }
		Y = DrawWrapped(Data->DefeatTag, Faded(Gold, (T - 1.0f) / 1.2f), Y + 18.f, 1.0f, Wrap);
		DrawWrapped(FString::Printf(TEXT("SCORE  %d"), Story->GetTotalScore()), Pale, Y + 20.f, 1.0f, Wrap);
		DrawPrompt(TEXT("SPACE  rise again    ·    ESC  title"), T);
		break;
	}
	}
}

void ASunderStoryHUD::DrawDawn(float T)
{
	// And for the first time in forty days, dawn: the horizon warms and the sun climbs into it over about five seconds.
	const float Rise = FMath::InterpEaseOut(0.f, 1.f, FMath::Clamp(T / 5.f, 0.f, 1.f), 2.f);
	DrawHorizon(Rise, Rise, FLinearColor(1.f, 0.45f, 0.12f), FLinearColor(1.f, 0.82f, 0.4f), FLinearColor(1.f, 0.86f, 0.5f));
}

void ASunderStoryHUD::DrawDusk(float T)
{
	// DAWN DENIED: the last of the light, a dull red sun, sinks below the horizon and the glow goes out after it.
	const float Fall = FMath::InterpEaseIn(0.f, 1.f, FMath::Clamp(T / 4.f, 0.f, 1.f), 2.f);
	DrawHorizon(0.6f * (1.f - Fall), 0.55f * (1.f - Fall), FLinearColor(0.6f, 0.06f, 0.12f), FLinearColor(0.35f, 0.08f, 0.4f),
		FLinearColor(0.85f, 0.2f, 0.12f));
}

void ASunderStoryHUD::DrawHorizon(float Height, float Glow, const FLinearColor& Low, const FLinearColor& High, const FLinearColor& Sun)
{
	// Drawn with flat strips (the canvas has no gradients): a band of light up from the horizon, then the sun's disc
	// at Height (0 = just below the horizon, 1 = well clear of it).
	const float W = Canvas->ClipX, H = Canvas->ClipY;
	const float Horizon = H * 0.97f, Band = H * (0.15f + 0.35f * Glow);
	const int32 Strips = 32;
	for (int32 i = 0; i < Strips; ++i)
	{
		const float F = (float)i / Strips;                     // 0 at the horizon, 1 at the top of the band
		DrawRect(Faded(FMath::Lerp(Low, High, F), 0.22f * Glow * (1.f - F) * (1.f - F)), 0.f, Horizon - Band * (F + 1.f / Strips), W,
			Band / Strips + 1.f);
	}
	const float R = H * 0.08f, CY = Horizon + R * 1.2f - (R * 2.4f + H * 0.06f) * Height;
	const float SunA = 0.85f * FMath::Clamp(Height * 3.f, 0.f, 1.f);
	const int32 Rows = 40;
	for (int32 i = 0; i < Rows; ++i)                           // the disc, row by row, cut off at the horizon
	{
		const float DY = -R + 2.f * R * (i + 0.5f) / Rows, Y = CY + DY;
		if (Y > Horizon) { continue; }
		const float HalfW = FMath::Sqrt(FMath::Max(R * R - DY * DY, 0.f));
		DrawRect(Faded(Sun, SunA), W * 0.5f - HalfW, Y, HalfW * 2.f, 2.f * R / Rows + 1.f);
	}
}
