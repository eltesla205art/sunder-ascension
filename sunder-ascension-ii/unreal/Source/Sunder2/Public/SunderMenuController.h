// SUNDER: Ascension II — input for the title, hangar and story screens (any SunderFrontEndGameMode), built at runtime
// with Enhanced Input (no input assets), like the ship's.
// Keys: WASD / arrows (D-pad, left stick) navigate · Space/Enter/J (A, Start) confirm · Esc/Backspace (B) back.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SunderMenuController.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class SUNDER2_API ASunderMenuController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	/** Hands raw key presses to a screen that is binding a key, before the menu's own actions see them. */
	virtual bool InputKey(const FInputKeyParams& Params) override;

private:
	class ASunderFrontEndGameMode* Screens() const;
	void OnUp();
	void OnDown();
	void OnLeft();
	void OnRight();
	void OnConfirm();
	void OnBack();

	UPROPERTY(Transient)
	TObjectPtr<UInputMappingContext> Mapping;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UInputAction>> Actions;
};
