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
};
