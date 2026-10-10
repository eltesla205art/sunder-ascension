// SUNDER: Ascension II — the arena's player controller: hands raw key and button presses to the pause menu's settings
// panel while it waits to rebind one (Settings → CONTROLS), before the ship's own input sees them.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SunderArenaController.generated.h"

UCLASS()
class SUNDER2_API ASunderArenaController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual bool InputKey(const FInputKeyParams& Params) override;
};
