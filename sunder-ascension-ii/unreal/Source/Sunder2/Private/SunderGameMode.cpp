// SUNDER: Ascension II — game mode for the arena.
#include "SunderGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SunderHUD.h"
#include "SunderKeeper.h"
#include "SunderShipPawn.h"
#include "Engine/GameInstance.h"
#include "SunderMusicSubsystem.h"
#include "SunderStorySubsystem.h"
#include "TimerManager.h"

ASunderGameMode::ASunderGameMode()
{
	DefaultPawnClass = ASunderShipPawn::StaticClass();       // BP_SunderGameMode points this at BP_SunderShip
	HUDClass = ASunderHUD::StaticClass();
}

void ASunderGameMode::BeginPlay()
{
	Super::BeginPlay();
	Lives = StartingLives;
	Score = 0;
	bGameOver = false;
}

void ASunderGameMode::AddScore(int32 Points)
{
	if (!bGameOver) { Score += Points; }
}

void ASunderGameMode::AnnounceWave(int32 Number, const FString& Name)
{
	WaveNumber = Number;
	WaveName = Name;
	WaveAnnouncedAt = GetWorld()->GetTimeSeconds();
}

void ASunderGameMode::AnnounceKeeper(ASunderKeeper* Keeper, const FString& Title, const FString& InTaunt)
{
	ActiveKeeper = Keeper;
	KeeperTitle = Title;
	KeeperTaunt = InTaunt;
	KeeperAnnouncedAt = GetWorld()->GetTimeSeconds();
}

ASunderKeeper* ASunderGameMode::GetActiveKeeper() const
{
	return ActiveKeeper.Get();
}

void ASunderGameMode::ClearKeeper(ASunderKeeper* Keeper)
{
	if (ActiveKeeper.Get() == Keeper) { ActiveKeeper.Reset(); }
}

void ASunderGameMode::OnShipDestroyed(ASunderShipPawn* Ship)
{
	if (bGameOver || !Ship) { return; }
	Lives = FMath::Max(Lives - 1, 0);
	if (Lives > 0)
	{
		GetWorldTimerManager().SetTimer(RespawnTimer,
			FTimerDelegate::CreateWeakLambda(Ship, [Ship]() { Ship->Respawn(); }), RespawnDelay, false);
	}
	else
	{
		bGameOver = true;
		if (ASunderKeeper* Keeper = GetActiveKeeper()) { Keeper->Gloat(); }   // the Keeper has the last word
		GetWorldTimerManager().SetTimer(RestartTimer, this, &ASunderGameMode::RestartArena, RestartDelay, false);
	}
}

void ASunderGameMode::RestartArena()
{
	USunderStorySubsystem* Story = GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderStorySubsystem>() : nullptr;
	if (Story && Story->IsActive())
	{
		// DAWN DENIED, in the story: its theme comes in at the weight the fight had reached.
		const USunderMusicSubsystem* Music = GetWorld()->GetSubsystem<USunderMusicSubsystem>();
		Story->ReportDefeat(this, Score, ActiveKeeper.IsValid() ? 3 : (Music ? Music->GetLayer() : 1));
		return;
	}
	UGameplayStatics::OpenLevel(this, MenuLevel.IsNone() ? FName(*UGameplayStatics::GetCurrentLevelName(this)) : MenuLevel);
}
