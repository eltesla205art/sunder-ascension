// SUNDER: Ascension II — the settings and controls pages, shared by the title menu and the pause menu.
#include "SunderSettingsPanel.h"

#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "GameFramework/HUD.h"
#include "SunderSettingsSubsystem.h"

void FSunderSettingsPanel::Open(float Now)
{
	bControlsPage = false;
	SettingIndex = 0;
	bCapturing = false;
	OpenedAt = Now;
}

ESunderPanelCue FSunderSettingsPanel::Navigate(USunderSettingsSubsystem* Settings, int32 X, int32 Y, float Now)
{
	if (bCapturing) { return ESunderPanelCue::None; }
	if (bControlsPage)
	{
		const int32 Rows = (int32)ESunderControl::Count + 2;  // the controls, RESET, BACK
		if (Y != 0) { ControlIndex = (ControlIndex - Y + Rows) % Rows; return ESunderPanelCue::Move; }
		if (X != 0) { ControlColumn = X > 0 ? 1 : 0; return ESunderPanelCue::Move; }   // keyboard <-> gamepad
		return ESunderPanelCue::None;
	}
	const int32 Rows = (int32)ESunderSetting::Back + 1;
	if (Y != 0) { SettingIndex = (SettingIndex - Y + Rows) % Rows; return ESunderPanelCue::Move; }
	if (X != 0 && Settings && SettingIndex != (int32)ESunderSetting::Back && SettingIndex != (int32)ESunderSetting::Controls)
	{
		Settings->Change((ESunderSetting)SettingIndex, X);
		return ESunderPanelCue::Select;
	}
	return ESunderPanelCue::None;
}

ESunderPanelCue FSunderSettingsPanel::Confirm(USunderSettingsSubsystem* Settings, float Now, bool& bOutClose)
{
	bOutClose = false;
	if (bCapturing) { return ESunderPanelCue::None; }
	if (!bControlsPage)
	{
		if (SettingIndex == (int32)ESunderSetting::Back) { bOutClose = true; return ESunderPanelCue::Back; }
		if (SettingIndex == (int32)ESunderSetting::Controls)
		{
			bControlsPage = true;
			ControlIndex = 0;
			ControlColumn = 0;
			OpenedAt = Now;
			return ESunderPanelCue::Select;
		}
		if (Settings) { Settings->Change((ESunderSetting)SettingIndex, 1); }   // SPACE steps a setting on (toggles flip)
		return ESunderPanelCue::Select;
	}
	const int32 Count = (int32)ESunderControl::Count;
	if (ControlIndex < Count)                                 // PRESS A KEY / PRESS A BUTTON
	{
		if (ControlColumn == 1 && !USunderSettingsSubsystem::HasPadButton((ESunderControl)ControlIndex)) { return ESunderPanelCue::None; }
		bCapturing = true;
		return ESunderPanelCue::Select;
	}
	if (ControlIndex == Count)                                // RESET TO DEFAULTS (both columns)
	{
		if (Settings) { Settings->ResetKeys(); Settings->Save(); }
		return ESunderPanelCue::Select;
	}
	bool bIgnored = false;                                    // BACK
	return Back(Now, bIgnored);
}

ESunderPanelCue FSunderSettingsPanel::Back(float Now, bool& bOutClose)
{
	bOutClose = false;
	if (bCapturing) { return ESunderPanelCue::None; }
	if (bControlsPage)
	{
		bControlsPage = false;
		SettingIndex = (int32)ESunderSetting::Controls;
		OpenedAt = Now;
		return ESunderPanelCue::Back;
	}
	bOutClose = true;
	return ESunderPanelCue::Back;
}

bool FSunderSettingsPanel::CaptureKey(USunderSettingsSubsystem* Settings, const FKey& Key, ESunderPanelCue& OutCue)
{
	OutCue = ESunderPanelCue::None;
	if (!bControlsPage || !bCapturing) { return false; }
	if (Key == EKeys::Escape || Key == EKeys::Gamepad_Special_Left) { bCapturing = false; OutCue = ESunderPanelCue::Back; return true; }   // cancel
	const bool bPad = ControlColumn == 1;
	if (bPad ? !USunderSettingsSubsystem::CanBindPad(Key) : !USunderSettingsSubsystem::CanBind(Key)) { return true; }   // keep waiting
	bCapturing = false;
	if (Settings)
	{
		if (bPad) { Settings->SetPadKey((ESunderControl)ControlIndex, Key); }
		else { Settings->SetKey((ESunderControl)ControlIndex, Key); }
	}
	OutCue = ESunderPanelCue::Select;
	return true;
}

void FSunderSettingsPanel::Draw(AHUD* Hud, const USunderSettingsSubsystem* Settings, float Now) const
{
	if (!Hud || !Hud->Canvas || !Settings) { return; }
	const float T = Now - OpenedAt;
	if (bControlsPage) { DrawControls(Hud, Settings, T); }
	else { DrawSettings(Hud, Settings, T); }
}

void FSunderSettingsPanel::WebText(AHUD* Hud, const FString& Text, const FLinearColor& Color, float BaselineY, float Px, const FLinearColor& Glow)
{
	// Centred text at the web game's baseline and pixel size (on its 720-high canvas), with an optional soft glow.
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	const float S = Hud->Canvas->ClipY / 720.f;
	float RW = 0.f, RH = 0.f;
	Hud->GetTextSize(TEXT("Ay"), RW, RH, Font, 1.f);
	const float Scale = RH > 0.f ? Px * S * 1.25f / RH : 1.f;
	float TW = 0.f, TH = 0.f;
	Hud->GetTextSize(Text, TW, TH, Font, Scale);
	const float X = (Hud->Canvas->ClipX - TW) * 0.5f, Y = BaselineY * S - TH * 0.8f;
	if (Glow.A > 0.f)
	{
		const float O = FMath::Max(2.f, Px * S * 0.06f);
		for (const FVector2D D : { FVector2D(-O, 0.f), FVector2D(O, 0.f), FVector2D(0.f, -O), FVector2D(0.f, O) })
		{
			Hud->DrawText(Text, FLinearColor(Glow.R, Glow.G, Glow.B, 0.22f * Color.A), X + D.X, Y + D.Y, Font, Scale);
		}
	}
	Hud->DrawText(Text, Color, X, Y, Font, Scale);
}

void FSunderSettingsPanel::DrawSettings(AHUD* Hud, const USunderSettingsSubsystem* Settings, float T) const
{
	// A glass panel in the menus' style (DESIGN.md: night indigo, gold hairline, cyan on the focused row): each setting's
	// name on the left, its value on the right, volumes as ten-cell bars, BACK at the foot.
	const float W = Hud->Canvas->ClipX, H = Hud->Canvas->ClipY, S = H / 720.f;
	const float A = FMath::Clamp(T / 0.25f, 0.f, 1.f);
	const FLinearColor Gilt(0.83f, 0.69f, 0.22f), Sky(0.56f, 0.89f, 1.f), Sand(0.79f, 0.70f, 0.41f);
	auto Faded = [](const FLinearColor& C, float Alpha) { return FLinearColor(C.R, C.G, C.B, FMath::Clamp(Alpha, 0.f, 1.f)); };
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	float RW = 0.f, RH = 0.f;
	Hud->GetTextSize(TEXT("Ay"), RW, RH, Font, 1.f);
	const float TextScale = RH > 0.f ? 16.f * S * 1.25f / RH : 1.f;

	const float PW = FMath::Min(W * 0.8f, 560.f * S), PX = (W - PW) * 0.5f, PY = 150.f * S, Rows = (float)ESunderSetting::Back + 1;
	const float RowH = 44.f * S, PH = Rows * RowH + 40.f * S;   // ten rows fit above the hint line
	Hud->DrawRect(FLinearColor(0.043f, 0.059f, 0.165f, 0.82f * A), PX, PY, PW, PH);     // night indigo glass
	for (const float Y : { PY, PY + PH }) { Hud->DrawLine(PX, Y, PX + PW, Y, Faded(Gilt, A), 1.f); }
	for (const float X : { PX, PX + PW }) { Hud->DrawLine(X, PY, X, PY + PH, Faded(Gilt, A), 1.f); }

	WebText(Hud, TEXT("SETTINGS"), Faded(FLinearColor(0.96f, 0.84f, 0.48f), A), 110.f, 30.f, FLinearColor(0.83f, 0.69f, 0.22f));
	for (int32 i = 0; i < (int32)Rows; ++i)
	{
		const ESunderSetting Setting = (ESunderSetting)i;
		const bool bOn = i == SettingIndex;
		const float Y = PY + 20.f * S + i * RowH, MidY = Y + RowH * 0.5f;
		if (bOn)                                              // the focused row: a cyan wash and a light sweep across it
		{
			Hud->DrawRect(Faded(Sky, 0.16f * A), PX + 8.f * S, Y + 4.f * S, PW - 16.f * S, RowH - 8.f * S);
			const float Sweep = FMath::Frac(T * 0.5f);
			Hud->DrawRect(Faded(Sky, 0.12f * A * FMath::Sin(Sweep * UE_PI)), PX + 8.f * S + (PW - 60.f * S) * Sweep, Y + 4.f * S, 44.f * S, RowH - 8.f * S);
		}
		float TW = 0.f, TH = 0.f;
		const FString Name = USunderSettingsSubsystem::Label(Setting);
		Hud->GetTextSize(Name, TW, TH, Font, TextScale);
		if (Setting == ESunderSetting::Back)
		{
			Hud->DrawText(Name, Faded(bOn ? FLinearColor(0.94f, 0.98f, 1.f) : Sand, A), (W - TW) * 0.5f, MidY - TH * 0.5f, Font, TextScale);
			continue;
		}
		Hud->DrawText(Name, Faded(bOn ? FLinearColor(0.94f, 0.98f, 1.f) : Sand, A), PX + 28.f * S, MidY - TH * 0.5f, Font, TextScale);
		const float RightX = PX + PW - 28.f * S;
		if (Setting == ESunderSetting::MusicVolume || Setting == ESunderSetting::EffectsVolume)
		{
			const int32 V = Setting == ESunderSetting::MusicVolume ? Settings->GetMusicVolume() : Settings->GetEffectsVolume();
			const float Cell = 14.f * S, BarW = 10.f * Cell;
			for (int32 k = 0; k < 10; ++k)
			{
				Hud->DrawRect(k < V ? Faded(bOn ? Sky : Gilt, A) : Faded(Gilt, 0.2f * A), RightX - BarW + k * Cell, MidY - 7.f * S, Cell - 3.f * S, 14.f * S);
			}
			const FString Num = FString::FromInt(V);
			Hud->GetTextSize(Num, TW, TH, Font, TextScale);
			Hud->DrawText(Num, Faded(Sand, A), RightX - BarW - 20.f * S - TW, MidY - TH * 0.5f, Font, TextScale);
		}
		else
		{
			const FString Value = bOn ? FString::Printf(TEXT("<  %s  >"), *Settings->Describe(Setting)) : Settings->Describe(Setting);
			Hud->GetTextSize(Value, TW, TH, Font, TextScale);
			Hud->DrawText(Value, Faded(bOn ? Sky : Gilt, A), RightX - TW, MidY - TH * 0.5f, Font, TextScale);
			if (Setting == ESunderSetting::BulletColours)          // swatches: an enemy shot, then one of yours
			{
				FLinearColor Enemy, Player;
				USunderSettingsSubsystem::PaletteFor(Settings->GetBulletColours(), Enemy, Player);
				auto Shown = [](const FLinearColor& C) { const float P = FMath::Max3(C.R, C.G, C.B); return P > 0.f ? FLinearColor(C.R / P, C.G / P, C.B / P) : C; };
				const float R = 8.f * S, SX = RightX - TW - 28.f * S;
				Hud->Canvas->K2_DrawPolygon(nullptr, FVector2D(SX - 3.f * R, MidY), FVector2D(R, R), 24, Faded(Shown(Enemy), A));
				Hud->Canvas->K2_DrawPolygon(nullptr, FVector2D(SX, MidY), FVector2D(R, R), 24, Faded(Shown(Player), A));
			}
		}
	}
	WebText(Hud, TEXT("W / S  choose    \u00B7    A / D  change    \u00B7    SPACE  toggle    \u00B7    ESC  back"),
		Faded(Sand, A), 680.f, 12.f);
}

void FSunderSettingsPanel::DrawControls(AHUD* Hud, const USunderSettingsSubsystem* Settings, float T) const
{
	// The same glass panel as Settings: each control with its key on the right; the chosen row waits for a key with a
	// pulsing PRESS A KEY; RESET TO DEFAULTS and BACK at the foot; the gamepad's fixed layout noted beneath.
	const float W = Hud->Canvas->ClipX, H = Hud->Canvas->ClipY, S = H / 720.f;
	const float A = FMath::Clamp(T / 0.25f, 0.f, 1.f);
	const FLinearColor Gilt(0.83f, 0.69f, 0.22f), Sky(0.56f, 0.89f, 1.f), Sand(0.79f, 0.70f, 0.41f), Bright(0.94f, 0.98f, 1.f);
	auto Faded = [](const FLinearColor& C, float Alpha) { return FLinearColor(C.R, C.G, C.B, FMath::Clamp(Alpha, 0.f, 1.f)); };
	UFont* Font = GEngine ? GEngine->GetLargeFont() : nullptr;
	float RW = 0.f, RH = 0.f;
	Hud->GetTextSize(TEXT("Ay"), RW, RH, Font, 1.f);
	const float TextScale = RH > 0.f ? 15.f * S * 1.25f / RH : 1.f;

	const int32 Count = (int32)ESunderControl::Count, Rows = Count + 2;
	const float PW = FMath::Min(W * 0.9f, 640.f * S), PX = (W - PW) * 0.5f, PY = 140.f * S, RowH = 42.f * S, PH = Rows * RowH + 30.f * S;
	const float ColX[2] = { PX + PW * 0.52f, PX + PW * 0.80f };   // the keyboard and gamepad columns' centres
	Hud->DrawRect(FLinearColor(0.043f, 0.059f, 0.165f, 0.82f * A), PX, PY, PW, PH);
	for (const float Y : { PY, PY + PH }) { Hud->DrawLine(PX, Y, PX + PW, Y, Faded(Gilt, A), 1.f); }
	for (const float X : { PX, PX + PW }) { Hud->DrawLine(X, PY, X, PY + PH, Faded(Gilt, A), 1.f); }
	WebText(Hud, TEXT("CONTROLS"), Faded(FLinearColor(0.96f, 0.84f, 0.48f), A), 104.f, 30.f, FLinearColor(0.83f, 0.69f, 0.22f));
	for (int32 c = 0; c < 2; ++c)                               // the column heads, the chosen one lit
	{
		const FString Head = c == 0 ? TEXT("KEYBOARD") : TEXT("GAMEPAD");
		float HW = 0.f, HH = 0.f;
		Hud->GetTextSize(Head, HW, HH, Font, TextScale * 0.85f);
		Hud->DrawText(Head, Faded(c == ControlColumn ? Sky : Sand, A), ColX[c] - HW * 0.5f, PY - HH - 6.f * S, Font, TextScale * 0.85f);
	}

	for (int32 i = 0; i < Rows; ++i)
	{
		const bool bOn = i == ControlIndex;
		const float Y = PY + 15.f * S + i * RowH, MidY = Y + RowH * 0.5f;
		if (bOn) { Hud->DrawRect(Faded(Sky, 0.16f * A), PX + 8.f * S, Y + 3.f * S, PW - 16.f * S, RowH - 6.f * S); }
		float TW = 0.f, TH = 0.f;
		if (i >= Count)                                        // RESET TO DEFAULTS, BACK
		{
			const FString Name = i == Count ? TEXT("RESET TO DEFAULTS") : TEXT("BACK");
			Hud->GetTextSize(Name, TW, TH, Font, TextScale);
			Hud->DrawText(Name, Faded(bOn ? Bright : Sand, A), (W - TW) * 0.5f, MidY - TH * 0.5f, Font, TextScale);
			continue;
		}
		const ESunderControl Control = (ESunderControl)i;
		const FString Name = USunderSettingsSubsystem::ControlLabel(Control);
		Hud->GetTextSize(Name, TW, TH, Font, TextScale);
		Hud->DrawText(Name, Faded(bOn ? Bright : Sand, A), PX + 28.f * S, MidY - TH * 0.5f, Font, TextScale);
		for (int32 c = 0; c < 2; ++c)                           // its key, then its pad button (the moves: the left stick)
		{
			const bool bCell = bOn && c == ControlColumn;
			const bool bFixed = c == 1 && !USunderSettingsSubsystem::HasPadButton(Control);
			const bool bWaiting = bCell && bCapturing;
			const FString Key = bWaiting ? (c == 0 ? TEXT("PRESS A KEY") : TEXT("PRESS A BUTTON"))
				: c == 0 ? USunderSettingsSubsystem::KeyName(Settings->GetKey(Control))
				: bFixed ? TEXT("LEFT STICK") : USunderSettingsSubsystem::PadName(Settings->GetPadKey(Control));
			const float KA = bWaiting ? 0.45f + 0.55f * FMath::Abs(FMath::Sin(T * 4.f)) : bFixed ? 0.45f : 1.f;
			Hud->GetTextSize(Key, TW, TH, Font, TextScale);
			const float KX = ColX[c] - TW * 0.5f;
			if (!bWaiting && !bFixed)                           // the key in a keycap
			{
				Hud->DrawRect(Faded(bCell ? Sky : Gilt, (bCell ? 0.22f : 0.12f) * A), KX - 8.f * S, MidY - TH * 0.5f - 3.f * S, TW + 16.f * S, TH + 6.f * S);
			}
			Hud->DrawText(Key, Faded(bCell ? Sky : Gilt, A * KA), KX, MidY - TH * 0.5f, Font, TextScale);
		}
	}
	WebText(Hud, TEXT("A key or button already in use swaps over  \u00B7  ESC or the pad's BACK cancels a rebind"),
		Faded(Sand, 0.7f * A), 140.f + (Rows * 42.f + 30.f) + 26.f, 11.f);
	WebText(Hud, TEXT("W / S  choose    \u00B7    A / D  keyboard or gamepad    \u00B7    SPACE  rebind    \u00B7    ESC  back"), Faded(Sand, A), 690.f, 12.f);
}
