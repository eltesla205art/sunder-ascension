// SUNDER: Ascension II — the story campaign across level loads (a game instance subsystem): which Hour is next, the
// score so far, and which story screen to show when the story level opens. The menu starts it; the story screens move
// it along; the arena asks it for the current Hour's waves and reports the Hour survived or DAWN DENIED.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SunderStoryData.h"
#include "SunderShipPawn.h"
#include "SunderStorySubsystem.generated.h"

class USunderWaveSet;

UENUM(BlueprintType)
enum class ESunderStoryScreen : uint8
{
	Opening,     // the crawl
	Map,         // the hour map
	Briefing,    // the coming Hour
	Clear,       // an Hour survived (and an act interlude between acts)
	Victory,     // the twelfth gate: dawn
	Defeat       // DAWN DENIED
};

UCLASS()
class SUNDER2_API USunderStorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Sunder|Story")
	void StartCampaign(USunderStoryData* InData);

	UFUNCTION(BlueprintCallable, Category = "Sunder|Story")
	void EndCampaign();

	UFUNCTION(BlueprintPure, Category = "Sunder|Story")
	bool IsActive() const { return bActive && Data != nullptr; }

	UFUNCTION(BlueprintPure, Category = "Sunder|Story")
	USunderStoryData* GetData() const { return Data; }

	/** 0-based: the Hour being briefed or flown, or the last one survived on the Clear screen. */
	UFUNCTION(BlueprintPure, Category = "Sunder|Story")
	int32 GetHourIndex() const { return HourIndex; }

	UFUNCTION(BlueprintPure, Category = "Sunder|Story")
	int32 GetTotalScore() const { return TotalScore; }

	UFUNCTION(BlueprintPure, Category = "Sunder|Story")
	ESunderStoryScreen GetScreen() const { return Screen; }

	void SetScreen(ESunderStoryScreen InScreen) { Screen = InScreen; }

	/** The music layer the arena was on when it ended (DAWN DENIED's theme comes in at the same weight). */
	int32 GetEndLayer() const { return EndLayer; }

	const FSunderStoryHour* GetHour() const;

	/** The ship's power-ups, bombs, shields and hull at the end of an Hour, for the next one. */
	void CarryShip(const FSunderShipState& InState) { CarriedShip = InState; bHasCarriedShip = true; }
	bool HasCarriedShip() const { return bHasCarriedShip; }
	const FSunderShipState& GetCarriedShip() const { return CarriedShip; }

	/** Move on to the next Hour (after the Clear screen). */
	void AdvanceHour();

	/** Fly the current Hour: open the arena. */
	void EnterHour(const UObject* WorldContext);

	/** The arena's wave set for the current Hour: the story's enemy waves, then its Keeper, in its Hour's sound. */
	USunderWaveSet* MakeHourWaveSet(UObject* Outer) const;

	/** From the arena: the Hour's Keeper is beaten (Clear, or Victory after the twelfth). Opens the story level. */
	void ReportHourCleared(const UObject* WorldContext, int32 Score);

	/** From the arena: the last life is gone. Opens the story level on DAWN DENIED. */
	void ReportDefeat(const UObject* WorldContext, int32 Score, int32 MusicLayer);

private:
	void OpenStoryLevel(const UObject* WorldContext) const;

	UPROPERTY(Transient)
	TObjectPtr<USunderStoryData> Data;

	bool bActive = false;
	int32 HourIndex = 0;
	int32 TotalScore = 0;
	int32 EndLayer = 1;
	ESunderStoryScreen Screen = ESunderStoryScreen::Opening;
	FSunderShipState CarriedShip;
	bool bHasCarriedShip = false;
};
