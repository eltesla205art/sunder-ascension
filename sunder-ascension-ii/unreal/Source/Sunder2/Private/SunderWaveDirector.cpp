// SUNDER: Ascension II — runs a wave set.
#include "SunderWaveDirector.h"

#include "Engine/World.h"
#include "EngineUtils.h"
#include "SunderEnemy.h"
#include "SunderGameMode.h"
#include "SunderKeeper.h"
#include "SunderMusicSubsystem.h"
#include "SunderStageAudio.h"
#include "SunderStorySubsystem.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "SunderWaveSet.h"

ASunderWaveDirector::ASunderWaveDirector()
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorHiddenInGame(true);
}

void ASunderWaveDirector::BeginPlay()
{
	Super::BeginPlay();
	ArenaCenter.Z = GetActorLocation().Z;                    // spawn on this actor's plane (place it at the ship's height)
	// Story mode: fly the campaign's current Hour (its enemy waves, then its Keeper, in its own sound) instead.
	USunderStorySubsystem* Story = GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderStorySubsystem>() : nullptr;
	if (Story && Story->IsActive())
	{
		if (USunderWaveSet* HourSet = Story->MakeHourWaveSet(this)) { WaveSet = HourSet; bStoryRun = true; }
	}
	// Swarm (chosen in the hangar): this set's waves without their Keepers, looping, faster and faster.
	if (const ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>(); Mode && !bStoryRun) { bSwarm = Mode->IsSwarm(); }
	WaitTimer = StartDelay;
	bBetweenWaves = true;
	if (!WaveSet) { UE_LOG(LogTemp, Warning, TEXT("SunderWaveDirector %s has no WaveSet."), *GetName()); }
}

int32 ASunderWaveDirector::GetAliveCount() const
{
	int32 N = 0;
	for (const TWeakObjectPtr<ASunderEnemy>& E : Alive) { if (E.IsValid()) { ++N; } }
	return N;
}

void ASunderWaveDirector::BuildSpawns(int32 Index)
{
	Pending.Reset();
	const FSunderWave& Wave = WaveSet->Waves[Index];
	FRandomStream Random(1234 + Index * 31 + LoopCount * 977);    // the same wave plays out the same way each time
	const float TopX = ArenaCenter.X + ArenaHalfExtents.X + SpawnMargin;
	const float Width = ArenaHalfExtents.Y * 0.85f;

	for (const FSunderSpawnGroup& Group : Wave.Groups)
	{
		if (!Group.EnemyClass) { continue; }
		const float LaneY = ArenaCenter.Y + Group.Lane * Width;
		const float Mid = (Group.Count - 1) * 0.5f;
		for (int32 i = 0; i < Group.Count; ++i)
		{
			FVector Location(TopX, LaneY, ArenaCenter.Z);
			switch (Group.Formation)
			{
			case ESunderFormation::Column:
				break;
			case ESunderFormation::Line:
				Location.Y = LaneY + (i - Mid) * Group.Spacing;
				break;
			case ESunderFormation::V:
				Location.Y = LaneY + (i - Mid) * Group.Spacing;
				Location.X = TopX + FMath::Abs(i - Mid) * Group.Spacing * 0.6f;   // wings trail behind the point
				break;
			case ESunderFormation::Random:
				Location.Y = ArenaCenter.Y + Random.FRandRange(-Width, Width);
				break;
			case ESunderFormation::Sides:
				Location.Y = ArenaCenter.Y + ((i % 2 == 0) ? -Width : Width);
				break;
			}
			Location.Y = FMath::Clamp(Location.Y, ArenaCenter.Y - Width, ArenaCenter.Y + Width);
			Pending.Add({ (Group.Delay + i * Group.Interval) * Pace(), Group.EnemyClass, Location });
		}
	}
	if (Wave.Keeper)
	{
		Pending.Add({ 0.f, TSubclassOf<ASunderEnemy>(Wave.Keeper.Get()), FVector(TopX + 200.f, ArenaCenter.Y, ArenaCenter.Z) });
	}
	Pending.Sort([](const FPendingSpawn& A, const FPendingSpawn& B) { return A.Time < B.Time; });
}

void ASunderWaveDirector::StartWave(int32 Index)
{
	WaveIndex = Index;
	WaveTime = 0.f;
	bBetweenWaves = false;
	++WavesStarted;
	if (WaveSet->Waves[Index].Keeper) { ClearForKeeper(); }
	BuildSpawns(Index);
	const FString& Name = WaveSet->Waves[Index].WaveName;
	const FString Label = LoopCount > 0 ? FString::Printf(TEXT("%s  +%d"), *Name, LoopCount) : Name;
	OnWaveStarted.Broadcast(WavesStarted, Label);
	PlayWaveAudio(Index);
	if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>()) { Mode->AnnounceWave(WavesStarted, Label); }
}

void ASunderWaveDirector::ClearForKeeper()
{
	// No score, no drops, no cue: the field is cleared for the Keeper, not won. Their shots stay in flight, as in the
	// web game.
	TArray<ASunderEnemy*> Leftovers;
	for (TActorIterator<ASunderEnemy> It(GetWorld()); It; ++It)
	{
		if (!It->IsA<ASunderKeeper>()) { Leftovers.Add(*It); }
	}
	for (ASunderEnemy* Enemy : Leftovers) { Enemy->Banish(); }
	Alive.RemoveAll([](const TWeakObjectPtr<ASunderEnemy>& E) { return !E.IsValid() || !E->IsA<ASunderKeeper>(); });
}

void ASunderWaveDirector::ReportStoryHourCleared()
{
	const ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>();
	if (Mode && Mode->IsGameOver()) { return; }              // DAWN DENIED got there first
	if (USunderStorySubsystem* Story = GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderStorySubsystem>() : nullptr)
	{
		// Battle math #5: every Hour survived, +1 hull (up to 2 over full), +1 bomb, +1 shield, carried to the next.
		if (const ASunderShipPawn* Ship = Cast<ASunderShipPawn>(UGameplayStatics::GetPlayerPawn(this, 0)))
		{
			FSunderShipState State = Ship->GetState();
			State.Health = FMath::Min(State.Health + 1.f, Ship->MaxHealth + 2.f);
			State.Bombs = FMath::Min(State.Bombs + 1, 9);
			State.Shield = FMath::Min(State.Shield + 1, 3);
			Story->CarryShip(State);
		}
		Story->ReportHourCleared(this, Mode ? Mode->GetScore() : 0);
	}
}

float ASunderWaveDirector::Pace() const
{
	return bSwarm ? FMath::Max(SwarmPaceFloor, FMath::Pow(SwarmPaceRate, SwarmTime)) : 1.f;
}

int32 ASunderWaveDirector::StageLayer(int32 Index) const
{
	// Like the web game: the theme builds in thirds as the stage nears its Keeper (here: through its enemy waves).
	int32 Before = 0, Total = 0;
	for (int32 i = 0; i < WaveSet->Waves.Num(); ++i)
	{
		if (WaveSet->Waves[i].Keeper) { continue; }
		if (i < Index) { ++Before; }
		++Total;
	}
	return Total > 0 ? FMath::Min(3, 1 + (3 * Before) / Total) : 1;
}

void ASunderWaveDirector::PlayWaveAudio(int32 Index)
{
	USunderMusicSubsystem* Music = GetWorld()->GetSubsystem<USunderMusicSubsystem>();
	if (!Music) { return; }
	const FSunderWave& Wave = WaveSet->Waves[Index];
	if (Wave.StageAudio) { CurrentStage = Wave.StageAudio; }
	else if (!CurrentStage) { CurrentStage = WaveSet->StageAudio; }
	if (!CurrentStage) { return; }

	const bool bNewStage = Music->GetStage() != CurrentStage;
	Music->SetStage(CurrentStage);
	if (Wave.Keeper) { return; }                             // the Keeper brings its own theme and its own cry
	Music->PlayStageCue(bNewStage ? ESunderStageCue::Start : ESunderStageCue::Wave);
	Music->PlayStageMusic(StageLayer(Index));
}

void ASunderWaveDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!WaveSet || WaveSet->Waves.Num() == 0 || bFinished) { return; }
	if (const ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>()) { if (Mode->IsGameOver()) { return; } }

	if (bSwarm) { SwarmTime += DeltaTime; }                 // the pace quickens between waves too

	if (bBetweenWaves)
	{
		WaitTimer -= DeltaTime;
		if (WaitTimer > 0.f) { return; }
		int32 Next = WaveIndex + 1;
		for (int32 Tries = 0; ; ++Tries)
		{
			if (Next >= WaveSet->Waves.Num())
			{
				if (!WaveSet->bLoop && !bSwarm)
				{
					bFinished = true;
					// The Hour is survived: let its fanfare (the stage's Clear cue) ring, then on to the story screens.
					if (bStoryRun) { GetWorldTimerManager().SetTimer(StoryTimer, this, &ASunderWaveDirector::ReportStoryHourCleared, StoryClearDelay, false); }
					return;
				}
				Next = 0;
				++LoopCount;
			}
			if (!bSwarm || !WaveSet->Waves[Next].Keeper) { break; }
			if (Tries > WaveSet->Waves.Num()) { bFinished = true; return; }   // a set of nothing but Keepers: no Swarm in it
			++Next;                                                            // Swarm: no Keepers
		}
		StartWave(Next);
		return;
	}

	WaveTime += DeltaTime;
	const float HealthScale = FMath::Pow(WaveSet->LoopHealthScale, LoopCount);
	const float SpeedScale = FMath::Pow(WaveSet->LoopSpeedScale, LoopCount);
	const float FireScale = FMath::Pow(WaveSet->LoopFireRateScale, LoopCount);
	int32 Spawned = 0;
	while (Spawned < Pending.Num() && Pending[Spawned].Time <= WaveTime)
	{
		const FPendingSpawn& Spawn = Pending[Spawned++];
		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		if (ASunderEnemy* Enemy = GetWorld()->SpawnActor<ASunderEnemy>(Spawn.EnemyClass, Spawn.Location, FRotator::ZeroRotator, Params))
		{
			if (Enemy->IsA<ASunderKeeper>())
			{
				Enemy->Setup(ArenaCenter, ArenaHalfExtents, HealthScale, SpeedScale, FireScale);   // a Keeper's numbers are its own
			}
			else
			{
				Enemy->Setup(ArenaCenter, ArenaHalfExtents, HealthScale * WaveSet->HealthScale, SpeedScale * WaveSet->SpeedScale,
					FireScale * WaveSet->FireRateScale, WaveSet->ShotSpeedScale, WaveSet->ScoreScale);
				Enemy->DropChance = FMath::Clamp(WaveSet->DropChance + Enemy->DropChanceBonus, 0.f, 1.f);
				if (WaveSet->ExplosionTint.A > 0.f) { Enemy->DeathColor = WaveSet->ExplosionTint; }   // the Hour's colour
			}
			Alive.Add(Enemy);
		}
	}
	if (Spawned > 0) { Pending.RemoveAt(0, Spawned); }
	Alive.RemoveAll([](const TWeakObjectPtr<ASunderEnemy>& E) { return !E.IsValid(); });

	const FSunderWave& Wave = WaveSet->Waves[WaveIndex];
	const bool bAllOut = Pending.Num() == 0 && (!Wave.bWaitForClear || Alive.Num() == 0);
	if (bAllOut || WaveTime >= Wave.MaxDuration)
	{
		bBetweenWaves = true;
		WaitTimer = Wave.BreakAfter * Pace();
	}
}
