// SUNDER: Ascension II — what the hangar chose, kept across level loads (a game instance subsystem): the ship and the
// mode. The hangar sets it at launch; the arena's game mode reads it (and also takes ?Ship= / ?Mode= on the level URL,
// so `open L_SunderArena?Ship=ibis?Mode=Swarm` works from the console). Story mode passes through the story level
// first, which is why the choice lives here rather than only on the URL.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SunderLoadoutSubsystem.generated.h"

UENUM(BlueprintType)
enum class ESunderPlayMode : uint8
{
	Story,   // the Hours, one by one, each ending with its Keeper (or the arena's own waves when played on its own)
	Swarm    // no Keepers, no end: the waves loop, tougher each time round and coming faster and faster
};

UCLASS()
class SUNDER2_API USunderLoadoutSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Sunder|Loadout")
	void Choose(const FString& InShipId, ESunderPlayMode InMode) { ShipId = InShipId; Mode = InMode; }

	/** Read ?Ship=<id> and ?Mode=Story|Swarm from a level's options; anything missing keeps the current choice. */
	void ReadOptions(const FString& Options);

	UFUNCTION(BlueprintPure, Category = "Sunder|Loadout")
	FString GetShipId() const { return ShipId; }

	UFUNCTION(BlueprintPure, Category = "Sunder|Loadout")
	ESunderPlayMode GetMode() const { return Mode; }

private:
	FString ShipId = TEXT("sunborn");
	ESunderPlayMode Mode = ESunderPlayMode::Story;
};
