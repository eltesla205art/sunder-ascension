// SUNDER: Ascension II — menu input, built at runtime with Enhanced Input (no input assets), like the ship's.
// Keys: W/S/↑/↓ (D-pad, left stick) mode · A/D/←/→ ship · Space/Enter/J (A, Start) confirm · Esc/Backspace (B) back.
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

private:
	class ASunderMenuGameMode* Menu() const;
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
