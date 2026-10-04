// SUNDER: Ascension II — runs a wave set: schedules each group's enemies into its formation along the top of the
// arena, waits for the wave to clear, announces the next one, and loops tougher when the set runs out.
// Place one in the level (create_enemies_and_waves.py does) and point it at a USunderWaveSet.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SunderWaveDirector.generated.h"

class USunderWaveSet;
class ASunderEnemy;
class USunderStageAudio;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSunderWaveStarted, int32, WaveNumber, const FString&, WaveName);

UCLASS()
class SUNDER2_API ASunderWaveDirector : public AActor
{
	GENERATED_BODY()

public:
	ASunderWaveDirector();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	TObjectPtr<USunderWaveSet> WaveSet;

	/** Same arena as the ship's (X up the screen, Y across it). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	FVector ArenaCenter = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	FVector2D ArenaHalfExtents = FVector2D(600.f, 1100.f);

	/** How far above the top edge enemies appear. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	float SpawnMargin = 120.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	float StartDelay = 1.5f;

	/** Swarm: each second, gaps between enemies and waves shrink by this factor (the web game's 0.985 per second)… */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Swarm", meta = (ClampMin = "0.5", ClampMax = "1"))
	float SwarmPaceRate = 0.985f;

	/** …down to this fraction of their length (the web game stops at 0.25 s between spawns). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Swarm", meta = (ClampMin = "0.1", ClampMax = "1"))
	float SwarmPaceFloor = 0.4f;

	/** Story mode: seconds after the Hour's last wave (its Keeper) before the story screens open. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	float StoryClearDelay = 3.f;

	UPROPERTY(BlueprintAssignable, Category = "Waves")
	FSunderWaveStarted OnWaveStarted;

	/** 1-based count of waves started so far, across loops. */
	UFUNCTION(BlueprintPure, Category = "Waves")
	int32 GetWaveNumber() const { return WavesStarted; }

	UFUNCTION(BlueprintPure, Category = "Waves")
	int32 GetAliveCount() const;

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	struct FPendingSpawn
	{
		float Time = 0.f;
		TSubclassOf<ASunderEnemy> EnemyClass;
		FVector Location = FVector::ZeroVector;
	};

	void StartWave(int32 Index);
	void BuildSpawns(int32 Index);
	void PlayWaveAudio(int32 Index);
	void ReportStoryHourCleared();
	FTimerHandle StoryTimer;
	bool bStoryRun = false;
	bool bSwarm = false;
	float SwarmTime = 0.f;
	/** 1 normally; in Swarm, how much the gaps have shrunk so far. */
	float Pace() const;
	int32 StageLayer(int32 Index) const;

	UPROPERTY(Transient)
	TObjectPtr<USunderStageAudio> CurrentStage;

	TArray<FPendingSpawn> Pending;                 // sorted by Time
	TArray<TWeakObjectPtr<ASunderEnemy>> Alive;
	int32 WaveIndex = -1;
	int32 LoopCount = 0;
	int32 WavesStarted = 0;
	float WaveTime = 0.f;
	float WaitTimer = 0.f;
	bool bBetweenWaves = true;
	bool bFinished = false;
};
