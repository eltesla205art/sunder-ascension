// SUNDER: Ascension II — wave data: a list of waves, each a list of spawn groups (enemy type × formation × timing).
// Edit DA_TestWaves (made by create_enemies_and_waves.py) or make new wave sets per stage.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SunderWaveSet.generated.h"

class ASunderEnemy;
class ASunderKeeper;

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
