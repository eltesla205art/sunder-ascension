// SUNDER: Ascension II — game mode for the arena.
#include "SunderGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SunderHUD.h"
#include "SunderShipPawn.h"
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
		GetWorldTimerManager().SetTimer(RestartTimer, this, &ASunderGameMode::RestartArena, RestartDelay, false);
	}
}

void ASunderGameMode::RestartArena()
{
	UGameplayStatics::OpenLevel(this, FName(*UGameplayStatics::GetCurrentLevelName(this)));
}
