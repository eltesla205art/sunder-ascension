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
	/** Victory: the sky warms from the horizon and the sun climbs into it over the first seconds. */
	void DrawDawn(float T);
	/** Defeat: the sun sinks below the horizon and its glow goes out. */
	void DrawDusk(float T);
	void DrawHorizon(float Height, float Glow, const FLinearColor& Low, const FLinearColor& High, const FLinearColor& Sun);
	void DrawMap(class USunderStoryData* Data, int32 Next, float T);
	/** A filled circle (the canvas's polygon) and a ring of line segments, for the map's gates. */
	void DrawDisc(const FVector2D& Centre, float Radius, const FLinearColor& Color);
	void DrawRing(const FVector2D& Centre, float Radius, const FLinearColor& Color, float Thickness);
};
