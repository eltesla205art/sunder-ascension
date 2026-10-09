// SUNDER: Ascension II — minimal HUD for the arena: score, lives, hull, the wave banner, a Keeper's intro card and GAME OVER.
// Placeholder until a UMG HUD is designed; drawn with the canvas so there are no widget assets to make.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SunderHUD.generated.h"

class ASunderKeeper;
class UFont;

UCLASS()
class SUNDER2_API ASunderHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

private:
	/** A Keeper's intro card: veil, portrait in its Hour's glow, its Hour, name and taunt; fades out after Hold. */
	void DrawKeeperCard(const ASunderKeeper* Keeper, const FString& Name, const FString& Quote, float Since, float Hold, UFont* Font);
};
