// SUNDER: Ascension II — wave data: a list of waves, each a list of spawn groups (enemy type × formation × timing).
// Edit DA_TestWaves (made by create_enemies_and_waves.py) or make new wave sets per stage.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SunderWaveSet.generated.h"

class ASunderEnemy;
class ASunderKeeper;
class USunderStageAudio;

UENUM(BlueprintType)
enum class ESunderFormation : uint8
{
	Column,     // one after another down a lane
	Line,       // side by side across the screen, centred on the lane
	V,          // a V pointing down the screen, centred on the lane
	Random,     // anywhere across the top
	Sides       // alternating from the left and right edges
};

USTRUCT(BlueprintType)
struct FSunderSpawnGroup
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	TSubclassOf<ASunderEnemy> EnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", meta = (ClampMin = "1"))
	int32 Count = 5;

	/** Seconds after the wave starts before this group's first enemy. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", meta = (ClampMin = "0"))
	float Delay = 0.f;

	/** Seconds between this group's enemies (0 = all at once). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", meta = (ClampMin = "0"))
	float Interval = 0.4f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	ESunderFormation Formation = ESunderFormation::Column;

	/** Where across the screen the group enters: -1 left edge, 0 centre, 1 right edge. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", meta = (ClampMin = "-1", ClampMax = "1"))
	float Lane = 0.f;

	/** Gap between enemies in Line and V formations. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	float Spacing = 160.f;
};

USTRUCT(BlueprintType)
struct FSunderWave
{
	GENERATED_BODY()

	/** Shown on screen as the wave starts. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	FString WaveName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	TArray<FSunderSpawnGroup> Groups;

	/** A Keeper for this wave: it enters at the top centre when the wave starts (give the wave a long MaxDuration). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	TSubclassOf<ASunderKeeper> Keeper;

	/** Switch to another Hour's sound from this wave on (the Keeper gauntlet gives each Keeper its Hour); empty = keep. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	TObjectPtr<USunderStageAudio> StageAudio;

	/** Wait for every enemy of this wave to be destroyed or gone before the next one (up to MaxDuration). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	bool bWaitForClear = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", meta = (ClampMin = "1"))
	float MaxDuration = 30.f;

	/** Breather before the next wave. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave", meta = (ClampMin = "0"))
	float BreakAfter = 2.f;
};

UCLASS(BlueprintType)
class SUNDER2_API USunderWaveSet : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	TArray<FSunderWave> Waves;

	/** The stage's music, ambience and cues (DA_StageAudio_*); its theme builds a layer each third of the way to the Keeper. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	TObjectPtr<USunderStageAudio> StageAudio;

	// ---- the Hour's difficulty: applied to every enemy of this set (not to its Keeper, whose numbers are its own).
	// create_hour_waves.py sets them from the web game's stage tuning, relative to Hour 1.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Difficulty", meta = (ClampMin = "0.1"))
	float HealthScale = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Difficulty", meta = (ClampMin = "0.1"))
	float SpeedScale = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Difficulty", meta = (ClampMin = "0.1"))
	float FireRateScale = 1.f;

	/** Enemy bullet speed. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Difficulty", meta = (ClampMin = "0.1"))
	float ShotSpeedScale = 1.f;

	/** Chance of each enemy dropping a pickup (the web game's Hour rate + 4 %, battle math #4); bombers add their bonus. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Difficulty", meta = (ClampMin = "0", ClampMax = "1"))
	float DropChance = 0.24f;

	/** Points per kill. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Difficulty", meta = (ClampMin = "0"))
	float ScoreScale = 1.f;

	/** After the last wave, start again from the first, tougher each time round. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	bool bLoop = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Loop", meta = (ClampMin = "1"))
	float LoopHealthScale = 1.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Loop", meta = (ClampMin = "1"))
	float LoopSpeedScale = 1.08f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves|Loop", meta = (ClampMin = "1"))
	float LoopFireRateScale = 1.12f;
};
