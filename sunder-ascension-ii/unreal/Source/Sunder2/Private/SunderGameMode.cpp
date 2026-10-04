// SUNDER: Ascension II — game mode for the arena.
#include "SunderGameMode.h"

#include "SunderShipPawn.h"

ASunderGameMode::ASunderGameMode()
{
	DefaultPawnClass = ASunderShipPawn::StaticClass();       // BP_SunderGameMode points this at BP_SunderShip
}
