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
	// Twelve gates in four acts of three, a serpentine road from dusk (top) to dawn (bottom).
	const float W = Canvas->ClipX, H = Canvas->ClipY;
	UFont* Font = HudFont();
	const int32 N = Data->Hours.Num();
	auto GatePos = [&](int32 i)
	{
		const int32 Act = i / 3, Step = i % 3;
		const int32 Col = (Act % 2 == 0) ? Step : 2 - Step;     // the road turns back each act
		return FVector2D(W * (0.30f + 0.20f * Col), H * (0.20f + 0.15f * Act));
	};
	for (int32 i = 0; i + 1 < N; ++i)                            // the road
	{
		const FVector2D A = GatePos(i), B = GatePos(i + 1);
		DrawLine(A.X, A.Y, B.X, B.Y, i < Next ? Gold : Faded(Dim, 0.6f), 2.f);
	}
	for (int32 i = 0; i < N; ++i)
	{
		const FSunderStoryHour& Hour = Data->Hours[i];
		const FVector2D P = GatePos(i);
		const bool bDone = i < Next, bNext = i == Next;
		const float R = bNext ? 22.f + 4.f * FMath::Sin(T * 4.f) : 16.f;
		const FLinearColor C = bDone ? Gold : bNext ? Hour.Tint : Dim;
		DrawRect(Faded(C, bDone || bNext ? 0.9f : 0.5f), P.X - R * 0.5f, P.Y - R * 0.5f, R, R);
		if (bNext) { DrawRect(Faded(Hour.Tint, 0.18f), P.X - R * 1.2f, P.Y - R * 1.2f, R * 2.4f, R * 2.4f); }
		const FString Num = FString::FromInt(i + 1);
		float TW = 0.f, TH = 0.f;
		GetTextSize(Num, TW, TH, Font, 0.8f);
		DrawText(Num, bNext ? FLinearColor::White : C, P.X - TW * 0.5f, P.Y + R * 0.5f + 6.f, Font, 0.8f);
	}
	for (int32 Act = 0; Act * 3 < N; ++Act)                      // act names at the left of each row
	{
		const FString& Sub = Data->Hours[Act * 3].Subtitle;
		DrawText(Sub, Faded(Cyan, Next >= Act * 3 ? 0.9f : 0.35f), W * 0.04f, H * (0.20f + 0.15f * Act) - 10.f, Font, 0.85f);
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
		DrawWrapped(TEXT("THE HOUR MAP"), Gold, H * 0.05f, 1.6f, Wrap);
		DrawMap(Data, Index, T);
		if (Hour)
		{
			const float Y = DrawWrapped(FString::Printf(TEXT("NEXT  ·  HOUR %d  ·  %s"), Index + 1, *HourName), Hour->Tint, H * 0.80f, 1.1f, Wrap);
			DrawWrapped(FString::Printf(TEXT("Keeper: %s"), *Hour->KeeperName), Pale, Y, 0.9f, Wrap);
		}
		DrawPrompt(FString::Printf(TEXT("SPACE  open the gate    ·    ESC  title    ·    SCORE  %d"), Story->GetTotalScore()), T);
		break;
	}
	case ESunderStoryScreen::Briefing:
	{
		if (!Hour) { break; }
		DrawBackdrop(Hour->Backdrop, 0.35f);
		if (Hour->KeeperPortrait)
		{
			const float S = FMath::Min(H * 0.28f, 300.f);
			DrawTexture(Hour->KeeperPortrait, (W - S) * 0.5f, H * 0.04f, S, S, 0.f, 0.f, 1.f, 1.f, Faded(FLinearColor::White, T / 1.0f));
		}
		float Y = H * 0.36f;
		Y = DrawWrapped(FString::Printf(TEXT("HOUR %d / %d"), Index + 1, Data->Hours.Num()), Cyan, Y, 1.0f, Wrap);
		Y = DrawWrapped(HourName, Hour->Tint, Y, 1.7f, Wrap);
		Y = DrawWrapped(FString::Printf(TEXT("%s  ·  Keeper: %s"), *Hour->Subtitle, *Hour->KeeperName), Pale, Y, 0.95f, Wrap);
		Y = DrawWrapped(Hour->Quote, Gold, Y + 18.f, 1.0f, Wrap);
		DrawWrapped(Hour->Brief, Pale, Y + 14.f, 0.95f, Wrap);
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
		DrawBackdrop(Hour ? Hour->Backdrop.Get() : nullptr, 0.12f);
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
	// Drawn with flat strips (the canvas has no gradients): a warm band up from the horizon, then the sun's disc
	// climbing through it, both easing in over about five seconds.
	const float W = Canvas->ClipX, H = Canvas->ClipY;
	const float Rise = FMath::InterpEaseOut(0.f, 1.f, FMath::Clamp(T / 5.f, 0.f, 1.f), 2.f);
	const float Horizon = H * 0.97f, Band = H * (0.15f + 0.35f * Rise);
	const int32 Strips = 32;
	for (int32 i = 0; i < Strips; ++i)
	{
		const float F = (float)i / Strips;                     // 0 at the horizon, 1 at the top of the band
		const FLinearColor C = FMath::Lerp(FLinearColor(1.f, 0.45f, 0.12f), FLinearColor(1.f, 0.82f, 0.4f), F);
		DrawRect(Faded(C, 0.22f * Rise * (1.f - F) * (1.f - F)), 0.f, Horizon - Band * (F + 1.f / Strips), W, Band / Strips + 1.f);
	}
	const float R = H * 0.08f, CY = Horizon + R * 1.2f - (R * 2.4f + H * 0.06f) * Rise;
	const int32 Rows = 40;
	for (int32 i = 0; i < Rows; ++i)                           // the disc, row by row, cut off at the horizon
	{
		const float DY = -R + 2.f * R * (i + 0.5f) / Rows, Y = CY + DY;
		if (Y > Horizon) { continue; }
		const float HalfW = FMath::Sqrt(FMath::Max(R * R - DY * DY, 0.f));
		DrawRect(Faded(FLinearColor(1.f, 0.86f, 0.5f), 0.85f * Rise), W * 0.5f - HalfW, Y, HalfW * 2.f, 2.f * R / Rows + 1.f);
	}
}
