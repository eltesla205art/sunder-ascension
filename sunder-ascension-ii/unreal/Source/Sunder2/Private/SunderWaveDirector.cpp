// SUNDER: Ascension II — runs a wave set.
#include "SunderWaveDirector.h"

#include "Engine/World.h"
#include "SunderEnemy.h"
#include "SunderGameMode.h"
#include "SunderKeeper.h"
#include "SunderMusicSubsystem.h"
#include "SunderStageAudio.h"
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
			Pending.Add({ Group.Delay + i * Group.Interval, Group.EnemyClass, Location });
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
	BuildSpawns(Index);
	const FString& Name = WaveSet->Waves[Index].WaveName;
	const FString Label = LoopCount > 0 ? FString::Printf(TEXT("%s  +%d"), *Name, LoopCount) : Name;
	OnWaveStarted.Broadcast(WavesStarted, Label);
	PlayWaveAudio(Index);
	if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>()) { Mode->AnnounceWave(WavesStarted, Label); }
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

	if (bBetweenWaves)
	{
		WaitTimer -= DeltaTime;
		if (WaitTimer > 0.f) { return; }
		int32 Next = WaveIndex + 1;
		if (Next >= WaveSet->Waves.Num())
		{
			if (!WaveSet->bLoop) { bFinished = true; return; }
			Next = 0;
			++LoopCount;
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
			Enemy->Setup(ArenaCenter, ArenaHalfExtents, HealthScale, SpeedScale, FireScale);
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
		WaitTimer = Wave.BreakAfter;
	}
}
