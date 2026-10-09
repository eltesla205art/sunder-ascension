// SUNDER: Ascension II — minimal HUD for the arena: score, lives, hull, the wave banner, a Keeper's intro and clear cards and GAME OVER.
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

	/** A Keeper beaten: HOUR N SURVIVED, the Hour's name · GATE OPEN, and its closing line (the web game's STAGE_CLEAR). */
	void DrawClearCard(const class ASunderGameMode* Mode, float Since, UFont* Font);

	/** The last life lost: the night closes in, DAWN DENIED, the score (and in Swarm how long you lasted). */
	void DrawDefeatCard(const class ASunderGameMode* Mode, float Since, UFont* Font);

	/** Centred text wrapped to MaxWidth; returns the Y below it. */
	float DrawCentredWrapped(const FString& Text, const FLinearColor& Color, float Y, float Scale, float MaxWidth, UFont* Font);

	/** Seconds the clear card stays up (story mode moves on to its Clear screen after the director's StoryClearDelay, 3 s). */
	float ClearCardTime = 3.6f;
};
