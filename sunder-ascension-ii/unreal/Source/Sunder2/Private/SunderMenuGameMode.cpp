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
#include "SunderSettingsSubsystem.h"
#include "SunderLoadoutSubsystem.h"
#include "TimerManager.h"

ASunderMenuGameMode::ASunderMenuGameMode()
{
	HUDClass = ASunderMenuHUD::StaticClass();
}

void ASunderMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
	// From the arena's pause menu (ESC: quit to ship select) the menu opens on the hangar, as in the web game.
	if (UGameplayStatics::HasOption(OptionsString, TEXT("Hangar"))) { EnterHangar(); }
	else { EnterTitle(); }
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
		if (TitleIndex == 1) { PlayCue(ModeSound, false); EnterSettings(); break; }
		PlayCue(StartSound, true);
		EnterHangar();
		QueueRev(0.9f);                                      // the chosen ship answers as the bay opens
		break;
	case ESunderMenuScreen::Settings:
		if (SettingIndex == (int32)ESunderSetting::Back) { PlayCue(BackSound, false); EnterTitle(); break; }
		if (SettingIndex == (int32)ESunderSetting::Controls) { PlayCue(ModeSound, false); EnterControls(); break; }
		if (USunderSettingsSubsystem* Settings = GetGameInstance()->GetSubsystem<USunderSettingsSubsystem>())
		{
			Settings->Change((ESunderSetting)SettingIndex, 1);  // SPACE steps a setting on (toggles flip)
			PlayCue(ModeSound, false);
		}
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
	case ESunderMenuScreen::Controls:
	{
		const int32 Count = (int32)ESunderControl::Count;
		if (ControlIndex < Count)                             // PRESS A KEY / PRESS A BUTTON…
		{
			if (ControlColumn == 1 && !USunderSettingsSubsystem::HasPadButton((ESunderControl)ControlIndex)) { break; }   // the stick
			bCapturingKey = true;
			PlayCue(ModeSound, false);
			break;
		}
		if (ControlIndex == Count)                            // RESET TO DEFAULTS
		{
			if (USunderSettingsSubsystem* Settings = GetGameInstance()->GetSubsystem<USunderSettingsSubsystem>())
			{
				Settings->ResetKeys();                        // both columns
				Settings->Save();
			}
			PlayCue(ModeSound, false);
			break;
		}
		PlayCue(BackSound, false);                           // BACK
		EnterSettings();
		SettingIndex = (int32)ESunderSetting::Controls;
		break;
	}
	default:
		break;
	}
}

void ASunderMenuGameMode::EnterControls()
{
	Screen = ESunderMenuScreen::Controls;
	ControlIndex = 0;
	ControlColumn = 0;
	bCapturingKey = false;
	MarkScreenOpened();
}

bool ASunderMenuGameMode::CaptureKey(const FKey& Key)
{
	if (Screen != ESunderMenuScreen::Controls || !bCapturingKey) { return false; }
	bCapturingKey = false;
	if (Key == EKeys::Escape || Key == EKeys::Gamepad_Special_Left) { PlayCue(BackSound, false); return true; }   // cancel
	const bool bPad = ControlColumn == 1;
	if (bPad ? !USunderSettingsSubsystem::CanBindPad(Key) : !USunderSettingsSubsystem::CanBind(Key))
	{
		bCapturingKey = true;                                // the wrong kind of input: keep waiting
		return true;
	}
	if (USunderSettingsSubsystem* Settings = GetGameInstance()->GetSubsystem<USunderSettingsSubsystem>())
	{
		if (bPad) { Settings->SetPadKey((ESunderControl)ControlIndex, Key); }
		else { Settings->SetKey((ESunderControl)ControlIndex, Key); }
	}
	PlayCue(ModeSound, false);
	return true;
}

void ASunderMenuGameMode::EnterSettings()
{
	Screen = ESunderMenuScreen::Settings;
	SettingIndex = 0;
	MarkScreenOpened();                                      // the title's music and ambience carry on underneath
}

void ASunderMenuGameMode::Back()
{
	if (Screen == ESunderMenuScreen::Settings) { PlayCue(BackSound, false); EnterTitle(); return; }
	if (Screen == ESunderMenuScreen::Controls)
	{
		PlayCue(BackSound, false);
		EnterSettings();
		SettingIndex = (int32)ESunderSetting::Controls;
		return;
	}
	if (Screen != ESunderMenuScreen::Hangar) { return; }
	PlayCue(BackSound, false);
	GetWorldTimerManager().ClearTimer(RevTimer);
	EnterTitle();
}

void ASunderMenuGameMode::Navigate(int32 X, int32 Y)
{
	if (Screen == ESunderMenuScreen::Title)
	{
		if (Y != 0) { TitleIndex = 1 - TitleIndex; PlayCue(MoveSound, false); }
		return;
	}
	if (Screen == ESunderMenuScreen::Controls)
	{
		const int32 Rows = (int32)ESunderControl::Count + 2;  // the controls, RESET, BACK
		if (Y != 0) { ControlIndex = (ControlIndex - Y + Rows) % Rows; PlayCue(MoveSound, false); }
		else if (X != 0) { ControlColumn = X > 0 ? 1 : 0; PlayCue(MoveSound, false); }   // keyboard ↔ gamepad
		return;
	}
	if (Screen == ESunderMenuScreen::Settings)
	{
		const int32 Rows = (int32)ESunderSetting::Back + 1;
		if (Y != 0)                                          // up is +1 from the controller
		{
			SettingIndex = (SettingIndex - Y + Rows) % Rows;
			PlayCue(MoveSound, false);
		}
		else if (X != 0 && SettingIndex != (int32)ESunderSetting::Back && SettingIndex != (int32)ESunderSetting::Controls)
		{
			if (USunderSettingsSubsystem* Settings = GetGameInstance()->GetSubsystem<USunderSettingsSubsystem>())
			{
				Settings->Change((ESunderSetting)SettingIndex, X);
				PlayCue(ModeSound, false);
			}
		}
		return;
	}
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
	if (USunderLoadoutSubsystem* Loadout = GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderLoadoutSubsystem>() : nullptr)
	{
		Loadout->Choose(Ship, ModeIndex == 1 ? ESunderPlayMode::Swarm : ESunderPlayMode::Story);   // through the story level too
	}
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
