// SUNDER: Ascension II — canvas drawing for the story screens and the hour map (SunderStoryGameMode holds the state).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SunderStoryHUD.generated.h"

class UTexture2D;

UCLASS()
class SUNDER2_API ASunderStoryHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

private:
	/** Draw text centred, wrapped to MaxWidth; returns the Y below it. Keeps paragraph breaks ("\n"). */
	float DrawWrapped(const FString& Text, const FLinearColor& Color, float Y, float Scale, float MaxWidth);
	void DrawBackdrop(UTexture2D* Art, float Light);
	void DrawPrompt(const FString& Text, float T);
	void DrawMap(class USunderStoryData* Data, int32 Next, float T);
};
