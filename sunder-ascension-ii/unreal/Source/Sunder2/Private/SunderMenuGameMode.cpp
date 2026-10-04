// SUNDER: Ascension II — title screen and hangar.
#include "SunderMenuGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "SunderMenuController.h"
#include "SunderMenuHUD.h"
#include "SunderMusicSubsystem.h"
#include "SunderStageAudio.h"
#include "TimerManager.h"

ASunderMenuGameMode::ASunderMenuGameMode()
{
	DefaultPawnClass = nullptr;
	PlayerControllerClass = ASunderMenuController::StaticClass();
	HUDClass = ASunderMenuHUD::StaticClass();
}

void ASunderMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
	EnterTitle();
}

float ASunderMenuGameMode::GetScreenTime() const
{
	return GetWorld()->GetTimeSeconds() - ScreenOpenedAt;
}

void ASunderMenuGameMode::EnterTitle()
{
	Screen = ESunderMenuScreen::Title;
	ScreenOpenedAt = GetWorld()->GetTimeSeconds();
	if (USunderMusicSubsystem* Music = GetWorld()->GetSubsystem<USunderMusicSubsystem>())
	{
		Music->SetStage(TitleAudio);                         // wind at the gate, the portal's hum, drifting embers
		Music->PlayStageMusic(MusicLayer);
	}
}

void ASunderMenuGameMode::EnterHangar()
{
	Screen = ESunderMenuScreen::Hangar;
	ScreenOpenedAt = GetWorld()->GetTimeSeconds();
	if (USunderMusicSubsystem* Music = GetWorld()->GetSubsystem<USunderMusicSubsystem>())
	{
		Music->SetStage(HangarAudio);                        // machinery, vents, clanks, the base PA
		Music->PlayStageMusic(MusicLayer);
	}
}

void ASunderMenuGameMode::PlayCue(USoundBase* Sound, bool bDuck)
{
	if (!Sound) { return; }
	UGameplayStatics::PlaySound2D(this, Sound);
	if (bDuck)
	{
		if (USunderMusicSubsystem* Music = GetWorld()->GetSubsystem<USunderMusicSubsystem>()) { Music->Duck(Sound->GetDuration() * 0.7f); }
	}
}

void ASunderMenuGameMode::QueueRev(float Delay)
{
	// A newer pick replaces a rev that hasn't started yet, like the web game's per-ship timing.
	GetWorldTimerManager().SetTimer(RevTimer, this, &ASunderMenuGameMode::PlayRev, FMath::Max(Delay, 0.01f), false);
}

void ASunderMenuGameMode::PlayRev()
{
	if (Ships.IsValidIndex(ShipIndex)) { PlayCue(Ships[ShipIndex].RevSound, false); }
}

void ASunderMenuGameMode::Confirm()
{
	switch (Screen)
	{
	case ESunderMenuScreen::Title:
		PlayCue(StartSound, true);
		EnterHangar();
		QueueRev(0.9f);                                      // the chosen ship answers as the bay opens
		break;
	case ESunderMenuScreen::Hangar:
		Screen = ESunderMenuScreen::Launching;
		ScreenOpenedAt = GetWorld()->GetTimeSeconds();
		PlayCue(LaunchSound, true);
		GetWorldTimerManager().ClearTimer(RevTimer);
		PlayRev();
		if (USunderMusicSubsystem* Music = GetWorld()->GetSubsystem<USunderMusicSubsystem>())
		{
			Music->StopMusic(LaunchDelay);
			Music->SetStage(nullptr);                        // the hangar falls quiet behind you
		}
		GetWorldTimerManager().SetTimer(LaunchTimer, this, &ASunderMenuGameMode::OpenArena, FMath::Max(LaunchDelay, 0.01f), false);
		break;
	default:
		break;
	}
}

void ASunderMenuGameMode::Back()
{
	if (Screen != ESunderMenuScreen::Hangar) { return; }
	PlayCue(BackSound, false);
	GetWorldTimerManager().ClearTimer(RevTimer);
	EnterTitle();
}

void ASunderMenuGameMode::MoveShip(int32 Direction)
{
	if (Screen != ESunderMenuScreen::Hangar || Ships.Num() == 0 || Direction == 0) { return; }
	ShipIndex = (ShipIndex + (Direction > 0 ? 1 : -1) + Ships.Num()) % Ships.Num();
	const float Now = GetWorld()->GetTimeSeconds();
	if (Now - LastMoveCue >= 0.08f)                          // the web game's limit on the servo sound
	{
		LastMoveCue = Now;
		PlayCue(MoveSound, false);
	}
	QueueRev(0.22f);                                         // the bay turns, then that ship's engine answers
}

void ASunderMenuGameMode::ToggleMode()
{
	if (Screen != ESunderMenuScreen::Hangar) { return; }
	ModeIndex = 1 - ModeIndex;
	PlayCue(ModeSound, false);
}

void ASunderMenuGameMode::OpenArena()
{
	const FString Ship = Ships.IsValidIndex(ShipIndex) ? Ships[ShipIndex].Id : TEXT("sunborn");
	const FString Options = FString::Printf(TEXT("Ship=%s?Mode=%s"), *Ship, ModeIndex == 1 ? TEXT("Swarm") : TEXT("Story"));
	UGameplayStatics::OpenLevel(this, ArenaLevel, /*bAbsolute*/ true, Options);
}
