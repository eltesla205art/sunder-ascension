// SUNDER: Ascension II — the Codex panel.
#include "SunderCodexPanel.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "GameFramework/HUD.h"
#include "SunderCodexSubsystem.h"

#include "SunderCodexEntries.inl"

namespace
{
	const TCHAR* Tabs[3] = { TEXT("KEEPERS"), TEXT("HOURS"), TEXT("SHIPS") };
	FLinearColor Faded(const FLinearColor& C, float A) { return FLinearColor(C.R, C.G, C.B, FMath::Clamp(A, 0.f, 1.f)); }
	float ScaleFor(AHUD* Hud, UFont* Font, float Px)
	{
		float W = 0.f, H = 0.f;
		Hud->GetTextSize(TEXT("Ay"), W, H, Font, 1.f);
		return H > 0.f ? Px * (Hud->Canvas->ClipY / 720.f) * 1.25f / H : 1.f;
	}
}

void FSunderCodexPanel::Open(float Now)
{
	OpenedAt = Now;
}

int32 FSunderCodexPanel::Count() const
{
	return Tab == 0 ? UE_ARRAY_COUNT(GCodexKeepers) : Tab == 1 ? UE_ARRAY_COUNT(GCodexHours) : UE_ARRAY_COUNT(GCodexShips);
}

bool FSunderCodexPanel::Navigate(int32 X, int32 Y, float Now)
{
	if (X != 0) { Tab = (Tab + (X > 0 ? 1 : -1) + 3) % 3; OpenedAt = Now; return true; }
	if (Y != 0) { Index[Tab] = (Index[Tab] - Y + Count()) % Count(); return true; }   // up is +1
	return false;
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

	// The list on the left: number and name, or ??? while locked.
	const int32 N = Count(), Sel = Index[Tab];
	const float ListX = PX + 18.f * S, ListW = PW * 0.32f, RowH = FMath::Min(40.f * S, (PH - 30.f * S) / FMath::Max(N, 1));
	const float RowScale = ScaleFor(Hud, Font, 13.f);
	for (int32 i = 0; i < N; ++i)
	{
		FString Label;
		bool bOpen = true;
		if (Tab == 0) { bOpen = Codex && Codex->IsMet(GCodexKeepers[i].Hour); Label = FString::Printf(TEXT("%2d  %s"), GCodexKeepers[i].Hour, bOpen ? GCodexKeepers[i].Name : TEXT("???")); }
		else if (Tab == 1)
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
	if (Tab == 0)
	{
		const FSunderCodexKeeper& K = GCodexKeepers[Sel];
		if (!Codex || !Codex->IsMet(K.Hour))
		{
			Y = DrawWrapped(Hud, TEXT("???"), Faded(Dim, A), DX, Y, DW, 24.f);
			DrawWrapped(Hud, FString::Printf(TEXT("A Keeper waits beyond gate %d. Reach Hour %d to meet it."), K.Hour, K.Hour), Faded(Sand, A), DX, Y + 8.f * S, DW, 13.f);
			return;
		}
		const bool bBeaten = Codex->IsBeaten(K.Hour);
		if (Portraits.Num() < UE_ARRAY_COUNT(GCodexKeepers)) { Portraits.SetNum(UE_ARRAY_COUNT(GCodexKeepers)); }
		if (!Portraits[Sel].IsValid()) { Portraits[Sel].Reset(LoadObject<UTexture2D>(nullptr, K.Portrait)); }
		float TextW = DW;
		if (UTexture2D* Portrait = Portraits[Sel].Get())              // the portrait, top right of the entry
		{
			const float P = 150.f * S;
			Hud->DrawTexture(Portrait, DX + DW - P, Y, P, P, 0.f, 0.f, 1.f, 1.f, FLinearColor(1.f, 1.f, 1.f, A));
			TextW = DW - P - 16.f * S;
		}
		Y = DrawWrapped(Hud, K.Name, Faded(Gold, A), DX, Y, TextW, 24.f);
		Y = DrawWrapped(Hud, K.Epithet, Faded(Sky, A), DX, Y, TextW, 15.f);
		Y = DrawWrapped(Hud, K.HourLine, Faded(Sand, A), DX, Y + 6.f * S, TextW, 12.f);
		Y = DrawWrapped(Hud, K.Quote, Faded(Gilt, A), DX, Y + 10.f * S, TextW, 13.f);
		Y = FMath::Max(Y, PY + 22.f * S + 160.f * S);
		if (!bBeaten)
		{
			DrawWrapped(Hud, TEXT("Beat it to learn what it is."), Faded(Dim, A), DX, Y + 10.f * S, DW, 13.f);
			return;
		}
		Y = DrawWrapped(Hud, K.Lore, Faded(Pale, A), DX, Y + 10.f * S, DW, 13.f);
		Y = DrawWrapped(Hud, FString::Printf(TEXT("ATTACKS  %s"), K.Patterns), Faded(Sand, A), DX, Y + 12.f * S, DW, 12.f);
		DrawWrapped(Hud, FString::Printf(TEXT("ARENA  %s"), K.Arena), Faded(Sand, A), DX, Y + 4.f * S, DW, 12.f);
	}
	else if (Tab == 1)
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
