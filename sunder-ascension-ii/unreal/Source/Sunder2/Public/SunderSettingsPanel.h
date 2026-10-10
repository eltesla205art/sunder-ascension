// SUNDER: Ascension II — the settings and controls pages as one reusable panel: the title menu and the arena's pause
// menu both open it (same rows, same look, same key capture). It only keeps which row is chosen; the values live in
// USunderSettingsSubsystem. Its owner plays the cues it returns and draws it from its HUD.
#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"

class AHUD;
class USunderSettingsSubsystem;

/** What the owner should play after a step (its own sounds, if it has any). */
enum class ESunderPanelCue : uint8 { None, Move, Select, Back };

struct SUNDER2_API FSunderSettingsPanel
{
	/** Open on the settings page, first row. Now = the world's real time (it animates while the game is paused). */
	void Open(float Now);
	/** A / D, W / S (up is +1). */
	ESunderPanelCue Navigate(USunderSettingsSubsystem* Settings, int32 X, int32 Y, float Now);
	/** SPACE / A. bOutClose = BACK on the settings page: the owner closes the panel. */
	ESunderPanelCue Confirm(USunderSettingsSubsystem* Settings, float Now, bool& bOutClose);
	/** ESC / B / Back: the controls page goes back to settings; the settings page asks the owner to close. */
	ESunderPanelCue Back(float Now, bool& bOutClose);
	/** A raw key or button while a rebind waits; true = taken (the owner's input ignores it). */
	bool CaptureKey(USunderSettingsSubsystem* Settings, const FKey& Key, ESunderPanelCue& OutCue);
	bool IsCapturing() const { return bCapturing; }

	void Draw(AHUD* Hud, const USunderSettingsSubsystem* Settings, float Now) const;

private:
	void DrawSettings(AHUD* Hud, const USunderSettingsSubsystem* Settings, float T) const;
	void DrawControls(AHUD* Hud, const USunderSettingsSubsystem* Settings, float T) const;
	static void WebText(AHUD* Hud, const FString& Text, const FLinearColor& Color, float BaselineY, float Px,
		const FLinearColor& Glow = FLinearColor(0.f, 0.f, 0.f, 0.f));

	bool bControlsPage = false;
	int32 SettingIndex = 0;
	int32 ControlIndex = 0;
	int32 ControlColumn = 0;     // 0 keyboard, 1 gamepad
	bool bCapturing = false;
	float OpenedAt = 0.f;
};
