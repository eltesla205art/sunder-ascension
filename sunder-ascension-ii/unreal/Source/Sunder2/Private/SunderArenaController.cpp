// SUNDER: Ascension II — the arena's player controller.
#include "SunderArenaController.h"

#include "Engine/World.h"
#include "SunderGameMode.h"

bool ASunderArenaController::InputKey(const FInputKeyParams& Params)
{
	if (Params.Event == IE_Pressed)
	{
		ASunderGameMode* Mode = GetWorld() ? GetWorld()->GetAuthGameMode<ASunderGameMode>() : nullptr;
		if (Mode && Mode->CaptureKey(Params.Key)) { return true; }
	}
	return Super::InputKey(Params);
}
