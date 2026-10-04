// SUNDER: Ascension II — minimal HUD for the arena: score, lives, hull, the wave banner and GAME OVER.
// Placeholder until a UMG HUD is designed; drawn with the canvas so there are no widget assets to make.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SunderHUD.generated.h"

UCLASS()
class SUNDER2_API ASunderHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;
};
