// SUNDER: Ascension II — title screen and hangar.
#include "SunderMenuGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Engine/GameInstance.h"
#include "SunderMenuHUD.h"
#include "SunderMusicSubsystem.h"
#include "SunderStageAudio.h"
#include "SunderStorySubsystem.h"
#include "TimerManager.h"

ASunderMenuGameMode::ASunderMenuGameMode()
{
	HUDClass = ASunderMenuHUD::StaticClass();
}

void ASunderMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
	EnterTitle();
}

void ASunderMenuGameMode::EnterTitle()
{
	Screen = ESunderMenuScreen::Title;
	MarkScreenOpened();
	if (USunderMusicSubsystem* M = Music())
	{
		M->SetStage(TitleAudio);                             // wind at the gate, the portal's hum, drifting embers
		M->PlayStageMusic(MusicLayer);
	}
}

void ASunderMenuGameMode::EnterHangar()
{
	Screen = ESunderMenuScreen::Hangar;
	MarkScreenOpened();
	if (USunderMusicSubsystem* M = Music())
	{
		M->SetStage(HangarAudio);                            // machinery, vents, clanks, the base PA
		M->PlayStageMusic(MusicLayer);
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
		MarkScreenOpened();
		PlayCue(LaunchSound, true);
		GetWorldTimerManager().ClearTimer(RevTimer);
		PlayRev();
		if (USunderMusicSubsystem* M = Music())
		{
			M->StopMusic(LaunchDelay);
			M->SetStage(nullptr);                            // the hangar falls quiet behind you
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

void ASunderMenuGameMode::Navigate(int32 X, int32 Y)
{
	if (X != 0) { MoveShip(X); }
	if (Y != 0) { ToggleMode(); }
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
	USunderStorySubsystem* Story = GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderStorySubsystem>() : nullptr;
	if (ModeIndex == 0 && !StoryLevel.IsNone() && StoryData && Story)
	{
		Story->StartCampaign(StoryData);                     // the opening crawl, then the hour map
		UGameplayStatics::OpenLevel(this, StoryLevel, /*bAbsolute*/ true, Options);
		return;
	}
	if (Story) { Story->EndCampaign(); }                     // Swarm: the arena on its own wave set, looping
	UGameplayStatics::OpenLevel(this, ArenaLevel, /*bAbsolute*/ true, Options);
}
