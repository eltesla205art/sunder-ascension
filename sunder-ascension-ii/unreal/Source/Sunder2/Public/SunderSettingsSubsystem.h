// SUNDER: Ascension II — the player's settings (DESIGN.md: performance modes and accessibility in Settings). Volumes
// and the hitbox toggle are the game's own, saved in GameUserSettings.ini under [SunderSettings]; window mode,
// performance mode and VSync are the engine's (UGameUserSettings), applied and saved with it.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SunderSettingsSubsystem.generated.h"

UENUM(BlueprintType)
enum class ESunderSetting : uint8
{
	MusicVolume,
	EffectsVolume,
	WindowMode,
	Performance,
	VSync,
	ScreenShake,
	BulletColours,
	ShowHitbox,
	Back
};

UCLASS()
class SUNDER2_API USunderSettingsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** 0–10 each; the game multiplies its sounds by Value / 10. */
	UFUNCTION(BlueprintPure, Category = "Settings") int32 GetMusicVolume() const { return MusicVolume; }
	UFUNCTION(BlueprintPure, Category = "Settings") int32 GetEffectsVolume() const { return EffectsVolume; }
	/** Accessibility: a ring on the ship's hit sphere, always shown. */
	UFUNCTION(BlueprintPure, Category = "Settings") bool ShowHitbox() const { return bShowHitbox; }
	/** Accessibility (DESIGN.md: adjustable screen-shake): 0 off, 1 low (half), 2 full (the web game's). */
	UFUNCTION(BlueprintPure, Category = "Settings") int32 GetScreenShake() const { return ScreenShake; }
	/** The shake multiplier for the arena (1 when there is no game instance yet). */
	static float ShakeScale(const UObject* WorldContext);

	/** Accessibility (DESIGN.md: colourblind-safe bullet palettes): 0 standard, 1 red-green safe (protanopia /
	 *  deuteranopia), 2 blue-yellow safe (tritanopia). */
	UFUNCTION(BlueprintPure, Category = "Settings") int32 GetBulletColours() const { return BulletColours; }
	/** The bullet colours to use (HDR): true when a colourblind palette is on, with every enemy and Keeper shot in
	 *  OutEnemy and the ship's shots and beam in OutPlayer (Okabe–Ito colours). */
	static bool BulletPalette(const UObject* WorldContext, FLinearColor& OutEnemy, FLinearColor& OutPlayer);
	/** A mode's pair for the settings screen's swatches (mode 0: the standard violet and gold). */
	static void PaletteFor(int32 Mode, FLinearColor& OutEnemy, FLinearColor& OutPlayer);

	/** Step a setting left (-1) or right (+1); toggles flip either way. Saved and applied at once. */
	UFUNCTION(BlueprintCallable, Category = "Settings") void Change(ESunderSetting Setting, int32 Direction);
	/** The value as the settings screen shows it ("7", "FULLSCREEN", "ON"…). */
	UFUNCTION(BlueprintPure, Category = "Settings") FString Describe(ESunderSetting Setting) const;
	static FString Label(ESunderSetting Setting);

	/** The volume multipliers for anything in the game that plays a sound (1 when there is no game instance yet). */
	static float MusicGain(const UObject* WorldContext);
	static float EffectsGain(const UObject* WorldContext);

private:
	void Save() const;

	int32 MusicVolume = 8;
	int32 EffectsVolume = 8;
	bool bShowHitbox = false;
	int32 ScreenShake = 2;
	int32 BulletColours = 0;
};
