// SUNDER: Ascension II — the hangar's choice across level loads.
#include "SunderLoadoutSubsystem.h"

#include "Kismet/GameplayStatics.h"

void USunderLoadoutSubsystem::ReadOptions(const FString& Options)
{
	const FString Ship = UGameplayStatics::ParseOption(Options, TEXT("Ship"));
	if (!Ship.IsEmpty()) { ShipId = Ship.ToLower(); }
	const FString InMode = UGameplayStatics::ParseOption(Options, TEXT("Mode"));
	if (InMode.Equals(TEXT("Swarm"), ESearchCase::IgnoreCase)) { Mode = ESunderPlayMode::Swarm; }
	else if (InMode.Equals(TEXT("Story"), ESearchCase::IgnoreCase)) { Mode = ESunderPlayMode::Story; }
}
