// SUNDER: Ascension II — game mode for the arena. BP_SunderGameMode sets the default pawn to BP_SunderShip.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SunderGameMode.generated.h"

UCLASS()
class SUNDER2_API ASunderGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASunderGameMode();
};
