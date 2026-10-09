// SUNDER: Ascension II — canvas drawing for the title screen and the hangar (SunderMenuGameMode holds the state).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SunderMenuHUD.generated.h"

UCLASS()
class SUNDER2_API ASunderMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;

private:
	void DrawCentered(const FString& Text, const FLinearColor& Color, float Y, float Scale);
	/** The title: the web game's drawTitle on the same art (breathing gate, flickering eclipse rim, rising embers, the
	 *  chosen ship rising out of the gate, legibility bands, the layered logo, the prompt and the credits). */
	void DrawTitle(const class ASunderMenuGameMode* Menu, float T, float ArtX, float ArtW);
	/** The hangar: the web game's drawShipSelect (hangar band, ringed preview, name, class, stats, personality,
	 *  browse arrows, STORY / SWARM, LAUNCH), then the fade to black on launch. */
	void DrawHangar(const class ASunderMenuGameMode* Menu, float T, bool bLaunching);
	/** Centred text placed by the web game's baseline and pixel size; Glow (alpha > 0) adds its soft shadow. */
	void DrawWebText(const FString& Text, const FLinearColor& Color, float BaselineY, float Px,
		const FLinearColor& Glow = FLinearColor(0.f, 0.f, 0.f, 0.f));
};
