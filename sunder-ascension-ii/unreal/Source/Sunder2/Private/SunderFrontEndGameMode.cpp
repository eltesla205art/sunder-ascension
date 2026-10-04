// SUNDER: Ascension II — base for the screens outside the arena.
#include "SunderFrontEndGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "SunderMenuController.h"
#include "SunderMusicSubsystem.h"
#include "TimerManager.h"

ASunderFrontEndGameMode::ASunderFrontEndGameMode()
{
	DefaultPawnClass = nullptr;
	PlayerControllerClass = ASunderMenuController::StaticClass();
}

float ASunderFrontEndGameMode::GetScreenTime() const
{
	return GetWorld()->GetTimeSeconds() - ScreenOpenedAt;
}

void ASunderFrontEndGameMode::MarkScreenOpened()
{
	ScreenOpenedAt = GetWorld()->GetTimeSeconds();
}

USunderMusicSubsystem* ASunderFrontEndGameMode::Music() const
{
	return GetWorld() ? GetWorld()->GetSubsystem<USunderMusicSubsystem>() : nullptr;
}

void ASunderFrontEndGameMode::PlayCueNow(USoundBase* Sound, bool bDuck)
{
	if (!Sound) { return; }
	UGameplayStatics::PlaySound2D(this, Sound);
	if (bDuck)
	{
		if (USunderMusicSubsystem* M = Music()) { M->Duck(Sound->GetDuration() * 0.7f); }
	}
}

void ASunderFrontEndGameMode::PlayCue(USoundBase* Sound, bool bDuck, float Delay)
{
	if (!Sound) { return; }
	if (Delay <= 0.f) { PlayCueNow(Sound, bDuck); return; }
	FTimerHandle& Handle = CueTimers.AddDefaulted_GetRef();
	TWeakObjectPtr<USoundBase> WeakSound(Sound);
	GetWorldTimerManager().SetTimer(Handle, FTimerDelegate::CreateWeakLambda(this, [this, WeakSound, bDuck]()
	{
		PlayCueNow(WeakSound.Get(), bDuck);
	}), Delay, false);
}

void ASunderFrontEndGameMode::CancelCues()
{
	for (FTimerHandle& Handle : CueTimers) { GetWorldTimerManager().ClearTimer(Handle); }
	CueTimers.Reset();
}
