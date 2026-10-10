// SUNDER: Ascension II — base for the screens outside the arena (title and hangar, the story and the hour map): no pawn,
// SunderMenuController for input (it calls Confirm / Back / Navigate), cues that can wait a beat and duck the music.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SunderFrontEndGameMode.generated.h"

class USoundBase;
class USunderMusicSubsystem;

UCLASS(Abstract)
class SUNDER2_API ASunderFrontEndGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASunderFrontEndGameMode();

	/** Space / Enter / A. */
	virtual void Confirm() {}
	/** Esc / Backspace / B. */
	virtual void Back() {}
	/** Arrows / WASD / D-pad / left stick: X = left -1 / right +1, Y = down -1 / up +1. */
	virtual void Navigate(int32 X, int32 Y) {}
	/** A key pressed while a screen is waiting to bind one (Settings → CONTROLS); true = taken, the menu ignores it. */
	virtual bool CaptureKey(const FKey& Key) { return false; }

	/** Seconds since the current screen opened (for fades). */
	UFUNCTION(BlueprintPure, Category = "Sunder|Screens")
	float GetScreenTime() const;

	/** No pawn on these screens: the controller and HUD are all there is. */
	virtual void RestartPlayer(AController* NewPlayer) override {}

protected:
	void MarkScreenOpened();
	/** Play a cue now or after Delay seconds; bDuck steps the music back under it (the web game's duck). */
	void PlayCue(USoundBase* Sound, bool bDuck, float Delay = 0.f);
	/** Drop cues still waiting to play (when the screen changes). */
	void CancelCues();
	USunderMusicSubsystem* Music() const;

private:
	void PlayCueNow(USoundBase* Sound, bool bDuck);

	float ScreenOpenedAt = 0.f;
	TArray<FTimerHandle> CueTimers;
};
